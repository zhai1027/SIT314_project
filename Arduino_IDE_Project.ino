
/void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  //模拟3个办公室的light使用频率
  int led_one = random(0, 2);
  int led_two = random(0, 2);
  int led_three = random(0, 2);

  //注意，这里的输出结构和Arduino Uno板有很大影响，不同板会导致javascript
  //抓取数字错误，极有可能导致抓取字符变成字母而不是数字。
  Serial.print("led_one: ");
  Serial.print(led_one);
  Serial.print("");
  delay(5000);

  Serial.print("led_two: ");
  Serial.print(led_two);
  Serial.print("");
  delay(5000);

  Serial.print("led_three: ");
  Serial.print(led_three);
  Serial.print("");
  delay(5000);


//--------------------------------------------------------------------

/*
int led_one = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  static String command = ""; // 保持指令的持久性

  while (Serial.available() > 0) {
    char receivedChar = Serial.read();
    
    if (receivedChar != '\n') {
      command += receivedChar;
    } else {
      // 处理完整的指令
      if (command == "0") {
        led_one = 0;
        Serial.print("led_one: ");
        Serial.print(led_one);
        Serial.println(" LED1 turned off");
      }
      // 清空指令以准备下一个指令
      command = "";
    }
  }

  // 模拟LED状态
  int led_one = random(0, 2);
  Serial.print("led_one: ");
  Serial.print(led_one);
  delay(5000);
}
*/

//--------------------------------------------------------------------

#include <SoftwareSerial.h>
SoftwareSerial MyBlue(0, 1);  // RX | TX
int value = 48;

//pinMode(LED_BUILTIN, OUTPUT);
//digitalWrite(LED_BUILTIN, HIGH);
//digitalWrite(LED_BUILTIN, LOW);

void setup() {
  Serial.begin(9600);
  MyBlue.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //Serial.println("Ready to connect\nDefualt password is 1234 or 000");
}
void loop() {
  if (MyBlue.available())
    value = MyBlue.read();
  if (value == 49) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED On");
    delay(3000);
  } else if (value == 48) {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED Off");
    delay(3000);
  }
}

//--------------------------------------------------------------------
/*
const int trigPin = 8;
const int echoPin = 13;
float duration, distance;
int led_one;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  //int led_one = random(0, 2);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  delay(1000);
  if(distance <= 30){
    led_one = 1;
    Serial.print("LED on: ");
    Serial.print(led_one);
    delay(2000);
  }else{
    led_one = 0;
    Serial.print("LED off: ");
    Serial.print(led_one);
    delay(2000);
  }
}
*/