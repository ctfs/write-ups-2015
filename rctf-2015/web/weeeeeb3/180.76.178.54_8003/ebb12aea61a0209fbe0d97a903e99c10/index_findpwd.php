<!doctype html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>ResetPwd</title>
</head>
<script src="js/jquery.js"></script>
<body>
<style type="text/css">
* { margin: 0px; padding: 0px; }
.form-box { width: 400px; margin: 30px auto }
.form-box .px { border: 1px solid #CCC; padding:5px 3px; border-radius: 5px; margin:5px 0; width: 382px }
.form-box button { display: block; font-size: 15px; width: 100px; margin:5px auto; height: 35px; background: #36C; border-radius: 3px; border: none; color: #FFF }
</style>

<div class="form-box">
	<form action="index.php?module=findpwd&step=1&doSubmit=yes" method="post">
		<p><input class="px" type="text" name="username" placeholder="username" /></p>
		<p><input class="px" type="text" name="birthday" placeholder="birthday" /></p>
		<p><input class="px" type="text" name="address" placeholder="address" /></p>
		<div class="box" id="div_geetest_lib">
			<div id="div_id_embed"></div>
			<script type="text/javascript">
				var gtFailbackFrontInitial = function(result) {
					var s = document.createElement('script');
					s.id = 'gt_lib';
					s.src = 'http://static.geetest.com/static/js/geetest.0.0.0.js';
					s.charset = 'UTF-8';
					s.type = 'text/javascript';
					document.getElementsByTagName('head')[0].appendChild(s);
					var loaded = false;
					s.onload = s.onreadystatechange = function() {
						if (!loaded && (!this.readyState|| this.readyState === 'loaded' || this.readyState === 'complete')) {
							loadGeetest(result);
							loaded = true;
						}
					};
				}
				//get  geetest server status, use the failback solution


				var loadGeetest = function(config) {

					//1. use geetest capthca
					window.gt_captcha_obj = new window.Geetest({
						gt : config.gt,
						challenge : config.challenge,
						product : 'embed',
						offline : !config.success
					});

					gt_captcha_obj.appendTo("#div_id_embed");
				}

				s = document.createElement('script');
				s.src = 'http://api.geetest.com/get.php?callback=gtcallback';
				$("#div_geetest_lib").append(s);

				var gtcallback =( function() {
					var status = 0, result, apiFail;
					return function(r) {
						status += 1;
						if (r) {
							result = r;
							setTimeout(function() {
								if (!window.Geetest) {
									apiFail = true;
									gtFailbackFrontInitial(result)
								}
							}, 1000)
						}
						else if(apiFail) {
							return
						}
						if (status == 2) {
							loadGeetest(result);
						}
					}
				})()

				$.ajax({
					url : "StartCaptchaServlet.php?rand="+Math.round(Math.random()*100),
					type : "get",
					dataType : 'JSON',
					success : function(result) {
						console.log(result);
						gtcallback(result)
					}
				})
			</script>
		</div>
		<p><button type="submit">verify</button></p>
	</form>
</div>

</body>
</html>