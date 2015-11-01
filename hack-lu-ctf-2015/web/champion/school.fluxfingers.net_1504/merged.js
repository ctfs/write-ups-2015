var WIDTH = 800;
var HEIGHT = 600;
var TILESIZE = 40;
var WIDTH_IN_TILES = WIDTH / TILESIZE; /* 20 */
var HEIGHT_IN_TILES = HEIGHT / TILESIZE; /* 15 */
var SOLIDTILEENTITIES = 'L'.split('');
var TILEENTITIES = 'X'.split('').concat(SOLIDTILEENTITIES); /* also update in solidAt */
var SIMPLE_TILETYPES = 'F'.split(''); /* also update in solidAt */
var TILETYPES = SIMPLE_TILETYPES.concat(TILEENTITIES);
var SOLID = SIMPLE_TILETYPES.concat(SOLIDTILEENTITIES);
var ALLIMGS = TILETYPES.concat(['player','lazor','marcher_l','marcher_r','boots','player_with_boots']);
var MAX_SAVE_SIZE = 50 * 60 * 20; // 20 minutes max

function encode_replay(input) {
  if (input.length > MAX_SAVE_SIZE) return alert('input too big, play faster!'), '<input too big>';
  if (input.length == 0) return '';
  var out = [];
  var cur = input[0];
  var curlen = 1;
  for (var i=1; i<input.length; i++) {
    if (input[i] != cur) {
      out.push(cur + curlen);
      cur = input[i];
      curlen = 0;
    }
    curlen++;
  }
  out.push(cur + curlen);
  return out.join('');
}

function load_replay(worldobj, input) {
  input = input.split('');
  var out = [];
  while (input.length > 0) {
    var c = input.shift();
    var n = ['0'];
    while (input.length > 0 &&
        input[0].charCodeAt(0) >= '0'.charCodeAt(0) &&
        input[0].charCodeAt(0) <= '9'.charCodeAt(0)) {
      n.push(input.shift());
    }
    n = n.join('');
    n = parseInt(n, 10);
    if (n > MAX_SAVE_SIZE) {
      console.log('expand element reject');
      worldobj.replay_in = [];
      return 'expand element reject (replay too long)';
    }
    for (var i=0; i<n; i++) out.push(c);
    if (out.length > MAX_SAVE_SIZE) {
      console.log('  expand total reject');
      worldobj.replay_in = [];
      return 'expand total reject (replay too long)';
    }
  }
  worldobj.replay_in = out;
}

function unimplemented() {}

function Entity(x, y) {
  this.x = x;
  this.y = y;
  this.has_jumpy_boots = false; // the player can collect jumpy boots for better jumping
  this.img = '';
  this.tick = unimplemented;
  this.marching_right = true;
  this.spawntick = -1;
}

function objIntersect(a, b) {
  var at = tiles[a.img];
  var bt = tiles[b.img];

  if (a.y + at.halfheight < b.y - bt.halfheight) return false;
  if (b.y + bt.halfheight < a.y - at.halfheight) return false;
  if (a.x + at.halfwidth < b.x - bt.halfwidth) return false;
  if (b.x + bt.halfwidth < a.x - at.halfwidth) return false;
  return true;
}

function World() {
  this.offX = 0;
  this.offY = 0;
  this.rng_state = [];
  this.rng_used = 64;
  this.world = null;
  this.player = null;
  this.replay_in = null;
  this.jumping = 0; // jump time left for the player
  this.entities = [];
  this.cb_result = null;
  this.pressed = {left:false,up:false,right:false,down:false};
  this.current_tick = 0;
}

function removeEntity(worldobj, ent) {
  worldobj.entities.splice(worldobj.entities.indexOf(ent), 1);
}

function rng_getbyte(w  , cb) {
  if (w.rng_used === 64) {
    var sha_input = w.rng_state.join();
/*STARTBROWSERONLY*/
    sha512(sha_input, function rng_getbyte_(newstate) {
      w.rng_state = newstate;
      w.rng_used = 1;
      cb(newstate[0]);
    });
/*ENDBROWSERONLY*/
/*STARTNODEONLY
    w.rng_state = sha512(sha_input);
    w.rng_used = 1;
    return w.rng_state[0];
ENDNODEONLY*/
  } else {
/*STARTBROWSERONLY*/
    cb(
/*ENDBROWSERONLY*/
/*STARTNODEONLY
    return (
ENDNODEONLY*/
      w.rng_state[w.rng_used++]
    );
  }
};

