#include "cliente.h"

void hardcodearCliente(sCliente cliente[],int tam)
{
    int i;
    int idCliente[10]={1,2,3,4,5};
    char nombre[10][20]={"Flor","Beto","Zelda","Link","Pedrito"};
    char apellido[10][20]={"Floripondia","Casella","Hyrule","Hylian","Perez"};
    char localidad[10][20]={"Lanus","Lomas","Temperley","Adrogue","Burzaco"};
    char telefono[10][20]={"+5412132786","+541235754","+549958743","+541215354","+541231253"};
    int edad[10]={18,64,20,16,44};
    char sexo[10]={'F','M','F','M','M'};
    int estado[10]={1,1,1,1,1};

    for(i=0;i<tam;i++)
    {
    cliente[i].idCliente=idCliente[i];
    cliente[i].edad=edad[i];
    cliente[i].sexo=sexo[i];
    cliente[i].estado=estado[i];
    strcpy(cliente[i].nombre,nombre[i]);
    strcpy(cliente[i].apellido,apellido[i]);
    strcpy(cliente[i].localidad,localidad[i]);
    strcpy(cliente[i].telefono,telefono[i]);
    }
}

void inicializarCliente(sCliente cliente[],int tam ,int libre)
{
int i;
for(i=0;i<tam;i++)
    {
    cliente[i].estado=libre;
    cliente[i].idCliente=0;
    cliente[i].cantMascotas=0;
    }
}

void mostrarCliente(sCliente cliente[],int tam, int ocupado)
{
int i;
char space=' ';
printf("|%14cNOMBRE|%12cAPELLIDO|%11cLOCALIDAD|%12cTELEFONO| EDAD| SEXO|%4cID|CANT MASCOTAS|\n\n",space,space,space,space,space);
for(i=0;i<tam;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        printf("|%20s",cliente[i].nombre);
        printf("|%20s",cliente[i].apellido);
        printf("|%20s",cliente[i].localidad);
        printf("|%20s",cliente[i].telefono);
        printf("|%5d",cliente[i].edad);
        printf("|%5c",cliente[i].sexo);
        printf("|%6d",cliente[i].idCliente);
        printf("|%13d|",cliente[i].cantMascotas);
        printf("\n");
        }
    }
printf("\n");
}

int altaCliente(sCliente cliente[],int tam ,int libre, int ocupado)
{
int aux;
aux=buscarClienteLibre(cliente,tam,libre);
int retorno=-1;
if(aux!=-1)
    {
    getString(cliente[aux].nombre,"Ingrese Nombre: ");
    getString(cliente[aux].apellido,"Ingrese Apellido: ");
    getString(cliente[aux].localidad,"Ingrese Localidad: ");
    getString(cliente[aux].telefono,"Ingrese Telefono: ");
    cliente[aux].edad=getInt("Ingrese Edad: ","Ingrese una edad valida: ",0,110,1);
    do
        {
        cliente[aux].sexo=getChar("Ingrese sexo ('M' o 'F'): ","",0,0,0);
        }while(cliente[aux].sexo!='M' && cliente[aux].sexo!='F');
    cliente[aux].idCliente=generarIDCliente(cliente,tam);
    cliente[aux].estado=ocupado;
    system("color 2F");
    printf("Agregado exitosamente\n");
    retorno=aux;
    }
return retorno;
}

int generarIDCliente(sCliente cliente[],int tam)
{
int i;
int may=0;
for(i=0;i<tam;i++)
{
if(i==0 || cliente[i].idCliente>may)
    {
    may=cliente[i].idCliente;
    }
}
return may+1;
}

int buscarClienteLibre(sCliente cliente[],int tam ,int libre)
{
int i;
int retorno = -1;
for(i=0;i<tam;i++)
    {
    if(cliente[i].estado==libre)
        {
        retorno = i;
        break;
        }
    }
return retorno;
}

int buscarCliente(sCliente cliente[],int tam ,int ocupado ,int opcion, int id)
{
int i;
int retorno = -1;
int aux;
if(opcion==0)
    {
    aux=getInt("Ingrese una ID: ","",0,0,0);
    }
else if(opcion==1)
    {
    aux=id;
    }
for(i=0;i<tam;i++)
    {
    if(cliente[i].estado==ocupado && cliente[i].idCliente==aux)
        {
        if(opcion==0)
        {
        printf("Se ha encontrado una coincidencia\n");
        }
        retorno = i;
        break;
        }
    }
return retorno;
}

