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
  lcd.print("Git Gud!");
}

void loop() {
  // put your main code here, to run repeatedly:
  
    // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

  
}
