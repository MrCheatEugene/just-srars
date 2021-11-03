//---------------
//CONFIGURATION
//Конфиг
//---------------

//20x4 display pins. Don't change if you're using ramps 1.4+RepRap Discount SMART(not full graphics)CONTROLLER
//Пины дисплея 20х4. Не меняйте, если вы используете ramps 1.4+RepRap Discount(не full graphics)Smart Controller
const int rs = 16, en = 17, d4 = 23, d5 = 25, d6 = 27, d7 = 29;
#define CLK 31// clock pin of encoder | clock энкодера
#define DT 33// DT энкодера | DT encoder pin
#define SW 35// кнопка энкодера | encoder switch
#define typeENC TYPE2 // тип энкодера(TYPE1: 1 шаг, TYPE2: 2 шага) | encoder type (TYPE1: one-step, TYPE2 : two-step) 
//CODe BELOW
#include <LiquidCrystal.h>
#include <GyverEncoder.h>
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  Encoder enc1(CLK, DT, SW);
  bool doPlay=false;
  bool crAchved=false;
 int px,py,x,y;
 int16_t crysts =0;//нахуй хуй его знает
 int cx = random(1,20);
 int cy = random(0,3);
  int32_t timer=0;
void setup(){
 enc1.setType(typeENC);  
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Made in MrCheat,Inc.");
  lcd.setCursor(0,1);
lcd.print("---");
delay(500);
lcd.print("JUST-");
delay(500);
lcd.print("STARS-");delay(500);
Serial.begin(9600);
lcd.print("0");
lcd.print("---");
delay(500);
lcd.setCursor(0,2);
lcd.print("v. Pre-PVT 0.1");
delay(1500);

lcd.clear();
lcd.setCursor(0,0);  
lcd.print("Hold:Start;Left=-Y");
lcd.setCursor(0,1);  
lcd.print("Right:+X;");
lcd.setCursor(0,2);  
lcd.print("H+X/Y=-X; +Y");
lcd.setCursor(0,3);  
lcd.print("CONTROLS");
  }
void loop(){

enc1.tick();  
if(doPlay==true){

  if (enc1.isRightH()) {
    if(y>0){
y=y-1;}
  }
  if (enc1.isLeftH()) {    
    if(x>0){
    x=x-1;}
  }  if (enc1.isRight()) {
    if(x<20){
 x=x+1;   }
    }
  if (enc1.isLeft()) {
    if(y<4){
 y=y+1;  }    
  }}
if(doPlay==false)  {
  crysts =0;

  if (enc1.isHold() or enc1.isPress() or enc1.isLeft()or enc1.isLeftH() or enc1.isRight() or enc1.isRightH()) {      timer=millis();
   crAchved,px,py,x,y,crysts,cx,cy=false,0,0,0,0,0,random(1,20),random(0,3);
    doPlay=true;  
     timer=millis();
    }
    
    }
if(doPlay==true){
  
  if(millis()-timer < 5000){
      lcd.setCursor(0,0);
  lcd.print(crysts);
  if(px==x and py==y){}else{
   
  lcd.clear();
  if(crAchved==false){
                cx =random(1,20);
            cy=random(0,3);
crAchved=true;
}
    }
  lcd.setCursor(x,y);
lcd.print("X");
px=x;
py=y;
if(crAchved){
  lcd.setCursor(cx,cy);
lcd.print("*");
}
if(cx == x and cy==y){
  crAchved=false;
  crysts=crysts+1;
    cx =random(0,20);
cy =random(0,4);
timer=millis();
  }
}else{
  doPlay=false;
    lcd.clear();
    lcd.setCursor(0,0);
lcd.print("Game over.");
    }
  }  
}
