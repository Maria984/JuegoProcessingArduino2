int btn1 = 7;
int btn2 = 8;

int ledPin = 13;

int estado = 0;
int estado2 = 0;

int sensor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);

  Serial.begin(9600); // Pasar información de arduino a otro programa / 9600v
  
}

void loop() {
  // put your main code here, to run repeatedly:
  estado = digitalRead(btn1); // Leea lo que hay en el puerto 7, guardela en estado
  estado2 = digitalRead(btn2);

  if(estado == HIGH)
  {
    digitalWrite(ledPin, HIGH); // Emitir una funcion
    sensor = 1; // Dato enviado a processing al oprimir un boton
  }
  else if(estado2 == HIGH)
  {
    digitalWrite(ledPin, HIGH); // Emitir una funcion
    sensor = 2; // Dato enviado a processing al oprimir un boton
  }
  else if(estado == LOW){
    digitalWrite(ledPin, LOW); // Emitir una funcion / Si ninguno esta oprimido el led apagado
    sensor = 0; // Dato enviado a processing al oprimir un boton    
  }
  else if(estado2 == LOW) {
    digitalWrite(ledPin, LOW);
    sensor = 3;
    }
  
  Serial.write(sensor);

  delay(100);

}
