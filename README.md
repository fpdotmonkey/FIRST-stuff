FIRST-stuff
===========

My RobotC code that would be useful for FIRST teams


Programs
--------

* `dead_motor.c`
  - A boolean function that will inform you if a motor is dead.  Handy if you have four-motor drive and you want to be able to turn that to two-motor drive in the event of an emergency.

* `holonomic_drive.c`
  - My holonomic drive function.  The 'smart' version uses the HiTechnic Compass Sensor to allow seperation of movement and rotation

* `preprocessor_checks.h`
  - Checks a few preprocessor defines to make sure you're using RobotC in NXT/TETRIX mode as well as FTC mode.  Also checks for the latest firmware version.

* `basic_functions.h`
  - Functions generally useful for a simple autonomous routine e.g. one that just drives around

* `TeleOp_functions.h`
  - Drive functions for use in the Tele-Operation phase

* `encoder_check_fun.c`
  - A function that adresses an [issue](http://www.instructables.com/id/FTC-Sporadic-Encoder-Values/) with sporadic encoder values raised by Cougar Robotics FTC Team 4251
