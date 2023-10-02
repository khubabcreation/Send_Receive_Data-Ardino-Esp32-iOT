/// use the firebase esp32 version of mobizet and the version should be 3.12.1 keep  in mind other wise it through the error .


#include <heltec.h>
#include <Arduino.h>
#if defined(ESP32) || defined(PICO_RP2040)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
// LoRa settings
#define BAND 915E6 

#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://random-794f3-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyAWPvrGGTTbA78vYpp9fMiZE7dbUm5o-4M"
#define WIFI_SSID "Printwishes"
#define WIFI_PASSWORD "Cbf7932e"

FirebaseData firebaseData;
FirebaseJson json;
#define LED1_PIN 7  // Change this to the actual pin number of your first LED
#define LED2_PIN 55  
void setup()
{
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  Serial.println("------------------------------------");
  Serial.println("Connected...");
}



void loop(){
// {
//   if (Firebase.getString(firebaseData, "/light"))
//   {
//     String led1Status = firebaseData.stringData();

//     if (led1Status == "0")
//     {
//       digitalWrite(LED1_PIN, HIGH);
//     }
//     else if (led1Status == "off")
//     {
//       digitalWrite(LED1_PIN, LOW);
//     }
//   }

  // if (Firebase.getString(firebaseData, "/light"))
  // {
  //   String led2Status = firebaseData.stringData();

  //   if (led2Status == "0")
  //   {
  //     digitalWrite(LED2_PIN, HIGH);
  //   }
  //   else if (led2Status == "off")
  //   {
  //     digitalWrite(LED2_PIN, LOW);
  //   }
  // }

  // delay(1000);  // Delay between Firebase requests


 // Check for data changes in Firebase
  if (Firebase.getString(firebaseData, "/light")) {


      Serial.println(firebaseData.stringData().toInt());


    if (firebaseData.dataType() == "string") {
      String receivedData = firebaseData.stringData();
      Serial.print("Received data: ");
      Serial.println(receivedData);
    }
  }

  delay(100); 


}










// void loop()
// {
//   int Sdata = random(0, 1023);
//   Serial.println(Sdata);
//   delay(100);

//   // json.set("/Reading1", Sdata);
//   // json.set("/Reading2", Sdata - 100);
//   // json.set("/Reading3", Sdata - 59);

//   // Firebase.updateNode(firebaseData, "/Sensor", json);
// }
