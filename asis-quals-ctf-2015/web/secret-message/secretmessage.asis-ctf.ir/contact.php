<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">
    <link rel="icon" href="../../favicon.ico">

    <title>Secret Message</title>

    <!-- Bootstrap core CSS -->
    <link href="../assets/css/bootstrap.min.css" rel="stylesheet">

    <!-- Just for debugging purposes. Dont actually copy these 2 lines! -->
    <!--[if lt IE 9]>
    <script src="../assets/js/ie8-responsive-file-warning.js"></script><![endif]-->
    <script src="../assets/js/ie-emulation-modes-warning.js"></script>

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
    <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
    <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->

    <!-- Custom styles for this template -->
    <link href="../assets/css/carousel.css" rel="stylesheet">
    <!-- a helper script for vaidating the form-->
    <script language="JavaScript" src="/assets/js/gen_validatorv31.js" type="text/javascript"></script>
</head>

<body>

<div class="navbar-wrapper">
    <div class="container">

        <nav class="navbar navbar-inverse navbar-static-top">
            <div class="container">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse"
                            data-target="#navbar"
                            aria-expanded="false" aria-controls="navbar">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="#">Secret Message!</a>
                </div>
                <div id="navbar" class="navbar-collapse collapse">
                    <ul class="nav navbar-nav">
                        <li class="active"><a href="index.html">Home</a></li>
                        <li><a href="#">About</a></li>
                        <li><a href="contact.php">Contact</a></li>
                        <li><a href="login.htm">Login</a></li>

                    </ul>
                </div>
            </div>
        </nav>

    </div>
</div>
<div class="clearfix"></div>
<div class="container">
    <div class="row col-xs-5" style="margin-top:100px;">
                        <form method="POST" name="contact_form" action="contact.php">
            <div class="form-group">
                <label for="InputName">Your Name</label>
                <input type="text" class="form-control" name="name" id="InputName"
                       placeholder="Enter Name">
            </div>
            <div class="form-group">
                <label for="InputEmail">Your Email</label>
                <input type="email" class="form-control" id="InputEmail" name="email" placeholder="Enter Email">
            </div>
            <div class="form-group">
                <label for="InputMessage">Message</label>
                <textarea name="message" id="InputMessage" class="form-control" rows="8" cols="40"></textarea>
            </div>
            <img src="captcha_code_file.php?rand=" id='captchaimg'><br>
            <label for='message'>Enter the code above here :</label><br>
            <input id="6_letters_code" name="6_letters_code" type="text"><br>
            <small>Can't read the image? click <a href='javascript: refreshCaptcha();'>here</a> to refresh
            </small>
            </p>
            <input type="submit" value="Submit" name='submit'>
        </form>
        <hr class="featurette-divider hidden-lg">
    </div>
    <!--
    <div class="col-xs-7" style="margin-top:100px;">
        <div class="alert alert-info">
            <a href="#" class="close" data-dismiss="alert">&times;</a>
            <strong>Note: mail sample!</strong>
            <br>
            To: someone@somewhere.tld<br>
            MIME-Version: 1.0<br>
            Content-type: text/plain; charset=iso-8859-1<br>
            From: ASIS &lt;another_one@another_where.tld&gt;<br>
            X-Mailer: PHP/5.5.12<br>
        </div>
    -->
    </div>
    <script language="JavaScript">
        // Code for validating the form
        // Visit http://www.javascript-coder.com/html-form/javascript-form-validation.phtml
        // for details
        var frmvalidator = new Validator("contact_form");
        //remove the following two lines if you like error message box popups
        frmvalidator.EnableOnPageErrorDisplaySingleBox();
        frmvalidator.EnableMsgsTogether();

        frmvalidator.addValidation("name", "req", "Please provide your name");
        frmvalidator.addValidation("email", "req", "Please provide your email");
        frmvalidator.addValidation("email", "email", "Please enter a valid email address");
    </script>
    <script language='JavaScript' type='text/javascript'>
        function refreshCaptcha() {
            var img = document.images['captchaimg'];
            img.src = img.src.substring(0, img.src.lastIndexOf("?")) + "?rand=" + Math.random() * 1000;
        }
    </script>
    <!-- Bootstrap core JavaScript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
    <script src="../assets/js/bootstrap.min.js"></script>
    <!-- Just to make our placeholder images work. Don't actually copy the next line! -->
    <script src="../assets/js/holder.js"></script>
    <!-- IE10 viewport hack for Surface/desktop Windows 8 bug -->
    <script src="../assets/js/ie10-viewport-bug-workaround.js"></script>
</div>
</body>
