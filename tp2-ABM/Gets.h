
/** \brief This function ask the user to enter something (string) like Name, Last Name, etc... and make of the function Validate_String.
 *
 * \param char[] Receives the message to show.
 * \param char[] Receives data that user enters.
 * \param int Receives the length of the "string".
 * \return void Return nothing
 *
 */
void GetString(char[],char[],int);


/** \brief Ask the user to enter an option for menu in a range of 1 to 5 (amount of option in menu). Use the same for sector(1 to 5) and make of the function Validate_Integer.
 *
 * \param char[] Receives the message to show.
 * \return int Return number validated.
 *
 */
int GetOption(char[]);


/** \brief Ask the user to enter an Id for later validate it using function Validate_IntId.
 *
 * \param char[] Receives the message to show.
 * \param int Receive length of the "string".
 * \return int Return validated number.
 *
 */
int GetInt(char[]);


/** \brief Ask the user to enter the salary.
 *
 * \param char[] Receives the message to show.
 * \return float Return the number loaded.
 *
 */
float GetFloat(char[]);


/** \brief Ask the user to enter a character 'S' or 'N' to make a decision
 *
 * \param message[] char Receives the message to show.
 * \return char Return character validated.
 *
 */
char GetChar(char message[]);
