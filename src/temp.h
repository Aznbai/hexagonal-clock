// // Convert temp to array needet for display
// void TempToArray()
// {
//   tmElements_t tm;
//   RTC.read(tm);
//   if (tm.Second != 27)
//   {
//     TempShow = false;
//     return;
//   }
//   TempShow = false; // true to false
//   int t = RTC.temperature();
//   int celsius = (t / 4.0) * 100;
//   Serial.print("Temp is: ");
//   Serial.println(celsius);
//   int cursor = 56; // last led /*  */number
//   leds[27] = 0x000000;
//   leds[28] = 0x000000;
//   leds[29] = 0x000000;
//   leds[30] = 0x000000;

//   for (int i = 1; i <= 4; i++)
//   {
//     int digit = celsius % 10; // get last digit in time
//     if (i == 1)
//     {
//       Serial.print("Digit 4 is : ");
//       Serial.print(digit);
//       Serial.print(" ");

//       cursor = 30;

//       for (int k = 0; k <= 9; k++)
//       {
//         Serial.print(digits[11][k]);
//         if (digits[11][k] == 1)
//         {
//           leds[cursor] = ledColor;
//         }
//         else if (digits[11][k] == 0)
//         {
//           leds[cursor] = 0x000000;
//         };
//         cursor++;
//       };
//       Serial.println();
//     }
//     else if (i == 2)
//     {
//       Serial.print("Digit 3 is : ");
//       Serial.print(digit);
//       Serial.print(" ");

//       cursor = 20;

//       for (int k = 0; k <= 9; k++)
//       {
//         Serial.print(digits[10][k]);
//         if (digits[10][k] == 1)
//         {
//           leds[cursor] = ledColor;
//         }
//         else if (digits[10][k] == 0)
//         {
//           leds[cursor] = 0x000000;
//         };
//         cursor++;
//       };
//       Serial.println();
//     }
//     else if (i == 3)
//     {
//       Serial.print("Digit 2 is : ");
//       Serial.print(digit);
//       Serial.print(" ");
//       cursor = 10;
//       for (int k = 0; k <= 9; k++)
//       {
//         Serial.print(digits[digit][k]);
//         if (digits[digit][k] == 1)
//         {
//           leds[cursor] = ledColor;
//         }
//         else if (digits[digit][k] == 0)
//         {
//           leds[cursor] = 0x000000;
//         };
//         cursor++;
//       };
//       Serial.println();
//     }
//     else if (i == 4)
//     {
//       Serial.print("Digit 1 is : ");
//       Serial.print(digit);
//       Serial.print(" ");
//       cursor = 0;
//       for (int k = 0; k <= 9; k++)
//       {
//         Serial.print(digits[digit][k]);
//         if (digits[digit][k] == 1)
//         {
//           leds[cursor] = ledColor;
//         }
//         else if (digits[digit][k] == 0)
//         {
//           leds[cursor] = 0x000000;
//         };
//         cursor++;
//       };
//       if (digit == 0)
//       {
//         for (int k = 0; k < 10; k++)
//         {
//           leds[k] = 0x000000;
//         };
//         Serial.println();
//       }
//     }
//     celsius /= 10;
//   };
// };
