/*
This code was designed by Konstantinos Sakkas on August 7th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina and my github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/

//blink red and green led

#define RLED RED_LED      //define RLED = red led
#define GLED GREEN_LED   //define GLED = green led

void setup() {                //Function of initialization of system parameters and materials.
                             //Initialize both serial ports: 
  Serial.begin(9600);       //It is the rate of transmission in bits per sec (for Serial).
  pinMode(RLED, OUTPUT);   //Declare RED_LED as output   
  pinMode(GLED, OUTPUT);  //Declare GREEN_LED as output   

}

int x=0;               //Initialization x = 0 (for counter)
void loop() {
  digitalWrite(RLED, HIGH);    //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
  digitalWrite(GLED, LOW);    //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
  delay(1000);               //Delay for 1000 ms = 1 sec
  digitalWrite(RLED, LOW);     //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
  digitalWrite(GLED, HIGH);   //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
  delay(1000);               // Delay for 1000 ms = 1 sec
  x++;                       // x = x + 1
  Serial.print(x);          //appearance in the serial the value of x
}