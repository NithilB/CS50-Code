-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Aryaman was my partner

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "chamberlin";

--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

Select transcript from interviews where month = 7 and day = 28 and year = 2020

-- 1. Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. 
-- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

-- 2. I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, 
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

-- 3. As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. 
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

Select account_number from atm_transactions where month = 7 and day = 28 and year = 2020 and atm_location like "%Fifer Street%" and transaction_type like "%withdraw%";

-- 28500762
-- 28296815
-- 76054385
-- 49610011
-- 16153065
-- 25506511
-- 81061156
-- 26013199

Select caller, receiver from phone_calls where month = 7 and day = 28 and year = 2020 and duration < 60

-- caller / receiver
-- (130) 555-0289 / (996) 555-8899
-- (499) 555-9472 / (892) 555-8872
-- (367) 555-5533 / (375) 555-8161
-- (499) 555-9472 / (717) 555-1342
-- (286) 555-6063 / (676) 555-6554
-- (770) 555-1861 / (725) 555-3243
-- (031) 555-6622 / (910) 555-3251
-- (826) 555-1652 / (066) 555-9701
-- (338) 555-6650 / (704) 555-2131

Select license_plate, activity from courthouse_security_logs where month = 7 and day = 28 and year = 2020 and hour = 10 and (minute > 5 and minute < 25); 

-- 5P2BI95 exit
-- 94KL13X exit
-- 6P58WS2 exit
-- 4328GD8 exit
-- G412CB7 exit
-- L93JTIZ exit
-- 322W7JE exit
-- 0NTHK55 exit

/*
flight has an id
airport has an id
flight has an airport from id 
and airport to id
*/

Select origin_airport_id, hour, minute from flights join airports on flights.origin_airport_id = airports.id where month = 7 and day = 29 and year = 2020 and city like "%Fiftyville%"

--origin id = 8 and time 8:20 earliest flight

Select passport_number from passengers join flights on passengers.flight_id = flights.id where month = 7 and day = 29 and year = 2020 and hour = 8 and minute = 20 and origin_airport_id = 8

-- 7214083635
-- 1695452385
-- 5773159633
-- 1540955065
-- 8294398571
-- 1988161715
-- 9878712108
-- 8496433585

Select name from people join bank_accounts on people.id = bank_accounts.person_id
where (phone_number like "(130) 555-0289" or phone_number like "(499) 555-9472" or phone_number like "(367) 555-5533" or phone_number like "(286) 555-6063" or phone_number like "(770) 555-1861" or phone_number like "(031) 555-6622" or phone_number like "(826) 555-1652" or phone_number like "(338) 555-6650")
and (passport_number = 7214083635 or passport_number = 1695452385 or passport_number = 5773159633 or passport_number = 1540955065 or passport_number = 8294398571 or passport_number = 1988161715 or passport_number = 9878712108 or passport_number = 8496433585)
and (license_plate like "5P2BI95" or license_plate like "94KL13X" or license_plate like "6P58WS2" or license_plate like "4328GD8" or license_plate like "G412CB7" or license_plate like "L93JTIZ" or license_plate like "322W7JE" or license_plate like "0NTHK55")
and (account_number = 28500762 or account_number = 28296815 or account_number = 76054385 or account_number = 49610011 or account_number = 16153065 or account_number = 25506511 or account_number = 81061156 or account_number = 26013199)

--Ernest

Select * from people where name like "Ernest"

--phone number = (367) 555-5533
--passport number = 5773159633
--license plate = 94KL13X

--Select city from airports join flights on airports.id = flights.destination_airport_id join passengers on passengers.flight_id = airports.id where passport_number = 5773159633

Select city from airports join flights on flights.destination_airport_id = airports.id where month = 7 and day = 29 and year = 2020 and hour = 8 and minute = 20 and origin_airport_id = 8 

--London

Select name from people where phone_number like "(375) 555-8161"

--Berthold