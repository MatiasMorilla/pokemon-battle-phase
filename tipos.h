#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define ARCHIVO_TIPOS "tipos.bin"

typedef struct {
  int id;
  char nombre[MAX_LENGTH];
  int idDebilidades[ MAX_LENGTH ];

} stTipo;

typedef struct _tipoNodo {
  stTipo tipo;

  struct _tipoNodo* siguiente;
} tipoNodo; // Nodo de lista simple

tipoNodo* inicListaTipos();
tipoNodo* agregarTipoALista( tipoNodo* lista, tipoNodo* nuevoNodo );
tipoNodo* cargarTiposDesdeArchivo( char archivoTipos[] );
tipoNodo* crearNodoTipo( stTipo tipo );
stTipo buscarTipo( tipoNodo* listaDeTipos, int idDelTipoBuscado );
void imprimirTipo( stTipo tipo );
void mostrarTipos( tipoNodo* lista );
void creacionDeNuevoTipo();
float esDebilidad( stTipo tipoA, stTipo tipoB );
float calcularEfectividadDelAtaque( tipoNodo* lista, int idTipoMovimiento, int idTipoDefensor1, int idTipoDefensor2 );
