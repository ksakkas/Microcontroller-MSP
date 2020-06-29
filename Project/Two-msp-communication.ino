/*
This code was designed by Konstantinos Sakkas on June 2th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/
/* 1* In this step,we have to  design and implement this application which  sends and receives character strings,
 * via the free serial port (UART) of the system MSP430F5529 LaunchPad. 
 * 2* The application will receive a character string from the keyboard of the connected PC
* 3* each character string is considered to end with <CR>, <LF> or a combination of    them 
* 4* The application afterwards will send character by character the string to the UART transmitter.
* 5* Similarly, the application can accept characters from the UART receiver to create a string
 * 6* (maximum length 20 characters)
 * 7* Each character string is considered to end with <CR>.
 * 8* When the string is completed, it is sented to the connected computer. */

void setup() {                               //Function of initialization of system parameters and materials.
                                            //Initialize both serial ports: 
    Serial.begin(9600);                    //It is the rate of transmission in bits per sec (for Serial).
    Serial1.begin(9600);                  //It is the rate of transmission in bits per sec (for Serial1).
    pinMode(RED_LED, OUTPUT);            //Declare RED_LED as output
    pinMode(GREEN_LED, OUTPUT);         //Declare GREEN_LED as output
    UCA0STAT |=  UCLISTEN;             //Loopback (UART) 

  Serial.println("Department Informatics & Telecommunication");        //Show message at the beginning of the program
  Serial.println("Microprocessor Systems");                           //Show message at the beginning of the program
  Serial.println("Final Implementation of the Project (Part 1)");    //Show message at the beginning of the program
  Serial.println("");                                               //Show message at the beginning of the program
  Serial.println("Give character string");                         //Show message at the beginning of the program
  Serial.println("");                                             //Show message at the beginning of the program

}
int c=0;
void loop() {                                         //Main repetitive function.
    if (Serial.available())                          //In this step,by using  if command checks if serial entry is available.
    {                     
      String mes = Serial.readString();            //1, 2* In the variable mes we assign the value given by the user to the serial by converting it to string.
      int s=strlen(mes.c_str());                  //In the variable s we assign the value to length to mes
      Serial.println("Reading the String");      //Show message at the beginning of the program
      for(int i=0; i<s; i++)                    //Repettiting loop creation.
      {
        digitalWrite(RED_LED, HIGH); //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
        delay(50);                  //Delay for 50 ms = 0.05 sec
        digitalWrite(RED_LED, LOW); //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
        delay(50);                //Delay for 50 ms = 0.05 sec
      }
        for (int i=0; i<s; i++)              //Repettiting loop creation.
        {             
          Serial1.write(mes[i]);                    //1,4* Write mes to Serial1
        }

    }
  
  if (Serial1.available())   //In this step,by using  if command checks if serial entry is available.
   {               
    String mes = Serial1.readString();    //1, 5* In the variable mes we assign the value given by the user to the serial by converting it to string.
    int s=strlen(mes.c_str());           //In the variable s we assign the value to length to mes
    Serial.println(s);                  //Show s
   if(s>21)                            //3, 6* If the s > 21
  {
    Serial.println("You have exceeded the limit");     //Show message
    Serial.println("Press the restart button to give new character string");     //Show message
    Serial.println("");     //Show message
    Serial.println("");     //Show message
    digitalWrite(RED_LED, HIGH); //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
    exit(1);                                 //Return 1
  }
    for (int i=0; i<s; i++){               //Repettiting loop creation.
    digitalWrite(GREEN_LED, HIGH);       //It gives a reasonable value of 1 (HIGH) to the led, ie it turns it on.
    delay(200);                         //Delay for 500 ms = 0.5 sec
    Serial.write(mes[i]);              //1, 8* Write mes to Serial
    digitalWrite(GREEN_LED, LOW);     //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
    delay(200);                      //Delay for 500 ms = 0.5 sec
    }
  }
}

