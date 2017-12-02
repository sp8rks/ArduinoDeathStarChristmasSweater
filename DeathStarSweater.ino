//Copyright Taylor Sparks 2017 (12-2-2017). Feel free to use this code but please retain attribution. 
//If you use the code for your own project send me a picture of your creation! sparks@eng.utah.edu

// Declare left and right accelerometers
const int LAccel = 1;                  // Accelerometer's Y axis is anolog pin 1 on Arduino
const int RAccel = 0;                  // Accelerometer's Y axis is anolog pin 0 on Arduino

int yLAccel = 0;
int yRAccel = 0;
int armTime = 125;

//For left arm blasters
int ledL1 = 4;
int ledL2 = 3;
int ledL3 = 2;
int ledL4 = 1;
int ledL5 = 0;

//For right arm blasters
int ledR1 = 7;
int ledR2 = 8;
int ledR3 = 11; //careful, this is a PWM pin that I just will use as digital
int ledR4 = 12;
int ledR5 = 13;

//For starry night background
int ledStar1 = 5;       // PWM pin for 5 stars in "Star1" category
int ledStar2 = 6;       // PWM pin for 5 stars in "Star2" category
int ledStar3 = 9;       // PWM pin for 5 stars in "Star3" category
int ledStar4 = 10;      // PWM pin for 5 stars in "Star4" category
int brightness1 = 30;    // how bright the LEDStar is for star1
int brightness2 = 70;   // how bright the LEDStar is for star2
int brightness3 = 140;  // how bright the LEDStar is for star2
int brightness4 = 210;  // how bright the LEDStar is for star2

int fadeAmount1 = 15;    // how many points to fade the LED by
int fadeAmount2 = 15;    // how many points to fade the LED by
int fadeAmount3 = 15;    // how many points to fade the LED by
int fadeAmount4 = 15;    // how many points to fade the LED by


void setup() {
  pinMode(LAccel, INPUT);  // Sets analog pin 1 to input for left accelerometer.
  pinMode(RAccel, INPUT);  // Sets analog pin 0 to input for right accelerometer.
  pinMode(ledL1, OUTPUT); 
  pinMode(ledL2, OUTPUT);
  pinMode(ledL3, OUTPUT);
  pinMode(ledL4, OUTPUT);
  pinMode(ledL5, OUTPUT);
  pinMode(ledR1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  pinMode(ledR3, OUTPUT);
  pinMode(ledR4, OUTPUT);
  pinMode(ledR5, OUTPUT);
  pinMode(ledStar1, OUTPUT);
  pinMode(ledStar2, OUTPUT);
  pinMode(ledStar3, OUTPUT);
  pinMode(ledStar4, OUTPUT);
}

void loop() {
  //read accelerometer values from L&R arms
  yLAccel=analogRead(LAccel);
  yRAccel=analogRead(RAccel);

  //MAKE THE STARS TWINKLE
  // reverse the direction of the fading at the ends of the fade
  if (brightness1 <= (0+15) || brightness1 >= (255-15)) {
    fadeAmount1 = -fadeAmount1;
  }
   if (brightness2 <= (0+15) || brightness2 >= (255-15)) {
    fadeAmount2 = -fadeAmount2;
  }
   if (brightness3 <= (0+15) || brightness3 >= (255-15)) {
    fadeAmount3 = -fadeAmount3;
  }
   if (brightness4 <= (0+15) || brightness4 >= (255-15)) {
    fadeAmount4 = -fadeAmount4;
  }
 
  analogWrite(ledStar1, brightness1);
  analogWrite(ledStar2, brightness2);
  analogWrite(ledStar3, brightness3);
  analogWrite(ledStar4, brightness4);
  // change the brightness for next time through the loop:
  brightness1 = brightness1 + fadeAmount1;
  brightness2 = brightness2 + fadeAmount2;
  brightness3 = brightness3 + fadeAmount3;
  brightness4 = brightness4 + fadeAmount4;
  // wait for 30 milliseconds to see the dimming effect
  delay(30);  


  // left arm death ray
  if ((yLAccel < 450) && (yRAccel < 550)) { 
    digitalWrite(ledL5, HIGH);
    delay(armTime);            
    digitalWrite(ledL4, HIGH);
    delay(armTime);            
    digitalWrite(ledL3, HIGH);
    delay(armTime); 
    digitalWrite(ledL2, HIGH);
    delay(armTime);  
    digitalWrite(ledL1, HIGH);
   delay(armTime);          
    digitalWrite(ledL1, LOW);
    digitalWrite(ledL2, LOW);
    digitalWrite(ledL3, LOW);
    digitalWrite(ledL4, LOW);
    digitalWrite(ledL5, LOW);
    delay(50);
  } 

    // right arm death ray
  if ((yRAccel > 550) &&(yLAccel > 450)) { 
    digitalWrite(ledR5, HIGH);
    delay(armTime);            
    digitalWrite(ledR4, HIGH);
    delay(armTime);            
    digitalWrite(ledR3, HIGH);
    delay(armTime); 
    digitalWrite(ledR2, HIGH);
    delay(125);  
    digitalWrite(ledR1, HIGH);
    delay(armTime);          
    digitalWrite(ledR1, LOW);
    digitalWrite(ledR2, LOW);
    digitalWrite(ledR3, LOW);
    digitalWrite(ledR4, LOW);
    digitalWrite(ledR5, LOW);
    delay(50);
  } 

    if ((yLAccel < 450) && (yRAccel > 550)) { 
    digitalWrite(ledL5, HIGH);
    digitalWrite(ledR5, HIGH);
    delay(armTime);            
    digitalWrite(ledL4, HIGH);
    digitalWrite(ledR4, HIGH);
    delay(armTime);            
    digitalWrite(ledL3, HIGH);
    digitalWrite(ledR3, HIGH);
    delay(armTime); 
    digitalWrite(ledL2, HIGH);
    digitalWrite(ledR2, HIGH);
    delay(armTime);  
    digitalWrite(ledL1, HIGH);
    digitalWrite(ledR1, HIGH);
    delay(armTime);          
    digitalWrite(ledL1, LOW);
    digitalWrite(ledL2, LOW);
    digitalWrite(ledL3, LOW);
    digitalWrite(ledL4, LOW);
    digitalWrite(ledL5, LOW);
    digitalWrite(ledR1, LOW);
    digitalWrite(ledR2, LOW);
    digitalWrite(ledR3, LOW);
    digitalWrite(ledR4, LOW);
    digitalWrite(ledR5, LOW);
    delay(50);
  } 

}

