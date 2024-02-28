# FT_PRINTF (Emula el comportamiento de `printf`)
He realizado tres versiones de este ejercicio, una más propia para aplicar en el
examen y otras dos más eficientes que manejan un buffer para evitar llamar a la
función write una y otra vez.
- [Primera versión (No maneja buffer)](./ft_printf.c)
- [Segunda versión (Maneja buffer estático)](./ft_printf_improved_with_static_buffer.c)
- [Tercera versión (Maneja buffer dinámico)](./ft_printf_improved_with_dynamic_buffer.c)

## Primera versión

## Segunda versión

## Tercera versión

## Rendimiento y tests realizados

```bash
grep "The program took" test_simple_*.txt | awk '{print $4}' > results_simple.txt
grep "The program took" test_simple_*.txt | awk '{print $4}' | awk '{sum += $1} END {print "Total: " sum " milliseconds"; print "Average: " sum/10 " milliseconds"}' >> results_simple.txt

grep "The program took" test_loop_*.txt | awk '{print $4}' > results_loop.txt
grep "The program took" test_loop_*.txt | awk '{print $4}' | awk '{sum += $1} END {print "Total: " sum " milliseconds"; print "Average: " sum/10 " milliseconds"}' >> results_loop.txt
```