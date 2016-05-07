//
bool xdir=0, xstep=0;
int xpos=0;
bool ydir=0, ystep=0;
int ypos=0;

const int XD = 4; //X Direction
const int XS = 5; //X Step
const int YD = 6; //Y Direction
const int YS = 7; //Y Step

void setup() {
  pinMode(XD, OUTPUT);
  pinMode(XS, OUTPUT);
  pinMode(YD, OUTPUT);
  pinMode(YS, OUTPUT);
}

void loop() {   
  for(int i=0; i<1000;i++){
    stepY(true,0);
    delay(1);
  }
  for(int i=0; i<1000;i++){
    stepY(false,0);
    delay(1);
  }
}



void homeAxes(){
  int i=0;
  while(i<100){
    stepX(false,1);
    i++;
  }
  
}

void stepX(bool dir, int spd){
  /*digitalWrite(XD, dir);
  digitalWrite(XS, 1);
  delay(2);
  digitalWrite(XS, 0);
  */
    digitalWrite(XD, dir);
    delay(5);
    digitalWrite(XS, 1);
    delay(spd);
    digitalWrite(XS, 0);
    delay(spd);
}

void stepY(bool dir, int spd){
  digitalWrite(YD, dir);
  //digitalWrite(YS, 0);
  delay(spd);
  digitalWrite(YS, 1);
  delay(spd);
  digitalWrite(YS, 0);
}

void FF7(){
  // int victory[]={1,1,1,1,3,2,1,2,1};
  // int dur[]={320,320,320,600,600,600,500,320,600};
  
 int victory[]={8,8,6,5,4,3,1,3,2,1};
  int dur[]={400,800,200,800,400,800,400,800,400,800};
   
int test1[]={};
  int dur1[]={};
  
  
  
  bool alt = false;
  for(int c=0;c<=8;c++){
   for(int d=0;d<dur[c]/2;d+=5){
     stepX(alt,victory[c]);
   }
   alt=!alt;
   }
   delay(1000);
}

void pitchTesting(){
   for(int b=0; b<15;b+=2){
   for(int i=0;i<25;i++){
     stepX(true,b);
   }
   delay(100);
   for(int j=0;j<25;j++){
     stepX(false,b+1);
   }
   delay(100);
  }

}
