//
//  Particle.hpp
//  ParticleSystemOfADown
//
//  Created by Shawn Lawson on 9/19/17.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"

class Particle {

public:
    ofColor color;
    ofVec3f scale;
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    
    Particle();
    Particle(ofColor c,
             ofVec3f s,
             ofVec3f p,
             ofVec3f v,
             ofVec3f a
             );
    
    void update();
    void draw();
    
};



#endif /* Particle_hpp */
