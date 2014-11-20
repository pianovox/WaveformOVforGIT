#pragma once

#include "ofMain.h"
#include "ofxAudioDecoder.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void dragEvent(ofDragInfo dragInfo);
	
	void loadFile(string filename);
	
	ofxAudioDecoder audio;
    vector < float > left;
    vector < float > right;
    

    
};