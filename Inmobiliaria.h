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
void filtrar(char *barrio, float precioMaximo, int ambientesMinimos);
void mostrarPropiedades(ListaPropiedades *lista);

#endif
