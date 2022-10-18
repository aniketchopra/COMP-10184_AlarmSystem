//I, Aniket Chopra, student number 000814313, certify that this material is my original work. No other person's work has been used without due acknowledgment and I have not made my work available to anyone else.


//Completed till Stage-4

// COMP-10184 – Mohawk College 
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 
 
#include <Arduino.h> 
 
// digital input pin definitions 
#define PIN_PIR D5 
#define PIN_BUTTON D6 
 

bool sensorState = false;
int blinkDelay = 125;
int buttonDelay = 1000;
bool flag = false;
int buttonState;
// long time;
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure the LED output 
  pinMode(LED_BUILTIN, OUTPUT); 
 
  // PIR sensor is an INPUT 
  pinMode(PIN_PIR, INPUT); 
 
  // Button is an INPUT 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
} 
 
// ************************************************************* 
void loop() { 
  bool bPIR; 
  // static bool ledOn = true;
  // read PIR sensor (true = Motion detected!).  As long as there 
  // is motion, this signal will be true.  About 2.5 seconds after  
  // motion stops, the PIR signal will become false. 
  bPIR = digitalRead(PIN_PIR); 
  // long timeLedOn = millis();
  // Serial.println(timeLedOn);
  // send the PIR signal directly to the LED 
  // but invert it because true = LED off! 

  //CHeck if sensor detetct anything
  if(bPIR){
    sensorState = true;

  }

  //Check the sensor situation and check the flag
  if(sensorState && !flag){
    for(int i =0; i<40;i++){
      buttonState = digitalRead(PIN_BUTTON);    
      
      //WHenever button is clicked LEd turn off
      if(!buttonState){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(buttonDelay);
        flag =  !flag;
        Serial.println(flag);
        break;
      }
      else{
        digitalWrite(LED_BUILTIN, LOW);
        delay(blinkDelay);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(blinkDelay);
        
      }
      
    
    // delay(10000);
    }
    sensorState = !sensorState;
    flag=!flag;
    Serial.println(flag);
  }
  
  digitalWrite(LED_BUILTIN, !flag);
    
  

}

