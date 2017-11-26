/* Read the status of the inputs and different actions for if even and if odd */

#include<reg51.h>

typedef unsigned char tByte;
typedef unsigned int tWord;

sbit SEL = P1^4;

void delayMs(tWord x)
{
  tWord i;
  while(x--)
  for(i=0;i<120;i++);
}

tByte readInput()
{
  tByte temp = 0;
  SEL = 0;
  temp = 0x0f & P1;
  SEL = 1;
  temp = (P1 & 0x0f)<<4 | temp;
  return temp;
}

tByte countOnes(tByte x)
{
  tByte i,count = 0;
  for(i=0;i<8;i++)
  {
    if(x&(0x01<<i))
    count++;
  }
  return count;
}


int main()
{
  tByte temp,count;
  while(1)
  {
    temp = readInput();
    count = countOnes(temp);
    if(count%2==0)
      P0 = 0xFF;
    else
      P0 = 0x00;
    delayMs(1000);
    P0 = count;
    delayMs(1000);
  }
}
