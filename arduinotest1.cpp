// Motor driver pin connections
const int ENA = 5;  // Speed control for left motor
const int IN1 = 2;
const int IN2 = 3;

const int ENB = 6;  // Speed control for right motor
const int IN3 = 4;
const int IN4 = 7;

String inputCommand = "";

void setup() {
  // Initialize motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start Serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    inputCommand = Serial.readStringUntil('\n');
    inputCommand.trim();  // Clean whitespace

    if (inputCommand == "forward") {
      moveForward();
    } else if (inputCommand == "left") {
      turnLeft();
    } else if (inputCommand == "right") {
      turnRight();
    } else if (inputCommand == "stop") {
      stopMotors();
    }
  }
}

// Movement functions
void moveForward() {
  analogWrite(ENA, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 200);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, 150);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
