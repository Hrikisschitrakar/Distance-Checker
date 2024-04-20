
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance >0 && distance<=10){
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
  }
  if(distance<=20 && distance>=11){
    digitalWrite(7,HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  if(distance<=31 && distance>=21){
    digitalWrite(5,HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  }
  delay(1000);
}
