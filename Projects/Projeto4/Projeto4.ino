int led1Pin = 13;
int led2Pin = 12;
int buttonPin = 2;
int faseBotao;
int buttonEstado;
int buttonOldEstado;
int interval;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  pinMode(buttonPin,INPUT);
  faseBotao = 1;
  buttonOldEstado = digitalRead(buttonPin);
  interval=1000;

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonEstado = digitalRead(buttonPin);
  
  if((buttonEstado == HIGH) && (buttonOldEstado == LOW)){
    if(faseBotao == 1){
      faseBotao = faseBotao +1;
    }else{
    faseBotao = 1;
    }
  }
  buttonOldEstado = buttonEstado;

  if(faseBotao == 1){
    interval = 1000;
  }else{
    interval = 100;
  }

  digitalWrite(led1Pin,buttonEstado);
  digitalWrite(led2Pin,!buttonEstado);
  delay(interval);
  digitalWrite(led1Pin,!buttonEstado);
  digitalWrite(led2Pin,buttonEstado);
  delay(interval);

}
