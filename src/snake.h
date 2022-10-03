
void animateCenterSnake()
{
    uint8_t sinBeatLeds1 = beatsin8(10, 58, 61, 0, 0);
    uint8_t sinBeatVals1 = beatsin8(10, 40, 80, 0, 0);
    leds[sinBeatLeds1].nscale8_video(sinBeatVals1);

    uint8_t sinBeatLeds2 = beatsin8(10, 58, 61, 400, 0);
    uint8_t sinBeatVals2 = beatsin8(10, 20, 40, 400, 0);
    leds[sinBeatLeds2].nscale8_video(sinBeatVals2);

    uint8_t sinBeatLeds3 = beatsin8(10, 58, 61, 800, 0);
    uint8_t sinBeatVals3 = beatsin8(10, 10, 20, 800, 0);
    leds[sinBeatLeds3].nscale8_video(sinBeatVals3);
}