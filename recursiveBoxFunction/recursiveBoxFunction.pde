void setup() {
  size(800, 800);
  frameRate(1);
  rectMode(CENTER);
  noFill();
}

void draw() {
  background(0);
  boxes(random(200, width/2), random(200, height/2), 300);
}

void boxes(float xPos, float yPos, float rectSize) {
  float recursionPoint, newX, newY;
  stroke(random(255));
  rect(xPos, yPos, rectSize, rectSize);
  if (rectSize > 1) {
    recursionPoint = random(10);
    newX = xPos + rectSize * sin(recursionPoint);
    newY = yPos + rectSize * cos(recursionPoint);
    boxes(newX, newY, rectSize/2);

    recursionPoint = random(10);
    newX = xPos + rectSize/2 * sin(recursionPoint);
    newY = yPos + rectSize/2 * cos(recursionPoint);
    boxes(newX, newY, rectSize/2);
    
    recursionPoint = random(25);
    newX = xPos + rectSize/2 * sin(recursionPoint);
    newY = yPos + rectSize/2 * cos(recursionPoint);
    boxes(newX, newY, rectSize/2);
  }
}