// Please support Youtube Channel ADSP
// https://www.youtube.com/channel/UCaFqpdENcVNK2Zn4qY-vOzQ
// VIDEO TUTOR: https://youtu.be/_EWHDUknL_w
// GITHUB: https://github.com/adsp17/Cara-Pakai-LN298N
#define in1  6
#define in2  7
#define enA  5

int pwmValue = 200; // default speed (0-255)

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  analogWrite(enA, pwmValue);

  Serial.begin(9600);
  Serial.println("Ketik 'maju' atau 'mundur', atau angka (0-255) untuk ubah PWM");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.equalsIgnoreCase("maju")) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, pwmValue);
      Serial.println("Motor maju");
    }
    else if (input.equalsIgnoreCase("mundur")) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, pwmValue);
      Serial.println("Motor mundur");
    }
    else if (input.toInt() > 0 || input == "0") {
      pwmValue = input.toInt();
      if (pwmValue > 255) pwmValue = 255;
      analogWrite(enA, pwmValue);
      Serial.print("PWM diubah ke: ");
      Serial.println(pwmValue);
    }
    else {
      Serial.println("Perintah tidak dikenali!");
    }
  }
}
