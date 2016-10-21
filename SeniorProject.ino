  
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

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(lhPWM, 127);

}
