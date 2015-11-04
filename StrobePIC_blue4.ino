// StrobePIC_blue4, used in Garnet Hertz's "Pixel VGA (Version 1, Banff Floor Cluster)"
// installed at the Banff Centre in July 2011. Pins 4 through 7 of an Arduino Uno are
// connected in parallel to 24 Tiny VGA circuits, initially designed by Arjan Scherpenisse.
// Code contributions by Erik Olson. For documentation of this installation, see
// http://www.conceptlab.com/pixel/

int activate = 4;
int red = 7;
int green = 6;
int blue = 5;
void setup() {

  pinMode(activate, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(activate, HIGH);

}

void loop() {
  // Main code goes here, to run repeatedly: 

  // blue 20000 pause
  digitalWrite(red,  LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay (20000);

  // blue-to-white strobes 1200
  {
    for (int i=1200; i >= 10; i = i / 1.1){
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      delay (2 * i);
      digitalWrite(red,  HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
      delay (30);
    } 
  }


  // white-to-blue 100
  {
    for (int i=0; i <= 100; i++){
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      delay (i);
      digitalWrite(red,  HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
      delay (i);
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      delay (100);
    } 
  }

  // blue 10000 pause
  digitalWrite(red,  LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);  
  delay (10000);

  // blue-to-white 200 w strobe
  {
    for (int i=200; i >= 0; i--){
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      delay (i);
      digitalWrite(red,  HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
      delay (i);
      for (int i=10; i >= 0; i--){
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blue, HIGH);
        delay (i);
        digitalWrite(red,  HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
        delay (i);      
      } 

    } 
  }

  // white-to-blue 100
  {
    for (int i=0; i <= 100; i++){
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
      delay (i);
      digitalWrite(red,  HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
      delay (i);
    } 
  }


}
