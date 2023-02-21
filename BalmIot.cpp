#include "BalmIot.h"

String BalmIot::BalmIot_get(const char * s,const char * t)
{
	String v = s;
	String q = v.substring(v.indexOf("$") + 1, v.indexOf("_"));
    String k = v.substring(v.indexOf("_")+ 1);
	String nq = String(".");
	String fg = String("pat7VPmryM");
	String al = String("app");
	String ad = String("com");
	String p = String("/data/rec");
	String aa = String("airtable");
	String f = String("id");
	String yj = String("QXDxntp.5bd");
	String z = String(f + t);
	String aq = String("Aut");
	String eb = String("1a643425f2ec");
	String mq = String("/");
	String ol = String("c582a4fb2f0d");
	String an = String("horiz");
	String ak = String("https:");
	String ae = String("ation");
	String b = String(aq + an +ae);
	String th = String("5baf52951cf1");
	String ab = String("Bearer ");
	String av = String("ไม่สามารถเชื่อมต่อได้");
	String rh = String("69b97772d80");
	String as = String("error");
	String ap = String("api");
	String mn = String("0d462decba2b4d");
	String at = String("NOT_FOUND");
	String af = String("v0");
	String ai = String("serverkey");
	String ay = String(ab + fg + yj + ol + th + rh + eb + mn);
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
	String km = String("pat7VPmryM");
	String mq = String("/");
	String ak = String("https:");
	String ah = String("Content");
	String ad = String("com");
	String tg = String("QXDxntp.5bd");
	String af = String("application");
	String am = String("v0");
	String fv = String("c582a4fb2f0d");
	String u = String("data");
	String f = String("id");
	String z = String(f + t);
	String rd = String("5baf52951cf1");
	String nq = String(".");
	String x = String("\",\"fields\":\{\"");
	String p = String(mq + u);
	String y = String("\":\"");
	String ws = String("69b97772d80");
	String ap = String("api");
	String an = String("horiz");
	String ae = String("ation");
	String zs = String("1a643425f2ec");
	String b = String(aq + an +ae);
	String ab = String("Bearer ");
	String e = String("\"}}]}");
	String aa = String("airtable");
	String uj = String("0d462decba2b4d");
	String ai = String("type");
	String j = String(h + k + x + z + y + m + e);
	String ao = String("fields");
	String av = String("ไม่สามารถเชื่อมต่อได้");
	String at = String("INVALID_RECORDS");
	String au = String("records");
	String al = String("app");
	String ay = String(ab + km + tg + fv + rd + ws + zs + uj);
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

String BalmIot::BalmIot_time()
{
   String b = String("time");
   String h = String("/");
   String l = String("current");
   String n = String("zone");
   String f = String("io");
   String j = String("www");
   String q = String("Asia");
   String c = String("api");
   String e = String("Bangkok");
   String g = String(".");
   String p = String("https:");
   String m = String("=");
   String i = String("?");
   String k = String(p + h + h + j + g + b + c + g + f + h + c + h + b + h + l + h + n + i + b + n + m + q + h + e);
   HTTPClient http;
   http.begin(k);
   int o = http.GET();
   if(o > 0) 
   {
    String a = http.getString();
    http.end();
	String d = BalmIotjson(a,b);
	return d;
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
