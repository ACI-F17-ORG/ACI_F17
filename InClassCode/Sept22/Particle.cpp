//
//  Particle.cpp
//  ParticleSystemOfADown
//
//  Created by Shawn Lawson on 9/19/17.
//
//

#include "Particle.hpp"

Particle::Particle(){
    Particle(ofColor::hotPink,
             ofVec3f(1, 1, 1),
             ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0),
             ofVec3f(0, 0, 0),
             ofVec3f(0, 0, 0));
}

Particle::Particle(ofColor c,
                     ofVec3f s,
                     ofVec3f p,
                     ofVec3f v,
                     ofVec3f a){
    color = c;
    scale = s;
    position = p;
    velocity = v;
    acceleration = a;
    
}

void Particle::update(){
    velocity += acceleration;
    velocity.limit(50);
    position += velocity;
}

void Particle::draw(){
    ofTranslate(position);
    //would like to rotate!!
    ofSetColor(color);
}

















