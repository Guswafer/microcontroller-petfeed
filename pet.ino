#define BLYNK_TEMPLATE_ID "TMPL6ykW_pXqQ"
#define BLYNK_TEMPLATE_NAME "pet feed"
#define BLYNK_AUTH_TOKEN "5wYtQAnqUO5IEI3AYI5l0-u1fhRg0CdY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// กำหนดขาอุปกรณ์
#define LED_READY D5      // ไฟแสดงสถานะพร้อมทำงาน
#define LED_FEEDING D7    // ไฟแสดงสถานะกำลังให้อาหาร
#define SERVO_PIN D8      // ขาเซอร์โวมอเตอร์

Servo servo;

char ssid[] = "Julusgy";  // ใส่ชื่อ WiFi ของคุณ
char pass[] = "11111111"; // ใส่รหัสผ่าน WiFi ของคุณ

void setup() {
    Serial.begin(9600);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    
    pinMode(LED_READY, OUTPUT);
    pinMode(LED_FEEDING, OUTPUT);
    servo.attach(SERVO_PIN);
    
    digitalWrite(LED_READY, HIGH); // ไฟพร้อมใช้งาน
}

// ฟังก์ชันรับค่าจาก Blynk เพื่อควบคุมเซอร์โว
BLYNK_WRITE(V2) {
    int angle = param.asInt();
    feedPet(angle);
}

// ฟังก์ชันสำหรับป้อนอาหาร
void feedPet(int angle) {
    digitalWrite(LED_FEEDING, HIGH);
    servo.write(angle);
    delay(3000);
    servo.write(0); // กลับตำแหน่งเดิม
    digitalWrite(LED_FEEDING, LOW);
}

void loop() {
    Blynk.run();

}
