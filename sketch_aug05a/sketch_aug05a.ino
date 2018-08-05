void setup() {
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  digitalWrite(8,LOW);
}

bool is_on = false;
long time = millis();

void loop() {
  if((millis()-time)>=100 && !is_on && !digitalRead(5)){
    Serial.println("ON");
    is_on = true;
    digitalWrite(8,HIGH);
    while(!digitalRead(5));
    time = millis();
  }
  else if ((millis()-time)>=100 && is_on && !digitalRead(5)){
    Serial.println("OFF");
    is_on = false;
    digitalWrite(8,LOW);
    while(!digitalRead(5));
    time = millis();
  }
}
