//
//  meSectionManager.cpp
//  mapEditClean
//
//  Created by seoha on 2014. 7. 31..
//
//

#include "meSectionManager.h"
#include "string.h"

bool meSectionManager::saveWithValidation(vector<mePoint> p){
    
    
    
    
    
    if(map->child == NULL){
        map->child = new meSectionLeaf(p);
        cout << "congratulations! you have a daughter\n";
    }
    else{
        int count =1;
        cout << "Oh! you already have a daugther; I will ask her\n";
        meSectionLeaf* savepoint = map->child;
        
        while(savepoint->sibling != NULL){
            savepoint = savepoint->sibling;
            count++;
            cout << "Oh! you already have a sister; I will ask her\n";
        }
        savepoint->sibling = new meSectionLeaf(p);
        cout<< "you have " << count << " siblings! good for you!\n";
        
    }
}

bool meSectionManager::validatePoint(mePoint point){
    if(tempPoints.size() == 0){
        meSectionLeaf *tempLeaf = map;
        while(tempLeaf != NULL){
            if(tempLeaf->validate(point)){
                
                currentMother = tempLeaf;
                tempLeaf = tempLeaf->child;
                
            }
            else{
                tempLeaf = tempLeaf->sibling;
            }
        }
        tempPoints.push_back(point);
        return true;
          
    }
    else{
        if(currentMother->validate(point)){
            
            meSectionLeaf *tempLeaf = currentMother->child;
            while(tempLeaf != NULL){
                if(tempLeaf->validate(point)) return false;
                tempLeaf = tempLeaf->sibling;
                
            }
            if(point.getX()== tempPoints[0].getX() && point.getY()== tempPoints[0].getY()){
                if(currentMother->child == NULL){
                    currentMother->adoptChild( new meSectionLeaf(tempPoints));
                    tempPoints.clear();
                    return true;
                }
                else{
                    tempLeaf = currentMother->child;
                    meSectionLeaf *tempSavePoint = new meSectionLeaf(tempPoints);
                    currentMother->child = NULL;
                    while(tempLeaf != NULL){
                        
                        if(tempSavePoint->validate(tempLeaf->giveone())){
                            
                            tempSavePoint->adoptChild(tempLeaf);
                        }
                        else{
                            currentMother->adoptChild(tempLeaf);
                        }
                        meSectionLeaf *t = tempLeaf->sibling;
                        tempLeaf->sibling = NULL;

                        tempLeaf = t;
                    }
                    currentMother->adoptChild(tempSavePoint);
                    tempPoints.clear();
                    return true;
                }
            }
            else{
                tempPoints.push_back(point);
                return true;
            }
            
            
            
        }
        else return false;
        
    }
    
    
}
string meSectionManager::status(float mouseX,float mouseY){
    string message = " ";
    meSectionLeaf * temp =map;
    int count = 1;
    while(temp != NULL){
        if(temp->validate(mePoint(mouseX,mouseY))){
            temp = temp->child;
            message += (ofToString(count)+" ");
            count = 1;
        }
        else{
            temp = temp->sibling;
            count++;
        }
        
    }
    return message;
    
}

meSection* meSectionManager::pointToSection(float mouseX, float mouseY, float corX, float corY, int beyul){
    mouseX = mePoint::XbyCor(mouseX, corX, beyul);
    mouseY = mePoint::YbyCor(mouseY, corY, beyul);
    
    meSectionLeaf * temp = map;
    meSectionLeaf * result = NULL;
    while(temp != NULL){
        if(temp->validate(mePoint(mouseX,mouseY))){
            result = temp;
            temp = temp->child;
        }
        else{
            result = temp;
            temp = temp->sibling;
        }
    }
    return result->me;
}










