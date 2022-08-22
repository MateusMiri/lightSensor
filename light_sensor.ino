const int piezo = A2;
const int poten = A1;
const int led = 11;
const int ledInd = 2;
const int sensor = A5;
int luminosidade = 0;
int valorPot = 0;

void setup()
{
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(ledInd, OUTPUT);
  pinMode(poten, INPUT);
  pinMode(piezo, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  
  luminosidade = analogRead(A5);
  
   if (luminosidade > 150){
    digitalWrite(ledInd, HIGH);
    tone(piezo, 1000);
  } else {
    digitalWrite(ledInd, LOW);
    noTone(piezo);
  }
  valorPot =  map(analogRead(poten), 0, 1023, 0, 255);
  analogWrite(led, valorPot);

  Serial.println(luminosidade);
}
