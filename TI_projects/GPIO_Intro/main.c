#include <TM4C123GH6PM.h>

unsigned long In;  // input from PF4

unsigned long Out; // output to PF2 (blue LED)

//   Function Prototypes

void PortF_Init(void);

// 3. Subroutines Section

// MAIN: Mandatory for a C Program to be executable

int main(void){    // initialize PF0 and PF4 and make them inputs

  PortF_Init();    // make PF3-1 out (PF3-1 built-in LEDs)

  while(1){

   // In = GPIOF->DATA&0x10;   // read PF4 into Sw1

   // In = In>>2;                    // shift into position PF2

   // Out = GPIOF->DATA;

   // Out = Out&0xFB;

   // Out = Out|In;

    GPIOF->DATA = 0x2;        // output

  }

}

// Subroutine to initialize port F pins for input and output

// PF4 is input SW1 and PF2 is output Blue LED

// Inputs: None

// Outputs: None

// Notes: ...

void PortF_Init(void){ volatile unsigned long delay;

  SYSCTL->RCGC2|= 0x00000020;     // 1) activate clock for Port F

  delay = SYSCTL->RCGC2;           // allow time for clock to start

  GPIOF->LOCK = 0x4C4F434B;   // 2) unlock GPIO Port F

  GPIOF->CR = 0x1F;           // allow changes to PF4-0

  // only PF0 needs to be unlocked, other bits can't be locked

  GPIOF->AMSEL = 0x00;        // 3) disable analog on PF

  GPIOF->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0

  GPIOF->DIR = 0x0E;          // 5) PF4,PF0 in, PF3-1 out

  GPIOF->AFSEL= 0x00;        // 6) disable alt funct on PF7-0

  GPIOF->PUR = 0x11;          // enable pull-up on PF0 and PF4

  GPIOF->DEN= 0x1F;          // 7) enable digital I/O on PF4-0

}