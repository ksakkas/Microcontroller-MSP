/*
This code was designed by Konstantinos Sakkas on May 24th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/
/*
1 * The application will start by pressing "S" (Start) on the keyboard of the connected PC.
2 * The application will end by pressing "S" (Stop) on the keyboard of the connected PC.
3 * The application performs red LED discharge under the control of SW1 (push to start / push to stop).
4 * Respectively performs the green LED discharge under the control of SW2 (push to start / push to stop).
5 * Green LED flashes twice as often as red LED.
*/

const int buttonar = PUSH1;                                     //3* We initialize in the constant button,button PUSH1 (P2.1)
const int buttondex = PUSH2;                                   //We initialize in the constant button,button PUSH2 (P1.1)
int buttonCurrent=0;                                          //We initialize variable buttonCurrent=0
int buttonCurrent2=0;                                        //We initialize variable buttonCurrent2=0

int buttonstate= HIGH;                                     //We initialize variable buttonstate=high which means reasonable/logical 1.
int buttonstate2= HIGH;                                   //We initialize variable buttonstate2=high which means reasonable/logical 1.

void setup() {                                              //Function of initialization of system parameters and materials.
  Serial.begin(9600);                                      //It is the rate of transmission in bits per sec.
  
  pinMode(RED_LED, OUTPUT);                               //Declare RED_LED as output
  pinMode (GREEN_LED, OUTPUT);                           //Declare GREEN_LED as output
  pinMode(buttonar, INPUT_PULLUP);                      //Declare const buttonar as input.
  pinMode(buttondex, INPUT_PULLUP);                    //Declare const buttondex as input.

  Serial.println("Department Informatics & Telecommunication");             //Show message at the beginning of the program
  Serial.println("Microprocessor Systems");           //Show message at the beginning of the program
  Serial.println("Final Implementation of the Project (Part 1)");                                  //Show message at the beginning of the program
  Serial.println("");                                               //Show message at the beginning of the program
  Serial.println("Give S to start the program");          //Show message at the beginning of the program
  Serial.println("Give S again to stop the program");  //Show message at the beginning of the program
  Serial.println("");                                 //Show message at the beginning of the program
  while (!Serial.available())                    //In this step,by using  if command checks if serial entry is available.
  { };                                          //It keeps repeating,it coninues the repeating.
}

void loop() {               //Main repetitive function.
  if(Serial.available())   //In this step,by using  if command checks if serial entry is available.
  {
    String a = Serial.readString(); //1* In the variable a we assign the value given by the user to the serial by converting it to string. 
    
    if(a[0]=='S')                  //1* If a[0] == 'S'
    {
      Serial.println("The Initiation of the System has Begun"); //Show message at the beginning of the program
      Serial.println(""); //Show message at the beginning of the program

      while(1) {                      //Creating repetitive endless loop. 
      buttonCurrent = digitalRead(buttonar);          //3* Assign to the variable buttonCurrent the price of the buttonar (whether pressed or not).
      if(buttonCurrent == LOW )                      //If buttonCurrent == LOW 
      {
       while(1){                                   //Creating repetitive endless loop. 
          digitalWrite(RED_LED, LOW);             //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.

          digitalWrite(GREEN_LED, HIGH);      //5* It gives a reasonable value of 1 (HIGH) to the red led, ie it turns it on.
          delay(250);                        //Delay for 500 ms = 0.5 sec
          digitalWrite(GREEN_LED, LOW);     //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
          delay(250);                      //Delay for 500 ms = 0.5 sec
          
        buttonCurrent = digitalRead(buttonar);            //Assign to the variable buttonCurrent the price of the buttonar (whether pressed or not).
        buttonstate=HIGH;                                //Assign to the variable buttonstate = HIGH
        if(buttonstate == HIGH && buttonCurrent == LOW) //IF buttonstate == HIGH && buttonCurrent == LOW
        {
                   break;                            
        }
       }
      }


      buttonCurrent2 = digitalRead(buttondex);          //Assign to the variable buttonCurrent2 the price of the buttondex (whether pressed or not).
      if(buttonCurrent2 == LOW )                       //If buttonCurrent2 == LOW 
      {
       while(1){                                    //Creating repetitive endless loop. 
          digitalWrite(GREEN_LED, LOW);          //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.

          digitalWrite(RED_LED, HIGH);     //5* It gives a reasonable value of 1 (HIGH) to the red led, ie it turns it on.
          delay(500);                    //Delay for 500 ms = 0.5 sec
          digitalWrite(RED_LED, LOW);   //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
          delay(500);                 //Delay for 500 ms = 0.5 sec
          
        buttonCurrent2 = digitalRead(buttondex);          //Assign to the variable buttonCurrent2 the price of the buttondex (whether pressed or not).
        buttonstate2=HIGH;                         //Assign to the variable buttonstate2 = HIGH
        if(buttonstate2 == HIGH && buttonCurrent2 == LOW) //If buttonstate == HIGH && buttonCurrent == LOW
        {
                   break;
        }
       }
      }

      
      digitalWrite(RED_LED, HIGH);   //It gives a reasonable value of 1 (HIGH) to the red led, ie it turns it on.
      delay(500);             //Delay for 500 ms = 0.5 sec
      digitalWrite(RED_LED, LOW);   //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
      delay(500);  //Delay for 500 ms = 0.5 sec
      
      digitalWrite(GREEN_LED, HIGH);    //It gives a reasonable value of 1 (HIGH) to the red led, ie it turns it on.
      delay(250);               //Delay for 250 ms = 0.25 sec
      digitalWrite(GREEN_LED, LOW);    //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
      delay(250); //Delay for 250 ms = 0.25 sec
    
     if(Serial.available())     //In this step,by using  if command checks if serial entry is available.
      {  
        a = Serial.readString(); //2* In the variable x we assign the value given by the user to the serial by converting it to string.  
        if(a[0]=='S'){                                       //2* If a[0] == 'S'
          Serial.println("System has Been Disable"); //Show message at the beginning of the program
          Serial.println(""); //Show message at the beginning of the program
          break; 
        }
        else
        {}
      }
      }
    }
 }
}
