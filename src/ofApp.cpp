#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(ushort i = 0; i < DIMENSION; i++){
        for(ushort j = 0; j < DIMENSION; j++){
            som[i][j].set(ofRandom(255), ofRandom(255), ofRandom(255));
        }
    }
    it = 0;
    pause = true;
    ofSetLineWidth(4);

}



//--------------------------------------------------------------


void ofApp::update(){
    
    if(pause)return;
    
    ofColor newColor(ofRandom(255), ofRandom(255), ofRandom(255));
    
    int minDif = 255*3;
    for(ushort i = 0; i < DIMENSION; i++){
        for(ushort j = 0; j < DIMENSION; j++){
            ushort  sum = 0;
            sum += abs(newColor.r - som[i][j].r);
            sum += abs(newColor.g - som[i][j].g);
            sum += abs(newColor.b - som[i][j].b);
            if(minDif > sum){
                nearX = i;
                nearY = j;
                minDif = sum;
            }
        }
    }
    
    ofLog() << "newColor " << (int)newColor.r << ' '  << (int)newColor.g << ' '  << (int)newColor.b;
    ofLog() << "nearX:" << nearX <<  "  nearY:" << nearY;
    
    
    // adjust to new color
    som[nearX][nearY].r += (newColor.r- som[nearX][nearY].r) * 0.7;
    som[nearX][nearY].g += (newColor.g- som[nearX][nearY].g) * 0.7;
    som[nearX][nearY].b += (newColor.b- som[nearX][nearY].b) * 0.7;

    
    // influence
    for(short i = nearX-1; i <= nearX+1; i++){
        for(short j = nearY-1; j <= nearY+1; j++){
            if(i < 0 || j < 0) continue;
            if(i >= DIMENSION || j >= DIMENSION) continue;
            if(i == nearX && j == nearY) continue;
            
            som[i][j].r += (newColor.r- som[i][j].r) * 0.35;
            som[i][j].g += (newColor.g- som[i][j].g) * 0.35;
            som[i][j].b += (newColor.b- som[i][j].b) * 0.35;
        }
    }
    ofLog() << "iteration:" << it;
}


//--------------------------------------------------------------
void ofApp::draw(){

    
    for(int i = 0; i < DIMENSION; i++){
        for(int j = 0; j < DIMENSION; j++){
            ofSetColor(som[i][j]);
            ofRect(i* SIZE, j*SIZE, SIZE, SIZE);
        }
    }
    ofNoFill();
    ofSetColor(255,0,0);
    ofRect(nearX*SIZE, nearY*SIZE, SIZE, SIZE);
    ofFill();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    pause = !pause;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
