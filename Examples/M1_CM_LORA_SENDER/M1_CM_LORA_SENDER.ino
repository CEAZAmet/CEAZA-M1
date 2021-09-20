/*
 * This sketch is an application example of LoRa.h and LowPwer.h with a 433MHz LoRa module
 * for data transmitting and go to sleep in CEAZA MEGA + M1 system
 * Is highly recommend do not use the M1 module without LoRa and GNSS antenas connected
 * to avoid damage the respective modules.
 * 
 * You have to intall LoRa library
 * https://github.com/sandeepmistry/arduino-LoRa
 * 
 * and LowPower library
 * https://github.com/rocketscream/Low-Power
 * 
 * Remember to select the "Arduino Mega or Mega2560" board for CEAZA MEGA
 */
#include <SPI.h>
#include <LoRa.h>
#include "LowPower.h"

// Pin definition
#define M1_3V3_EN_PIN   35
#define M1_VLORA_EN_PIN 33
#define LORA_SS_PIN     22
#define LORA_RESET_PIN  23
#define LORA_DIO0_PIN   2
#define FLASH_SS_PIN    32
#define SD_SS_PIN       53
#define LED_PIN         13

// LoRa setup definition
#define LORA_FREC       433E6   //(`433E6`, `866E6`, `915E6`)
#define LORA_SF         9       //6 to 12
#define LORA_TX_POW     18      //2 to 20
#define LORA_BANDWIDTH  125E3   //`7.8E3`, `10.4E3`, `15.6E3`, `20.8E3`, `31.25E3`, `41.7E3`, `62.5E3`, `125E3`, and `250E3`.

// Message counter
int counter = 0;

void setup() {
  // MCU I/O definition
  pinMode(FLASH_SS_PIN,OUTPUT);digitalWrite(FLASH_SS_PIN,HIGH);       // SPI Flash communication disabled
  pinMode(SD_SS_PIN,OUTPUT);digitalWrite(SD_SS_PIN,HIGH);             // SPI microSD communication disabled
  pinMode(LED_PIN,OUTPUT);digitalWrite(LED_PIN,LOW);                  // Built in LED off
  pinMode(M1_3V3_EN_PIN,OUTPUT);digitalWrite(M1_3V3_EN_PIN,HIGH);     // dedicated M1 3.3V power supply on 
  delay(10);                                                          // step down converter Start time
  pinMode(M1_VLORA_EN_PIN,OUTPUT);digitalWrite(M1_VLORA_EN_PIN,HIGH); // turn-on LoRa module

  Serial.begin(115200);
  Serial.println("\nM1 CEAZA Mega LoRa Sender");
  
  LoRa.setPins(LORA_SS_PIN, LORA_RESET_PIN, LORA_DIO0_PIN);
  Serial.print("LORA_TX_POW,");Serial.print(LORA_TX_POW);
  Serial.print(",LORA_FREC_MHz,");Serial.print(LORA_FREC/1000000);
  Serial.print(",LORA_SF,");Serial.print(LORA_SF);
  Serial.print(",LORA_BANDWIDTH_KHz,");Serial.print(LORA_BANDWIDTH/1000);
  Serial.println();

  // Begin LoRa module
  if (!LoRa.begin(433E6)) {    
    Serial.println("Starting LoRa failed!");    
    while (1);
  }
  LoRa.setTxPower(LORA_TX_POW);
  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setSignalBandwidth(LORA_BANDWIDTH);

  // Once the LoRa module is not in use the module is turn-off to reduce the power consumption
  digitalWrite(M1_VLORA_EN_PIN,LOW);  // Turn-off the LoRa module
  digitalWrite(M1_3V3_EN_PIN,LOW);    // Turn-off the M1 +3V3 power supply
}

void loop() {
  // Turn-on LoRa module
  digitalWrite(M1_3V3_EN_PIN,HIGH);delay(10);
  digitalWrite(M1_VLORA_EN_PIN,HIGH);

  // LoRa Module init. it must be initializaed every time is turned on
  if (!LoRa.begin(433E6)) {    Serial.println("Starting LoRa failed!"); }
  else{
    digitalWrite(LED_PIN,HIGH);        // LED is turn on while the module is transmitting data
    LoRa.setTxPower(LORA_TX_POW);
    LoRa.setSpreadingFactor(LORA_SF);
    LoRa.setSignalBandwidth(LORA_BANDWIDTH);
    
    Serial.print("Sending packet: "); 
    Serial.println(counter);

    // send packet
    LoRa.beginPacket();
    LoRa.print("hello ");
    LoRa.print(counter);    
    LoRa.endPacket();
  
    counter++;
    
    digitalWrite(LED_PIN,LOW);      // Turn off transmitting LED
  }
  
  // Turn-off LoRa module to save energy
  digitalWrite(M1_VLORA_EN_PIN,LOW);
  digitalWrite(M1_3V3_EN_PIN,LOW);

  // Go to sleep 4S
  Serial.flush();
  LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF); 
}
