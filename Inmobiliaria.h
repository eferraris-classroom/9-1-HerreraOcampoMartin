#ifndef INC_9_1_HERRERAOCAMPOMARTIN_INMOBILIARIA_H
#define INC_9_1_HERRERAOCAMPOMARTIN_INMOBILIARIA_H

typedef struct propiedad {
    char *barrio;
    char *direccion;
    float precio;
    int ambientes;
    struct propiedad *siguiente;
} Propiedad;

typedef struct listaPropiedades {
    int tam;
    Propiedad *primera;
} ListaPropiedades;

ListaPropiedades *crearListaPropiedades();
Propiedad *crearPropiedad(char *barrio, char *direccion, float precio, int ambientes);
void agregarPropiedad(ListaPropiedades *lista, Propiedad *nueva);
void mostrarPropiedades(ListaPropiedades *lista);
ListaPropiedades *filtrar(ListaPropiedades *lista, char *barrioElegido, float precioMaximo, int ambientesMinimos);
void copiarAFiltrados(ListaPropiedades *filtrados, Propiedad *nueva);
char *eliminarEnter(char *texto);

#endif
