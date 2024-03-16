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
        if (message.pitch == 73) darlingApp.shuffle();
        if (message.pitch == 74) darlingApp.bigger();
        if (message.pitch == 75) darlingApp.smaller();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    auto frame = ofGetWindowRect();
    
    auto time = ofGetElapsedTimef();
    
    darlingApp.draw(frame, time);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') darlingApp.shuffle();
    if (key == OF_KEY_UP) darlingApp.bigger();
    if (key == OF_KEY_DOWN) darlingApp.smaller();
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