function random_bool(w, p  , cb) {
/*STARTBROWSERONLY*/
  rng_getbyte(w, function random_bool_(b) { cb(b < p); });
/*ENDBROWSERONLY*/
/*STARTNODEONLY
  return rng_getbyte(w) < p;
ENDNODEONLY*/
};

function tileByPos(w, x, y) {
  var xpos = Math.floor(x/TILESIZE);
  var ypos = Math.floor(y/TILESIZE);
  var tile = (w.world[ypos]||'')[xpos];
  return tile;
};

function solidAt(w, x, y) {
  var tile = tileByPos(w, x, y);
  //return tile !== undefined && SOLID.indexOf(tile) !== -1;
  return tile === 'F' || tile === 'L';
};

function objTestSolid(w, o, skewX, skewY, which) {
  var t = tiles[o.img];
  var centerX = o.x + skewX;
  var centerY = o.y + skewY;
  var left = centerX - t.halfwidth;
  var right = centerX + t.halfwidth;
  var top = centerY - t.halfheight;
  var bottom = centerY + t.halfheight;
  
  switch (which) {
    case 'top': return solidAt(w, left, top) || solidAt(w, right, top);
    case 'bottom': return solidAt(w, left, bottom) || solidAt(w, right, bottom);
    case 'left': return solidAt(w, left, top) || solidAt(w, left, bottom);
    case 'right': return solidAt(w, right, top) || solidAt(w, right, bottom);
    default: return false; /*throw 'unknown "which"';*/
  }
};

var tiles = {};

function load_tiles(cb) {
  var pendingimgs = ALLIMGS.length;
  ALLIMGS.forEach(function load_tile(t) {
    load_img('tiles/'+t+'.png', function load_tile_(img) {
      tiles[t] = img;
      pendingimgs--;
      if (pendingimgs == 0) cb();
    });
  });
}

function tick(worldobj, cb) {
/*STARTBROWSERONLY*/
  var ent_i = 0;
  function tick_1() {
    if (ent_i >= worldobj.entities.length) {
      // scroll
      var relPlayerX = worldobj.player.x - worldobj.offX * TILESIZE;
      var relPlayerY = worldobj.player.y - worldobj.offY * TILESIZE;
      if (relPlayerX < TILESIZE/4 + 4*TILESIZE) worldobj.offX -= 10;
      if (relPlayerX > WIDTH - TILESIZE/4 - 4*TILESIZE) worldobj.offX += 10;
      if (relPlayerY < TILESIZE/4 + 2*TILESIZE) worldobj.offY -= 7;
      if (relPlayerY > HEIGHT - 2*TILESIZE - TILESIZE/4) worldobj.offY += 7;

      render();
      cb(true);
    } else {
      var ret = worldobj.entities[ent_i].tick(worldobj, tick_2);
      if (ret !== undefined) tick_2(ret);
    }
  }
  function tick_2(val) {
    if (!val) {
      cb(false);
    } else {
      ent_i++;
      tick_1();
    }
  }
  tick_1();
/*ENDBROWSERONLY*/
/*STARTNODEONLY
  var ents = worldobj.entities;
  for (var ent_i = 0; ent_i < ents.length; ent_i++) {
    if (!ents[ent_i].tick(worldobj)) {
      cb(false);
      return;
    }
  }
  cb(true);
ENDNODEONLY*/
}

function boots_tick(worldobj) {
  if (objIntersect(this, worldobj.player)) {
    worldobj.player.has_jumpy_boots = true;
    worldobj.player.img = 'player_with_boots';
    removeEntity(worldobj, this);
  }
  return true;
}

function lazor_tick(worldobj) {
  if (objIntersect(this, worldobj.player)) {
    dead('hit by lazor in tick '+worldobj.current_tick+', spawned in '+this.spawntick, worldobj);
    return false;
  }
  this.x += 2;
  if (objTestSolid(worldobj, this, 0, 0, 'right')) removeEntity(worldobj, this);
  return true;
}

function exit_tick(worldobj) {
  if (objIntersect(this, worldobj.player)) {
    win(worldobj);
    return false;
  }
  return true;
}

function marcher_tick(worldobj) {
  if (this.marching_right) {
    if (objTestSolid(worldobj, this, 2, 0, 'right')) {
      this.marching_right = false;
      this.img = 'marcher_l';
    } else {
      this.x += 2;
    }
  } else {
    if (objTestSolid(worldobj, this, -2, 0, 'left')) {
      this.marching_right = true;
      this.img = 'marcher_r';
    } else {
      this.x -= 2;
    }
  }
  if (objIntersect(this, worldobj.player)) {
    dead('ran into a walker', worldobj);
    return false;
  }
  return true;
}

