#include "Inmobiliaria.h"
#include <stdlib.h>
#include <stdio.h>

ListaPropiedades *crearListaPropiedades() {
    ListaPropiedades *lista = (ListaPropiedades *) malloc(sizeof (ListaPropiedades));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primera = NULL;

    return lista;
}

Propiedad *crearPropiedad(char *barrio, char *direccion, float precio, int ambientes) {
    Propiedad *nueva = (Propiedad *) malloc(sizeof (Propiedad));

    if(nueva == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    nueva->siguiente = NULL;
    nueva->precio = precio;
    nueva->barrio = barrio;
    nueva->direccion = direccion;
    nueva->ambientes = ambientes;

    return nueva;
}
