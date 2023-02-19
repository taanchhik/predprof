int leftLinePin = A0;
int rightLinePin = A1;

int leftDirPin = 4;
int leftSpeedPin = 5;

int rightDirPin = 7;
int rightSpeedPin = 6;

void go(int leftSpeed, int rightSpeed) {
  digitalWrite(leftDirPin, leftSpeed > 0);
  digitalWrite(rightDirPin, rightSpeed > 0);

  leftSpeed = abs(constrain(leftSpeed, -255, 255));
  rightSpeed = abs(constrain(rightSpeed, -255, 255));
  
  analogWrite(leftSpeedPin, leftSpeed);
  analogWrite(rightSpeedPin, rightSpeed);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(leftDirPin, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightDirPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);
}

void loop() {
  int runSpeedLeft = 30;
  int runSpeedRight = 30;
  if (analogRead(A0) > 750){
    runSpeedLeft += 10;
    runSpeedRight -= 10;
  } 
  if (analogRead(A0) > 750 and analogRead(A1) > 750){
    runSpeedLeft -= 5;
    runSpeedRight -= 5;
  }
    if (analogRead(A0) <= 750 and analogRead(A1) <= 750){
    runSpeedLeft -= 10;
  }
    if (analogRead(A0) > 750 and analogRead(A1) <= 750){
    runSpeedLeft += 5;
  }
    if (analogRead(A0) <= 750 and analogRead(A1) > 750){
    runSpeedRight += 10;
  }
  if (analogRead(A1) > 750){
    runSpeedRight += 10;
    runSpeedLeft -= 10;
  } 
  Serial.println(analogRead(A0));
  go(runSpeedLeft, runSpeedRight);
}
