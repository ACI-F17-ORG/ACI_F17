#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 640;
    camHeight = 480;
    
    vidGrabber.setDeviceID(0);
    vidGrabber.initGrabber(camWidth, camHeight);
    
    finder.setup("haarcascade_frontalface_default.xml");
    
    rgb.allocate(camWidth, camHeight);
    hsb.allocate(camWidth, camHeight);
    hue.allocate(camWidth, camHeight);
    sat.allocate(camWidth, camHeight);
    bri.allocate(camWidth, camHeight);
    filter1.allocate(camWidth, camHeight);
    filter2.allocate(camWidth, camHeight);
    finalImage.allocate(camWidth, camHeight);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew())
    {
        rgb.setFromPixels(vidGrabber.getPixels());
        hsb = rgb;
        hsb.convertRgbToHsv();
        hsb.convertToGrayscalePlanarImages(hue, sat, bri);
        
        int hueRange = 10;
        for (int i = 0; i < camWidth * camHeight; ++i) {
            filter1.getPixels()[i] = ofInRange(hue.getPixels()[i],
                                               findHue - hueRange,
                                               findHue + hueRange) ? 255 : 0;
        }
        
        
        finder.findHaarObjects(vidGrabber.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    vidGrabber.draw(0, 0, camWidth, camHeight);
    
    ofSetColor(ofColor::lawnGreen);
    ofNoFill();
    for (int i = 0; i < finder.blobs.size(); ++i) {
        ofDrawRectangle(finder.blobs[i].boundingRect);

    }
    ofFill();
    
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
