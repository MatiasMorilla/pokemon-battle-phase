#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

enum gender { femenino = 1, masculino = 2 };

typedef struct _tipoNodo {
  int id;
  char nombre[MAX_LENGTH];
  int idDebilidades;

  struct _tipoNodo* siguiente;

} tipoNodo; // Nodo de lista simple

typedef struct _movimientoNodo {
  int id;
  char nombre[ MAX_LENGTH ];
  int tipo;
  int poder;
  int esEspecial;

  struct _movimientoNodo* izquierda;
  struct _movimientoNodo* derecha;

} movimientoNodo; // Nodo de arbol binario

typedef struct {
  int idPokedex;
  char nombre[ MAX_LENGTH ];
  char apodo[ MAX_LENGTH ]; // Nombre elegido por el entrenador
  int genero; // femenino o masculino

  int idTipo[2]; // -1 en el segundo tipo si no lo tiene

  int nivel;

  int estadSalud;
  int estadAtaque;
  int estadDefensa;
  int estadEspecial;
  int estadVelocidad;

  char naturaleza[ MAX_LENGTH ]; // Son 25 en total, seleccionado al azar

  int idSiguienteEvolucion; // -1 si no tiene

  int idMovimientosDisponibles[2];
  
  int experienceObtenida;

} pokemon;

tipoNodo buscarTipo( tipoNodo* listaDeTipos, int idDelTipoBuscado );
movimientoNodo buscarMovimiento( movimientoNodo* arbolDeMovimientos, int idDelMovimientoBuscado );
void pokemonAtaca( pokemon atacante, pokemon receptor, int usaAtaqueEspecial );
