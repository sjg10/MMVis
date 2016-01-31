/*
 * MMVis - Metamath Visual - A metamath language parser to create visual representations of mathematical proofs.
 * Copyright (C) 2016 Samuel Gonshaw
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * @file main.c
 * The main entry point to the program. 
 */

// Includes
#include <stdio.h>
#include "types.h"
#include "mm_parse.h"

// Preprocessor defines
#define REQUIRED_INPUT_COUNT 2

#define ERROR_NONE           0
#define ERROR_INPUT_SYNTAX   1
#define ERROR_PARSE_ERROR    2


// Local Function Definitions

/*
 * TODO: comment
 */
void print_usage(char* prog_name)
{
    printf("Error: Bad usage.\n");
    printf("Usage: %s INPUT_FILE.\n", prog_name);
}

/*
 * TODO: comment
 */
int main(int argc, char ** argv)
{
    int retval = ERROR_NONE;

    if (argc != REQUIRED_INPUT_COUNT)
    {
        print_usage(argv[0]);
        retval = ERROR_INPUT_SYNTAX;
    }
    else
    {
        if (mm_parse_input(argv[1]) == FALSE)
        {
            printf("Parse error!\n");
            retval = ERROR_PARSE_ERROR;
        }
    }
    return retval;
}
