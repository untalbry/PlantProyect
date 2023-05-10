//@version. 1.0.2
//Last to modify: @bryan
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
  //se crea variable de conductivilidad que recibe los valores del sensor 
  int conductivilidad = analogRead(sensorPin);
  //Convertimos la variable anterior a un porcentaje de humedad 
  //Donde 0 es el valor máximo de humedad y 1024 el valor mínimo
  int humedad = map( conductivilidad, 1024, 0, 0, 100);
  
  Serial.print("Conductivilidad 0-1024 : ");
  Serial.print(conductivilidad);
  Serial.print(" humedad: ");
  Serial.print(humedad);
  Serial.println("%");
  //Si la humedad es menor al que debe de tener la planta en cuestión
  //Se prende la bomba para regar la planta. 
  if(humedad < HUMEDAD_MINIMA){
    Serial.println("Regando planta");
    //llamar a función de bomba
  }
  
  delay(1000);
  
  
}
