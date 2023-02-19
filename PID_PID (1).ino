#include <NewPing.h>
#define PIN_TRIG 2
#define PIN_ECHO 3
#define MAX_DISTANCE 200 
NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

int leftDirPin = 4;
int leftSpeedPin = 5;

int rightDirPin = 7;
int rightSpeedPin = 6;

int runSpeed = 50;

void go()
{
  analogWrite (leftSpeedPin, runSpeed);
  analogWrite (rightSpeedPin, runSpeed);
}

void goForward()
{
    digitalWrite (leftDirPin, HIGH);
    digitalWrite (rightDirPin, HIGH);
    go();
}

void turnLeft()
{
  digitalWrite(leftDirPin, HIGH);
  digitalWrite(rightDirPin, LOW);
  go();
}

void pidForward(int xLeft, int xRight)
{
  analogWrite (leftSpeedPin, xLeft);
  analogWrite (rightSpeedPin, xRight);
  digitalWrite (leftDirPin, HIGH);
  digitalWrite (rightDirPin, HIGH);
}

void go2(int xLeft, int xRight)
{
  analogWrite (leftSpeedPin, xLeft);
  analogWrite (rightSpeedPin, xRight);
}
void setup() {
  Serial.begin(9600);
  pinMode(leftDirPin, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightDirPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
    delay(50);
    unsigned int distance = sonar.ping_cm();
    Serial.print(distance);
    Serial.println("см");
    int Ust = 10;
    int err = distance - Ust;
    int k = 1.5;
    int U = err*k;
    int Vleft = runSpeed - U;
    int Vright = runSpeed + U;
    pidForward(Vleft, Vright);
}
