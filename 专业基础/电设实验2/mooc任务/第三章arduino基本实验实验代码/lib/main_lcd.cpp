/**
 * lcd显示实验
 * 
 */
#include <Arduino.h>
#include <LiquidCrystal.h>
// ============ 变量 ============
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// ============ 初始化 ============
void setup() {
  lcd.begin(16, 2);  // 初始化LCD，设置行列数
  Serial.begin(9600);  // 初始化串口通信，设置波特率为9600
}

void loop() {
  Serial.print("loop begin\n");
  if(Serial.available() > 0) {
    delay(100); // 等待数据完全接收
    lcd.clear(); // 清屏
    while(Serial.available() > 0) {
      char c = Serial.read(); // 读取一个字符
      lcd.write(c); // 在LCD上显示字符
    }
  }
  Serial.print("loop end\n");
  delay(2000);                          // 等待2秒
}