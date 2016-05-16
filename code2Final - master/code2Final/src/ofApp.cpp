#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
	ofEnableDepthTest();
	glShadeModel(GL_SMOOTH);

	GLfloat lightOnePosition[] = { .5, -.5, 1, 0 };
	GLfloat lightOneColor[] = { 255, 175, 175, 1 };

	glLightfv(GL_LIGHT0, GL_POSITION, lightOnePosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightOneColor);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	
	camera.setup(320, 256);

	head.loadModel("head.3DS", 20);
	eye1.loadModel("eye.3DS", 20);
	eye2.loadModel("eye.3DS", 20);
	lip1.loadModel("lipUp.3DS", 20);
	lip2.loadModel("lipLo.3DS", 20);

	bubble.load("bubble.png");
	star.load("star.png");

	example1.load("example1.jpg");
	example2.load("example2.jpg");
	example3.load("example3.jpg");
	example4.load("example4.jpg");

	font1.load("mode.TTF", 20);
	font2.load("mode.TTF", 30);
	font3.load("mode.TTF", 15);
	font4.load("mode.TTF", 50);

	vox.load("vox.wav");
	perc.load("perc.wav");
	inst.load("inst.wav");

	vox.play();
	perc.play();
	inst.play();

	vox.setLoop(true);
	perc.setLoop(true);
	inst.setLoop(true);

	headPos.set(ofGetWidth() / 4, ofGetHeight() / 1.45, 0);
	headSize = 50;
	eyeSize = headSize / 4.0;
	lipSize = headSize / 1.0;
	eyeSpacing = eyeSize * 6.0;
	lipSpacing = lipSize / 3.0;
	lookV = 20.0;
	lookH = 30.0;

	speed = .01;
	scene = 0;
	mode = 0;
}

void ofApp::headParam() {
	eyePos.set(headPos.x, headPos.y - headSize / 1.5, headSize * 3.0);
	lipPos.set(headPos.x, headPos.y + headSize * 2.0, headSize * 3.5);

	head.setScale(headSize, headSize, headSize);
	head.setPosition(headPos.x, headPos.y, headPos.z);

	eye1.setScale(eyeSize, eyeSize, eyeSize);
	eye1.setPosition(eyePos.x - eyeSpacing, eyePos.y, eyePos.z);

	eye2.setScale(eyeSize, eyeSize, eyeSize);
	eye2.setPosition(eyePos.x + eyeSpacing, eyePos.y, eyePos.z);

	lip1.setScale(lipSize, lipSize, lipSize);
	lip1.setPosition(lipPos.x, lipPos.y, lipPos.z);

	lip2.setScale(lipSize, lipSize, lipSize);
	lip2.setPosition(lipPos.x, lipPos.y + lipSpacing, lipPos.z);
}

void ofApp::talk() {
	angle2 = angle2 + 0.05;
	lipSpacing = (sin(angle2) * 10) + 25;
}

void ofApp::follow(float catchX, float catchY) {
	headPos.x = speed * catchX + (1 - speed) * headPos.x;
	headPos.y = speed * catchY + (1 - speed) * headPos.y;
}

