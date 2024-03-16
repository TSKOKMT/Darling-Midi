#pragma once

#include "ofMain.h"

class darlingApp {

public:
    darlingApp();
    void draw(ofRectangle frame_, float time_);
    void align(int countH_, int countV_, float spacing_);
    
    void shuffle();
    void bigger();
    void smaller();

private:
    void drawApp(ofPoint position_, float radius_, float rotation_, int id_);
    
    int resolution = 120;
    
    vector<int> ids;
    vector<ofPoint> points;
    vector<float> terms;
    vector<ofColor> colors;
    
    int countH;
    int countV;
    
    float spacing = 12;
};
