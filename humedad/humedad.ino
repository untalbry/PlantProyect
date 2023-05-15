//@version. 1.0.4
//Last modified by: @bryan
/**Description: 
 * File to program the humidity sensor
 * 
 * Modifications: Add functionality of the L298N module with two humidity sensors
 * Turning into functional code: adding setBomba and printHumety functions
*/

const int sensorPin1 = A0;
const int sensorPin2 = A1;

const int ENA_PIN = 6; // ENA pin of the L298N module
const int IN1_PIN = 7; // IN1 pin of the L298N module
const int IN2_PIN = 8; // IN2 pin of the L298N module
const int ENB_PIN = 9; // ENB pin of the L298N module
const int IN3_PIN = 10; // IN3 pin of the L298N module
const int IN4_PIN = 11; // IN4 pin of the L298N module

const int HUMEDAD_MINIMA = 60; // Minimum value

void setup() {
  // Start serial communication between Arduino and PC. 9600 is the data transmission
  // rate through the serial port. (9600 baud)
  Serial.begin(9600);
  
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);

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
  digitalWrite(ENA_PIN, HIGH); // Enable the L298N module
  digitalWrite(IN2_PIN, LOW); // Enable IN2 port as LOW
  digitalWrite(IN4_PIN, LOW); // Enable IN4 port as LOW

 // Create a conductivity variable that receives sensor values
  int sensor1 = analogRead(sensorPin1);
  int sensor2 = analogRead(sensorPin2);

  //Convertimos la variable anterior a un porcentaje de humedad 
  //Donde 0 es el valor máximo de humedad y 1024 el valor mínimo
  int humedad1 = map( sensor1, 1024, 0, 0, 100);
  int humedad2 = map( sensor2, 1024, 0, 0, 100);
  
  printHumety(sensor1, humedad1);
  printHumety(sensor2, humedad2);

 // If the humidity is lower than the required value for the plant
  // Set the pump1 pin to HIGH 
  if(humedad1 < HUMEDAD_MINIMA){
    setBomba(IN1_PIN);
  }else{
    digitalWrite(IN1_PIN, LOW); /// Enable IN2 port as LOW
  }
  // Set the pump2 pin to HIGH 
  if(humedad2 < HUMEDAD_MINIMA){
     setBomba(IN3_PIN);
  }else{
    digitalWrite(IN3_PIN, LOW); // Enable IN3 port as LOW
  }
  
  delay(2000); 
}
