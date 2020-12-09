typedef struct{
    int id;
    int cuil;
    char nombre[20];
    char apellido[20];
}cliente;

/** \brief Inicializa la estructura cliente
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Initcliente(cliente* listcliente, int tam);

/** \brief Obtiene el cliente por ID
 *
 * \param listcliente cliente*
 * \param tam int
 * \param id int
 * \return retorna -1 si no existe, y el indice si existe
 *
 */
int ObtclienteById(cliente* listcliente, int tam,int id);

/** \brief Realiza el alta de un cliente
 *
 * \param listcliente cliente*
 * \param tam int
 * \param id int*
 * \return void
 *
 */
void Altacliente(cliente* listcliente, int tam, int* id);
/** \brief Modifica un dato de algun cliente
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Modcliente(cliente* listcliente, int tam);
/** \brief Da de baja un cliente
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Delcliente(cliente* listcliente, int tam);

/** \brief Lista los clientes
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Listarcliente(cliente* listcliente, int tam);
/** \brief Printea un cliente
 *
 * \param cliente cliente
 * \return void
 *
 */
void Printcliente(cliente cliente);
