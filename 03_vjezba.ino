#include<Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(24, 2, NEO_GRB - NEO_KHZ800);

int x;
float y;
int prethodnaVrijednost;

int boje[][3] = {
  {0, 255, 0},
  {255, 255, 0},
  {255, 70, 0},
  {255, 0, 0}
};

void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  digitalWrite(A1, LOW);
  prethodnaVrijednost = -100;
  pixels.begin();
}

void loop()
{
  provjeriRazinu();
  delay(10);
}

void provjeriRazinu() {
  x = analogRead(A1);
  Serial.print(x);
  Serial.print(" -> ");
  y = ((float(x)) / 1023) * 100;
  Serial.print(y);
  Serial.println("%");
  
  if(prethodnaVrijednost != x) {
    prethodnaVrijednost = x;
  	postaviled((y / 25 + 1) > 4 ? 4 : (y / 25 + 1));
  }
}

void postaviled(int razina) {
  for(int j = 0; j < razina * 2; j++) {
  	for(int i = 0; i < 3; i++) {
      int led = i * 8 + j;
      pixels.setPixelColor(led, pixels.Color(boje[j / 2][0], boje[j / 2][1], boje[j / 2][2]));
      pixels.show();
    }
  }
  for(int j = 7; j >= razina * 2; j--) {
  	for(int i = 0; i < 3; i++) {
      int led = i * 8 + j;
      pixels.setPixelColor(led, pixels.Color(0, 0, 0));
      pixels.show();
    }
  }
}








































