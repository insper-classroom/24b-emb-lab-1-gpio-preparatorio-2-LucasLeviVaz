#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;

const int LED_PIN_V = 5;
const int LED_PIN_R = 8;
const int LED_PIN_A = 11;
const int LED_PIN_M = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN_V);
  gpio_set_dir(LED_PIN_V, GPIO_OUT);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_A);
  gpio_set_dir(LED_PIN_A, GPIO_OUT);

  gpio_init(LED_PIN_M);
  gpio_set_dir(LED_PIN_M, GPIO_OUT);

  while (true) {

    if (!gpio_get(BTN_PIN)) {

      gpio_put(LED_PIN_V, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_V, 0);

      gpio_put(LED_PIN_R, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_R, 0);

      gpio_put(LED_PIN_A, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_A, 0);

      gpio_put(LED_PIN_M, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_M, 0);

      while (!gpio_get(BTN_PIN)) {
      };
    }

  }
}
