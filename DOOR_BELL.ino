const int TrigPin = 2;
const int EchoPin = 3;
const int Data = 8;
float  cm;
void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
 pinMode(EchoPin, INPUT);
  pinMode(Data,OUTPUT);
}
void loop()
{
  digitalWrite(TrigPin, LOW);       
  delayMicroseconds(2);
 digitalWrite(TrigPin,  HIGH);
  delayMicroseconds(10);
 digitalWrite(TrigPin, LOW);
  cm = pulseIn(EchoPin,  HIGH) / 58.0; //The echo time is converted into cm
  cm = (int(cm * 100.0)) /  100.0;     //Keep two decimal places
  Serial.println();
  if(cm<15){ //if  you are puting the sensor behind the door use ">" sysmbole insted of ">" p.s.  make sure tat the door nob is less than 15 cm away
      digitalWrite(Data,HIGH);
        Serial.print("Door closed");
    }
    else
    {
      digitalWrite(Data,LOW);
      delay(200);  
      Serial.print("Door  open");
    }
  delay(200);
}
