#include "ofApp.h"

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundAuto(false);
	speed = 0.0005;
}

//--------------------------------------------------------------
void ofApp::update() {
	zeno(mouseX, mouseY);
}

void ofApp::zeno(float catchX, float catchY) {
	obj.x = speed * catchX + (1 - speed) * obj.x;
	obj.y = speed * catchY + (1 - speed) * obj.y;
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(0, 0, 0, 3);
	ofFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	for (int i = 25; i > 0; i-=5) {
		ofSetColor(mouseY/5, mouseX/5, (obj.y + obj.x)/3);
		ofFill();
		ofCircle(obj.x, obj.y, i*2);

		ofSetColor(i * 10);
		ofNoFill();
		ofCircle(obj.x, obj.y, i);
	}
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
