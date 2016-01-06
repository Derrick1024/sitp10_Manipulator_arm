#define D_PIN1 3
#define D_PIN2 6
#define A_PIN1 A0

int readvalue1 = 0;
int readvalue2 = 0;
int outvalue1 = 0;
int threshold = 8;
int state = 0;
int diff = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D_PIN1, OUTPUT);
  pinMode(D_PIN2, OUTPUT);
  analogWrite(D_PIN1, 0);
  analogWrite(D_PIN2, 0);
  readvalue1 = analogRead(A_PIN1);
}

void loop() {
  // put your main code here, to run repeatedly:
  //readvalue1 = analogRead(A_PIN1);
  readvalue2 = analogRead(A_PIN1);
  diff = readvalue2 - readvalue1;

  if (diff < (-threshold))
  {
    outvalue1 = map(diff, 50, 500, 150, 255);
    analogWrite(D_PIN1, 0);
    analogWrite(D_PIN2, outvalue1);
    delay(100);
    readvalue1 = readvalue2;
    analogWrite(D_PIN2, 0);
    state = 1;
  }
  if (diff > threshold)
  {
    outvalue1 = map(diff, 50, 500, 150, 255);
    analogWrite(D_PIN1, outvalue1);
    analogWrite(D_PIN2, 0);
    delay(100);
    readvalue1 = readvalue2;
    analogWrite(D_PIN1, 0);
    state = 1;
  }
  //  Serial.print("readvalue2= ");
  //  Serial.print(readvalue2);
  //  Serial.print("\n");
  //  Serial.print("outvalue2= ");
  //  Serial.print(outvalue1);
  //  Serial.print("\n");
  //
  delay(50);
  //analogWrite(D_PIN1, outvalue1);


}
