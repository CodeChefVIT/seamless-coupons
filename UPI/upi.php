<?php
$host = "localhost";
$user = "root";
$password ="";
$database = "food";

$final = $_GET['final'];
list($send_rfid,$rcv_rfid,$amount,$pin) = explode(";", $final);



mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);
try{
    $connect = mysqli_connect($host, $user, $password, $database);
} 
catch (mysqli_sql_exception $ex) {
    echo 'Error';
}

if(!empty($amount))
{
    
    $search_Query = "SELECT * FROM upi WHERE rfid = '$send_rfid'";
    
    $search_Result = mysqli_query($connect, $search_Query);
    
    if($search_Result)
    {
        if(mysqli_num_rows($search_Result))
        {
            while($row = mysqli_fetch_array($search_Result))
            {
                $amt = $row['amount'];
                $pin_validate = $row['pin'];
                if ($pin == $pin_validate){
                    if($amt>$amount){
                         
                        
                        $search_Query = "SELECT * FROM upi WHERE rfid = '$rcv_rfid'";
    
                        $search_Result = mysqli_query($connect, $search_Query);
    
                        if($search_Result)
                            {
                                if(mysqli_num_rows($search_Result))
                                    {
                                    while($row = mysqli_fetch_array($search_Result))
                                        {
                                        $rcv_amt = $row['amount'];
                                        $amt = $amt - $amount;
                                        $rcv_amt = $rcv_amt + $amount;
                                        echo 'Succefully Transfered Money :)';
                                        
                                        $update_Query1 = "UPDATE `upi` SET `amount`='$amt' WHERE `rfid` = '$send_rfid'";
                                        $update_Result1 = mysqli_query($connect, $update_Query1);
                                        
                                        $update_Query2 = "UPDATE `upi` SET `amount`='$rcv_amt' WHERE `rfid` = '$rcv_rfid'";
                                        $update_Result2 = mysqli_query($connect, $update_Query2);
                                        }
                                    }
                            else{
                            echo 'Reciever doesnt exist';
                        }
                        }
                        
                        }
                        else{
                            echo 'No Amount';    
                            }    
                }
                else{
                echo 'Wrong PIN';
                }
                }
            }
    }
    }
    else{
        echo 'Result Error';
    }

?>