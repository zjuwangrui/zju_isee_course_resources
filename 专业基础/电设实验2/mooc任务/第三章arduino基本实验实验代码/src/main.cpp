/**
 * 继电器实验
 * 
 */
#include <Arduino.h>
// ============ 变量 ============
#define RELAY_PIN 2

// ============ 初始化 ============
void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);  // 初始化串口通信，设置波特率为9600
}

void loop() {
  Serial.print("loop begin\n");
  digitalWrite(RELAY_PIN, HIGH); // 打开继电器
  delay(1000); // 等待1秒
  digitalWrite(RELAY_PIN, LOW); // 关闭继电器
  Serial.print("loop end\n");
  delay(2000);                          // 等待2秒
}