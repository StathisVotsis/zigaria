/*-----( Import needed libraries )-----*/
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <Hx711.h>
Hx711 scale(A2, A3);
#include <Keypad.h>
/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypa
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
/*-----( Declare Variables )-----*/
//NONE
float val;
int ledPin = 13;
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);  // Used to type in characters
  pinMode(ledPin, OUTPUT); 
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);   

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 2; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

//-------- Write characters on the display ------------------
// NOTE: Cursor Position: (CHAR, LINE) start at 0  
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Load cell honey");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Put empty jar"); // Print text on second line
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Press:"); // Print text on second line 
  lcd.setCursor(0,1); 
  lcd.print("A=1,B=1/2,C=1/4"); 
 

 


}

////////////////////////////////////////////////////////////////////////////////
void loop()   
{
  

 //////////////////////////////////
 char key = keypad.getKey();

 if (key)  // Check for a valid key.
  {
    switch(key)
    {
      case 'A':
             lcd.clear();
             while(1)
             {
             lcd.setCursor(0, 0);
             lcd.print(scale.getGram(), 1);
             lcd.print(" gr");
             lcd.print(" ");
             val=(scale.getGram());
             //lcd.setCursor(0, 1);
             //lcd.print(val);
             
             if(val>950){ digitalWrite(ledPin, HIGH);}//εδω αλλάζεις τιμη του κιλού
             if(val<100){ digitalWrite(ledPin, LOW);}
             //delay(200);
             key = keypad.getKey();
              if (key=='*')
              {
                digitalWrite(ledPin, LOW);
                break;
              }
             }
      break;
      case 'B':
            lcd.clear();
             while(1)
             {
             lcd.setCursor(0, 0);
             lcd.print(scale.getGram(), 1);
             lcd.print(" gr");
             lcd.print(" ");
             val=(scale.getGram());
             //lcd.setCursor(0, 1);
             //lcd.print(val);
             
             if(val>470){ digitalWrite(ledPin, HIGH);}//εδω αλλάζεις τιμη του μισόκιλου
             if(val<100){ digitalWrite(ledPin, LOW);}
             //delay(200);
             key = keypad.getKey();
              if (key=='*')
              {
                digitalWrite(ledPin, LOW);
                break;
              }
             }
      break;
      case 'C':
        lcd.clear();
             while(1)
             {
             lcd.setCursor(0, 0);
             lcd.print(scale.getGram(), 1);
             lcd.print(" gr");
             lcd.print(" ");
             val=(scale.getGram());
             //lcd.setCursor(0, 1);
             //lcd.print(val);
             
             if(val>240){ digitalWrite(ledPin, HIGH);}//εδω αλλάζεις τιμη του τεταρτου
             if(val<80){ digitalWrite(ledPin, LOW);}
             //delay(200);
             key = keypad.getKey();
              if (key=='*')
              {
                digitalWrite(ledPin, LOW);
                break;
              }
             }
      break;
    }
  }
  

}/* --(end main loop )-- */


/* ( THE END ) */


