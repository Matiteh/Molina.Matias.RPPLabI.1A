typedef struct{
    int id;
    int idcliente;
    int importe;
    int cantCuotas;
    char estado[20];
}prestamo;
/** \brief Inicializa la estructura prestamo
 *
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void Initprestamo(prestamo* listprestamo, int tam);
/** \brief Obtiene el prestamo por id
 *
 * \param listprestamo prestamo*
 * \param tam int
 * \param id int
 * \return retorna -1 si no existe y el indice si existe
 *
 */
int ObtprestamoById(prestamo* listprestamo, int tam,int id);

/** \brief Realiza el alta de un prestamo
 *
 * \param listprestamo prestamo*
 * \param tamA int
 * \param id int*
 * \param listcliente cliente*
 * \param tamC int
 * \return void
 *
 */
void Altaprestamo(prestamo* listprestamo, int tamA, int* id,cliente* listcliente, int tamC);
/** \brief Deja al prestamo en estado saldado
 *
 * \param listprestamo prestamo*
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Saldarprestamo(prestamo* listprestamo,cliente* listcliente, int tam);
/** \brief Deja al prestamo en estado activo
 *
 * \param listprestamo prestamo*
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Reanudarprestamo(prestamo* listprestamo,cliente* listcliente, int tam);

/** \brief Lista los prestamos
 *
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void Listarprestamo(prestamo* listprestamo, int tam);
/** \brief Printea un prestamo
 *
 * \param prestamo prestamo
 * \return void
 *
 */
void Printprestamo(prestamo prestamo);
/** \brief Lista los prestamos activos
 *
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void ListarprestamoAct(prestamo* listprestamo, int tam);
/** \brief Lista los prestamos saldados
 *
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void ListarprestamoSald(prestamo* listprestamo, int tam);
