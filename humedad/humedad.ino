//@version. 1.0.1
//Last to modify: @rommel
/**Descripción: 
 * Archivo para programar el sensor de humedad
 * 
 * Modificaciones: Agregar función map para el porcentaje de humedad
*/

const int sensorPin = A0;
const int HUMEDAD_MINIMA = 60; //valor máximo
void setup() {
  //Iniciar comunicacion serial entre arduino y pc 9600 es la velocidad de
  //transmisión de datos a través del puerto serie. (9600 baudios)
  Serial.begin(9600);
}
void loop() {
  //se crea variable de humedad y de porcentaje
  int humedad = map(analogRead(sensorPin), 1023, 0, 0, 100);
  Serial.print("humedad");
  Serial.print(humedad);
  Serial.println("%");
  Serial.print();
  if(humedad < HUMEDAD_MINIMA){
    Serial.println("Regando planta");
    //llamar a función de bomba
  }

  delay(1000);
  
  
}