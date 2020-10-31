#include <stdio.h>
#include <stdlib.h>
#include "stpoke.h"

void limpiarPantalla();
void pausa();
void mostrarMenu();
void tomarOpcion( int* opcion );
void menuMovimientos();
void menuMovimientosPorTipo();

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
          menuMovimientosPorTipo();
          tomarOpcion(&opcion);

          if( opcion > 0 && opcion < 19 ) {
            limpiarPantalla();
            mostrarMovimientosPorTipo( arbolDeMovimientos, opcion );
            pausa();
          } else if( opcion == 19 ) {
            limpiarPantalla();
            mostrarMovimientos( arbolDeMovimientos );
            pausa();
          }

        }
        else if ( opcion == 2 ) {
          limpiarPantalla();
          mostrarTipos( listaDeTipos );
          creacionDeNuevoMovimiento();
        }

        break;

      default:
        break;
    }

  } while ( opcion );
  
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
  printf("2- Agregar Movimiento Nuevo (Necesita reiniciar para tomar efecto)\n");
  printf("\n9- Salir\n");
}

void pausa() {
  printf("\n\nPRESIONE UNA TECLA PARA CONTINUAR");
  getchar();
}

void limpiarPantalla() {
  system("cls||clear");
}

void menuMovimientosPorTipo() {
  printf("MOSTRAR MOVIMIENTOS POR TIPO\n");
  printf("1- Acero\n");
  printf("2- Agua\n");
  printf("3- Bicho\n");
  printf("4- Dragón\n");
  printf("5- Eléctrico\n");
  printf("6- Fantasma\n");
  printf("7- Fuego\n");
  printf("8- Hada\n");
  printf("9- Hielo\n");
  printf("10- Lucha\n");
  printf("11- Normal\n");
  printf("12- Planta\n");
  printf("13- Psíquico\n");
  printf("14- Roca\n");
  printf("15- Siniestro\n");
  printf("16- Tierra\n");
  printf("17- Veneno\n");
  printf("18- Volador\n");

  printf("\n19 - Mostrar todos\n");

  printf("\n20 - Volver atrás\n");
}
