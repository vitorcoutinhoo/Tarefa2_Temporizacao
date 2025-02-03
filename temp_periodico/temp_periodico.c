#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos
#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

// Led atual: Vermelho
uint current = 13;

// Função para iniciar um pino e setar direção
void init_gpio(uint gpio, uint dir) {
    gpio_init(gpio);
    gpio_set_dir(gpio, dir);
}

// Função call-back pra atualizar o led aceso
bool repeating_timer_callback(struct repeating_timer *t) {

    // Caso o led atual seja o vermelho
    if (current == 13) {
        gpio_put(YELLOW_LED, 0);
        gpio_put(GREEN_LED, 0);
        gpio_put(RED_LED, 1);

        printf("Ligando Vermelho!\n");
        current -= 1; // Vai pro led amarelo

        return true;
    }

    // Caso o led atual seja o amarelo
    if (current == 12) {

        // Amarelo no simulador, Azul na placa
        // gpio_put(RED_LED, 0);
        // gpio_put(GREEN_LED, 0);
        // gpio_put(YELLOW_LED, 1);

        // Amarelo na placa
        gpio_put(RED_LED, 1);
        gpio_put(GREEN_LED, 1);

        printf("Ligando Amarelo!\n");
        current -= 1; // Vai pro led verde

        return true;
    }

    // Caso o led atual seja o verde
    if (current == 11) {
        gpio_put(RED_LED, 0);
        gpio_put(YELLOW_LED, 0);
        gpio_put(GREEN_LED, 1);

        printf("Ligando Verde!\n");
        current += 2; // Volta pro led vermelho

        return true;
    }

    return true;
}

int main() {
    stdio_init_all();

    // Inicia os pinos e suas direções
    init_gpio(RED_LED, GPIO_OUT);
    init_gpio(YELLOW_LED, GPIO_OUT);
    init_gpio(GREEN_LED, GPIO_OUT);

    // Liga o led vermelho
    gpio_put(current, 1);
    current -= 1;

    // Configura o timer e chama a função callback a cada 3s
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // Mensagem do loop principal
        printf("passou 1 segundo!\n");
        sleep_ms(1000);
    }
}