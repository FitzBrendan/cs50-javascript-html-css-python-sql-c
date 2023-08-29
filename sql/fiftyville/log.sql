-- Keep a log of any SQL queries you execute as you solve the mystery.

-- start with crime_scene_reports table
-- list crimes on July 28, 2021; Humphrey Street
--      SELECT  description
--      FROM    crime_scene_reports
--      WHERE   month = 7 AND day = 28 AND year = 2021 AND street = "Humphrey Street";

--  Result  Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--          Interviews were conducted today with three witnesses who were present at the time –
--          each of their interview transcripts mentions the bakery.

-- get transcipt (3 whitnesses) from interviews table
--      SELECT  transcript
--      FROM    interviews
--      WHERE   month = 7 AND day = 28 AND year = 2021;

--  Result
--          | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
--          If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

--          | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
--          I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--          | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--          In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--          The thief then asked the person on the other end of the phone to purchase the flight ticket. |

--get destination airport id from suspects; license plates -> ids -> bank account numbers -> atm transactions -> passports -> flights
--       SELECT DISTINCT destination_airport_id, hour FROM flights
 --       JOIN passengers ON passengers.flight_id = flights.id
 --       WHERE month = 7 AND day = 29 AND year = 2021
  --      AND flight_id IN
 --               (SELECT flight_id FROM passengers
   --             WHERE passport_number IN
     --                  (SELECT passport_number FROM people
       --                 JOIN bank_accounts ON bank_accounts.person_id = people.id
         --               WHERE bank_accounts.person_id IN
           --                     (SELECT person_id FROM bank_accounts
             --                   WHERE account_number IN
               --                         (SELECT DISTINCT account_number FROM atm_transactions
                 --                       WHERE month = 7 AND day = 28 AND year = 2021
                   --                     AND atm_location = "Leggett Street"
                     --                   AND transaction_type = "withdraw"
                       --                 AND account_number IN
                         --                   (SELECT account_number FROM bank_accounts
                           --                 WHERE person_id IN
                             --                   (SELECT id FROM people
                               --                 WHERE license_plate IN
                                 --                   (SELECT license_plate FROM bakery_security_logs
                                   --                 WHERE   month = 7 AND day = 28 AND year = 2021 AND activity = "exit" AND hour = 10)))))))
    --        ORDER BY hour
     --       LIMIT 1;

-- Result   desination airpirt id is 4, LaGuardia Airport

-- get city of destination airport
--SELECT city FROM airports
--WHERE id = 4;

-- Result   destination city was New York City

-- Querries above determined flight id of 36
-- Querries above narrowed down suspects to 3 with 3 matched accomplishments, id'd with phone numbers
-- Suspect / Accomplice matches
-- (367) 555-5533   /   (375) 555-8161
-- (286) 555-6063   /   (676) 555-6554
-- (770) 555-1861   /   (725) 555-3243

-- get passport number, match passengers with flight id 36, get names of suspects
--SELECT name, phone_number FROM people
--WHERE passport_number IN
    --(SELECT passport_number FROM passengers
    --WHERE flight_id = 36
    --AND passport_number IN
        --(SELECT passport_number FROM  people
        --WHERE phone_number IN
        --("(367) 555-5533", "(375) 555-8161", "(286) 555-6063", "(676) 555-6554", "(770) 555-1861", "(725) 555-3243")));

-- Result suspect Bruce with accomplice Robin
