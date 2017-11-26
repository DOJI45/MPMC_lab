/* SEVEN SEGMENT DISPLAY
display FIRE and HELP in seven segment display
it is with common anode configuration(active low)
*/

#include<reg52.h>

typedef unsigned char tByte;
typedef unsigned int tWord;

sbit DAT = P0^0;
sbit CLK = p0^1;

void delayMs(tWord x)
{
  tWord i;
  while(x--)
  for(i=0;i<75;i++);
}

//It uses a shift register SIPO
void writeSeg(tByte x)
{
  tByte i;
  for(i=0;i<8;i++)
  {
    if(x&(0x80>>i))
      DAT = 1;
    else
      DAT = 0;
    //clock is given to push the bit in the  register
    CLK = 0;
    CLK = 1;
  }
}

int main()
{
  int i=0;
  tByte help[4] = {0x89,0x86,0xC7,0x8c};
  tbyte fire[4] = {0x8e,0xcf,0xaf,0x86};

  P0 = 0x00;
  while(1)
  {
    for(i=0;i<4;i++)
      writeSeg(help[i]);
    delayMs(1000);
    for(i=0;i<4;i++)
      writeSeg(fire[i]);
    delayMs(1000);
  }
}
  
