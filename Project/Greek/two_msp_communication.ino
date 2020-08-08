/*
Αυτός ο κωδικός σχεδιάστηκε από τον Κωνσταντίνο Σάκκα.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων και του github https://ksakkas.github.io/Microcontroller-MSP430/.
*/
/*
Αυτός ο κώδικας σχεδιάστηκε και εκτελέστηκε στο πρόγραμμα Energia έκδοσης 1.8.11E23
Σχεδιάστηκε για χρήση με τον μικροεπεξεργαστή MSP430F5529
*/

/* 1* Να σχεδιαστεί και υλοποιηθεί εφαρμογή η οποία εκτελεί αποστολή και λήψη συμβολοσειρών χαρακτήρων (character strings), 
 * μέσω της ελεύθερης σειριακής θύρας (UART) του συστήματος MSP430F5529 LaunchPad. 
 * 2* Η εφαρμογή θα δέχεται ένα character string από το πληκτρολόγιο του συνδεμένου Η/Υ 
 * 3* (κάθε character string θεωρείτε ότι τερματίζεται με <CR>, <LF> ή συνδυασμό τους ). 
 * 4* Ακολούθως η εφαρμογή θα αποστέλλει χαρακτήρα-χαρακτήρα την συμβολοσειρά στον πομπό του UART. 
 * 5* Αντίστοιχα, η εφαρμογή μπορεί να δέχεται από τον δέκτη του UART χαρακτήρες για την δημιουργία ενός string 
 * 6* (μήκους το πολύ 20 χαρακτήρων). 
 * 7* Κάθε character string θεωρείτε ότι τερματίζεται με <CR>. 
 * 8* Όταν ολοκληρωθεί η λήψη του string αυτό αποστέλλεται στον συνδεμένο Η/Υ. 
 */

void setup() {                               //Συνάρτηση αρχικοποίησης παραμέτρων και υλικών συστήματος
                                            //Αρχικοποιήση και των δύο σειριακών θυρών:
    Serial.begin(9600);                    //Ρυθμός μετάδοσης σε bits / sec (για Serial).
    Serial1.begin(9600);                  //Ρυθμός μετάδοσης σε bits / sec (για Serial1).
    pinMode(RED_LED, OUTPUT);            //Δήλωση RED_LED ως έξοδο
    pinMode(GREEN_LED, OUTPUT);         //Δήλωση GREEN_LED ως έξοδο
    UCA0STAT |=  UCLISTEN;             //Loopback (UART) 

  Serial.println("Department Informatics & Telecommunication");        //Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("Microprocessor Systems");                           //Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("Final Implementation of the Project (Part 1)");    //Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("");                                               //Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("Give character string");                         //Εμφάνιση μηνύματος στην έναρξη του προγράμματος
  Serial.println("");                                             //Εμφάνιση μηνύματος στην έναρξη του προγράμματος

}
int c=0;
void loop() {                                         //Κύρια επαναληπτική συνάρτηση
    if (Serial.available())                          //Αν η σειριακή είσοδος είναι διαθέσιμη
    {                     
      String mes = Serial.readString();            //1, 2* Στην μεταβλητή mes εκχωρούμε την τιμή που έδωσε ο χρήστης στην σειριακή μετατρέποντας το σε αλφαριθμητικό 
      int s=strlen(mes.c_str());                  //Στη μεταβλητή s αντιστοιχίζουμε την τιμή σε μήκος της mes
      Serial.println("Reading the String");      //Εμφάνιση μηνύματος
      for(int i=0; i<s; i++)                    //Δημιουργία βρόχου επανάληψης.
      {
        digitalWrite(RED_LED, HIGH); //Δίνει λογική τιμή 1 (HIGH) στο led δηλαδή το ανάβει
        delay(50);                  //Σταματά την εκτέλεση για 500 ms = 0.5 sec
        digitalWrite(RED_LED, LOW); //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
        delay(50);                //Σταματά την εκτέλεση για 500 ms = 0.5 sec
      }
        for (int i=0; i<s; i++)              //Δημιουργία βρόχου επανάληψης.
        {             
          Serial1.write(mes[i]);                    //1,4* Γράψτε το mes στο Serial1
        }

    }
  
  if (Serial1.available())   //Αν η σειριακή1 είσοδος είναι διαθέσιμη
   {               
    String mes = Serial1.readString();    //1, 5*  Στην μεταβλητή mes εκχωρούμε την τιμή που έδωσε ο χρήστης στην σειριακή μετατρέποντας το σε αλφαριθμητικό 
    int s=strlen(mes.c_str());           //Στη μεταβλητή s αντιστοιχίζουμε την τιμή σε μήκος του mes
    Serial.println(s);                  //Εμφάνιση s
   if(s>21)                            //3, 6* Αν το s > 21
  {
    Serial.println("You have exceeded the limit");     //Εμφάνιση μηνύματος
    Serial.println("Press the restart button to give new character string");     //Εμφάνιση μηνύματος
    Serial.println("");     //Εμφάνιση μηνύματος
    Serial.println("");     //Εμφάνιση μηνύματος
    digitalWrite(RED_LED, HIGH); //Δίνει λογική τιμή 1 (HIGH) στο led δηλαδή το ανάβει
    exit(1);                                 //Επιστρέφει 1
  }
    for (int i=0; i<s; i++){               //Δημιουργία βρόχου επανάληψης.
    digitalWrite(GREEN_LED, HIGH);       //Δίνει λογική τιμή 1 (HIGH) στο led δηλαδή το ανάβει
    delay(200);                         //Σταματά την εκτέλεση για 200 ms = 0.2 sec
    Serial.write(mes[i]);              //1, 8* Γράψτε το mes στο Serial
    digitalWrite(GREEN_LED, LOW);     //Δίνει λογική τιμή 0 (LOW) στο led δηλαδή το σβήνει
    delay(200);                      //Σταματά την εκτέλεση για 200 ms = 0.2 sec
    }
  }
}