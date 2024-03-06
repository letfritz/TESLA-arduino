int pinos[9] = {12,11,10,9,8,7,6,5,3};
int pinLED;
int pinLDR = A0;

float minimo = 0;
float maximo = 1023;
float valorLDR;
float luminosidade;

void setup() {
  // put your setup code here, to run once:
  
  for(pinLED = 0; pinLED <= 8; pinLED++){
    pinMode(pinos[pinLED],OUTPUT);
  }

  pinMode(pinLDR,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  valorLDR = analogRead(pinLDR);
  luminosidade = ((valorLDR - minimo)/(maximo - minimo))*10;
  luminosidade = (luminosidade - 10) * -1;
  
  for(pinLED = 0; pinLED <= 8; pinLED++){
    if(pinLED < luminosidade){
      digitalWrite(pinos[pinLED],HIGH);
    }else{
      digitalWrite(pinos[pinLED],LOW);
    }
  }

  delay(500);

}


