/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.comProject :
Version :
Date : 08/01/2016
Author : Wayan Dadang
Company : Sains Lab
Comments:
Chip type : ATmega16A
Program type : Application
AVR Core Clock frequency: 11.059200 MHz
Memory model : Small
External RAM size : 0
Data Stack size : 256
*****************************************************/#include <mega16a.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>
unsigned char buff[21],buff1[21],buff2[21],buff3[21],buff4[21],buff5[21],buff6[21],buff7[21];
unsigned char buff8[21],buff9[21],buff10[21],buff11[21],buff12[21],buff13[21],buff14[21],buff15[21];
unsigned char buff16[21],buff17[21],buff18[21],buff19[21],buff20[21],buff21[21],buff22[21],buff23[21];
unsigned char looper;
unsigned char temp;
unsigned int sensor_data[8],sensor_data1[8],sensor_data2[8];
float suhu_celcius[8],suhu_celcius1[8],suhu_celcius2[8];
// Alphanumeric LCD functions
#include <alcd.h>
#define ADC_VREF_TYPE 0x00

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=Out
// State7=T State6=T State5=T State4=T State3=T State2=0 State1=0 State0=0
PORTB=0x00;
DDRB=0x07;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC Clock frequency: 691.200 kHz
// ADC Voltage Reference: AREF pin
// ADC Auto Trigger Source: ADC Stopped
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x84;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS – PORTC Bit 0
// RD – PORTC Bit 1
// EN – PORTC Bit 2
// D4 – PORTC Bit 4
// D5 – PORTC Bit 5
// D6 – PORTC Bit 6
// D7 – PORTC Bit 7
// Characters/line: 20
lcd_init(20);

while (1)
{
// Place your code here

for (looper = 0; looper < 8; looper++)
{

temp = PORTB;
temp &= ~0x07;
temp |= looper;
PORTB = temp; // set low 3 bits of PORTB to multiplexor selector

sensor_data[looper] = read_adc(0);
sensor_data1[looper] = read_adc(1);
sensor_data2[looper] = read_adc(2);

suhu_celcius[looper] = (float)sensor_data[looper]*500/1023; //rumus untuk mengubah kedalam derajat celcius
suhu_celcius1[looper] = (float)sensor_data1[looper]*500/1023; //rumus untuk mengubah kedalam derajat celcius
suhu_celcius2[looper] = (float)sensor_data2[looper]*500/1023; //rumus untuk mengubah kedalam derajat celcius

}

ftoa(suhu_celcius[0],0,buff);
ftoa(suhu_celcius[1],0,buff1);
ftoa(suhu_celcius[2],0,buff2);
ftoa(suhu_celcius[3],0,buff3);
ftoa(suhu_celcius[4],0,buff4);
ftoa(suhu_celcius[5],0,buff5);
ftoa(suhu_celcius[6],0,buff6);
ftoa(suhu_celcius[7],0,buff7);

ftoa(suhu_celcius1[0],0,buff8);
ftoa(suhu_celcius1[1],0,buff9);
ftoa(suhu_celcius1[2],0,buff10);
ftoa(suhu_celcius1[3],0,buff11);
ftoa(suhu_celcius1[4],0,buff12);
ftoa(suhu_celcius1[5],0,buff13);
ftoa(suhu_celcius1[6],0,buff14);
ftoa(suhu_celcius1[7],0,buff15);

ftoa(suhu_celcius2[0],0,buff16);
ftoa(suhu_celcius2[1],0,buff17);
ftoa(suhu_celcius2[2],0,buff18);
ftoa(suhu_celcius2[3],0,buff19);
ftoa(suhu_celcius2[4],0,buff20);
ftoa(suhu_celcius2[5],0,buff21);
ftoa(suhu_celcius2[6],0,buff22);
ftoa(suhu_celcius2[7],0,buff23);
lcd_clear();
lcd_gotoxy(0,0);
lcd_puts(buff);
lcd_gotoxy(3,0);
lcd_puts(buff1);
lcd_gotoxy(6,0);
lcd_puts(buff2);
lcd_gotoxy(9,0);
lcd_puts(buff3);
lcd_gotoxy(12,0);
lcd_puts(buff4);
lcd_gotoxy(15,0);
lcd_puts(buff5);
lcd_gotoxy(18,0);
lcd_puts(buff6);
lcd_gotoxy(0,1);
lcd_puts(buff7);

lcd_gotoxy(3,1);
lcd_puts(buff8);
lcd_gotoxy(6,1);
lcd_puts(buff9);
lcd_gotoxy(9,1);
lcd_puts(buff10);
lcd_gotoxy(12,1);
lcd_puts(buff11);
lcd_gotoxy(15,1);
lcd_puts(buff12);
lcd_gotoxy(18,1);
lcd_puts(buff13);
lcd_gotoxy(0,2);
lcd_puts(buff14);
lcd_gotoxy(3,2);
lcd_puts(buff15);

lcd_gotoxy(6,2);
lcd_puts(buff16);
lcd_gotoxy(9,2);
lcd_puts(buff17);
lcd_gotoxy(12,2);
lcd_puts(buff18);
lcd_gotoxy(15,2);
lcd_puts(buff19);
lcd_gotoxy(18,2);
lcd_puts(buff20);
lcd_gotoxy(0,3);
lcd_puts(buff21);
lcd_gotoxy(3,3);
lcd_puts(buff22);
lcd_gotoxy(6,3);
lcd_puts(buff23);

lcd_gotoxy(11,3);
lcd_puts(“Wayan phD”);
delay_ms(100);

}
}
