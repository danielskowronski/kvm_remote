# IR signals

## Program
```c++
#include <Arduino.h>
#include <IRremote.hpp>

int IR_RECEIVE_PIN = 15;

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, false); 
  Serial.println("IR Receiver ready");
}

void loop() {
  if (IrReceiver.decode()) {
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.resume();
  }
  delay(100);
}
```

## USB
```
PC1 Protocol=NEC Address=0x1  Command=0x3  Raw-Data=0xFC03FE01 32 bits LSB first
PC2 Protocol=NEC Address=0x1  Command=0x0  Raw-Data=0xFF00FE01 32 bits LSB first
PC3 Protocol=NEC Address=0x1  Command=0x7  Raw-Data=0xF807FE01 32 bits LSB first
PC4 Protocol=NEC Address=0x1  Command=0x4  Raw-Data=0xFB04FE01 32 bits LSB first
TGL Protocol=NEC Address=0x1  Command=0x1F Raw-Data=0xE01FFE01 32 bits LSB first
```

## HDMI
```
A_1 Protocol=NEC Address=0x80 Command=0x1  Raw-Data=0xFE017F80 32 bits LSB first
A_2 Protocol=NEC Address=0x80 Command=0x2  Raw-Data=0xFD027F80 32 bits LSB first
A_3 Protocol=NEC Address=0x80 Command=0x3  Raw-Data=0xFC037F80 32 bits LSB first
A_4 Protocol=NEC Address=0x80 Command=0x6  Raw-Data=0xF9067F80 32 bits LSB first

A_L Protocol=NEC Address=0x80 Command=0x4  Raw-Data=0xFB047F80 32 bits LSB first
A_R Protocol=NEC Address=0x80 Command=0x5  Raw-Data=0xFA057F80 32 bits LSB first

B_1 Protocol=NEC Address=0x80 Command=0xA  Raw-Data=0xF50A7F80 32 bits LSB first
B_2 Protocol=NEC Address=0x80 Command=0x1B Raw-Data=0xE41B7F80 32 bits LSB first
B_3 Protocol=NEC Address=0x80 Command=0x1F Raw-Data=0xE01F7F80 32 bits LSB first
B_4 Protocol=NEC Address=0x80 Command=0xE  Raw-Data=0xF10E7F80 32 bits LSB first

B_L Protocol=NEC Address=0x80 Command=0xC  Raw-Data=0xF30C7F80 32 bits LSB first
B_R Protocol=NEC Address=0x80 Command=0xD  Raw-Data=0xF20D7F80 32 bits LSB first

PWR Protocol=NEC Address=0x80 Command=0x12 Raw-Data=0xED127F80 32 bits LSB first
ARC Protocol=NEC Address=0x80 Command=0x1E Raw-Data=0xE11E7F80 32 bits LSB first
```