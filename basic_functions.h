//
// basic_functions.h
//
// Copyright (c) 2013 Suit Bots FTC Team 4628
//

bool EncoderValReached(tMotor motor, long MaxVal) {
  int threshold = 0;
  if (nMotorEncoder[motor] > MaxVal
      && nMotorEncoder[motor] < MaxVal + threshold) {
    return true;
  }
  return false;
}

void GoToEncoderVal(tMotor motor, long EncoderVal) {
  while (! EncoderValReached(motor, EncoderVal)) {
    motor[motor] = 100;
  }
  motor[motor] = 0;
  nMotorEncoder[motor] = 0;
}

const int FRICTION;

//
// Please create an array like this one so the functions will work
//
// tMotor DriveMotors[] = { DriveL, DriveR };
//
// or for Holonomic Drive:
//
// tMotor DriveMotors[] = { DriveFL, DriveFR, DriveBL, DriveBR };
//

void rotate(tMotor *DriveMotors, int degrees, size_t numMotors) {
  if (numMotors != 2) {
    writeDebugStream('Error: there must be exactly two motors for drive function');
    return;
  }
  const float scale_factor = 0;
  long encoderVal = degrees * scale_factor * FRICTION;
  if (degrees >= 0) {
    GoToEncoderVal(DriveMotors[0], -encoderVal);
    GoToEncoderVal(DriveMotors[1], encoderVal);
  }
  else {
    GoToEncoderVal(DriveMotors[0], encoderVal);
    GoToEncoderVal(DriveMotors[1], -encoderVal);
  }
}

void move(tMotor *DriveMotors, int distanceCM, size_t numMotors) {
  if (numMotors != 2) {
    writeDebugStream('Error: there must be exactly two motors for drive function');
    return;
  }
  const float scale_factor = 0;
  long encoderVal = distanceCM * scale_factor * FRICTION;
  GoToEncoderVal(DriveMotors[0], encoderVal);
  GoToEncoderVal(DriveMotors[1], encoderVal);
}

typedef enum direction_t { FORWARD, BACKWARD, LEFT, RIGHT };

void omnimove(tMotor *DriveMotors, int distanceCM, size_t numMotors, direction_t direction) {
  if (numMotors != 4) {
    writeDebugStream('Error: there must be exactly four motors for drive function');
    return;
  }
  const float scale_factor = 0;
  long encoderVal = distanceCM * scale_factor * FRICTION;
  switch (direction) {
  case FORWARD:
    GoToEncoderVal(DriveMotors[0], encoderVal);
    GoToEncoderVal(DriveMotors[1], encoderVal);
    GoToEncoderVal(DriveMotors[2], encoderVal);
    GoToEncoderVal(DriveMotors[3], encoderVal);
    break;
  case BACKWARD:
    GoToEncoderVal(DriveMotors[0], -encoderVal);
    GoToEncoderVal(DriveMotors[1], -encoderVal);
    GoToEncoderVal(DriveMotors[2], -encoderVal);
    GoToEncoderVal(DriveMotors[3], -encoderVal);
    break;
  case LEFT:
    GoToEncoderVal(DriveMotors[0], -encoderVal);
    GoToEncoderVal(DriveMotors[1], encoderVal);
    GoToEncoderVal(DriveMotors[2], encoderVal);
    GoToEncoderVal(DriveMotors[3], -encoderVal);
    break;
  case RIGHT:
    GoToEncoderVal(DriveMotors[0], encoderVal);
    GoToEncoderVal(DriveMotors[1], -encoderVal);
    GoToEncoderVal(DriveMotors[2], -encoderVal);
    GoToEncoderVal(DriveMotors[3], encoderVal);
    break;
  }
}

void omnirotate(tMotor *DriveMotors, int degrees, size_t numMotors) {
  if (numMotors != 4) {
    writeDebugStream('Error: there must be exactly four motors for drive function');
    return;
  }
  const float scale_factor = 0;
  long encoderVal = degrees * scale_factor * FRICTION;
  if (degrees >= 0) {
    GoToEncoderVal(DriveMotors[0], -encoderVal);
    GoToEncoderVal(DriveMotors[1], encoderVal);
    GoToEncoderVal(DriveMotors[2], -encoderVal);
    GoToEncoderVal(DriveMotors[3], encoderVal);
  }
  else {
    GoToEncoderVal(DriveMotors[0], encoderVal);
    GoToEncoderVal(DriveMotors[1], -encoderVal);
    GoToEncoderVal(DriveMotors[2], encoderVal);
    GoToEncoderVal(DriveMotors[3], -encoderVal);
  }
}
