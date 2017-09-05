#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(ofColor::skyBlue);
    
    ofSetColor(ofColor::ghostWhite, 32);
    
    // make a new variable called i //initialize
    // while i < 30                 //conditional
    // add 1 to i                   //increment
    for (int i = 0; i < 3000; ++i) {
        //ofDrawCircle(float x, float y, float radius);
        ofDrawCircle(ofGetWindowWidth()/2 + ofRandom(-100, 100),
                     
                     ofGetWindowHeight()/2 + ofRandom(-50, 50),
                     
                     100 + ofRandom(-20, 20));
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
