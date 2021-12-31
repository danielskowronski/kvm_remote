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
  print_wakeup_reason();
  uint64_t GPIO_reason = esp_sleep_get_ext1_wakeup_status();
  Serial.print("GPIO that triggered the wake up: GPIO ");
  Serial.println((log(GPIO_reason))/log(2), 0);
  delay(500);
  esp_sleep_enable_ext1_wakeup(BUTTON_PIN_BITMASK,ESP_EXT1_WAKEUP_ANY_HIGH);
  //esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);

  esp_deep_sleep_start();
}
void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}
void setPC1(){
  IrSender.sendNEC(USB__ADR, USB__PC1, 0, false);
  IrSender.sendNEC(0x80, HDMI_A_3, 0, false);
  delay(500);
  IrSender.sendNEC(HDMI_ADR, HDMI_B_4, 0, false);
}
void setPC2(){
  IrSender.sendNEC(USB__ADR, USB__PC2, 0, false);
  IrSender.sendNEC(HDMI_ADR, HDMI_A_1, 3, false);
  delay(500);
  IrSender.sendNEC(HDMI_ADR, HDMI_B_2, 3, false);
}

void loop() {
  Serial.println("never reached");
  delay(1000);
}
