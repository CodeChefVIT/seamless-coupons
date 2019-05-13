<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "seamless-coupons";

$att = "p";
$d = date("j");
$m = date("m");
$date = "{$d} / {$m}";
$data = "try";
//$date = mysql_real_escape_string($date);

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "INSERT INTO attendance (`rfid`, `$data`) VALUES ('ABCDE', 'present')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
