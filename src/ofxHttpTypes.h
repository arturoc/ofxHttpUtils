/*
    ofxHttpUtils v0.3
    Chris O'Shea, Arturo, Jesus, CJ

    Modified: 16th March 2009
    openFrameworks 0.06

*/
#ifndef OFX_HTTP_TYPES
#define OFX_HTTP_TYPES


#define OFX_HTTP_GET  0
#define OFX_HTTP_POST 1

#include "ofUtils.h"
#include "boost/filesystem.hpp"

struct ofxHttpForm{


	int method;
    std::string action;
	std::string name;

    ofxHttpForm(){
    	method = OFX_HTTP_GET;
    	expectBinaryResponse = false;
    }
    ~ofxHttpForm(){
        clearFormFields();
    }

	void addHeaderField(std::string id, std::string value) {
		headerIds.push_back(id);
		headerValues.push_back(value);
	}

	// ----------------------------------------------------------------------
	void addFormField(std::string id, std::string value){
        formIds.push_back( id );
        formValues.push_back( value );
	}
	// ----------------------------------------------------------------------
	void clearFormFields(){
	    formIds.clear();
        formValues.clear();
        formFiles.clear();
	}
	// ----------------------------------------------------------------------
	void addFile(std::string fieldName, std::string path){
		formFiles[fieldName] = ofToDataPath(path);
	}

	std::string getFieldValue(std::string id){
		for(unsigned int i=0;i<formIds.size();i++){
			if(formIds[i]==id) return formValues[i];
		}
		return "";
	}

	std::vector <std::string> formIds;
	std::vector <std::string> formValues;
	std::vector <std::string> headerIds;
	std::vector <std::string> headerValues;
	std::map<std::string,std::string> formFiles;
	bool expectBinaryResponse;
};

#endif
