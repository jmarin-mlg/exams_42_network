# FT_PRINTF (Emula el comportamiento de `printf`)
He realizado tres versiones de este ejercicio, una más propia para aplicar en el
examen y otras dos más eficientes que manejan un buffer y evitar llamar a la
función `write()` una y otra vez.
- [Primera versión (No maneja buffer)](./ft_printf.c)
- [Segunda versión (Maneja buffer estático)](./ft_printf_improved_with_static_buffer.c)
- [Tercera versión (Maneja buffer dinámico)](./ft_printf_improved_with_dynamic_buffer.c)

Con cualquiera de ellas, aprobarás el examen. ¿Cúal utilizarás tú?

## [Primera versión](./ft_printf.c)
Está es la versión más rápida de escribir y la que seguramente utilizaría la
gran mayoria de alumnos de `42 Network`. En contra-partida es la menos eficiente
de todas, dado que utilizamos la función `write()` para imprimir por pantalla,
todos y cada uno de los caracteres que nos llegan a nuestra funcición
`ft_printf`. En esta versión no se utiliza ningún tipo de `BUFFER`.

## [Segunda versión](./ft_printf_improved_with_static_buffer.c)
En esta versión utilizamos un `BUFFER estático`, definiendo un tamaño fijo.
Para ello hacemos uso de la macro `BUFFER_SIZE` con un valor pre-definido
pero que podrá ser modificado en la compilación y tomar los valores entre
1 y 1024.

En esta versión conseguimos no hacer un uso excesivo y recurrente de la
función `write()`, dado que solamente se hará uso de ella al final del
programa o bien cuando pudiera haber desbordamiento del buffer.

## [Tercera versión](./ft_printf_improved_with_dynamic_buffer.c)
En esta versión utilizamos un `BUFFER dinámico`, gracias al uso de punteros
y a la reserva de memoria con `malloc()` podemos calcular exactamente el tamaño
del `BUFFER` que vamos a necesitar escribir.

Podriamos pensar que está es la versión más eficiente de las tres, pero después
de analizar la tabla de rendimiento podemos observar que la versión con
`BUFFER estático` es más rápida que está.

Seguramente mi código se pueda optimizar mucho más y finalmente el buffer
dinámico gane al estático o no?, estaría encantado de recibir vuestras
versiones o modificaciones sobre estás para mejorar el rendimiento, que como
era de esperar dista mucho del rendimiento de la función original `printf()`.

## Tests realizados
Se han utilizado para estos tests los ordenadores `Macintosh` de `42 Málaga` y
mi ordenador personal con sistema operativo `Linux`. Podeis hacer más tests en
diferentes ordenadores y visualizar/contrastar vuestros propios resultados.

Lo primero de todo, es compilar los ficheros *.c para generar los ficheros `bin`
que ejecutarán el programa. Para estas pruebas he creado un [main.c](./main.c)
que utiliza dos macros:
- `ORIGINAL_PRINTF`: Si esta macro se define, se utilizará la función original
`printf` de `C`. De lo contrario, utilizará nuestra función `ft_printf`.
- `LOOP`: Por defecto su valor es 1, pero podemos definirle el número de vueltas
que deseemos, muy util para medir el rendimiento del programa.

