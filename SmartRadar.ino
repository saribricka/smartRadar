#include "Timer.h"
#include "Button.h"
#include "ChooseStateTask.h"
#include "SingleTask.h"
#include "ManualTask.h"
#include "AutoTask.h"
#include "ScanningTask.h"
#include "BlinkTask.h"
#include "AlarmTask.h"
#include "TrackingAlarmTask.h"

const int basePeriod = 50;
State state;
State lastState;
bool* blinkState;
Timer* timer = new Timer();
ServoMotor* servo = new ServoMotorImpl(SERVO_PIN);
Pot* pot = new PotImpl(POT_PIN);
Sonar* sonar = new SonarImpl(TRIG_PIN, ECHO_PIN);
Led* led = new LedImpl(LED_PIN);
Task* chooseStateTask = new ChooseStateTask(SINGLE_BUTTON, MANUAL_BUTTON, AUTO_BUTTON, &state);
Task* blinkTask = new BlinkTask(blinkState, led);
Task* tasks[NUM_TASKS];

void initTasks(){
  tasks[0] = new SingleTask(&state);
  tasks[1] = new ManualTask();
  tasks[2] = new AutoTask(&state, servo, pot, sonar);
  tasks[3] = new ScanningTask(&state, blinkState, servo, pot, sonar);
  tasks[4] = new AlarmTask(&state, blinkState, servo, pot, sonar);
  tasks[5] = new TrackingAlarmTask(&state, sonar);
}

void step() {
  blinkTask->tick();
  chooseStateTask->tick();
  if(state != lastState && (state != State::TRACKING_ALARM || lastState == State::ALARM)){
    tasks[(int)lastState]->init(basePeriod);
  }
  lastState = state;
  if(tasks[(int)state]->updateAndCheckTime(basePeriod)){
    tasks[(int)state]->tick();
  }
}

void setup() {
  Serial.begin(9600);
  timer->setupPeriod(4*basePeriod);
  state = lastState = State::MANUAL;
  servo->on();
  chooseStateTask->init(basePeriod);
  *blinkState = false;
  blinkTask->init(10*basePeriod);
  initTasks();
  for(int i=0; i<NUM_TASKS; i++){
    tasks[i]->init(basePeriod);
  }
}

void loop() {
  step();
  timer->waitForNextTick();
}
