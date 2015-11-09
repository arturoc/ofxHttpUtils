#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	action_url = "http://localhost/of-test/upload.php";
	ofAddListener(httpUtils.newResponseEvent,this,&ofApp::newResponse);
	httpUtils.start();

	ofBackground(255,255,255);
	ofSetColor(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBitmapString(requestStr,20,20);
	ofDrawBitmapString(responseStr,20,60);
}

//--------------------------------------------------------------
void ofApp::newResponse(ofxHttpResponse & response){
	responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	ofxHttpForm form;
	form.action = action_url;
	form.method = OFX_HTTP_POST;
	form.addFormField("number", ofToString(counter));
	form.addFile("file","ofw-logo.gif");
	httpUtils.addForm(form);
	requestStr = "message sent: " + ofToString(counter);
	counter++;
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
void ofApp::windowResized(int w, int h){

}

