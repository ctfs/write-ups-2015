"use strict";
(function(){
  function encrypt(s) {
    var s_utf8 = unescape(encodeURIComponent(s));
    var a = [];
    var i;
    for (i = 0; i < s_utf8.length; i++) {
      a.push(String.fromCharCode(s_utf8.charCodeAt(i) ^ 0x73));
    }
    return a.join('');
  }
  $("#loginform").bind("submit", function() {
    var $input_id = $(this).find("[name=id]");
    var $input_password = $(this).find("[name=password]");
    var form = {
      "id": encrypt($input_id.val()),
      "password": encrypt($input_password.val()),
    };
    $.post("login", JSON.stringify(form), function(resp) {
      if (resp["result"] == "success") {
        document.cookie = 'ticket=' + encodeURIComponent(resp["ticket"]) + "; path=" + resp["ticket_for"];
        location.href = resp["redirect_to"];
      }
      else {
        $input_id.add($input_password).css({
          'background-color': 'pink'
        });
      }
    }, 'json');
    return false;
  });
})();
