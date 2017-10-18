#include "ofApp.h"

bool showStuff = true;

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
        filter1.flagImageChanged();
        
        int satRange = 20;
        for (int i = 0; i < camWidth * camHeight; ++i) {
            filter2.getPixels()[i] = ofInRange(sat.getPixels()[i],
                                               findSat - satRange,
                                               findSat + satRange) ? 255 : 0;
        }
        filter2.flagImageChanged();
        
        cvAnd(filter1.getCvImage(),
              filter2.getCvImage(),
              finalImage.getCvImage());
        finalImage.flagImageChanged();
        
        contours.findContours(finalImage,
                              50,
                              (camWidth*camHeight)/3,
                              3,
                              false);
        
        finder.findHaarObjects(vidGrabber.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (showStuff){
        ofSetColor(ofColor::white);
        vidGrabber.draw(0, 0, camWidth, camHeight);
        
        hsb.draw(0, camHeight, 320, 240);
        
        hue.draw(camWidth, 0,  320, 240);
        sat.draw(camWidth, 240,  320, 240);
        bri.draw(camWidth, 480,  320, 240);
        
        filter1.draw(camWidth + 320, 0,  320, 240);
        filter2.draw(camWidth + 320, 240,  320, 240);
        finalImage.draw(camWidth + 320, 480,  320, 240);
    }
    contours.draw(0,0);
    
    ofSetColor(ofColor::lawnGreen);
    ofNoFill();
    for (int i = 0; i < finder.blobs.size(); ++i) {
        ofDrawRectangle(finder.blobs[i].boundingRect);

    }
    ofFill();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ')
        showStuff = !showStuff;
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

    int mx = x % camWidth;
    int my = y % camHeight;
    
    findHue = hue.getPixels()[my*camWidth + mx];
    findSat = sat.getPixels()[my*camWidth + mx];
    
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
