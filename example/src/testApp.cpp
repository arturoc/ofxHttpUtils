#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);

	action_url = "http://localhost/of-test/upload.php";
	ofAddListener(httpUtils.newResponseEvent,this,&testApp::newResponse);
	httpUtils.start();

	ofBackground(255,255,255);
	ofSetColor(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString(requestStr,20,20);
	ofDrawBitmapString(responseStr,20,60);
}

//--------------------------------------------------------------
void testApp::newResponse(ofxHttpResponse & response){
	responseStr = ofToString(response.status) + ": " + response.responseBody;
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
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
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

