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
1 * The user through messages will be able to control the duty cycle with which the green led of the board will be extinguished
2 * The extinguishing of the red Led will be controlled using the button located in P1.1
3 * As long as the user presses the button, the red LED should flash gradually (breathing effect)
4 * The red led in idle mode should maintain the last state it had while the user pressed the button
*/

const int button = PUSH2;                                      //Initialize the PUSH2 button (P1.1) on the fixed button
int buttonCurrent=0;                                          //We initialize the variable buttonCurrent = HIGH, ie logical 1
                                                             //This variable will hold the status of the button
int p,t;                                                    //Led state cash variables
void setup() {                                             //System parameter and materials initialization function
       Serial.begin(9600);                                //It is the transmission rate in bits / sec
       pinMode(RED_LED, OUTPUT);                         //Declaration of constant led = RED_LED as output
       pinMode (GREEN_LED, OUTPUT);                     //Declaration of constant led = GREEN_LED as output
       pinMode(button, INPUT_PULLUP);                  //Fixed button declaration = PUSH2 as output
       Serial.println("Department Informatics & Telecommunications ");         //Show message at start of program
       Serial.println("Give a number for the x of the Duty Cycle");           //Show message at start of program
}

int k = 20000;                                      //Period (T)
int i = 0;                                         //Counter
int j = 10;                                       //Time on = d
int l = 50;                                      //Step

void loop() {                                  //Main iterative function
buttonCurrent = digitalRead(button);          //Assign the Button value to the buttonCurrent variable (whether pressed or not)
if(Serial.available())                       //If serial input is available
  {
    if(buttonCurrent != LOW){              //If the value of the buttonCurrent is different from LOW = logical 0 then
    int x = Serial.parseInt();            //In the variable x we ​​assign the value given by the user to the serial by converting it to integer
    int d=0.1*(x+1)*k;                   //Type of duty cycle
  while(1){                             //Creating a repetitive endless loop
  digitalWrite(GREEN_LED, HIGH);       //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
  for(i=0; i<d; i++) {}               //Creating a repetitive loop
  digitalWrite(GREEN_LED, LOW);      //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
  for(i=d; i<k; i++) {}             //Creating a repetitive loop
  
    if(Serial.available())        //If serial input is available
      { 
        x = Serial.parseInt();  //In the variable x we ​​assign the value given by the user to the serial by converting it to integer
        buttonCurrent = digitalRead(button);                       //Assign the Button value to the buttonCurrent variable (whether pressed or not)
        if(x==0)                                                  //If x has its value equal to 0
        {}                                                       //Continues to repeat
        else if(x!=0 || buttonCurrent!=LOW){                    //If x has its value equal to 0 or the state of the button is different from LOW
        break;                                                 //Stops the repetition
        }
      } 
   }
}
    else{                                                 //Else
  

   while(buttonCurrent == LOW)                         //If the value of buttonCurrent is LOW = logical 0 then
    {
      digitalWrite(RED_LED, HIGH);                   //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      for(i=0; i<j; i++) {p++;}                     //Create a repetitive loop and add a counter
      digitalWrite(RED_LED, LOW);                  //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      for(i=j; i<k; i++){ t++;}                   //Create a repetitive loop and add a counter
      j=j+l;                                     // l (-10)
      if(j>19000)                               //If j > 19000
      {
        l=l*-1;                               //We reduce it l
      }
      if(j<5)                               //If j < 5
      {
        l=l*-1;                           //We reduce it l
      }
        buttonCurrent = digitalRead(button);       //Assign the Button value to the buttonCurrent variable (whether pressed or not)
      }  
    if(p>t)                                      //If p > t  
    {
         digitalWrite(RED_LED, HIGH);          //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
    }
    else                                     //Else
    {
        digitalWrite(RED_LED, LOW);        //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off

    }
   }
  }
}