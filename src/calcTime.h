void getTime()
{
   tmElements_t now;
   RTC.read(now);
   hours = now.Hour;
   minutes = now.Minute;
   seconds = now.Second;
   // timeAsNumber = hours * 10000 + minutes * 100 + seconds;
   // Serial.print(hour);
   rndLocal1 = random(4) + 26;
   rndLocal2 = random(4) + 26;
   seconds % 2 == 0 ? dot = false : dot = true;
   if (hours < 10)
   {
      timeAsArray[2] = hours;
      timeAsArray[3] = 0;
   }
   else
   {
      timeAsArray[2] = hours % 10;
      hours /= 10;
      // hours < 1 ? timeAsArray[5] = 0 : timeAsArray[5] = hours % 10;
      timeAsArray[3] = hours % 10;
   }

   timeAsArray[0] = minutes % 10;
   minutes /= 10;
   timeAsArray[1] = minutes % 10;
   // timeAsArray[0] = seconds % 10;
   // seconds /= 10;
   // timeAsArray[1] = seconds % 10;
};

// void updateTime()
// {
//    // time_t t = now();
//    tmElements_t now;

//    if (RTC.read(now))
//    {
//       RTC.read(now);
//       hours = now.Hour;
//       minutes = now.Minute;
//       seconds = now.Second;
//       timeAsNumber = (hours * 10000) + (minutes * 100) + seconds;
//       if (seconds % 2 == 0)
//       {
//          dot = false;
//          rndLocal2 = random(4) + 26;
//       }
//       else
//       {
//          dot = true;
//          rndLocal1 = random(4) + 26;
//       };
//       // Serial.print(hour + " " + minute + " " + second);
//       // Serial.print(timeAsNumber);
//       // if (hour >= 12)
//       // {
//       //    hour -= 12;
//       // }
//    }
//    else
//    {
//       if (RTC.chipPresent())
//       {
//          Serial.println("The DS1307 is stopped.  Please run the SetTime");
//          Serial.println("example to initialize the time and begin running.");
//          Serial.println();
//       }
//       else
//       {
//          Serial.println("DS1307 read error!  Please check the circuitry.");
//          Serial.println();
//       }
//       delay(1000);
//    }
//    // delay(1000);
// }
