#include "ofApp.h"

//proportional size of square
#define RECT_SIZE 25

bool redraw = true;

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(1);
    //size of canvas or window
    //outline only nofill
    ofNoFill();
    
    //OMG rectangles draw from top-left!!
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (redraw) {
        //white background
        ofBackground(ofColor::white);
        
        //black square
        ofSetColor(ofColor::black);
    
        //offset from top corner
        ofTranslate(RECT_SIZE, RECT_SIZE);
        
        //calc for full randomness
        float randScale = 180/23;
    
    for (int k = 0; k < 100; ++k ){
        ofPushMatrix();
        ofTranslate(ofRandom(-100, ofGetWidth()+100),
                    ofRandom(-100, ofGetHeight()+100));
        
        //repeat -> //12 for horizontal #
        //23 for vertical #
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 23; ++j) {
                //save coordinate space
                ofPushMatrix();
                
                //control over randomness
                //vertical position affects randomness
                
                //position square
                ofTranslate(RECT_SIZE * i + ofRandom(-j, j),
                            RECT_SIZE * j + ofRandom(-j, j));
                
                //rotate square
                ofRotateZ( ofRandom(-j * randScale,
                                    j * randScale) );
                
                //draw square
                ofDrawRectangle(0,
                                0,
                                RECT_SIZE,
                                RECT_SIZE);
                
                //return to coordinate space
                ofPopMatrix();
                
            } //end of j loop
        } //end of i loop
//        redraw = false;
    } // end of if (redraw)

    //ART-Y
    //draw as one-shot or as iterative top to bottom & left right?
    //falling?
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    redraw = true;
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
