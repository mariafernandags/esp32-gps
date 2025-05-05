# ESP32 GPS Project

## Visão Geral

Este projeto demonstra como integrar um módulo GPS MTK3339 com um microcontrolador ESP32 utilizando a biblioteca TinyGPS++. O sistema é capaz de ler e exibir em tempo real:

- **Coordenadas geográficas**: latitude e longitude  
- **Data e hora**: fornecidas pelo sinal de satélite  
- **Status dos satélites**: número de satélites visíveis e qualidade do sinal  

A comunicação entre o ESP32 e o módulo GPS é realizada via UART, e os dados são exibidos no monitor serial, facilitando o monitoramento e a análise em tempo real.

## Componentes Necessários

- ESP32 DevKit  
- Módulo GPS MTK3339 (ou compatível)  
- Jumpers macho-macho  
- Fonte de alimentação adequada (por exemplo, USB)  

## Conexões do Circuito

- **VCC** do GPS → **3.3V** do ESP32  
- **GND** do GPS → **GND** do ESP32  
- **TX** do GPS → **RX2 (GPIO16)** do ESP32  
- **RX** do GPS → **TX2 (GPIO17)** do ESP32  

> **Nota**: Certifique-se de que o módulo GPS opera em 3.3V. Caso contrário, utilize um conversor de nível lógico para evitar danos ao ESP32.

## Bibliotecas Utilizadas

- [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus): Biblioteca para parsing de dados NMEA provenientes do GPS.  
- [HardwareSerial](https://www.arduino.cc/en/Reference/HardwareSerial): Biblioteca padrão do Arduino para comunicação serial.  

## Explicação do Código

- **Configuração**: Inicializa a comunicação serial com o computador e com o módulo GPS. Configura os pinos RX2 e TX2 do ESP32 para comunicação com o GPS.  
- **Loop Principal**: Lê os dados do GPS continuamente. Quando uma nova informação válida é recebida, exibe:
  - Latitude e longitude  
  - Data e hora atualizadas  
  - Número de satélites conectados  
  - Altitude (se disponível)  

## Como Utilizar

1. Conecte o hardware conforme descrito acima.  
2. Clone este repositório e abra o projeto na IDE de sua preferência (por exemplo, Arduino IDE ou PlatformIO).  
3. Instale as bibliotecas necessárias, se ainda não estiverem instaladas.  
4. Compile e envie o código para o ESP32.  
5. Abra o monitor serial com a taxa de baud correta (ex: 9600) para visualizar os dados em tempo real.  

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
