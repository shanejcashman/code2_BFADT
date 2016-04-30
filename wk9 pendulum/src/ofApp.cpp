#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	horizontal.x;
	horizontal.y = ofGetWidth();
	direction = 1;
	size = 20;
	center = ofGetHeight()/1.5;
}

//--------------------------------------------------------------
void ofApp::update() {
	speed.x += size/50000 * direction;

	if (circle.x >= ofGetWidth()) {
		direction = -1;
	}
	else if (circle.x <= 0) {
		direction = 1;
	}
	circle.x = ((1-speed.x)*horizontal.x) + (speed.x* horizontal.y);

	if (circle.x <= ofGetWidth() / 2) {
		speed.y = powf(0.01, speed.x);
	}
	else 
	{
		speed.y = powf(0.01, (1-speed.x));
	}
	circle.y = (1 - speed.y) * center;
}

//--------------------------------------------------------------

void ofApp::draw() {
	ofSetColor(255);
	ofLine(circle.x, circle.y, ofGetWidth() / 2, 0);
	
	ofSetColor(150);
	ofCircle(circle.x, circle.y, size);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
