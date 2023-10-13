#include "ADC.h"
#include "LCD.h"

int main(void)
{
	unsigned short volt;
	unsigned char temp;
	ADC_init();
	LCD_init();
	LCD_send_string("Temp=");
    while(1)
    {
		volt = 2.5*ADC_read();
		if(volt>=1000)
		{
			temp = (volt-1000)/10;
			if(temp<10)
			{
				LCD_move_cursor(1,6);
				LCD_send_char(temp+48);
				LCD_send_char(0xDF);
				LCD_send_char('C');
				LCD_send_char(' ');
				LCD_send_char(' ');
			}
			else if(temp<100)
			{
				LCD_move_cursor(1,6);
				LCD_send_char((temp/10)+48);
				LCD_send_char((temp%10)+48);
				LCD_send_char(0xDF);
				LCD_send_char('C');
				LCD_send_char(' ');
			}
			else
			{
				LCD_move_cursor(1,6);
				LCD_send_char((temp/100)+48);
				LCD_send_char((temp/10)%10+48);
				LCD_send_char((temp%10)+48);
				LCD_send_char(0xDF);
				LCD_send_char('C');
			}
		}
		else
		{
			temp = (1000-volt)/10;
			LCD_move_cursor(1,6);
			LCD_send_char('-');
			if(temp<10)
			{
				LCD_send_char(temp+48);
				LCD_send_char(0xDF);
				LCD_send_char('C');
				LCD_send_char(' ');
			}
			else if(temp<100)
			{
				LCD_send_char((temp/10)+48);
				LCD_send_char((temp%10)+48);
				LCD_send_char(0xDF);
				LCD_send_char('C');
			}
		}
    }
}