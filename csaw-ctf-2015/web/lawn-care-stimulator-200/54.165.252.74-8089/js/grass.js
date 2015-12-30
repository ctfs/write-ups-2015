var ctx, stack, w, h;
var awards, grassHeight;

var drawer = function(){
  ctx.fillStyle="#00ccff";
  ctx.fillRect(0,0,w,h);
  stack.forEach(function(el){
      el[0]();
  })
  requestAnimationFrame(drawer);
}

var grow = function(){
  grassHeight+=1;
  stack.forEach(function(el){
      el[1]();
  })
  checkAcheivments();
    
}
var anim = function(){
  var x = Math.random()*20, y = 0;
  var maxTall = Math.random()*100+400;
  var maxSize = Math.random()*10+5;
  var speed = Math.random()*2;  
  var position = Math.random()*w-w/2;
  var c = function(l,u){return Math.round(Math.random()*(u||255)+l||0);}
  var color = 'rgb('+c(60,10)+','+c(201,50)+','+c(120,50)+')';
  return [function(){
    var deviation=Math.cos(x/30)*Math.min(x/40,50),
        tall = Math.min(x/2,maxTall),
        size = Math.min(x/50,maxSize);
    ctx.save();
    ctx.strokeWidth=10;
    ctx.translate(w/2+position,h)
    ctx.fillStyle=color;
    ctx.beginPath();
    ctx.lineTo(-size,0);
    ctx.quadraticCurveTo(-size,-tall/2,deviation,-tall);
    ctx.quadraticCurveTo(size,-tall/2,size,0);
    ctx.fill();
    ctx.restore()
  },
  function() {
    x += speed; 
  }];
};
function initGrass(){
    var canvas   = document.getElementById('grass');
    ctx      = canvas.getContext('2d');
    stack    = [];
    w        = 600;
    h        = 600;
    for(var x = 0; x<400;x++){stack.push(anim());}
    canvas.width = w;
    canvas.height = h;
    drawer();
    initAcheivements();
}

function checkAcheivments(){
    for (var gh in awards){
        if (grassHeight == gh){
            alert(awards[gh]);
        }
    }
}

function initAcheivements(){
    awards = {
        10: "Acheivment unlocked!\nYour grass is 10 mm!",
        30: "Acheivment unlocked!\nYour grass is 30 mm!",
        50: "Acheivment unlocked!\nYour grass is 50 mm!",
        100: "Acheivment unlocked!\nYour grass is 100 mm!",
        150: "Acheivment unlocked!\nYour grass is 150 mm!",
    };
    grassHeight = 0;
    
}
