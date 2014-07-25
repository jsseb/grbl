/*
	Laser Control
*/

#include "laser_control.h"
#include "gcode.h"
#include "system.h"
#include "protocol.h"
	
#include <avr/io.h>

static uint8_t current_laser_mode;

void laser_init()
{
	LASER_DDR |= (1 << LASER_BIT);
	laser_stop();
}

void laser_stop()
{
	LASER_PORT &= ~(1 << LASER_BIT);
}

void laser_run(uint8_t mode)
{
	if (sys.state == STATE_CHECK_MODE) { return; }

  	protocol_auto_cycle_start();   //temp fix for M8 lockup
  	protocol_buffer_synchronize(); // Ensure laser turns on when specified in program.
	if (mode == LASER_ENABLE){
		LASER_PORT |= (1 << LASER_BIT);
	} else {
		laser_stop();
	}
}