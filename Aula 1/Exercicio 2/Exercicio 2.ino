#include <SPI.h>
#include <Ethernet.h>

int fan = 4;

int pos = 0;
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x24, 0x70 };
byte ip[] = { 192,168,1,200 };
byte gateway[] = { 192, 168, 1, 199 };
byte subnet[] = { 255, 255, 255, 0 };
EthernetServer server(80);

String readString;

void setup() {
    Serial.begin(9600);
    while (!Serial)
    {
      ;
    }

    pinMode(fan, OUTPUT);

    Ethernet.begin(mac, ip);
    server.begin();
    Serial.print("server is at ");
    Serial.println(Ethernet.localIP())
}

void loop() {
  EthernetClient client = server.available();

  if(client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        if (readString.length() < 100) {
          readString += c;
        }
        if ( c == '\n') {
          Serial.println(readString);
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          client.println("<Title>Arduino Fan control switch </TITLE>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<H1>FAN Control</H1>");
          client.println("<hr />");
          client.println("<br />");
          client.println("<H2> Fan control with arduino Ethernet shield</H2>");
          client.println("<br />");
          client.println("<a href=\"/?button1on\"\">Turon On FAN</a>");
          client.println("<a href=\"/?button1off\"\">Turon Off FAN</a><br />");
          client.println("<br />");
          client.println("<br />");
          client.println("<br />");
          client.println("</BODY>");
          client.println("</HTML>");

          delay(1);
          client.stop();

          if (readString.indexOf("?button1off") >0) {
            digitalWrite(fan, HIGH);
          }
          if (readString.indexOf("?button1off" >0)) {
            digitalWrite(fan, LOW);
          }
          readString="";
        }
      }
    }
  }
}