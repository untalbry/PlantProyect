# PlantProyect
Automated irrigation system where the humidity of a plant is measured to analyze if it should be watered or not with Arduino Uno
## Process
<p>
 Necesitará un sensor de humedad FC-28:
 El higrómetro FC-28 es un sensor muy simple que mide la humedad de la tierra indirectamente calculando la conductividad de la tierra. Si puede conducir  electricidad, significa que la tierra está húmeda ya que el agua es un gran conductor.
</p>
<p align="center">
  <img src="https://user-images.githubusercontent.com/91161604/236649833-1d05623c-56a3-476a-8737-e717c4bbfdf6.PNG" alt="SENSOR">
</p>
**El FC-28 se distribuye con una placa de medición estándar que permite obtener la medición como valor analógico o como una salida digital, activada cuando la humedad supera un cierto umbral.
Los valores obtenidos van desde 0 sumergido en agua, a 1023 en el aire (o en un suelo muy seco). Un suelo ligeramente húmero daría valores típicos de 600-700. Un suelo seco tendrá valores de 800-1023.
La salida digital dispara cuando el valor de humedad supera un cierto umbral, que ajustamos mediante el potenciómetro. Por tanto, obtendremos una señal LOW cuando el suelo no está húmedo, y HIGH cuando la humedad supera el valor de consigna. **

## LM393 Comparador de Voltaje de Precisión
<p>
 Se ocupará un comparador de voltaje LM393, el cual es un circuito integrado doble diseñado para ser utilizado como comparador de voltaje de precisión, con capacidad de operación con suministro de fuente simple o doble. Este dispositivo nos ayuda a comprar dos señales e indicarnos cual es la mayor y la menor, se medirán niveles e indicaremos como queremos que funciones nuestro circuito, dependiendo si el nivel de entrada es mayor o menor.
</p>
 <p align="center">
   <img src="https://github.com/RommelGarcia/plantproyect_rommel/assets/95105657/7f68279a-92cb-4a93-993d-e89feb78e393" alt="COMPARADOR">
</p>

## Módulo L298N
<p>
 El módulo L298N permite controlar la velocidad y la dirección de dos motores de corriente continua a un motor paso a paso de una forma muy sencilla. Además, incluye un regulador de tensión que permite obtener del módulo una tensión de 5V, esto es ideal para alimentar al Arduino. Solo funciona si el módulo se alimenta con una tensión máxima de 12V.
</p>
 <p align="center">
   <img src="https://github.com/RommelGarcia/plantproyect_rommel/assets/95105657/e79abe3d-e6e6-4db1-927d-6d18c39cae99" alt="L298N">
</p>

## Módulo L298N
<p>
 Se utilizará un Arduino UNO para controlar toda la parte del proyecto, desde los servomotores hasta el display para mostrar los datos de los sensores de humedad. El Arduino estará programado desde un ordenador, donde se le indicará la forma de cómo medirán la conductividad de la tierra con valores de 0 a 1024 y respectivamente tendrán valores de porcentaje siendo 0 el 0% y 1024 el 100% de humedad dentro del cultivo. De igual manera, se controlarán los motores permitiendo dispersar y regar el agua cuando los valores de la tierra sean menores de lo aceptable para la planta en cuestión. 
El Arduino no se estará alimentando de una fuente de energía independiente con una pila de 12V sin necesidad de estar conectado a un enchufe, con la finalidad de utilizar los paneles solares como una fuente renovable para suministrarle energía a las pilas dentro del sistema.
</p>
 <p align="center">
   <img src="https://github.com/RommelGarcia/plantproyect_rommel/assets/95105657/3447bd81-8d8e-4a60-bba5-21ab3c1162f0" alt="ARDUINO">
</p>

# Software
<p>
Fusion 360
 <p>
  Dentro del software que utilizamos se encuentra Fusion 360, es una plataforma de software CAD, CAM, CAE y de circuitos impresos de modelado 3D basada en la nube para el diseño y la manufactura de productos donde se logra diseñar,  proyectar y crear amplios componentes electrónicos y las herramientas de diseño ahorrando tiempo y dinero, fabricando piezas más rápido. 
  Se diseñó un terreno irregular para la implementación del proyecto dentro del sembradío, utilizando las nuevas tecnologías, se mandó a imprimir el modelo en una impresora 3D para simular el trabajo a escala
</p>
 <p align="center">
   <img src="https://github.com/RommelGarcia/plantproyect_rommel/assets/95105657/ef87c76b-ae14-4b05-abc5-c8b3a228fe2a" alt="FUSION">
</p>







