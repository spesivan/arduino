#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

int ledPin = 7;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(ledPin, OUTPUT);
  Serial.println("RC522 Kart Okuma Hazir!");
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("UID: ");
    printUID();
    
    // Belirli bir kartın UID'sini kontrol et


    if (checkCard("card uıd")) {
      digitalWrite(ledPin, HIGH); // LED'i yak
      delay(1000);
      digitalWrite(ledPin, LOW); // LED'i söndürs
      Serial.println("Geçiş Onaylandı!");
    } else {
      digitalWrite(ledPin, LOW); // LED'i söndür
      Serial.println("Geçiş Reddedildi!");
    }
    
    delay(1000); // Bekleme süresi
  }
}

void printUID() {
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println("");
}

bool checkCard(String targetUID) {
  String currentUID = "00-11-22-33";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    currentUID += mfrc522.uid.uidByte[i] < 0x10 ? "0" : "";
    currentUID += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) {
      currentUID += "-";
    }
  }
  Serial.print("Current UID: ");
  Serial.println(currentUID);
  
  return currentUID.equals(targetUID);
}
