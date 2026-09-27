/**
 * lm35温度传感器实验
 * 
 */
#include <Arduino.h>

// ============ 变量 ============
#define SENSOR A0

// ============ 初始化 ============
void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);  // 初始化串口通信，设置波特率为9600
}

void loop() {
  Serial.print("loop begin\n");
  int sensorValue = analogRead(SENSOR);  // 读取传感器值
  delay(1000);                          // 等待1秒
  float voltage = sensorValue /204.6;  // 将传感器值转换为电压
  float temp = voltage /0.01;         // 假设电压与温度成正比，转换为摄氏度
  float tempF = temp * 1.8 + 32.0; // 将摄氏度转换为华氏度
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" \tVoltage: ");
  Serial.println(voltage);
  Serial.print(" \tTemperature: ");
  Serial.println(temp);
  Serial.print(" \tTemperature (F): ");
  Serial.println(tempF);
  Serial.print("loop end\n");
  delay(2000);                          // 等待2秒
}

  