#include <Arduino.h>
#include <IRremote.h>

// GPIO ports
#define IR_SEND 4
#define BUTTON_PC1 34
#define BUTTON_PC2 35
#define BUTTON_PIN_BITMASK 0xc00000000 // GPIO 34 and GPIO 35

// IR codes: AIMOS AM-404CY KVM 4 port
#define USB__ADR 0x1
#define USB__PC1 0x3 
#define USB__PC2 0x0 
#define USB__PC3 0x7 
#define USB__PC4 0x4 
#define USB__TGL 0x1F

// IR codes: Caneov 4X2 Hdmi2.0 Matrix Switch Splitter 4K60Hz Switcher (HDMX402)
#define HDMI_ADR 0x80
#define HDMI_A_1 0x1  
#define HDMI_A_2 0x2  
#define HDMI_A_3 0x3  
#define HDMI_A_4 0x6  
#define HDMI_A_L 0x4  
#define HDMI_A_R 0x5  
#define HDMI_B_1 0xA  
#define HDMI_B_2 0x1B 
#define HDMI_B_3 0x1F 
#define HDMI_B_4 0xE  
#define HDMI_B_L 0xC  
#define HDMI_B_R 0xD  
#define HDMI_PWR 0x12 
#define HDMI_ARC 0x1E 

void setup() {
  Serial.begin(115200);
  IrSender.begin(); // this library on ESP32 ignores every form of providing send pin and uses GPIO4

  uint64_t GPIO_reason = esp_sleep_get_ext1_wakeup_status();
  Serial.print("GPIO that triggered the wake up: GPIO ");
  int reason = (log(GPIO_reason))/log(2);
  Serial.println(reason, 0);
  
  delay(500);

  if (reason==34) setPC1();
  else if (reason==35) setPC2();
  
  esp_sleep_enable_ext1_wakeup(BUTTON_PIN_BITMASK,ESP_EXT1_WAKEUP_ANY_HIGH);
  //esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);

  pinMode(0, OUTPUT); 
  digitalWrite(0, LOW);

  esp_deep_sleep_start();
}

void setPC1(){
  Serial.printf("PC1 (priv): USB2, HDMI3+4\n");
  delay(100);  
  IrSender.sendNEC(USB__ADR, USB__PC2, 0, false);
  delay(100);
  IrSender.sendNEC(HDMI_ADR, HDMI_A_3, 3, false);
  delay(250);
  IrSender.sendNEC(HDMI_ADR, HDMI_B_4, 3, false);
}
void setPC2(){
  Serial.printf("PC2 (corp): USB4, HDMI1+2\n");
  delay(100);  
  IrSender.sendNEC(USB__ADR, USB__PC4, 0, false);
  delay(100);
  IrSender.sendNEC(HDMI_ADR, HDMI_A_1, 3, false);
  delay(250);
  IrSender.sendNEC(HDMI_ADR, HDMI_B_2, 3, false);
}

void loop() {
  Serial.println("never reached");
  delay(1000);
}
