//
//  meSection.h
//  mapEditClean
//
//  Created by seoha on 2014. 7. 26..
//
//

#ifndef __mapEditClean__meSection__
#define __mapEditClean__meSection__

#include <iostream>
#include "ofMain.h"
#include "mePoint.h"
#include "meLine.h"

class meSection{
    /*
        구획 규칙
            1.구획과 구획은 겹칠 수 없다.(포함될 수는 있다)
            2.block은 hierarchy를 가진다
            3.모든 구획은 도로와 접해야 한다
     
     
     
     
     */
private:
    vector<mePoint> points;
public:
    meSection(vector<mePoint> p){
        for(int i =0; i< p.size();i++){
            points.push_back(p[i]);
        }
        
    }
    int getNumPoint(){
        return points.size();
    }
    bool raycast(mePoint point){
        int count= 0;
        for(int i = 1; i < points.size(); i++) {
            if (mePoint::intersect(mePoint(-1,-1),point,points[i-1],points[i])) count++;
        }
        if(mePoint::intersect(mePoint(-1,-1),point,points[0],points[points.size()-1])) count ++;
        count %= 2;
        if(count == 1) return true;
        else return false;
    }
    void draw(float corX,float corY,int beyul){
        for (int i =1; i < points.size(); i++){
            ofLine(points[i].getXByCor(corX, beyul),points[i].getYByCor(corY, beyul),
                   points[i-1].getXByCor(corX, beyul),points[i-1].getYByCor(corY, beyul));
            
        }
        ofLine(points[0].getXByCor(corX, beyul),points[0].getYByCor(corY, beyul),
               points[points.size()-1].getXByCor(corX, beyul),points[points.size()-1].getYByCor(corY, beyul));
        
    }
    
    
};
class meSectionLeaf{
    
public:
    meSection *me;
    meSectionLeaf *child;
    meSectionLeaf *sibling;
    meSectionLeaf(vector<mePoint> p){
        me = new meSection(p);
        child = NULL;
        sibling = NULL;
        
    }
    bool validate(mePoint p){
        if(me->raycast(p)) return true;
        else return false;
    }
    void draw(float corX,float corY,int beyul){
        me->draw(corX,corY,beyul);
        if(child != NULL) child->draw(corX,corY,beyul);
        if(sibling != NULL) sibling->draw(corX,corY,beyul);
        
    }
    
};

#endif /* defined(__mapEditClean__meSection__) */


