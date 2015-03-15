<?php
$p = $_REQUEST['page'];

if($p == "" || $p == "index")
{
$p = "main";
}

$haq = base64_decode("ICAgICAgICAgICAgICAgICAgIC8tLS0tLS0tLS0KICAgICAgICAgICAgICAgICAgLyAvIC8qKioqKipcCiAgICAgICAgICAgICAgICAgLyAvKioqKi0tICogKlwKICAgICAgLy8oKCg6PDw8PC86KioqKioqKioqM1xYKlwoKDwKICAgICAvWFgvQ1hDJkNHRy8vKiovLS0vLy9YKlZcKiouLmcmCigvVkNDM2dnMC4uLi4uLi4uKi8vWC8vKC8vL1YqQ1wqLi44ODhnZzhnJjNDPAooMyZnRyYuLi4uLi4uLi4uLiouLlhYWC8oKCgvKi5cKi4uLi4uLi5HLzA4ODgzWDxgCi8oPEM4IC4uLi4uLi4uLi4uKi5YWFhYLy8vLzwvLi4qLi4uLi4uLi4uLi4uLi4uM0NeClgvLzw8Ly4uLi4uLi4uLi4uKiZDVlgvLy9WLzw8Ly4qLi4uLi4uLi4uLi4uLi4uOEdDPApYWC9DLzo8L1YuLi4uLi4uLiomM0NWWFZYVlgoPFYqKi4uLi4uLi4uLi4uLi4uLiBnOENeCiAgICBHQy88PC8oLi4uLi44RyYzQ0NWWFhYWFZ+WFYqLi4uLi4uLi4uLi4uLi4uIEM4M1YKICAgICAgIFYvPF48KFg4OCZWLy8oKDw8PDwoKDxePCoqLi4uLi4uLi4uLi4uLi4uWCYmQwogICAgICAgICAgICAgIGA6L0NDVi8oKCg8PCgvVlZWLyouLi4uLi4uLi4uLi4uLigvQyYvCiAgICAgICAgICAgICAgIDw8IF5eKC9WMzNWWC9WQyZYKlZDLi4uLjo8PH48PDwoKFggIGAKICAgICAgICAgICAgICAgVi8oLzwgXiBeXjovWC8oKDw8Xl4tLS1WOn5+PDwoCiAgICAgICAgICAgICAgMyYgICAgICAgICAgICAgICAgICAuXi0vCiAgICAgICAgICAgICAgQyAgL1wgICAgICAgL1wgICAgICAgIHwKICAgICAgICAgICAgIC9DICBcLyAgICAgICBcLyAgICAgICAvLwogUExaIFNUT1AgICAgIDMgICAgICAgICAgICAgICAgICAgIHxcCiAgIEhBQ0tJTkcgICAgQyAgICAgICAgICAgICAgICAgICAvNSoKICAgICAgICAgICAgICBWICAgICAvLS0tLS1cICAgICAgIC8KICAgICAgICAgICAgICBDRyAgfCAgICAgICAgIHwgIDwvLy88CiAgICAgICAgICAgICAgVkdWIHwgICAgICAgICB8IF4oL1g8XgogICAgICAgICAgICAgICAmJjwgIFwtLS0tLS8gIC4oKDwoXgogICAgICAgICAgICAgICAgODMoICAgICAgICAuPCh+YDw8CiAgICAgICAgICAgICAgICAgOFhgICAgICAuPDxeYCBgKCheCiAgICAgICAgICAgICAgICBCQEBDPC5gXl5gICAgICBeKENHJkMoPC5gYAogICAgIENHOEIkQEBAQEBAQEBAJCggICAgICAgICAgXl4oMEBAQEAkODNYPGAKICAgQkBAQEBAQEBAQEBAQEBAQEBAOC8gICAgICAgYDxDJEBAQEBAQEBAQEAkJjwKICBAQEBAQEBAQEBAQEBAQEAkJCRAQEAkJDA4ODhCQEBAQEBAQEBAQEBAQEBAQEBWYAogQEBAQEBAQEBAQEBAQEAkQCQkJCQkJCRAQEBAJCRAQEAkQEBAQEBAQEBAQEBAQEBDYApAQEBAQEBAQEBAQEBAQCRAJCQkJCQkJCQkJCQkJCQkJCQkQEBAQEBAQEBAQEBAQEBAKGAKQEBAQEBAQEBAQEAkQCQkJCQkJCQkJCQkJCQkQEAkJEBAQEBAQEBAQEBAQEBAQEBAQEIK");
$haq = htmlentities($haq);

if(strstr($p,"..") !== FALSE)
die("<pre>$haq</pre>");

if(stristr($p,"http") !== FALSE)
die("<pre>$haq</pre>");

if(stristr($p,"ftp") !== FALSE)
die("<pre>$haq</pre>");

if(strlen($p) >= 60)
die("<pre>string > 60
$haq</pre>");

$inc = sprintf("%s.php",$p);

?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Owlur - The simple image sharing website for owl pictures</title>

    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>
  <body style="background-color: #d0d0c8;">
<center>
<h1>owlur</h1>



<?php
include($inc);
?>
</center>
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>

