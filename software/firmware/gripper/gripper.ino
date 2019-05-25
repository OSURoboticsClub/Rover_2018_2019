//Pinouts
//Settings
#define AMPMAX 4 // probably can take 6 but 4 is good for safety.
#define FORWARD 1 //pinch = forward  open = !forward

bool homed = false;
float speed = 0; //0-100
float speedLimit=0;

//function stubs
bool home(); // used to home the gripper moter

void setup() {
  // Pin Setup:

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorUpdate();

  if(homed)
  {
    homed = home();
  }
  else
  {
    
  }
  

}

void sensorUpdate();

bool home()
{
  // four volt shut off
  speed


  return 1;
}

float limitUpdate()
{

  return speedLimit
}
