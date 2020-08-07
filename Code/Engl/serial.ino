/*
This code was designed by Konstantinos Sakkas on August 7th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina and my github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/

//Serial and led

void setup() {                   //Function of initialization of system parameters and materials.
                                //Initialize both serial ports: 
Serial.begin(9600);            //It is the rate of transmission in bits per sec (for Serial).
pinMode(RED_LED,OUTPUT);      //Declare RED_LED as output (immediately)
Serial.println("Do you want to turn on the led ");   //Show message at the beginning of the program
Serial.println("press  1  to turn on, 2 to shut off"); //Show message at the beginning of the program
while(!Serial.available())  //In this step,by using  if command checks if serial entry is not available.
{};                     
}

void loop() {         //Main repetitive function.
if(Serial.available()){   //In this step,by using  if command checks if serial entry is available.
  int x =  Serial.parseInt(); //Read from the serial and convert it to an integer
  if(x==1)                   //if x = 1
  {
    digitalWrite(RED_LED, HIGH);  //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
  }
  else if (x==2)           //else if x = 2
  {
    digitalWrite(RED_LED, LOW); //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
  }
  else                  //else
  {
      Serial.printl("Give 1 or 2"); //Show message
  }
}
}