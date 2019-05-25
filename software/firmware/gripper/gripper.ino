//Pinouts
//Settings
#define AMPMAX 4 // probably can take 6 but 4 is good for safety.
#define FORWARD 1 //pinch = forward  open = !forward




//function stubs
void sensorUpdate(); //used to update all internal sensor values
void getmodBusUpdate();
bool home(); // used to home the gripper moter
void limitUpdate();
void moveMotor(); 


// average class discriber
template <typename T> 
class Average
{
public:
  Average(int arraySize); // made to handle possible error case

  T update(T);
  bool full();

  // library-accessible "private" interface
private:
  T *myQueue;
  int size = 0;
  int length;
  void enqueue(T);
  T queueAve();
};



//general settings
bool ishomed = false;
float speed = 0; //0-100?

//sensor variables
float currentAMPS = 0;

//speed limit variables
float currentSpeedLimit=0;

//homing variables
Average<float> ampAverage = Average<float>(20); //Used in homing function
Average<float> localAmpAverage = Average<float>(4);




void setup() {
  // Pin Setup:

}

void loop() {
  sensorUpdate();
  getmodBusUpdate(); //canU
  
  if(ishomed)
  {
    ishomed = home();
  }
  limitUpdate(); //possibly Average
  moveMotor(); 
  
  

}

void sensorUpdate()
{

  return;
}

void getmodBusUpdate()
{

  return;
}

bool home()
{
  bool homed = false;

  float averageAmps = 0.0;
  float localAverage = 0.0;
  
  averageAmps = ampAverage.update(currentAMPS);
  localAverage = localAmpAverage.update(currentAMPS);

  if(true == ampAverage.full())
  {
    speed;

  }
  
  return homed;
}

void limitUpdate()
{
  return;
}
void moveMotor()
{
   return;
}










//should probably be broken out into a library



template <typename T> 
Average<T>::Average(int arraySize)
{
  size = arraySize;

  myQueue[size] = {-1.0} ;
  length = size;
}

template <typename T> 
T Average<T>::update(T number)
{
  enqueue(number);
  return queueAve();
}

template <typename T>
bool Average<T>::full()
{
  bool isFull = false;
  
  if (size<length)
    isFull = true;
  
  return isFull;
}


// Private Methods 
template <typename T>
void Average<T>::enqueue(T newNumber)
{
  myQueue[length%size] = newNumber;
  length++;
}

template <typename T>
T Average<T>::queueAve()
{
  T result = 0;
  for (int i = 0; size > i; i++)
  {
    if((-1.0) != myQueue[i])
      result += myQueue[i];
  }
  return (result/size);
}