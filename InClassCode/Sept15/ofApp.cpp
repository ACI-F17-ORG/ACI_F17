#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    anim.reset(0.0);
    anim.setRepeatType(LOOP_BACK_AND_FORTH);
    anim.setCurve(OBJECT_DROP);
    anim.animateTo(300);

    ofSetCircleResolution(100);
    
    panel.setup();
    panel.add(chachaSlider.setup("backgroundColor",
                                 ofColor::chocolate,
                                 ofColor::black,
                                 ofColor::white));
    hideGui = false;

}


//--------------------------------------------------------------
void ofApp::update(){
    float deltaTime = ofGetLastFrameTime();
    anim.update(deltaTime);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(chachaSlider);
    
    ofDrawCircle(ofGetWidth()/2,
                 ofGetHeight()/2,
                 anim);
    
    if (!hideGui) {
        panel.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'g') {
        hideGui = !hideGui;
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
