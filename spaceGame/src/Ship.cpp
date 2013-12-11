//
//  Ship.cpp
//  spaceGame
//
//  Created by J. Matthew Griffis on 10/4/13.
//
//

#include "Ship.h"

//--------------------------------------------------------------
Ship::Ship() {
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
}

//--------------------------------------------------------------
void Ship::setup() {
    
    // White
    c = ofColor( 255 );
    
    // Centered
    pos.x = ofGetWidth() * 0.5f;
    pos.y = ofGetHeight() * 0.5f;
    
    // Size
    wide = 25.0f;
    tall = 2.0 * wide;
    mass = 1.0f;
    
    // Speed defaults.
    vel.x = vel.y = 0.0f;
    accel.x = accel.y = 0.0f;
    damping = 0.99f;
    
    // Movement acceleration speed.
    gasPedal = 0.3f;
    
    currentAngle = direction = 90;
    angleVel = 5;
    
    // Movement defaults.
    up = down = left = right = false;
    
}

//--------------------------------------------------------------
void Ship::applyForce(ofVec2f force){
    
    // Newton in the house. F = ma
    
    accel += (force / mass);
    
}

//--------------------------------------------------------------
void Ship::fireTheEngines() {
    
    // Move on the player's command.
    
    if ( up ) {
        applyForce( ofVec2f( 0.0f, -gasPedal ));
    }
    if ( left ) {
        applyForce( ofVec2f( -gasPedal, 0.0f ));
    }
    if ( down ) {
        applyForce( ofVec2f( 0.0f, gasPedal ));
    }
    if ( right ) {
        applyForce( ofVec2f( gasPedal, 0.0f ));
    }
    
}

//--------------------------------------------------------------
void Ship::faceWhichWay() {
    
    // Calculate the angle of the direction the ship should be facing.
    if ( up ) {
        if ( left ) {
            direction = 90 + ( 90 / 2 );
        } else if ( right ) {
            direction = 90 - ( 90 / 2 );
        } else {
            direction = 90;
        }
    } else if ( down ) {
        if ( left ) {
            direction = 270 - ( 90 / 2 );
        } else if ( right ) {
            direction = 270 + ( 90 / 2 );
        } else {
            direction = 270;
        }
    } else if ( left ) {
        direction = 180;
    } else if ( right ) {
        direction = 0;
    }
    
    
    // Get to the destination angle.
    if ( currentAngle != direction ) {
        // Calculate the fastest way to get to the destination angle. This is stupidly complicated because it's necessary to account for crossing the 0 / 360 line.
        float diff = direction - currentAngle;
        if ( fabs( diff ) < 180 ) {
            if ( diff > 0 ) {
                currentAngle += angleVel;
            } else if ( diff < 0 ) {
                currentAngle -= angleVel;
            }
        } else if ( fabs( diff ) > 180 ){
            if ( diff > 0 ) {
                currentAngle -= angleVel;
            } else if ( diff < 0 ) {
                currentAngle += angleVel;
            }
        } else {
            if ( ofRandom( 1 ) < 0.5f ) {
                currentAngle += angleVel;
            } else {
                currentAngle -= angleVel;
            }
        }
    }
    
    
    // Keep the angle from growing or shrinking out of bounds.
    if ( currentAngle < 0 ) {
        currentAngle = 360;
    } else if ( currentAngle > 360 ) {
        currentAngle = 0;
    }
    
}

//--------------------------------------------------------------
void Ship::pacMan() {
    
    // Go offscreen, Pac-Man to the other side
    
    // x
    if ( pos.x < -( wide * 0.5 ) ) {
        pos.x = ofGetWidth() + ( wide * 0.5 );
    } else if ( pos.x > ofGetWidth() + ( wide * 0.5 ) ) {
        pos.x = -( wide * 0.5 );
    }
    
    // y
    if ( pos.y < -( tall * 0.5 ) ) {
        pos.y = ofGetHeight() + ( tall * 0.5 );
    } else if ( pos.y > ofGetHeight() + ( tall * 0.5 ) ) {
        pos.y = -( tall * 0.5 );
    }
    
}

//--------------------------------------------------------------
void Ship::update() {
    
    // Handle player movement-input.
    fireTheEngines();
    
    // Face the right way.
    faceWhichWay();
    
    vel += accel;
    pos += vel;
    
    // Handle offscreen.
    pacMan();
    
    // Reset acceleration each frame so we only accelerate when force is applied.
    accel.set(0);
    
    // Slow down (acts like friction).
    vel *= damping;
    
    // Interestingly, it seems the damping force removes the need to set a max speed. Speed tops out at just shy of 30. Put the following in the draw to see it.
//    ofDrawBitmapString(ofToString(vel.x), 10, 10);
    
}

//--------------------------------------------------------------
void Ship::draw() {
    
    ofSetColor(c);
    
    ofPushMatrix();{
        ofTranslate( pos );
        ofRotate( -currentAngle ); // Rotate in the direction of movement.
        ofTriangle( tall / 2, 0.0, -tall / 2, -wide / 2, -tall / 2, wide / 2 );
    }ofPopMatrix();
    
}

//--------------------------------------------------------------