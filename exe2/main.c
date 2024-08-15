#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_V = 26;
const int BTN_PIN_A = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_V);
  gpio_set_dir(BTN_PIN_V, GPIO_IN);
  gpio_pull_up(BTN_PIN_V);

  gpio_init(BTN_PIN_A);
  gpio_set_dir(BTN_PIN_A, GPIO_IN);
  gpio_pull_up(BTN_PIN_A);

  while (true) {
    if (!gpio_get(BTN_PIN_V)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN_V)) {
      };
    }
    
    if (!gpio_get(BTN_PIN_A)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PIN_A)) {
      };
    }
  }

}
