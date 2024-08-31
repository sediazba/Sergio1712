## Modelar Sistemas Físicos con Cinder

<p align="center">
  <img src="https://libcinder.org/docs/_assets/images/cinder_logo.svg" alt="Cinder Logo" width="256" height="auto"/>
</p>

Este proyecto tiene como objetivo simular fenómenos físicos utilizando la biblioteca Cinder, asociada al lenguaje C++, para facilitar la visualización de movimientos presentes en la vida cotidiana y servir como herramienta en la construcción del pensamiento físico.

En la carpeta comprimida encontrarás cuatro directorios, cada uno correspondiente a uno de los ejemplos realizados (el código de cada uno estará en su respectiva carpeta "src"). Los ejemplos son:

1. **Harmonic Oscillator:** Este código simula un péndulo simple, con un cable de masa despreciable y una esfera conectada a este. Es análogo a lo que se hace en dinámica molecular, pero en lugar de calcular las fuerzas sobre la partícula, nos basamos en la frecuencia y aceleración angular asociadas al péndulo simple.

<p align="center">
  <img src="https://2.bp.blogspot.com/-jv4hhbzZhEY/WUfyp7WeHCI/AAAAAAAAFZY/BAUBcRV3KHMXUcCWVo1MxmcQTyO7al0dQCLcBGAs/s1600/pendulo.gif" alt="Péndulo en movimiento" width="30%">
</p>

2. **Helicoidal:** Aquí se ejecuta un movimiento helicoidal, donde se mueve con velocidad constante sobre el eje X, mientras que en los ejes Y y Z realiza un movimiento circular. Este código está inspirado en el movimiento de una carga puntual ante la presencia de un campo magnético constante. Las ecuaciones de movimiento en cada eje son la solución al sistema mencionado. Este programa permite representar movimientos cuando tenemos las ecuaciones de movimiento para cada eje por separado, como una parametrización del movimiento, todas en función del parámetro t, que representa el tiempo.

<p align="center">
  <img src="https://th.bing.com/th/id/R.0fa11e3f196b8a820b0059f4a062f46c?rik=rx1ph%2f%2bbzwI5Wg&riu=http%3a%2f%2fimage.sciencenet.cn%2fhome%2f202309%2f10%2f170657iwb2nn55kq5onpqk.jpg&ehk=Xd8ZjaAWkuFs2UwRdFLx1SrYCuFmgtGnZFkA3wbz4XU%3d&risl=&pid=ImgRaw&r=0" alt="Descripción de la imagen" width="30%">
</p>

3. **Spring:** Este ejemplo muestra el movimiento de un oscilador armónico simple, similar al primer caso, pero la variación es que el movimiento se da solo en el eje horizontal, simulando una masa atada a un resorte.

<p align="center">
  <img src="https://images.hive.blog/DQmfS9Nsj3hUYcxsHDV6bZ5LhGknPF8Bo5jn3rUVsme9U67/fig5.gif" alt="Descripción del GIF" width="50%">
</p>

4. **Wall Collision:** En este código utilizamos lo aprendido en las clases del capítulo de Dinámica Molecular para modelar el movimiento de una partícula, afectada únicamente por la gravedad y las fuerzas ejercidas por las paredes. Es importante destacar que el origen de coordenadas se encuentra en la esquina superior izquierda, por lo que las expresiones para los "delta" varían. También, suponemos que las paredes son los bordes de la ventana de OpenGL que se habilita al ejecutar el programa.

<p align="center">
  <img src="https://th.bing.com/th/id/R.d327726ee36538a8698de27f70a408a3?rik=wKYcVLjGCexcgQ&riu=http%3a%2f%2f3.bp.blogspot.com%2f-T23_PfNYhc0%2fUqDY3h3TvnI%2fAAAAAAAAFI0%2f39DiH9qYYdM%2fs200%2fgas-animado.gif&ehk=mLoXCnIhXNaJX2o1Wzb2kcZIUztCSAwiKTNJeDbL1og%3d&risl=&pid=ImgRaw&r=0" alt="Descripción del GIF" width="30%">
</p>

## Instrucciones de Compilación y Ejecución

1. Descarga la biblioteca [Cinder](https://www.libcinder.org/).

2. Descarga la carpeta comprimida llamada **Final_Project.zip**.

3. Mueve la carpeta al directorio donde descargaste Cinder. Allí encontrarás muchas carpetas; verifica si está la carpeta "samples" para confirmar la ubicación correcta.

4. Extrae los elementos de la carpeta comprimida; debería aparecer una carpeta con el mismo nombre que el archivo .zip.

5. Dentro de esta carpeta encontrarás otras cuatro carpetas con los nombres de los cuatro ejemplos desarrollados para el proyecto final. Ahora sigue estos pasos en la terminal:

    a. Usando el comando "cd", navega hasta la carpeta del ejemplo que deseas ejecutar. Dentro de esta, ingresa a la carpeta "proj" y luego a la carpeta "cmake".

    b. Inserta el comando `cmake .`

    c. Inserta el comando `make`

    d. Ya hemos compilado el programa. Para ejecutarlo, usa `./Debug/nombre_programa/nombre_programa`.  
    Por ejemplo, si ingresaste a "Harmonic_Oscillator", ejecuta el programa con `./Debug/Harmonic_Oscillator/Harmonic_Oscillator`.

    e. A continuación, aparecerá la ventana de OpenGL con la ejecución del programa.

## Enlace del Video

**Nota:** El enlace que encontrará a continuación corresponde a la explicación teórica de nuestro proyecto, las transformaciones en OPEN GL, los CmakeList, entre otras características importantes. La parte de programación y visualización de los códigos se hará en la clase directamente.