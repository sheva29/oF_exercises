//
//  Ship.h
//  spaceGame
//
//  Created by J. Matthew Griffis on 10/4/13.
//
//

#pragma once
#include "ofMain.h"

class Ship {
public:
    Ship();
    
    void setup();
    
    void applyForce(ofVec2f force);
    void fireTheEngines();
    void faceWhichWay();
    void pacMan();
    
    void update();
    void draw();
    
    ofVec2f pos, vel, accel;
    
    // Deceleration and acceleration.
    float damping, gasPedal;
    
    // Angle facing.
    float currentAngle, direction, angleVel;
    
    float wide, tall, mass;
    
    ofColor c;
    
    // Allow player-controlled movement.
    bool up, down, left, right;
    
};