#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANT_ELEMENTOS 20
#define LARGO_NOMBRE 21

typedef struct{

    char nombre[LARGO_NOMBRE];
    int edad;
    int estado;
    long int dni;

}EPersona;

int validaS_N (void);//

int buscOrd (int, int [], int);

int obtenerEspacioLibre(EPersona lista[]);

long int buscarPorDni(EPersona lista[], long int dni);

int getInt(char mensaje[]);

int esNumerico(char str[]);//
int esSoloLetras(char str[]);//
int esFloat(char str[]);//

void getString(char mensaje[],char input[]);//
int getStringLetras(char mensaje[],char input[]);//
int getStringNumeros(char mensaje[],char input[]);//
int getStringFloat(char mensaje[],char input[]);//

void inicializarArrayPersona(EPersona lista[]);

void agregarPersona(EPersona persona[]);
void borrarPersona(EPersona persona[]);
void listaOrdenada(EPersona persona[]);
void graficoEdad(EPersona persona[]);

void recuadroStr(char cadena[]);


#endif // FUNCIONES_H_INCLUDED
