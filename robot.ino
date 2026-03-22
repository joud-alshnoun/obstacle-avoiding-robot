#include <NewPing.h>

// تعريف المداخل للسينسور
#define TRIG_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200

// الموتور A
#define IN1 2
#define IN2 3

// الموتور B
#define IN3 4
#define IN4 5

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(100);  // مهلة بسيطة لقراءة السينسور
  int distance = sonar.ping_cm();
  Serial.print("المسافة: ");
  Serial.println(distance);

  if (distance > 0 && distance < 20) {
    // إذا في عائق قريب
    stopCar();
    delay(200);
    turnRight();
    delay(500);
  } else {
    moveForward();
  }
}

// فنكشنز التحكم بالموتور
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
