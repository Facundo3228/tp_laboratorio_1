//*********************************** GETS ***********************************

/** \brief
 *
 * \param mensaje[] charmensaje Es el mensaje que será mostrado al usuario
 * \param mensajeError[] charmensaje Es el mensaje de error que será mostrado al usuario
 * \param min int un valor minimo
 * \param max int un valor maximo
 * \param limit int un limite de intentos
 * \return int es el numeroingresado por el usuario
 *
 */
int getIntLimit (char mensaje[], char mensajeError[], int min, int max, int limit);


/** \brief Solicita un numero - devuelve el resultado.
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
int getInt (char mensaje[]);



/** \brief Solicita un numero - devuelve el resultado.
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el numero ingresado por el usuario.
 */
float getFloat (char mensaje[]);



/** \brief Solicita un caracter - devuelve el resultado.
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el caracter ingresado por el usuario.
 */
char getChar(char mensaje[]);



//******************************* VALIDACIONES *******************************
/** \brief Hace mayusculas la primer letra del dato ingresado.
 *
 * \param caracter[] dato que va a ser modificado.
 * \return void
 */
void stringToUpper(char caracter[]);



/** \brief Verifica si es numerico.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es numero // 0 si no es numero.
 */
int esNumerico (char str[]);



/** \brief Verifica si contiene solamente numeros, + y -.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si es numero, con espacios y guion // 0 si no es numero.
 */
int esTelefono (char str[]);



/** \brief Verifica si contiene solamente letras.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si contiene solo espacios y letras // 0 si contiene numero, etc.
 */
int esSoloLetras (char str[]);



/** \brief Verifica si contiene solo letras y numeros.
 *
 * \param str Array con la cadena que va a ser analizada.
 * \return 1 si contiene solo espacio o letras y numeros // 0 si no.
 */
int esAlfaNumerico (char str[]);



/** \brief Solicita un texto.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargara el texto ingresado.
 * \return void.
 */
void getString(char mensaje[], char input[]);



/** \brief Solicita un texto y lo devuelve.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return 1 si el texto contiene SOLO letras.
 */
int getStringLetras(char mensaje[], char input[]);



/** \brief Solicita un texto numerico y lo devuelve.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargara el texto ingresado.
 * \return 1 si el texto contiene SOLO numeros.
 */
int getStringNumeros(char mensaje[], char input[]);



/**
 * \brief Solicita un texto Alfa numérico y lo devuelve.
 * \param char* Es el mensaje a ser mostrado.
 * \param char* puntero donde se cargará el texto ingresado.
 * \return 1 si el texto contiene solo números enteros o letras.
 */
 int getAlfaNumerico(char mensaje[], char input[]);
