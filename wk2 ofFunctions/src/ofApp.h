#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void checkMouse();
		void drawFace();
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage ld1, lm1, lu1, md1, mm1, mu1, rd1, rm1, ru1; //normal
		ofImage ld2, lm2, lu2, md2, mm2, mu2, rd2, rm2, ru2; //angry
		ofImage clock;
		ofImage explode;

		ofVideoPlayer rest, noise;

		ofSoundPlayer alarm;

		ofTrueTypeFont font1, font2, font3;

		bool toggle1;
		bool toggle2;

		int row;
		int column;

		float bg;
		int fade;
		int scale;

		float wakeLevel;
		float meterH;
		float size;
};
