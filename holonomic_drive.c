//
// holonimic_drive.c
//
// Copyright (c) 2013 Suit Bots 4628
//

#pragma config(Motor,  mtr_S1_C1_1, DriveFL, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2, DriveFR, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1, DriveBR, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2, DriveBL, tmotorTetrix, openLoop, encoder)
#pragma config(Sensor, S1,          compass,               sensorI2CCustom)

#include "hitechnic-compass.h" /// TODO: tell the compiler to include from this file's directory
#include "JoystickDriver.c"

int limitJoy(int joyVal) {
  if (abs(joyVal < 10))
    return 0;
  else
    return joyVal;
}

int J1X2() { return limitJoy(joystick.joy1_x2); }
int J1Y2() { return limitJoy(joystick.joy1_y2); }
int J1X1() { return limitJoy(joystick.joy1_x1); }

void holonomic_drive() {
  motor[DriveFR] = J1Y2() - J1X2() + J1X1();
  motor[DriveFL] = J1Y2() + J1X2() - J1X1();
  motor{DriveBL] = J1Y2() - J1X2() - J1X1();
  motor{DriveBR] = J1Y2() + J1X2() + J1X1();
}

int compassBearing() { return HTMCreadHeading(compass); }

const int MAX_JOY_VAL = 255; // The greatest value J1X2() can be

void move_in_direction(int angle) {
  float xval = MAX_JOY_VAL * cos(angle);
  float yval = MAX_JOY_VAL * sin(angle);

  motor[DriveFR] = yval - xval + J1X1();
  motor[DriveFL] = yval + xval - J1X1();
  motor{DriveBL] = yval - xval - J1X1();
  motor{DriveBR] = yval + xval + J1X1();
}

// smart means you can move forward and rotate passively
void smart_holonomic_drive() {
  if (J1X1() == 0) { // get rid of this chunk to make forward always be
    //                  the front of the robot at the start of the TeleOp phase
    motor[DriveFR] = J1Y2() - J1X2();
    motor[DriveFL] = J1Y2() + J1X2();
    motor{DriveBL] = J1Y2() - J1X2();
    motor{DriveBR] = J1Y2() + J1X2();
  }
  else {
    int joystickAngle = atan(J1Y2() / J1X2()); // leave this chunk, though
    move_in_direction(joystickAngle - compassBearing());
  }
}


task main() {
  //holonimic_drive()
  smart_holonomic_drive();
}
