#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * printFormattedUnsigned - Prints an unsigned number in the desired format.
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle the formatted output.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedUnsigned(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    int i = MAX_BUFFER_SIZE - 2;
    unsigned long int number = va_arg(argList, unsigned long int);

    number = convertSizeUnsigned(number, dataSize);

    if (number == 0)
        outputBuffer[i--] = '0';

    outputBuffer[MAX_BUFFER_SIZE - 1] = '\0';

    while (number > 0)
    {
        outputBuffer[i--] = (number % 10) + '0';
        number /= 10;
    }

    i++;

    return (writeFormattedUnsigned(0, i, outputBuffer, activeFlags, fieldWidth, precision, dataSize));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * printFormattedOctal - Prints an unsigned number in octal notation.
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle the formatted output.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedOctal(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    int i = MAX_BUFFER_SIZE - 2;
    unsigned long int number = va_arg(argList, unsigned long int);
    unsigned long int initialNumber = number;

    UNUSED(fieldWidth);

    number = convertSizeUnsigned(number, dataSize);

    if (number == 0)
        outputBuffer[i--] = '0';

    outputBuffer[MAX_BUFFER_SIZE - 1] = '\0';

    while (number > 0)
    {
        outputBuffer[i--] = (number % 8) + '0';
        number /= 8;
    }

    if (activeFlags & FLAG_HASH && initialNumber != 0)
        outputBuffer[i--] = '0';

    i++;

    return (writeFormattedUnsigned(0, i, outputBuffer, activeFlags, fieldWidth, precision, dataSize));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * printFormattedHexadecimal - Prints an unsigned number in hexadecimal notation.
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle the formatted output.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedHexadecimal(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    return (printFormattedHexa(argList, "0123456789abcdef", outputBuffer,
        activeFlags, 'x', fieldWidth, precision, dataSize));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * printFormattedHexadecimalUpper - Prints an unsigned number in uppercase hexadecimal notation.
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle the formatted output.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedHexadecimalUpper(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    return (printFormattedHexa(argList, "0123456789ABCDEF", outputBuffer,
        activeFlags, 'X', fieldWidth, precision, dataSize));
}

/************** PRINT HEX NUM IN LOWER OR UPPER **************/
/**
 * printFormattedHexa - Prints a hexadecimal number in lower or uppercase.
 * @argList: List of arguments.
 * @mapTo: Array of values to map the number to.
 * @outputBuffer: Buffer array to handle the formatted output.
 * @activeFlags: Flags indicating the formatting options.
 * @flagCharacter: Flag character used for formatting.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedHexa(va_listargList, char mapTo[], char outputBuffer[], int activeFlags,
    char flagCharacter, int fieldWidth, int precision, int dataSize)
{
    int i = MAX_BUFFER_SIZE - 2;
    unsigned long int number = va_arg(argList, unsigned long int);
    unsigned long int initialNumber = number;

    number = convertSizeUnsigned(number, dataSize);

    if (number == 0)
        outputBuffer[i--] = '0';

    outputBuffer[MAX_BUFFER_SIZE - 1] = '\0';

    while (number > 0)
    {
        outputBuffer[i--] = mapTo[number % 16];
        number /= 16;
    }

    if (activeFlags & FLAG_HASH && initialNumber != 0)
    {
        if (flagCharacter == 'x')
        {
            outputBuffer[i--] = 'x';
            outputBuffer[i--] = '0';
        }
        else if (flagCharacter == 'X')
        {
            outputBuffer[i--] = 'X';
            outputBuffer[i--] = '0';
        }
    }

    i++;

    return (writeFormattedUnsigned(0, i, outputBuffer, activeFlags, fieldWidth, precision, dataSize));
}
