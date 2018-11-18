#define LED 13
#define ADC_INPUT A0
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(ADC_INPUT, INPUT); //Pin 14 = A0 used for Voltage Input
  analogReadResolution(16); //set resolution to 13 bits usable
  analogReference(EXTERNAL);
}

void loop() {

  int DAC_ValueBits = 0;
  float ADC_Measurement = 0.0;
  float ValueInVolts = 0.0;

  // put your main code here, to run repeatedly:

  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);

  ADC_Measurement = analogRead(ADC_INPUT); // read the value from the AD0 Pin
  ValueInVolts = (ADC_Measurement * (3.3/65535)); // BitsRead * (VmeasMax/BitsMax) 16 bits = FFFF 65535 and Vmax = external Vref = 2.5V
  Serial.print ("Measure and Display Value in Bits = "); 
  Serial.println (ADC_Measurement); 
  Serial.print ("Measure and Display Value in Volts = "); 
  Serial.println (ValueInVolts); 
}
