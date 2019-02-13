int pin = 13;
char lightType[20];

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop()
{
  int lf = 10; 
  Serial.readBytesUntil(lf, lightType, 1);
  if (strcmp(lightType, "o")==0){
    on();
  }
  if (strcmp(lightType, "f")==0){
    off();
  }
}

void on()
{
  digitalWrite(pin, HIGH);
}

void off()
{
  digitalWrite(pin, LOW);
}
