/******************************************************************************************************************************
COMMING SOON PAGE
*******************************************************************************************************************************/

/******************************************************************************************************************************
ANIMATIONS
*******************************************************************************************************************************/
(function($) {
    "use strict";
    var isMobile = false;
    if (navigator.userAgent.match(/Android/i) || 
        navigator.userAgent.match(/webOS/i) ||
        navigator.userAgent.match(/iPhone/i) || 
        navigator.userAgent.match(/iPad/i)|| 
        navigator.userAgent.match(/iPod/i) || 
        navigator.userAgent.match(/BlackBerry/i)) {                 
        isMobile = true;            
    }
    if (isMobile == true) {
        $('body').removeClass('nomobile');
        $('.animated').removeClass('animated');
    }
    $(function() {
        if (isMobile == false) {
            $('*[data-animated]').addClass('animated');
        }
        function animated_contents() {
            $(".animated:appeared").each(function (i) {
                var $this    = $(this),
                    animated = $(this).data('animated');

                setTimeout(function () {
                    $this.addClass(animated);
                }, 50 * i);
            });
        }
        animated_contents();
        $(window).scroll(function () {
            animated_contents();
        });
    });
})(jQuery);

/******************************************************************************************************************************
BOOTSTRAP
*******************************************************************************************************************************/
(function($) {
    "use strict";
        $('[data-rel=tooltip]').tooltip();
        $(".alert").alert();
})(jQuery);
/******************************************************************************************************************************
PROGRESS BAR
*******************************************************************************************************************************/
(function($) {
    "use strict";
    $("a.btn-progress").click(function(){
        $('#bar-container').slideToggle(); 
    });
})(jQuery);

var T = 6000;
function animate() {
    var delta = 10;
    var el = $(".timer")[0];
    for (var i = 0; i <= T / delta; i++) {
        setTimeout(
            function (i) {
                el.style.width = ((100.0 * delta * i) / T).toString() + "%";
            }, delta * i, i);
    }
}

var int;
function start_voting() {
    $.post('vote.php', "data=init", function (x) {
        $("#start")[0].style.display = "none";
        $("#msg").text(x);
    });
    setTimeout(function () {
        $.post('vote.php', "data=stop", function (x) {
            $("#start")[0].style.display = "inline-block";
            $("#msg").text(x);
            clearInterval(int);
        });
    }, T);
    int = setInterval(function () {
        $.get('vote.php', function (x) {
            var res = JSON.parse(x);
            $("#lyapas").text(res["lyapas"]);
            $("#rust").text(res["rust"]);
            $("#go").text(res["go"]);
            $("#swift").text(res["swift"]);
        });
    },100);
    animate();
}

$(document).ready(function(){
    $("form").on('submit', function (e) {
        e.preventDefault();
        start_voting();
    })
    $(".btn-vote").on('click', function (e) {
        $.ajax({
            type: 'POST',
            url: 'vote.php',
            data: "data=" + e.target.id,
            beforeSend: function (xhr) {
                var sid = $("#vote-ssid").val();
                xhr.setRequestHeader("X-Vote-Sid", sid);
            }
        })
        .done(function (x) {
            $("#msg").text(x);
        });
    });
});