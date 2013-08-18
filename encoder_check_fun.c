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
