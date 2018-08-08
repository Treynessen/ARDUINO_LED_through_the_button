void setup() {
  pinMode(5, INPUT_PULLUP);
  pinMode(8, OUTPUT);
}

bool low_signal = true; 
bool ON = false; 
byte count_low_signal = 0;

void loop() {
  // Защита от дребезга контактов. Смена состояния сигнала, если количество низких сигналов = 100
  if (!low_signal && digitalRead(5) && count_low_signal++ >= 100) low_signal = true; 
  // Включение/выключение диода происходит в том случае, если предыдущий сигнал был низкий, что соответствует не нажатой кнопке
  if (low_signal && !digitalRead(5)) {
    low_signal = false;
    digitalWrite(8, (ON = !ON)); 
    count_low_signal = 0; 
  } 
}
