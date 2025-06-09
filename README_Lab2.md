
# Laboratorio 2: Sensores, Percepción y Planificación Básica

### Integrantes: Bruno Toro, Davor Serey, Ignacio Silva

## Parte 1

### 1. ¿Qué es la percepción en robótica y por qué es fundamental en los sistemas autónomos?
**Respuesta:**  
La percepción es la capacidad de un robot para obtener e interpretar información del entorno mediante sensores. Es fundamental porque permite al robot tomar decisiones informadas y adaptarse a su entorno sin intervención humana.

### 2. En el sensor ultrasónico HC-SR04 ¿Qué parámetro se mide para calcular la distancia?
**Respuesta:**  
El sensor mide el tiempo que tarda una onda ultrasónica en ir desde el emisor hasta un obstáculo y regresar al receptor. A partir de este tiempo se calcula la distancia usando la fórmula:  
> distancia = (tiempo * velocidad del sonido) / 2

### 3. ¿Cómo influye el ruido en las mediciones del sensor ultrasónico y cómo podría reducirse?
**Respuesta:**  
El ruido genera lecturas inestables o erróneas. Puede deberse a reflejos irregulares, interferencias u objetos muy pequeños. Se puede reducir mediante técnicas de filtrado como promedios móviles, eliminación de valores atípicos o múltiples mediciones consecutivas.

---

## Parte 2

### 1. Si el robot detecta el color rojo en el suelo ¿Qué acción debería tomar? ¿Por qué?
**Respuesta:**  
El robot debería girar a la izquierda. El rojo se puede usar como señal de alerta o desvío en el entorno, por lo que el robot debe cambiar de trayectoria para evitar zonas críticas o peligrosas.

### 2. Si el sensor ultrasónico detecta valores erráticos ¿Qué estrategias podrías aplicar para mejorar la precisión?
**Respuesta:**  
- Filtrar los datos usando medias móviles o mediana.
- Realizar múltiples mediciones y usar la más confiable.
- Asegurar que no haya superficies inclinadas o absorbentes.
- Reducir vibraciones o interferencias mecánicas.

### 3. Si tuvieras que integrar un nuevo sensor para mejorar la navegación del robot ¿Cuál elegirías y por qué?
**Respuesta:**  
Un sensor LIDAR, ya que proporciona mapas más detallados del entorno con mayor precisión, permitiendo una mejor planificación y navegación, incluso en entornos complejos.

### 4. ¿Cuál es el tiempo de respuesta del robot al detectar un cambio de color?
**Respuesta:**  
El tiempo de respuesta depende del ciclo de lectura del sensor y del código implementado, pero típicamente está entre 100 y 300 milisegundos, dependiendo del retardo de lectura y procesamiento en el loop.

---
