## temp_periodico

Este projeto implementa um sistema de controle de LEDs onde estes alternam entre vermelho, amarelo e verde a cada 3 segundos.

### Configuração dos Pinos

Os LEDs estão conectados aos seguintes pinos GPIO do Raspberry Pi Pico:

- LED Vermelho: GPIO 13

- LED Amarelo: GPIO 12

- LED Verde: GPIO 11

### Funcionamento

O programa inicializa os pinos como saída.

O LED vermelho acende primeiro.

A cada 3 segundos, a cor do LED muda na sequência:

- Vermelho → Amarelo

- Amarelo → Verde

- Verde → Vermelho

O programa imprime mensagens no terminal a cada 1 segundo, indicando o LED ativo.

### Como Compilar e Executar

- Instale o SDK do Raspberry Pi Pico.

- Compile o código utilizando o CMake.

- Carregue o arquivo binário no Raspberry Pi Pico.

- Conecte-se ao dispositivo via terminal para visualizar as mensagens de saída.

### Vídeo Demonstrativo

Houve uma adaptação no código para poder rodar na placa, como o pino 12 na placa é relacionado ao led azul, para aparecer o amarelo foi necessario acender os pinos vermelho e verde. As duas versões estão na função que liga o led amarelo.

https://drive.google.com/file/d/1-zwQf9pStACR-k7H2gh22_AJxc4W6kv4/view?usp=drive_link

## Temp_Oneshot

Este projeto implementa um sistema de controle de LEDs. Ele permite acender três LEDs e desligá-los sequencialmente ao pressionar um botão.

### Configuração dos Pinos

Os LEDs e o botão estão conectados aos seguintes pinos GPIO do Raspberry Pi Pico:

- LED Vermelho: GPIO 13

- LED Azul: GPIO 12

- LED Verde: GPIO 11

- Botão: GPIO 5

### Funcionamento

O programa inicializa os pinos como saída para os LEDs e entrada para o botão.

Quando o botão é pressionado, todos os LEDs acendem simultaneamente.

Após 3 segundos, os LEDs são desligados um por um na ordem: Azul → Vermelho → Verde.

O botão fica desativado enquanto os LEDs estão apagando para evitar múltiplas execuções.

O sistema imprime mensagens no terminal indicando o status dos LEDs.

### Como Compilar e Executar

- Instale o SDK do Raspberry Pi Pico.

- Compile o código utilizando o CMake.

- Carregue o arquivo binário no Raspberry Pi Pico.

### Vídeo Demonstrativo

Na placa a cor do led RGB indica a quantidade de leds acesos e quais são:
- 3 leds acesos: cor Branca
- 2 leds acesos: cor Amarela
- 1 led aceso: cor Verde

Lembrando que segue a ordem de desligamento: Azul -> Vermelho -> Verde.

https://drive.google.com/file/d/109ESAt4p6ydLrz3hQTttK4vCZ6qELgxj/view?usp=drive_link

