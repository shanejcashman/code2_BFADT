int rectX, rectY;
int rectW, rectH;

void setup() {
  size(500, 500);
  rectX = width/2;
  rectY = height/2;
  rectW = 100;
  rectH = 100;
}

void draw() {
  rect(rectX, rectY, rectW, rectH);
  for (int i=0; i<width; i+=width/5) {
    fill(random(255));
    rect(i, rectY, rectW, rectH);
  }
  circleSquare(100, 100, 100);
  if (mousePressed) {
    background(255);
  } else {
    background(0);
  }
  if (keyPressed) {
    if (key == 's') {
      saveFrame();
    }
  }
}

void circleSquare(float x, float y, float diam) {
  ellipse(x, y, diam, diam);
  rect(x, y, diam, diam);
}