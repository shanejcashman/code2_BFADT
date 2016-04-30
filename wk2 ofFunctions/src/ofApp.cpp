#include "ofApp.h"

void ofApp::setup() {
	font1.loadFont("arial.ttf", 10);
	font2.loadFont("arial.ttf", 12);
	font3.loadFont("arial.ttf", 50);

	rest.load("rest.mp4");
	rest.play();

	noise.load("noise.mp4");
	noise.play();

	alarm.load("alarm.wav");

	ld1.load("1.png");
	lm1.load("2.png");
	lu1.load("3.png");
	rd1.load("4.png");
	rm1.load("5.png");
	ru1.load("6.png");
	md1.load("7.png");
	mm1.load("8.png");
	mu1.load("9.png");

	ld2.load("10.png");
	lm2.load("11.png");
	lu2.load("12.png");
	rd2.load("13.png");
	rm2.load("14.png");
	ru2.load("15.png");
	md2.load("16.png");
	mm2.load("17.png");
	mu2.load("18.png");

	clock.load("clock.png");
	explode.load("explode.png");
}

void ofApp::update() {
	rest.update();
	noise.update();
	checkMouse();
}

void ofApp::draw() {
	ofSetLineWidth(.5);
	ofColor inner = (50, 50, 75);
	ofColor outer = (bg, 0, 0);

	ofBackgroundGradient(inner, outer, OF_GRADIENT_LINEAR);

	ofSetColor(100, 100, 150, 90);
	ofRect(100, 50, 200, 100);		//status border
	ofRect(650, 50, 200, 75);		//control border
	ofRect(100, 175, 110, 100);		//sound border

	ofSetColor(0, 0, 0, 90);
	ofRect(105, 55, 190, 90);		//status bg
	ofRect(655, 55, 190, 65);		//control bg
	ofRect(105, 175, 100, 100);		//sound bg

	ofRect(50, 50, 25, 255);		//meter bg

	ofSetColor(255, 0, 0, 90);
	ofRect(50, 50, 25, 25);			//threshold

	ofSetColor(255, 255, 255, 90);	
	ofRect(50, 305, 25, meterH);	//meter

	ofNoFill();
	ofSetColor(255);
	ofRect(50, 50, 25, 255);		//meter border

	ofFill();

	drawFace();

	if (size > 100) {
		toggle2 = true;
	}
	if (toggle1 == false) {
		if (toggle2 == false) {
			rest.draw(105, 175, 100, 100);
			alarm.stop();
			clock.draw(mouseX - 100, mouseY - 50);
		} 
		if (wakeLevel > 0) {
			wakeLevel -= .08;
		}
		if (bg > 0) {
			bg -= 1;
		}
		if (meterH < 0) {
			meterH += .08;
		}
	}

	if (toggle1 == true) {
		if (toggle2 == false) {
			noise.draw(105, 175, 100, 100);
			clock.draw(mouseX - ofRandom(90, 110), mouseY - ofRandom(40, 60));
			alarm.play();
			if (wakeLevel >= 230) {
				if (size <= 100) {
					size+=.5;
				}
			}

			if (wakeLevel < 255) {
				wakeLevel += .5;
			}
			if (bg < 255) {
				bg += 3;
			}
			if (meterH > -255) {
				meterH -= .5;
			}
		}
		else {
			if (wakeLevel > 0) {
				wakeLevel -= .08;
			}
			if (bg > 0) {
				bg -= 1;
			}
			if (meterH < 0) {
				meterH += .08;
			}
		}
	}
	font1.drawString("STATUS:", 110, 70);
	font1.drawString("MOUSE to move", 665, 70);
	font1.drawString("SPACE to trigger alarm", 665, 85);
	font1.drawString("R to respawn", 665, 110);

	if (toggle2 == false) {
		if (wakeLevel < 150 && toggle1 == false) {
			font2.drawString("asleep", 110, 100);
		}
		else if (wakeLevel >= 150 && toggle1 == false) {
			font2.drawString("i'll just hit snooze", 110, 100);
		}
		else if (toggle1 == true) {
			if (wakeLevel < 50) {
				font2.drawString("i'll just hit snooze", 110, 100);
			}
			if (wakeLevel > 50 && wakeLevel <= 110) {
				font2.drawString("ugh, i guess it's time...", 110, 100);
			}
			if (wakeLevel > 110 && wakeLevel <= 150) {
				font2.drawString("ok! i'm up!", 110, 100);
			}
			if (wakeLevel > 150 && wakeLevel <= 230) {
				font2.drawString("ok! i get it!", 110, 100);
			}
			if (wakeLevel > 230) {
				font2.drawString("TURN it OFF!!!", 110, 100);
			}
		}
	}
	else {
		font2.drawString("...", 110, 100);
		ofSetColor(255);
		font3.drawString("SWEET DREAMS", 200, ofGetHeight() / 2);
	}
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		toggle1 = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == ' ') {
		toggle1 = false;
	}
	if (key == 'r' || key == 'R') {
		toggle2 = false;
	}
}

