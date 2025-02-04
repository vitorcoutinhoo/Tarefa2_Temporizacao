#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definição dos pinos
#define RED_LED 13
#define BLUE_LED 12
#define GREEN_LED 11
#define BUTTON 5  // Botão a


uint leds[3] = {BLUE_LED, RED_LED, GREEN_LED}; // Ordem a ser desligada
bool leds_on[3] = {false, false, false}; // Led aceso: true

uint current = 0; // Led a ser desligado
bool processing = false; // Impede o botão funcionar novamente durante o processo


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

        // Passa para o próximo led a ser desligado
        current++;

        // Chama a função de callback novamente, até todos os led estiverem desligados
        if (current < 3) add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        else processing = false; // Habilida o botão novamente
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
        if (gpio_get(BUTTON) == 0) {
            sleep_ms(50); // Debouncing simples, espera 50 ms e verifica se o botão continua pressionado
            
            if (gpio_get(BUTTON) == 0 && all_off() && !processing) {
                processing = true; // Trava o botão de funcionar durante esse processo
                current = 0; 
    
                // Liga todos os leds
                for (int i = 0; i < 3; i++) {
                    gpio_put(leds[i], 1);
                    leds_on[i] = true;
                }
    
                // Chama a função callback
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

           

        // Sleep pra não sobrecarregar o processamento
        sleep_ms(10);
    }
}
