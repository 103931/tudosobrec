#include <Ultrasonic.h>
const int pino_trigger = 8;
const int pino_echo = 11;

// são os pinos do motor;
int motor1_a = 3;
int motor1_b = 5;
int motor2_a = 9;
int motor2_b = 7;
long randNumber;

Ultrasonic ultrasonic_sensor(pino_trigger, pino_echo);

// isso é um tipo char. Isso garante que o código sempre funcione
uint8_t comando; 


// isso é um tipo char. Isso garante que o código sempre funcione
uint8_t comandoManual; 
void setup() {
 Serial.begin(9600);
 Serial.println("Teste sensor ultrassom");
 pinMode(motor1_a, OUTPUT);
 pinMode(motor1_b, OUTPUT);
 pinMode(motor2_a, OUTPUT);
 pinMode(motor2_b, OUTPUT);
 randomSeed(analogRead(0));
 comando = 's';
 comandoManual = 's';
}

void loop() {
    delay(1000);

  float cmMsec, inMsec;
  long microsec = ultrasonic_sensor.timing();
  cmMsec = ultrasonic_sensor.convert(microsec, Ultrasonic::CM);
//  inMsec = ultrasonic_sensor.convert(microsec, Ultrasonic::IN);
  Serial.println("Distância em centímetro:");
  Serial.println(cmMsec);

  Serial.println("Distância em polegadas:");
 Serial.println(inMsec);
 delay(5000);

  if(Serial.available()){
   comando =  Serial.read();  
   comandoManual = comando;
  }
 


if(comandoManual == 's'){
  if(comando == 'f'){
  forward();
  }else if(comando == 'a'){
    backward();
  }else if(comando == 'p'){
     break1;
  }else if(comando == 'r'){
     rigth();
  }else if(comando == 'l'){
   left();
  }else
       break1;
  }else{
    forward();
  if(cmMsec <15 && cmMsec != 0){
    break1;
    delay(5000);
    backward();
   delay(20000);
   if(randNumber == 1){
    left();
   }else{
    rigth();
   }
   delay(5000);
  }
  }
}

void left(){
   digitalWrite(motor1_a, HIGH);
   digitalWrite(motor1_b, HIGH);
   digitalWrite(motor2_a, LOW);
   digitalWrite(motor2_b, LOW);
}

void rigth(){
   digitalWrite(motor1_a, HIGH);
   digitalWrite(motor1_b, HIGH);
   digitalWrite(motor2_a, LOW);
   digitalWrite(motor2_b, LOW);
}

void  break1(){
   digitalWrite(motor1_a, LOW);
   digitalWrite(motor1_b, LOW);
   digitalWrite(motor2_a, LOW);
   digitalWrite(motor2_b, LOW);
}


void  forward(){
   digitalWrite(motor1_a, HIGH);
   digitalWrite(motor1_b, LOW);
   digitalWrite(motor2_a, HIGH);
   digitalWrite(motor2_b, LOW);
}

void  backward(){
   digitalWrite(motor1_a, LOW);
   digitalWrite(motor1_b, HIGH);
   digitalWrite(motor2_a, LOW);
   digitalWrite(motor2_b, HIGH);
}
