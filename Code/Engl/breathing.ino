/*
This code was designed by Konstantinos Sakkas on August 7th 2020.
It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina and my github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
This code was designed and compiled at Energia ver. 1.8.11E23
It was designed for use with TI MSP430F5529
*/

//Breathing Effect

void setup() {
  pinMode(RED_LED, OUTPUT); //Declare RED_LED as output (immediately)
}

int k = 20000; //Var for Period (T)
int i = 0; //Var for counter
int j = 10; //Var for Time on
int l = 50; //Var for Step
 
void loop() {
  digitalWrite(RED_LED, HIGH); //Δίνει λογική τιμή 1 (HIGH) στο led, δηλαδή το ανάβει.
  for(i=0; i<j; i++) {}       //for loop with null for Breathing
  digitalWrite(RED_LED, LOW); //It gives a reasonable value of 0 (LOW) to the led, ie it turns it off.
  for(i=j; i<k; i++){}       //for loop with null for Breathing
  j=j+l;                    // l (-10)
  if(j>19000)              //if j >19000
  {
    l=l*-1;              //we reduce l
  }
  if(j<5)               //if j < 5
  {
    l=l*-1;           //we reduce l
  }
  
}