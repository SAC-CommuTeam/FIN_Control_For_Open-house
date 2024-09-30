#include <Servo.h>
#define L_SW_PIN 20
#define R_SW_PIN 21

Servo FIN_Left;
Servo FIN_Right;
int offset = 95;

int a = 0;
int b = 0;
int Trig_servo =0;
int Servo_L = 95;
int Servo_R = 95;
bool L_SW = true ;
bool R_SW = true ;


void L_sw()
{
   if ( digitalRead(L_SW_PIN) == 0 && a == 1)
  {
    L_SW = !L_SW ;
    Trig_servo +=10;
    a = 0;   
  }
  else if ( digitalRead(L_SW_PIN) == 1 && a == 0)a = 1;
  Serial.print("L_sw : ");Serial.print(L_SW);
}

void R_sw()
{
   if ( digitalRead(R_SW_PIN) == 0 && b == 1)
  {
    R_SW = !R_SW ;
    Trig_servo -=10;
    b = 0;   
  }
  else if ( digitalRead(R_SW_PIN) == 1 && b == 0)b = 1;
   Serial.print("\t R_sw : ");Serial.print(R_SW);
}



void setup() 
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(L_SW_PIN, INPUT_PULLUP);
  pinMode(R_SW_PIN, INPUT_PULLUP);
  
  digitalWrite(LED_BUILTIN, LOW);
  FIN_Left.attach(19);
  FIN_Right.attach(18);
  FIN_Left.write(offset);  
  FIN_Right.write(offset); 
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  L_sw();
  R_sw();
  
  if      ((Trig_servo)<=-95)Trig_servo=-95;
  else if ((Trig_servo)>=95)  Trig_servo=95;
 
  Serial.print(" Trig_servo : ");Serial.println(Trig_servo); 
  
  FIN_Left.write(offset+Trig_servo);  
  FIN_Right.write(offset-Trig_servo); 
}
