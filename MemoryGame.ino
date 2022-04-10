const byte LEDNums=4;
const int LEDPins[LEDNums]={9,2,3,4};
const int ButtonPins[LEDNums]={5,6,7,8};
int LED_array[8];
int personinput[8];
int level=1;
int Tone[4];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
randomSeed(analogRead(0));
for(int i=0;i<LEDNums;i++){
  pinMode(LEDPins[i],OUTPUT);
  pinMode(ButtonPins[i],INPUT_PULLUP);
}
for(int i=0;i<8;i++){
LED_array[i]=0;
personinput[i]=0;
}
for(int i=0;i<4;i++){
  Tone[i]=1;
}
}

void loop() {
  // put your main code here, to run repeatedly:
  int needContinue=0;
  int needBreak=0;
  while(level<9){
  for(int i=0;i<level;i++){
  LED_array[i]=random(1,5);
  Serial.println(LED_array[i]);
    }
    Serial.println("--------------");
    for(int i=0;i<level;i++){
      LED_on(LED_array[i]);
    }
  bool isSucces=false;
  while(isSucces!=true){
    for(int i=0;i<level;i++){
      while(personinput[i]==0){
        //Serial.println(level);
        //Serial.println(".");
        //Serial.println(i);
        button_to_number(i);
        }
    }
    for(int i=0;i<level;){
    if(personinput[i]!=LED_array[i]){
      Serial.print("person:");
        Serial.println(personinput[i]);
        Serial.print("array:");
           Serial.println(LED_array[i]);
      SuccesLED();
    for(int j=0;j<8;j++)
    personinput[j]=0;
    needBreak=1;
    break;
    }
    else {i++;
    if(i==level){
      if(level<8){
        SuccesLED();
        SuccesLED();
        SuccesLED();
      level++;
      needBreak=1;
      for(int j=0;j<8;j++)
    personinput[j]=0;
      break;
      }
      else
      {
        level++;
        isSucces=true;
      needBreak=1;
      break;
      }
    }
    }
  }
  if(needContinue==1){
    continue;
  }
  if(needBreak==1){
    break;
  }
  }
 
  }
}
void LED_on(int a){
    digitalWrite(LEDPins[a-1],1);
    delay(500);
    digitalWrite(LEDPins[a-1],0);  
    delay(500); 
}
void button_to_number(int a){
  Tone[0]=digitalRead(5);
  Tone[1]=digitalRead(6);
  Tone[2]=digitalRead(7);
  Tone[3]=digitalRead(8);
  if(Tone[0]==0){
   digitalWrite(9,1);
   delay(500);
    digitalWrite(9,0);
    delay(500);
  personinput[a]=1;
  Tone[0]=1;
  }
  else if(Tone[1]==0){
    digitalWrite(2,1);
    delay(500);
    digitalWrite(2,0); 
    delay(500);
  personinput[a]=2;
  Tone[1]=1;
  }
  else if(Tone[2]==0){
    digitalWrite(3,1);
    delay(500);
    digitalWrite(3,0);  
    delay(500);
  personinput[a]=3;
  Tone[2]=1;
  }
  else if(Tone[3]==0){
    digitalWrite(4,1);
    delay(500);
    digitalWrite(4,0);  
    delay(500);
  personinput[a]=4;
  Tone[3]=1;
  }
}
void SuccesLED(){
digitalWrite(9,1);
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,1);
      delay(500);
      digitalWrite(9,0);
      digitalWrite(2,0);
      digitalWrite(3,0);
      digitalWrite(4,0);
      delay(500);

}
