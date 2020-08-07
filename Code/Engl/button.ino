/*
This code was designed by Konstantinos Sakkas on August 7th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina and my github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/

//Push button example

const int button = PUSH2;                  //statement as const button P1.1
const int gled =  GREEN_LED;              //statement as const green led

int buttonstate = 0;                     // Initialization buttonstate = 0 (for state)

void setup() {
  pinMode(gled, OUTPUT);              //Declare gled as output   
  pinMode(button, INPUT_PULLUP);     //Declare button as INPUT_PULLUP 
}

void loop(){                                //Main repetitive function.
  
  buttonstate = digitalRead(button);      //Read the state of the button

  if (buttonstate == HIGH) {     // check if the button is pressed => buttonState = HIGH.    
    digitalWrite(gled, HIGH);   //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
  } 
  else {
    digitalWrite(gled, LOW);  //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
  }
}
 
