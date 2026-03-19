// C++ code
//
int ldrPin = A0;
int pirPin = 2;
int ledPin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);   // 0–1023
  int motion = digitalRead(pirPin);      // 0 or 1

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print("  Motion: ");
  Serial.println(motion);

  // NIGHT condition (adjust threshold if needed)
  if (lightValue < 500) {
    
    if (motion == HIGH) {
      analogWrite(ledPin, 255);   // Bright
    } else {
      analogWrite(ledPin, 80);    // Dim
    }

  } else {
    digitalWrite(ledPin, LOW);    // Day → OFF
  }

  delay(200);
}
