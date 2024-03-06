int pinVermelho = 13;
int pinAmarelo = 12;
int pinVerde = 11;
int pinPedestreVermelho = 9;
int pinPedestreVerde = 8;
int pinBotao = 2;
int faseSemaforo;
int estadoBotao;
int estadoAnteriorBotao;
int tempoPisca;
int estadoPisca;

void setup() {
  // put your setup code here, to run once:

  pinMode(pinVermelho,OUTPUT);
  pinMode(pinAmarelo,OUTPUT);
  pinMode(pinVerde,OUTPUT);
  pinMode(pinBotao,INPUT);

  faseSemaforo = 1;
  estadoAnteriorBotao = digitalRead(pinBotao);
  tempoPisca = 0;
  estadoPisca = HIGH;

}

void loop() {
  // put your main code here, to run repeatedly:

  estadoBotao = digitalRead(pinBotao);

  if((estadoBotao == HIGH) && (estadoAnteriorBotao == LOW)){
    if (faseSemaforo < 4){
      faseSemaforo = faseSemaforo + 1;  
    }else{
      faseSemaforo = 1;
    }
  }
  estadoAnteriorBotao = estadoBotao;

  if (faseSemaforo == 1){
    digitalWrite(pinVerde,HIGH);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,LOW);
    digitalWrite(pinPedestreVermelho,HIGH);
    digitalWrite(pinPedestreVerde,LOW);
  }

  if(faseSemaforo == 2){
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,HIGH);
    digitalWrite(pinVermelho,LOW);
    digitalWrite(pinPedestreVermelho,HIGH);
    digitalWrite(pinPedestreVerde,LOW);
  }

  if(faseSemaforo == 3){
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,HIGH);
    digitalWrite(pinPedestreVermelho,LOW);
    digitalWrite(pinPedestreVerde,HIGH);
  }

  if(faseSemaforo == 4){
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,HIGH);
    
    tempoPisca = tempoPisca + 1;
    if (tempoPisca == 400){
      estadoPisca = !estadoPisca;
      tempoPisca = 0;
    }
    
    digitalWrite(pinPedestreVermelho,estadoPisca);
    digitalWrite(pinPedestreVerde,LOW);
  }

  delay(1);

}




