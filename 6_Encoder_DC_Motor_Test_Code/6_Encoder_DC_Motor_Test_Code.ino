////////////--DC Motor Test Code--//////////////
const int motorPin1 = 32; 
const int motorPin2 = 33; 
const int nslp = 13; 
const int frequency = 5000;
int speed = 200;
////////////--IR Encoder Code--//////////////
const int irSensorPin = 36;
int irSensorState = 0;
bool flag = 1;
int enc_count = 0; 
////////////////////////////////////////

int enc_val = 250;

////////////////////////////////////////



// DC Motor
void motor_forward(int speed) // Speed Value (0 - 255)
{ 
  ledcWrite(5, speed);
  ledcWrite(6, 0);
 // Serial.println("motor_forward");
}

void motor_backward(int speed) // Speed Value (0 - 255)
{ 
  ledcWrite(5, 0);
  ledcWrite(6, speed);
 // Serial.println("motor_backward");
}

void motor_stop() {
  ledcWrite(5, 0);
  ledcWrite(6, 0);
  //Serial.println("motor_stop");
}


void setup() {
  Serial.begin(115200);
  //######### DC Motor Setup ###########//
  ledcSetup(5, frequency, 8);
  ledcSetup(6, frequency, 8);
  ledcAttachPin(motorPin1, 5);
  ledcAttachPin(motorPin2, 6);
  pinMode(nslp, OUTPUT);
  digitalWrite(nslp, HIGH);

  //######### IR Setup ###########//
  pinMode(irSensorPin, INPUT);

}
 
void loop() {


  if(flag == 1)
  {
    motor_forward(200);
    
    irSensorState = analogRead(irSensorPin);
 
    if (irSensorState < 1000)
    {
      enc_count++;
      Serial.println("Rotation enc_count : " + String(enc_count));
    }
  
  }

 
  // Check if enc_counts have reached the threshold
  if (enc_count == enc_val)//((175 <= enc_count) && (enc_count <= 200)) 
  {
    flag= 0;
    motor_stop();
    enc_count = 0;  
  }

}