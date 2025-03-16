// Kindly Check whether the Library Files are installed in Library Manager.

#define DPDT_Push_Button_Pin 34

bool DPDT_STATE = 0; //Initial False state.

void setup() {
  Serial.begin(115200);

  //######### DPDT Setup #########//
  pinMode(DPDT_Push_Button_Pin, INPUT);
}

void loop() {

  DPDT_STATE = digitalRead(DPDT_Push_Button_Pin);
  Serial.println("DPDT Button State : "+String(DPDT_STATE));

}
