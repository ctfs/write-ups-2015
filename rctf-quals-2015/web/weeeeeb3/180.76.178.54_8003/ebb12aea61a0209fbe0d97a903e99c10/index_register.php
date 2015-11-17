<!doctype html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Register</title>
</head>
<body>
<style type="text/css">
* { margin: 0px; padding: 0px; }
.form-box { width: 400px; margin: 30px auto }
.form-box .px { border: 1px solid #CCC; padding:5px 3px; border-radius: 5px; margin:5px 0; width: 382px }
.form-box button { display: block; font-size: 15px; width: 100px; margin:5px auto; height: 35px; background: #36C; border-radius: 3px; border: none; color: #FFF }
</style>

<div class="form-box">
	<form action="index.php?module=register&doSubmit=yes" method="post">
		<p><input class="px" type="text" name="username" placeholder="username" /></p>
		<p><input class="px" type="text" name="password" placeholder="password" /></p>
		<p><input class="px" type="text" name="birthday" placeholder="birthday:2015/01/01" /></p>
		<p><input class="px" type="text" name="address" placeholder="address" /></p>
		<p><button type="submit">Register</button></p>
	</form>
</div>

</body>
</html>