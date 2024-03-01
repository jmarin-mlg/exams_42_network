# FT_PRINTF (Emula el comportamiento de `printf`)
He realizado tres versiones de este ejercicio, una más propia para aplicar en el
examen y otras dos más eficientes que manejan un buffer para evitar llamar a la
función write una y otra vez.
- [Primera versión (No maneja buffer)](./ft_printf.c)
- [Segunda versión (Maneja buffer estático)](./ft_printf_improved_with_static_buffer.c)
- [Tercera versión (Maneja buffer dinámico)](./ft_printf_improved_with_dynamic_buffer.c)

Con cualquiera de ellas, aprobarás el examen. ¿Cúal utilizarás tú?

## Primera versión
Está es la versión para rápida de escribir y la que seguramente utilizaría la
gran mayoria de alumnos de `42 Network`. En contra-partida es la menos eficiente
de todas, dado que utilizamos la función `write()` para imprimir por pantalla
todos y cada uno de los caracteres que nos llegan a nuestra funcición
`ft_printf`. En esta versión no se utiliza ningún tipo de `BUFFER`.

## Segunda versión
En esta versión utilizamos un `BUFFER estático`, definiendo un tamaño fijo.
Para ello hacemos uso de la macro `BUFFER_SIZE` con un valor pre-definido
pero que podrá ser modificado en la compilación y tomar los valores entre
1 y 1024.

Con esta versión conseguimos no hacer un uso excesivo y recurrente de la
función `write()`, dado que solamente se hará uso de ella al final del
programa o bien cuando pudiera haber desbordamiento del buffer.

## Tercera versión
En esta versión utilizamos un `BUFFER dinámico`, gracias al uso de punteros
y a la reserva de memoria con `malloc()` podemos calcular exactamente el tamaño
del `BUFFER` que vamos a necesitar escribir.

Podriamos pensar que está es la versión más eficiente de las tres, pero después
de analizar la tabla de rendimiento podemos observar que la versión con
`BUFFER estático` es más rápida que está.

Seguramente mi código se pueda optimizar mucho más y finalmente el buffer
dinámico gane al estático o no?, estaría encantado de recibir vuestras
versiones o modificaciones sobre estás para mejorar el rendimiento que como
era de esperar dista mucho del rendimeinto de la función original `printf()`.

## Tests realizados
Se han utilizado para estos tests los ordenadores `Macintosh` de `42 Málaga` y
mi ordenador personal con sistema operativo `Linux`. Podeis hacer más tests en
diferentes ordenadores y visualizar/contrastar vuestros resultados.

Lo primero de todo es compilar los ficheros *.c para generar los ficheros `bin`
generarán los ejecutables. Para estas pruebas he creado un [main.c](./main.c)
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
