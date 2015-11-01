(function(m) {
  "use strict"
  var module = m;
  const BLACKLIST = ["require", "eval", "setTimeout", "setInterval", "setImmediate"];
  for (var i=0; i < BLACKLIST.length; i++) {
    var key = BLACKLIST[i];
    // not defined in browser-JS: global[key] = function() {};
    m[key] = function() {};
  }

  function interpret(s, debug, r) {
    const DEBUG = debug;
    // opcodes up to v2
    const MARK            = '(';
    const STOP            = '.';
    const POP             = '0';
    const POP_MARK        = '1';
    const DUP             = '2';
    const FLOAT           = 'F';
    const INT             = 'I';
    const BININT          = 'J';
    const BININT1         = 'K';
    const LONG            = 'L';
    const BININT2         = 'M';
    const NONE            = 'N';
    const PERSID          = 'P';
    const BINPERSID       = 'Q';
    const REDUCE          = 'R';
    const STRING          = 'S';
    const BINSTRING       = 'T';
    const SHORT_BINSTRING = 'U';
    const UNICODE         = 'V';
    const BINUNICODE      = 'X';
    const APPEND          = 'a';
    const BUILD           = 'b';
    const GLOBAL          = 'c';
    const DICT            = 'd';
    const EMPTY_DICT      = '}';
    const APPENDS         = 'e';
    const GET             = 'g';
    const BINGET          = 'h';
    const INST            = 'i';
    const LONG_BINGET     = 'j';
    const LIST            = 'l';
    const EMPTY_LIST      = ']';
    const OBJ             = 'o';
    const PUT             = 'p';
    const BINPUT          = 'q';
    const LONG_BINPUT     = 'r';
    const SETITEM         = 's';
    const TUPLE           = 't';
    const EMPTY_TUPLE     = ')';
    const SETITEMS        = 'u';
    const BINFLOAT        = 'G';
    const TRUE            = 'I01\n';
    const FALSE           = 'I00\n';
    // Protocol 2 things:
    const PROTO           = '\x80';
    const NEWOBJ          = '\x81';
    const EXT1            = '\x82';
    const EXT2            = '\x83';
    const EXT4            = '\x84';
    const TUPLE1          = '\x85';
    const TUPLE2          = '\x86';
    const TUPLE3          = '\x87';
    const NEWTRUE         = '\x88';
    const NEWFALSE        = '\x89';
    const LONG1           = '\x8a';
    const LONG4           = '\x8b';
    // TODO: implement Protocol v3 and v4

    var index = 0;
    var stack = [];
    var memo = {};
    var mark = {'marky':'mark'};

    function read(i) {
      var out = s.slice(index, index+i);
      index = index +i;
      return out;
    }
    function readline() {
      var remaining = s.substr(index);
      var temparr = remaining.split("\n");
      index = index + temparr[0].length + 1; // skip over newline
      return temparr[0]+"\n";
      /* the newline we append, will be stripped basically in every use
       * but it will be kept and stripped just like in pickle.py
       * to make it easier to compare
       */
    }
    function marker() { // finds marker
      var k = stack.length-1;
      while (stack[k] != mark) {
        k = k-1
      }
      return k
    }
    function load_proto() {
      var proto = read(1).charCodeAt(0);
      if ((proto < 0) || (proto > 2)) {
        throw new Error("unsupported pickle protocol: "+proto);
      }
    }
    function findClass(modulename, name) {
      var mod;
      if((BLACKLIST.indexOf(modulename) !== -1) || (BLACKLIST.indexOf(name) !== -1)) {
        return function() {};
      }
      if (modulename in this) {
        mod = this[modulename];
      }
      if (typeof mod == "undefined") {
        throw new Error("Could not find global name '" +modulename+"'");
      }
      if (name in mod) {
        return mod[name];
      }
      throw new Error("Could not find property '"+name+"' in module '"+modulename+"'");
    }
    function mloads(num) {
      // in python2.7 it's marshal.load
      // in python3.4 this is unpack("<i", ..) with 4bytes or "<H" for 2.
      // but it's actually the same:
      // e.g. '\x05\x00\x00\x00' -> 5
      // .. '\x00\x01\x00\x00' -> 1
      if ((num.charAt(0) == 'i') && (num.length == 5)) {
        var buf = new ArrayBuffer(4);
        var view = new DataView(buf);
        view.setUint8(0, num[1].charCodeAt(0));
        view.setUint8(1, num[2].charCodeAt(0));
        view.setUint8(2, num[3].charCodeAt(0));
        view.setUint8(3, num[4].charCodeAt(0));
        console.log(view.getInt32(0, true)); // little endian!
        /*
         var len = mloads('i' + read(4));
         var s = read(len);
         var buf = new ArrayBuffer(s.length);
         var view = new DataView(buf);
         for (var i in s) {
         view.setUint8(i, s[i].charCodeAt(0));
         }
         var decoder = new TextDecoder("utf-8");
         var outstring = decoder.decode(buf);
         stack.push(outstring);
         * */
      }
    }
    function persistent_load() {
      // wtf? somehow this always failes in python3.4's pickle.py
      throw new Error("unsupported persistent id encountered");
    }
    function decode_long(data) {
      if (data == '') { return 0; }
      var buf = new ArrayBuffer(2);
      var view = new DataView(buf);
      view.setUint8(0, data.charCodeAt(0));
      view.setUint8(1, data.charCodeAt(1));
      ///XXX maybe compute correct function (getInt8, 16, 32) from data.length?
      if (data.length == 1) {
        return view.getInt8(0, true); // little endian
      } else if (data.length == 2) {
        console.log(view.getInt16(0, true)); // little endian
      }
      throw new Error("Unexpected size for decode_long");
    }
    function instantiate(klass, k) {
      var args = stack.slice(k+1);
      var stackBefore = stack.slice(0,k-1);
      var value;
      try {
        value = klass.call(this, args);
      } catch(e) {
        // retry with 'new' below
      }
      if (typeof value == "undefined") {
        try {
          value = new klass.call(args);
        } catch(e) { throw new Error("Couldnt instantiate: " + klass); }
      }
      stackBefore.push(value);
      stack = stackBefore;
      return;
    }
    while (true) {
      key = read(1);
      switch(key) {
        case '':
          throw Error("EOF");
          break;
        case PROTO:
          load_proto();
          break;
        case PERSID:
          var pid = readline().slice(0,-1);
          stack.push(persistent_load(pid));
          break;
        case BINPERSID:
          var pid = stack.pop();
          stack.push(persistent_load(pid));
          break;
        case NONE:
          stack.push(null); //XXX null==None
          break;
        case NEWFALSE:
          stack.push(false);
          break;
        case NEWTRUE:
          stack.push(true);
          break;
        case INT:
          var data = readline().slice(0,-1);
          var val;
          if (data == FALSE.slice(1,-1)) {
            val = false;
          } else if (data == TRUE.slice(1,-1)) {
            val = true;
          } else {
            // allows notation like '0xFF', which python doesnt.
            val = parseInt(data);
          }
          stack.push(val);
          break;
        case BININT:
          stack.push(mloads('i'+read(4)));
          break;
        case BININT1:
          stack.push(read(1).charCodeAt(0));
          break;
        case BININT2:
          stack.push(mloads('i'+read(2)+'\x00\x00'));
          break;
        case LONG:
          // allows notation like '0xFF', as intended
          stack.push(new Number(readline().slice(0,-1)));
          break;
        case LONG1:
          var n = read(1).charCodeAt(0);
          var bytes = read(n);
          stack.push(decode_long(bytes));
          break;
        case LONG4:
          var n = mloads('i' + read(4));
          var bytes = read(n);
          stack.push(decode_long(bytes));
          break;
        case FLOAT:
          // not as strict as python, because we dont know the difference
          // between float and integer.
          stack.push(new Number(readline().slice(0,-1)));
          break;
        case BINFLOAT:
          throw new Error("Not implemented");
          var binary = read(8);
          var buf = new ArrayBuffer(8);
          var view = new DataView(buf);
          for (var c in binary) {
            view.setUint8(c, binary[c].charCodeAt(0));
          } // like unpack '>d'
          stack.push(view.getFloat64(0));
          break;
        case STRING:
          var rep = readline().slice(0,-1);
          var quotes = ["'", '"'];
          for (var j=0; j < quotes.length; j++) {
            // ES6 for (var q of quotes) {
            var q = quotes[j];
            if (rep.indexOf(q) == 0) {
              if ((rep.length < 2) || (rep.slice(-1) !== q)) {
                throw new Error("insecure string pickle");
              }
              rep = rep.slice(q.length,-q.length);
              break;
            } else {
              throw new Error("insecure string pickle");
            }
          }
          stack.push(rep.replace(/'/g, '')); //XXX slightly cheating
          break;
        case BINSTRING:
          var len = mloads('i' + read(4));
          stack.push(read(len));
          break;
        case UNICODE:
          var line = readline().slice(0,-1);
          var quoted = '"' + line +'"';
          /* XXX do we want to plant a bug in this JSON.parse here
           *     or do we want to escape all { and [ with a backslash?
           *   ... we should probably do that for all " anyway..
           */
          var unicode = JSON.parse(quoted); // escapes resolved
          stack.push(unicode);
          break;
        case BINUNICODE:
          var len = mloads('i' + read(4));
          var s = read(len);
          var buf = new ArrayBuffer(s.length);
          var view = new DataView(buf);
          for (var i in s) {
            view.setUint8(i, s[i].charCodeAt(0));
          }
          var decoder = new TextDecoder("utf-8");
          var outstring = decoder.decode(buf);
          stack.push(outstring);
          break;b
        case TUPLE:
        case LIST: // JS doesnt make a difference between those
          var k = marker();
          var stackBeforeMarker = stack.slice(0,k);
          var stackAfterMarker = stack.slice(k+1);
          // note: don't merge/concat array!
          // but append last things as an array element on top of stack.
          stackBeforeMarker.push(stackAfterMarker);
          stack = stackBeforeMarker;
          break;
        case EMPTY_TUPLE:
          stack.push([]);
          break;
        case TUPLE1:
          var tos = stack.pop();
          stack.push([tos]);
          break;
        case TUPLE2:
          stack = stack.slice(0,-2) + [stack.slice(-2)];
          break;
        case TUPLE3:
          stack = stack.slice(0,-3) + [stack.slice(-3)];
          break;
        case EMPTY_LIST:
          stack.push([]);
          break;
        case EMPTY_DICT:
          stack.push({});
          break;
        //case LOAD_LIST? see TUPLE
        case DICT:
          var k = marker();
          var o = {};
          var items = stack.slice(k+1);
          for (var i=0; i<=items.length; i=i+2) {
            var key = items[i];
            var value = items[i+1];
            if (typeof key !== "undefined") {
              o[key] = value
            }
          }
          var newStack = stack.slice(k-1);
          newStack.push(o);
          stack = newStack;
          break;
        case INST:
          var modulename = readline().slice(0,-1);
          var name = readline().slice(0,-1);
          var className = findClass(modulename, name);
          instantiate(className, marker());
          break;
        case OBJ:
          var k = marker();
          var className = stack[k+1];
          stack.slice(k+1);
          instantiate(className, k);
          break;
        case NEWOBJ:
          var args = stack.pop();
          var cls = stack.pop();
          var newObj = new cls.apply(this, args);
          stack.push(newObj);
          break;
        case GLOBAL:
          var modulename = readline().slice(0,-1);
          var name = readline().slice(0,-1);
          var className = findClass(modulename, name);
          stack.push(className);
          break;
        case EXT1:
          /* (un)pickling extension types implemented in C
           * We don't want to support that.
           */
          var extensionCode = read(1).charCodeAt(0);
          throw new Error('unregistered extension code ' +extensionCode );
          break;
        case EXT2:
          var extensionCode = mloads('i' + read(2) + "\x00\x00");
          throw new Error('unregistered extension code ' + extensionCode );
          break;
        case EXT4:
          var extensionCode = mloads('i' + read(4));
          throw new Error('unregistered extension code ' + extensionCode );
          break;
        case REDUCE:
          var args = stack.pop();
          var func = stack.pop();
          var value = func.apply(this, args);
          stack.push(value);
          break;
        case POP:
          stack.pop();
          break;
        case POP_MARK:
          var k = marker();
          for (var i=stack.length; i > 0; i--) {
            if (i !== k) {
              stack.pop();
            } else {
              break;
            }
          }
          break;
        case DUP:
          stack.push(stack.slice(-1));
          break;
        case GET:
          var fromMemo = memo[readline().slice(0,-1)];
          stack.push(fromMemo);
          break;
        case BINGET:
          var i = read(1).charCodeAt(0);
          var fromMemo = memo[i.toString()];
          stack.push(fromMemo);
          break;
        case LONG_BINGET:
          var i = mloads('i' + read(4));
          var fromMemo = memo[i.toString()];
          stack.push(fromMemo);
          break;
        case PUT:
          var l = readline().slice(0,-1);
          memo[l] = stack.slice(-1)[0];
          break;
        case BINPUT:
          var i = read(1).charCodeAt(0);
          memo[i.toString()] = stack.slice(-1);
          break;
        case LONG_BINPUT:
          var i = mloads('i' + read(4));
          memo[i.toString()] = stack.slice(-1);
          break;
        case APPEND: // did I understand this correctly?
          var value = stack.pop();
          var arr = stack.pop();
          arr.push(value);
          stack.push(arr);
          break;
        case APPENDS:
          // stack layout: …, oldArr, marker, addme1, addme2, …
          var k = marker();
          var arr = stack[k-1]; // find array before marker
          // extend array with elements after marker:
          arr = arr.concat(stack.slice(k+1));
          // remove oldArr and everything after it.
          stack = stack.splice(0,k-1);
          // throw new arr on top.
          stack.push(arr);
          break;
        case SETITEM:
          var value = stack.pop();
          var key = stack.pop();
          var obj = stack.pop();
          obj[key] = value;
          stack.push(obj);
          break;
        case SETITEMS:
          // stack: …, obj, marker, key1, value1, key2, value2, …
          var k = marker();
          var obj = stack[k-1];
          for (var i = k+1; i>stack.length; i=i+2) {
            obj[stack[i]] = stack[i+1]
          }
          stack = stack.splice(0,k-1); // remove up to marker _and_ before.
          stack.push(obj);
          break;
        case BUILD: ///XXX
          throw new Error("Fredy was too lazy to understand or implement this");
          break;
        case MARK:
          stack.push(mark);
          break;
        case STOP:
          var value = stack.pop();
          return value; // yay
          break;
        default:
          // exit vm or throw something.
          console.log("Sipping unknown opcode ", key);
          break;
      }
    }
  }

  m.pickle = {
      loads: interpret
    };

})(window);
/***
 * Notes: splice is weird and does something in place -.-
 *        better review all existing splice uses :<
 *          I may have messed up slice/splice, also.. :D
 *
 *
 *
 */
