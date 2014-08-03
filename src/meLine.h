//
//  meLine.h
//  mapEditClean
//
//  Created by seoha on 2014. 7. 14..
//
//

#ifndef __mapEditClean__meLine__
#define __mapEditClean__meLine__

#include <iostream>
#include "mePoint.h"
#include "ofMain.h"
class meLine{
private:
    mePoint *start;
    mePoint *end;
    bool active;
public:
    meLine(mePoint s, mePoint e){
        start = new mePoint(s.getX(),s.getY());
        end = new mePoint(e.getX(),e.getY());
        active = false;
        
    }
    mePoint getS(){
        return *start;
    }
    mePoint getE(){
        return *end;
    }
    bool checkActive(){
        return active;
    }
    float distFromPoint(float &mX,float &mY,float x,float y, float sd, float corX, float corY, int beyul);
    
    
};


#endif /* defined(__mapEditClean__meLine__) */
