#include <Servo.h>

int position = 0;
int i = 0;
int j = 0;
int x = 0;

Servo myservo;

void setup ()
{
  pinMode( 8, INPUT);  // PIR input
  //pinMode( 7, OUTPUT);  // LED
  pinMode( 3, OUTPUT);
  
  myservo.attach(3, 500, 2500);
  Serial.begin(9600);
}
void loop ()
{
  x = digitalRead(8);
  
  
  Serial.println(x);
  	if (x == HIGH)
    { 
		myservo.write(360);
		Serial.println("Clockwise");
    	delay(20); // Wait for 20 millisecond(s)
 	}  
  	else
    	for (position = 179; position >= 1; position -= 1) {
    	myservo.write(position);
        }
  delay(100);
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
  
}