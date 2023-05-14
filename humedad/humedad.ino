//@version. 1.0.4
//Last to modify: @bryan
/**Descripción: 
 * Archivo para programar el sensor de humedad
 * 
 * Modificaciones: Añadir funcionamiento del módulo L298N
*/

const int sensorPin = A0;
const int ENA_PIN = 6; // pin ENA del módulo L298N
const int IN1_PIN = 7; // pin IN1 del módulo L298N 
const int IN2_PIN = 8; // pin IN2 del módulo L298N

const int HUMEDAD_MINIMA = 60; //valor máximo
void setup() {
  //Iniciar comunicacion serial entre arduino y pc 9600 es la velocidad de
  //transmisión de datos a través del puerto serie. (9600 baudios)
  Serial.begin(9600);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

}

void loop() {
  digitalWrite(ENA_PIN, HIGH); // Habilita el módulo L298N
  digitalWrite(IN2_PIN, LOW); //Habilita el puerto 1N2 en BAJO
  //se crea variable de conductivilidad que recibe los valores del sensor 
  int sensor1 = analogRead(sensorPin);
  // int sensor2 = analogRead(sensorPin);

  //Convertimos la variable anterior a un porcentaje de humedad 
  //Donde 0 es el valor máximo de humedad y 1024 el valor mínimo
  int humedad1 = map( sensor1, 1024, 0, 0, 100);
  //int humedad2 = map( sensor2, 1024, 0, 0, 100);
  
  Serial.print("Conductivilidad 0-1024 : ");
  Serial.print(conductivilidad);
  Serial.print(" humedad: ");
  Serial.print(humedad);
  Serial.println("%");

  //Si la humedad es menor al que debe de tener la planta
  //Colocamos HIGH al pin de la bomba1. 
  if(humedad1 < HUMEDAD_MINIMA){
    Serial.println("Regando planta");
    digitalWrite(IN1_PIN, HIGH);// Configura IN1 en ALTO
  }else{
    digitalWrite(IN1_PIN, LOW);
  }
  
  delay(2000); 
}
