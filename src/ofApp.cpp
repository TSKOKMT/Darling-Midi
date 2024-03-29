#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetWindowShape(ofGetScreenWidth() * (16 / 18.), ofGetScreenWidth() / 2.);
    ofSetWindowPosition((ofGetScreenWidth() - ofGetWidth()) / 2., (ofGetScreenHeight() - ofGetHeight()) / 2.);
    ofBackground(0);
    ofSetCircleResolution(128);
    
    midiIn.openPort(0);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle("Darling Midi | " + ofToString(round(ofGetFrameRate())));
    
    if (midiIn.hasWaitingMessages()) {
        ofxMidiMessage message;
        midiIn.getNextMessage(message);
        if (message.control == 17) rotationL = message.value / 128. * TWO_PI;
        if (message.control == 16) rotationR = message.value / 128. * TWO_PI;
        if (message.pitch == 60) myDarlingApp.button01();
        if (message.pitch == 61) myDarlingApp.button02();
        if (message.pitch == 62) myDarlingApp.button03();
        cout << message.value << ", " << message.pitch << ", " << message.control << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    auto frame = ofGetWindowRect();
    
    auto time = ofGetElapsedTimef();
    
    auto unit = sqrt(frame.width * frame.height) / 120.;
    
    float radius = 30 * unit;
    
    int res = 30;
    
    ofPushMatrix();
    ofTranslate(frame.getCenter() - ofPoint(radius, 0));
    ofRotateRad(rotationL);
    ofBeginShape();
    for (int i = 0; i <= res; i++) {
        float theAngle = ofMap(i, 0, res, 0, PI);
        ofVertex(cos(theAngle) * radius, sin(theAngle) * radius);
    }
    ofEndShape(true);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(frame.getCenter() + ofPoint(radius, 0));
    ofRotateRad(rotationR);
    ofBeginShape();
    for (int i = 0; i <= res; i++) {
        float theAngle = ofMap(i, 0, res, 0, PI);
        ofVertex(cos(theAngle) * radius, sin(theAngle) * radius);
    }
    ofEndShape(true);
    ofPopMatrix();
    
    //myDarlingApp.draw(frame, time);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') myDarlingApp.button01();
    if (key == OF_KEY_UP) myDarlingApp.button02();
    if (key == OF_KEY_DOWN) myDarlingApp.button03();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
