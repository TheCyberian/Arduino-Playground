const int trigger = 4;
const int echo = 5;

long time_taken;
int dist, distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop() {
   cal_dist(trigger, echo);
   distance = dist;   

  /* if(distance > 45 && distance < 50){
    Serial.println("Play/Pause");
   }*/

   if(distance >=13 && distance <= 17){
    delay(100);
    cal_dist(trigger, echo);
    distance = dist;
    if(distance >= 13 && distance <= 17){
//     Serial.println("Locked");
     while(distance <= 40){
      cal_dist(trigger, echo);
      distance = dist;
      if(distance < 20){
        Serial.println("Vdown");
        delay(300);
      }
      if(distance > 20){
        Serial.println("Vup");
        delay(300);
      }
     }
    }
   }
} 


void cal_dist(int trigger, int echo){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  time_taken = pulseIn(echo, HIGH);
  dist = time_taken*0.034/2;
//  Serial.println(dist);
  if(dist > 50){
    dist=50;
  }
}
