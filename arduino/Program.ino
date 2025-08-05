/* Project Motorcycle Alarm
   Anggota : Aditya Yusuf Rizal_15
             Ulung Whayu Jatmiko_17
             Rahmat Yuniantoro_19
             Arvin Maulana Hafidz_20
*/

const int R_C = 13;
const int R_S = 12;
const int R_B = 11;
const int SENSOR = A0;
String DataIn;
String Pass[4] = { "ulung", "adit", "rahmat", "arvin" };
String Off[3] = { "off", "Off", "OFF" };

void setup() {
  Serial.begin(9600);
  pinMode(R_C, OUTPUT);
  pinMode(R_S, OUTPUT);
  pinMode(R_B, OUTPUT);
  pinMode(SENSOR, INPUT_PULLUP);
  digitalWrite(R_C, LOW);
  digitalWrite(R_S, LOW);
  digitalWrite(R_B, LOW);
  delay(2000);
  Serial.println("WELCOME! INSERT PASSWORD PLEASE :) ");
}

void loop() {
  if (Serial.available() > 0) {
    DataIn = Serial.readString();
    DataIn.trim();

    if (DataIn == Pass[0] || DataIn == Pass[1] || DataIn == Pass[2] || DataIn == Pass[3]) {
      Pass_Benar();
    } else if (DataIn == Off[0] || DataIn == Off[1] || DataIn == Off[2]) {
      Off_Benar();
    } else {
      Pass_Salah();
    }
  }


  if (digitalRead(SENSOR) == LOW) { 
    Serial.println("MOTOR ADA YANG MENGENDARAI");
    delay(1000);
  }

  delay(10);
}

void Pass_Benar(void) {
  Serial.print("WELCOME CAPTAIN");
  delay(2000);
  Serial.print("->");
  digitalWrite(R_B, LOW);
  digitalWrite(R_B, HIGH);
  delay(100);
  digitalWrite(R_B, LOW);
  digitalWrite(R_B, HIGH);
  delay(100);
  digitalWrite(R_B, LOW);
  digitalWrite(R_C, HIGH);
  delay(1000);
  Serial.print("  ENGINE POWERING UP!");
  delay(2000);
  digitalWrite(R_S, HIGH);
  delay(2000);
  digitalWrite(R_S, LOW);
  Serial.print("->");
  delay(1000);
  Serial.print("  ENGINE ON  ");
}

void Pass_Salah(void) {
  Serial.print("X");
  Serial.print("  WRONG PASSWORD!");
  Serial.print("  X");
  delay(2000);
  delay(1000);
  Serial.print("  TRY AGAIN : ");
  digitalWrite(R_C, LOW);
  digitalWrite(R_S, LOW);
  digitalWrite(R_B, HIGH);
}

void Off_Benar(void) {
  Serial.print("  ENGINE POWERING OFF!");
  delay(2000);
  Serial.print("->");
  digitalWrite(R_B, HIGH);
  delay(250);
  digitalWrite(R_B, LOW);
  digitalWrite(R_B, HIGH);
  delay(250);
  digitalWrite(R_B, LOW);
  digitalWrite(R_B, HIGH);
  delay(250);
  digitalWrite(R_B, LOW);
  digitalWrite(R_C, LOW);
  digitalWrite(R_S, LOW);
  Serial.print("  HAVE NICE DAY CAPTAIN! ");
}

void Off_Salah(void) {
  digitalWrite(R_C, LOW);
  digitalWrite(R_S, LOW);
  digitalWrite(R_B, LOW);
}
