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

https://drive.google.com/file/d/1-zwQf9pStACR-k7H2gh22_AJxc4W6kv4/view?usp=drive_link



