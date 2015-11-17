<!doctype html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Login</title>
</head>
<body>
<style type="text/css">
* { margin: 0px; padding: 0px; }
a { font-size: 13px; color: #444; text-decoration: none; }
.form-box { width: 400px; margin: 30px auto }
.form-box .px { border: 1px solid #CCC; padding:5px 3px; border-radius: 5px; margin:5px 0; width: 382px }
.form-box button { display: block; font-size: 15px; width: 100px; margin:5px auto; height: 35px; background: #36C; border-radius: 3px; border: none; color: #FFF }
</style>

<div class="form-box">
	<form action="index.php?module=login&doSubmit=yes" method="post">
		<p><input class="px" type="text" name="username" placeholder="username" /></p>
		<p><input class="px" type="password" name="password" placeholder="password" /></p>
		<p><a href="index.php?module=register"?>Register</a><p>
		<p><a href="index.php?module=findpwd"?>Findpwd</a><p>
		<p><button type="submit">Login</button></p>
	</form>
</div>

</body>
</html>