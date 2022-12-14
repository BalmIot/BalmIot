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
รับค่าจากช่อง
ใส่ค่ารหัสคีย์และเลขช่องเพื่อรับข้อมูลจากช่องนั้น
การรับทำได้ 2 แบบคือ
1.ใส่ข้อความ
show.BalmIot_get("","");
2.ใส่ตัวแปร
show.BalmIot_get(keys,ch);
ส่งค่าไปที่ช่อง
ใส่ค่ารหัสคีย์กับเลขช่องและข้อความส่งข้อมูลไปที่ช่องนั้น
การส่งทำได้ 2 แบบคือ
1.ใส่ข้อความ
show.BalmIot_up("","","");
2.ใส่ตัวแปร
show.BalmIot_up(keys,ch,text);
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
    //รับค่าจากช่อง
    //ใส่ค่ารหัสคีย์และเลขช่องเพื่อรับข้อมูลจากช่องนั้น
    //การรับทำได้ 2 แบบคือ
    //String test = show.BalmIot_get("","");//1.ใส่ข้อความ
    String test = show.BalmIot_get(keys,ch);//2.ใส่ตัวแปร
    
    //ส่งค่าไปที่ช่อง
    //ใส่ค่ารหัสคีย์กับเลขช่องและข้อความส่งข้อมูลไปที่ช่องนั้น
    //การส่งทำได้ 2 แบบคือ
    //String test = show.BalmIot_up("","","");//1.ใส่ข้อความ
    //String test = show.BalmIot_up(keys,ch,text);//2.ใส่ตัวแปร
    
    Serial.println(test);//แสดงผล test
    delay(5000);//หน่วงเวลา 5 วินาที
   }
}
