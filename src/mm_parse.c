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
 * @file mm_parse.c
 * This parses the input file to an array of statements. 
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "mm_parse.h"

// Preprocessor defines
#define INITIAL_MAX_INPUT_SIZE (1024 * 1024) // A MB of char's

// Local Function Definitions

/*
 * TODO: comment
 */
bool mm_parse_preprocess(FILE * fp, char * pf)
{
    bool retval = TRUE;
    //TODO: read in file to pf,
    //TODO: expandincludes and comments into pf
    //TODO: realloc as needed
    return retval; 
}

/*
 * TODO: comment
 */
bool mm_parse_process(char * pf)
{
    bool retval = TRUE;
    //TODO: convert pf into global statement struct
    return retval; 
}

bool mm_parse_input(char * input_file)
{
    int retval = TRUE;   
    FILE *fp;

    fp = fopen(input_file, "r");

    if (fp == NULL)
    {
        printf("Could not find file.\n");
        retval = FALSE;
    }
    else
    {
        char* preprocessed_file = (char*) malloc(INITIAL_MAX_INPUT_SIZE * sizeof(char));
        retval &= mm_parse_preprocess(fp, preprocessed_file);
        fclose(fp); //TODO: error check, combine with other if-case

        if(retval == TRUE) retval &= mm_parse_process(preprocessed_file);

        free(preprocessed_file);
    }

    return retval;
}
