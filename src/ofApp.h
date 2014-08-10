#pragma once

#include "ofMain.h"

#define DIMENSION 30
#define SIZE 30
class ofApp : public ofBaseApp{

    ofColor som[DIMENSION][DIMENSION];
    int it;
    bool pause;
    ushort nearX = 0, nearY = 0;

public:
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void influence();
};
