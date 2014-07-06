/*
 * Robot_line_follower.ino
 *
 * robot line follower , Arduino mini pro 328 , TCRT5000, L2203N, manual tune gain pid with 3 variable resistors , 
 * manual tune speed with a variable resistor 
 
 
 * Created: 7/6/2014 12:19:59 PM
 * Author: Wasin
 */ 
int motor_r = 5 ;
int	motor_l = 6 ;

int gain_p = 0	;
int gain_i = 0	;
int gain_d = 0	;
int gain_v = 0	;

int sensor_l =;
int sensor_r =;

void setup()
{
	pinMode(motor_r,OUTPUT);
	pinMode(motor_l,OUTPUT);
}

void loop()
{

	  /* add main program code here, this code starts again each time it ends */

}
