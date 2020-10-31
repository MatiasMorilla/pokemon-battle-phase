#include <stdio.h>
#include <stdlib.h>
#include "stpoke.h"

void limpiarPantalla();
void pausa();
void mostrarMenu();
void tomarOpcion( int* opcion );
void menuMovimientos();

int main()
{
  tipoNodo* listaDeTipos = cargarTiposDesdeArchivo( ARCHIVO_TIPOS );
  movimientoNodo* arbolDeMovimientos = cargarMovimientosDesdeArchivo( ARCHIVO_MOVIMIENTOS );

  int opcion;

  do {
    limpiarPantalla();
    mostrarMenu();
    tomarOpcion(&opcion);

    switch( opcion ) {
      case 1:
        limpiarPantalla();
        mostrarTipos( listaDeTipos );
        pausa();
        break;

      case 2:
        limpiarPantalla();
        menuMovimientos();
        tomarOpcion(&opcion);

        if ( opcion == 1 ) {
          limpiarPantalla();
          mostrarMovimientos( arbolDeMovimientos );
          pausa();
        }
        if ( opcion == 2 ) {
          limpiarPantalla();
          creacionDeNuevoMovimiento();
        }

        break;

      default:
        break;
    }

  } while ( opcion );
  
  mostrarTipos( listaDeTipos );
  //mostrarMovimientos( arbolDeNodos );
  //creacionDeNuevoMovimiento();

  return 0;
}

void mostrarMenu() {
  printf("1- Tipos Elementales\n");
  printf("2- Movimientos\n");
  printf("\n0- Salir\n");
}

void tomarOpcion( int* opcion ) {
  printf("\n> ");
  scanf("%d", opcion);
  while( getchar() != '\n' );
}

void menuMovimientos() {
  printf("1- Mostrar Movimientos\n");
  printf("2- Agregar Movimiento Nuevo\n");
  printf("\n9- Salir\n");
}

void pausa() {
  printf("\n\nPRESIONE UNA TECLA PARA CONTINUAR");
  getchar();
}

void limpiarPantalla() {
  system("cls||clear");
}
