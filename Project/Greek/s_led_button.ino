/*
Αυτός ο κωδικός σχεδιάστηκε από τον Κωνσταντίνο Σάκκα.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων και του github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
Αυτός ο κώδικας σχεδιάστηκε και εκτελέστηκε στο πρόγραμμα Energia έκδοσης 1.8.11E23
Σχεδιάστηκε για χρήση με τον μικροεπεξεργαστή MSP430F5529
*/

/*
1* Η εκκίνηση της εφαρμογής θα γίνεται πιέζοντας “S”(Start) στο πληκτρολόγιο του συνδεμένου Η/Υ. 
2* Η εφαρμογή θα τερματίζει πιέζοντας “S”(Stop) στο πληκτρολόγιο του συνδεμένου Η/Υ.
3* Η εφαρμογή εκτελεί αφέσβεση του κόκκινου LED υπό τον έλεγχο του SW1 (push to start/push to stop). 
4* Αντίστοιχα εκτελεί αφέσβεση του πράσινου LED υπό τον έλεγχο του SW2 (push to start/push to stop). 
5* Το πράσινο LED αναβοσβήνει με διπλάσια συχνότητα από το κόκκινο LED.
*/


const int buttonar = PUSH1;                                      //Αρχικοποιούμε στην σταθερά button το κουμπί PUSH2 (P2.1)
const int buttondex = PUSH2;                                      //Αρχικοποιούμε στην σταθερά button το κουμπί PUSH2 (P1.1)
int buttonCurrent=0;                                          //Αρχικοποιούμε την μεταβλητή buttonCurrent = 0
int buttonCurrent2=0;                                          //Αρχικοποιούμε την μεταβλητή buttonCurrent2 = 0

int buttonstate= HIGH;                                          //Αρχικοποιούμε την μεταβλητή buttonstate = HIGH δηλαδή λογικό 1
int buttonstate2= HIGH;                                          //Αρχικοποιούμε την μεταβλητή buttonstate2 = HIGH δηλαδή λογικό 1

void setup() {                                             //Συνάρτηση αρχικοποίησης παραμέτρων και υλικών συστήματος
  Serial.begin(9600);                                      //Ρυθμός μετάδοσης σε bits / sec
  
  pinMode(RED_LED, OUTPUT);                               //Δήλωση RED_LED ως έξοδο
  pinMode (GREEN_LED, OUTPUT);                           //Δήλωση GREEN_LED ως έξοδο
  pinMode(buttonar, INPUT_PULLUP);                     //Δήλωση σταθεράς buttonar = PUSH1 ως έξοδο
  pinMode(buttondex, INPUT_PULLUP);                  //Δήλωση σταθεράς buttondex = PUSH2 ως έξοδο

  Serial.println("Τμήμα Πληροφορικής & Τηλεπικοινωνιών "); //Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("");//Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("Δώσε S για να ξεκινήσει το πρόγραμμα");//Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("Ξανά δώσε S για να σταματήσει το πρόγραμμα");//Εμφάνιση μηνύματος στην έναρξη του προγράμματος

  while (!Serial.available()) //Όσο η σειριακή είσοδος δεν είναι διαθέσιμη *δεν θα κάνει τίποτα 
  { }; //*δεν θα κάνει τίποτα 
}

void loop() {              //Κύρια επαναληπτική συνάρτηση
  if(Serial.available())  //Αν η σειριακή είσοδος είναι διαθέσιμη
  {
    String a = Serial.readString(); //Στην μεταβλητή a εκχωρούμε την τιμή που έδωσε ο χρήστης στην σειριακή μετατρέποντας το σε αλφαριθμητικό 
    
    if(a[0]=='S') //Αν το x έχει την τιμή του ίση με S
    {
      while(1) {                      //Όσο το x = 1 => δημιουργία επαναληπτικού ατέρμον βρόγχου 
      buttonCurrent = digitalRead(buttonar);          //Εκχώρηση στην μεταβλητή buttonCurrent την τιμή του Buttonar (εαν πατήθηκε ή όχι)
      if(buttonCurrent == LOW )                      //Εαν έχει πατηθεί το κουμπί
      {
       while(1){                                   //Δημιουργία επαναληπτικού ατέρμον βρόγχου 
          digitalWrite(RED_LED, LOW);             //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει

          digitalWrite(GREEN_LED, HIGH);     //Δίνει λογική τιμή 1 (HIGH) στο led δηλαδή το ανάβει
          delay(250);                       //Σταματά την εκτέλεση για 250 ms = 0.25 sec
          digitalWrite(GREEN_LED, LOW);    //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
          delay(250);                     //Σταματά την εκτέλεση για 250 ms = 0.25 sec
          
        buttonCurrent = digitalRead(buttonar);            //Εκχώρηση στην μεταβλητή buttonCurrent την τιμή του Button (εαν πατήθηκε ή όχι)
        buttonstate=HIGH;                                //Εκχώρηση στην μεταβλητή buttonstate = HIGH
        if(buttonstate == HIGH && buttonCurrent == LOW) //AN buttonstate == HIGH && buttonCurrent == LOW
        {
                   break;                            
        }
       }
      }


      buttonCurrent2 = digitalRead(buttondex);          //Εκχώρηση στην μεταβλητή buttonCurrent2 την τιμή του buttondex (εαν πατήθηκε ή όχι)
      if(buttonCurrent2 == LOW )                       //Εαν έχει πατηθεί το κουμπί
      {
       while(1){
          digitalWrite(GREEN_LED, LOW);   //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει

          digitalWrite(RED_LED, HIGH);    //Δίνει λογική τιμή 1 (HIGH) στο led δηλαδή το ανάβει
          delay(500);                    //Σταματά την εκτέλεση για 500 ms = 0.5 sec
          digitalWrite(RED_LED, LOW);   //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
          delay(500);                 //Σταματά την εκτέλεση για 500 ms = 0.5 sec
          
        buttonCurrent2 = digitalRead(buttondex);          //Εκχώρηση στην μεταβλητή buttonCurrent την τιμή του Button (εαν πατήθηκε ή όχι)
        buttonstate2=HIGH;                         //Εκχώρηση στην μεταβλητή buttonstate2 = HIGH
        if(buttonstate2 == HIGH && buttonCurrent2 == LOW) //AN buttonstate == HIGH && buttonCurrent == LOW
        {
                   break;
        }
       }
      }

      
      digitalWrite(RED_LED, HIGH);   //Δίνει λογική τιμή 1 (HIGH) στο red led δηλαδή το ανάβει
      delay(500);             //Σταματά την εκτέλεση για 500 ms = 0.5 sec
      digitalWrite(RED_LED, LOW);   //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
      delay(500);  //Σταματά την εκτέλεση για 500 ms = 0.5 sec
      
      digitalWrite(GREEN_LED, HIGH);    //Δίνει λογική τιμή 1 (HIGH) στο red led δηλαδή το ανάβει
      delay(250);               //Σταματά την εκτέλεση για 250 ms = 0.25 sec
      digitalWrite(GREEN_LED, LOW);    //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
      delay(250); //Σταματά την εκτέλεση για 250 ms = 0.25 sec
    
     if(Serial.available())     //Αν η σειριακή είσοδος είναι διαθέσιμη
      {  
        a = Serial.readString(); //Στην μεταβλητή x εκχωρούμε την τιμή που έδωσε ο χρήστης στην σειριακή μετατρέποντας το σε ακέραιο 
        if(a[0]=='S') //Αν το x έχει την τιμή του ίση με 0
          break; //Σταματάει την επανάληψη  
        else
        {}
      }
      }
    }
   
    
 }
}