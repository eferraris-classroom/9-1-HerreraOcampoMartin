#include "Inmobiliaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void agregarPropiedad(ListaPropiedades *lista, Propiedad *nueva) {
    Propiedad *aux = lista->primera;

    if(aux == NULL){
        lista->primera = nueva;
        return;
    }

    for(; aux->siguiente != NULL; aux = aux->siguiente){}

    aux->siguiente = nueva;
}

void mostrarPropiedades(ListaPropiedades *lista) {
    Propiedad *aux = lista->primera;

    if(aux == NULL){
        printf("No hay propiedades disponibles.\n");
        return;
    }

    for(; aux != NULL; aux = aux->siguiente){
        printf("* Barrio: %s \t- Dirección: %s \t- Precio: %.2f \t- Ambientes: %d\n",
               aux->barrio,
               aux->direccion,
               aux->precio,
               aux->ambientes);
    }
}

ListaPropiedades *filtrar(ListaPropiedades *lista, char *barrioElegido, float precioMaximo, int ambientesMinimos) {
    Propiedad *aux = lista->primera;

    ListaPropiedades *filtrados = crearListaPropiedades();

        barrioElegido = eliminarEnter(barrioElegido); // Esto esta porque cuando le das
        // "Enter" en el momento del ingreso, C agrega un '\n', que a la hora de compararlo
        // con el barrio, no reconoce las palabras como iguales.

        printf("-- Propiedades disponibles:\n");

        for(; aux != NULL; aux = aux->siguiente){

            if(strcmp(aux->barrio, barrioElegido) == 0 &&
                aux->precio <= precioMaximo &&
                aux->ambientes >= ambientesMinimos){

                copiarAFiltrados(filtrados, aux);

            }

        }

    return filtrados;

}

char *eliminarEnter(char *texto) {
    char *resultado;
    int i, j;

    for (i = 0; texto[i] != '\n'; i++){}

    resultado = (char *) malloc(sizeof (char) * (i+1)); // i = cantidad de caracteres, +1 para el \0

    for(j = 0; j < i; j++){
        resultado[j] = texto[j];
    }

    resultado[j] = '\0';

    return resultado;
}

void copiarAFiltrados(ListaPropiedades *filtrados, Propiedad *nueva) {
    Propiedad *copia = (Propiedad*) malloc(sizeof (Propiedad));

    if(copia == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    copia->siguiente = NULL;
    copia->ambientes = nueva->ambientes;
    copia->precio = nueva->precio;
    copia->barrio = nueva->barrio;
    copia->direccion = nueva->direccion;

    Propiedad *aux = filtrados->primera;

    if(aux == NULL){
        filtrados->primera = copia;
        return;
    }

    for(; aux->siguiente != NULL; aux = aux->siguiente){}

    aux->siguiente = copia;
}
