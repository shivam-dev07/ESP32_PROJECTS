#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"

#define I2S_DOUT      25
#define I2S_BCLK      27
#define I2S_LRC       26

Audio audio;


void setup()
{

  Serial.begin(115200);

  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin( "Raju", "thekingsuv1901");

  while (WiFi.status() != WL_CONNECTED)
    delay(1500);

  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(150);
  audio.connecttohost("https://gigl-audio.sgp1.digitaloceanspaces.com/audios/82_368.mp3");
}

void loop()

{

  audio.loop();

}

void audio_info(const char *info) {
  Serial.print("audio_info: "); 
  Serial.println(info);
}
//https://gigl-audio.sgp1.digitaloceanspaces.com/audios/82_368.mp3 :-audi book wings of fire ep1
//https://gigl-audio.sgp1.digitaloceanspaces.com/audios/82_369.mp3 :-ep2
//http://pureplay.cdnstream1.com/6042_128.mp3 :- hip hop music
//http://mp3.ffh.de/radioffh/hqlivestream.mp3
//http://stream.zenolive.com/yg1qhsbaqv5tv :- 90s songs




