#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    for (int i = 0; i < 1; i++) {
        Ball tmp;
        redBall.push_back(tmp);
    }
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for( int i = 0; i < redBall.size(); i++){
        
        ofPoint mousePos = ofPoint(mouseX,mouseY);
        redBall[i].pos.y = ofGetWindowHeight()/2;
        
        if( mousePos.x < (ofGetWindowWidth()/10)){
            
            redBall[i].pos.x = (ofGetWindowWidth()/20);
            
        }else if ( mousePos.x > (ofGetWindowWidth()/10) && mousePos.x < (ofGetWindowWidth()/10) * 2){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 3);
        
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 2 && mousePos.x < (ofGetWindowWidth()/10) * 3){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 5);
        
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 4 && mousePos.x < (ofGetWindowWidth()/10) * 5){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 9);
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 5 && mousePos.x < (ofGetWindowWidth()/10) * 6){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 11);
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 6 && mousePos.x < (ofGetWindowWidth()/10) * 7){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 13);
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 7 && mousePos.x < (ofGetWindowWidth()/10) * 8){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 15);
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 8 && mousePos.x < (ofGetWindowWidth()/10) * 9){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 17);
        }else if ( mousePos.x > (ofGetWindowWidth()/10) * 9 && mousePos.x < ofGetWindowWidth()){
            
            redBall[i].pos.x = ((ofGetWindowWidth()/20) * 19);
        }

    }
  

}

//--------------------------------------------------------------
void testApp::draw(){

    for( int i = 0; i < ofGetWindowWidth(); i += 103){
        
        float newColor;
        newColor = ofMap(i, 0, 1024, 0, 255);
        ofSetColor(newColor);
        ofRect( i, 0, 103, 768);
        
    }
    
    for( int i = 0; i < redBall.size(); i++){
       
        redBall[i].draw();
        
        
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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