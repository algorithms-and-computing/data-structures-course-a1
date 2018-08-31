
# Ejercicios de Ordenamiento

Resuelve los siguientes ejercicios:

## _Problema 1_
Dado un numero _N_ de calificaciones, encuentra la mediana de dicho conjunto.

> En el ámbito de la estadística, la **mediana** representa el valor de la variable de posición central en un conjunto de datos ordenados.

**_Entrada:_**
El numero _N_ que representa la cantidad de las calificaciones.
_N_ números separados por un espacio que representan las calificaciones.

**_Salida:_**
Un unico número representando la mediana del conjunto de calificaciones.

**_Ejemplo:_**
_Entrada:_
9
100 80 70 85 64 50 90 76 92

_Salida:_
80

**_Explicaión:_**
Si ordenamos las calicicaciones encontraremos que el _**80**_ es el numero que está en el centro del conjunto.
_50 64 70 76 **80** 85 90 92 100_

**_Consideraciones:_**
1 ≤ N ≤ 10000
0 ≤ Calificación ≤ 100

---

## _Problema 2_
Una universidad quiere generar un reporte de las edades de sus alumnos de tal manera que cuando ellos pregunten por cierta edad, el programa les responda la cantidad de alumnos que tienen.

**_Entrada:_**
El numero _N_ que representa la cantidad de las edades.
_N_ números separados por un espacio que representan las edades.
El numero _k_ de preguntas/consultas.
_k_ consultas, donde se indica la edad de la que se desea conocer el número de alumnos.

**_Salida:_**
_k_ números representando la cantidad de estudiantes de la consulta _i_

**_Ejemplo:_**
_Entrada:_
14
20 21 18 17 25 16 20 28 32 21 24 20 18  17
3
20 17 26

_Salida:_
3 2 0

**_Explicaión:_**
Se nos indica que nos darán 14 edades, seguidas de 3 consultas, las cuales son las siguientes:
* _Alumnos de 20 años: 3_
* _Alumnos de 17 años: 2_
* _Alumnos de 26 años: 0_

**_Consideraciones:_**
1 ≤ N ≤ 10000
0 ≤ k ≤ 100000