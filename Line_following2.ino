#define trigPin 4 // Ultrasonic sensor trigger pin (connected to Arduino pin 4)
#define echoPin 2 // Ultrasonic sensor echo pin (connected to Arduino pin 2)
#define obstacleThreshold 30 // Distance threshold in centimeters to detect an obstacle

int mr1 = 9;  //motor right 1
int mr2 = 8;  //motor right 2
int ml1 = 10; //motor left 1
int ml2 = 11; //motor left 2
int right_sensor = 6;  //sensor right
int left_sensor = 7;   //sensor left
int enr = 3; //ENA
int enl = 5; //ENB

// Variables to store sensor values
int sl; //sensor value left
int sr; //sensor value right

// Motor speed and delay variables
int vspeed = 150;  //motor speed  
int tdelay = 20;   //delay time

void setup() {
  // Configure pins as inputs or outputs
  pinMode(right_sensor, INPUT);
  pinMode(left_sensor, INPUT);
  pinMode(mr1, OUTPUT);
  pinMode(ml1, OUTPUT);
  pinMode(mr2, OUTPUT);
  pinMode(ml2, OUTPUT);
  pinMode(enr, OUTPUT);
  pinMode(enl, OUTPUT);

  pinMode(trigPin, OUTPUT); // Set ultrasonic sensor trigger pin as output
  pinMode(echoPin, INPUT); // Set ultrasonic sensor echo pin as input
}

void loop() {
  // Read ultrasonic sensor data
  int distance = getDistance();

  // Check for obstacle
  if (distance < obstacleThreshold) {
    // If obstacle detected, stop the motors
    Stop();
  } else {
    // Otherwise, continue with line following behavior
    // Read sensor values
    sr = digitalRead(right_sensor);
    sl = digitalRead(left_sensor);

    // Determine motor behavior based on sensor readings
    if (sr == LOW && sl == LOW) {
      Forward();
    } else if (sr == HIGH && sl == LOW) {
      Right();
    } else if (sr == LOW && sl == HIGH) {
      Left();
    } else if (sr == HIGH && sl == HIGH) {
      Stop();
    }
  }
}

// Function to read distance from ultrasonic sensor
int getDistance() {
  // Clear trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Send 10 microsecond pulse to trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read echo pin and calculate distance based on pulse duration
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Convert pulse duration to distance in centimeters
  return distance;
}

// Function to move forward
void Forward() {
  digitalWrite(mr1, HIGH);
  digitalWrite(ml1, HIGH);
  digitalWrite(mr2, LOW);
  digitalWrite(ml2, LOW);
  analogWrite (enr, vspeed);
  analogWrite (enl, vspeed);
}

// Function to turn right
void Right() {
  while (sr == HIGH && sl == LOW) {
    digitalWrite(mr1, LOW);
    digitalWrite(ml1, HIGH);
    digitalWrite(mr2, LOW);
    digitalWrite(ml2, LOW);
    analogWrite (enr, vspeed);
    analogWrite (enl, vspeed);
    delay(tdelay);
    // Update sensor values
    sr = digitalRead(right_sensor);
    sl = digitalRead(left_sensor);
  }
}

// Function to turn left
void Left() {
  while (sr == LOW && sl == HIGH) {
    digitalWrite(mr1, HIGH);
    digitalWrite(ml1, LOW);
    digitalWrite(mr2, LOW);
    digitalWrite(ml2, LOW);
    analogWrite (enr, vspeed);
    analogWrite (enl, vspeed);
    delay(tdelay);
    // Update sensor values
    sr = digitalRead(right_sensor);
    sl = digitalRead(left_sensor);
  }
}

// Function to stop
void Stop() {
  analogWrite (enr, 0);
  analogWrite (enl, 0);
}
