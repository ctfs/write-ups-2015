<?php

class session {
  private $id = "";
  private $session = "";
  function __construct($id) {
    $this->id = $id;
    if(file_exists("/tmp/".$this->id)) {
      $this->session = json_decode(file_get_contents("/tmp/".$this->id), true);
    }
    else {
      $this->session = Array();
    }
    
  }
  function get($var) {
    return $this->session[$var];
  }
  function set($var,$value) {
    $this->session[$var] = $value;
    if(isset($this->id) && $this->id !== "") {
      file_put_contents("/tmp/".$this->id,json_encode($this->session));
    }
  }
  function debug() {
    print file_get_contents("/tmp/".$this->id);
  }
  
  function getId() {
    return $this->id;
  }
  
}

class user {

  function login($username,$password) {
  mysql_connect("localhost","inso15","inso15");
  mysql_select_db("inso15");
  $query = "SELECT id FROM users WHERE name = '$username' and password = '" . sha1($password) . "'";
  $result = mysql_query($query);
  $line = mysql_fetch_array($result,MYSQL_ASSOC);
    if(isset($line['id']) && $line['id'] !== "") {
      $GLOBALS['session']->set("userid",$line['id']);
      $GLOBALS['message'] = "Login Success";
    }
    else {
      $GLOBALS['session']->set("userid",-1);
      $GLOBALS['message'] = "Login fail";
    }
  }
  function logout($user) {
    $GLOBALS['session']->set("userid",-1);
  }
  function register($username,$password) {
    //TODO
  }

}


class page {
  private $name;
  private $allowed_pages = array("home","artists","films","directors","logout");
  function render($page) {
  
      if($GLOBALS['session']->get("userid") > 0) {
	foreach($this->allowed_pages as $allowed_page) {
	  if(preg_match("/$allowed_page/",$page)) {
	  //print "This is page " . $page;
	    include($page . ".php");
	  }
	}
      }
      else {
	include("login.php");
      }
  }
}
?>
