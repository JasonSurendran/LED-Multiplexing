//Jason Surendran
//Multiplexing Project

//GENERAL Game Variable Setup
int DIAGONAL,SNAKE,PONG,NAME;

//PONG Variable Setup
int p1,p2,p3;

//NAME Variable Setup
int PinsA[12] = {2,3,4,5,6,7,8,9,10,11,12,13}; //2-4 Positive Pins, 4-13 Negative Pins
int SymbolA [2][12] = {
 {0,0,1,1,0,0,1,0,1,0,0,0},//J
 {0,0,1,0,0,0,0,0,0,0,0,0},//S
 };


//DIAGONAL Variable Setup
int PinsC [12] = {2,3,4,5,6,7,8,9,10,11,12,13}; //2-4 Positive Pins, 4-13 Negative Pins
int SymbolC [9][12] = {
 {0,0,1,1,1,1,1,1,1,1,1,0}, {0,0,1,1,1,1,1,1,1,1,0,1}, {0,0,1,1,1,1,1,1,0,1,1,1},{0,0,1,1,1,1,1,1,1,0,1,1}, 
 {0,0,1,1,1,1,1,0,1,1,1,1}, {0,0,1,1,1,0,1,1,1,1,1,1}, {0,0,1,1,1,1,0,1,1,1,1,1},{0,0,1,1,0,1,1,1,1,1,1,1}, 
 {0,0,1,0,1,1,1,1,1,1,1,1}, };

 
//SNAKE Variable Setup
int PinsB [12] = {2,3,4,5,6,7,8,9,10,11,12,13}; //2-4 Positive Pins, 4-13 Negative Pins
int SymbolB [53][12] = { 
 {0,0,1,1,1,1,1,1,1,1,1,0}, {0,0,1,1,1,1,1,1,1,1,0,1}, {0,0,1,1,1,1,1,1,1,0,1,1}, {0,0,1,1,1,1,0,1,1,1,1,1}, 
 {0,0,1,1,1,1,1,0,1,1,1,1}, {0,0,1,1,1,1,1,1,0,1,1,1}, {0,0,1,1,1,0,1,1,1,1,1,1}, {0,0,1,1,0,1,1,1,1,1,1,1},
 {0,0,1,0,1,1,1,1,1,1,1,1}, {0,1,0,0,1,1,1,1,1,1,1,1}, {0,1,0,1,0,1,1,1,1,1,1,1}, {0,1,0,1,1,0,1,1,1,1,1,1}, 
 {0,1,0,1,1,1,1,1,0,1,1,1}, {0,1,0,1,1,1,1,0,1,1,1,1}, {0,1,0,1,1,1,0,1,1,1,1,1}, {0,1,0,1,1,1,1,1,1,0,1,1},
 {0,1,0,1,1,1,1,1,1,1,0,1}, {0,1,0,1,1,1,1,1,1,1,1,0}, {1,0,0,1,1,1,1,1,1,1,1,0}, {1,0,0,1,1,1,1,1,1,1,0,1}, 
 {1,0,0,1,1,1,1,1,1,0,1,1}, {1,0,0,1,1,1,0,1,1,1,1,1}, {1,0,0,1,1,1,1,0,1,1,1,1}, {1,0,0,1,1,1,1,1,0,1,1,1}, 
 {1,0,0,1,1,0,1,1,1,1,1,1}, {1,0,0,1,0,1,1,1,1,1,1,1}, {1,0,0,0,1,1,1,1,1,1,1,1}, {1,0,0,1,0,1,1,1,1,1,1,1}, 
 {1,0,0,1,1,0,1,1,1,1,1,1}, {1,0,0,1,1,1,1,1,0,1,1,1}, {1,0,0,1,1,1,1,0,1,1,1,1}, {1,0,0,1,1,1,0,1,1,1,1,1}, 
 {1,0,0,1,1,1,1,1,1,0,1,1}, {1,0,0,1,1,1,1,1,1,1,0,1}, {1,0,0,1,1,1,1,1,1,1,1,0}, {0,1,0,1,1,1,1,1,1,1,1,0},
 {0,1,0,1,1,1,1,1,1,1,0,1}, {0,1,0,1,1,1,1,1,1,0,1,1}, {0,1,0,1,1,1,0,1,1,1,1,1}, {0,1,0,1,1,1,1,0,1,1,1,1}, 
 {0,1,0,1,1,1,1,1,0,1,1,1}, {0,1,0,1,1,0,1,1,1,1,1,1}, {0,1,0,1,0,1,1,1,1,1,1,1}, {0,1,0,0,1,1,1,1,1,1,1,1},
 {0,0,1,0,1,1,1,1,1,1,1,1}, {0,0,1,1,0,1,1,1,1,1,1,1}, {0,0,1,1,1,0,1,1,1,1,1,1}, {0,0,1,1,1,1,1,1,0,1,1,1}, 
 {0,0,1,1,1,1,1,0,1,1,1,1}, {0,0,1,1,1,1,0,1,1,1,1,1}, {0,0,1,1,1,1,1,1,1,0,1,1}, {0,0,1,1,1,1,1,1,1,1,0,1},
 {0,0,1,1,1,1,1,1,1,1,1,0}
 };
 
void setup() {
 Serial.begin(9600);
  for (int i=2; i<14;i++){
    pinMode(i,OUTPUT);}}
