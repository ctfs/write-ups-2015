<?php

function generate_secret()
{
    $f = fopen('/dev/urandom','rb');
    $secret1 = fread($f,32);
    $secret2 = fread($f,32);
    fclose($f);
    
    return sha1($secret1).sha1($secret2);
}

session_start();

if(!isset($_SESSION['secret']))
    $_SESSION['secret'] = generate_secret();
    
if(!isset($_POST['guess']))
{
    echo 'Wanna play lotto? Just try to guess 320 bits.<br/><br/>'.PHP_EOL;
    highlight_file(__FILE__);
    exit;
}

$guess = $_POST['guess'];

if($guess === $_SESSION['secret'])
{
    $flag = require('flag.php');
    exit('Lucky bastard! You won the flag! ' . $flag);
}
//else...
echo "Wrong! '{$_SESSION['secret']}' != '";
echo htmlspecialchars($guess);
echo "'";

$_SESSION['secret'] = generate_secret();
