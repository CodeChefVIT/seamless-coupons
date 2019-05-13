<?php

$host = "localhost";
$user = "root";
$password ="";
$database = "seamlesscoupons";

$rfid = $_GET['rfid'];
$coupons = "1";
$coupons = (int)$coupons;

mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);


try{
    $connect = mysqli_connect($host, $user, $password, $database);
} 
catch (mysqli_sql_exception $ex) {
    echo 'Error';
}


if(!empty($rfid))
{
    
    $search_Query = "SELECT * FROM codechef WHERE rfid = '$rfid'";
    
    $search_Result = mysqli_query($connect, $search_Query);
    
    if($search_Result)
    {
        if(mysqli_num_rows($search_Result))
        {
            while($row = mysqli_fetch_array($search_Result))
            {
                $rfid1 = $row['rfid'];
                $coupons1 = $row['coupons'];
                
                if ($coupons1 > 0 ){
                    
                    $coupons1 = $coupons1-1;
                    
                    //update
                    $update_Query = "UPDATE `codechef` SET `coupons`='$coupons1' WHERE `rfid` = '$rfid1'";
                    try{
                        $update_Result = mysqli_query($connect, $update_Query);
        
                    if($update_Result){
                        if(mysqli_affected_rows($connect) > 0){
                            echo 'Data Updated';
                            }
                        else{
                            echo 'Data Not Updated';
                            }
                        }
                    }
                    catch (Exception $ex) {
                        echo 'Error Update '.$ex->getMessage();
                        }
                    }
                
                else {
                    echo 'Out of coupons';
                }
                }
            }
        
        else{
            //insert
            echo "No RFID Exist";
            }
        }
    }
    else{
        echo 'Result Error';
    }


