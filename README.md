FIRST-stuff
===========

My RobotC code that would be useful for FIRST teams


Programs
--------

* dead_motor.c
  - A boolean function that will inform you if a motor is dead.  Handy if you have four-motor drive and you want to be able to turn that to two-motor drive in the event of an emergency.

* holonomic_drive.c
  - My holonomic drive function.  The 'smart' version uses the HiTechnic Compass Sensor to allow seperation of movement and rotation

* preprocessor_checks.h
  - Checks a few preprocessor defines to make sure you're using RobotC in NXT/TETRIX mode as well as FTC mode.  Also checks for the latest firmware version.
