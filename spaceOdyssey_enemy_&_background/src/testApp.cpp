#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofBackground(255, 0);
    enemy.setup();
    imageCounter = 0;
    
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    gif.loadImage("metroid.gif");

}

//--------------------------------------------------------------
void testApp::update(){
    imageCounter++;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //This allows us to save the information of the fbo in a pixel buffer.
    {
    fbo.begin();
    pix.clear();
    ofClear(0,0,0,0);
    enemy.draw();
    fbo.end();
    
    fbo.readToPixels(pix);
    ofSaveImage(pix, ofToString(imageCounter) + ".png");
//   ofSaveScreen(ofToString(imageCounter) + ".png");
    fbo.draw(0,0);
    }
    ofSetRectMode(OF_RECTMODE_CORNER);
//    gif.draw(0, 0);

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
