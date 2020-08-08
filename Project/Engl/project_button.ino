/*
This code was designed by Konstantinos Sakkas.
It is intended for academic use at the Department of Informatics and Telecommunication
of University of Ioannina and my github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/

/*
During normal program flow, the red LED (PIN 1.0)
will flash at a frequency of 1 Hz. The microcontroller will print to the serial console
the number of appeals

When the user presses the right button (PIN 1.1), the flow of the program will stop.
When the user presses the button again it will continue
*/

#define LED RED_LED //We declare that we will use the red led
const int button = PUSH2;  //Initialize the PUSH2 button (P1.1) on the fixed button
const int led  = RED_LED;  //Initialize the red led in the fixed led (P1.0)

int ledState=LOW;           //We initialize the variable ledState = LOW, ie logical 0
                           //This variable will keep the status of the led
int buttonCurrent=LOW;    //We initialize the variable buttonCurrent = LOW, ie logical 0
                         //This variable will hold the status of the button
int buttonPrevious=LOW; //We initialize the variable buttonPrevious = LOW, ie logical 0
                       //This variable will keep the previous state of the button
int x=0;              //Initialize the variable x = 0 for counter

void setup() {                                                       //System parameter and materials initialization function
  Serial.begin(9600);                                               //It is the transmission rate in bits / sec
  pinMode(led, OUTPUT);                                            //Declaration of constant led = RED_LED as output
  pinMode(button, INPUT_PULLUP);                                  //Fixed button declaration = PUSH2 as output
  Serial.println("Department of Informatics & Telecommunications");        //Show message at start of program 
  Serial.println("Project Button");                     //Show message at start of program  
}

void loop()                                                        //Main iterative function
{
  buttonCurrent = digitalRead(button);                           //Assign the Button value to the buttonCurrent variable (whether pressed or not)
  if (buttonCurrent != buttonPrevious)                          //If the value of the buttonCurrent is different from the value of the buttonPrevious then 
                                                               //(ie if the value of the current status is different from the previous one)
  {
    if(buttonCurrent == HIGH)                                //If the value of buttonCurrent is HIGH = reasonable 1 then
    {
      if(ledState == LOW){                                 //If the value of ledState is LOW = logical 0 then
        while(buttonCurrent == HIGH){                     //As long as the value of buttonCurrent is HIGH = reasonable 1
          digitalWrite(led, HIGH);                       //Gives a reasonable value of 1 (HIGH) to the led, ie it lights up
          delay(500);                                   //Stops execution for 500 ms = 0.5 sec  
          digitalWrite(led, LOW);                      //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
          delay(500);                                 //Stops execution for 500 ms = 0.5 sec
          x++;                                       //Increases the counter by one
          Serial.print("The LED is blinking: ");//Show message
          Serial.print(x);                         //Display x counter value
          Serial.println(" times");               //Show message
          buttonCurrent = digitalRead(button);   //Assign the Button value to the buttonCurrent variable (whether pressed or not)
          }
        ledState=HIGH;                         //The state variable of led becomes HIGH, ie logical 1
      }
      else{                                  //Otherwise (if the previous condition does not apply)
          digitalWrite(led, LOW);           //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
          ledState= LOW;                   //The status variable of led becomes LOW, ie logical 0
          Serial.println("The LED stopped blinking ");    //Show message
      }
    }
       buttonPrevious = buttonCurrent;  //In the variable that holds the previous state of the button we assign the state of the button
  }
}