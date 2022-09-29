
void Start_game(){
  slaveScr.fill(random(100),random(100),random(100));
  slaveScr.stroke(random(256),random(256),random(256));
  mainScr.setTextSize(4);
  slaveScr.setTextSize(4);
  mainScr.stroke(255,0,0);  
  slaveScr.stroke(255,0,0); 
  mainScr.text("Game", 30,25); 
  mainScr.text("start", 25,65);
  slaveScr.text("Game", 30,25); 
  slaveScr.text("start", 25,65);
  delay(80);
  mainScr.stroke(0,255,0); 
  slaveScr.stroke(0,255,0); 
  mainScr.text("Game", 30,25); 
  mainScr.text("start", 25,65);
  slaveScr.text("Game", 30,25); 
  slaveScr.text("start", 25,65);
  delay(80);
  mainScr.stroke(0,0,255); 
  slaveScr.stroke(0,0,255); 
  mainScr.text("Game", 30,25); 
  mainScr.text("start", 25,65);
  slaveScr.text("Game", 30,25); 
  slaveScr.text("start", 25,65);
  delay(80);
  mainScr.stroke(255,255,0); 
  slaveScr.stroke(255,255,0); 
  mainScr.text("Game", 30,25); 
  mainScr.text("start", 25,65);
  slaveScr.text("Game", 30,25); 
  slaveScr.text("start", 25,65);
  delay(80);
  mainScr.stroke(255,0,255); 
  slaveScr.stroke(255,0,255); 
  mainScr.text("Game", 30,25); 
  mainScr.text("start", 25,65);
  slaveScr.text("Game", 30,25); 
  slaveScr.text("start", 25,65);
  delay(80);
  mainScr.stroke(0,255,255);
  slaveScr.stroke(0,255,255);  
  mainScr.text("Game", 30,25); 
  mainScr.text("start", 25,65);
  slaveScr.text("Game", 30,25); 
  slaveScr.text("start", 25,65);
  delay(80);   
  PrintScore();
 }
 
void PrintScore(){
  mainScr.noStroke();
  mainScr.fill(32,18,0);
  slaveScr.noStroke();
  slaveScr.fill(20,1,45);
  mainScr.rect(0,0,160,128); 
  slaveScr.rect(0,0,160,128); 
  Image1 = mainScr.loadImage("game.bmp");
  Image2 = mainScr.loadImage("redGame.bmp");
  mainScr.image(Image1, 50, 24);
  slaveScr.image(Image2, 49, 23);
  Image1.close();
  Image2.close();
  mainScr.noFill();
  slaveScr.noFill();
  mainScr.setTextSize(8);
  slaveScr.setTextSize(8);
  mainScr.stroke(random(160),random(160),random(160));
  slaveScr.stroke(random(160),random(160),random(160));
  mainScr.rect(0,0,160,128); 
  slaveScr.rect(0,0,160,128); 
  UpdateScore();  
}

void UpdateScore(){
  String PlayerA_char = String(PlayerA);
  String PlayerB_char = String(PlayerB);
  PlayerA_char.toCharArray(printoutA,4);
  PlayerB_char.toCharArray(printoutB,4);
  mainScr.noStroke();
  slaveScr.noStroke();
  slaveScr.fill(20,1,45);
  slaveScr.rect(3, 28, 45, 73);
  slaveScr.rect(111, 28, 45, 73);
  mainScr.fill(32,18,0);
  mainScr.rect(3, 28, 45, 73);
  mainScr.rect(111, 28, 45, 73);
  slaveScr.stroke(220, 124, 164);
  mainScr.stroke(145, 201, 130);
  mainScr.text(printoutB, 7, 38);
  mainScr.text(printoutA, 112, 38);  
  slaveScr.text(printoutA, 7, 38);
  slaveScr.text(printoutB, 112, 38); 
}

void Sleep(){
  Image1 = mainScr.loadImage("sleep1.bmp");
  Image2 = mainScr.loadImage("sleep2.bmp");
  mainScr.image(Image1, 0, 0);
  slaveScr.image(Image2, 0, 0);
  Image1.close();
  Image2.close();
  ChengeScoreMode = false;
  CanSleep = false;
}

void AnimGolB(){
  slaveScr.invertDisplay(true);
  delay(100);
  slaveScr.invertDisplay(false);
  delay(100);
  slaveScr.invertDisplay(true);
  delay(100);
  slaveScr.invertDisplay(false);
  delay(100);
  slaveScr.invertDisplay(true);
  delay(100);
  slaveScr.invertDisplay(false);
  for (int i = 0; i<160; i++){
    mainScr.ScrollRight();
    delay(2);
  }
}

void AnimGolA(){
  mainScr.invertDisplay(true);
  delay(100);
  mainScr.invertDisplay(false);
  delay(100);
  mainScr.invertDisplay(true);
  delay(100);
  mainScr.invertDisplay(false);
  delay(100);
  mainScr.invertDisplay(true);
  delay(100);
  mainScr.invertDisplay(false);
  for (int i = 0; i<160; i++){
    slaveScr.ScrollRight();
    delay(2);
  }
}

void WinA(){
  Image1 = mainScr.loadImage("win3.bmp");
  Image2 = mainScr.loadImage("redLose.bmp");
  mainScr.image(Image1, 0, 0);
  slaveScr.image(Image2, 0, 0);
  Image1.close();
  Image2.close();
}

void WinB(){
  Image1 = mainScr.loadImage("win2.bmp");
  Image2 = mainScr.loadImage("lose.bmp");
  slaveScr.image(Image1, 0, 0);
  mainScr.image(Image2, 0, 0);
  Image1.close();
  Image2.close();
}

void Stop_game(){
  Image1 = mainScr.loadImage("map.bmp");
  mainScr.doubleImage(Image1, 0, 0);
  Image1.close();
}

void ChangeMaxScore(){
  Image1 = mainScr.loadImage("maxSc.bmp");
  mainScr.doubleImage(Image1, 0, 0);
  Image1.close();
  mainScr.stroke(10,139, 255);
  slaveScr.stroke(10,139, 255);
  mainScr.setTextSize(3);
  slaveScr.setTextSize(3);
  mainScr.text("Play to", 20, 92);
  slaveScr.text("Play to", 20, 92);
  MaxScoreUpdate();
}

void MaxScoreUpdate(){
  char simb[4];
  sprintf(simb, "%d", Win);
  Image1 = mainScr.loadImage("part.bmp");
  mainScr.doubleImage(Image1, 64, 7);
  Image1.close();
  mainScr.setTextSize(6);
  slaveScr.setTextSize(6);
  mainScr.stroke(10,139, 255);
  slaveScr.stroke(10,139, 255);
  mainScr.text(simb, 65,25);
  slaveScr.text(simb, 65,25);
}

void IdleScreen(){ 
  Vector3 color;
  mainScr.noFill();
  slaveScr.noFill();
  for(int i=0; i<=42; i++){
    color.Set(random(256),random(256),random(256));
    mainScr.stroke(color.x, color.y, color.z);
    slaveScr.stroke(color.x, color.y, color.z); 
    mainScr.circle(random(159),random(127),random(30));
    slaveScr.circle(random(159),random(127),random(30));
  }
  Image1 = mainScr.loadImage("idle.bmp");
  mainScr.doubleImage(Image1, 0, 0);
  Image1.close();
}
