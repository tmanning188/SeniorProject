  #include <LiquidCrystal.h>

LiquidCrystal lcd(12,8,2,4,5,6);

  int lhPWM = 3;
  int hlPWM = 9;
  int lhPWM2 = 10;
  int hlPWM2 = 11;

void setup() {
  // put your setup code here, to run once:

  pinMode(lhPWM, OUTPUT);
  pinMode(hlPWM, OUTPUT);
  pinMode(lhPWM2, OUTPUT);
  pinMode(hlPWM2, OUTPUT);

  analogWrite(lhPWM, 127);
  analogWrite(hlPWM, 127);
  analogWrite(lhPWM2, 127);
  analogWrite(hlPWM2, 127);

    // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("RPM:");
  lcd.setCursor(0,1);
  lcd.print("Speed:");
}

void loop() {
  // put your main code here, to run repeatedly:
  double rpm;
  double velocity;

  for(rpm=0;rpm<450;rpm=rpm+50){
    velocity=rpm/60*0.33274;
    lcd.setCursor(5, 0);
    lcd.print(rpm);
    lcd.setCursor(7,1);
    lcd.print(velocity);
    delay(750);
  }
  
}
