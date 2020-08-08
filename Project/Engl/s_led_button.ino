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
1 * The application will be started by pressing "S" (Start) on the keyboard of the connected PC.
2 * The application will end by pressing "S" (Stop) on the keyboard of the connected PC.
3 * The application executes the red LED under the control of SW1 (push to start / push to stop).
4 * Respectively executes the green LED under the control of SW2 (push to start / push to stop).
5 * The green LED flashes twice as often as the red LED.
*/


const int buttonar = PUSH1;                                      //Initialize the PUSH2 button (P2.1) on the fixed button
const int buttondex = PUSH2;                                    //Initialize the PUSH2 button (P1.1) on the fixed button
int buttonCurrent=0;                                           //Initialize the variable buttonCurrent = 0
int buttonCurrent2=0;                                         //Initialize the variable buttonCurrent2 = 0

int buttonstate= HIGH;                                      //We initialize the variable buttonstate = HIGH, ie logical 1
int buttonstate2= HIGH;                                    //We initialize the variable buttonstate2 = HIGH, ie logical 1

void setup() {                                           //System parameter and materials initialization function
  Serial.begin(9600);                                   //Transmission rate in bits / sec
  
  pinMode(RED_LED, OUTPUT);                            //Declaration RED_LED as output
  pinMode (GREEN_LED, OUTPUT);                        //Declaration GREEN_LED as output
  pinMode(buttonar, INPUT_PULLUP);                   //Declaration of constant buttonar = PUSH1 as output
  pinMode(buttondex, INPUT_PULLUP);                 //Declaration of constant buttondex = PUSH2 as output

  Serial.println("Department of Informatics & Telecommunications ");  //Show message at start of program
  Serial.println("");                                                //Show message at start of program
  Serial.println("Give S to start the program");                    //Show message at start of program
  Serial.println("Give S again to stop the program");              //Show message at start of program

  while (!Serial.available()) //As long as serial input is not available * it will do nothing 
  { }; //*will do nothing
}

void loop() {                           //Main iterative function
  if(Serial.available())               //If serial input is available
  {
    String a = Serial.readString();  //In variable a we assign the value given by the user to the serial by converting it to an alphanumeric
    
    if(a[0]=='S')                  //If x has its value equal to S
    {
      while(1) {                 //As long as x = 1 => creation of a repetitive loop infinite
      buttonCurrent = digitalRead(buttonar);          //Assign the Buttonar value to the buttonCurrent variable (whether pressed or not)
      if(buttonCurrent == LOW )                      //If the button has been pressed
      {
       while(1){                                   //Creating a repetitive endless loop 
          digitalWrite(RED_LED, LOW);             //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off

          digitalWrite(GREEN_LED, HIGH);     //Gives a reasonable value of 1 (HIGH) to the led, ie it lights up
          delay(250);                       //Stops execution for 250 ms = 0.25 sec
          digitalWrite(GREEN_LED, LOW);    //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
          delay(250);                     //Stops execution for 250 ms = 0.25 sec
          
        buttonCurrent = digitalRead(buttonar);            //Assign the Button value to the buttonCurrent variable (whether pressed or not)
        buttonstate=HIGH;                                //Assign to the buttonstate = HIGH variable
        if(buttonstate == HIGH && buttonCurrent == LOW) //AN buttonstate == HIGH && buttonCurrent == LOW
        {
                   break;                             
        }
       }
      }


      buttonCurrent2 = digitalRead(buttondex);          //Assign to buttonCurrent2 the value of buttondex (whether pressed or not)
      if(buttonCurrent2 == LOW )                       //If the button has been pressed
      {
       while(1){
          digitalWrite(GREEN_LED, LOW);   //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off

          digitalWrite(RED_LED, HIGH);    //Gives a reasonable value of 1 (HIGH) to the led, ie it lights up
          delay(500);                    //Stops execution for 500 ms = 0.5 sec
          digitalWrite(RED_LED, LOW);   //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
          delay(500);                  //Stops execution for 500 ms = 0.5 sec
          
        buttonCurrent2 = digitalRead(buttondex);            //Assign the Button value to the buttonCurrent variable (whether pressed or not)
        buttonstate2=HIGH;                                 //Assign to the buttonstate2 = HIGH variable
        if(buttonstate2 == HIGH && buttonCurrent2 == LOW) //AN buttonstate == HIGH && buttonCurrent == LOW
        {
                   break;
        }
       }
      }

      
      digitalWrite(RED_LED, HIGH);    //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      delay(500);                    //Stops execution for 500 ms = 0.5 sec     
      digitalWrite(RED_LED, LOW);   //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
      delay(500);                  //Stops execution for 500 ms = 0.5 sec
      
      digitalWrite(GREEN_LED, HIGH);     //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      delay(250);                       //Stops execution for 250 ms = 0.25 sec
      digitalWrite(GREEN_LED, LOW);    //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      delay(250);                     //Stops execution for 250 ms = 0.25 sec
    
     if(Serial.available())        //If serial input is available
      {  
        a = Serial.readString(); //In the variable x we ​​assign the value given by the user to the serial by converting it to integer 
        if(a[0]=='S')           //If x has its value equal to 0
          break;               //Stops the repetition
        else
        {}
      }
      }
    }
   
    
 }
}