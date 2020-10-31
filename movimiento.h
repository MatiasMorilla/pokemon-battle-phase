#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define ARCHIVO_MOVIMIENTOS "movimientos.bin"

typedef struct {
  int id;
  char nombre[ MAX_LENGTH ];
  int tipo;
  int poder;

} stMovimiento;

typedef struct _movimientoNodo {
  stMovimiento movimiento;

  struct _movimientoNodo* izquierda;
  struct _movimientoNodo* derecha;
} movimientoNodo; // Nodo de arbol binario

movimientoNodo* cargarMovimientosDesdeArchivo( char archivoMovimientos[MAX_LENGTH] );
stMovimiento buscarMovimiento( movimientoNodo* arbolDeMovimientos, int idDelMovimientoBuscado );
movimientoNodo* inicArbolMovimientos();
movimientoNodo* agregarMovimientoAlArbol( movimientoNodo* arbol, movimientoNodo* nodoNuevo );
movimientoNodo* crearNodoMovimiento( stMovimiento movimientoNuevo );
void imprimirMovimiento( stMovimiento aMostrar );
void mostrarMovimientos( movimientoNodo* arbol );
stMovimiento crearMovimiento();
void creacionDeNuevoMovimiento();
