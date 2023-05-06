//@version. 1.0.0 
//Last to modify: @bryan 
/**Descripción: 
 * Archivo para programar el sensor de humedad
 * 
*/
const int sensorPin = A0;
const int HUMEDAD_MINIMA = 500;
void setup() {
  //Iniciar comunicacion serial entre arduino y pc 9600 es la velocidad de
  //transmisión de datos a través del puerto serie. (9600 baudios)
  Serial.begin(9600);
}
void loop() {
  //se crea va
  int humedad = analogRead(sensorPin);
  Serial.println(humedad);
  if(humedad < HUMEDAD_MINIMA){
    Serial.println("Regando planta");
    //llamar a función de bomba
  }
  delay(1000);
  
  
}
