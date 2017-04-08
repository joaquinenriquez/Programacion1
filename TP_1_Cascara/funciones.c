/**
 * \brief Recibe dos operando y realiza la suma
 * \param Operando 1
 * \param Operando 2
 * \return Suma de Operando 1 y Operando 2
 *
 */
float addition(float num1, float num2){
    float result = num1 + num2;
    return result;
}


/**
 * \brief Recibe dos operando y realiza la resta
 * \param Operando 1
 * \param Operando 2
 * \return Resta del Operando 1 menos el Operando 2
 *
 */
float subtraction(float num1, float num2){
    float result = num1 - num2;
    return result;
}

/**
 * \brief Recibe dos operando y realiza el producto
 * \param Operando 1
 * \param Operando 2
 * \return Realiza el producto entre Operando1 y Operando2
 *
 */
float multiplication(float num1, float num2){
    float result = num1 * num2;
    return result;
}

/**
 * \brief Recibe dos operando y realiza la division
 * \param Operando 1
 * \param Operando 2
 * \return Divide el Operando1 por el Operando2
 *
 */
float division(float num1, float num2){
    float result = num1 / num2;
    return result;
}

/**
 * \brief Recibe un numero y devuelve el factorial
 * \param Operando 1
 * \return Factorial de Operando1
 *
 */
long long int factorial(int num1){
    long long int result;
    if (num1 == 1)
        return 1;
    result = num1 * factorial(num1 - 1);
    return (result);
}
