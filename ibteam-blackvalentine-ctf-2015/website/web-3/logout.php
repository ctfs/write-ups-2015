<?php
session_start();
$logged =0;
$bool = 0;
session_destroy();
header("location:index.php");
?>