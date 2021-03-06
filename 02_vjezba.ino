int x;
float y;
int koef;
int duljinaDelay;

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(A0, LOW);
}

void loop()
{
  digitalWrite(7, HIGH);
  duljinaDelay = 1000 * provjeriKoef();
  Serial.print("Trajanje crvenog svjetla: ");
  Serial.println(duljinaDelay);
  delay(duljinaDelay);
  digitalWrite(7, LOW);
  
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  
  digitalWrite(5, HIGH);
  duljinaDelay = 5000 / provjeriKoef();
  Serial.print("Trajanje zelenog svjetla: ");
  Serial.println(duljinaDelay);
  delay(duljinaDelay);
  digitalWrite(5, LOW);
}

int provjeriKoef() {
  x = analogRead(A0);
  Serial.print(x);
  Serial.print(" -> ");
  y = ((float(x)) / 1023) * 100;
  x = y;
  Serial.print(x);
  Serial.print("% ---> koef: ");
  
  if(x <= 25) {
    koef = 1;
  } else if(x <= 50) {
    koef = 2;
  } else if(x <= 75) {
    koef = 3;
  } else {
    koef = 5;
  }
  Serial.println(koef);
  return koef;
}

























































