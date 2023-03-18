// Define the IR sensor pins
const int irSensorPins[4][6] = {
  {2, 3, 4, 5, 6, 7},
  {8, 9, 10, 11, 12, 13},
  {14, 15, 16, 17, 18, 19},
  {20, 21, 22, 23, 24, 25}
};

// Define the PID constants
const float kp = 0.1;
const float ki = 0.01;
const float kd = 0.01;

// Define the desired line position (between 0 and 5)
const int desiredPosition = 2;

// Define the motor control pins
const int leftMotorPin = 6;
const int rightMotorPin = 9;

// Define the motor speed
const int motorSpeed = 100;

// Define the PID variables
float lastError = 0;
float integral = 0;

void setup() {
  // Initialize the IR sensors as inputs
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 6; col++) {
      pinMode(irSensorPins[row][col], INPUT);
    }
  }
  
  // Initialize the motor control pins as outputs
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
}

void loop() {
  // Read the sensor values
  int sensorValues[4][6];
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 6; col++) {
      sensorValues[row][col] = digitalRead(irSensorPins[row][col]);
    }
  }
  
  // Calculate the error signal
  float error = 0;
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 6; col++) {
      if (sensorValues[row][col] == HIGH) {
        error += (col - desiredPosition);
      }
    }
  }
  
  // Calculate the PID terms
  float proportional = error;
  integral += error;
  float derivative = error - lastError;
  
  // Calculate the motor speeds
  int leftSpeed = motorSpeed - (kp * proportional + ki * integral + kd * derivative);
  int rightSpeed = motorSpeed + (kp * proportional + ki * integral + kd * derivative);
  
  // Update the motor speeds
  analogWrite(leftMotorPin, leftSpeed);
  analogWrite(rightMotorPin, rightSpeed);
  
  // Save the last error signal
  lastError = error;
}
