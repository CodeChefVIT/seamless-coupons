-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 13, 2019 at 03:13 PM
-- Server version: 10.1.37-MariaDB
-- PHP Version: 7.3.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `food`
--

-- --------------------------------------------------------

--
-- Table structure for table `attendance`
--

CREATE TABLE `attendance` (
  `id` int(3) NOT NULL,
  `rfid` varchar(50) NOT NULL,
  `name` varchar(100) NOT NULL,
  `13_05` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `attendance`
--

INSERT INTO `attendance` (`id`, `rfid`, `name`, `13_05`) VALUES
(0, 'ABCDE', '', ''),
(0, 'sandy', '', 'present');

-- --------------------------------------------------------

--
-- Table structure for table `codechef`
--

CREATE TABLE `codechef` (
  `rfid` varchar(30) DEFAULT NULL,
  `coupons` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `codechef`
--

INSERT INTO `codechef` (`rfid`, `coupons`) VALUES
('06 97 D6 18', '0'),
('random', '0'),
('random1', '0'),
('random2', '1'),
('random4', '1'),
('sandeep', '2');

-- --------------------------------------------------------

--
-- Table structure for table `upi`
--

CREATE TABLE `upi` (
  `id` int(3) NOT NULL,
  `rfid` varchar(50) NOT NULL,
  `pin` int(4) NOT NULL,
  `amount` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `upi`
--

INSERT INTO `upi` (`id`, `rfid`, `pin`, `amount`) VALUES
(123, 'sandy', 1999, 600),
(124, 'abhi', 1999, 2200);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
