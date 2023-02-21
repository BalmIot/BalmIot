#ifndef BALMIOT
#define BALMIOT
#include "Arduino.h"
#include "HTTPClient.h"

class BalmIot{
    
	private:
		String BalmIotjson(String json, String name);

    public:
        String BalmIot_get(const char * s,const char * t);
		String BalmIot_up(const char * s,const char * t,const char * m);
		String BalmIot_time();
};

#endif