void ofApp::checkMouse() {
	// mouseX sets column
	if (mouseX <= ofGetWidth() / 3) {
		column = 1;
	}
	if (mouseX > ofGetWidth() / 3 && mouseX < (ofGetWidth() / 3) * 2) {
		column = 2;
	}
	if (mouseX >= (ofGetWidth() / 3) * 2) {
		column = 3;
	}

	// mouseY set row
	if (mouseY <= ofGetHeight() / 3) {
		row = 1;
	}
	if (mouseY > ofGetHeight() / 3 && mouseY < (ofGetHeight() / 3) * 2) {
		row = 2;
	}
	if (mouseY >= (ofGetHeight() / 3) * 2) {
		row = 3;
	}
}

void ofApp::drawFace() {
	if (wakeLevel <= 230) {
		size = 0;
		if (row == 1 && column == 1) {
			lu1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 1 && column == 2) {
			ru1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 1 && column == 3) {
			mu1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}

		if (row == 2 && column == 1) {
			lm1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 2 && column == 2) {
			rm1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 2 && column == 3) {
			mm1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 3 && column == 1) {
			ld1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 3 && column == 2) {
			rd1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
		if (row == 3 && column == 3) {
			md1.draw(0, 0, ofGetWidth(), ofGetHeight());
		}
	}
	else
	{
		if (row == 1 && column == 1) {
			lu2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (row == 1 && column == 2) {
			mu2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (row == 1 && column == 3) {
			ru2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}


		if (row == 2 && column == 1) {
			lm2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (row == 2 && column == 2) {
			mm2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (row == 2 && column == 3) {
			rm2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}

		if (row == 3 && column == 1) {
			ld2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (row == 3 && column == 2) {
			md2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (row == 3 && column == 3) {
			rd2.draw(0, 0, ofGetWidth() + ofRandom(0, 5), ofGetHeight() + ofRandom(0, 5));
		}
		if (toggle2 == false) {
			fade = 255;
			scale = 10;
			ofSetColor(ofRandom(0, 250), 0, ofRandom(0, 250));
			ofSetLineWidth(3);
			ofDrawLine(mouseX - 75, mouseY - 25, (ofGetWidth() / 2) - 50, ofGetHeight() / 2);
			ofDrawLine(mouseX - 25, mouseY - 25, (ofGetWidth() / 2) + 50, ofGetHeight() / 2);
			ofSetColor(ofRandom(0, 250), ofRandom(0, 250), 0);
			ofDrawEllipse(mouseX - 50, mouseY - 25, size, size);
		}
		else {
			fade--;
			ofSetColor(ofRandom(0, 250), 0, ofRandom(0, 250), fade);
			ofSetLineWidth(3);
			ofDrawLine(mouseX - 75, mouseY - 25, (ofGetWidth() / 2) - 50, ofGetHeight() / 2);
			ofDrawLine(mouseX - 25, mouseY - 25, (ofGetWidth() / 2) + 50, ofGetHeight() / 2);
			ofSetColor(ofRandom(0, 250), ofRandom(0, 250), 0, fade);
			ofDrawEllipse(mouseX - 50, mouseY - 25, size, size);
			ofSetColor(255, 255, 255, fade);
			explode.draw(mouseX - 200, mouseY - 150, 300, 250);
			explode.draw(100, 175, 125, 100);
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
