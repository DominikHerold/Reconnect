# Reconnect

Simple reconnects to a wifi every 20 seconds. After a GET request the ESP8266 goes into deep-sleep mode for 20 seconds.

## Configuration

Connect `D0` with `RST` via a cable. And configure [following](https://github.com/DominikHerold/Reconnect/blob/master/reconnect/reconnect.ino#L3-L12) part:

    const char* ssid = "foo";
    const char* password = "foo";
    const char* host = "192.168.10.1";
    int port = 80;

