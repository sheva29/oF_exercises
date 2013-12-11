#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofEnableAlphaBlending();
//    ofHideCursor(); // Doesn't work.
    
    // Background
    // Black
    ofBackground( 0 );
    
    myShip.setup();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    myShip.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myShip.draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch ( key ) {
            
            // Reset
        case 'r':
        case 'R':
            setup();
            break;
            
            // Move up.
        case 'w':
        case 'W':
            myShip.up = true;
            break;
            
            // Move left.
        case 'a':
        case 'A':
            myShip.left = true;
            break;
            
            // Move down.
        case 's':
        case 'S':
            myShip.down = true;
            break;
            
            // Move right.
        case 'd':
        case 'D':
            myShip.right = true;
            break;
            
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    switch ( key ) {
            
            // Stop moving up.
        case 'w':
        case 'W':
            myShip.up = false;
            break;
            
            // Stop moving left.
        case 'a':
        case 'A':
            myShip.left = false;
            break;
            
            // Stop moving down.
        case 's':
        case 'S':
            myShip.down = false;
            break;
            
            // Stop moving right.
        case 'd':
        case 'D':
            myShip.right = false;
            break;
            
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
