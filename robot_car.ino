#include <Servo.h>
#include <AFMotor.h>

#define Echo A0
#define Trig A1
#define motor 10
#define Speed 170
#define spoint 103

int currentMode = 0; // Default mode is Bluetooth control

char command = 'S'; // Default command is 'Stop'
int distance;
int left_distance = -1;  // Initialize to invalid value
int right_distance = -1; // Initialize to invalid value
bool modeSelectionPending = false;
int pendingMode = 0;

Servo servo;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

#define BLUETOOTH_CONTROL 0
#define OBSTACLE_AVOIDANCE 1
#define VOICE_CONTROL 2

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  servo.attach(motor);
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);
}

void loop() {
  // Check for mode selection command
  if (Serial.available() > 0) {
    char newCommand = Serial.read();
    Serial.println(newCommand);

    if (newCommand == 'M') {  
      modeSelectionPending = true;
    } else if (modeSelectionPending) {
      int newMode = newCommand - '0';  // Convert char to int
      selectMode(newMode);
      modeSelectionPending = false;
    } else if (newCommand == 'Z') {
      checkDistance();
    } else {
      // If not a mode selection command, handle control commands
      command = newCommand; // Update command value
    }
  }
  

  // Execute control function based on current mode
  switch (currentMode) {
    case BLUETOOTH_CONTROL:
      Bluetoothcontrol();
      break;
    case OBSTACLE_AVOIDANCE:
      Obstacle();
      break;
    case VOICE_CONTROL:
      voicecontrol();
      break;
    default:
      Serial.println("Unknown mode.");
  }
}

void selectMode(int newMode) {
  if (newMode >= BLUETOOTH_CONTROL && newMode <= VOICE_CONTROL) { 
    // Validate mode selection
    currentMode = newMode;
    Serial.print("Mode switched to ");
    Serial.println(newMode);
  } else {
    Serial.println("Invalid mode selection.");
  }
}

void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    delay(100); // Delay to ensure complete command reception
  }

  switch (command) {
    case 'F':
      forward();
      break;
    case 'B':
      backward();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    case 'S':
      stop();
      break;
    default:
      // Unknown command, do nothing
      break;
  }
}

void Obstacle() {
  distance = ultrasonic();

  if (distance <= 12) {
    stop();
    backward();
    delay(100);
    stop();
    left_distance = leftsee();
    servo.write(spoint);
    delay(300); // Adjusted delay for better response
    right_distance = rightsee();
    servo.write(spoint);
    delay(300); // Adjusted delay for better response

    if (left_distance < right_distance) {
      right();
      delay(500);
      stop();
      delay(200);
    } else if (left_distance > right_distance) {
      left();
      delay(500);
      stop();
      delay(200);
    }
  } else {
    forward();
  }
}

void voicecontrol() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
  }

  switch (command) {
    case '^':
      forward();
      break;
    case '-':
      backward();
      break;
    case '<':
      left_distance = leftsee();
      servo.write(spoint);
      delay(300); // Adjusted delay for better response
      if (left_distance >= 10) {
        left();
        delay(500);
        stop();
      } else {
        stop();
      }
      break;
    case '>':
      right_distance = rightsee();
      servo.write(spoint);
      delay(300); // Adjusted delay for better response
      if (right_distance >= 10) {
        right();
        delay(500);
        stop();
      } else {
        stop();
      }
      break;
    case '*':
      stop();
      break;
    default:
      // Unknown command, do nothing
      break;
  }
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

void stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH);
  long cm = t / 29 / 2; //time convert distance
  return cm;
}

int rightsee() {
  servo.write(20);
  delay(300); // Adjusted delay for better response
  int distance = ultrasonic();
  servo.write(spoint);
  return distance;
}

int leftsee() {
  servo.write(180);
  delay(300); // Adjusted delay for better response
  int distance = ultrasonic();
  servo.write(spoint);
  return distance;
}

void checkDistance() {
  distance = ultrasonic();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}