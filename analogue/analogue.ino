const int led=9;
int lc=1;




void setup() {
  // put your setup code here, to run once:'

  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(lc=0;lc<=255;lc++)  //fadein
  {
  
  analogWrite(led,lc);
  delay(5); //wait 10ms
  }

  for(lc=255;lc>=0;lc--)
    {
       analogWrite(led,lc);
       delay(5);
    }
  

}