int modificarCliente(sCliente cliente[],int tam,int ocupado)
{
int aux;
int i;
int eleccion;
int retorno=-1;
aux=buscarCliente(cliente,tam,ocupado,0,0);
if(aux!=-1)
    {
    printf("Se encontro el Cliente, elija que modificara: \n");
    do
        {
        printf("1.Modificar Nombre\n");
        printf("2.Modificar Apellido\n");
        printf("3.Modificar Localidad\n");
        printf("4.Modificar Telefono\n");
        printf("5.Modificar Edad\n");
        printf("6.Modificar Sexo\n");
        printf("7.Salir\n");
        eleccion=getInt("Elija una opcion: ","Elija una opcion valida: ",1,7,1);
        system("cls");
        switch(eleccion)
            {
            case 1:
                {
                getString(cliente[aux].nombre,"Ingrese el Nombre: ");
                break;
                }
            case 2:
                {
                getString(cliente[aux].apellido,"Ingrese el Apellido: ");
                break;
                }
            case 3:
                {
                getString(cliente[aux].localidad,"Ingrese la Localidad: ");
                break;
                }
            case 4:
                {
                getString(cliente[aux].telefono,"Ingrese el Telefono: ");
                break;
                }
            case 5:
                {
                cliente[aux].edad=getInt("Ingrese Edad: ","Ingrese una edad valida: ",1,110,1);
                break;
                }
            case 6:
                {
                do
                    {
                    cliente[aux].sexo=getChar("Ingrese sexo ('M'o?'F'): ","",0,0,0);
                    }while((cliente[aux].sexo=='M'||cliente[aux].sexo!='F')!=1);
                break;
                }
            case 7:
                {
                printf("Fuera del menu de Modificaciones\n");
                break;
                }
            }
        }while(eleccion!=7);
    retorno=i;
    }
return retorno;
}

void mostrarUnCliente(sCliente cliente[],int tam, int index)
{
printf("|%20s|%20s|%20s|%20s|%5d|%5c|%6d|\n",cliente[index].nombre
                                            ,cliente[index].apellido
                                            ,cliente[index].localidad
                                            ,cliente[index].telefono
                                            ,cliente[index].edad
                                            ,cliente[index].sexo
                                            ,cliente[index].idCliente);
}

void ordenarClientePorCantMascotas(sCliente cliente[],int tam,int ocupado)
{
int i,j;
sCliente aux;
for(i=0;i<tam-1;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        for(j=i+1;j<tam;j++)
            {
            if(cliente[i].cantMascotas>cliente[j].cantMascotas)
                {
                aux=cliente[i];
                cliente[i]=cliente[j];
                cliente[j]=aux;
                }
            }
        }
    }
}

void ordenarClientePorCantMascotasYNombre(sCliente cliente[],int tam,int ocupado)
{
int i,j;
sCliente aux;
for(i=0;i<tam-1;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        for(j=i+1;j<tam;j++)
            {
            if(cliente[i].cantMascotas>cliente[j].cantMascotas)
                {
                aux=cliente[i];
                cliente[i]=cliente[j];
                cliente[j]=aux;
                }
            else if(cliente[i].cantMascotas==cliente[j].cantMascotas && strcmp(cliente[i].nombre,cliente[j].nombre)>0)
                {
                aux=cliente[i];
                cliente[i]=cliente[j];
                cliente[j]=aux;
                }
            }
        }
    }
}

void calculoDeHombresYMujeres(sCliente cliente[],int tam, int ocupado)
{
int i;
int edadHombres=0;
int edadMujeres=0;
float promedioEdadMujeres;
float promedioEdadHombres;
int cantHombres=0;
int cantMujeres=0;
float totalClientes=0;
float porcentajeHombres;
float porcentajeMujeres;
for(i=0;i<tam;i++)
    {
    if(cliente[i].sexo=='M')
        {
        cantHombres++;
        edadHombres+=cliente[i].edad;
        totalClientes++;
        }
    else if(cliente[i].sexo=='F')
        {
        cantMujeres++;
        edadMujeres+=cliente[i].edad;
        totalClientes++;
        }
    }
if(totalClientes>0)
    {
    printf("La cantidad de clientes es: %.2f\n",totalClientes);
    if(cantHombres>0)
        {
        porcentajeHombres=cantHombres*100.00/totalClientes;
        promedioEdadHombres=edadHombres/cantHombres;
        printf("El porcentaje de Clientes Hombres es:%% %5.2f\n",porcentajeHombres);
        printf("El promedio de edad de Clientes Hombres es: %5.2f\n", promedioEdadHombres);
        }
    else
        {
        printf("No hay Clientes Hombres\n");
        }
    if(cantMujeres>0)
        {
        porcentajeMujeres=cantMujeres*100.00/totalClientes;
        promedioEdadMujeres=edadHombres/cantMujeres;
        printf("El porcentaje de Clientes Mujeres es:%% %5.2f\n",porcentajeMujeres);
        printf("El promedio de edad de Clientes Mujeres es: %5.2f\n", promedioEdadMujeres);
        }
    else
        {
        printf("No hay Clientes Mujeres\n");
        }
    }
else
    {
    printf("No se ingresaron Clientes\n");
    }
}

void mostrarClientesConMasDeUnaMascota(sCliente cliente[],int tamCliente,int ocupado)
{
int i,j;
int flag;
char space=' ';
printf("|%14cNOMBRE|%12cAPELLIDO|%11cLOCALIDAD|%12cTELEFONO| EDAD| SEXO|%4cID|\n\n",space,space,space,space,space);
for(i=0;i<tamCliente;i++)
    {
    if(cliente[i].estado==ocupado && cliente[i].cantMascotas>1)
        {
        mostrarUnCliente(cliente,tamCliente,i);
        }
    }
}

int cantClientes(sCliente cliente[], int tam , int ocupado)
{
int i;
int contadorClientes=0;
for(i=0;i<tam;i++)
    {
    if(cliente[i].estado==ocupado)
        {
        contadorClientes++;
        }
    }
return contadorClientes;
}
