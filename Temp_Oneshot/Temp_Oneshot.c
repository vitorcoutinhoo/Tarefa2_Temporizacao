#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11
#define BUTTON 5  // Botão a

// Variaveis globais
uint leds[3] = {BLUE_LED, RED_LED, GREEN_LED};
bool leds_on[3] = {false, false, false};
uint current = 0;
bool processing = false;

// Função para iniciar um pino e setar direção
void init_gpio(uint gpio, uint dir) {
    gpio_init(gpio);
    gpio_set_dir(gpio, dir);
}

// Função callback para desligar os leds
uint64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (current < 3) {
        gpio_put(leds[current], 0);
        leds_on[current] = false;

        current++;

        if (current < 3) add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        else processing = false;
    }

    return 0;
}

// Verifica se todos os leds estão desligados
bool all_off() {
    for (int i = 0; i < 3; i++) 
        if (leds_on[i]) return false;
    
    return true;
}

int main() {
    stdio_init_all();

    // Inicaliza os pinos e seta as direções
    init_gpio(RED_LED, GPIO_OUT);
    init_gpio(BLUE_LED, GPIO_OUT);
    init_gpio(GREEN_LED, GPIO_OUT);
    init_gpio(BUTTON, GPIO_IN);

    // Coloca o botão em pull-up
    gpio_pull_up(BUTTON);

    while (true) {
        if (gpio_get(BUTTON) == 0 && all_off() && !processing) {
            processing = true;
            current = 0;

            for (int i = 0; i < 3; i++) {
                gpio_put(leds[i], 1);
                leds_on[i] = true;
            }

            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        }   

        sleep_ms(10);
    }
}
