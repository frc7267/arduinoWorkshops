
int led1Pin = 13;
int led2Pin = 12;
int buttonPin = A0;

int delayDuration = 1000;  // in milliseconds

int eventCounter = 0;

void setup() {

    pinMode(buttonPin, INPUT);
    pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
}

void loop() {

    if (digitalRead(buttonPin) == HIGH) {

        if (eventCounter == 0) {

            // blink led 1 3 times
            for (int i = 0; i < 3; i++) {
                digitalWrite(led1Pin, HIGH);
                delay(delayDuration);
                digitalWrite(led1Pin, LOW);
                delay(delayDuration);
            }
        }

        if (eventCounter == 1) {

            // blink led 2 3 times
            for (int i = 0; i < 3; i++) {
                digitalWrite(led2Pin, HIGH);
                delay(delayDuration);
                digitalWrite(led2Pin, LOW);
                delay(delayDuration);
            }
        }

        if (eventCounter == 2) {

            // blink both leds 3 times
            for (int i = 0; i < 3; i++) {
                digitalWrite(led1Pin, HIGH);
                digitalWrite(led2Pin, HIGH);
                delay(delayDuration);
                digitalWrite(led1Pin, LOW);
                digitalWrite(led2Pin, LOW);
                delay(delayDuration);
            }
        }

        // update event
        eventCounter = (eventCounter + 1) % 3;
    }
}