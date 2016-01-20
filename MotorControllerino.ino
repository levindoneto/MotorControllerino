const int Motor1[] = {2, 3, 5};
const int Motor2[] = {12, 13, 6};
int botao = 4;
int cont = 0;
const int MAX = 255;

void moveFrente() {
 
  analogWrite (Motor1[2], MAX); // pwm motor 1
 analogWrite (Motor2[2], MAX); //pwm motor 2
 // motor 1
 digitalWrite (Motor1[0], HIGH) ; // (+)
 digitalWrite (Motor1[1], LOW); // (-)
 // motor 2 
 digitalWrite (Motor2[0], LOW) ; // (-)
 digitalWrite (Motor2[1], HIGH); // (+)
}

void moveTras() {
 analogWrite (Motor1[2], MAX); // pwm motor 1
 analogWrite (Motor2[2], MAX); //pwm motor 2
 // motor 1
 digitalWrite (Motor1[0], LOW); // (-)
 digitalWrite (Motor1[1], HIGH) ; // (+)
 // motor 2 
 digitalWrite (Motor2[0], HIGH); // (+)
 digitalWrite (Motor2[1], LOW) ; // (-)
}

void moveDir() {
 analogWrite (Motor1[2], MAX); // pwm motor 1
 analogWrite (Motor2[2], MAX); //pwm motor 2
 // motor 1
 digitalWrite (Motor1[0], LOW); // (-)
 digitalWrite (Motor1[1], HIGH) ; // (+)
 // motor 2 
 digitalWrite (Motor2[0], LOW) ; // (-)
 digitalWrite (Motor2[1], HIGH); // (+)
}

void moveEsq() {
 analogWrite (Motor1[2], MAX); // pwm motor 1
 analogWrite (Motor2[2], MAX); //pwm motor 2
 // motor 1
 digitalWrite (Motor1[0], HIGH) ; // (+)
 digitalWrite (Motor1[1], LOW); // (-)
 // motor 2 
 digitalWrite (Motor2[0], HIGH); // (+)
 digitalWrite (Motor2[1], LOW) ; // (-)
}

void moveNo() {
 analogWrite (Motor1[2], 0); // pwm motor 1
 analogWrite (Motor2[2], 0); //pwm motor 2

}

void setup() {
  for(int i=0; i<3; i++){
    pinMode(Motor1[i], OUTPUT);
  }
    for(int i=0; i<3; i++){
    pinMode(Motor2[i], OUTPUT);
  }
  pinMode(botao, INPUT);
}

void loop() {
  if (digitalRead(botao) == HIGH){
    delay(2000);
    cont++; 
  } 
  switch(cont){
   case 0:
     moveNo(); break;
   case 1:
     moveFrente(); break;
   case 2:
     moveTras(); break;
   case 3:
     moveDir(); break;
   case 4:
     moveEsq(); break;
  }
  if (cont > 4) cont = 0; 
}
