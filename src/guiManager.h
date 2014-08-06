//
//  guiManager.h
//  mapEditClean
//
//  Created by Nicholas Kwack on 2014. 8. 7..
//
//

#ifndef __mapEditClean__guiManager__
#define __mapEditClean__guiManager__

#include <stdio.h>
#include "ofxUI.h"
#include "meSectionManager.h"
#include "mePoint.h"

class guiManager{
public:
    meSectionManager* MSM;
    ofxUICanvas* gui;
    meSection* selectedSection;
    
    guiManager(meSectionManager* MSM, ofxUICanvas* gui){
        this->MSM = MSM;
        this->gui =gui;
        
        gui->addTextInput("NAME", "default");
        gui->autoSizeToFitWidgets();
        gui->setVisible(false);
    }
    
    void selectSection(float x, float y, float corX, float corY, int beyul);
};

class guiObject{
public:
    enum guiType{SECTION_CONFIG, BUILDING_CONFIG};
    guiType _guiType;
    float xPos;
    float yPos;
    meSection* section;
    
    guiObject(guiType _guiType, float xPos, float yPos, meSection* section){
        this->xPos = xPos;
        this->yPos = yPos;
        this->_guiType = _guiType;
        this->section = section;
    }
    
    void display(){
        
    }
    
};

#endif /* defined(__mapEditClean__guiManager__) */
