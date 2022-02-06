bool firstLoop = true;

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if (firstLoop) {
    // 1. korak prvi loop
    checkSwitch(0, 0); // provjera polozaja prekidaca
    digitalWrite(13, HIGH);
  	digitalWrite(10, HIGH);
  	delay(1000);
    firstLoop = false;
  } else {
    // 1. korak ako nije prvi loop
    digitalWrite(13, HIGH);
    delay(1000);
  }
  
  checkSwitch(13, 10);
  
  // 2. korak
  digitalWrite(9, HIGH);
  delay(500);
  
  checkSwitch(13, 9);
  
  // 3. korak
  digitalWrite(8, HIGH);
  delay(3000);
  
  checkSwitch(13, 8);
  
  // 4. korak
  digitalWrite(9, HIGH);
  delay(500);
  
  checkSwitch(13, 9);
  
  // 5. korak
  digitalWrite(10, HIGH);
  delay(1000);
  
  checkSwitch(10, 13);
  
  // 6. korak
  digitalWrite(12, HIGH);
  delay(500);
  
  checkSwitch(10, 12);
  
  // 7. korak
  digitalWrite(11, HIGH);
  delay(3000);
  
  checkSwitch(10, 11);
  
  // 8. korak
  digitalWrite(12, HIGH);
  delay(500);
  
  checkSwitch(10, 12);
}

void checkSwitch(int ostavitiUklj, int iskljuciti) {
  if (iskljuciti) {
    digitalWrite(iskljuciti, LOW);
  }
  if (digitalRead(2) == 1) {
    if (ostavitiUklj) {
      digitalWrite(ostavitiUklj, LOW);
  	}
    Serial.println("pocinje treptece zuto svjetlo!");
    while(digitalRead(2) == 1) {
      digitalWrite(12, HIGH);
      digitalWrite(9, HIGH);
      delay(1000);
      digitalWrite(12, LOW);
      digitalWrite(9, LOW);
      delay(1000);
    }
    if (ostavitiUklj) {
      digitalWrite(ostavitiUklj, HIGH);
    }
  }
}




























































































