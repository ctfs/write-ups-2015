<?php
// secret vars
include('secrets.php');

function do_xor($a,$b) {
  $s = '';
  for ($i=0; $i < max(strlen($a),strlen($b)); $i++) {
    $x = $i < strlen($a) ? ord($a[$i]) : 0;
    $y = $i < strlen($b) ? ord($b[$i]) : 0;
    $s .= chr($x ^ $y);
  }
  return $s;
}

if (!$_GET) {
   highlight_file(__FILE__);
   exit(0);
}

// user vars
$action = $_GET['a'];
$method = $_GET['m'];
$data = $_GET['d'];
$signature = $_GET['s'];


if ($action == 'sign') {

   $to_sign = $data;

   if (strstr($data,'get')) {
      die('get word not allowed');
   }

   if ($method == 'old') {
      echo md5(do_xor($data,$secret));
   } else {
      echo hash_hmac('md5',$data, $secret);
   }

} else if ($action == 'verify') {

  if ($method == 'old')
     die('deprecated');

  if ($signature == hash_hmac('md5',$data, $secret)) {
    if (strstr($data, 'get flag')) {
      echo $flag;
    }
  }
}


?>
