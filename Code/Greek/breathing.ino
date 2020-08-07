/*
Αυτός ο κωδικός σχεδιάστηκε από τον Κωνσταντίνο Σάκκα στις 7 Αυγούστου 2020.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων και του github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
Αυτός ο κωδικός σχεδιάστηκε και εκτελέστηκε στο Energia ver. 1.8.11E23
Σχεδιάστηκε για χρήση με TI MSP430F5529
*/

//Breathing Effect

void setup() {
  pinMode(RED_LED, OUTPUT); //Δηλώση RED_LED ως έξοδο 
}

int k = 20000; //Περίοδος (T)
int i = 0;    //Μετρητής
int j = 10;  //Time on
int l = 50; //Step = Βήμα
 
void loop() {
  digitalWrite(RED_LED, HIGH);   //Δίνει λογική τιμή 1 (HIGH) στο led, δηλαδή το ανάβει.
  for(i=0; i<j; i++) {}         //Eπαναληπτικός βρόγχος για το Breathing
  digitalWrite(RED_LED, LOW);  //Δίνει λογική τιμή 0 (LOW) στο led, δηλαδή το απενεργοποιεί.
  for(i=j; i<k; i++){}        //Eπαναληπτικός βρόγχος για το Breathing
  j=j+l;                     //το l γίνεται (-10)
  if(j>19000)               //Αν το j > 19000
  {
    l=l*-1;               //Mειώνουμε το l
  }
  if(j<5)               //Aν το j < 5
  {
    l=l*-1;           //Mειώνουμε το l
  }
  
}