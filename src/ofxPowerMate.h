//
//  ofxPowerMate.h
//  example_simple
//
//  Created by Natxo Pedreira gonzalez on 24/11/14.
//
//

#ifndef __example_simple__ofxPowerMate__
#define __example_simple__ofxPowerMate__

#include "ofMain.h"
#include "hidapi.h"

class ofxPowerMate {
    
public:

	struct EventData{
		int direccion;
		int presionado;
	};

    ofxPowerMate();
    ~ofxPowerMate();
    
    bool conecta();
    void update(ofEventArgs & arg);

	bool connected() { return handle != NULL; }
    
    void setBrillo(int brillo);
	void setPulse(bool enabled);
	void setPulseSpeed(int speed); // [-32, 64]
    
    ofEvent<EventData> tengoInfo;

private:
  
    wchar_t wstr[256];
    unsigned char buf[7];
    int res;
    hid_device *handle = NULL;

    float elapsed;
	EventData data;
};

#endif /* defined(__example_simple__ofxPowerMate__) */
