 <!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="author" content="HHP">

    <title>Join with us</title>
    
    <style>
    .alert{
        width: 70%;
        margin-top: 10px;
    }
    </style>
    <link href="content/css/bootstrap.min.css" rel="stylesheet">

    <link href="content/css/freelancer.css" rel="stylesheet">

    <link href="content/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">
    <link href="http://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">
    <link href="http://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic" rel="stylesheet" type="text/css">

</head>

<body id="page-top" class="index">

    <!-- Navigation -->
    <nav class="navbar navbar-default navbar-fixed-top">
        <div class="container">
         
            <div class="navbar-header page-scroll">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                   
                </button>
                <a class="navbar-brand" href="index.php">Start Adventures with us</a>
            </div>

            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav navbar-right">
                    <li class="page-scroll">
                        <a href="index.php">Back To Home</a>
                    </li>
                </ul>
            </div>
          
        </div>
       
    </nav>   
    
     <section id="contact" style="padding-top:200px">
        <div class="container">
            <div class="row">
                <div class="col-lg-12 text-center">
                    <h2>Send us your resume if u wanna join</h2>
                    <hr class="star-primary">
                </div>
            </div>
            <div class=" row panel panel-primary">
                <div class="panel-body">
                    <div class="col-lg-8 col-lg-offset-2">
                       <h4>Select file from your computer</h4>
                        <form action="join.php" name="upload" method="post" enctype="multipart/form-data" id="js-upload-form">
                             <div class="form-inline">
                                <div class="form-group">
                                  <input type="file" name="file" id="js-upload-files" multiple>
                                 </div>
                                  <input type="submit" name = "upload" class="btn btn-sm btn-primary" id="js-upload-submit" value="Upload file">
                            </div>
                        </form>
                           
                    </div>
                </div>
            </div>
        </div>
    </section>
    