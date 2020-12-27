/*
Mert Altuntas - Robotistan
*/
int sensorpin = 4;
int R1 = 2;
int alkis = 0;
long ilkalkis = 0;
long akisarasi = 0;
boolean RoleDurumu = false;
 
void setup() {
  pinMode(sensorpin, INPUT);
  pinMode(R1, OUTPUT);
}
 
void loop() {
 
  int sensordurum = digitalRead(sensorpin);
 
  if (sensordurum == 0)
  {
    if (alkis == 0)
    {
      ilkalkis = akisarasi = millis();
      alkis++;
    }
    else if (alkis > 0 && millis()-akisarasi >= 50)
    {
      akisarasi = millis();
      alkis++;
    }
  }
  if (millis()-ilkalkis >= 400)
  {
    if (alkis == 2)
    {
      if (!RoleDurumu)
        {
          RoleDurumu = true;
          digitalWrite(R1, HIGH);
        }
        else if (RoleDurumu)
        {
          RoleDurumu = false;
          digitalWrite(R1, LOW);
        }
    }
    alkis = 0;
  }
}
