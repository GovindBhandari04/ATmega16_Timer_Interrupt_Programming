/*
 * Timer interrupt program.c
 *
 * Created: 8/18/2023 7:17:25 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
    sei();      //Enable the global interrupt enable bit.
	TIMSK |= (1<<OCIE1A);    //enable the required output compare bit in TCCR1A register 
	TCCR1A &= ~(1<<WGM10) & ~(1<<WGM11);    //enable the waveform generation bit
	TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13);   // in normal mode in TCCR1A and TCCR1B.
	TCCR1A |= (1<<COM1A0);    //enable the output compare mode0 in channelA
	TCCR1A &= ~(1<<COM1A1);   //disable the output compare mode1 in channelA
	TCCR1B |= (1<<CS12)|(1<<CS10);   //enable clock select bit CS12 and CS10 in 1024 prescaler
	TCCR1B &= ~(1<<CS11);	         //disable the clock select bit in CS11 bit in 1024 prescaler
	TCNT1 = 0;   //start the timer with intial value equal to zero
	OCR1A = 7812.5; //its show my 7812.5upcounting times in 1tick of timer in 1 sec  ==>  8000000/1024 => 7812.5 ==> 1/7812.5 ==> 128microsseconds
	DDRD |= (1<<DDD5);   //set DDD5 pin as output 
	
    while (1) 
    {
    }
}

ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0;
	OCR1A = 7812.5; 
}
