/* 
   Javascript Utilities

   Copyright (c) 2011-2012 Fabrice Bellard

   Redistribution or commercial use is prohibited without the author's
   permission.
*/
"use strict";

/* add the bind function if not present */
if (!Function.prototype.bind) {
    Function.prototype.bind = function(obj) {
        var slice1 = [].slice,
        args = slice1.call(arguments, 1),
        self = this,
        nop = function () {},
        bound = function () {
            return self.apply( this instanceof nop ? this : ( obj || {} ),
                               args.concat( slice1.call(arguments) ) );   
        };
        
        nop.prototype = self.prototype;
        
        bound.prototype = new nop();
        
        return bound;
    };
}

/* include script 'filename' */
function include(filename)
{
   document.write('<script type="text/javascript" src="' + filename + 
                  '"><' + '/script>');
}

/* Load a binary data. cb(data, len) is called with data = null and
 * len = -1 in case of error. Otherwise len is the length in
 * bytes. data can be a string, Array or Uint8Array depending on
 * the implementation. */
function load_binary(url, cb)
{
    var req, typed_array, is_ie;

    //    console.log("load_binary: url=" + url);

    req = new XMLHttpRequest();
    req.open('GET', url, true);

    /* completion function */
    req.onreadystatechange = function() {
        var err, data, len, i, buf;

        if (req.readyState == 4) {
            //            console.log("req status=" + req.status);
            if (req.status != 200 && req.status != 0) {
                cb(null, -1);
            } else {
                if (is_ie) {
                    data = new VBArray(req.responseBody).toArray();
                    len = data.length;
                    cb(data, len);
                } else {
                    if (typed_array && 'mozResponse' in req) {
                        /* firefox 6 beta */
                        data = req.mozResponse;
                    } else if (typed_array && req.mozResponseArrayBuffer) {
                        /* Firefox 4 */
                        data = req.mozResponseArrayBuffer;
                    } else if ('responseType' in req) {
                        /* Note: in Android 3.0 there is no typed arrays so its
                           returns UTF8 text */
                        data = req.response;
                    } else {
                        data = req.responseText;
                        typed_array = false;
                    }
                
                    if (typed_array) {
                        len = data.byteLength;
                        buf = new Uint8Array(data, 0, len);
                        cb(buf, len);
                    } else {
                        len = data.length;
                        cb(data, len);
                    }
                }
            }
        }
    };

    is_ie = (typeof ActiveXObject == "function");
    if (!is_ie) {
        typed_array = ('ArrayBuffer' in window && 'Uint8Array' in window);
        if (typed_array && 'mozResponseType' in req) {
            /* firefox 6 beta */
            req.mozResponseType = 'arraybuffer';
        } else if (typed_array && 'responseType' in req) {
            /* Chrome */
            req.responseType = 'arraybuffer';
        } else {
            req.overrideMimeType('text/plain; charset=x-user-defined');
            typed_array = false;
        }
    }
    req.send(null);
}
