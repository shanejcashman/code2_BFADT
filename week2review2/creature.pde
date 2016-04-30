class Creature {
  //variables
  float size;
  float xPos, yPos;
  float xSpeed, ySpeed;
  color fur;

  //constructor
  Creature() {
    size = 1;
    xPos = random(width);
    yPos = random(height);
    xSpeed = random(-3, 3);
    ySpeed = random(-3, 3);
    fur = color (255, 100, 125);
  }
  //methods
  void giveBirth(){
    xPos = mouseX;
    yPos = mouseY;
  }
  
  void update() {
    strokeWeight(3);
    stroke(0);
    fill(fur);
    ellipse(xPos, yPos, size*50, size*50);
    fill(255);
    ellipse(xPos -(size*4), yPos-(size*2), size*25, size*10);
    fill(0);
    ellipse(xPos-(size*5), yPos-(size+size*0.5), size*5, size*5);
    line(xPos-(size*16), yPos+(size*10), xPos+(size*11), yPos + (size*10));
    
    xPos+=xSpeed;
    yPos+=ySpeed;
  }
}