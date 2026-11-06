c

#ifndef RETO_H
#define RETO_H

#define MAX_UNIDADES 20
#define MAX_MUESTRAS 8
#define MAX_NOMBRE 16

/*Estructura de configuracion anidada */
typedef struct {
  int tipo;    /* 0: izquierda a derecha, 1: derecha a izquierda */
  int p;       /* parametro base para el presupuesto ( p + 50 )  */
} Configuracion;

/* Estructura principal del registro de la unidad mecatronica */
typedef struct {
  int id;
  char nombre[MAX_NOMBRE];
  configuracion config;
  int score;
  int estado;
} unidadMecatronica;

/*Prototipos de funciones obligatorias y auxiliares */
void calcular(const int muestras_unidad|, int m, int tipo, int p, int *estado, int *score_out)
int total_rec(const unidadMecatronica unidades|, int n);
void ordenar(unidadMecatronica unidades|, int n);
int buscar(const unidadMecatronica unidades_ordenadas|, int n, int q);
int validar_y_procesar(void);

#endif /* RETO_H */.
