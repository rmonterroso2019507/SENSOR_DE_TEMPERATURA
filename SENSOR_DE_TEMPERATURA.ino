/*
 * 
 Fundacion Kinal
 Centro Educativo Tecnico Laboral KINAL
 Electronica
 Grado:5to A
 Nombre:Roberto Monterroso
 Carne :2019507
 */
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>

#define Direccion_LCD 0x27
#define FILAS 2
#define COLUMNAS 16
#define Pin_de_datos 2
#define LED_R 3
#define LED_G 5
#define LED_A 7

int Fahrenheit;
int OFahrenheit();
int Celsius;
int ICelsius();
void LCD_Temperature();
byte Termometro[] = {
  B11111,
  B01010,
  B01010,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};
byte Signo_de_grados[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte Copo_de_Nieve[] = {
  B10101,
  B01110,
  B00100,
  B11111,
  B00100,
  B01110,
  B10101,
  B00000
};
byte Fuego[] = {
  B10100,
  B01010,
  B01111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
byte Persona[] = {
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110,
  B01110,
  B00000
};
OneWire ourWire(2);
DallasTemperature SENSOR(&ourWire); 
LiquidCrystal_I2C LCD_Roberto(Direccion_LCD, COLUMNAS, FILAS);
void setup() {
  delay(1000);
  Serial.begin(9600);
  SENSOR.begin();
  pinMode(LED_R , OUTPUT);
  pinMode(LED_G , OUTPUT);
  pinMode(LED_A, OUTPUT);
  LCD_Roberto.begin(16, 2);
  LCD_Roberto.init();
  LCD_Roberto.backlight();
  LCD_Roberto.createChar(1, Termometro);
  LCD_Roberto.write(1);
  LCD_Roberto.createChar(2, Signo_de_grados);
  LCD_Roberto.write(2);
  LCD_Roberto.createChar(3, Copo_de_Nieve);
  LCD_Roberto.write(3);
  LCD_Roberto.createChar(4, Fuego);
  LCD_Roberto.write(4);
  LCD_Roberto.createChar(5, Persona);
  LCD_Roberto.write(5);
}

void loop() 
{
   LCD_Temperature(); 
}
 int ICelsius(){
  SENSOR.requestTemperatures();
  int C = SENSOR.getTempCByIndex(0); 
  return C;
}
 int OFahrenheit(){
  SENSOR.requestTemperatures();
  int F = SENSOR.getTempFByIndex(0); 
  return F;
}

 void LCD_Temperature(){
 Fahrenheit = OFahrenheit();
 Celsius = ICelsius();
  if(Celsius > 30){
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.print("MEDIDOR");
    LCD_Roberto.setCursor(10,0);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(0,1);
    LCD_Roberto.print(SENSOR.getTempCByIndex(0));
    LCD_Roberto.setCursor(5,1);
    LCD_Roberto.write(2);
    LCD_Roberto.setCursor(6,1);
    LCD_Roberto.print("C");
    LCD_Roberto.setCursor(7,1);
    LCD_Roberto.write(4);
    LCD_Roberto.setCursor(9,1);
    LCD_Roberto.print(SENSOR.getTempFByIndex(0));
    LCD_Roberto.setCursor(14,1);
    LCD_Roberto.write(2);
    LCD_Roberto.setCursor(15,1);
    LCD_Roberto.print("F");
    digitalWrite(LED_R , HIGH);
    digitalWrite(LED_G , LOW);
    digitalWrite(LED_A, LOW);
    }
  if(Celsius > 15 && Celsius < 30){
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.print("MEDIDOR");
    LCD_Roberto.setCursor(10,0);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(0,1);
    LCD_Roberto.print(SENSOR.getTempCByIndex(0));
    LCD_Roberto.setCursor(5,1);
    LCD_Roberto.write(2);
    LCD_Roberto.setCursor(6,1);
    LCD_Roberto.print("C");
    LCD_Roberto.setCursor(7,1);
    LCD_Roberto.write(5);
    LCD_Roberto.setCursor(9,1);
    LCD_Roberto.print(SENSOR.getTempFByIndex(0));
    LCD_Roberto.setCursor(14,1);
    LCD_Roberto.write(2);
    LCD_Roberto.setCursor(15,1);
    LCD_Roberto.print("F");
    digitalWrite(LED_R , LOW);
    digitalWrite(LED_G , HIGH);
    digitalWrite(LED_A, LOW); 

  }
  if(Celsius < 15 ){
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.print("MEDIDOR");
    LCD_Roberto.setCursor(10,0);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(0,1);
    LCD_Roberto.print(SENSOR.getTempCByIndex(0));
    LCD_Roberto.setCursor(5,1);
    LCD_Roberto.write(2);
    LCD_Roberto.setCursor(6,1);
    LCD_Roberto.print("C");
    LCD_Roberto.setCursor(7,1);
    LCD_Roberto.write(3);
    LCD_Roberto.setCursor(9,1);
    LCD_Roberto.print(SENSOR.getTempFByIndex(0));
    LCD_Roberto.setCursor(14,1);
    LCD_Roberto.write(2);
    LCD_Roberto.setCursor(15,1);
    LCD_Roberto.print("F");
    digitalWrite(LED_R , LOW);
    digitalWrite(LED_G , LOW);
    digitalWrite(LED_A, HIGH); 
  }
  }
