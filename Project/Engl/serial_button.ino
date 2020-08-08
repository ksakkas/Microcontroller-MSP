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
The user will be able to check the status of both integrated LEDs on the board via messages

Each led will be controlled with a different message-command
1-2 Red Led
3-4 Green Led
5-6 Both
(Odd numbers refer to LEDs and scales to LEDs off)

The red LED will flash with a frequency of 1Hz while the green with a frequency of 2Hz.
(For those who do not have a physical board, consider the green LED on the right)

Use a different meter for each Led

The system will inform the user about the status of the system when he presses the button
*/

const int button = PUSH2;  //Initialize the PUSH2 button (P1.1) on the fixed button

int buttonCurrent=HIGH; //We initialize the variable buttonCurrent = HIGH, ie logical 1
                       // This variable will hold the status of the button
                       
void setup() {         //System parameter and materials initialization function
  Serial.begin(9600); //It is the transmission rate in bits / sec
  pinMode(RED_LED, OUTPUT); //Declaration of constant RED_LED as output
  pinMode (GREEN_LED, OUTPUT); //Declaration of constant GREENN_LED as output
  pinMode(button, INPUT_PULLUP); //Fixed button declaration = PUSH2 as INPUT_PULLUP
  Serial.println("Department of Informatics & Telecommunications ");//Show message at start of program
  Serial.println("");//Show message at start of program
  Serial.println("Red LED;");//Show message at start of program
  Serial.println("Turns on with 1 and goes off with 2");//Show message at start of program
  Serial.println("Green LED;");//Show message at start of program
  Serial.println("Turns on with 3 and goes off with 4");//Show message at start of program
  Serial.println("Red & Green");//Show message at start of program
  Serial.println("They turn on with 5 and go off with 6");//Show message at start of program
  while (!Serial.available()) //As long as serial input is not available * it will do nothing
  {}; // * will do nothing
}
    int r=0;//Initialize the variable x = 0 for red led meter
    int g=0;//Initialize the variable x = 0 for green led meter
    
void loop() { //Main iterative function
  if(Serial.available())  //If serial input is available
  {

    int x = Serial.parseInt(); //In the variable x we ​​assign the value given by the user to the serial by converting it to integer 

    if(x==1)//If x has its value equal to 1
    {
      while(x=1) { //As long as x = 1 => creation of a repetitive loop infinite
      digitalWrite(RED_LED, HIGH);  //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      delay(500);              //Stops execution for 500 ms = 0.5 sec
      digitalWrite(RED_LED, LOW); //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      delay(500); //Stops execution for 500 ms = 0.5 sec
      r++; // Increases the counter by one
      if(Serial.available()) //If serial input is available
      { 
        x = Serial.parseInt(); //In the variable x we ​​assign the value given by the user to the serial by converting it to integer 
        if(x==0)//If x has its value equal to 0
        {}//Continues to repeat
        else if (x==2)//If x has its value equal to 2
        {              
          break;//Stops the repetition
        }
       }
      }
    }
   
    else if (x==2)//If x has its value equal to 2
    {  
      digitalWrite(RED_LED, LOW);         //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
    }
    
    else if (x==3)//If x has its value equal to 3
    {
      while(x=3) {                      //As long as x = 3 => creation of a repetitive loop infinite
      digitalWrite(GREEN_LED, HIGH);   //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      delay(250);                     //Stops execution for 250 ms = 0.25 sec
      digitalWrite(GREEN_LED, LOW);  //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      delay(250);                   //Stops execution for 250 ms = 0.25 sec
      g++;                         //Increases the counter by one
      if(Serial.available())      //If serial input is available
      {  
        x = Serial.parseInt(); //In the variable x we ​​assign the value given by the user to the serial by converting it to integer
        if(x==0)              //If x has its value equal to 0
        {}                   //Continues to repeat
        else if (x==4)      //If x has its value equal to 4
        { 
          break;          //Stops the repetition  
        }
       }
      }
    }
    else if (x==4) //If x has its value equal to 4
    {
      digitalWrite(GREEN_LED, LOW);   //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
    }
    else if (x==5) //If x has its value equal to 5
    {
      while(x=5){           //As long as x = 5 => create a repetitive loop infinite
      digitalWrite(RED_LED, HIGH);  //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      delay(500);             //Stops execution for 500 ms = 0.5 sec
      digitalWrite(RED_LED, LOW);   //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      delay(500);  //Stops execution for 500 ms = 0.5 sec
      digitalWrite(GREEN_LED, HIGH);   //Gives a reasonable value of 1 (HIGH) to the red led, ie it lights up
      delay(250);            //Stops execution for 250 ms = 0.25 sec   
      digitalWrite(GREEN_LED, LOW);    //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      delay(250); //Stops execution for 250 ms = 0.25 sec
      r++;//Increases the counter by one
      g++;//Increases the counter by one

      if(Serial.available())//If serial input is available
      {  
        x = Serial.parseInt(); //In the variable x we ​​assign the value given by the user to the serial by converting it to integer 
        if(x==0)//If x has its value equal to 0
        {}//Continues to repeat
        else if (x==6)//If x has its value equal to 6
        {          
          break;//Stops the repetition
        }
      }
      }
    }
    else if (x==6)//If x has its value equal to 6
    {
      digitalWrite(RED_LED, LOW);     //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
      digitalWrite(GREEN_LED, LOW); //Gives a reasonable value of 0 (LOW) to the led, ie it turns it off
     
    }
   } 
 buttonCurrent = digitalRead(button);                       //Assign the Button value to the buttonCurrent variable (whether pressed or not)
   if(buttonCurrent == LOW)                                //If the value of buttonCurrent is LOW = logical 0 then
    {
    Serial.print("The red LED lit: ");//Information about the overall operation of the red led
    Serial.print(r);//Display of the variable - the counter r
    Serial.println(" times");//Informs about the status of the system
    Serial.print("The green LED lit: " );//Information on the overall operation of the green led
    Serial.print(g);//Display of the variable - the counter g
    Serial.println(" times");//Informs about the status of the system
   }
}