#include <Arduino.h>
#include <SoftwareSerial.h>
#include <L298N.hpp>

SoftwareSerial bluetooth(2, 3); // RX, TX
L298N driver1 (10, 11, 4, 5, 6, 7);

void setup() {

  Serial.begin(9600);   // inicia comunicação serial do arduino
  bluetooth.begin(9600);    //inicia comunicação serial do bluetooth
  driver1.init();

  pinMode(LED_BUILTIN, OUTPUT); //configura o led do pino 13 como saída

  digitalWrite(LED_BUILTIN, LOW); // inicia o led em estado LOW
  driver1.safeStart();

}

void loop() {
  if (bluetooth.available() > 0){
    int incomingByte = bluetooth.read();

    if (incomingByte == '0'){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LED DESLIGADO!");
      bluetooth.println("Motor Desligado!");
      driver1.safeStart();
    }
    if (incomingByte == '1'){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED LIGADO!");
      bluetooth.println("Motor Ligado!");
      driver1.motorPower1(10, 255);
    }
    if (incomingByte == '3'){
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED LIGADO!");
      driver1.antiClockwise();
    }
    if (incomingByte == '4'){
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LED LIGADO!");
      driver1.clockwise();
    }
    
  }
}