//Creating variables to store which day it is
int day = 0;
int daychange = 0;
//Variables to store the I/O pin on the Arduino
int clockPin = 16; 
int dataPin = 17; 
int latchPin = 15; 

//Pattern array to turn a single LED on at a time
bit pattern[7] = {
B00000001, 
B00000010, 
B00000100, 
B00001000, 
B00010000, 
B00100000, 
B01000000, 
//B10000000, Last bit is not used
};

//Setting the variables to outputs
void setup()
{
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}

//Loop segment of the code
void loop()
{

//After 24 hours the day counter moves forward and the hour and minute are reset
if (hour >= 24) 
{
	day++;
	hour = 0;
	minute = 0; // reset minutes to zero
}

//After seven days have passed the day is reset to Monday
if (day >= 7)
{
    day = 0;
}

//Changing the bit pattern sent to the Arduino
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, patterns[day]);
digitalWrite(latchPin, HIGH);  
  
//Reads the input from a push button and increases the day of the week accordingly without 
//changing the hour or minute.
daychange = digitalRead(18);  
if (daychange == LOW)
{
	day++;
	second = 0;
delay(250);
}

}