#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    counter = -1;
    itr = 0;
    nextVal = broadcastTimes[itr];
    
    ofSetFrameRate(60);
    ofBackground(0,0,0);
    ofSetColor(0,0,0);
    
    ofNoFill();
    ofSetLineWidth(2);
    
    circCount = 0;
    
    img.load("mapInverted.png");
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int i=0;
    
    while(i<4){
    
    if(counter < yearLen){
        counter++;
    } else {
        counter = 0;
        itr = 0;
        nextVal = broadcastTimes[itr];
    }
    
    trigger = false;
    
    if(counter == nextVal){
        trigger = true;
        
        int j = itr*5;
        
        trig[0+i] = broadcastLoc[j];
        j++;
        trig[1+i] = broadcastLoc[j];
        j++;
        trig[2+i] = broadcastLoc[j];
        j++;
        trig[3+i] = broadcastLoc[j];
        j++;
        trig[4+i] = broadcastLoc[j];
        
        itr++;
        nextVal = broadcastTimes[itr];
    }
    
    if(trigger){
        
        if(trig[0] != 0){
            int x = trig[0+i];
            activeCircles[circCount][0] = countryCoords[x][0];
            activeCircles[circCount][1] = countryCoords[x][1];
            activeCircles[circCount][2] = 0;
            activeCircles[circCount][3] = 255;
            if(circCount < 79){
                circCount++;
            } else {
                circCount = 0;
            }
        }
        if(trig2 != 0){
            int x = trig[1+i];
            activeCircles[circCount][0] = countryCoords[x][0];
            activeCircles[circCount][1] = countryCoords[x][1];
            activeCircles[circCount][2] = 0;
            activeCircles[circCount][3] = 255;
            if(circCount < 79){
                circCount++;
            } else {
                circCount = 0;
            }
        }
        if(trig3 != 0){
            int x = trig[2+i];
            activeCircles[circCount][0] = countryCoords[x][0];
            activeCircles[circCount][1] = countryCoords[x][1];
            activeCircles[circCount][2] = 0;
            activeCircles[circCount][3] = 255;
            if(circCount < 79){
                circCount++;
            } else {
                circCount = 0;
            }
        }
        if(trig4 != 0){
            int x = trig[3+i];
            activeCircles[circCount][0] = countryCoords[x][0];
            activeCircles[circCount][1] = countryCoords[x][1];
            activeCircles[circCount][2] = 0;
            activeCircles[circCount][3] = 255;
            if(circCount < 79){
                circCount++;
            } else {
                circCount = 0;
            }
        }
        if(trig5 != 0){
            int x = trig[4+i];
            activeCircles[circCount][0] = countryCoords[x][0];
            activeCircles[circCount][1] = countryCoords[x][1];
            activeCircles[circCount][2] = 0;
            activeCircles[circCount][3] = 255;
            if(circCount < 79){
                circCount++;
            } else {
                circCount = 0;
            }
        }
        
    }
        
        i++;
        
    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate((ofGetWidth()-1425)/2, (ofGetHeight()-742)/2, 0);
    
    ofSetColor(255,255,255);
    img.draw(0,0);
    
    ofFill();
    for (int i = 0; i < 143; i++){
        for(int j = 0; j < 75; j++){
            int c = ofRandom(0,20);
            ofSetColor(255,255,255,c);
            ofDrawRectangle(i*10,j*10,10,10 );
        }
    }
    ofNoFill();
    
    ofSetColor(255,255,255);
    
   // ofDrawBitmapString(counter, 10,0);
    
    int dayTime = counter%1440;
    int date = counter/1440 + 1;
    
    string month = "";
    
    if (date <= 31){
        month = "January";
    } else if(date <= 60){
        month = "February";
        date -= 31;
    } else if(date <= 91){
        month = "March";
        date -= 60;
    } else if(date <= 121){
        month = "April";
        date -= 91;
    } else if(date <= 152){
        month = "May";
        date -= 121;
    } else if(date <= 182){
        month = "June";
        date -= 152;
    } else if(date <= 213){
        month = "July";
        date -= 182;
    } else if(date <= 244){
        month = "August";
        date -= 213;
    } else if(date <= 274){
        month = "September";
        date -= 244;
    } else if(date <= 305){
        month = "October";
        date -= 274;
    } else if(date <= 335){
        month = "November";
        date -= 305;
    } else {
        month = "December";
        date -= 335;
    }
    
    ofDrawBitmapString( "Number station broadcasts, " + month + " " + to_string(date) + ", 2016 " + to_string(dayTime/60) + ":" + to_string(dayTime%60), 5, 770);
    ofDrawBitmapString( "1 circle = 1 message", 5, 790);
    
    
    /*
    ofDrawBitmapString(countryKeys[trig1], 10,100);
    
    if(countryKeys[trig2] != "na") ofDrawBitmapString(countryKeys[trig2], 10,120);
    if(countryKeys[trig3] != "na") ofDrawBitmapString(countryKeys[trig3], 10,140);
    if(countryKeys[trig4] != "na") ofDrawBitmapString(countryKeys[trig4], 10,160);
    if(countryKeys[trig5] != "na") ofDrawBitmapString(countryKeys[trig5], 10,180);
    */
     
    int i = 0;
    while(i < 80){
        
        if(activeCircles[i][0] != 0){
            activeCircles[i][3] -= 3;
            if(activeCircles[i][3] <= 0){
                activeCircles[i][0] = 0;
                activeCircles[i][1] = 0;
                activeCircles[i][2] = 0;
                activeCircles[i][3] = 0;
            } else {
                activeCircles[i][2] += 5;
                ofSetColor(255,255,255,activeCircles[i][3]);
                ofDrawCircle(activeCircles[i][0],activeCircles[i][1],activeCircles[i][2]);
            }
        }
        
        i++;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
