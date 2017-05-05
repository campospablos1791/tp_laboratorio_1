
int alta (E_Usuario listaPersonas[],int cantidad,int id);
void baja (E_Usuario listaPersonas[],int cantidad,E_Productos listaProductos[], int cantidadProductos,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void modificar (E_Usuario listaPersonas[],int cantidad,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void nuevaPublicacion (E_Usuario listaPersonas[],int cantidad, E_Productos listaProductos[], int cantidadLlamas,int id);
void asignarAmbulancia (E_Usuario listaPersonas[],int cantidadPersonas, E_Productos listaProductos[],int cantiadLlamadas,int stock);
void informarMotivosMasDemorados(E_Productos listaProductos[],int canttidadLlamadas,EMotivo nombreProducto[]);
void informarAfiliadosMasLlamadas(E_Productos listaProductos[],int cantLlamadas,E_Usuario listaPersonas[],int cantidad,int afiliadosConMasLlamadas[]);
//void informarAfiliadosMasLlamadas(E_Productos listaProductos[],int cantLlamadas,E_Usuario listaPersonas[],int cantidad,int afiliadosConMasLlamadas[]);
void informarMotivosMasRepetidos(E_Productos listaProductos[],int canttidadLlamadas,EMotivo nombreProducto[]);
void imprimirListaPorNombre(E_Usuario listaPersonas[],int cantidad);
void informarAfiliadosPorNombreypasword(E_Usuario listaPersonas[],int cantidad);
void modificarPublicacion (E_Usuario listaPersonas[],int cantidad,E_Productos listaProductos[], int cantidadProductos,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void cancelarPublicacion (E_Usuario listaPersonas[],int cantidad,E_Productos listaProductos[], int cantidadProductos,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
void nuevaCompra(E_Usuario listaUsuarios[],int cantidadUsuarios,E_Productos listaProductos[], int cantidadProductos);
void listarPublicacionesDeUsuarios(E_Usuario listaPersonas[],int cantidad,E_Productos listaProductos[], int cantidadProductos,char mensaje[],char mensajeError[],char  mensajeNoEncontrado[]);
