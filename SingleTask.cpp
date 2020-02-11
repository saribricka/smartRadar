#include "SingleTask.h"
#include "Arduino.h"
#include <avr/sleep.h>
#include <avr/power.h>

void sleep(){
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  //power_adc_disable();
  //power_spi_disable(); //??
  //power_twi_disable(); //??
  delay(200);
  sleep_cpu(); //sleep_cpu();
}

void wakeUp(){
  sleep_disable();
  power_all_enable();
  Serial.println("_____________________________Rilevato______________________________");
}

SingleTask::SingleTask(State *state){
  this->pir = new PirImpl(PIR_PIN);
  this->state = state;
  attachInterrupt(digitalPinToInterrupt(this->pir->getPin()), wakeUp, RISING);
}

void SingleTask::init(int period){
  Task::init(period);
}

void SingleTask::tick(){
  sleep();
  *(this->state) = State::SCANNING;
  Serial.println("Running SINGLE");
}
