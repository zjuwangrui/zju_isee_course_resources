/**
 * Arduino环境搭建验证
 * 
 */
#include <Arduino.h>

// ============ 变量 ============
#define LED_PIN 1

// ============ 初始化 ============
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, LOW);   // 点亮LED，注意低电平点亮。
  delay(1000);                  // 等待1秒
}

  