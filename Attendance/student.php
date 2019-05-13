<?php
$host = "localhost";
$user = "root";
$password ="";
$database = "food";
$rfid = $_GET['rfid'];
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);
try{
    $connect = mysqli_connect($host, $user, $password, $database);
} 
catch (mysqli_sql_exception $ex) {
    echo 'Error';
}


$d = date("j");
$m = date("m");
$date = "{$d}_{$m}";


if(!empty($rfid))
{
    
    $search_Query = "SELECT * FROM attendance WHERE rfid = '$rfid'";
    
    $search_Result = mysqli_query($connect, $search_Query);
    
    if($search_Result)
    {
        if(mysqli_num_rows($search_Result))
        {
            while($row = mysqli_fetch_array($search_Result))
            {
                $rfid1 = $row['rfid'];
                
                $insert_Query = "UPDATE `attendance` SET `$date`='present' WHERE `rfid` = '$rfid1'";
                $insert_Result = mysqli_query($connect, $insert_Query);
                }
                echo 'Rfid Exsists';
                
                }
            }
        
        }
    
    else{
        echo 'Result Error';
    }
