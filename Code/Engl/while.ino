/*
This code was designed by Konstantinos Sakkas on August 7th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina and my github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/

//While

#define rled RED_LED      //define RLED = red led

void setup() {
    Serial.begin(9600);                    //It is the rate of transmission in bits per sec (for Serial).
    pinMode(rled, OUTPUT);                //Declare rled as output
}

void loop() {
  int x = Serial.parseInt();        //read from the serial and convert it to an integer

    while(x == 1){                 //while x = 1
      digitalWrite(rled, HIGH);   //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
    }
}