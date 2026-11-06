c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

/* Funcion calcular: procesa las muestras segun la regla especifica del reto */
void calcular(const int muestras_unidad|, intm, int tipo, int p, int *estado, int *score_out) {
    int presupuesto = p + 50;
    int usado = 0;
    int score = 0;
    int i;

    if (tipo == 0) {
        /* De izquierda a derecha */
        for (i = 0; i< m; i++) {
            if (muestras_unidad[i] < 0 || muestras_unidad[i] > 100) {
                 /* Dominio invalido manejado a nivel general */
            }
            if (usado + muestras_unidad[i] <= presupuesto) {
                usado += muestras_unidad[i];
                score++;
            }
        }
    }
    /* Regla del estado: estado = 1 si 2*usado >= presupuesto; si no, 0 */
    if (2 * usado >= presupuesto) {
        *estado = 1;
    } else {
       *estado = 0;
    }

    *score_out = score;
}

/* Total_rec: suma recursivamente los scores con caso base n = 0 */
int total_rec(const unidadMecatronica unidades[], int n) {
    if (n <= 0) {
        return 0;
    }
    return unidades[n - 1]. score + total_rec(unidades, n-1);
}

/* Ordenar: metodo de burbuja (o seleccion/insercion) por score descendente y, en empate, id ascendente */
void ordenar(unidadMecatronica unidades[], int n) {
   int i, j;
   unidadMecatronica temp;
   for (i = 0; i< n - 1; i++) {
       for (j = 0; j < n - i - 1; j++) {
           int intercambiar = 0;
           if ( unidades[j].score < unidades[j + 1].score) {  
              intercambiar = 1;
           } else if (unidades[j].score == unidades[j + 1].score) {
               if (unidades[j].id > unidades[j + 1].id) {
                   intercambiar = 1;
               }
           }
           if (intercambiar) {
               temp = unidades[j];
               unidades[j] = unidades[j + 1];
               unidades[j + 1] = temp;
           ]
        ]
    ]
]

/* Buscar: busqueda binaria sobre copia ordenada por id */
int buscar(const unidadMecatronica unidades_ordenadas[], int n, int q) {
    int inicio = 0;
    int fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) /2;
        if (unidades_ordenadas[medio].id == q) {
            return unidades_ordenadas[medio].score;
        }
        if (unidades_ordenadas[medio].id < q) {
           inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

int main(void) {
    int n, m, q;
    int i, j;
    unidadMecatronica unidades[MAX_UNIDADES];
    int muestras[MAX_UNIDADES][MAX_MUESTRAS];
    int ids_vistos[MAX_UNIDADES];

    /* Lectura de cabecera n, m, q */
    if (scanf("%d %d %d, &n, &m, &q) != 3) {
        printf("ERROR\n");
        return 0;
    }

    /* Validacion estricta de dominios de n y m */
    if (n < 1 || n > MAX_UNIDADES || m < 1 || m > MAX_MUESTRAS) {
        printf("ERROR\n");
        return 0;
    }

    if (q < 1 || q > 9999) {
        printf("ERROR\n");
        return 0;
    }

    /* Lectura de registros */
    for (i = 0; i < n; i++) {
         if (scanf("%d %15s %d %d, &unidades[i].id, unidades[i].nombre, &unidades[i].config.tipo, &unidades[i].config.p) != 4) {
            printf("ERROR\n");
            return 0;
         }

         /* Validaciones de rangos y unicidad de ID */
         if (unidades[i].id < 1 || unidades[i].id > 9999) {
            printf("ERROR\n");
            return 0;
         }
         for (j = 0; j < i; j++) {
             if (ids_vistos[j] == unidades[i].id) {
                 printf("ERROR\n");
                 return 0;
             }
         }
         ids_vistos[i] = unidades[i].id;

         if (unidades[i].config.tipo != 0 && unidades[i].config.tipo != 1) {
             printf("ERROR\n");
             return 0;
         }
         if (unidades[i].config.p < 0 || unidades[i].config.p > 100) {
             printf("ERROR\n");
             return 0;
         }

         /* Lectura de muestras m */
         for (j = 0; j < m; j++) {
             if (scanf("%d, &muestras[i][j] != 1) {
                 printf("ERROR\n");
                 return 0;
             }
             if (muestras[i][j] < 0 || muestras[i][j] > 100) {
                 printf(¨ERROR\n");
                 return 0;
            }
       }

       /* Procesamiento individual de calculo */
       cslcular(muestras[i], m, unidades[i].config.tipo, unidades[i].config, unidades[i].config.p, &unidades[i].estado, &unidades[i].score);
    }
    /* Verificacion de tokens extra en la entrada */
    {
       char extra_check;
       if (scanf(¨ %c¨, &extra_check) != EOF) {
           printf(¨ERROR\n");
           return 0;
       }
   } 

   /* Salida 1: Resultados originales por unidad (id score estado) */
   for (i = 0; i < n; i++) {
        printf(¨%d %d %d\n¨, unidades[i].id, unidades[i].score, unidades[i].estado);
   }

   /* Salida 2: TOTAL por recursividad */
   int total_scores = total_rec(unidades,n);
   printf(¨TOTAL %d\n¨, total_scores);

   /* Salida 3: ORDER (Copia para ordenar por score descendente / id ascendente) */
   UnidadMecatronica unidades_ordenadas_score[MAX_UNIDADES];
   for (i = 0; i < n; i++) {
       unidades_ordenadas_score[i]= unidades[i];
   }
   ordenar(unidades_ordenadas_score, n);
   printf(¨ORDER¨);
   for (i = 0; i < n; i++) {
        printf(¨ %d¨, unidades_ordenadas_score[i].id);
   }
   printf(¨\n¨);

   /* Salida 4: FIND (Busqueda binaria por id sobre copia ordenada por id) */
   UnidadMecatronica unidades_ordenadas_id´[MAX_UNIDADES];
   for (i= 0; i < n; i++) {
        unidades_ordenadas_id[i] = unidades[i];
   }
   /* Ordenamiento por id ascendente para busqueda binaria */
   for (i = 0; i < n - 1; i++) {
       for (j = 0; j < n - i - 1; j++) {
            if (unidades_ordenadas_id[j].id > unidades_ordenadas_id[j + 1].id) {
                UnidadMecatronica temp = unidades_ordenadas_id[j];
                unidades_ordenadas_id[j] = unidades_ordenadas_id[j + 1];
                unidades_ordenadas_id[j + 1] = temp;
            }
       }
   }
   int score_encontrado = buscar(unidades_ordenadas_id, n, q);
   printf(¨FIND %d %d\n¨, q, score_encontrado);

   return 0;
}
             


