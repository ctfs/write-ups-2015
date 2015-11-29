<html>
<head>
    <meta charset="utf-8">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>LOGIN</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="css/signin.css" rel="stylesheet">
</head>
<script src="js/jquery-2.1.4.min.js"></script>
<body>

<div class="container">

    <form class="form-signin">
        <h2 class="form-signin-heading">Please Sign In</h2>
        <label for="inputEmail" class="sr-only">username</label>
        <input type="text" id="inputName" class="form-control" placeholder="Username" required autofocus>
        <label for="inputPassword" class="sr-only">Password</label>
        <input type="password" id="inputPassword" class="form-control" placeholder="Password" required>
        <div class="checkbox">
        </div>
        <div class="btn-group" aligin="center">
            <button onclick="login()" type="button" class="btn btn-lg btn-primary">Login</button>
            <button onclick="window.location='register.php'" type="button" class="btn btn-lg btn-primary">Rigester</button>
        </div>
    </form>


</div>
</body>
<!-- login as admin-->
</html>

<script>
    function login()
    {
        var name = $("#inputName").val();
        var pass = $("#inputPassword").val();
        $.post("checkLogin.php",{name:name,pass:pass,login:'login'},function (result) {
            $(".checkbox").html(result);
        });
    }

</script>
