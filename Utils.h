#define NUM_TASKS 6
#define SINGLE_BUTTON 4
#define MANUAL_BUTTON 5
#define AUTO_BUTTON 6
#define PIR_PIN 2
#define LED_PIN 13
#define TRIG_PIN 7
#define ECHO_PIN 8
#define SERVO_PIN 9
#define POT_PIN A0

#define N 16
#define DFAR 0.4
#define DNEAR 0.2

enum class State {SINGLE, MANUAL, AUTO, SCANNING, ALARM, TRACKING_ALARM};
