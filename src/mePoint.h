//
//  mePoint.h
//  mapEditClean
//
//  Created by seoha on 2014. 7. 14..
//
//

#ifndef __mapEditClean__mePoint__
#define __mapEditClean__mePoint__

#include <iostream>
#include "meMath.h"
class mePoint{
private:
    float x;
    float y;
public:
    mePoint(float xx,float yy){
        x = xx;
        y = yy;
    }
    float getX() const { return x;}
    float getY() const { return y;}
    mePoint(float corX, float corY,float xx, float yy, int beyul){
        x =corX+(xx*100/beyul);
        y =corY+(yy*100/beyul);
    }
    float getXByCor(float corX, int beyul){
        return (x-corX)*beyul/100;
    }
    float getYByCor(float corY, int beyul){
        return (y-corY)*beyul/100;
    }
    float dot(const mePoint &mp){
        return (x* mp.getX())+(y*mp.getY());
    }
    mePoint sub(mePoint &mp){
        return mePoint(x-mp.getX(),y-mp.getY());
    }
    static bool intersect(mePoint as,mePoint ae, mePoint bs, mePoint be){
        float x1 = as.getX(), x2 = ae.getX(), x3 = bs.getX(), x4 = be.getX();
        float y1 = as.getY(), y2 = ae.getY(), y3 = bs.getY(), y4 = be.getY();
        
        float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        // If d is zero, there is no intersection
        if (d == 0) return false;
        
        // Get the x and y
        float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
        float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
        float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
        
        // Check if the x and y coordinates are within both lines
        if ( x < meMath::min(x1, x2) || x > meMath::max(x1, x2) ||
            x < meMath::min(x3, x4) || x > meMath::max(x3, x4) ) return false;
        if ( y < meMath::min(y1, y2) || y > meMath::max(y1, y2) ||
            y < meMath::min(y3, y4) || y > meMath::max(y3, y4) ) return false;
        
        return true;
        
    }
    static float XbyCor(float mouseX, float corX, int beyul){
        return (mouseX-corX)*beyul/100;
    }
    static float YbyCor(float mouseY, float corY, int beyul){
        return (mouseY-corY)*beyul/100;
    }
    
};

#endif /* defined(__mapEditClean__mePoint__) */
