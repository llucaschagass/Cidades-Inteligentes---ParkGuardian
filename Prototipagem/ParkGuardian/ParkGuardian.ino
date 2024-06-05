#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Defina as credenciais do Wi-Fi
const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";

// Defina o URL do servidor web
const char* serverUrl = "http://seu_servidor.com/update";

// Defina os pinos do sensor ultrassônico
const int trigPin = D1;
const int echoPin = D2;

void setup() {
  // Inicialize a comunicação serial
  Serial.begin(115200);

  // Configure os pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Conecte-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi!");
}

void loop() {
  // Envie um pulso para o sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Le o tempo de retorno do pulso
  long duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em centímetros
  int distance = duration * 0.034 / 2;

  // Verifica se há um carro na vaga (por exemplo, se a distância é menor que 10 cm)
  bool vagaOcupada = distance < 10;

  // Cria a string de dados para enviar ao servidor
  String data = "vaga=" + String(vagaOcupada ? "ocupada" : "livre");

  // Envie os dados para o servidor web
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(data);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Erro ao enviar dados: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }

  // Aguarda um tempo antes de fazer a próxima leitura
  delay(5000);
}

