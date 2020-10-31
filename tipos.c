#include "tipos.h"

tipoNodo* inicListaTipos() {
  return NULL;
}

tipoNodo* agregarTipoALista( tipoNodo* lista, tipoNodo* nuevoNodo ) {
  if( !lista ) {
    lista = nuevoNodo;
  } else {
    lista->siguiente = agregarTipoALista( lista->siguiente, nuevoNodo );
  }

  return lista;
}

tipoNodo* crearNodoTipo( stTipo tipo ) {
  tipoNodo* nuevoNodo = (tipoNodo*) malloc( sizeof(tipoNodo) );

  nuevoNodo->tipo = tipo;
  nuevoNodo->siguiente = inicListaTipos();

  return nuevoNodo;
}

tipoNodo* cargarTiposDesdeArchivo( char archivoTipos[] ) {
  tipoNodo* lista = inicListaTipos();
  tipoNodo* auxNodo;
  stTipo auxTipo;

  FILE* archivo = fopen( archivoTipos, "rb" );

  if ( archivo ) {

    while( fread(&auxTipo, sizeof(stTipo), 1, archivo) ) {
      auxNodo = crearNodoTipo( auxTipo );
      lista = agregarTipoALista( lista, auxNodo );
    }
  } else {
    archivo = fopen( archivoTipos, "wb" );
  }

  fclose( archivo );

  return lista;
}

void imprimirTipo( stTipo tipo ) {
  int i=0;

  printf("Id: %d\n", tipo.id);
  printf("Nombre: %s\n", tipo.nombre);

  while( tipo.idDebilidades[i] != -1 ) {
    printf("Debilidad: %d\n", tipo.idDebilidades[i]);
    i++;
  }
}

void mostrarTipos( tipoNodo* lista ) {
  if( lista ) {
    imprimirTipo( lista->tipo );
    printf("\n");
    mostrarTipos( lista->siguiente );
  }
}

void creacionDeNuevoTipo() {

  stTipo nuevoTipo;
  int i= 0;
  int ultimoIngreso = 0;

  printf("\nId: ");
  scanf("%d", &(nuevoTipo.id));
  while( getchar() != '\n' );
  printf("\nNombre: ");
  fgets(nuevoTipo.nombre, MAX_LENGTH, stdin);
  nuevoTipo.nombre[ strlen(nuevoTipo.nombre)-1 ] = 0;

  while( ultimoIngreso != -1 ) {
    printf("\nDebilidad (-1 termina): ");
    scanf("%d", &ultimoIngreso);
    nuevoTipo.idDebilidades[i] = ultimoIngreso;
    i++;
  }

  FILE* archivo= fopen( ARCHIVO_TIPOS, "ab" );
  if( archivo ) {
    fwrite( &nuevoTipo, sizeof(stTipo), 1, archivo );
  }
  fclose(archivo);
}

stTipo buscarTipo( tipoNodo* listaDeTipos, int idDelTipoBuscado ) {
  stTipo tipoBuscado;

  if( listaDeTipos ) {
    if( (listaDeTipos->tipo).id == idDelTipoBuscado ) {
      tipoBuscado = listaDeTipos->tipo;
    } else {
      tipoBuscado = buscarTipo( listaDeTipos->siguiente, idDelTipoBuscado );
    }
  } else {
    printf("======== ERROR: LISTA DE TIPOS SIN CARGAR O TIPO INEXISTENTE ======== \n");
  }

  return tipoBuscado;
}

float esDebilidad( stTipo tipoA, stTipo tipoB ) {
  float debil = 0;
  int i = 0;

  while( tipoB.idDebilidades[i] != -1 ) {
    if ( tipoB.idDebilidades[i] == tipoA.id ) {
      debil=0.5;
    }
    i++;
  }

  return debil;
}

float calcularEfectividadDelAtaque( tipoNodo* lista, int idTipoMovimiento, int idTipoDefensor1, int idTipoDefensor2 ) {
  float efectividad = 1;
  stTipo tipoMovimiento = buscarTipo( lista, idTipoMovimiento );
  stTipo tiposDefensor[2];

  tiposDefensor[0] = buscarTipo( lista, idTipoDefensor1 );
  tiposDefensor[1] = buscarTipo( lista, idTipoDefensor2 );

  efectividad += esDebilidad( tipoMovimiento, tiposDefensor[0] );
  efectividad += esDebilidad( tipoMovimiento, tiposDefensor[1] );
  efectividad -= esDebilidad( tiposDefensor[0], tipoMovimiento );
  efectividad -= esDebilidad( tiposDefensor[1], tipoMovimiento );

  if( efectividad == 0 ) {
    efectividad = 0.25;
  }

  return efectividad;
}
