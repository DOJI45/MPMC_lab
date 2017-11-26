/* display the result of multiplications c = a*b,
8bit * 8bit = 16bit */

#include<reg51.h>

typedef unsigned char tByte;
typedef unsigned int tWord;

sbit SEL = P1^4;
sbit key1 = P3^2;
sbit key2 = P3^3;
sbit key3 = P3^4;

void delayMs(tWord x)
{
  tWord i;
  while(x--)
  for(i=0;i<120;i++);
}

tByte readInput(tByte x)
{
  tByte temp = 0;
  SEL = 0;
  temp = P1 & 0x0F;
  SEL = 1;
  temp = (P1 & 0x0F) << 4 | temp;
  return temp;
}

int main()
{
  tWord a = 0,b=0,c=0;
  P0 = 0x00;
  while(1)
  {

    //reading input a
    if(key1==0)
    {
      a = readInput();
      P0 = a;
      delayMs(500);
      P0 = 0x00;
      delayMs(500);
    }

    //reading input b
    if(key2==0)
    {
      b = readInput();
      P0 = b;
      delayMs(500);
      P0 = 0x00;
      delayMs(500);
    }

    //displaying output c

    if(key3==0)
    {
      c = a*b;
      P0 = c & 0xFF;       //Lower 8 bits
      delayMs(1000);
      P0 = c>>8;          //upper 8 bits
      delayMs(1000);
      P0 = 0x00;
    }
    
  }
}
