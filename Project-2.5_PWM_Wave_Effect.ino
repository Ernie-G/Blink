int pins[] = {3, 5, 6, 9, 11};
int numPins = 5;

int brightness[5] = {0};
int direction[5] = {1}; // 1 is up, -1 is down

unsigned long lastUpdate[5] = {0}; // gets timestamp of last update for each pin
int offsetDelay = 100; // delay between LEDs start time
int interval = 5; // time is ms between led brightness changes

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT); // LED control pin is 3, pwm capable
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  for (int i = 0; i < numPins; i++) {
    
    // stagger start times
    if (currentMillis < i * offsetDelay) {
      continue;
    }

    if (currentMillis - lastUpdate[i] >= interval) { // checks to see if pins waited long enough
      lastUpdate[i] = currentMillis; // updates time since last change
      brightness[i] += direction[i]; // brightens or dims light

      brightness[i] += direction[i];

      if (brightness[i] >= 255) { // flips from brightening to dimming
        brightness[i] = 255;
        direction[i] = -1;
        delay(25);
      }
      else if (brightness[i] <= 0) { // flips from dimming to brightening
        brightness[i] = 0;
        direction[i] = 1;
        delay(25);
      }

      analogWrite(pins[i], brightness[i]); // sets brightness to pins
    }
  }
}
