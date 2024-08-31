/*
  Distance Variable Alarm Code

  An initial alarm at 20cm and the intensity of the alarm increases as the distancs reduces

  A Buzzer is connected at digital pin 13 and a Ultrasonic Distance Sensor HC-SR04 at pin 11(Trig) and 12(Echo).

  by Heonics

  https://github.com/Heonics/Distance_Variable_Alarm/blob/main/Dustance_Variable_Alarm.ino


Required Materials :
1 X Arduino Uno
1 X HC-SR04
1 X 5V Buzzer
1 X Breadboard(optional)

Circuit Diagram :
Arduino Digital Pin 13 -> Buzzer +ve
Arduino GND -> Buzzer -ve
Arduino 5V -> HC-SR04 +ve
Arduino GND -> HC-SR04 +ve
Arduino Digital Pin 12 -> HC-SR04 Echo
Arduino Digital Pin 11 -> HC-SR04 Trig
*/

#include <HCSR04.h>//Install this Library from Library Manager in Arduino IDE

UltraSonicDistanceSensor distanceSensor(11, 12);  // Initialize the HC-SR04 sensor that is connected to digital pins 11(Trig) and 12(Echo).

int max_val = 20; // define maximum value of the range
int min_val = 2; // define the minimum value of the range
int Buzzer = 13; // Initialize the Buzzer at digital pin 13

void setup() {
  pinMode(Buzzer, OUTPUT); // Assigning Buzzer as output
}

void loop() {

	int distance_measured = distanceSensor.measureDistanceCm();//store the distance
	
	if(distance_measured < max_val && distance_measured > min_val){ // checks if it is in range

    digitalWrite(Buzzer, HIGH);  // turn the Buzzer on
    delay(50);                      // wait for a while
    digitalWrite(Buzzer, LOW);   // turn the Buzzer off
	
		int Val = map(distance_measured, 0, 20, 0, 100); // finds out how much time to wait
    delay(Val);                      // wait according to the distance measured

  }else{
    digitalWrite(Buzzer, LOW);   // turn the Buzzer off if it is not in range
  }

}
