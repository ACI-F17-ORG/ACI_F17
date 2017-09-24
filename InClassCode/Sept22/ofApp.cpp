#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    boxMesh = ofMesh::box(20, 20, 20);
    
    fft.setup(1024);
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
    
    float value = fft.getBins()[20];
    if( value > .5) {
        for (int i = 0; i < 10; ++i) {
            Particle p = Particle(ofColor::blue,
                                  ofVec3f(1),
                                  ofVec3f(ofGetMouseX(),
                                          ofGetMouseY(),
                                          0),
                                  ofVec3f(ofRandom(-10, 10),
                                          ofRandom(-10, 10),
                                          ofRandom(-10, 10)),
                                  ofVec3f(ofRandom(-10, 10),
                                          ofRandom(-10, 10),
                                          ofRandom(-10, 10)));
            particles.push_back(p);
        }
    }
    
    vector<Particle> p;
    
    for (int i = 0; i < particles.size(); ++i) {
        particles[i].update();
        if(particles[i].position.length() < 1000) {
            p.push_back(particles[i]);
        }
    }
    
    particles = p;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cout << particles.size() << endl;
    ofBackground(ofColor::black);
    
    for (int i = 0; i < particles.size(); ++i) {
        ofPushMatrix();
        particles[i].draw();
        boxMesh.draw();
        ofPopMatrix();
    }
    
    ofPushMatrix();
    ofTranslate(16, 16);
    ofSetColor(255);
    ofDrawBitmapString("Frequency Domain", 0, 0);
    plot(fft.getBins(), 128);
    ofPopMatrix();
}

void ofApp::plot(vector<float>& buffer, float scale) {
    ofNoFill();
    int n = MIN(1024, buffer.size());
    ofDrawRectangle(0, 0, n, scale);
    ofPushMatrix();
    ofTranslate(0, scale);
    ofScale(1, -scale);
    ofBeginShape();
    for (int i = 0; i < n; i++) {
        ofVertex(i, buffer[i]);
    }
    ofEndShape();
    ofPopMatrix();
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

    for (int i = 0; i < 10; ++i) {
        Particle p = Particle(ofColor::blue,
                              ofVec3f(1),
                              ofVec3f(x, y, 0),
                              ofVec3f(ofRandom(-10, 10),
                                      ofRandom(-10, 10),
                                      ofRandom(-10, 10)),
                              ofVec3f(ofRandom(-10, 10),
                                      ofRandom(-10, 10),
                                      ofRandom(-10, 10)));
        particles.push_back(p);
    }
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
