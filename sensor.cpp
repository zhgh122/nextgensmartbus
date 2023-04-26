#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin1 = 2;
const int echoPin1 = 1;

const int trigPin2 = 4;
const int echoPin2 = 3;

const int trigPin3 = 6;
const int echoPin3 = 5;

const int trigPin4 = 8;
const int echoPin4 = 7;

int currentCount = 4;
bool occupied1 = false;
bool occupied2 = false;
bool occupied3 = false;
bool occupied4 = false;

byte customChar1[] = {
  B00000,
  B00010,
  B00010,
  B01100,
  B10010,
  B00010,
  B00110,
  B00110
};

byte customChar2[] = {
  B00000,
  B00000,
  B00000,
  B01100,
  B10010,
  B00010,
  B00010,
  B00010
};

byte customChar3[] = {
  B00000,
  B00000,
  B00000,
  B00110,
  B00110,
  B10010,
  B01010,
  B00110
};

byte customChar4[] = {
  B00001,
  B00001,
  B01111,
  B11001,
  B11011,
  B01101,
  B01001,
  B01001
};

void setup()
{
  lcd.begin();
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.createChar(2, customChar3);
  lcd.createChar(3, customChar4);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  lcd.setCursor(5, 0);
  lcd.write(byte(0));
  lcd.setCursor(6, 0);
  lcd.write(byte(1));
  lcd.setCursor(7, 0);
  lcd.write(byte(2));
  lcd.setCursor(9, 0);
  lcd.print(currentCount);
  lcd.setCursor(11, 0);
  lcd.write(byte(3));
}

void loop()
{
  // Sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(9);
  digitalWrite(trigPin1, LOW);
  
  long duration1 = pulseIn(echoPin1, HIGH);
  float distance1 = duration1 * 0.034 / 2;

  if (distance1 <= 10 && !occupied1) {
    occupied1 = true;
    currentCount--;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  if (distance1 > 10 && occupied1) {
    occupied1 = false;
    currentCount++;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  // Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(9);
  digitalWrite(trigPin2, LOW);
  
  long duration2 = pulseIn(echoPin2, HIGH);
  float distance2 = duration2 * 0.034 / 2;

  if (distance2 <= 10 && !occupied2) {
    occupied2 = true;
    currentCount--;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  if (distance2 > 10 && occupied2) {
    occupied2 = false;
    currentCount++;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  // Sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(9);
  digitalWrite(trigPin3, LOW);
  
  long duration3 = pulseIn(echoPin3, HIGH);
  float distance3 = duration3 * 0.034 / 2;

  if (distance3 <= 10 && !occupied3) {
    occupied3 = true;
    currentCount--;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  if (distance3 > 10 && occupied3) {
    occupied3 = false;
    currentCount++;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  // Sensor 4
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(9);
  digitalWrite(trigPin4, LOW);
  
  long duration4 = pulseIn(echoPin4, HIGH);
  float distance4 = duration4 * 0.034 / 2;

  if (distance4 <= 10 && !occupied4) {
    occupied4 = true;
    currentCount--;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }

  if (distance4 > 10 && occupied4) {
    occupied4 = false;
    currentCount++;
    lcd.setCursor(9, 0);
    lcd.print(currentCount);
  }
}
