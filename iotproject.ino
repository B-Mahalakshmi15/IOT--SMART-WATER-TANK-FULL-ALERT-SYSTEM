void setup() {
  Serial.begin(9600);      
  pinMode(4, OUTPUT); // LED
  pinMode(5, OUTPUT); // Buzzer
}

void loop() {
  int value = analogRead(A3); 
  Serial.print("Value : ");
  Serial.println(value);

  if (value < 300) {
    digitalWrite(4, HIGH); // LED ON
    Serial.println("Heavy rain - LED ON, Buzzer Beeping");

    // Buzzer beeps ON and OFF every 200ms
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(5, LOW);
    delay(200);

  } else {
    digitalWrite(4, LOW); // LED OFF
    digitalWrite(5, LOW); // Buzzer OFF
  }
}