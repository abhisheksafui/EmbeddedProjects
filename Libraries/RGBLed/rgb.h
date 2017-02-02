/* Copyright 2016 Abhishek Safui
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 * rgb.h
 *
 *  Created on: 17-Jan-2017
 *      Author: abhi
 */

#ifndef RGB_H_
#define RGB_H_

#include<inttypes.h>
#include <math.h>
#include <Arduino.h>

#define PWM_MAX 65535

typedef enum {
	RGB_RANDOM,
	RGB_PWM,
	RGB_CONSTANT,
	RGB_TRANSITION
}RGB_MODE;

typedef enum{
	RBG_VIOLET,
	RGB_INDIGO,
	RGB_BLUE,
	RGB_GREEN,
	RGB_YELLOW,
	RGB_ORANGE,
	RGB_RED,
	RGB_WHITE
}RGB_COLOR;
class RGB {
public:
	/*
	 * Desired color and mode
	 */
	int red;
	int blue;
	int green;
	RGB_MODE mode;
	RGB_COLOR color;

	/*
	 * Actual values currently existing in PWM
	 */

	int red_pwm; float red_increment_per_step;
	int blue_pwm; float blue_increment_per_step;
	int green_pwm; float green_increment_per_step;
	int state_transition_time_ms;

	int transition_step;
/*
 * 	Hardware variables
 */
	uint8_t red_pin;
	uint8_t green_pin;
	uint8_t blue_pin;

	//HardwareTimer *timer;
	uint32_t fsm_period_ms;


	RGB(uint8_t red_p,uint8_t green_p,uint8_t blue_p,uint32_t fsm_ms=20);
	void setMode(RGB_MODE mode) { this->mode = mode; }

	void setColor(uint8_t red, uint8_t green, uint8_t blue,int transit_time_ms);
	void setColor(RGB_COLOR color,int transit_time = 5000);

	RGB_COLOR getColor() { return color; }

	void fsm(void);

private:
	int getTransitionSteps();

};

#endif /* RGB_H_ */
