#include "main.h"

/************************* PRINT CHARACTER *************************/
/**
 * printFormattedCharacter - Prints a character
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedCharacter(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    char ch = va_arg(argList, int);

    return (handleWriteCharacter(ch, outputBuffer, activeFlags, fieldWidth, precision, dataSize));
}

/************************* PRINT STRING *************************/
/**
 * printFormattedString - Prints a string
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedString(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    int length = 0, x;
    char *str = va_arg(argList, char *);

    UNUSED(outputBuffer);
    UNUSED(activeFlags);
    UNUSED(fieldWidth);
    UNUSED(precision);
    UNUSED(dataSize);

    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = "      ";
    }

    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (fieldWidth > length)
    {
        if (activeFlags & F_MINUS)
        {
            write(1, &str[0], length);
            for (x = fieldWidth - length; x > 0; x--)
                write(1, " ", 1);
            return fieldWidth;
        }
        else
        {
            for (x = fieldWidth - length; x > 0; x--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return fieldWidth;
        }
    }

    return write(1, str, length);
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * printFormattedPercentSign - Prints a percent sign
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedPercentSign(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    UNUSED(argList);
    UNUSED(outputBuffer);
    UNUSED(activeFlags);
    UNUSED(fieldWidth);
    UNUSED(precision);
    UNUSED(dataSize);

    return write(1, "%%", 1);
}

/************************* PRINT INTEGER *************************/
/**
 * printFormattedInteger - Prints an integer
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedInteger(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    int x = MAX_BUFFER_SIZE - 2;
    int isNegative = 0;
    long int number = va_arg(argList, long int);
    unsigned long int num;

    number = convertSizeNumber(number, dataSize);

    if (number == 0)
        outputBuffer[x--] = '0';

    outputBuffer[MAX_BUFFER_SIZE - 1] = '\0';
    num = (unsigned long int)number;

    if (number < 0)
    {
        num = (unsigned long int)((-1) * number);
        isNegative = 1;
    }

    while (num > 0)
    {
        outputBuffer[x--] = (num % 10) + '0';
        num /= 10;
    }

    x++;

    return writeNumber(isNegative, x, outputBuffer, activeFlags, fieldWidth, precision, dataSize);
}

/************************* PRINT BINARY *************************/
/**
 * printFormattedBinary - Prints an unsigned number in binary format
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicatingthe formattingHere is the modified code with the variable `i` changed to `x`:

```c
#include "main.h"

/************************* PRINT CHARACTER *************************/
/**
 * printFormattedCharacter - Prints a character
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedCharacter(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    char ch = va_arg(argList, int);

    return (handleWriteCharacter(ch, outputBuffer, activeFlags, fieldWidth, precision, dataSize));
}

/************************* PRINT STRING *************************/
/**
 * printFormattedString - Prints a string
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedString(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    int length = 0, x;
    char *str = va_arg(argList, char *);

    UNUSED(outputBuffer);
    UNUSED(activeFlags);
    UNUSED(fieldWidth);
    UNUSED(precision);
    UNUSED(dataSize);

    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = "      ";
    }

    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (fieldWidth > length)
    {
        if (activeFlags & F_MINUS)
        {
            write(1, &str[0], length);
            for (x = fieldWidth - length; x > 0; x--)
                write(1, " ", 1);
            return fieldWidth;
        }
        else
        {
            for (x = fieldWidth - length; x > 0; x--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return fieldWidth;
        }
    }

    return write(1, str, length);
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * printFormattedPercentSign - Prints a percent sign
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedPercentSign(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    UNUSED(argList);
    UNUSED(outputBuffer);
    UNUSED(activeFlags);
    UNUSED(fieldWidth);
    UNUSED(precision);
    UNUSED(dataSize);

    return write(1, "%%", 1);
}

/************************* PRINT INTEGER *************************/
/**
 * printFormattedInteger - Prints an integer
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicating the formatting options.
 * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedInteger(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    int x = MAX_BUFFER_SIZE - 2;
    int isNegative = 0;
    long int number = va_arg(argList, long int);
    unsigned long int num;

    number = convertSizeNumber(number, dataSize);

    if (number == 0)
        outputBuffer[x--] = '0';

    outputBuffer[MAX_BUFFER_SIZE - 1] = '\0';
    num = (unsigned long int)number;

    if (number < 0)
    {
        num = (unsigned long int)((-1) * number);
        isNegative = 1;
    }

    while (num > 0)
    {
        outputBuffer[x--] = (num % 10) + '0';
        num /= 10;
    }

    x++;

    return writeNumber(isNegative, x, outputBuffer, activeFlags, fieldWidth, precision, dataSize);
}

/************************* PRINT BINARY *************************/
/**
 * printFormattedBinary - Prints an unsigned number in binary format
 * @argList: List of arguments.
 * @outputBuffer: Buffer array to handle print.
 * @activeFlags: Flags indicatingthe formatting options.
 * * @fieldWidth: Width of the output field.
 * @precision: Precision specification.
 * @dataSize: Size specifier.
 * Return: Number of characters printed.
 */
int printFormattedBinary(va_list argList, char outputBuffer[],
    int activeFlags, int fieldWidth, int precision, int dataSize)
{
    unsigned int number = va_arg(argList, unsigned int);
    int x = MAX_BUFFER_SIZE - 2;

    number = convertSizeNumber(number, dataSize);

    if (number == 0)
        outputBuffer[x--] = '0';

    outputBuffer[MAX_BUFFER_SIZE - 1] = '\0';

    while (number > 0)
    {
        outputBuffer[x--] = (number % 2) + '0';
        number /= 2;
    }

   x++;

    return writeNumber(0, x, outputBuffer, activeFlags, fieldWidth, precision, dataSize);
}
