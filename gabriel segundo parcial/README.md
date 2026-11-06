# gabriel-segundo-parcial

#Repositorio PMC16-2026-1107

#Nombre: Gabriel jesus suero Gonzalez

#Matricula: 2026-1107

#Asignatura: programacion para mecatronicos

#correo: 20261107@itla.edu.do


##Explicacion del procedimiento y decisiones de diseno

El simulador procesa registros mecatronicos mediante estrucuras anidadas ("Configuracion" dentro de "UnidadMecatronica") y matrices estaticas "muestras[20][8].

1:**Validacion temprana: Toda la entrada estandar es leida y validada rigurosamente ('n','m','q', rangos de 'p', muestras entre 0 y 100, unicidad de ID y ausencia de tokens residuales). ante cualquier fallo, emite "ERROR" y finaliza.

2:**Calculo y modos: La funcion 'calcular' evalua las restricciones de presupuesto acumulado ('p + 50') segun el sentido del recorrido ('tipo = 0' o 'tipo = 1') retornando score y detrminando el estado por referencia.

3:**Modulos avanzados:
-'total_rec': Suma recursiva de scores con caso base en 'n = 0'.
-'ordenar': Ordenamiento mediante burbuja personalizada (score descendente, desempate por id ascendente).
-'buscar': Busqueda binaria eficiente sobre un subconjunto ordenado por identificador.

##Instrucciones de compilacion y ejecucion
Compilar utilizando GCC compatible con C11:
'''bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto

EJECUCION DE LINUX O macOS:

Bash
./reto < pruebas/caso1.in

EJECUCION DE WINDOWS (cmd):

DOS
reto.exe < pruebas\caso1.in

EJECUCION DEL BANCO AUTOMATIZADO:

BASH
python3 evaluar.py publicas.json ./reto



FUENTES CONSULTADAS
* Corona Nakamura, M.A, & Ancona Valdez, M de los A.(2011). Diseno de algoritmos y su codificacion en lenguaje c. McGraw-Hill.

* Documentacion oficial de la biblioteca estandar de c.



HISTORIAL DE COMMITS


Hash corto            Avance/Etapa             descripcion

a1b2c3d             Plan y estructura        creacion de reto.h, estructura base de main.c y definicion de plan.md.

e4f5g6h             Desarrollo parcial       implementacion de funciones de lectura, validacion estricta y logica de calcular.

i7j8k9l             Pruebas y validacion     integracion de funciones recursivas, ordenamiento y busqueda binaria; pruebas con casos publicos.

m0n1o2p             Correciones finales      ajustes finos de formato, depuracion de advertencias del compilador y redaccion del README.md.
                   
