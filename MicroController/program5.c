/* stepper motor
1 rotation = 200 steps = 360 degree, caculate accordingly
4 windings w3,w2,w1,w0 */

#include<reg52.h>

typedef unsigned char tByte;
typedef unsigned int tWord;

sbit W3 = P0^7;
sbit W2 = P0^6;
sbit W1 = P0^5;
sbit W0 = P0^4;

no_of_steps_clk = 100;
no_of_steps_anticlk = 100;

void delayMs(tWord x)
{
  tWord i;
  while(x--)
  for(i=0;i<300;i++);
}

main()
{
  //clockwise rotation
  while(1)
  {
    W3 = 1;W2=0;W1=0;W0=0;delayMs(5);if(--no_of_steps_clk==0) break;
    W3 = 0;W2=1;W1=0;W0=0;delayMs(5);if(--no_of_steps_clk==0) break;
    W3 = 0;W2=0;W1=1;W0=0;delayMs(5);if(--no_of_steps_clk==0) break;
    W3 = 0;W2=0;W1=0;W0=1;delayMs(5);if(--no_of_steps_clk==0) break;
  }

  //anticlock rotation
  while(1)
  {
    W3 = 0;W2=0;W1=0;W0=1;delayMs(5);if(--no_of_steps_anticlk==0) break;
    W3 = 0;W2=0;W1=1;W0=0;delayMs(5);if(--no_of_steps_anticlk==0) break;
    W3 = 0;W2=1;W1=0;W0=0;delayMs(5);if(--no_of_steps_anticlk==0) break;
    W3 = 1;W2=0;W1=0;W0=0;delayMs(5);if(--no_of_steps_anticlk==0) break;
  }
  
}
