#include <SD.h>
#include <SPI.h>
#include <TFT.h> 
#include <EEPROM.h>
#include <EncButton.h>
#include "PinChangeInterrupt.h"

#define SleepTime 90000     
#define MainSensorPin A0
#define SlaveSensorPin A1
#define Fan_pin 8         
#define But_pin 4           
#define Laser_pin 6  
#define SD_CS_pin 10
#define CS 7                       
#define CStwo 5           
#define DC 9              
#define TimeGoal 1800       
//#define Debug
//#define Plotter
//#define LoopTime

extern const uint8_t logo[];
boolean PrintAccept;
boolean ChengeScoreMode;     
boolean CanSleep = true;                    
boolean Game;       
volatile boolean FlagGolA;
volatile boolean FlagGolB;
          
unsigned long GolTimer; 
unsigned long Timer;             
#ifdef LoopTime
  unsigned long LoopTimer;           
#endif

byte Win = EEPROM.read(1);      
byte PlayerA;                  
byte PlayerB;                   
byte ScrollPix;                  
char printoutA[4];                
char printoutB[4];               

TFT mainScr = TFT(CS, DC, 0);
TFT slaveScr = TFT(CStwo,DC,0);
EncButton<EB_TICK, But_pin> powBtn;

PImage Image1, Image2;

struct Vector3{
  Set(int X, int Y, int Z){
    x = X;
    y = Y;
    z = Z;
  }
  int x, y, z;
};

void setup(){ 
  #ifdef Debug || Plotter || LoopTime
    Serial.begin(9600); 
  #endif
  pinMode(But_pin, INPUT_PULLUP);
  pinMode(Fan_pin, OUTPUT);
  pinMode(Laser_pin, OUTPUT);
  pinMode(CStwo, OUTPUT);
  SD.begin(SD_CS_pin);
  mainScr.begin();
  slaveScr.begin();
  mainScr.AddDisp(CStwo);
  mainScr.background(0,0,0);
  slaveScr.background(0,0,0);
//  mainScr.drawInvBitmap(0, 0, logo, 160, 128, 1024);
//  slaveScr.drawInvBitmap(0, 0, logo, 160, 128, 1024);
  Image1 = mainScr.loadImage("idle.bmp");
  mainScr.doubleImage(Image1, 0, 0);
  Image1.close();
}                                           
                                               
void loop(){ 
  #ifdef LoopTime
    Serial.println(micros() - LoopTimer);
    LoopTimer = micros();
  #endif

  #ifdef Debug
    if (FlagGolA) {
      Serial.println("SensA");
      GolTimer = millis();
      FlagGolA = false;
    }
    if (FlagGolB) {
      Serial.println("SensB");
      GolTimer = millis();
      FlagGolB = false;
    }
  #else
    if (FlagGolA) PlayerA_Gol();
    if (FlagGolB) PlayerB_Gol();
  #endif
  
  powBtn.tick();
  
  if (powBtn.click()) {                   
    if (ChengeScoreMode){
      Win++;
      if (Win > 9) Win = 1;
      Serial.println(Win);
      EEPROM.write(1, Win);
      MaxScoreUpdate();
    } else {
      GameManager();
      if (Game)
        Start_game();
      else
        Stop_game();
    }
    Timer = millis();
    CanSleep = 1;
  }

  if (!Game){
    if (powBtn.held()) {  //Удержание кнопки
      if(ChengeScoreMode){
        IdleScreen();
      } else {
        ChangeMaxScore();
      }
      ChengeScoreMode = !ChengeScoreMode;
      Timer=millis();
      CanSleep = 1;
    }
    if(CanSleep && millis() - Timer >= SleepTime) Sleep();
  }
random(256);
random(100);
}                                             
