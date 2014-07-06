/*
 * Robot_line_follower.ino
 *
 * robot line follower , Arduino mini pro 328 , TCRT5000, L2203N, manual tune gain pid with 3 variable resistors , 
 * manual tune speed with a variable resistor 
 
 
 * Created: 7/6/2014 12:19:59 PM
 * Author: Wasin
 */ 
unsigned int motor_r		=	5 ;
unsigned int	motor_l		=	6 ;
unsigned int sensor_l	=	A0;
unsigned int sensor_r	=	A2;

unsigned int VR1	= A1 ;
unsigned int VR2	= A3 ;
unsigned int VR3	= A5 ;
unsigned int VR4	= A4 ;

unsigned int gain_p = 0	;
unsigned int gain_i = 0	;
unsigned int gain_d = 0	;
unsigned int gain_v = 0	;


unsigned int read_buffer (int pin)
{
	
	unsigned int buffer_read = 0;

	for (int index=0; index < 10 ; index++)
	{
		delay(50);
		buffer_read = buffer_read + analogRead(pin);
	}
	return buffer_read/10 ;
}


void setup()
{
	pinMode(motor_r,OUTPUT);
	pinMode(motor_l,OUTPUT);
	
	gain_p = read_buffer(VR2)  ;
	gain_i = read_buffer(VR3)	;
	gain_d = read_buffer(VR4)	;
	gain_v = read_buffer(VR1)	;
	
}



void loop()
{
	int error = analogRead(sensor_l)-analogRead(sensor_r);
	
	

	
}
