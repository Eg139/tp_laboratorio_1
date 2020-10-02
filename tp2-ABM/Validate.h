
/** \brief Validate string in case user enter space, less than 3 letters, Enter-key or anything other than letters.
 *
 * \param char[] Receives string.
 * \return int Return 0 if something go wrong (Error) or 1 if everything 0k.
 *
 */
int Validate_String(char[]);


/** \brief Validate "strings" of numbers and validate in a range from 1 to 5 and if the user enter space or Enter-key for first time. It used to for options.
 *
 * \param char[] Receives string.
 * \return int Return 0 if something go wrong (Error) or 1 if everything 0k.
 *
 */
int Validate_Integer(char[]);


/** \brief Validate "strings" of numbers and validate if the user enter space or Enter-key for first time and other things. It used to enter id.
 *
 * \param char[] Receives string.
 * \return int Return 0 if something go wrong (Error) or 1 if everything 0k.
 *
 */
int Validate_IntID(char[]);
