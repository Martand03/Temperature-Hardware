#include "TRIGGER_WIFI.h"               
#include "TRIGGER_GOOGLESHEETS.h"       

String Sheets_GAS_ID = "AKfycbxwqez2dg8Aay5CxuQKObjF1FpS9XBl7OHnUdYBF7KTwk-FIwyU7eCJWA1s1DxlF-YDyw";  
int No_of_Parameters = 1;                                          
const int lm35_pin = A0;

void setup() 
{
    Serial.begin(9600);
    while (!Serial);

    WIFI_Connect("Ani","1234567890");                                                     
    Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters);         
}

void loop() { 
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  
  temp_val = (temp_adc_val * 4.88); 
  temp_val = (temp_val/10); 
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  delay(10);
  Data_to_Sheets(No_of_Parameters,  temp_val);        
  delay(1000);
}
