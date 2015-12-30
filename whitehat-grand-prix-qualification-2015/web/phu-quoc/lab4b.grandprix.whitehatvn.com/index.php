<!DOCTYPE html>
<html>
<head>
        <title> World of games </title>
    <!-- Bootstrap Core CSS -->
        <link href="content/css/bootstrap.min.css" rel="stylesheet">
    <!-- Custom CSS -->
    <link href="content/css/simple-sidebar.css" rel="stylesheet">
    <script src="content/js/clock.js"></script>
    <script src="content/js/jquery-2.1.4.min.js"></script>
</head>

<body>

<div id="wrapper">
    <!-- Sidebar -->
    <div id="sidebar-wrapper">
    <ul class="sidebar-nav">
        <li class="sidebar-brand">
            <a href="index.php">
                World of Games
            </a>
        </li>
        <li>
            <a href="?game=starcraft">Starcraft II</a>
        </li>
                <li>
            <a href="?game=aoe">Age of Empires</a>
        </li>
                <li>
            <a href="?game=pes">PES 15</a>
        </li>
        <center>
        <canvas id="canvas" width="150" height="150" style="background-color:#fffff"> </canvas>
                </center>
        <center>
        <b> <script type="text/javascript">
                        $.ajax({
                                url: "/cgi-bin/counter?hit=true",
                                async: false
                        }).done(function(data){
                                document.write("Total visitors: " + data['counter'] );
                        });
                </script> </b>
        </center>
            </ul>

</div>    <!-- #sidebar-wrapper -->

<div id="page-content-wrapper">
        <div class="container-fluid">
                <div class="row">
                        <div class="col-lg-12">
                                <div class="col-lg-8">
                                        <h2> Welcome to my world</h2>                                </div>
                                <div class="col-lg-4">
                                                                        </div>
                        </div>
                </div>
        </div>
    <!-- #page-content-wrapper -->
</div>

<script type="text/javascript">
        var canvas = document.getElementById("canvas");
        var ctx = canvas.getContext("2d");
        var radius = canvas.height / 2;
        ctx.translate(radius, radius);
        radius = radius * 0.90
        drawClock();
        setInterval(drawClock, 1000);
</script>
</body>
</html>
