#include <PID_v1.h>
double error   = 0.0;
double output  = 0.0;
double referpoint  = 0.0 ;

PID myPID(&error, &output, &referpoint, 0.0, 0.0, 0.0, DIRECT);

unsigned int motor_r		=	5 ;
unsigned int motor_l		=	6 ;
unsigned int sensor_l	=	A0;
unsigned int sensor_r	=	A2;

unsigned int VR1	= A1 ;
unsigned int VR2	= A3 ;
unsigned int VR3	= A5 ;
unsigned int VR4	= A4 ;

double gain_p = 0	;
double gain_i = 0	;
double gain_d = 0	;
double verocity = 0	;


double read_buffer (int pin)
{

	double buffer_read = 0;

	for (int index=0; index < 10 ; index++)
	{
		delay(50);
		buffer_read = buffer_read + analogRead(pin);
	}
	return buffer_read/10 ;
}


int led_state = 1 ;

void setup()
{
	pinMode(motor_r, OUTPUT);
	pinMode(motor_l, OUTPUT);
	pinMode(13, OUTPUT);

	gain_p = read_buffer(VR2)/500  ;
	gain_i = read_buffer(VR4)/500    ;
	gain_d = read_buffer(VR3)/500   ;
	verocity = read_buffer(VR1)/4;

	/************************************************************************/
	/*                              Start PID                               */
	/************************************************************************/

	myPID.SetTunings(gain_p, gain_i, gain_d);
    myPID.SetOutputLimits(-255, 255);
	myPID.SetMode(AUTOMATIC);

	 /* Serial.begin(9600);*/
}



void loop()
{
	 error = analogRead(sensor_l)-analogRead(sensor_r);

	  myPID.Compute();

	 /************************************************************************/
	 /* write to output by 2 cases                                           */
	 /************************************************************************/


	if (verocity + output >= 0)
	{
		analogWrite(motor_l,verocity + output);
	}
	else
	{
		analogWrite(motor_l,0);
	}

	if (verocity - output >= 0)
	{
		analogWrite(motor_r,verocity - output);
	}
	else
	{
		analogWrite(motor_r,0);
	}

	led_state = 1 - led_state;

	digitalWrite(13,led_state);

	/*
	Serial.print(" p  ");
	serial.print(gain_p);
	serial.print(" i  ");
	serial.print(gain_i);
	Serial.print(" D  ");
	Serial.print(gain_d);
	Serial.print(" ERR  ");
	Serial.print(error);
	Serial.print(" U  ");
	Serial.println(output);
	*/
}
