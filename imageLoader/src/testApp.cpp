#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0,0,200);
    counter = 0;
    frameNum = 0;
    for( int i =0; i < 50; i++){
        
        string frameNum = ofToString(i);
        metroid[i].loadImage(frameNum + ".png");
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    frameNum = abs( abs(49 - counter) - 49);
    counter++;
    
    if( counter == 100){
        
        counter = 0;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    metroid[frameNum].draw(0, 0);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
