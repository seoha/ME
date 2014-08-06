//
//  meMath.h
//  mapEditClean
//
//  Created by seoha on 2014. 8. 2..
//
//

#ifndef mapEditClean_meMath_h
#define mapEditClean_meMath_h

#include "ofMain.h"
#include "mePoint.h"

class meMath{
public:
    
    static float min(float x, float y){
        if(x>y) return y;
        else return x;
    }
    static float max(float x, float y){
        if(x>y) return x;
        else return y;
    }
};

#endif

