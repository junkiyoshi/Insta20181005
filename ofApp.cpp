#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int radius = 36;
	for (int x = radius; x < ofGetHeight(); x += radius * 2) {

		for (int y = radius; y < ofGetHeight(); y += radius * 2) {

			ofPushMatrix();
			ofTranslate(x, y);

			int deg_start = ofMap(ofNoise(x * 0.05, ofGetFrameNum() * 0.005), 0, 1, 0, 720);
			int deg_end = ofMap(ofNoise((y + radius) * 0.05, ofGetFrameNum() * 0.005), 0, 1, 0, 720);
			if (deg_start > deg_end) { std::swap(deg_start, deg_end); }

			ofFill();
			ofBeginShape();
			for (int deg = deg_start; deg < deg_end; deg += 5) {

				ofVertex(radius * 0.85 * cos(deg * DEG_TO_RAD), radius * 0.85 * sin(deg * DEG_TO_RAD));
			}
			if (deg_end - deg_start < 180) { ofVertex(0, 0); }
			ofEndShape(true);

			ofNoFill();
			ofBeginShape();
			for (int deg = 0; deg < 360; deg += 5) {

				ofVertex(radius * 0.95 * cos(deg * DEG_TO_RAD), radius * 0.95 * sin(deg * DEG_TO_RAD));
			}
			ofEndShape(true);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}