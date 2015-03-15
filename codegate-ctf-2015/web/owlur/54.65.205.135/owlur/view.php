<?php
$pic = $_REQUEST['id'];

if($pic == "" || $pic == "random")
{
$picname = "preloaded-owls/" . rand(1,14) . ".jpg";
}

else $picname = "/owl/" . $pic . ".jpg";



echo '<img src="' . $picname . '">';

?>
