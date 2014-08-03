#pragma once

#include "ofMain.h"
#include "mePoint.h"
#include "meLine.h"
#include "meSectionManager.h"
#include "json/json.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    //mouseReleased
    void RulerMouseReleased(int x, int y, int button);
    void MSMMouseReleased(int x, int y, int button);
    
    //draw
    void RulerDraw();
    void MSMDraw();
    
    //
    void meMouseCalibrate(float x, float y);
    ofTrueTypeFont font;
    vector<mePoint> tempPoints;
    float corX, corY;
    int beyul;
    vector<meLine> Lines;
    string stateString[3];
    bool shift;
    float meX;
    float meY;
    meSectionManager MSM;
    enum Tool{CURSOR, RULER, SECTION};
    Tool selectedTool;
};
