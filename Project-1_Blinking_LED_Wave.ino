int sd = 100;
int d = 250;
int ed = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);  // LED 1 control is set to pin 2 as an output
  pinMode(3, OUTPUT);  // Same for LEDs 2-5
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 2; i < 7; i++){ // Loops from pin 2 to pin 6
    digitalWrite(i, HIGH); // Turn on LED i
    delay(d); // Wait for d amount of time
    digitalWrite(i, LOW); // Turn off LED i
  }
  for (int i = 5; i > 2; i--){ // Loops from pin 6 to pin 3, pin 2 doesn't need repeated since 1st loop starts at it again
    digitalWrite(i, HIGH); 
    delay(d); 
    digitalWrite(i, LOW); 
  }
  // Loop will now start over from begining
}
