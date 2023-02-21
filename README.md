# BalmIot

BalmIot is a library to make it easier to you interact with from Arduino.

## Dependencies

- Requires the Ethernet library WiFi which is in Arduino 1.0 and later

## Installation

1. Download the latest version of the library from https://github.com/BalmIot/BalmIot/releases and save the file somewhere
1. In the Arduino IDE, go to the Sketch -> Import Library -> Add Library... menu option
1. Find the zip file that you saved in the first step, and choose that
1. Check that it has been successfully added by opening the Sketch -> Import Library menu.  You should now see BalmIot listed among the available libraries.

## Usage example

```c++
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

```
## License

Copyright (c) 2022 BALM IOT All right reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
