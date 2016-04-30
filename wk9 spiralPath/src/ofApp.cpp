#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	circleX = ofGetWidth() / 2;
	circleY = ofGetHeight() / 2;
	ofSetBackgroundAuto(false);
	arial.loadFont("arial.ttf", 10);
}

//--------------------------------------------------------------
void ofApp::update() {
	if (toggle == true) {
		circleX = ofGetWidth() / 2;
		circleY = ofGetHeight() / 2;
		turn = 0;
	}
	else {
		turn += 0.01;
		circleX = ofGetWidth() / 2 + sin(ofGetElapsedTimef()) * turn;
		circleY = ofGetHeight() / 2 + cos(ofGetElapsedTimef()) * turn;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(0);
	ofRect(20, 20, 200, 30);
	ofSetColor(255);
	arial.drawString("SPACE to generate new spiral", 30, 40);

	ofSetColor(0);
	ofNoFill();
	ofCircle(circleX, circleY, ofRandom(13));

	ofSetColor(255);
	ofFill();
	ofCircle(circleX, circleY, ofRandom(13));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		toggle = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == ' ') {
		toggle = false;
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
