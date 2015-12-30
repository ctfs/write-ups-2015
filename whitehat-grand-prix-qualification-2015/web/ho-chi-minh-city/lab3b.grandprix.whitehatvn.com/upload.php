
<!DOCTYPE html>
<!-- Website template by freewebsitetemplates.com -->
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>ImG Library</title>
	<link rel="shortcut icon" type="image/png" href="images/favicon.ico"/>
	<link rel="stylesheet" href="css/style.css" type="text/css" charset="utf-8" />	
    <link href="css/login.css" rel="stylesheet">	
	
</head>

<body>
	<span id="background"></span>
	<div id="page">
		<div id="sidebar">
			<div id="logo">
				<a href="index.php">The selected works of us</a>
			</div> <!-- /#logo -->
			<ul id="navigation">
				<li><a href="upload.php">Upload</a></li>
				<li><a href="index.php?cid=Popular">Most Popular</a></li>
				<li><a href="index.php?cid=Selected">Selected Images</a></li>
				<li><a href="index.php?cid=YourImages">Your Images</a></li>
			</ul> <!-- /#navigation -->
			</ul>
			<ul id="connect">
				<li><a href="#" class="facebook"></a></li>
				<li><a href="#" class="twitter"></a></li>
				<li><a href="#" class="link-us"></a></li>
			</ul> <!-- /#connect -->
			<div class="footer">
				&copy; Copyright &copy; 2015.
			</div> <!-- /.footer -->
		</div> <!-- /#sidebar -->
		
		<div id="contents">
			<span class="header"></span>
			<div class="container">
				<div id="content">
					<form action="login.php" method="POST">
						<h1>Login</h1>
						<div>
							<input type="text" placeholder="Username" required="" id="username" name="uname" />
						</div>
						<div>
							<input type="password" placeholder="Password" required="" id="password" name="passwd"/>
						</div>
												<div>
							<input type="submit" value="Log in" />
							<a href="register.php">Register</a>
						</div>
						<br/>
					</form><!-- form -->
				</div><!-- content -->
			</div><!-- container -->
		</div> <!-- /#contents -->
	</div> <!-- /#page -->
</body>
</html>