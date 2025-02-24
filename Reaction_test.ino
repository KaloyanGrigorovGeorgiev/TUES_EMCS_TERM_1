int a = 7;
int b = 6;
int c = 5;
int d = 11;
int e = 10;
int f = 8;
int g = 9;
int dp = 4;
int i;
int btn1 = 3, btn2 = 2, btn3 = 12;
int pts = 0, count = 0;
void clearDisplay() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}
void setup()
{

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);

}
void loop()
{
  i = random(1, 4);
  switch (i) {
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 2: digitalWrite(b, HIGH); digitalWrite(a, HIGH); digitalWrite(e, HIGH); digitalWrite(g, HIGH); digitalWrite(d, HIGH); break;
    case 3: digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(a, HIGH); digitalWrite(g, HIGH); digitalWrite(d, HIGH); break;
  }
  
  delay(1000);
 

  if(digitalRead(btn1) == HIGH || digitalRead(btn2) == HIGH || digitalRead(btn3) == HIGH) {
  
    if (i == 1 && digitalRead(btn1) == HIGH) {
      pts += 1;
    }     else  if (i == 2 && digitalRead(btn2) == HIGH) {
      pts += 1;
    }     else if (i == 3 && digitalRead(btn3) == HIGH) {
      pts += 1;
    }
    else pts -= 1;

  } else pts -= 1;

  clearDisplay();

  //   count++;
  //   if(count == 10){
  Serial.println(pts);
  //  } Could be uncommented if you want to print your score after every 10 iterations instead of 1.
 
  delay(1000);

}