function lazor_shooter_tick(worldobj  , cb) {
  var self = this;
/*STARTNODEONLY
  var shoot_now =
ENDNODEONLY*/
  random_bool(worldobj, 2
/*STARTBROWSERONLY*/
, function lazor_shooter_tick_(shoot_now) {
/*ENDBROWSERONLY*/
/*STARTNODEONLY
);
ENDNODEONLY*/
  if (shoot_now) {
    var bullet_ent = new Entity(self.x + TILESIZE, self.y);
    bullet_ent.img = 'lazor';
    bullet_ent.tick = lazor_tick;
    bullet_ent.spawntick = worldobj.current_tick;
    worldobj.entities.push(bullet_ent);
  }
  cb(true);
/*STARTBROWSERONLY*/
  });
/*ENDBROWSERONLY*/
}

function player_tick(worldobj) {
  //console.log('  player tick at '+(process.hrtime()[1]-t_last_tick));
  // load/store input. ensure that the input is used synchronously after this!
/*STARTBROWSERONLY*/
  if (worldobj.replay_in != null) {
/*ENDBROWSERONLY*/
    if (worldobj.replay_in.length == 0) {
      end_of_replay(worldobj);
      return false;
    }
    var code = worldobj.replay_in.shift().charCodeAt(0) - 97;
    worldobj.pressed.left = !!(code & 1);
    worldobj.pressed.up = !!(code & 2);
    worldobj.pressed.right = !!(code & 4);
/*STARTBROWSERONLY*/
  }
/*ENDBROWSERONLY*/
  var code = (worldobj.pressed.left?1:0) + (worldobj.pressed.up?2:0) + (worldobj.pressed.right?4:0);
/*STARTBROWSERONLY*/
  if (worldobj.replay_in == null) stored_input.push(String.fromCharCode(97 + code));
/*ENDBROWSERONLY*/

  // mix fresh data into the RNG
  worldobj.rng_state.push(code);

  // left/right movement
  if (worldobj.pressed.left && !objTestSolid(worldobj, this, -4, 0, 'left')) this.x -= 4;
  if (worldobj.pressed.right && !objTestSolid(worldobj, this, 4, 0, 'right')) this.x += 4;

  // Does the player stand on the ground right now?
  var onground = objTestSolid(worldobj, this, 0, 1, 'bottom');
  if (worldobj.pressed.up && (worldobj.jumping || onground)) {
    for (var i=0; i<5; i++) {
      if (objTestSolid(worldobj, this, 0, -1, 'top')) break;
      this.y--;
    }
    if (onground) {
      // We're standing on the ground and starting a jump. Allow moving up
      // through air for the next few ticks. Tuned to not allow jumping on a
      // two-block wall without special shoes.
      worldobj.jumping = 70;
    }
    // After jumping up from the ground, the time you can jump for is limited.
    worldobj.jumping -= this.has_jumpy_boots ? 2 : 5;
  } else {
    // stay on the ground or fall
    for (var i=1; i<6; i++) {
      if (objTestSolid(worldobj, this, 0, i, 'bottom')) break;
    }
    this.y += i - 1;
  }
  return true;
}

var WORLDLINES = get('world.txt').split('\n');
function loadworld(worldobj) {
  worldobj.world = WORLDLINES.map(function load_world_line(line, y) {
    return line.split('').map(function load_world_char(tilechar, x) {
      var ent = new Entity(TILESIZE * x + TILESIZE/2, TILESIZE * y + TILESIZE/2);
      if (tilechar == 'P') {
        ent.img = 'player';
        ent.tick = player_tick;
        worldobj.player = ent;
        worldobj.entities.push(ent);
      } else if (tilechar == 'L') {
        ent.tick = lazor_shooter_tick;
        worldobj.entities.push(ent);
      } else if (tilechar == 'X') {
        ent.img = 'X';
        ent.tick = exit_tick;
        worldobj.entities.push(ent);
      } else if (tilechar == 'B') {
        ent.img = 'boots';
        ent.tick = boots_tick;
        worldobj.entities.push(ent);
      } else if (tilechar == 'M') {
        ent.img = 'marcher_r';
        ent.tick = marcher_tick;
        worldobj.entities.push(ent);
      }
      if (TILETYPES.indexOf(tilechar) === -1) {
        tilechar = ' ';
      }
      return tilechar;
    }).join('');
  });
}
var worldobj = new World();
/*STARTBROWSERONLY*/
var stored_input;
/*ENDBROWSERONLY*/
worldobj.cb_result = (typeof cb_result === 'function' ? cb_result : null);
function upload_result(name, replaystr) {
  var req = new XMLHttpRequest();
  req.open('POST', '/submit', false);
  req.setRequestHeader('Genuine', 'yes');
  req.send(replaystr + '\n' + name);
  alert((req.status == 200 ? 'upload successful' : 'upload failed') + '\n' + req.responseText);
}

