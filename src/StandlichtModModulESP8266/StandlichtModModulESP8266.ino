/*
   Copyright (c) 2015, Majenko Technologies
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

 * * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

 * * Redistributions in binary form must reproduce the above copyright notice, this
     list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.

 * * Neither the name of Majenko Technologies nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "A6 US-Standlicht Mod"
#define APPSK  ""
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
  Serial.write("Normal");
  
  char temp[1800];
  snprintf(temp, 1800, 
"<style>\n"
"\n"
"    .button{                                                               \n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414); \n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color:#525252;\n"
"      \n"
"    }\n"
"    \n"
"    .button_selected{\n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414);\n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color: #E85831;\n"
"\t  text-shadow: 0 0 3px black , 0 0 5px #777777 ;\n"
"    }\n"
"    \n"
"    body{\n"
"      background-image: linear-gradient(8deg, #525252 , #252525  );\n"
"      }\n"
"      \n"
"    a{\n"
"      text-decoration: none;\n"
"      font-family: \"Arial\", sans-serif;\n"
"      \n"
"      \n"
"      } \n"
"    \n"
"    h1{\n"
"      text-align: center;\n"
"      font-family: \"Arial\", sans-serif;\n"
"\t  font-size:6em;\n"
"\t  font-weight: bold;\n"
"      color: white;\n"
"\t  text-shadow: 0 0 1em #D4B434;\n"
"      \n"
"      }  \n"
"      \n"
" </style>\n"
"\n"
"<html>\n"
"    <body>\n"
"\t  <br><br>\n"
"      <h1>A6 4F Scheinwerfer</h1>\n"
"\t  <br><br>\n"
"      <a href = \"/Normal\"><Button class = \"button_selected\">US-Standlicht</button></a><br><br>\n"
"      <a href = \"/PoliceMode\"><Button class = \"button\">Police Mode</button></a><br><br>\n"
"      <a href = \"/BlinkerSpam\"><Button class = \"button\">Blinker Spam</button></a><br><br>\n"
"    </body>\n"
"   </html>"
);
  
  server.send(200, "text/html",temp);
  }

void Normal(){
  Serial.write("Normal");

  char temp[1800];
  snprintf(temp, 1800, 
"<style>\n"
"\n"
"    .button{                                                               \n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414); \n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color:#525252;\n"
"      \n"
"    }\n"
"    \n"
"    .button_selected{\n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414);\n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color: #E85831;\n"
"\t  text-shadow: 0 0 3px black , 0 0 5px #777777 ;\n"
"    }\n"
"    \n"
"    body{\n"
"      background-image: linear-gradient(8deg, #525252 , #252525  );\n"
"      }\n"
"      \n"
"    a{\n"
"      text-decoration: none;\n"
"      font-family: \"Arial\", sans-serif;\n"
"      \n"
"      \n"
"      } \n"
"    \n"
"    h1{\n"
"      text-align: center;\n"
"      font-family: \"Arial\", sans-serif;\n"
"\t  font-size:6em;\n"
"\t  font-weight: bold;\n"
"      color: white;\n"
"\t  text-shadow: 0 0 1em #D4B434;\n"
"      \n"
"      }  \n"
"      \n"
" </style>\n"
"\n"
"<html>\n"
"    <body>\n"
"\t  <br><br>\n"
"      <h1>A6 4F Scheinwerfer</h1>\n"
"\t  <br><br>\n"
"      <a href = \"/Normal\"><Button class = \"button_selected\">US-Standlicht</button></a><br><br>\n"
"      <a href = \"/PoliceMode\"><Button class = \"button\">Police Mode</button></a><br><br>\n"
"      <a href = \"/BlinkerSpam\"><Button class = \"button\">Blinker Spam</button></a><br><br>\n"
"    </body>\n"
"   </html>"
);
  
  server.send(200, "text/html",temp);
  }

void PoliceMode(){
  Serial.write("Police");

  char temp[1800];
  snprintf(temp, 1800, 
  "<style>\n"
"\n"
"    .button{                                                               \n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414); \n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color:#525252;\n"
"      \n"
"    }\n"
"    \n"
"    .button_selected{\n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414);\n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color: #E85831;\n"
"\t  text-shadow: 0 0 3px black , 0 0 5px #777777 ;\n"
"    }\n"
"    \n"
"    body{\n"
"      background-image: linear-gradient(8deg, #525252 , #252525  );\n"
"      }\n"
"      \n"
"    a{\n"
"      text-decoration: none;\n"
"      font-family: \"Arial\", sans-serif;\n"
"      \n"
"      \n"
"      } \n"
"    \n"
"    h1{\n"
"      text-align: center;\n"
"      font-family: \"Arial\", sans-serif;\n"
"\t  font-size:6em;\n"
"\t  font-weight: bold;\n"
"      color: white;\n"
"\t  text-shadow: 0 0 1em #D4B434;\n"
"      \n"
"      }  \n"
"      \n"
" </style>\n"
"\n"
"<html>\n"
"    <body>\n"
"\t  <br><br>\n"
"      <h1>A6 4F Scheinwerfer</h1>\n"
"\t  <br><br>\n"
"      <a href = \"/Normal\"><Button class = \"button\">US-Standlicht</button></a><br><br>\n"
"      <a href = \"/PoliceMode\"><Button class = \"button_selected\">Police Mode</button></a><br><br>\n"
"      <a href = \"/BlinkerSpam\"><Button class = \"button\">Blinker Spam</button></a><br><br>\n"
"    </body>\n"
"   </html>"
  );
  
  server.send(200, "text/html",temp);
  }

void BlinkerSpam(){
  Serial.write("BlinkerSpam");

  char temp[1700];
  snprintf(temp, 1700, 
  "<style>\n"
"\n"
"    .button{                                                               \n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414); \n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color:#525252;\n"
"      \n"
"    }\n"
"    \n"
"    .button_selected{\n"
"      display: block;\n"
"      width: 10em;\n"
"\t  height: 2em;\n"
"      border: none;\n"
"      background-image: linear-gradient(5deg, #EE691D, #FAD414);\n"
"      cursor: pointer;\n"
"      text-align: center;\n"
"      border-radius: 20px;\n"
"      font-size: 6em;\n"
"      color: #E85831;\n"
"\t  text-shadow: 0 0 3px black , 0 0 5px #777777 ;\n"
"    }\n"
"    \n"
"    body{\n"
"      background-image: linear-gradient(8deg, #525252 , #252525  );\n"
"      }\n"
"      \n"
"    a{\n"
"      text-decoration: none;\n"
"      font-family: \"Arial\", sans-serif;\n"
"      \n"
"      \n"
"      } \n"
"    \n"
"    h1{\n"
"      text-align: center;\n"
"      font-family: \"Arial\", sans-serif;\n"
"\t  font-size:6em;\n"
"\t  font-weight: bold;\n"
"      color: white;\n"
"\t  text-shadow: 0 0 1em #D4B434;\n"
"      \n"
"      }  \n"
"      \n"
" </style>\n"
"\n"
"<html>\n"
"    <body>\n"
"\t  <br><br>\n"
"      <h1>A6 4F Scheinwerfer</h1>\n"
"\t  <br><br>\n"
"      <a href = \"/Normal\"><Button class = \"button\">US-Standlicht</button></a><br><br>\n"
"      <a href = \"/PoliceMode\"><Button class = \"button\">Police Mode</button></a><br><br>\n"
"      <a href = \"/BlinkerSpam\"><Button class = \"button_selected\">Blinker Spam</button></a><br><br>\n"
"    </body>\n"
"   </html>"
  );
  
  server.send(200, "text/html",temp);
  }  

  

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/PoliceMode", PoliceMode);
  server.on("/Normal", Normal);
  server.on("/BlinkerSpam", BlinkerSpam);
  server.begin();
  Serial.println("HTTP server started");
}



void loop() {
  server.handleClient();
}
