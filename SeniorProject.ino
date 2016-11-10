  #include <LiquidCrystal.h>

LiquidCrystal lcd(12,8,2,4,5,6);

  int highinput = 3;
  int highinput2 = 9;
  int lowinput = 10;
  int lowinput2 = 11;

void setup() {
  // put your setup code here, to run once:

  pinMode(highinput, OUTPUT);
  pinMode(highinput2, OUTPUT);
  pinMode(lowinput, OUTPUT);
  pinMode(lowinput2, OUTPUT);

  analogWrite(highinput, 127);
  analogWrite(highinput2, 127);
  digitalWrite(lowinput, HIGH);
  digitalWrite(lowinput2, HIGH);

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
