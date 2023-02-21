/*
เรียกใช้งานไลบรารี่ BALM IOT
#include <BalmIot.h>

ตัวแปรรหัสคีย์(ระบบจะส่งรหัสคีย์ให้ท่านทางอีเมล)
const char* keys = "***";

ตัวแปรเลขช่อง
const char* ch = "1";

ตัวแปรข้อความ
const char* text = "ทดสอบ";

เรียกใช้งาน BALM IOT
BalmIot show;

รับค่าเวลา
จะได้ค่าเวลาล่าสุด เช่น 12:40
show.BalmIot_time();

รับค่าจากช่อง
ใส่ค่ารหัสคีย์และเลขช่องเพื่อรับข้อมูลจากช่องนั้น
การรับทำได้ 4 แบบคือ
show.BalmIot_get("keys","1");
show.BalmIot_get(keys,ch);
show.BalmIot_get("keys",ch);
show.BalmIot_get(keys,"1");

ส่งค่าไปที่ช่อง
ใส่ค่ารหัสคีย์กับเลขช่องและข้อความส่งข้อมูลไปที่ช่องนั้น
การส่งทำได้ 6 แบบคือ
show.BalmIot_up("keys","1","เทส");
show.BalmIot_up(keys,ch,text);
show.BalmIot_up("keys",ch,text);
show.BalmIot_up(keys,"1",text);
show.BalmIot_up(keys,ch,"เทส");
show.BalmIot_up(keys,"1","เทส");
*/

#include <WiFi.h>//เรียกใช้งานไลบรารี่ WiFi
#include <BalmIot.h>//เรียกใช้งานไลบรารี่ BALM IOT
const char* ssid     = "***";//ชื่อ WiFi
const char* password = "***";//รหัส WiFi
const char* keys = "***";//ตัวแปรรหัสคีย์(ระบบจะส่งรหัสคีย์ให้ท่านทางอีเมล)
const char* ch = "1";//ตัวแปรเลขช่อง
const char* text = "ทดสอบ";//ตัวแปรข้อความ

BalmIot show;//เรียกใช้งาน BALM IOT

void setup()//ทำงานแบบการตั้งค่า
{
   Serial.begin(9600);//แสดงผลที่การเชื่อมต่อ 9600
   Serial.println("กำลังเชื่อมต่อ WiFi...");//แสดงผลคำว่า กำลังเชื่อมต่อ WiFi...
   WiFi.begin(ssid, password);//ทำการกำลังเชื่อมต่อ WiFi
   while (WiFi.status() != WL_CONNECTED)//ถ้าไม่ได้เชื่อมต่อ WiFi
   {
      delay(1000);//หน่วงเวลา 1 วินาที
   }
   Serial.println("เชื่อมต่อ WiFi แล้ว");//แสดงผลคำว่า เชื่อมต่อ WiFi แล้ว
}

void loop()//ทำงานแบบวนลูป
{
  if ((WiFi.status() == WL_CONNECTED))//ถ้าเชื่อมต่อ WiFi อยู่
  {
   //รับค่าเวลา
   //String test = show.BalmIot_time();//จะได้ค่าเวลาล่าสุด เช่น 12:40
   
   //รับค่าจากช่อง
   //ใส่ค่ารหัสคีย์และเลขช่องเพื่อรับข้อมูลจากช่องนั้น
   //การรับทำได้ 4 แบบคือ
   //String test = show.BalmIot_get("keys","1");
   String test = show.BalmIot_get(keys,ch);
   //String test = show.BalmIot_get("keys",ch);
   //String test = show.BalmIot_get(keys,"1");
    
   //ส่งค่าไปที่ช่อง
   //ใส่ค่ารหัสคีย์กับเลขช่องและข้อความส่งข้อมูลไปที่ช่องนั้น
   //การส่งทำได้ 6 แบบคือ
   //String test = show.BalmIot_up("keys","1","เทส");
   //String test = show.BalmIot_up(keys,ch,text);
	//String test = show.BalmIot_up("keys",ch,text);
	//String test = show.BalmIot_up(keys,"1",text);
	//String test = show.BalmIot_up(keys,ch,"เทส");
	//String test = show.BalmIot_up(keys,"1","เทส");
    
    Serial.println(test);//แสดงผล test
    delay(5000);//หน่วงเวลา 5 วินาที
   }
}
