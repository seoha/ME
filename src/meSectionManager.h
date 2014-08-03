//
//  meSectionManager.h
//  mapEditClean
//
//  Created by seoha on 2014. 7. 31..
//
//

#ifndef __mapEditClean__meSectionManager__
#define __mapEditClean__meSectionManager__

#include <iostream>
#include "ofMain.h"
#include "mePoint.h"
#include "meLine.h"
#include "meSection.h"

class meSectionManager{
private:
    meSectionLeaf* map;
    meSectionLeaf* currentMother;
public:
    vector<mePoint> tempPoints;
    meSectionManager(){
    
        tempPoints.push_back(mePoint(0,0));
        tempPoints.push_back(mePoint(0,600));
        tempPoints.push_back(mePoint(900,600));
        tempPoints.push_back(mePoint(900,0));
        
        map = new meSectionLeaf(tempPoints);
        tempPoints.clear();
    }
    bool saveWithValidation(vector<mePoint> p);
    bool validatePoint(mePoint point);
    void draw(float corX, float corY, int beyul,float meX, float meY){
        
        map->draw(corX,corY,beyul,200);
        
        ofSetColor(255,0,0);
        for(int i =1; i< tempPoints.size(); i++){
            ofLine(tempPoints[i].getXByCor(corX, beyul),tempPoints[i].getYByCor(corY, beyul),
                   tempPoints[i-1].getXByCor(corX, beyul),tempPoints[i-1].getYByCor(corY, beyul));
            
        }
        if(tempPoints.size()>0){
            
    
        ofLine(meX,meY,
               tempPoints[tempPoints.size()-1].getXByCor(corX, beyul),tempPoints[tempPoints.size()-1].getYByCor(corY, beyul));
        }
        
    }
    string status(float mouseX,float mouseY);
    void clear(){
        tempPoints.clear();
    }
    
    
    
};



#endif /* defined(__mapEditClean__meSectionManager__) */
