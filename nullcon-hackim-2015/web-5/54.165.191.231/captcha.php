<!DOCTYPE html>
<html>
    <head>
        <script type="text/javascript">
           function error() {
               alert("Session Expired");
               location.reload(); 
           }
         </script>
        <title>Captcha challenge</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
    <center>
      <div>How many times can you break this captcha? Your time starts now... 
      </div>
      <form action="verify.php" method="post"> 
            <img src="imagedemo.php" onerror=javascript:error();><br>
            Enter Code:<input type="text" name="solution" /> 
            <input type="submit" name="Submit" value="Submit" /> <br><br>

            <p>Note: Your session will be expired in 120 Seconds. </p> <br>
           Score :0 
      </form>
    </center>
    </body>
</html>