### Tests en MAC
```bash
# Compilación (partiendo del directorio raíz de este repositorio)
cd ./rank_03/ft_printf
mkdir -p bin/mac

gcc -Wall -Werror -Wextra -o ./bin/mac/printf_original main.c -D ORIGINAL_PRINTF
gcc -Wall -Werror -Wextra -o ./bin/mac/printf_original_loop_100k main.c -D ORIGINAL_PRINTF -D LOOP=100000

gcc -Wall -Werror -Wextra -o ./bin/mac/exam_version main.c ft_printf.c
gcc -Wall -Werror -Wextra -o ./bin/mac/exam_version_loop_100k main.c ft_printf.c -D LOOP=100000

gcc -Wall -Werror -Wextra -o ./bin/mac/static_buffer_version main.c ft_printf_improved_with_static_buffer.c
gcc -Wall -Werror -Wextra -o ./bin/mac/static_buffer_version_loop_100k main.c ft_printf_improved_with_static_buffer.c -D LOOP=100000

gcc -Wall -Werror -Wextra -o ./bin/mac/dynamic_buffer_version main.c ft_printf_improved_with_dynamic_buffer.c
gcc -Wall -Werror -Wextra -o ./bin/mac/dynamic_buffer_version_loop_100k main.c ft_printf_improved_with_dynamic_buffer.c -D LOOP=100000

# Generamos los ficheros de textos de test
mkdir -p tests/mac/printf
mkdir -p tests/mac/ft_printf/exam_version
mkdir -p tests/mac/ft_printf/static_buffer_version
mkdir -p tests/mac/ft_printf/dynamic_buffer_version

./bin/mac/printf_original > ./tests/mac/printf/test_simple_01.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_02.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_03.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_04.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_05.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_06.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_07.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_08.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_09.txt
./bin/mac/printf_original > ./tests/mac/printf/test_simple_10.txt

./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_01.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_02.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_03.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_04.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_05.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_06.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_07.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_08.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_09.txt
./bin/mac/printf_original_loop_100k > ./tests/mac/printf/test_loop_100k_10.txt

./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_01.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_02.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_03.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_04.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_05.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_06.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_07.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_08.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_09.txt
./bin/mac/exam_version > ./tests/mac/ft_printf/exam_version/test_simple_10.txt

./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_01.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_02.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_03.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_04.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_05.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_06.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_07.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_08.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_09.txt
./bin/mac/exam_version_loop_100k > ./tests/mac/ft_printf/exam_version/test_loop_100k_10.txt

./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_01.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_02.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_03.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_04.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_05.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_06.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_07.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_08.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_09.txt
./bin/mac/static_buffer_version > ./tests/mac/ft_printf/static_buffer_version/test_simple_10.txt

./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_01.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_02.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_03.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_04.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_05.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_06.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_07.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_08.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_09.txt
./bin/mac/static_buffer_version_loop_100k > ./tests/mac/ft_printf/static_buffer_version/test_loop_100k_10.txt

./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_01.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_02.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_03.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_04.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_05.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_06.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_07.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_08.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_09.txt
./bin/mac/dynamic_buffer_version > ./tests/mac/ft_printf/dynamic_buffer_version/test_simple_10.txt

./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_01.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_02.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_03.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_04.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_05.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_06.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_07.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_08.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_09.txt
./bin/mac/dynamic_buffer_version_loop_100k > ./tests/mac/ft_printf/dynamic_buffer_version/test_loop_100k_10.txt

# Por último, generamos los resultados de rendimiento
#
# Es necesario hacerlo en todos los directorios:
# 	./tests/mac/printf/
# 	./tests/mac/ft_printf/exam_version
# 	./tests/mac/ft_printf/static_buffer_version
# 	./tests/mac/ft_printf/dynamic_buffer_version
#
# Para no replicar código solamente pongo aquí el referente al directorio
# `./tests/mac/printf/`
cd ./tests/mac/printf/

grep "The program took" test_simple_*.txt | awk '{print $4}' > results_simple.txt
grep "The program took" test_simple_*.txt | awk '{print $4}' | awk '{sum += $1} END {print "Total: " sum " milliseconds"; print "Average: " sum/10 " milliseconds"}' >> results_simple.txt

grep "The program took" test_loop_*.txt | awk '{print $4}' > results_loop.txt
grep "The program took" test_loop_*.txt | awk '{print $4}' | awk '{sum += $1} END {print "Total: " sum " milliseconds"; print "Average: " sum/10 " milliseconds"}' >> results_loop.txt
```

### Test en Linux
Haremos exactamente lo mismo que en `MAC` pero sustituyendo el directorio
`./bin/mac` por `./bin/linux` y el directorio `./tests/mac` por `./tests/linux`.

## Tablas de rendimiento
A continuación, se muestran las tablas de rendimiento en `MAC` y `Linux`. Los
tiempos estan expresados en milisegundos.

### Comparativa de rendimiento (ordenado de más rápido a más lento)
| Macintosh        | LOOP 1 | LOOP 100.000 |
|:---------------- |-------:| ------------:|
| **printf**       | 0.0185 | 410.77       |
| **ft_printf V2** | 0.0637 | 3769.74      |
| **ft_printf V3** | 0.0872 | 4225.54      |
| **ft_printf V1** | 0.4523 | 34927.30     |

| Linux            | LOOP 1 | LOOP 100.000 |
|:---------------- |-------:| ------------:|
| **printf**       | 0.0672 | 280.95       |
| **ft_printf V2** | 0.1511 | 4997.52      |
| **ft_printf V3** | 0.2056 | 5358.83      |
| **ft_printf V1** | 0.8554 | 42971.50     |

### Resultado detallado de rendimiento en MAC
| printf (original) | LOOP 1       | LOOP 100.000   |
|:----------------- |-------------:| --------------:|
| Test 01           | 0.045000     | 393.925000     |
| Test 02        	| 0.014000     | 414.315000     |
| Test 03           | 0.017000     | 428.116000     |
| Test 04           | 0.016000     | 377.446000     |
| Test 05           | 0.016000     | 422.751000     |
| Test 06           | 0.016000     | 408.562000     |
| Test 07           | 0.016000     | 409.615000     |
| Test 08           | 0.016000     | 421.739000     |
| Test 09           | 0.015000     | 410.149000     |
| Test 10           | 0.014000     | 421.082000     |
| **Promedio**      | **0.018500** | **410.770000** |

