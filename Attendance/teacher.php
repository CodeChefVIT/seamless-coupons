<?php


$servername = "localhost";
$username = "root";
$password = "";
$dbname = "seamlesscoupons";
$conn = new mysqli($servername, $username, $password, $dbname);


$att = "p";
$d = date("j");
$m = date("m");
$data = "{$d}_{$m}";
$sdc = "sdbhc";

$column= "ALTER TABLE attendance ADD $data VARCHAR(50) NOT NULL";

$column_result = mysqli_query($conn, $column);

?>
