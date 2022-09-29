void GolA(){
  if (millis() - TimeGoal > GolTimer) FlagGolA = true; 
}
void GolB(){
  if (millis() - TimeGoal > GolTimer) FlagGolB = true;
}

void GameManager(){
  if (Game){
    #ifdef Debug
      Serial.println("Game stop");
    #endif
    detachPinChangeInterrupt(digitalPinToPCINT(MainSensorPin));
    detachPinChangeInterrupt(digitalPinToPCINT(SlaveSensorPin));
    FlagGolA = false;
    FlagGolB = false;
    digitalWrite(Fan_pin, LOW);
    digitalWrite(Laser_pin, LOW);
    Game = 0;
    Timer=millis();
    CanSleep = 1;
  } else {  
    #ifdef Debug
      Serial.println("Game start");
    #endif
    digitalWrite(Fan_pin, HIGH);
    digitalWrite(Laser_pin, HIGH);
    delay(200);
    attachPCINT(digitalPinToPCINT(MainSensorPin), GolB, FALLING);
    attachPCINT(digitalPinToPCINT(SlaveSensorPin), GolA, FALLING);
    FlagGolA = false;
    FlagGolB = false;
    Game = 1;
    PlayerA = 0;
    PlayerB = 0;
    CanSleep = 0;
  }
}

void PlayerA_Gol(){
  GolTimer = millis();
  FlagGolA = false;
  if(Game){
     PlayerB++;
     if(PlayerB == Win){
      GameManager();
      WinA();     
      Stop_game();
     } else {
       AnimGolA();
       UpdateScore();
     }
  }  
}

void PlayerB_Gol(){
  GolTimer = millis();
  FlagGolB = false;
  if(Game){
     PlayerA++;
     if(PlayerA == Win){
      GameManager();
      WinB();
      Stop_game();
     } else {
      AnimGolB();
      UpdateScore();
     }
  }  
}
