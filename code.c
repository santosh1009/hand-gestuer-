#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 14, d5 = 27, d6 = 26, d7 = 25;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>


const char* ssid = "SMILE123";
const char* password ="123456789";

#define BOTtoken "7863616791:AAFoBykuE9Lid1jvxoQ6ug5T2G4nNdWECA0"  // your Bot Token (Get from Botfather)
#define CHAT_ID "1212765384"

//X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


char Start_buff[70]; 
int i,z;             
char ch;
int str_len;
char textmessage[20];



int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;


void setup() 
{
  

  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.println("MEMS HAND GLOVES");
  lcd.print("Hand Gesture");
  lcd.setCursor(0,1);
  lcd.print("Recognition");
  delay(1000);
   Serial.println("Starting TelegramBot...");

    Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

   

  bot.sendMessage(CHAT_ID, "Hand Gesture Recognition..");
  delay(2000); 
 

}

void loop()
{

  Flex_Read();

}

void Flex_Read()
{
  while(1)
  {
    int F1_val=analogRead(39);
    int F2_val=analogRead(34);
    int F3_val=analogRead(35);
    int F4_val=analogRead(32);


   
  
//    Serial.print("F1:");
//    Serial.println(F1_val);
//    
//    Serial.print("F2:");
//    Serial.println(F2_val);
////    
//    Serial.print("F3:");
//    Serial.println(F3_val);
////    
//    Serial.print("F4:");
//    Serial.println(F4_val);
    
//    Serial.print("F5:");
//    Serial.println(F5_val);
//  
 
    delay(1000);
    if((F1_val<2000)&&(F2_val>3500)&&(F3_val>3500)&&(F4_val>3500))
    {
        Serial.println(" 3 ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("3 ");
        bot.sendMessage(CHAT_ID, " 3 ");
        delay(1000);
      
    }
   
    if((F2_val<2000)&&(F1_val>3500)&&(F3_val>3500)&&(F4_val>3500))
    {
     
      Serial.println(" 7 ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("7 ");
        bot.sendMessage(CHAT_ID, " 7 ");
        delay(1000);
    }
  
    if((F3_val<2000)&&(F2_val>3500)&&(F1_val>3500)&&(F4_val>3500))
    {
      Serial.println(" 8 ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("8 ");
        bot.sendMessage(CHAT_ID, " 8 ");
        delay(1000);
      
    }
  
    if((F4_val<2000)&&(F2_val>3500)&&(F3_val>3500)&&(F1_val>3500))
    {
    
       Serial.println(" F ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("F ");
        bot.sendMessage(CHAT_ID, " F ");
        delay(1000);
    
      
    }
    if((F1_val<2000)&&(F2_val<2000)&&(F3_val>3500)&&(F4_val>3500))
    {
     
        Serial.println(" 2 ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("2 ");
        bot.sendMessage(CHAT_ID, " 2 ");
        delay(1000);
      
    }
//    if((F1_val<2000)&&(F2_val>3500)&&(F3_val<2000)&&(F4_val>3500))
//    {
//   
//         Serial.println(" F ");
//        lcd.clear();
//        lcd.setCursor(0, 0);
//        lcd.print("F ");
//        bot.sendMessage(CHAT_ID, " F ");
//        delay(1000);
//      
//   }
//     if((F1_val<2000)&&(F2_val>3500)&&(F3_val>3500)&&(F4_val<2000))
//    {
//   
//       lcd.clear();
//      lcd.print("Thank You");
//      lcd.setCursor(0,1);
//      lcd.print(" ");
//      Serial.println("Thank You");
//      delay(1000);
//      
//   }
//    if((F2_val<2000)&&(F1_val>3500)&&(F4_val>3500)&&(F3_val<2000))
//    {
//   
//       lcd.clear();
//      lcd.print("Sorry I Can Not");
//      lcd.setCursor(0,1);
//      lcd.print("  Speak ");
//      Serial.println("Sorry I Can Not Speak Please Listen to the Speaker");
//      delay(1000);
//      
//   }
//    if((F2_val<2000)&&(F1_val>3500)&&(F3_val>3500)&&(F4_val<2000))
//    {
//   
//       lcd.clear();
//      lcd.print("The Work Is");
//      lcd.setCursor(0,1);
//      lcd.print("  Finished ");
//      Serial.println("The Work Is Finished");
//      delay(1000);
//      
//   }
    if((F3_val<2000)&&(F1_val>3500)&&(F2_val>3500)&&(F4_val<2000))
    {
   
       Serial.println(" K ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("K ");
        bot.sendMessage(CHAT_ID, " K ");
        delay(1000);
      
   }
   if((F1_val<2000)&&(F2_val<2000)&&(F3_val<2000)&&(F4_val>3500))
    {
   
      Serial.println(" Y ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Y ");
        bot.sendMessage(CHAT_ID, " Y ");
        delay(1000);
      
   }
//     if((F1_val<2000)&&(F2_val<2000)&&(F4_val<2000)&&(F3_val>3500))
//    {
//   
//        Serial.println(" F ");
//        lcd.clear();
//        lcd.setCursor(0, 0);
//        lcd.print("F ");
//        bot.sendMessage(CHAT_ID, " F ");
//        delay(1000);
//      
//   }
    if((F1_val<2000)&&(F2_val>3500)&&(F3_val<2000)&&(F4_val<2000))
    {
   
       Serial.println(" Z ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Z ");
        bot.sendMessage(CHAT_ID, " Z ");
        delay(1000);
      
   }
    if((F1_val>3500)&&(F2_val<2000)&&(F3_val<2000)&&(F4_val<2000))
    {
   
      Serial.println(" 1 ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("1");
        bot.sendMessage(CHAT_ID, " 1 ");
        delay(1000);
      
   }
    if((F1_val<2000)&&(F2_val<2000)&&(F3_val<2000)&&(F4_val<2000))
    {
   
        Serial.println(" A ");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("A ");
        bot.sendMessage(CHAT_ID, " A ");
        delay(1000);
      
   }

  }
}