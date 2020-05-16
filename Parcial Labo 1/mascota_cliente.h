#include "mascota.h"
#include "cliente.h"

/** \brief muestra cada estructua del array sCliente junto a un listado de estructuras del array sMascota
 *que coincidan en el valor idCliente
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tamMascota tamaño del array mascota
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tamCliente tamaño del array cliente
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mostrarClienteConSusMascotas(sMascota mascota[], int tamMascota,sCliente cliente[],int tamCliente,int ocupado);

/** \brief introduce el valor Nombre de las estrucuras del array cliente
 * en el valor nombreCliente de las estructuras del array mascota mediante coincidencia del valor idCliente
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tamMascota tamaño del array mascota
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tamCliente tamaño del array cliente
 * \param int ocupado valor de estado
 * \return void
 *
 */
void vincluarClienteAMascota(sMascota mascota[], int tamMascota,sCliente cliente[],int tamCliente,int ocupado);

/** \brief busca por ID una estructura activa(estado=ocupado) del array cliente
 * y todas las estructuras activas del array mascota correspondientes por coincidencia del valor ID cliente
 * y las transforma a inactivas o libres (estado=libre)
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tamMascota tamaño del array mascota
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tamCliente tamaño del array cliente
 * \param int ocupado valor de estado
 * \param int libre valor de estado
 * \return void
 *
 */
void eliminarClienteYSusMascotas(sMascota mascota[], int tamMascota,sCliente cliente[],int tamCliente,int ocupado,int libre);

/** \brief introduce en cantMascotas de una estructura cliente,
 * la cantidad de estructuras mascota que coincidan en valor de idCliente
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tamMascota tamaño del array mascota
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tamCliente tamaño del array cliente
 * \param int ocupado valor de estado
 * \return void
 *
 */
void calcularMascotasPorCliente(sMascota mascota[],int tamMascota,sCliente cliente[],int tamCliente,int ocupado);

/** \brief introduce en cantMascotas de una estructura cliente,
 * la cantidad de estructuras mascota que coincidan en valor de idCliente
 *
 * \param sMascota mascota[] Array de estructuras sMascota
 * \param int tamMascota tamaño del array mascota
 * \param sCliente cliente[] Array de estructuras sCliente
 * \param int tamCliente tamaño del array cliente
 * \param int ocupado valor de estado
 * \return void
 *
 */
void mostrarClientesConMasDeUnaMascota(sCliente cliente[],int tamCliente,int ocupado);

