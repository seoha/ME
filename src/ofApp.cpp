#include "ofApp.h"

//cake is a lie

//--------------------------------------------------------------
void ofApp::setup(){
    font.loadFont( OF_TTF_SANS,11,true,true);
    state = 0;
    stateString[0]="None";
    stateString[1] ="Ruler";
    stateString[2] ="Section";
    shift = false;
    beyul = 100;
    corX = corY = 0;
    MSM = meSectionManager();

}

//--------------------------------------------------------------
void ofApp::update(){
    meMouseCalibrate(mouseX,mouseY);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(0);
    ofFill();
    
    RulerDraw();
    MSMDraw();
    for(vector<mePoint>::iterator it = tempPoints.begin(); it != tempPoints.end(); ++it){
        ofEllipse(it->getXByCor(corX, beyul),it->getYByCor(corY, beyul),3,3);
    }
    for(vector<meLine>::iterator it = Lines.begin(); it != Lines.end(); ++it){
        if(it->checkActive()){
            ofSetColor(255,0,0);
        }
        else {
            ofSetColor(79,217,225);
        }
        ofFill();
        ofLine((it->getS()).getXByCor(corX, beyul),(it->getS()).getYByCor(corY, beyul),(it->getE()).getXByCor(corX, beyul),(it->getE()).getYByCor(corY, beyul));
        
    }
    ofSetColor(0);
	font.drawString("fps: " + ofToString((int)ofGetFrameRate()),ofGetWidth()-150,20);
    font.drawString("state: " + stateString[state],ofGetWidth()-150,40);
    font.drawString("beyul: " + ofToString(beyul),ofGetWidth()-150,60);
    font.drawString(MSM.status(mouseX,mouseY),ofGetWidth()-150,80);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f' || key =='F'){
        shift = true;
    }
    if(key == OF_KEY_LEFT){
        corX-= 10*100/beyul;
    }
    if(key == OF_KEY_RIGHT){
        corX+= 10*100/beyul;
    }
    if(key == OF_KEY_UP){
        corY-= 10*100/beyul;
    }
    if(key == OF_KEY_DOWN){
        corY+= 10*100/beyul;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'c' || key =='C'){
        state = 0;
        tempPoints.clear();
    }
    if(key == 'r' || key =='R'){
        state = 1;
        tempPoints.clear();
    }
    if(key == 's' || key =='S'){
        state = 2;
        tempPoints.clear();
    }
    if(key == 'f' || key =='F'){
        shift = false;
    }
    if(key == '.'){
        
        beyul += 10;
        if(beyul> 50000){
            beyul = 50000;
        }
    }
    if(key ==',') {
        beyul -= 10;
        if(beyul<100){
            beyul = 100;
        }
    }
    

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(state ==1){
        RulerMouseReleased(x, y, button);
    }
    else if(state ==2){
        MSMMouseReleased(x, y, button);
    }
    

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
// mouse released
void ofApp::RulerMouseReleased(int x, int y, int button){
    tempPoints.push_back(mePoint(corX,corY,meX,meY,beyul));
    if(tempPoints.size() == 2){
        Lines.push_back(meLine(tempPoints[0],tempPoints[1]));
        tempPoints.clear();
    }
    
}

void ofApp::MSMMouseReleased(int x, int y, int button){
    MSM.validatePoint(mePoint(corX,corY,meX,meY,beyul));
}



// draw
void ofApp::RulerDraw(){
    if(tempPoints.size()==1){
        ofSetColor(79,217,225);
        ofLine(tempPoints[0].getXByCor(corX,beyul),tempPoints[0].getYByCor(corY,beyul),mouseX,mouseY);
    }
    ofEllipse(meX,meY,3,3);
}

void ofApp::MSMDraw(){
    MSM.draw(corX, corY, beyul,meX,meY);
}
void ofApp::meMouseCalibrate(float x, float y){
    meX = x;
    meY = y;
    float sd = 20;
    for(vector<meLine>::iterator it = Lines.begin(); it != Lines.end(); ++it){
        sd = it->distFromPoint(meX, meY,mouseX,mouseY,sd,corX,corY,beyul);
    }
    
}
