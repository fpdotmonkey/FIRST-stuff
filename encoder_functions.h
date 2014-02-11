//
// encoder_functions.h
//
// Copyright (c) Fletcher Porter 2014
//

muxUpdateInterval = 10; // default

int motorSpeed(tMotor motor) { // Calculates avgerage change in encoder value
  int sampleSize = 100;
  int sample[sampleSize + 1];
  int deltaSample[sampleSize];
  int avgSpeed = 0;
  
  for (int i = 0; i < sampleSize; ++i) {
    sample[i] = nMotorEncoder[motor];
    deltaSample[i] = sample[i] - sample[i - 1];
  }

  for (int i = 0; i < sampleSize; ++i) {
    avgSpeed += deltaSample[i];
  }

  avgSpeed /= sampleSize;
  writeDebugStream("avgSpeed: %i", avgSpeed);
  return avgSpeed;
}

const int MIN_MOTOR_SPEED = 10; //TODO: adjust

void motor_off_if_danger_smoking(tMotor motor) { // Turns a motor off if it is in danger of smoking
  if (motorSpeed(motor) < MIN_MOTOR_SPEED
      && nMotorRunState[motor] != runStateIdle) {
    motor[motor] = 0;
  }
}

void sync_motors_at_ratio(tMotor master, tMotor slave, int ratio, int masterPower) {
  int powerIncrement = 3;

  static int power = masterPower;
  motor[master] = power;
  motor[slave] = power * ratio;
  
  if (motorSpeed(slave) > (motorSpeed(master) * ratio)) {
    motor[slave] = power - powerIncrement;    
  }
  else if (motorSpeed(slave) < (motorSped(master) * ratio)) {
    motor[slave] = power + powerIncremet;
  }
}
