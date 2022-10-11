#include "BalmIot.h"

String BalmIot::BalmIot_get(const char * s,const char * t)
{
	String v = s;
	String q = v.substring(v.indexOf("$") + 1, v.indexOf("_"));
    String k = v.substring(v.indexOf("_")+ 1);
	String nq = String(".");
	String al = String("app");
	String ad = String("com");
	String p = String("/data/rec");
	String aa = String("airtable");
	String f = String("id");
	String z = String(f + t);
	String aq = String("Aut");
	String mq = String("/");
	String an = String("horiz");
	String ak = String("https:");
	String ae = String("ation");
	String b = String(aq + an +ae);
	String ab = String("Bearer ");
	String ar = String("key");
	String az = String(ab + ar);
	String ax = String("Lwysy7R");
	String g = String("7EmODc1");
	String av = String("ไม่สามารถเชื่อมต่อได้");
	String as = String("error");
	String ap = String("api");
	String at = String("NOT_FOUND");
	String af = String("v0");
	String ai = String("serverkey");
	String ay = String(az + ax + g);
	String l = String(ak + mq + mq + ap + nq + aa + nq + ad + mq + af + mq + al + q + p + k);
	HTTPClient http;
	http.begin(l);
	http.addHeader(b,ay);
	int o = http.GET();
	if(o > 0) 
		{
		String n = http.getString();
		http.end();
		String aw = BalmIotjson(n,as);
		if(aw == at) 
			{
			String d = String(av);
			return d;
			}
		else
			{
			String d = BalmIotjson(n,z);
			String au = BalmIotjson(d,ai);
			if(v == au) 
				{
				String d = String(av);
				return d;
				}
			else
				{
				return d;
				}
			}
		}
}

String BalmIot::BalmIot_up(const char * s,const char * t,const char * m)
{
	String v = s;
	String q = v.substring(v.indexOf("$") + 1, v.indexOf("_"));
    String k = v.substring(v.indexOf("_")+ 1);
	String h = String("{\"records\":\[{\"id\":\"rec");
	String aq = String("Aut");
	String mq = String("/");
	String ak = String("https:");
	String ah = String("Content");
	String ad = String("com");
	String af = String("application");
	String am = String("v0");
	String u = String("data");
	String f = String("id");
	String z = String(f + t);
	String nq = String(".");
	String x = String("\",\"fields\":\{\"");
	String p = String(mq + u);
	String y = String("\":\"");
	String ap = String("api");
	String an = String("horiz");
	String ae = String("ation");
	String b = String(aq + an +ae);
	String ab = String("Bearer ");
	String e = String("\"}}]}");
	String ar = String("key");
	String az = String(ab + ar);
	String ax = String("Lwysy7R");
	String aa = String("airtable");
	String g = String("7EmODc1");
	String ai = String("type");
	String j = String(h + k + x + z + y + m + e);
	String ao = String("fields");
	String av = String("ไม่สามารถเชื่อมต่อได้");
	String at = String("INVALID_RECORDS");
	String au = String("records");
	String al = String("app");
	String ay = String(az + ax + g);
	String aj = String("-Type");
	String r = String(ah + aj);
	String ag = String("json");
	String w = String(af + mq + ag);
	String l = String(ak + mq + mq + ap + nq + aa + nq + ad + mq + am + mq + al + q + p);
	HTTPClient http;
	http.begin(l);
	http.addHeader(b,ay);
	http.addHeader(r,w);
	int o = http.PATCH(j);
	if(o > 0) 
		{
		String n = http.getString();
		http.end();
		String aw = BalmIotjson(n,ai);
		if(aw == at) 
			{
			String d = String(av);
			return d;
			}
		else
			{
			String a = BalmIotjson(n,au);
			String c = BalmIotjson(a,ao);
			String d = BalmIotjson(c,z);
			return d;
			}
		}
}

String BalmIot::BalmIotjson(String json, String name){
  char next;
  int start, stop;
  
  name = String("\"") + name + String("\"");
  start = json.indexOf(name) + name.length() + 1;
  next = json.charAt(start);
  if(next == '\"'){
    start = start + 1;
    stop = json.indexOf('"', start + 1);
  }
  else if(next == '['){
    int count = 1;
    int i = start;
    while(count > 0 && i++ < json.length()){
      if(json.charAt(i) == ']'){
	count--;
      }
      else if(json.charAt(i) == '['){
	count++;
      }
    }
    stop = i + 1;
  }
  else if(next == '{'){
    int count = 1;
    int i = start;
    while(count > 0 && i++ < json.length()){
      if(json.charAt(i) == '}'){
	count--;
      }
      else if(json.charAt(i) == '{'){
	count++;
      }
    }
    stop = i + 1;
  }
  else if(next == '.' || next == '-' || ('0' <= next  && next <= '9')){
    int i = start;
    while(i++ < json.length() && json.charAt(i) == '.' || ('0' <= json.charAt(i)  && json.charAt(i) <= '9')){
    }
    stop = i;
  }
  return json.substring(start, stop);
}