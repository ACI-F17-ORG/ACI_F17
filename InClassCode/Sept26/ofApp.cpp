#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    images[0].load("nyan.png");
    images[1].load("nyanInverse.png");
    ofSetBackgroundAuto(false);
    images[0].setAnchorPoint(images[0].getWidth()/2, images[0].getHeight()/2);
    images[1].setAnchorPoint(images[1].getWidth()/2, images[1].getHeight()/2);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if( ofGetMousePressed() ){
//        ofBackground(128);
        for (int i = 0;i < 100; ++i) {
            
            int which = (int)ofRandom(100) % 2;
            
            images[which].draw(ofRandom(ofGetWidth()),
                               ofRandom(ofGetHeight()),
                               images[which].getWidth() * ofGetMouseX()/ofGetWidth(),
                               images[which].getHeight() * ofGetMouseY()/ofGetHeight());
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if( key == OF_KEY_RIGHT ){
        cout << "right arrow works" << endl;
    }
    
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
