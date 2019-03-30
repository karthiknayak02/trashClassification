//Credit to viral science for inspiration and technical help
//Ultrasonic Distance alarm
const int trigPin = 5;
const int echoPin = 6;
//const int buzzer = 11;
const int ledPin = 7;
const int recyPin = 13;
const int orgPin = 12;

// defines variables
long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT);
  pinMode(recyPin, OUTPUT);
  pinMode(orgPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034 / 2;

  safetyDistance = distance;
  if (safetyDistance <= 10) { //Enter the Distance
    digitalWrite(ledPin, HIGH);
    digitalWrite(recyPin, HIGH);
    digitalWrite(orgPin, HIGH);

  } else {
    ite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(recyPin, LOW);
    digitalWrite(orgPin, LOW);
  }

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
