
int trigPin  = 13;
int echoPin  = 12;
int ledPin   = 8;
int led2Pin  = 7;

bool inRange = false;
int inRangeDistance = 100;   // in cm
int delayDuration = 1000;     // in milliseconds

void setup() {

    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
}

void loop() {

    // ping
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    // get distance in cm
    int   duration = pulseIn(echoPin, HIGH);
    float distance = duration / 58.0;

    // flash if object is in range
    if (distance <= inRangeDistance) {

        digitalWrite(ledPin, HIGH);
        digitalWrite(led2Pin, LOW);
        delay(delayDuration);

        digitalWrite(ledPin, LOW);
        digitalWrite(led2Pin, HIGH);
        delay(delayDuration);

    }
    // do not flash of object is out of range
    else {

        digitalWrite(ledPin, LOW);
        digitalWrite(led2Pin, LOW);   
    }

}