#include <Wire.h>
#include <LCD.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//Variables varias
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;
int led7 = 6;
int led8 = 5;
int led9 = 4;
int buzzer = A0;
int interruptor = 13;
//Variables sensor de ultrasonidos
long distancia;
long tiempo;
int pinecho = 2; // echo es el que recibe el pulso
int pintrig = 3; // trig es el que emite el pulso

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SENS PROXIMIDAD");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(interruptor, INPUT);
  pinMode(pinecho, INPUT);
  pinMode(pintrig, OUTPUT);
}

void loop() {
                              //Proceso de medida del sensor de ultrasonidos
  digitalWrite(pintrig, LOW); // para estabilizar el sensor
  delay(10);
  digitalWrite(pintrig, HIGH);
  delay(10); // generamos un pulso ultrasonico durante 10 milisegundos
  digitalWrite(pintrig, LOW);
  
  tiempo = pulseIn(pinecho, HIGH); // almacenamos en la variable tiempo el
                                   //tiempo que el pin echo ha estado recibiendo
                                   //un pulso "HIGH"
  distancia = ((tiempo/2) / 29);
  /* El pin echo almacena el tiempo que tarda la onda del pulso de ida y vuelta,
  por ello la dividimos entre 2. Luego la dividimos entre 29 para cambiar de 
  unidad la velocidad del sonido */
  /*
  if(digitalRead(interruptor) == HIGH) { 
    //lcd.noDisplay();
    //lcd.off();
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0);
  }
  else {
  */
  lcd.on();
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Distancia:");
  lcd.print(distancia);
  lcd.print("cm");
  delay(400);
  /*
  if(distancia < 101 && distancia > 90) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0); }
  if(distancia < 91 && distancia > 80) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0); }
  if(distancia < 81 && distancia > 70) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0); }
  if(distancia < 71 && distancia > 60) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0); }
  if(distancia < 61 && distancia > 50) {
     digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0); }
  if(distancia < 51 && distancia > 40) {
     digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 0); }
  if(distancia < 41 && distancia > 30) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 1024);
    delay(400);
    analogWrite(buzzer, 0);
    delay(400); }
    if(distancia < 31 && distancia > 20) {
      digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, LOW);
    analogWrite(buzzer, 1024);
    delay(200);
    analogWrite(buzzer, 0);
    delay(200); }
    if(distancia < 21 && distancia > 10) {
      digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    analogWrite(buzzer, 1024);
    delay(100);
    analogWrite(buzzer, 0);
    delay(100); }
    if(distancia < 11 && distancia > 0) {
      digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    delay(50);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    delay(50);
    analogWrite(buzzer, 1024); }
    if(distancia > 101) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW); 
    analogWrite(buzzer, 0); }
    */
    //Serial.println(distancia);

}
  
  
  
