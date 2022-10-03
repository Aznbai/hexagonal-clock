
void DSTcheck()
{
  int buttonDST = digitalRead(DST_PIN);
  // Serial.print("DST is: ");Serial.println(DST);
  if (buttonDST == LOW)
  {
    if (DST)
    {
      DST = false;
      // Serial.print("Switching DST to: ");Serial.println(DST);
    }
    else if (!DST)
    {
      DST = true;
      // Serial.print("Switching DST to: ");Serial.println(DST);
    };
    delay(500);
  };
}

void TimeAdjust()
{
  int buttonH = digitalRead(HUR_PIN);
  int buttonM = digitalRead(MIN_PIN);
  if (buttonH == LOW || buttonM == LOW)
  {
    delay(500);
    tmElements_t Now;
    RTC.read(Now);
    int hour = Now.Hour;
    int minutes = Now.Minute;
    int second = Now.Second;
    if (buttonH == LOW)
    {
      if (Now.Hour == 23)
      {
        Now.Hour = 0;
      }
      else
      {
        Now.Hour += 1;
      };
    }
    else
    {
      if (Now.Minute == 59)
      {
        Now.Minute = 0;
      }
      else
      {
        Now.Minute += 1;
      };
      // if (Now.Hour > 12){Now.Hour = Now.Hour -12;}  // 24 to 12 hr
      // else {Now.Hour = Now.Hour ;};
    };
    RTC.write(Now);
  }
}
