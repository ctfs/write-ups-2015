<?php
include('secrets.php');
// user vars
$action = $_GET['a'];
$method = $_GET['m'];
$data = $_GET['d'];
$signature = $_GET['s'];

if (!$_GET) {
   highlight_file(__FILE__);
   exit(0);
}


define("APPEND_LEFT", 1);
define("APPEND_RIGHT", 2);

if ($action == 'sign') {

   $to_sign = $data;

   if (strstr($data,'get')) {
      die('get word not allowed');
   }

   if ($method & APPEND_LEFT) {
      $to_sign = $secret_left . $to_sign;
   }
   if ($method & APPEND_RIGHT) {
      $to_sign = $to_sign . $secret_right;
   }

   echo md5($to_sign);

} else if ($action == 'verify') {
  if ($signature == md5( $secret_left . $data . $secret_right )) {
    echo 'signature ok';
    if (strstr($data, 'get flag')) {
      echo $flag;
    }
  }
}