void loop() {

//Set each game to an analog
DIAGONAL = analogRead(A8);
SNAKE = analogRead(A7);
PONG = analogRead(A10);
NAME = analogRead(A11);

//Diagonal Loop Code
{if (DIAGONAL>1020 && SNAKE<1020 && PONG<1020 && NAME<1020){ //Set Condition for Diagonal to Run
  //Array for Diagonal (Run variations)
  for(int i=0;i<=8;i++){
    for(int j=0;j<=11;j++){
      digitalWrite(PinsC[j],SymbolC[i][j]); }
    delay(500);}}
    
//Snake Loop Code
else if (DIAGONAL<1020 && SNAKE>1020 && PONG<1020 && NAME<1020){ //Set Condition for Snake to Run
    //Array for Snake (Run variations)
    for(int i=0;i<=52;i++){
      for(int j=0;j<=11;j++){
       digitalWrite(PinsB[j],SymbolB[i][j]); }
      delay(500);}
      }



//Name Loop Code
else if (DIAGONAL<1020 && SNAKE<1020 && PONG<1020 && NAME>1020){ //Set Condition for Name to Run
       //Array for Name (Run variations)
       for(int i=0;i<=1;i++){
           for(int j=0;j<50;j++){
                for(int k=0;k<=11;k++){
                   digitalWrite(PinsA[k],SymbolA[i][k]);}
                   delay(10);
                   for(int k=0;k<=11;k++){
                        digitalWrite(PinsA[k],1);}
                        delay(10);}
                        }
                      }
                   }
                                   
//Pong Loop Code
else if (DIAGONAL<1020 && SNAKE<1020 && PONG>1020 && NAME<1020){
  //Read analog pins for potentiometers
  p1 = analogRead(A0);
  p2 = analogRead(A1);
  p3 = analogRead(A2);
    for(int i=2;i<5;i++){
      digitalWrite(i,LOW);}
    for(int k=5;k<14;k++){
       digitalWrite(k,HIGH);}
       
          {if (p2 > 400 && p2<800 ){digitalWrite (3, HIGH); //Middle Row (y-axis)
           //Set x-axis and z-axis variation for Middle Row
           if (p3 > 400 && p3<800 && p1 > 400 && p1<800 ){  digitalWrite (9, LOW);} 
           if (p3 < 400 && p1 > 400 && p1<800 ){  digitalWrite (10, LOW);}
           if (p3 > 800 && p1 > 400 && p1<800 ){  digitalWrite (8, LOW);}
           if (p3 > 400 && p3 < 800 && p1 < 400 ){  digitalWrite (12, LOW);} 
           if (p3 > 800  && p1 < 400 ){  digitalWrite (11, LOW);}
           if (p3 < 400 && p1 < 400 ){  digitalWrite (13, LOW);}
           if (p3 > 400 && p3 < 800 && p1 > 800 ){  digitalWrite (6, LOW);} 
           if (p3 > 800  && p1 > 800 ){  digitalWrite (5, LOW);}
           if (p3 < 400 && p1 > 800 ){  digitalWrite (7, LOW);}
           }
           
           else if (p2 > 800){digitalWrite (4, HIGH); //Top Row (y-axis)
           //Set x-axis and z-axis variation for Top Row
           if (p3 > 400 && p3<800 && p1 > 400 && p1<800 ){digitalWrite (9, LOW);} 
           if (p3 < 400 && p1 > 400 && p1<800 ){digitalWrite (10, LOW);}
           if (p3 > 800 && p1 > 400 && p1<800 ){digitalWrite (8, LOW);}
           if (p3 > 400 && p3 < 800 && p1 < 400 ){digitalWrite (12, LOW);} 
           if (p3 > 800  && p1 < 400 ){digitalWrite (11, LOW);}
           if (p3 < 400 && p1 < 400 ){digitalWrite (13, LOW);}
           if (p3 > 400 && p3 < 800 && p1 > 800 ){digitalWrite (6, LOW);} 
           if (p3 > 800  && p1 > 800 ){digitalWrite (5, LOW);}
           if (p3 < 400 && p1 > 800 ){digitalWrite (7, LOW);}
           }
           
           else if (p2 < 400){digitalWrite (2, HIGH);  //Bottom Row (y-axis)
           //Set x-axis and z-axis variation for Bottom Row
           if (p3 > 400 && p3 < 800 && p1 > 400 && p1<800 ){digitalWrite (9, LOW);} 
           if (p3 < 400 && p1 > 400 && p1<800 ){digitalWrite (10, LOW);}
           if (p3 > 800 && p1 > 400 && p1<800 ){digitalWrite (8, LOW);}
           if (p3 > 400 && p3 < 800 && p1 < 400 ){digitalWrite (12, LOW);} 
           if (p3 > 800  && p1 < 400 ){digitalWrite (11, LOW);}
           if (p3 < 400 && p1 < 400 ){digitalWrite (13, LOW);}
           if (p3 > 400 && p3 < 800 && p1 > 800 ){digitalWrite (6, LOW);} 
           if (p3 > 800  && p1 > 800 ){digitalWrite (5, LOW);}
           if (p3 < 400 && p1 > 800 ){digitalWrite (7, LOW);}
           }
         }
       }
     }



