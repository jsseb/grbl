/*
	Laser control
*/

#ifndef laser_control_h
#define laser_control_h

#include <avr/io.h>

#define LASER_ENABLE 1
#define LASER_DISABLE 0

void laser_init();
void laser_stop();
void laser_run(uint8_t mode);

#endif
