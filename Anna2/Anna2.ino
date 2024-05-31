#include "TRIGGER_WIFI.h"               
#include "TRIGGER_GOOGLESHEETS.h"       

String Sheets_GAS_ID = "AKfycbzq9McaSwh88hUabCc476bWErdRKY4TPDibaihK3cSaz3BBw_d5eV-HjQiQJ9NKhE8w";  
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
    WIFI_Connect("Ani","1234567890");                                                     
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
