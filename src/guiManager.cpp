//
//  guiManager.cpp
//  mapEditClean
//
//  Created by Nicholas Kwack on 2014. 8. 7..
//
//

#include "guiManager.h"

void guiManager::selectSection(float x, float y, float corX, float corY, int beyul){
    selectedSection = MSM->pointToSection(x, y, corX, corY, beyul);
    gui->setPosition((int)x, (int)y);
    gui->setVisible(true);
    ofxUITextInput* in = (ofxUITextInput *)gui->getWidget("NAME");
    //string temp = selectedSection->getName();
    //in->setTextString(temp);
}