// Tanımlamalar
const int trigPin = 2;  // HC-SR04 Trigger pin
const int echoPin = 3;  // HC-SR04 Echo pin
const int ledPin = 7;   // LED pin
const int buzzerPin = 8; // Buzzer pin

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Mesafe ölçümü için sensörü tetikle
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo süresini ölç
  long duration = pulseIn(echoPin, HIGH);

  // Mesafeyi cm cinsinden hesapla
  int distance = duration * 0.034 / 2;

  // Mesafeyi seri monitöre yazdır
  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Mesafe 20 cm'den kısa ise LED ve Buzzer'i aktifleştir
  if (distance < 20) {
    digitalWrite(ledPin, HIGH);

    // Buzzer sesini mesafe ile orantılı olarak arttır
    int buzzerVolume = map(distance, 0, 20, 100, 1000);
    tone(buzzerPin, buzzerVolume);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin); // Buzzer'i kapat
  }

  delay(1000);  // 1 saniye bekle
}
