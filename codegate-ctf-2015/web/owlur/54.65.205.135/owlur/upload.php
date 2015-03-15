<?php

function RandomString()
{
    $characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    $randstring = "";
    for ($i = 0; $i < 7; $i++) {
        $randstring .= $characters[rand(0, strlen($characters)-1)];
    }
    return $randstring;
}

$target_dir = "/var/www/owlur/owlur-upload-zzzzzz/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 0;
$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
$fsize = $_FILES['fileToUpload']['size'];
$newid = RandomString();
$newname = $newid . ".jpg";

if(isset($_POST["submit"])) {
    if($imageFileType == "jpg") {
        $uploadOk = 1;
    } else {
    echo "<p>Sorry, only JPG images of owls will be accepted. Please use a different service if you do not intend to upload owl pictures.</p>";
        $uploadOk = 0;
    }

    if(!($fsize >= 0 && $fsize <= 200000)) {
    $uploadOk = 0;
        echo "<p>Sorry, the size of your owl picture is not to our liking.</p>";
    }

}

if($uploadOk)
{

$newpath = "/var/www/owlur/owlur-upload-zzzzzz/" . $newname;

if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $newpath)) {
    header('Location: /owlur/index.php?page=view&id=' . $newid);
    } else {
        echo "<p>Sorry, there was an error uploading your file.</p>";
    }

}


?>
