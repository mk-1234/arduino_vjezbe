unsigned long vrijeme = 0;
bool procesZuto = false;
bool ukljucenoZuto = false;
int korak = 0;
int preostaloVrijeme = 0;
int zadnjaProvjeraKoraka = -1;
int koraciVrijednosti[][3] = {
  {13, 10, 1000},
  {13, 9, 500},
  {13, 8, 3000},
  {13, 9, 500},
  {13, 10, 1000},
  {12, 10, 500},
  {11, 10, 3000},
  {12, 10, 500}
};

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
  vrijeme = millis();
  preostaloVrijeme = koraciVrijednosti[korak][2];
}

void loop()
{
  if (digitalRead(2) == 1) {
    if (procesZuto) {
      if (millis() - vrijeme >= 1000) {
        vrijeme = millis();
        if (ukljucenoZuto) {
          ukljucenoZuto = false;
          digitalWrite(12, LOW);
          digitalWrite(9, LOW);
      	  Serial.print(millis());
      	  Serial.println(" -- iskljuceno zuto");
        } else {
          ukljucenoZuto = true;
          digitalWrite(12, HIGH);
          digitalWrite(9, HIGH);
      	  Serial.print(millis());
      	  Serial.println(" -- ukljuceno zuto");
        }
      }
    } else {
      preostaloVrijeme = koraciVrijednosti[korak][2] - (millis() - vrijeme);
      vrijeme = millis();
      procesZuto = true;
      ukljucenoZuto = true;
      digitalWrite(koraciVrijednosti[korak][0], LOW);
      digitalWrite(koraciVrijednosti[korak][1], LOW);
      digitalWrite(12, HIGH);
      digitalWrite(9, HIGH);
      Serial.print("preostalo vrijeme -> ");
      Serial.println(preostaloVrijeme);
      Serial.print(millis());
      Serial.println(" -- ovo je pocetak, ukljuceno zuto");
    }
  } else {
    if (procesZuto) {
      vrijeme = millis();
      procesZuto = false;
      zadnjaProvjeraKoraka = -1;
      digitalWrite(12, LOW);
      digitalWrite(9, LOW);
      Serial.print(millis());
      Serial.println(" -- ovo je kraj, iskljuceno zuto");
    }
    
    if (korak != zadnjaProvjeraKoraka) {
      zadnjaProvjeraKoraka = korak;
      digitalWrite(koraciVrijednosti[korak][0], HIGH);
      digitalWrite(koraciVrijednosti[korak][1], HIGH);
    }
    if (millis() - vrijeme >= preostaloVrijeme) {
      vrijeme = millis();
      digitalWrite(koraciVrijednosti[korak][0], LOW);
      digitalWrite(koraciVrijednosti[korak][1], LOW);
      korak = (korak + 1) % 8;
      preostaloVrijeme = koraciVrijednosti[korak][2];
      Serial.print(millis());
      Serial.println(" -- iskljucenje ledica");
    }
  }
}