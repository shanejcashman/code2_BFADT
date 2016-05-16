#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp {
public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//functions
	void follow(float catchX, float catchY);
	void headParam();
	void talk();

	//interface
	ofTrueTypeFont font1, font2, font3, font4;
	ofImage bubble, star, example1, example2, example3, example4;
	bool sceneToggle, modeToggle;
	int scene,  mode;
	float hover, angle1, angle2;

	//model
	ofxAssimpModelLoader head, eye1, eye2, lip1, lip2;
	ofVec3f headPos, eyePos, lipPos;
	float eyeSpacing, lipSpacing;
	float headSize, eyeSize, lipSize;
	float lookH, lookV, speed;
	bool open;

	//camera
	ofVideoGrabber camera;
	ofImage img;
	int camX, camY, camW, camH, capCount;
	bool capture;

	//sound
	ofSoundPlayer perc, inst, vox;
	bool pTog, iTog, vTog;
};
