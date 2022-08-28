#include "motorCtrl.h"
#include "Arduino.h"

int MotorCtrl::inst_num = 0;

MotorCtrl::MotorCtrl(int I1, int I2) {
  IN1 = inst_num;
  IN2 = inst_num + 1;
  ledcSetup(IN1, 12800, 8);
  ledcSetup(IN2, 12800, 8);
  Serial.begin(9600);
  ledcAttachPin(I1, IN1);
  ledcAttachPin(I2, IN2);
  inst_num += 2;
}

void MotorCtrl::move(int speed) {
  if (speed > 0) {
    ledcWrite(IN1, speed);
    ledcWrite(IN2, 0);
  } else if (speed < 0) {
    ledcWrite(IN1, 0);
    ledcWrite(IN2, speed);
  } else {
    ledcWrite(IN1, 255);
    ledcWrite(IN2, 255);
    delay(100);
  }
  Serial.print(IN1);
  Serial.println(IN2);
}

void MotorCtrl::brake(int time) {
  ledcWrite(IN1, 255);
  ledcWrite(IN2, 255);
  delay(time);
}
