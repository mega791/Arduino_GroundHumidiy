int C = 1047;  
int D = 1175;  
int E = 1319; 
int F = 1397;  
int G = 1568; 
int A = 1760;  
int B = 1976;  


#include<AFMotor.h>  // need Adafruit_Motor_Shield_library folder
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
// Motor use (in MotorShield M1, M2 port)


// GH(Ground Humidity) S (sensor) part, GHS
#define GHS1 A7
#define GHS2 A8
int sensorVal1 = 0;
int sensorVal2 = 0;
//GHS use A7,A8


//sound part
#define piezo 46
int notes[25] = { G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };   
int tempo = 200;
// piezo use D46(pwm)


//manual oper part
#define btn1 42  // manual turn on
#define btn2 43  // manual turn off
//manual use D42, D43



void setup() {
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);

  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);

}

void loop() {
  int i; // motor variable
  
  sensorVal1 = analogRead(GHS1);
  delay(500);

  sensorVal2 = analogRead(GHS2);
  delay(500);

  

 //need water Activate motor 1,2
  if( sensorVal1 > 870 ) {
      for(int i=0; i<5; i++) {    //pump Activate melody 1
      tone(piezo,notes[i],tempo);
      delay(300);
    }

    motor1.setSpeed(150);
    motor1.run(FORWARD);
    delay(2000);
     noTone(piezo);
  }


 if( sensorVal2 > 870 ) {
    for(int i=6; i<11; i++) {    //pump Activate melody 2
      tone(piezo,notes[i],tempo);
      delay(300);
    }

    motor2.setSpeed(150);
    motor2.run(FORWARD);
    delay(2000);
      noTone(piezo);
 }

 
  //manual turn on/off part

    if(digitalRead(btn1) == HIGH) { //m turn on
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    delay(500);
    }
 
   if(digitalRead(btn2) == HIGH) {  //m turn off
      motor1.run(RELEASE);   
      motor2.run(RELEASE);
  }


 }
 