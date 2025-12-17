#define LS 40 
#define RS 39 
#define LD 29 
#define RD 30 
#define SLPL 11 
#define SLPR 31 
#define ULTRASONIC_TRIGGER_PIN 5 
#define ULTRASONIC_ECHO_PIN 6 
void setup() { 
  pinMode(LS, OUTPUT); 
  pinMode(RS, OUTPUT); 
  pinMode(LD, OUTPUT); 
  pinMode(RD, OUTPUT); 
  pinMode(SLPL, OUTPUT); 
  pinMode(SLPR, OUTPUT); 
  digitalWrite(SLPL, HIGH); 
  digitalWrite(SLPR, HIGH); 
  pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT); 
  pinMode(ULTRASONIC_ECHO_PIN, INPUT); 
  Serial.begin(9600); 
} 
void loop() { 
   // Trigger the ultrasound sensor 
   digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW); 
   delayMicroseconds(2); 
   digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW); 
   // Measure the response time of ultrasound sensor 
   long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH); 
   // Calculate distance in cm 
   int distance = duration * 0.034 / 2; 
   // Print distance for debugging 
   Serial.print("Distance: "); 
   Serial.print(distance); 
   Serial.println(" cm"); 
   // If an obstacle is detected within a certain range, perform obstacle avoidance 
   if (distance < 20) { 
      digitalWrite(LD, HIGH); 
      digitalWrite(RD, HIGH); 
      analogWrite(LS, 60); 
      analogWrite(RS, 60); 
      delay(1000); 
      digitalWrite(LD, LOW); 
      digitalWrite(RD, LOW); 
      analogWrite(LS, 30); 
      analogWrite(RS, 60); 
      delay(1000); 
else { 
      // If no obstacle is detected, continue moving forward 
      digitalWrite(LD, LOW); 
      digitalWrite(RD, LOW); 
      analogWrite(LS, 60); 
      analogWrite(RS, 60); 
      delay(1000); 
   } 
   }
