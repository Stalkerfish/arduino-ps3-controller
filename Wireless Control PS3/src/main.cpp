#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX

void setup() {

  Serial.begin(9600);   // inicia comunicação serial do arduino
  bluetooth.begin(9600);    //inicia comunicação serial do bluetooth

  pinMode(LED_BUILTIN, OUTPUT); //configura o led do pino 13 como saída

  digitalWrite(LED_BUILTIN, LOW); // inicia o led em estado LOW

}

void loop() {
  if (bluetooth.available() > 0){
    int incomingByte = bluetooth.read();

    if(incomingByte == 'H'){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("LED LIGADO!");
    }
    if (incomingByte == 'L'){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.print("LED DESLIGADO!");
    }
    
  }
}