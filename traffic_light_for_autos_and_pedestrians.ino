// Pin selection (avoid 0/1 which are RX/TX)
const byte CAR_R  = 2;
const byte CAR_Y  = 3;
const byte CAR_G  = 4;
const byte PED_R  = 8;
const byte PED_G  = 9;
const byte BTN    = 7;



// Timings (milliseconds)
const unsigned int PRE_STOP_MS = 1000;  // delay after press before cars yellow
const unsigned int YELLOW_MS   = 2000;  // cars yellow duration
const unsigned int WALK_MS     = 5000;  // pedestrians green duration
const unsigned int DEBOUNCE_MS = 30;    // button debounce

void carsGo_pedsStop() {
  digitalWrite(CAR_R, LOW);
  digitalWrite(CAR_Y, LOW);
  digitalWrite(CAR_G, HIGH);

  digitalWrite(PED_R, HIGH);
  digitalWrite(PED_G, LOW);
}

void carsYellow() {
  digitalWrite(CAR_G, LOW);
  digitalWrite(CAR_Y, HIGH);
}

void carsStop_pedsGo() {
  digitalWrite(CAR_Y, LOW);
  digitalWrite(CAR_R, HIGH);

  digitalWrite(PED_R, LOW);
  digitalWrite(PED_G, HIGH);
}

void setup() {
  pinMode(CAR_R, OUTPUT);
  pinMode(CAR_Y, OUTPUT);
  pinMode(CAR_G, OUTPUT);
  pinMode(PED_R, OUTPUT);
  pinMode(PED_G, OUTPUT);
  pinMode(BTN,   INPUT_PULLUP);  

  carsGo_pedsStop();
}

bool pressedNow() {
  // Returns true on press (LOW) with a tiny debounce, and waits for release
  if (digitalRead(BTN) == LOW) {
    delay(DEBOUNCE_MS);
    if (digitalRead(BTN) == LOW) {
      while (digitalRead(BTN) == LOW) { /* wait release */ }
      return true;
    }
  }
  return false;
}

void loop() {
  if (pressedNow()) {
    delay(PRE_STOP_MS);

    // Cars: green -> yellow -> red
    carsYellow();
    delay(YELLOW_MS);
    digitalWrite(CAR_Y, LOW);
    digitalWrite(CAR_R, HIGH);

    // Pedestrians: red -> green
    digitalWrite(PED_R, LOW);
    digitalWrite(PED_G, HIGH);
    delay(WALK_MS);

    // Back to default state
    digitalWrite(PED_G, LOW);
    digitalWrite(PED_R, HIGH);
    digitalWrite(CAR_R, LOW);
    digitalWrite(CAR_G, HIGH);

    delay(200); 
  }

}