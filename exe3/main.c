#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_V = 28;
const int BTN_PIN_A = 26;

const int LED_PIN_V = 4;
const int LED_PIN_A = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_V);
  gpio_set_dir(BTN_PIN_V, GPIO_IN);
  gpio_pull_up(BTN_PIN_V);

  gpio_init(BTN_PIN_A);
  gpio_set_dir(BTN_PIN_A, GPIO_IN);
  gpio_pull_up(BTN_PIN_A);

  gpio_init(LED_PIN_V);
  gpio_set_dir(LED_PIN_V, GPIO_OUT);

  gpio_init(LED_PIN_A);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);


  while (true) {

    int status_v = gpio_get(LED_PIN_V);
    int status_a = gpio_get(LED_PIN_A);


    if (!gpio_get(BTN_PIN_V)) {

      if (status_v == 0){
        gpio_put(LED_PIN_V, 1);
      }
      else {
        gpio_put(LED_PIN_V, 0);
      }

      while (!gpio_get(BTN_PIN_V)) {
      };
    }
    

    if (!gpio_get(BTN_PIN_A)) {

      if (status_a == 0){
        gpio_put(LED_PIN_A, 1);
      }
      else {
        gpio_put(LED_PIN_A, 0);
      }

      while (!gpio_get(BTN_PIN_A)) {
      };
    }

  }
}
