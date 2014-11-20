#include "ofApp.h"

void ofApp::setup() {
	ofSetVerticalSync(true);
	ofSetFrameRate(120);
	loadFile("demo.mp3");
    
    //cout << right [100]<< endl;
}

void ofApp::update() {
	
}

void ofApp::draw() {
    


    
    //    int mappedX = 0;
//    ofMap(mappedX, 0, ofGetWidth(), 1, 1000);
    
    
    int sampleSkipping = 1001 - ofClamp(mouseX, 1, 1000);
    int averageSize =  1001 - ofClamp(mouseX, 1, 1000);
    int sampleBlock = 0;
    float sampleAverage = 0;
    
    
//    for (int i = 0; i < right.size(); i = i + sampleAverage) {   //HERE IS WHERE I DRAW THE WAVEFORM USING i AS A SAMPLE SIZE
//        float height = right[i] * 400;
//        ofLine(i/sampleAverage,  400, i/sampleAverage, 400 - height);
    

    for (int i = 0; i < right.size(); i = i + averageSize)    {   // add ten to each cell
        
        float sampleBlock = 0;   //WATCH OUT NATHAN!!! Defined above as well
    
          for (int j = i; j < i + averageSize ; j = j + 1) {
              sampleBlock = sampleBlock + right[i];}
        
        float sampleAverage = sampleBlock/averageSize;
        float height = sampleAverage * 300;
        
      ofLine(i/averageSize, ofGetHeight()/2, i/averageSize, ofGetHeight()/2 - height);

    }
    
    cout << mouseY  << endl;
    
    
}

void ofApp::dragEvent(ofDragInfo dragInfo) {
	loadFile(dragInfo.files[0]);
}

void ofApp::loadFile(string filename) {
	audio.load(filename);
	
	left.clear();
	right.clear();
	
	
	const vector<float>& rawSamples = audio.getRawSamples();
	int channels = audio.getChannels();
	int n = rawSamples.size();
	for(int c = 0; c < channels; c++) {
		for(int i = c; i < n; i+= channels) {
			
            if (c == 0) left.push_back(rawSamples[i]);
            else right.push_back(rawSamples[i]);
            
            //(c == 0 ? left : right).addVertex(ofVec2f(i / channels, rawSamples[i]));
		}
	}
    
    
    
}


