# ParkGuardian - Monitoramento de Vagas de Estacionamento

## Descrição:

O ParkGuardian é um projeto que utiliza sensores de proximidade conectados a microcontroladores Arduino para monitorar vagas de estacionamento em tempo real. Com base nos dados coletados, o sistema informa aos motoristas a disponibilidade de vagas nas ruas, ajudando a reduzir o tempo gasto na busca por estacionamento, diminuir o congestionamento e melhorar a mobilidade urbana.

Este é um projeto do Cidades Inteligentes, programa de extensão do Centro Universitário UNA campus Betim.

## Componentes:

- Arduino (ex. Arduino Uno)
- Sensores de proximidade (ex. sensor ultrassônico HC-SR04)
- Módulo Wi-Fi (ex. ESP8266)
- Conexão à internet (Wi-Fi)
- Placa de circuito impresso (PCB)
- Bateria ou fonte de alimentação externa (para operação autônoma)

## Funcionamento:

O Arduino é responsável por medir a distância entre o sensor de proximidade e um possível veículo estacionado. Com base nessa medida, o sistema determina a disponibilidade da vaga:

- Distância < 10 cm: A vaga está ocupada.
- Distância >= 10 cm: A vaga está livre.

Os dados são enviados para um servidor web, que processa e disponibiliza as informações para o aplicativo ParkGuardian, onde os motoristas podem visualizar as vagas disponíveis em um mapa em tempo real.

## Montagem:

1. Conecte o sensor de proximidade ao Arduino conforme o esquema de pinagem especificado no código.
2. Configure o módulo Wi-Fi (ESP8266) para se conectar a uma rede Wi-Fi disponível.
3. Instale os sensores e o Arduino em uma localização adequada para monitorar as vagas de estacionamento.
4. Certifique-se de que o Arduino está corretamente alimentado por uma bateria ou fonte de alimentação externa.

## Integração com Servidor Web:

- O sistema envia os dados de disponibilidade das vagas para um servidor web em tempo real.
- O servidor web armazena e organiza os dados, que são acessados pelo aplicativo ParkGuardian para fornecer informações atualizadas aos motoristas.

## Licença:

Este projeto é disponibilizado sob a licença [MIT](https://opensource.org/licenses/MIT).
