//
//  meLine.cpp
//  mapEditClean
//
//  Created by seoha on 2014. 7. 14..
//
//

#include "meLine.h"

float meLine::distFromPoint(float &mX,float &mY,float x,float y, float sd, float corX, float corY, int beyul){
    if(fabs(start->getXByCor(corX, beyul)-x)<sd/2 && fabs(start->getYByCor(corY, beyul)-y)<sd/2){
        mX = start->getXByCor(corX, beyul);
        mY = start->getYByCor(corY, beyul);
        active = true;
        return 3;
    }
    else if(fabs(end->getXByCor(corX, beyul)-x)<sd/2 && fabs(end->getYByCor(corY, beyul)-y)<sd/2){
        mX = end->getXByCor(corX, beyul);
        mY = end->getYByCor(corY, beyul);
        active = true;
        return 3;
    }
    
    
    float a,b,c,d,dot,lq,parm,xx,yy;
    a = x - start->getXByCor(corX, beyul);
    b = y - start->getYByCor(corY, beyul);
    c = end->getXByCor(corX, beyul) - start->getXByCor(corX, beyul);
    d = end->getYByCor(corY, beyul) - start->getYByCor(corY, beyul);
    dot = (a*c) + (b*d);
    lq = (c*c) + (d*d);
    parm = dot/lq;
    
    
    if(parm < 0){
        xx = start->getXByCor(corX, beyul);
        yy = start->getYByCor(corY, beyul);
    }
    else if(parm >1){
        xx = end->getXByCor(corX, beyul);
        yy = end->getYByCor(corY, beyul);
    }
    else{
        xx = start->getXByCor(corX, beyul)+parm*c;
        yy= start->getYByCor(corY, beyul)+parm*d;
    }
    a= x-xx;
    b = y-yy;
    d= sqrt(a*a+b*b);
    if(d<5){
        active = true;
        if(d<sd){
            mX = xx;
            mY = yy;
            return d;
        }
        return sd;
    }
    else {
        active = false;
        return sd;
    }
}