var $ = document.getElementById.bind(document);

var canvas;
var in_tick = false;

function do_tick() {
  if (in_tick) return; /* skip frame */
  in_tick = true;
  tick(worldobj, function do_tick_() {
    in_tick = false
  });
}

document.addEventListener('DOMContentLoaded', function on_content_loaded() {
  load_tiles(function tiles_loaded() {
    loadworld(worldobj);

    canvas = $('output');
    $('btn_reset').onclick = function reset_btn_cb() {
      stop_and_reload(function reset_btn_cb_() {
        stored_input = [];
        start();
      });
    };
    $('btn_load').onclick = function load_btn_cb() {
      stop_and_reload(function load_btn_cb_() {
        load_replay(worldobj, $('replay_inout').value);
        stored_input = null;
        start();
      });
    };
    stored_input = [];
    start();
  });
});

function stop_and_reload(cb) {
  clearInterval(tick_interval);
  function stop_and_reload_() {
    // wheee, polling! don't kill me please.
    if (in_tick) return setTimeout(stop_and_reload_, 10);
    worldobj = new World();
    loadworld(worldobj);
    cb();
  }
  stop_and_reload_();
}

function start() {
  tick_interval = setInterval(do_tick, 20);
}

// there should really be a sync api for this.  srsly, hashing is not
// that slow.
function sha512(input, cb) {
  input = new TextEncoder("utf-8").encode(input);
  crypto.subtle.digest("SHA-512", input).then(function sha512_(hash){
    cb([].slice.call(new Uint8Array(hash)));
  });
}

function load_img(path, cb) {
  var img = new Image();
  img.onload = function load_img_() {
    img.halfheight = img.height / 2;
    img.halfwidth = img.width / 2;
    cb(img);
  };
  img.src = path;
}

var KEYS = {37:'left',38:'up',39:'right',40:'down'};
document.onkeydown = function onkeydown(e) {
  var key = KEYS[e.keyCode];
  if (key) worldobj.pressed[key] = true;
};
document.onkeyup = function onkeydown(e) {
  var key = KEYS[e.keyCode];
  if (key) worldobj.pressed[key] = false;
}

function get(path) {
  var req = new XMLHttpRequest();
  req.open('GET', path, false);
  req.send();
  return req.responseText;
}

function render() {
  var ctx = canvas.getContext('2d');
  ctx.fillStyle = 'white';
  ctx.fillRect(0, 0, WIDTH, HEIGHT);
  for (var relx = 0; relx < WIDTH_IN_TILES; relx++) {
    for (var rely = 0; rely < HEIGHT_IN_TILES; rely++) {
      var tile = (worldobj.world[worldobj.offY + rely] || [])[worldobj.offX + relx];
      if (tile && tiles[tile]) {
        var img = tiles[tile];
        ctx.drawImage(img, relx * TILESIZE + (TILESIZE-img.width)/2, rely * TILESIZE + (TILESIZE-img.height) / 2);
      }
    }
  }
  worldobj.entities.forEach(function draw_entity(ent) {
    if (!ent.img || ent.img.length == 1) return;
    var img = tiles[ent.img];
    if (!img) return;
    var centerX = ent.x - worldobj.offX * TILESIZE;
    var centerY = ent.y - worldobj.offY * TILESIZE;
    ctx.drawImage(img, centerX - img.width/2, centerY - img.height/2);
  });
}

function dead() {
  clearInterval(tick_interval);
  alert('you lost! :(');
}

function win() {
  clearInterval(tick_interval);
  alert('you won' + stored_input ? ('after '+stored_input.length+' ticks! going to upload...') : '');
  if (stored_input) {
    var replaystr = encode_replay(stored_input);
    var name = prompt('your name? (will appear in public highscore, <=50 chars, only [a-zA-Z0-9_ -])');
    if (name != null) {
      upload_result(name, replaystr);
    }
    $('replay_inout').value = replaystr;
  }
}

function end_of_replay() {
  clearInterval(tick_interval);
  alert('replay ended without win/lose')
}

var tick_interval;