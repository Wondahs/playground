// #include "main.h"

// void flushBuffer(char *buffer, int *pchar)
// {
//     write(1, buffer, *pchar);
//     *pchar = 0;
// }

// /**
//  *print_str - Prints string
//  *@str: Input string
//  *
//  *Return: Length of str
//  */
// int print_str(char *str, char *buffer, int *pchar)
// {
//     int i;
//     int len = 0;

//     for (i = 0; str[i] != '\0'; i++)
//     {
//         len++;
//         if (*pchar < BUFFER_SIZE - 1) {
//             buffer[(*pchar)++] = str[i];
//         } else {
//             flushBuffer(buffer, pchar);
//             buffer[(*pchar)++] = str[i];
//         }
//     }

//     return (len);
// }


// /**
//  * print_int - Print an integer using %i or %d format
//  * @num: The integer to be printed
//  *
//  * Return: The number of characters printed
//  */
// int print_int(int num)
// {
// 	char buffer[12];
// 	int len = 0;
// 	int abs_num, i;
// 	int num_digits = 0;

// 	if (num == 0)
// 	{
// 		buffer[len++] = '0';
// 	}
// 	else
// 	{
// 		if (num < 0)
// 		{
// 			buffer[len++] = '-';
// 			num = -num;
// 		}

// 		abs_num = num;
// 		/* int num_digits = 0; */

// 		while (abs_num > 0)
// 		{
// 			abs_num /= 10;
// 			num_digits++;
// 		}

// 		abs_num = num;
// 		for (i = num_digits - 1; i >= 0; i--)
// 		{
// 			buffer[len + i] = '0' + (abs_num % 10);
// 			abs_num /= 10;
// 		}
		
// 		len += num_digits;
// 	}

// 	write(1, buffer, len);

// 	return (len);
// }
#include "main.h"

void flushBuffer(char *buffer, int *pchar)
{
    write(1, buffer, *pchar);
    *pchar = 0;
}

int print_str(char *str, char *buffer, int *pchar)
{
    int len = strlen(str);

    if (*pchar + len >= BUFFER_SIZE)
    {
        flushBuffer(buffer, pchar);
    }

    for (int i = 0; i < len; i++)
    {
        buffer[(*pchar)++] = str[i];
    }

    return len;
}

int print_int(int num, char *buffer, int *pchar)
{
    char temp_buffer[12];  // Temporary buffer to hold integer characters
    int len = 0;
    int abs_num, i;
    int num_digits = 0;

    if (num == 0)
    {
        temp_buffer[len++] = '0';
    }
    else
    {
        if (num < 0)
        {
            buffer[(*pchar)++] = '-';
            num = -num;
        }

        abs_num = num;

        while (abs_num > 0)
        {
            temp_buffer[num_digits++] = '0' + (abs_num % 10);
            abs_num /= 10;
        }

        if (*pchar + num_digits >= BUFFER_SIZE)
        {
            flushBuffer(buffer, pchar);
        }

        for (i = num_digits - 1; i >= 0; i--)
        {
            buffer[(*pchar)++] = temp_buffer[num_digits - 1 - i];
        }
    }

    return len;
}
