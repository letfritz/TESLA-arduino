int led1Pin=12;
int led2Pin=13;
int buttonEstado=0;

void setup() {
  // put your setup code here, to run once:

  pinMode(led1Pin,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonEstado=digitalRead(buttonPin);

  digitalWrite(led1Pin,buttonEstado);
  digitalWrite(led2Pin,!buttonEstado);
  
}
