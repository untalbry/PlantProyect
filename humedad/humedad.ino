//@version. 1.0.4
//Last to modify: @bryan
/**Descripción: 
 * Archivo para programar el sensor de humedad
 * 
 * Modificaciones: Añadir funcionamiento del módulo L298N con dos sensores de humedad
 * Pasando a codigo funcional: agregando funciones setBomba y printHumety 
*/

const int sensorPin = A0;
const int ENA_PIN = 6; // pin ENA del módulo L298N
const int IN1_PIN = 7; // pin IN1 del módulo L298N 
const int IN2_PIN = 8; // pin IN2 del módulo L298N
const int ENB_PIN = 9; // pin ENB del módulo L298N
const int IN3_PIN = 10; // pin IN3 del módulo L298N 
const int IN4_PIN = 11; // pin IN4 del módulo L298N

const int HUMEDAD_MINIMA = 60; //valor máximo

void setup() {
  //Iniciar comunicacion serial entre arduino y pc 9600 es la velocidad de
  //transmisión de datos a través del puerto serie. (9600 baudios)
  Serial.begin(9600);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

}
void setBomba(int PIN){
      Serial.println("Regando planta");
      digitalWrite(PIN, HIGH);
}

void printHumety(int sensor, int humedad){
  Serial.print("Conductivilidad 0-1024 : ");
  Serial.print(sensor);
  Serial.print(" humedad: ");
  Serial.print(humedad);
  Serial.println("%");
}
void loop() {
  digitalWrite(ENA_PIN, HIGH); // Habilita el módulo L298N
  digitalWrite(IN2_PIN, LOW); //Habilita el puerto 1N2 en BAJO
  digitalWrite(IN4_PIN, LOW); //Habilita el puerto 1N4 en BAJO

  //se crea variable de conductivilidad que recibe los valores del sensor 
  int sensor1 = analogRead(sensorPin);
  int sensor2 = analogRead(sensorPin);

  //Convertimos la variable anterior a un porcentaje de humedad 
  //Donde 0 es el valor máximo de humedad y 1024 el valor mínimo
  int humedad1 = map( sensor1, 1024, 0, 0, 100);
  int humedad2 = map( sensor2, 1024, 0, 0, 100);
  
  printHumety(sensor1, humedad1);
  printHumety(sensor2, humedad2);

  //Si la humedad es menor al que debe de tener la planta
  //Colocamos HIGH al pin de la bomba1. 
  if(humedad1 < HUMEDAD_MINIMA){
    setBomba(IN1_PIN);
  }else{
    digitalWrite(IN1_PIN, LOW); //Habilita el puerto 1N2 en BAJO
  }
  
  if(humedad2 < HUMEDAD_MINIMA){
     setBomba(IN3_PIN);
  }else{
    digitalWrite(IN3_PIN, LOW); //Habilita el puerto 1N2 en BAJO
  }
  
  delay(2000); 
}
