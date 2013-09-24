//
//  Ball.cpp
//  emptyExample
//
//  Created by Mauricio Sanchez Duque on 9/23/13.
//
//

#include "Ball.h"


Ball::Ball(){
    
}

void Ball::draw(){
    
    ofSetColor( 255, 0 , 0);
    ofCircle(pos.x, pos.y, 25);
    
    
    
}
