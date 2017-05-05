/**
 tiene un nombreProducto , un
precio y transcurre un tiempo en ser asignada una ambulancia.
(ID, DNI, NOMBRE,
pasword, EDAD
**/
typedef struct
{
    char nombre[50];
    char pasword[50];
    char dni[9];
    int calificacion[10];
    int id;
    int isEmpty;
} E_Usuario;

typedef struct
{
    char nombreProducto[150];
    float precio;
    int id;
    int isEmpty;
    int idUsuario;
    int stock;
    int vendidos;
    int duracion;
} E_Productos;


typedef struct
{
    char tipo[15];
} EMotivo;


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);
int getNumeroAleatorio(int desde, int hasta, int iniciar);
void getString(char mensaje[],char arrayChar[]);
int getNumerosChar (char array[],char mensaje[]);
int getStringLetras(char mensaje[],char input[]);



int comentarioMasLikes (E_Productos comentarios[],int cantidad,int listaComentariosPopulares[]);
int ingresarSoloLetras (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarDNI (E_Usuario lista[],int cant,char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarEdad (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[]);
int cargarNumero (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[],int minimo, int maximo);
int nombreProductoLlamada(E_Productos listaProductos[],int indice);


void inicializarArrayDeIndices (int array[],int cantidad,int valor);
void inicializarListaDePersonas(E_Usuario lista[],int cantidad,int precio);
void inicializarListaDeProductos(E_Productos lista[],int cantidad,int precio);
void inicializarLikes(E_Productos lista[],int cantidad,int precio);
void inicializarArrayDeIndices (int array[],int cantidad,int valor);
