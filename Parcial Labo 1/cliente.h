#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "harryio.h"

typedef struct
{
    char nombre[20];
    char apellido[20];
    char localidad[20];
    char telefono[20];
    int edad;
    char sexo;
    int estado;
    int idCliente;
    int cantMascotas;
}sCliente;

/** \brief inicializa valores del el array como el estado y la ID de cada estructura
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int libre valor de estado
 * \return void
 *
 */
void inicializarCliente(sCliente cliente[],int tam ,int libre);

/** \brief Hardcodea valores en el array
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \return void
 *
 */
void hardcodearCliente(sCliente cliente[],int tam);

/** \brief muestra todos los clientes activos(estado=ocupado)
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mostrarCliente(sCliente cliente[],int tam, int ocupado);

/** \brief busca un a estructura libre(estado=libre) y permite ingresar datos en la misma y marcarla como activa(estado=ocupado)
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay estructuras libres o la posicion en el array de la estructura en la que se ingresaron los datos
 *
 */
int altaCliente(sCliente cliente[],int tam ,int libre, int ocupado);

/** \brief genera automaticamente un ID sumandole 1 a la ID mas grande que encuentre en el array
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \return int devuelve el valor de la id mas grande del array +1
 *
 */
int generarIDCliente(sCliente cliente[],int tam);

/** \brief busca la primer estructura libre en el array (estado==libre)
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int libre valor de estado
 * \return int devuelve -1 si no hay estructuras libres o la posicion en el array de la estructura libre
 *
 */
int buscarClienteLibre(sCliente cliente[],int tam ,int libre);

/** \brief pide una ID y busca una coincidencia en el array de estructuras
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int libre valor de estado
 * \return int devuelve -1 si no hay coincidencias o la posicion en el array de la estructura con ID coincidente
 *
 */
int buscarCliente(sCliente cliente[],int tam ,int ocupado);

/** \brief busca una estructura por ID y permite modificar datos de la misma si esta activa(estado=ocupado)
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return int devuelve -1 si no hay coincidencias o la posicion en el array de la estructura que se modifico
 *
 */
int modificarCliente(sCliente cliente[],int tam,int ocupado);

/** \brief permite ingresar una posicion del array y muestra la estructura de la misma
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int index posicion del array
 * \return void
 *
 */
void mostrarUnCliente(sCliente cliente[],int tam, int index);

/** \brief ordena el array de mayor a menor usando el valor de cantMascotas
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void ordenarClientePorCantMascotas(sCliente cliente[],int tam,int ocupado);

/** \brief ordena el array de mayor a menor usando el valor de cantMascotas
 * y en caso de igualdad, por el valor de nombre
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void ordenarClientePorCantMascotasYNombre(sCliente cliente[],int tam,int ocupado);

/** \brief clacula y muestra la cantidad total de clientes y el porcentaje de clientes hombres y el de mujeres
 * (en el enunciado decia que debia mostrarse promedio pero interprete que se referian a porcentaje
 *  ya que de otra manera no tendria sentido)
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array
 * \param int ocupado valor de estado
 * \return void
 *
 */
void porcentajeDeHombresYMujeres(sCliente cliente[],int tam, int ocupado);

/** \brief muestra todas las estructuras cuyo valor cantMascotas sea mayor a 1
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array cliente
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mostrarClientesConMasDeUnaMascota(sCliente cliente[],int tamCliente,int ocupado);

/** \brief cuenta la cantidad de estructuras activas (estado=ocupado) en el array
 *
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tam tamaño del array cliente
 * \param int ocupado valor de estado
 * \return int devuelve la cantidad de estructuras activas
 *
 */
int cantClientes(sCliente cliente[], int tam , int ocupado);
