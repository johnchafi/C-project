//////////////////////////////////////////////////////////////////////
/////////////////////// PROJET ANALYSOL //////////////////////////////
//////////////////////////////////////////////////////////////////////
int horaire[] = {13,10,7,4,3,2,5,8,11,12,13};

void setup() {
 Serial.begin(9600);
  for(int i=2;i<14;i++){
    pinMode(i, OUTPUT);
  }

    // affichage sens 1
  for (int i = 13;i>1;i--){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
  
  // affichage sens 2
  for (int i = 2;i<14;i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }

 // affichage horaire
 for (int i = 0;i<sizeof(horaire);i++){
 digitalWrite(horaire[i],HIGH);
 delay(100);
 digitalWrite(horaire[i],LOW);
 }

   
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int Valcapt1 = 100- map(analogRead(A0),0,1023,0,100);
  int Valcapt2 = 100- map(analogRead(A1),0,1023,0,100);
  int Valcapt3 = 100- map(analogRead(A2),0,1023,0,100);
  int Valcapt4 = 100- map(analogRead(A3),0,1023,0,100);

  int valeurs[] = {Valcapt1,Valcapt2,Valcapt3,Valcapt4};
  for(int i=0;i<4;i++){
    Serial.print(" : ");
    Serial.print( valeurs[i] );
    Serial.print(" : ");
  }
  Serial.println(" ");

  //////////////////////////// valeur pour les plantes
          // PLANTE 1: // LYS
          int p1_phase1 = 50; //orange humide
          int p1_phase2 = 15; //seuil critique secheresse
          
          // PLANTE 2: // humide rouge et blanche
          int p2_phase1 = 65; //orange humide
          int p2_phase2 = 25; //seuil critique secheresse 
           
          // PLANTE 3: // orchidée
          int p3_phase1 = 65; //orange humide
          int p3_phase2 = 25; //seuil critique secheresse
          
          // PLANTE 4: //GUSMANIA MAXIMA 1 arrosage fois par semaine
          int p4_phase1 = 50; //orange humide
          int p4_phase2 = 15; //seuil critique secheresse
          
/////////////////////////////// running du code

        /////////////////////// CODE PLANTE 1
if(Valcapt1 >= p1_phase1){
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
}
if(Valcapt1 >= p1_phase2 && Valcapt1 <p1_phase1){
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
}
if(Valcapt1 <p1_phase2){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
}
        //////////////////////// CODE PLANTE 2
if(Valcapt2 >= p2_phase1){
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
}
if(Valcapt2 >= p2_phase2 && Valcapt2 <p2_phase1){
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
}
if(Valcapt2 <p2_phase2){
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
}        
        //////////////////////// CODE PLANTE 3
if(Valcapt3 >= p3_phase1){
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
}
if(Valcapt3 >= p3_phase2 && Valcapt3 <p3_phase1){
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
}
if(Valcapt3 <p3_phase2){
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
}        
        //////////////////////// CODE PLANTE 4
if(Valcapt4 >= p4_phase1){
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}
if(Valcapt4 >= p4_phase2 && Valcapt4 <p4_phase1){
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
}
if(Valcapt4 <p4_phase2){
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}                 
}
