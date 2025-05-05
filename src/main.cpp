#include <TinyGPS.h>

TinyGPS gps;
HardwareSerial GPS_Serial(1);  // UART1 (RX=16, TX=17)

void setup() {
  Serial.begin(115200);
  GPS_Serial.begin(9600, SERIAL_8N1, 16, 17);
  
  // Configuração para módulos u-blox
  GPS_Serial.println("$PUBX,41,1,0007,0003,9600,0*10");  // Configura baud rate
  delay(500);
  
  Serial.println("Sistema GPS com TinyGPS");
  Serial.println("Aguardando dados dos satélites...");
  Serial.println("--------------------------------");
}

void loop() {
  bool newData = false;
  
  // Processa dados por 1 segundo
  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (GPS_Serial.available()) {
      char c = GPS_Serial.read();
      if (gps.encode(c)) {  // Dados NMEA válidos decodificados
        newData = true;
      }
    }
  }

  if (newData) {
    float flat, flon;
    unsigned long age;
    
    // Obtém posição
    gps.f_get_position(&flat, &flon, &age);
    
    Serial.print("Latitude: ");
    if (age == TinyGPS::GPS_INVALID_AGE) {
      Serial.print("INVALIDA");
    } else {
      Serial.print(flat, 6);
    }
    
    Serial.print(" | Longitude: ");
    if (age == TinyGPS::GPS_INVALID_AGE) {
      Serial.print("INVALIDA");
    } else {
      Serial.print(flon, 6);
    }
    
    // Data e Hora
    int year;
    byte month, day, hour, minute, second, hundredths;
    gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
    
    Serial.print("\nData: ");
    if (age == TinyGPS::GPS_INVALID_AGE) {
      Serial.print("INVALIDA");
    } else {
      Serial.print(day); Serial.print("/");
      Serial.print(month); Serial.print("/");
      Serial.print(year);
    }
    
    Serial.print(" | Hora: ");
    if (age == TinyGPS::GPS_INVALID_AGE) {
      Serial.print("INVALIDA");
    } else {
      Serial.print(hour-3); Serial.print(":");
      Serial.print(minute); Serial.print(":");
      Serial.print(second);
    }
    
    // Satélites e precisão
    Serial.print("\nSatélites: ");
    Serial.print(gps.satellites());
    Serial.print(" | Precisão: ");
    Serial.print(gps.hdop());
    Serial.println(" HDOP\n------------------");
  } else {
    Serial.println("Aguardando sinal GPS...");
  }
}