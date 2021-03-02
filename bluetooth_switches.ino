#include <Servo.h>
#include <SoftwareSerial.h> 

int degrees = 30;
SoftwareSerial MyBlue(2, 3); // RX | TX 
int blue_received;

Servo switch1;

void setup()
{
  Serial.begin(9600); 
  MyBlue.begin(38400);  
  switch1.attach(9, 500, 2500); // signal pin of servo at switch1 is attached at pin 9

}

void loop()
{
    if(MyBlue.available()) {
        blue_received = MyBlue.read();

        switch(blue_received){
            case "s1_on" : {
                switch1_on(degrees);
                break;
            }

            case "s1_off" : {
                switch1_off(degrees);
                break;
            }
        }

    }

}

void switch1_on(int deg){
    for(int i = 0; i <= deg; i++){
        switch1.write(i);
        delay(15);
    }
}

void switch1_off(int deg){
    for(int i = deg; i >= 0; i--){
        switch1.write(i);
        delay(15);
    }
}