// Kindly Check whether the Library Files are installed in Library Manager.

#include <NewPing.h>

#define FRONT_TRIGGER 12 
#define FRONT_ECHO  4  

#define FRONT1_TRIGGER 16
#define FRONT1_ECHO 14

#define FRONT2_TRIGGER 25 
#define FRONT2_ECHO  26  

#define BACK_TRIGGER 17
#define BACK_ECHO 19

#define LEFT_TRIGGER  2
#define LEFT_ECHO  23

#define RIGHT_TRIGGER 5
#define RIGHT_ECHO  18

#define MAX_DISTANCE 400

int front_us, front1_us, front2_us, back_us, left_us, right_us;

NewPing sonar1(FRONT_TRIGGER, FRONT_ECHO, MAX_DISTANCE); 
NewPing sonar5(FRONT1_TRIGGER, FRONT1_ECHO, MAX_DISTANCE); 
NewPing sonar6(FRONT2_TRIGGER, FRONT2_ECHO, MAX_DISTANCE); 

NewPing sonar2(BACK_TRIGGER, BACK_ECHO, MAX_DISTANCE); 
NewPing sonar3(LEFT_TRIGGER, LEFT_ECHO, MAX_DISTANCE);
NewPing sonar4(RIGHT_TRIGGER, RIGHT_ECHO, MAX_DISTANCE); 



void setup() {
  Serial.begin(115200);
}

void loop() {
  US_Values();
}

void US_Values()
{
  front_us = sonar1.ping_cm();
  front1_us = sonar5.ping_cm();
  front2_us = sonar6.ping_cm();
  back_us = sonar2.ping_cm(); 
  left_us = sonar3.ping_cm(); 
  right_us = sonar4.ping_cm(); 

  Serial.println("F1_US : " + String(front1_us) + " | F_US : " + String(front_us) + " | F2_US : " + String(front2_us) + 
              " | B_US : " + String(back_us) + " | L_US : " + String(left_us) + " | R_US : " + String(right_us));

}
