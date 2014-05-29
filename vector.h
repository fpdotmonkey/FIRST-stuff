//
// vector.h
//
// Copyright (c) 2013 Suit Bots 4628
//

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  double x;
  double y;
  double z;
} vect;

double magnitude(vect vector) {
  double mag;
  mag = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
  mag = sqrt(mag);
  return mag;
}

double directionXY(vect vector) { //angle in degrees
  double m = atan2(vector.y, vector.x) * 180 / M_PI;
  return m;
}

double directionXZ(vect vector) { //angle in degrees
  double m = atan2(vector.z, vector.x) * 180 / M_PI;
  return m;
}

vect add(vect vect1, vect vect2) {
  vect vector = { vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z };
  return vector;
}

vect mult(double scalar, vect vector) {
  vect vector_f = { vector.x * scalar, vector.y * scalar, vector.z * scalar };
  return vector_f;
}

double dot_prod(vect vect1, vect vect2) {
  double prod = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
  return prod;
}

vect unit_vector(vect vector) {
  return mult(1/magnitude(vector), vector);
}

bool equivalent(vect vect1, vect vect2) {
  if (magnitude(vect1) != magnitude(vect2))
    return false;
  if (directionXY(vect1) != directionXY(vect2))
    return false;
  if (directionXZ(vect1) != directionXZ(vect2))
    return false;
  return true;
}

void useless_val_warning(double useless_val) {
  // write_debug_stream("WARNING: %f has no meaning", useless_val);
  printf ("WARNING: %f has no meaning", useless_val);
}


/*  ____        _ _     ____        _         _____ _____ ____  */
/* / ___| _   _(_) |_  | __ )  ___ | |_ ___  |  ___|_   _/ ___| */
/* \___ \| | | | | __| |  _ \ / _ \| __/ __| | |_    | || |     */
/*  ___) | |_| | | |_  | |_) | (_) | |_\__ \ |  _|   | || |___  */
/* |____/ \__,_|_|\__| |____/ \___/ \__|___/ |_|     |_| \____| */
                                                            
/*  _  _    __  ____  ___   */
/* | || |  / /_|___ \( _ )  */
/* | || |_| '_ \ __) / _ \  */
/* |__   _| (_) / __/ (_) | */
/*    |_|  \___/_____\___/  */