void ofApp::update() {
	if (sceneToggle == true) {
		scene++;
		sceneToggle = false;
	}

	if (scene == 0) {
		if (modeToggle == true) {
			mode++;
			modeToggle = false;
		}

		if (mode > 3) {
			mode = 0;
		}
		camera.update();
		headParam();
		talk();
		perc.setVolume(0.0f);
		inst.setVolume(0.0f);

		angle1 = angle1 + 0.01;
		hover = sin(angle1) * 10;
		
		if (mouseX < 200) {
			if (lookH > 15) {
				lookH -= 0.1;
			}
		}
		else if (mouseX > 700) {
			if (lookH < 75) {
				lookH += 0.1;
			}
		}
		else {
			lookH = 40;
		}
	}
	if (scene == 1) {
		follow(mouseX, mouseY);
		headParam();

		if (abs(headPos.x - mouseX) <= 25 && abs(headPos.y - mouseY) <= 25) {
			if (lookH > 0) {
				lookH--;
			}
			if (lookV > 0) {
				lookV--;
			}
			if (lookH < 0) {
				lookH++;
			}
			if (lookV < 0) {
				lookV++;
			}
		}
		else 
		{
			if (mouseX < ofGetWidth() / 3.0) {
				if (lookH > -50.0) {
					lookH -= 0.5;
				}
			}
			else if (mouseX > (ofGetWidth() / 3.0) * 2.0) {
				if (lookH < 50.0) {
					lookH += 0.5;
				}
			}
			else if (mouseX > ofGetWidth() / 3 && mouseX < (ofGetWidth() / 3.0) * 2.0) {
				if (lookH > 0.0) {
					lookH -= 0.5;
				}
				else if (lookH < 0.0) {
					lookH += 0.5;
				}
			}

			if (mouseY < ofGetHeight() / 3.0) {
				if (lookV < 40.0) {
					lookV += 0.5;
				}
			}
			else if (mouseY > (ofGetHeight() / 3.0) * 2.0) {
				if (lookV > -40.0) {
					lookV -= 0.5;
				}
			}
			else if (mouseY > ofGetHeight() / 3.0 && mouseY < (ofGetHeight() / 3.0) * 2.0) {
				if (lookV > 0.0) {
					lookV -= 0.5;
				}
				else if (lookV < 0.0) {
					lookV += 0.5;
				}
			}
			follow(mouseX, mouseY);
		}
	}	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	if (scene == 0) {
		ofPushMatrix();
		ofTranslate(0, hover);
		font1.drawString("Shane Cashman", 625, 325);
		font1.drawString("Parsons School of Design 2016", 625, 350);
		font2.drawString("SPACE to begin", 700, 625);
		font4.drawString("SECRET ST  R", 635, 450);

		star.draw(1005, 390, 60, 60);
		bubble.draw(550, 250, 650, 450);
		ofPopMatrix();

		glPushMatrix();
		glTranslatef(headPos.x, headPos.y, 0);
		glRotatef(lookH, 0, 1, 0);
		glRotatef(lookV, 1, 0, 0);
		glTranslatef(-headPos.x, -headPos.y, 0);

		head.drawFaces();
		lip1.drawFaces();
		lip2.drawFaces();
		eye1.drawFaces();
		eye2.drawFaces();
		glPopMatrix();
		
		font3.drawString("Mode:", 80, 342);
		if (mode == 0) {
			font3.drawString("Head", 140, 342);
			font3.drawString("align your forehead to the frame", 600, 130);
			example1.draw(400, 225, 100, 80);
		}
		if (mode == 1) {
			font3.drawString("Eye", 140, 342);
			font3.drawString("align your eye to the guide", 600, 130);
			example2.draw(400, 225, 100, 80);
			ofRect(100, 120, 225, 150);
		}
		if (mode == 2) {
			font3.drawString("Upper lip", 140, 342);
			font3.drawString("align your lips to the frame", 600, 130);
			example3.draw(400, 225, 100, 80);
		}
		if (mode == 3) {
			font3.drawString("Lower lip", 140, 342);
			font3.drawString("align your lips to the frame", 600, 130);
			example4.draw(400, 225, 100, 80);
		}
		
		if (modeToggle == true) {
			ofFill();
			ofRect(52.5, 327.5, 20, 20);
		} else {
			ofNoFill();
			ofRect(52.5, 327.5, 20, 20);
		}
	
		font3.drawString("example:", 400, 210);
		font2.drawString("how to:", 600, 80);
		font3.drawString("'x' to capture", 600, 110);
		font3.drawString("restart after capture to upload texture", 600, 175);

		ofRect(50, 50, 320, 256);
		camera.draw(50, 50);
		ofNoFill();
		ofRect(400, 50, 160, 128);
		if (capture == true) {
			img.grabScreen(50, 50, 320, 256);

			string fileName;
			if (mode == 0) {
				fileName = "head.jpg";
			}
			if (mode == 1) {
				fileName = "eye.jpg";
			}
			if (mode == 2) {
				fileName = "lipUp.jpg";
			}
			if (mode == 3) {
				fileName = "lipLo.jpg";
			}

			img.save(fileName);
			capCount++;
			capture = false;
		}
		if (capCount > 0) {
			img.draw(400, 50, 160, 128);
		}
		
	}
	if (scene == 1) {
		font3.drawString("'1' toggles voice", 50, 50);
		font3.drawString("'2' toggles sound", 50, 75);
		font3.drawString("'3' toggles drums", 50, 100);

		if (vTog == true) {
			vox.setVolume(1.0f);
			ofRect(275, 35, 15, 15);
		}
		else {
			vox.setVolume(0.0f);
		}
		if (iTog == true) {
			inst.setVolume(1.0f);
			ofRect(275, 60, 15, 15);
		}
		else {
			inst.setVolume(0.0f);
		}
		if (pTog == true) {
			perc.setVolume(1.0f);
			ofRect(275, 85, 15, 15);
		}
		else {
			perc.setVolume(0.0f);
		}	
		
		glPushMatrix();
		glTranslatef(headPos.x, headPos.y, 0);
		glRotatef(lookH, 0, 1, 0);
		glRotatef(lookV, 1, 0, 0);
		glTranslatef(-headPos.x, -headPos.y, 0);

		head.drawFaces();
		lip1.drawFaces();
		lip2.drawFaces();
		eye1.drawFaces();
		eye2.drawFaces();
		glPopMatrix();

		vox.setSpeed((mouseY/mouseX));
		inst.setSpeed(1.0f);
		perc.setSpeed(1.0f);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'x') {
		capture = true;
	}
	if (key == 'r') {
		scene = 0;
	}
	if (key == '1') {
		if (vTog == false) {
			vTog = true;
		}
		else {
			vTog = false;
		}
	}
	if (key == '2') {
		if (iTog == false) {
			iTog = true;
		}
		else {
			iTog = false;
		}
	}
	if (key == '3') {
		if (pTog == false) {
			pTog = true;
		}
		else {
			pTog = false;
		}
	}
	if (scene < 2) {
		if (key == ' ') {
			sceneToggle = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (mouseX > 50 && mouseX < 75 && mouseY > 325 && mouseY < 350) {
		if (button == 0) {
			modeToggle = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
