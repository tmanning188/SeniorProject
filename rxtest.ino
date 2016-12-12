#include <LiquidCrystal.h>

//Function declarations
void ororx(void);
void orodrive(double rpm1, double rpm2);
void orolcd(double ch1, double ch2);

//Initialize RPMs for each wheel
double ch1;
double ch2;

//format for pwm pins:
// Motor - (+/-)
int leftposhigh = 3; //paired with pin 6
int leftneghigh = 9; //paired with pin 5
int rightposhigh = 10; //paired with pin 8
int rightneghigh = 11; //paired with pin 7

int leftposlow = 5; //paired with pin 9
int leftneglow = 6; //paired with pin 3
int rightposlow = 7; //paired with pin 10
int rightneglow = 8; //paired with pin 11

//LiquidCrystal lcd(13, 12, 8, 7, 6, 5);

void setup() {

  //set pins as input to enable pulse width reading
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  
  pinMode(leftposhigh, OUTPUT);
  pinMode(leftneghigh, OUTPUT);
  pinMode(rightposhigh, OUTPUT);
  pinMode(rightposhigh, OUTPUT);

  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  // set up the LCD's number of columns and rows:
 // lcd.begin(16, 2);
  // Print a message to the LCD.
 // lcd.print("RPM:");
 // lcd.setCursor(0,1);
 // lcd.print("Speed:");

  //set baud rate for Serial communication
  Serial.begin(9600);
  
}

void loop() {
  ororx();
  orodrive(ch1, ch2);
//  orolcd(ch1, ch2);
}

void ororx(void) {
  //measure pulse widths from RX
  ch1 = pulseIn(2, HIGH);
  ch2 = pulseIn(4, HIGH);


  //Maximum RPM is set to 400 RPM
  //Calculations to generate RPM from TX/RX are based on Max RPM
  
//Math to set neutral position from TX channel 1 to 0 RPM
  
  // sets the range of neutral data to 0
  if(ch1>1462 && ch1<1499){
    ch1=0;  
  }
  // sets the positive range of data to a RPM value
  
  if(ch1>0){
    ch1 -=1499;
    ch1 *=.67;
  }
  // sets the negative range
  if(ch1<0){
    ch1*= 0.93; // for some reason ch1 was reading negative values without this statement
  }


  //Math to set neutral position from TX channel 2 to 0 RPM
  if(ch2>1490 && ch2<1520) ch2=0; // sets the range of neutral data to 0
  if(ch2>0){
    ch2-=1500;
    ch2*=0.53;
  }
  if(ch2<0){
    ch2 *= 0.92;
  }
  if(ch1>252) ch1=252;
  if(ch1<-252) ch1 = -252;
  if(ch2>252) ch2=252;
  if(ch2<-252) ch2=-252;


  //Print Channel 1 RPM
  Serial.print("Channel 1:");
  Serial.println(ch1);

  //Print Channel 2 RPM
  Serial.print("Channel 2:");
  Serial.println(ch2);

  //Delay for testing purposes
  //delay(250);
}


void orodrive(double ch1, double ch2){
  if(ch1>0){
   analogWrite(leftposhigh, ch1);
   analogWrite(rightposhigh, ch1);
   digitalWrite(leftneglow, HIGH);
   digitalWrite(rightneglow, HIGH);
   digitalWrite(leftposlow, LOW);
   digitalWrite(leftposlow, LOW);
  }
  if(ch1<0){
    analogWrite(leftneghigh,-ch1);
    analogWrite(rightneghigh,-ch1);
    digitalWrite(leftposlow,HIGH);
    digitalWrite(rightposlow,HIGH);
  }
  if(ch1 == 0){
    analogWrite(leftposhigh, 0);
    analogWrite(leftneghigh, 0);
    analogWrite(rightposhigh,0);
    analogWrite(rightneghigh, 0);
    digitalWrite(leftposlow,LOW);
    digitalWrite(leftneglow,LOW);
    digitalWrite(rightposlow,LOW);
    digitalWrite(rightneglow,LOW);
  }
}

//void orolcd(double ch1, double ch2){
//  double rpm, fast;
//  rpm = ((82 + 73) / 2) * (ch1/252);

//  fast=rpm/60*0.33274;

//  lcd.setCursor(5, 0);
//  lcd.print(rpm);
//  lcd.setCursor(7,1);
//  lcd.print(fast);
//  delay(250);
  
//}

