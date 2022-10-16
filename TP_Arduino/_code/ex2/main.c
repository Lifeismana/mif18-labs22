// MIF18 - advanced systems
// Arduino Lab #1 - Main File for students, to be completed
// This is a C file.

// Functionality : 2 Leds to blink at the same frequency

#include <avr/io.h>
#include <util/delay.h>

int state=1; 

//Red Led on Digital 13 
//Other Led on digital 12

void init(void)
{
  // DDRB is the configuration register for digital 8 to 13
  // TODO : Set Digital 12 and 13 to "outputmode"
  DDRB |= 0b00100000;
  DDRB |= 0b00010000;
}

void change_led_state(int pin){
  // Change digital 13 on->off->on (xor is life!)
  PORTB ^= pin;
}


int main(void)
{
  init();
  while(1) //infinite loop
    {
      // TODO
           // 1Hz period
      if (state)
      {
        change_led_state(0b00100000);
        
      }
      else
      {
        change_led_state(0b00010000);
      }
      
      _delay_ms(100);

      state ^= 0b00000001;
    }
  
  return 0;
}
