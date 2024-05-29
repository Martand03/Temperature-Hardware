#include "TRIGGER_WIFI.h"               
#include "TRIGGER_GOOGLESHEETS.h"       

String Sheets_GAS_ID = "AKfycbzm8XbSmxgvSs1JKH5TwMUOAsv4RCLlfak_EAH5IJXhOZ6KL5yi1w9hXcbIyD2jkYP2Gg";  
int No_of_Parameters = 1;                                          
const int pulsePin = A0;

const int minValue = 0;      // Minimum analog value (calibration)
const int maxValue = 1023;   // Maximum analog value (calibration)
const int minBPM = 30;       // Minimum BPM (calibration)
const int maxBPM = 220; 
 
float analogToBPM(int analogValue) {
  // Map the analog value to BPM within the defined range
  return map(analogValue, minValue, maxValue, minBPM, maxBPM);
}


void setup() 
{
    Serial.begin(9600);
    while (!Serial);
    WIFI_Connect("Manik","martand003");                                                     
    Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters);         
}

void loop() { 
  
  int sensorValue = analogRead(pulsePin);
  
  // Convert the analog value to BPM
  float myBPM = analogToBPM(sensorValue);
  
  // Print the BPM value
  Serial.print("BPM: ");
  Serial.println(myBPM);
  Data_to_Sheets(No_of_Parameters,  myBPM);        
  delay(1000);
}
