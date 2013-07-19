//
// dead_motor.c
//
// Copyright (c) 2013 Suit Bots 4628
//

// This function is to be used when you have a situation where if a motor
// goes out, bad things happen.  This will tell you that the motor is out
// so you can mitigate disater.  It assumes you have encoders on the motor
// you are checking.

// One application could be during use of holonomic drive.  Normally, if a 
// motor goes out, your robot becomes a sitting duck.  With this, you can
// say that if a motor goes out, switch to arcade drive with the working 
// motors (or just two of them)

#pragma config(Motor,  mtr_S1_C2_2, MotorA, tmotorTetrix, openLoop, encoder)

bool motorIsOut (tmotor motor) {
  int accuracy = 9; //the bigger the number, the more accurate, but slower
  int encoderValue[accuracy];
  int weightDuration = 5; //set to refresh rate of the encoders
  int threshold = 10; //if the motor doesn't move this much in time, it's dead

  for (int i = 0; i <= accuracy; ++i) {
    encoderValue[i] = nMotorEncoder[motor] - encoderValue[i - 1];
    wait1ms(WEIGHT_DURATION);
  }

  int avg;

  for (int i = 0; i <= accuracy; ++i) {
    avg += encoderValue[i];
  }

  avg /= accuracy;

  if (avg < THRESHOLD)
    return true;
  return false;
}

task main() {
  while (true) {
    if (! motorIsOut(MotorA)) {
      motor[MotorA] = 100;
    }
    else {
      motor[MotorA] = 0;
      flash_red_light();
    }
  }
  return 0;
}
