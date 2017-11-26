/* Decimal up, down and ring counter using 8051 microcontroller */

#include<reg51.h>

typedef unsigned char tByte;
typedef unsigned int tWord;

void delayMs(tWord x)
{
  tWord i;
  while(x--)
  for(i=0;i<120;i++);
}

//key configurations

sbit key1 = P3^2;
sbit key2 = P3^3;
sbit key3 = P3^4;

int main()
{
  tByte count = 0,i,temp;
  tWord delay = 1000;
  P0 = 0x00; //initially turn off all the LED's
  while(1)
  {

    //upcounter
    if(key1==0)
    {
      for(count = 0;count<100;count++)
      {
        P0 = (count/10)<<4 | count%10;
        delayMs(delay);
      }
      P0 = 0x00;
    }

    //downcounter
    if(key2==0)
    {
      for(count = 99;count>=0;count--)
      {
        P0 = (count/10)<<4 | count%10;
        delayMs(delay);
      }
      P0 = 0x00;
    }

    //ringcounter
    if(key3==0)
    {
      while(1)
      {
        for(i=0;i<8;i++)
        {
          P0 = 0x01<<i;
          delayMs(delay);
        }
      }
    }

  }
  
}
