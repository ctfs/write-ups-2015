<?php

function parseParams($params) {
  if(is_array($params)) {
    return $params;
  }
  else {
    return explode("|",$params);
  }
}

function myDeserialize($object) {
  global $session;
  $class = $object["c"];
  $action = $object["a"];
  $cname = $class["name"];
  $cparams = Array();
  if(isset($class["params"])) {
    $cparams = $class["params"];
  }
  $my_obj = new $cname($cparams);
  $aname = $action["name"];
  $aparams = Array();
  if(isset($action["params"])) {
    $aparams = parseParams($action["params"]);
  }
  
  call_user_func_array(array($my_obj,$aname),$aparams);

}



?>
