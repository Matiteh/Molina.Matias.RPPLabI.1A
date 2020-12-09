
/** \brief Lista los clientes con la cantidad de prestamos activos
 *
 * \param listcliente cliente*
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void Listarclienteprestamos(cliente* listcliente,prestamo* listprestamo, int tam);
/** \brief Printea un cliente con sus prestamos activos
 *
 * \param cliente cliente
 * \param aux int
 * \return void
 *
 */
void Printclienteprestamos(cliente cliente, int aux);

/** \brief Lista los prestamos activos con los cuil del cliente perteneciente
 *
 * \param listprestamo prestamo*
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void ListarprestamoActCUIL(prestamo* listprestamo,cliente* listcliente, int tam);
/** \brief Printea un prestamo con el cuil del cliente
 *
 * \param prestamo prestamo
 * \param aux int
 * \return void
 *
 */
void PrintprestamoCUIL(prestamo prestamo, int aux);

/** \brief Printea cliente maximo con cantidad de P.Activos/P.Saldados/Prestamos
 *
 * \param cliente cliente
 * \param aux int
 * \return void
 *
 */
void PrintclienteMas(cliente cliente, int aux);
/** \brief Printea el cliente con mayor cantidad de prestamos activos
 *
 * \param listcliente cliente*
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void ClienteMasActivos(cliente* listcliente,prestamo* listprestamo, int tam);
/** \brief Printea el cliente con mayor cantidad de prestamos saldados
 *
 * \param listcliente cliente*
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void ClienteMasSaldados(cliente* listcliente,prestamo* listprestamo, int tam);
/** \brief Printea el cliente con mayor cantidad de prestamos
 *
 * \param listcliente cliente*
 * \param listprestamo prestamo*
 * \param tam int
 * \return void
 *
 */
void ClienteMasPrestamos(cliente* listcliente,prestamo* listprestamo, int tam);