| ft_printf V1      | LOOP 1       | LOOP 100.000     |
|:----------------- |-------------:| ----------------:|
| Test 01           | 0.782000     | 34822.787000     |
| Test 02        	| 0.431000     | 35149.036000     |
| Test 03           | 0.382000     | 35430.530000     |
| Test 04           | 0.437000     | 34788.135000     |
| Test 05           | 0.373000     | 34918.325000     |
| Test 06           | 0.434000     | 34837.441000     |
| Test 07           | 0.404000     | 34804.026000     |
| Test 08           | 0.427000     | 34844.578000     |
| Test 09           | 0.423000     | 34859.695000     |
| Test 10           | 0.430000     | 34818.826000     |
| **Promedio**      | **0.452300** | **34927.300000** |

| ft_printf V2      | LOOP 1       | LOOP 100.000    |
|:----------------- |-------------:| ---------------:|
| Test 01           | 0.064000     | 3668.616000     |
| Test 02        	| 0.063000     | 3729.567000     |
| Test 03           | 0.064000     | 3666.354000     |
| Test 04           | 0.063000     | 3772.011000     |
| Test 05           | 0.063000     | 3658.439000     |
| Test 06           | 0.064000     | 3738.971000     |
| Test 07           | 0.062000     | 3837.221000     |
| Test 08           | 0.064000     | 3762.047000     |
| Test 09           | 0.063000     | 3943.716000     |
| Test 10           | 0.067000     | 3920.417000     |
| **Promedio**      | **0.063700** | **3769.740000** |

| ft_printf V3      | LOOP 1       | LOOP 100.000    |
|:----------------- |-------------:| ---------------:|
| Test 01           | 0.145000     | 4197.109000     |
| Test 02        	| 0.099000     | 4147.678000     |
| Test 03           | 0.080000     | 4231.825000     |
| Test 04           | 0.079000     | 4260.759000     |
| Test 05           | 0.080000     | 4239.386000     |
| Test 06           | 0.080000     | 4259.341000     |
| Test 07           | 0.078000     | 4250.605000     |
| Test 08           | 0.080000     | 4234.868000     |
| Test 09           | 0.071000     | 4128.155000     |
| Test 10           | 0.080000     | 4305.708000     |
| **Promedio**      | **0.087200** | **4225.540000** |

### Resultado detallado de rendimiento en Linux
| printf (original) | LOOP 1       | LOOP 100.000   |
|:----------------- |-------------:| --------------:|
| Test 01           | 0.114000     | 277.132000     |
| Test 02        	| 0.055000     | 280.135000     |
| Test 03           | 0.121000     | 275.216000     |
| Test 04           | 0.056000     | 291.218000     |
| Test 05           | 0.061000     | 287.672000     |
| Test 06           | 0.058000     | 281.364000     |
| Test 07           | 0.058000     | 280.744000     |
| Test 08           | 0.049000     | 277.804000     |
| Test 09           | 0.049000     | 277.865000     |
| Test 10           | 0.051000     | 280.350000     |
| **Promedio**      | **0.067200** | **280.950000** |

| ft_printf V1      | LOOP 1       | LOOP 100.000     |
|:----------------- |-------------:| ----------------:|
| Test 01           | 1.018000     | 43083.780000     |
| Test 02        	| 0.885000     | 42845.071000     |
| Test 03           | 0.579000     | 42934.206000     |
| Test 04           | 0.708000     | 43312.922000     |
| Test 05           | 0.908000     | 42995.687000     |
| Test 06           | 1.625000     | 42899.746000     |
| Test 07           | 1.177000     | 42816.850000     |
| Test 08           | 0.576000     | 42885.484000     |
| Test 09           | 0.493000     | 42861.561000     |
| Test 10           | 0.585000     | 43079.909000     |
| **Promedio**      | **0.855400** | **42971.500000** |

| ft_printf V2      | LOOP 1       | LOOP 100.000    |
|:----------------- |-------------:| ---------------:|
| Test 01           | 0.109000     | 4999.432000     |
| Test 02        	| 0.111000     | 4978.743000     |
| Test 03           | 0.114000     | 4980.348000     |
| Test 04           | 0.250000     | 4989.026000     |
| Test 05           | 0.127000     | 4989.061000     |
| Test 06           | 0.102000     | 4989.525000     |
| Test 07           | 0.109000     | 5013.762000     |
| Test 08           | 0.242000     | 5002.742000     |
| Test 09           | 0.116000     | 4992.813000     |
| Test 10           | 0.231000     | 5039.718000     |
| **Promedio**      | **0.151100** | **4997.520000** |

| ft_printf V3      | LOOP 1       | LOOP 100.000    |
|:----------------- |-------------:| ---------------:|
| Test 01           | 0.318000     | 5337.811000     |
| Test 02        	| 0.133000     | 5323.561000     |
| Test 03           | 0.136000     | 5355.722000     |
| Test 04           | 0.293000     | 5359.072000     |
| Test 05           | 0.131000     | 5393.885000     |
| Test 06           | 0.093000     | 5340.052000     |
| Test 07           | 0.211000     | 5349.418000     |
| Test 08           | 0.333000     | 5384.893000     |
| Test 09           | 0.285000     | 5391.414000     |
| Test 10           | 0.123000     | 5352.512000     |
| **Promedio**      | **0.205600** | **5358.830000** |
