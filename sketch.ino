# include <RTClib.h>
RTC_DS1307 rtc;
String rtc_date="";
String rtc_time="";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!rtc.begin()){
    Serial.println("RTC Not Initialized");
    while(true);
  }
  Serial.println("RTC Found");
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime dt=rtc.now();
  rtc_time=get_time(dt);
  Serial.println(rtc_time);
  rtc_date=get_date(dt);
  Serial.println(rtc_date);
  delay(1000);
}

String get_time(DateTime current){
  int hour=current.hour();
  int minute=current.minute();
  int second=current.second();
  String current_time="Time : "+String(hour)+":"+String(minute)+":"+String(second);
  return current_time;
}

String get_date(DateTime current){
  int year=current.year();
  int month=current.month();
  int day=current.day();
  String current_date="Date : "+String(day)+"/"+String(month)+"/"+String(year);
  return current_date;
}
