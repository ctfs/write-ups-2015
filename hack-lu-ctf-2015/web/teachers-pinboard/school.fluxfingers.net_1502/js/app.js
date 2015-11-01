//(function() {
var running = false;
var notes = [];
var key;
var namespace;
function setupSalt(namespace) {
  var salt;
  if (!localStorage.getItem(namespace+"salt")) {
    // no notes. create template note
    salt = crypto.getRandomValues(new Uint8Array(8));
    localStorage.setItem(namespace+"salt", salt.join(","));
  } else {
    saltA = localStorage.getItem(namespace+"salt").split(",");
    salt = new Uint8Array(saltA);
  }
  return salt;
}
function setupKey(salt, pass) {
  var bytes = new TextEncoder("utf-8").encode(pass);
  var importedKey = crypto.subtle.importKey(
    "raw", bytes, "PBKDF2", false, ["deriveBits"]);
    return importedKey.then((key) => {
      var params = {name: "PBKDF2", hash: "SHA-1", salt, iterations: 1000};
      promise = crypto.subtle.deriveBits(params, key, 160);
      return promise;
    });
  }
  function initialize(ai) {
    var pass = ai.password;
    var user = ai.username;
    namespace = user+":";
    var salt = setupSalt(namespace);
    setupKey(salt, pass).then((digest) => {
      var bin = new TextDecoder("utf-8").decode(digest);
      key = btoa(escape(bin));
      restoreSession(key);
      setInterval(save, 5000);
    });
    document.getElementById("addNote").addEventListener("click", () => {
      addNote(true); // false = it's a note
    });
    document.getElementById("addList").addEventListener("click", () => {
      addNote(false); // true = it's a list
    })
  }
  function save() {
    if (typeof key == undefined) {
      alert("No key set. Are you logged in?")
    }
    else {
      localStorage.setItem(namespace+key, JSON.stringify(notes));
    }
  }
  function restoreSession(key) {
    if (running !== true) {
      notes = JSON.parse(localStorage.getItem(namespace+key));
      if (notes && notes.length) {
        showNotes(notes);
      } else {
        // this isn't the first start, but there are no notes saved
        // creating a dummy note again.
        firstStart();
      }

    }
  }
  function showNotes(notes) {
    var tpls = "";
    for (var note of notes) {
      var tpl = genNoteTemplate(note)
      tpls += tpl;
    }
    var waittext = document.getElementById("plswait");
    waittext.parentNode.removeChild(waittext);
    var main = document.getElementById("main");
    main.insertAdjacentHTML("afterend", tpls);
    updateEventListeners();
  }
  function updateEventListeners() {
    for (var el of document.querySelectorAll("div.note-editor")) {
      el.addEventListener("input", (ev) => {
        noteUpdated(ev.target.dataset.id);
      })
    }
    for (var el of document.querySelectorAll("button.note-del")) {
      el.addEventListener("click", (ev) => {
        delNote(ev.target.dataset.id);
      })
    }
  }
  function genNoteTemplate(note) {
    return `
    <div class="flex-item" id="note-${note.id}">
    <button class="note-del" data-id="${note.id}" title="Delete">x</button>
    <div contenteditable="true" class="note-editor" data-id="${note.id}">
    <h2 class="note-title" data-id="${note.id}">${note.title}</h2>
    </div>
    <div contenteditable="true" class="note-editor" data-id="${note.id}">
    <div class="note-body" data-id="${note.id}">${note.body}</div>
    </div>
    </div>`;
  }
  function delNote(id) {
    var idx;
    for (var i=0; i < notes.length; i++) {
      var note = notes[i];
      if (note.id == id) {
        idx = i;
      }
    }
    notes.splice(idx, 1)
    var n = document.getElementById("note-"+id);
    n.parentNode.removeChild(n);
  }
  function addNote(list) {
    var newNote;
    if (list) {
      newNote = {
        title: "Note "+ (notes.length+1),
        body: "<p>Click in here to start editing right away!</p>",
        lastUpdated: new Date(),
      }
    } else {
      newNote = {
            title: "Shopping List",
            body: "<ul><li>Pickles</li><li>Coffee</li></ul>",
            lastUpdated: new Date(),
          }

    }
    newNote.id = notes.length
    notes.push(newNote);
    var tpl = genNoteTemplate(newNote)
    var main = document.getElementById("main");
    main.insertAdjacentHTML("afterend", tpl);
    updateEventListeners();
  }
  function noteUpdated(id) {
    for (note of notes) {
      var n = false;
      if (note.id == id) {
        note.body = (n=document.querySelector("div.note-body[data-id='"+id+"']")) ? n.innerHTML : "Click in here to start editing right away!";
        note.title = (n=document.querySelector("h2.note-title[data-id='"+id+"']")) ? n.textContent : 'Note '+id;
        note.lastUpdated = new Date();
      }
    }
  }
  function firstStart() {
    notes = [{
      id: 0,
      title: "Welcome, teacher!",
      body: "Welcome to the <strong>PinBoard</strong>.<br><br> This is your first entry \\o/.<br>"
      +" You can now start creating, deleting and modifying your notes.<br>"+
      " Backups will be kept automatically based on your login.",
      lastUpdated: new Date()
    }, {
      id: 2,
      title: "DO NOT FORGET",
      body: `<ul><li>we must not fail Peter in science class. His father is our second largest donator!</li>
      <li>the english teacher is retiring in a few weeks, we should probably find a REAL computer science teacher before that.</li>
      </ul>`,
      lastUpdated: new Date(),
    }, {
      id: 1,
      title: "Shopping List",
      body: "<ul><li>Pickles</li><li>Coffee</li></ul>",
      lastUpdated: new Date(),
    }];
    showNotes(notes);
  }
  addEventListener('load', function() {
    if (document.cookie) {
      var pairs = document.cookie.split(";");
      for (var i=0; i < pairs.length; i++) {
        var kv = pairs[i].split("=");
        var key = kv[0];
        var value = kv[1];
        if (key.trim() === "accountinfo") {
          var accountinfo = pickle.loads(unescape(value));
          initialize(accountinfo);
          break;
        }
      }
    } else {
      console.log("Error")
    }
    document.getElementById("privacylink").addEventListener("click", function() {
      document.getElementById("privacytext").classList.toggle("hidden");
    })
  });
  //})();
