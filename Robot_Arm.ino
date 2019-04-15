#include <Event.timer_8>
#include <Timer.timer_8>

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10
#define HEATER_1_PIN       8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING

#define X_Control_PIN 4
#define Y_Control_PIN 5
#define Z_Control_PIN 11
#define Joy_switch 15

Timer t1, t2, t3, t4, t5, t6;

int timer_1, timer_2, timer_3, timer_4, timer_5, timer_6, timer_7, timer_8, timer_9, timer_10, timer_11, timer_12;
int step_speed = 10;  // Speed of Stepper motor
const unsigned long PERIOD1 = 0L * 0L;

void setup() {
  Serial.begin (9600);
  pinMode(FAN_PIN , OUTPUT);
  pinMode(HEATER_0_PIN , OUTPUT);
  pinMode(HEATER_1_PIN , OUTPUT);
  pinMode(LED_PIN  , OUTPUT);

  pinMode(X_STEP_PIN  , OUTPUT);
  pinMode(X_DIR_PIN    , OUTPUT);
  pinMode(X_ENABLE_PIN    , OUTPUT);

  pinMode(Y_STEP_PIN  , OUTPUT);
  pinMode(Y_DIR_PIN    , OUTPUT);
  pinMode(Y_ENABLE_PIN    , OUTPUT);

  pinMode(Z_STEP_PIN  , OUTPUT);
  pinMode(Z_DIR_PIN    , OUTPUT);
  pinMode(Z_ENABLE_PIN    , OUTPUT);

  digitalWrite(X_ENABLE_PIN    , LOW);
  digitalWrite(Y_ENABLE_PIN    , LOW);
  digitalWrite(Z_ENABLE_PIN    , LOW);

  pinMode(Joy_switch, INPUT_PULLUP);
  //t15.every(ZERO, statestop);
}

void loop() {
  if (!digitalRead(Joy_switch)) {
    //delay(); //delay for deboucing
    switch (step_speed) {
      case 1:
        step_speed = 10; //slow
        break;
      case 2:
        step_speed = 3; //medium
        break;
      case 3:
        step_speed = 0; //fast
        break;
    }
  }

  if (analogRead(X_Control_PIN) > 520) {
    digitalWrite(X_ENABLE_PIN    , LOW);
    digitalWrite(X_DIR_PIN , LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
    timer_1 = t1.oscillate(X_STEP_PIN, PERIOD1, HIGH); //digitalWrite(X_DIR_PIN , HIGH); changing state every milliseconds by setting oscillate  
    delay(step_speed);
    timer_2 = t1.oscillate(X_STEP_PIN, PERIOD1, LOW); //(which Pin, milliseconds, state)
    delay(step_speed);
    //t2.stop(X_Control_PIN); t3.stop(X_Control_PIN);
    t1.update();
    t1.update();
    t1.update();
    t1.update();
    t1.update();
    t1.update();
  }
  if (analogRead(X_Control_PIN) < 480) {
    digitalWrite(X_ENABLE_PIN    , LOW);
    digitalWrite(X_DIR_PIN , HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
    timer_3 = t2.oscillate(X_STEP_PIN, PERIOD1, LOW); //digitalWrite(X_DIR_PIN , HIGH);
    delay(step_speed);
    timer_4 = t2.oscillate(X_STEP_PIN, PERIOD1, HIGH); //digitalWrite(X_STEP_PIN, LOW);
    delay(step_speed);
    //t4.stop(X_Control_PIN); t5.stop(X_Control_PIN);
    t2.update();
    t2.update();
    t2.update();
    t2.update();
    t2.update();
    t2.update();
  }
  if (analogRead(Y_Control_PIN) > 540) {
    digitalWrite(Y_ENABLE_PIN    , LOW);
    digitalWrite(Y_DIR_PIN , LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
    timer_5 = t3.oscillate(Y_STEP_PIN, PERIOD1, HIGH); //digitalWrite(Y_STEP_PIN, HIGH);
    delay(step_speed);
    timer_6 = t3.oscillate(Y_STEP_PIN, PERIOD1, LOW); //digitalWrite(Y_STEP_PIN, LOW);
    delay(step_speed);
    //t6.stop(Y_STEP_PIN); t7.stop(Y_STEP_PIN);
    t3.update();
    t3.update();
    t3.update();
    t3.update();
    t3.update();
    t3.update();
  }
  if (analogRead(Y_Control_PIN) < 460) {
    digitalWrite(Y_ENABLE_PIN    , LOW);
    digitalWrite(Y_DIR_PIN , HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
    timer_7 = t4.oscillate(Y_STEP_PIN, PERIOD1, LOW); //digitalWrite(Y_STEP_PIN, HIGH);
    delay(step_speed);
    timer_8 = t4.oscillate(Y_STEP_PIN, PERIOD1, HIGH); //digitalWrite(Y_STEP_PIN, LOW);
    delay(step_speed);
    //t8.stop(Y_STEP_PIN); t9.stop(Y_STEP_PIN);
    t4.update();
    t4.update();
    t4.update();
    t4.update();
    t4.update();
    t4.update();
  }
  if (analogRead(Z_Control_PIN) > 520) {
    digitalWrite(Z_ENABLE_PIN    , LOW);
    digitalWrite(Z_DIR_PIN , LOW);  // (HIGH = anti-clockwise / LOW = clockwise)
    timer_9 = t5.oscillate(Z_STEP_PIN, PERIOD1, HIGH); //digitalWrite(Z_STEP_PIN, HIGH);
    delay(step_speed);
    timer_10 = t5.oscillate(Z_STEP_PIN, PERIOD1, LOW); //digitalWrite(Z_STEP_PIN, LOW);
    delay(step_speed);
    //t10.stop(Z_STEP_PIN); t11.stop(Z_STEP_PIN);
    t5.update();
    t5.update();
    t5.update();
    t5.update();
    t5.update();
    t5.update();
  }
  if (analogRead(Z_Control_PIN) < 480) {
    digitalWrite(Z_ENABLE_PIN    , LOW);
    digitalWrite(Z_DIR_PIN , HIGH);  // (HIGH = anti-clockwise / LOW = clockwise)
    timer_11 = t6.oscillate(Z_STEP_PIN, PERIOD1, LOW); //digitalWrite(Z_STEP_PIN, HIGH);
    delay(step_speed);
    timer_12 = t6.oscillate(Z_STEP_PIN, PERIOD1, HIGH); //digitalWrite(Z_STEP_PIN, LOW);
    delay(step_speed);
    // t12.stop(Z_STEP_PIN); t13.stop(Z_STEP_PIN);
    t6.update();
    t6.update();
    t6.update();
    t6.update();
    t6.update();
    t6.update();
  }
  statestop();
  
}

void statestop() {
  t1.stop(timer_1);
  t1.stop(timer_2);
  t2.stop(timer_3);
  t2.stop(timer_4);
  t3.stop(timer_5);
  t3.stop(timer_6);
  t4.stop(timer_7);
  t4.stop(timer_8);
  t5.stop(timer_9);
  t5.stop(timer_10);
  t6.stop(timer_11);
  t6.stop(timer_12);
  //loop();
}

