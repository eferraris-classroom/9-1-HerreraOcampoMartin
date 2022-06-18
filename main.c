#include <stdio.h>
#include "Inmobiliaria.h"

int main() {

    ListaPropiedades *lista = crearListaPropiedades();

    agregarPropiedad(lista, crearPropiedad("Saavedra", "Direccion en Saavedra 1", 129000, 2));
    agregarPropiedad(lista, crearPropiedad("Belgrano", "Direccion en Belgrano 1", 254000, 3));
    agregarPropiedad(lista, crearPropiedad("Belgrano", "Direccion en Belgrano 2", 654000, 4));
    agregarPropiedad(lista, crearPropiedad("Saavedra", "Direccion en Saavedra 2", 29000, 1));
    agregarPropiedad(lista, crearPropiedad("Palermo", "Direccion en Palermo 1", 2295000, 11));
    agregarPropiedad(lista, crearPropiedad("Colegiales", "Direccion en Colegiales 1", 867000, 5));
    agregarPropiedad(lista, crearPropiedad("Saavedra", "Direccion en Saavedra 3", 678000, 4));
    agregarPropiedad(lista, crearPropiedad("Colegiales", "Direccion en Colegiales 2", 1889000, 6));
    agregarPropiedad(lista, crearPropiedad("Palermo", "Direccion en Palermo 2", 6478000, 15));

    mostrarPropiedades(lista);

    // --------------------------------------------------

    char barrio[100];
    float precio = 0;
    int ambientes = 0;

    printf("INGRESE EL BARRIO DE INTERÉS: ");
    fgets(barrio, 100, stdin);

    printf("INGRESE EL PRECIO MÁXIMO: ");
    scanf("%f", &precio);
    fflush(stdin);

    printf("INGRESE LA CANTIDAD DE AMBIENTES MÍNIMOS: ");
    scanf("%d", &ambientes);
    fflush(stdin);

    ListaPropiedades *filtrados = filtrar(lista, barrio, precio, ambientes);
    mostrarPropiedades(filtrados);

    return 0;
}
