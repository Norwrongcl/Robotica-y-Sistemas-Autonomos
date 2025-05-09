# 🧪 Laboratorio de Robótica y Sistemas Autónomos  
### Integrantes: Bruno Toro, Davor Serey, Ignacio Silva

## Parte 1

### 1. ¿Qué función cumplen los sensores, actuadores y controladores en el robot?

**Respuesta:**  
- **Sensores:** Permiten al robot percibir su entorno y su propio estado (distancias, orientación, velocidad, etc.).  
- **Actuadores:** Ejecutan acciones físicas, como mover ruedas o girar servos.  
- **Controladores:** Procesan la información de los sensores y deciden qué acciones realizar, enviando señales a los actuadores para ejecutar comportamientos deseados.

---

### 2. ¿Cómo se puede estimar la velocidad sin encoders?

**Respuesta:**  
La velocidad puede estimarse indirectamente midiendo el tiempo que el robot tarda en recorrer una distancia conocida, usando sensores como el ultrasónico (para detectar distancia a obstáculos) o una IMU (para detectar aceleración). También se puede usar el tiempo y el valor de PWM aplicado, si se conoce previamente cómo responde el motor.

---

### 3. ¿Cómo afecta la falta de encoders a la precisión del movimiento?

**Respuesta:**  
Sin encoders, el robot pierde la capacidad de medir con precisión el desplazamiento real de sus ruedas, lo que genera errores acumulativos en la navegación. Esto afecta la capacidad de seguir trayectorias exactas, estimar distancias recorridas o corregir desvíos, especialmente en entornos dinámicos o con trayectorias complejas.

---

### 4. ¿Qué es PWM y cómo ayuda a controlar la velocidad de los motores?

**Respuesta:**  
PWM (Pulse Width Modulation) es una técnica para controlar la potencia promedio que se entrega a un motor, alternando entre encendido y apagado a alta velocidad. Al variar el ciclo de trabajo (duty cycle), se puede aumentar o disminuir la velocidad del motor sin necesidad de cambiar el voltaje.

---

### 5. ¿Cómo afecta el control de velocidad a la precisión de la navegación sin encoders?

**Respuesta:**  
Controlar la velocidad con PWM ayuda a mantener una velocidad constante y más predecible, pero sin retroalimentación (como la que proporcionan los encoders), los errores no se pueden corregir automáticamente. Esto limita la precisión en maniobras y trayectorias, ya que variaciones en carga, fricción o voltaje pueden alterar el comportamiento real sin ser detectadas.

---

## Parte 2

#### 1. ¿Cómo se calcula la velocidad del robot sin encoders usando PWM?

**Respuesta:**  
La velocidad se puede estimar midiendo el tiempo que el robot tarda en recorrer una distancia conocida bajo un cierto valor de PWM. Si se conoce la distancia recorrida y el tiempo, se puede aplicar:  
> velocidad = distancia / tiempo  

Este método requiere realizar pruebas experimentales para cada nivel de PWM y registrar la velocidad promedio asociada.

---

### 2. ¿Qué factores afectan la trayectoria y velocidad del robot al cambiar los intervalos de tiempo?

**Respuesta:**  
Al cambiar los intervalos de tiempo (duración del movimiento), se puede afectar:  
- La precisión del desplazamiento (más tiempo → más desviación posible).
- La estabilidad del robot, especialmente si hay variaciones en el terreno o batería.
- La respuesta del motor, ya que variaciones muy pequeñas pueden no generar movimiento apreciable y tiempos largos pueden acentuar errores.

---

### 3. ¿Cuáles son las ventajas y desventajas de usar un IMU para ajustar la dirección en lugar de encoders?

**Ventajas:**  
- Permite detectar orientación y cambios de dirección incluso si las ruedas patinan.  
- Útil en terrenos irregulares o donde los encoders no sean precisos.  
- Detecta inclinaciones y giros, lo que permite ajustes más completos del movimiento.

**Desventajas:**  
- Menor precisión en estimación de posición acumulada (deriva).  
- Requiere filtros y procesamiento adicional para obtener datos útiles.  
- Más sensible a vibraciones y ruidos mecánicos.

---

### 4. ¿Qué efecto tiene la inclinación o el giro en el movimiento del robot, y cómo se corrige con el IMU?

**Respuesta:**  
La inclinación o el giro puede desviar al robot de su trayectoria esperada. Esto es especialmente crítico en movimientos lineales o maniobras precisas. El IMU detecta estos cambios en orientación (roll, pitch, yaw) y permite aplicar correcciones en tiempo real, ajustando la velocidad de los motores para mantener la dirección deseada.

---

