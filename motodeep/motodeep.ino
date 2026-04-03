#include <Servo.h>
#include <AFMotor.h>

#define Echo A0
#define Trig A1
#define motor 10
#define Speed 170
#define spoint 103

char value;
int distance;
int Left;
int Right;
int L = 0;
int R = 0;

Servo servo;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

enum State { BLUETOOTH_CONTROL, OBSTACLE_AVOIDANCE };
State currentState = BLUETOOTH_CONTROL;

unsigned long previousMillis = 0;
const long interval = 100; // Check for obstacles every 100ms

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  servo.attach(motor);
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);
  servo.write(spoint); // Initialize servo to center position
}

void loop() {
  unsigned long currentMillis = millis();

  // Check for Bluetooth/voice commands
  Bluetoothcontrol();

  // Check for obstacles periodically
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Obstacle();
  }
}

void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);

    if (value == 'F' || value == '^') { // Forward command (Bluetooth or voice)
      forward();
      currentState = BLUETOOTH_CONTROL;
    } else if (value == 'B' || value == '-') { // Backward command (Bluetooth or voice)
      backward();
      currentState = BLUETOOTH_CONTROL;
    } else if (value == 'L' || value == '<') { // Left command (Bluetooth or voice)
      left();
      currentState = BLUETOOTH_CONTROL;
    } else if (value == 'R' || value == '>') { // Right command (Bluetooth or voice)
      right();
      currentState = BLUETOOTH_CONTROL;
    } else if (value == 'S' || value == '*') { // Stop command (Bluetooth or voice)
      Stop();
      currentState = BLUETOOTH_CONTROL;
    }
  }
}

void Obstacle() {
  if (currentState != BLUETOOTH_CONTROL) {
    distance = ultrasonic();
    if (distance <= 12) { // Obstacle detected
      Stop();
      backward();
      delay(100);
      Stop();

      L = leftsee(); // Check left distance
      servo.write(spoint); // Return servo to center
      delay(800);

      R = rightsee(); // Check right distance
      servo.write(spoint); // Return servo to center

      if (L < R) { // If left is clearer, turn right
        right();
        delay(500);
        Stop();
        delay(200);
      } else if (L > R) { // If right is clearer, turn left
        left();
        delay(500);
        Stop();
        delay(200);
      }
    } else { // No obstacle, move forward
      forward();
    }
  }
}

// Ultrasonic sensor distance reading function
int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH);
  long cm = t / 29 / 2; // Convert time to distance in cm
  return cm;
}

void forward() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void backward() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void right() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void left() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

int rightsee() {
  servo.write(20); // Turn servo to the right
  delay(800); // Wait for servo to move
  Left = ultrasonic(); // Measure distance
  return Left;
}

int leftsee() {
  servo.write(180); // Turn servo to the left
  delay(800); // Wait for servo to move
  Right = ultrasonic(); // Measure distance
  return Right;
}
