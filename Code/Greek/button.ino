/*
Αυτός ο κωδικός σχεδιάστηκε από τον Κωνσταντίνο Σάκκα στις 7 Αυγούστου 2020.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων και του github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
Αυτός ο κωδικός σχεδιάστηκε και εκτελέστηκε στο Energia ver. 1.8.11E23
Σχεδιάστηκε για χρήση με TI MSP430F5529
*/

//Παράδειγμα με χρήση κουμπιού

const int button = PUSH2;                  //δήλωση ως σταθερά button P1.1
const int gled =  GREEN_LED;              //δήλωση ως σταθερά green led

int buttonstate = 0;                     //Αρχικοποίηση buttonstate = 0 (για την κατάσταση του κουμπιού)

void setup() {
  pinMode(gled, OUTPUT);              //Δηλώση gled ως έξοδο   
  pinMode(button, INPUT_PULLUP);     //Δηλώση button ως INPUT_PULLUP 
}

void loop(){                                //Κύρια επαναλαμβανόμενη συνάρτηση
  
  buttonstate = digitalRead(button);      //Διαβάστε την κατάσταση του κουμπιού

  if (buttonstate == HIGH) {     //ελέγξτε εάν το κουμπί είναι πατημένο => buttonState = HIGH.    
    digitalWrite(gled, HIGH);   //Δίνει λογική τιμή 1 (HIGH) στο led, δηλαδή το ανάβει.
  } 
  else {
    digitalWrite(gled, LOW);  //Δίνει λογική τιμή 0 (LOW) στο led, δηλαδή το απενεργοποιεί.
  }
}
 
