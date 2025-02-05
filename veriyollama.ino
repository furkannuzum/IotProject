#include <WiFi.h>
#include <HTTPClient.h>
// WiFi ayarları
const char* ssid = "Fürkan"; // Wi-Fi isminiz
const char* password = "1234abcd"; // Wi-Fi şifreniz

// LED pinleri
const int ledPins[] = {12, 14, 27, 26, 25}; // 5 adet LED pinleri
const int ledCount = 5;

void setup() {
  Serial.begin(115200);
  
  // LED pinlerini çıkış olarak ayarla
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  
  // WiFi'ye bağlan
  WiFi.begin(ssid, password);
  Serial.println("WiFi'ye bağlanılıyor...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
  
  Serial.println("WiFi bağlantısı başarılı!");
  Serial.println(WiFi.localIP());
}

void loop() {
  fetchDataFromServer();
  delay(5000); // 5 saniye bekleyerek sunucudan veri al
}

// Sunucudan parmak sayısını al ve LED'leri kontrol et
void fetchDataFromServer() {


  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "hhttps://vyamacli.com/iot/lab/datatofile.php?fname=grup84&sayi"; // Parma sayısını alacağınız URL
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode == 200) {
      String response = http.getString();
      int fingerCount = response.toInt(); // Yanıtı tam sayıya dönüştür
      controlLEDs(fingerCount);
    } else {
      Serial.print("HTTP İstek hatası: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
}

// Parmak sayısına göre LED kontrolü
void controlLEDs(int count) {
  Serial.print("Alınan parmak sayısı: ");
  Serial.println(count);

  // Tüm LED'leri kapat
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Gelen sayıya göre LED'leri yak
  for (int i = 0; i < count && i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

