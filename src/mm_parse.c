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
#include "mm_lang_types.h"

// Preprocessor defines
#define INITIAL_MAX_INPUT_SIZE (1024 * 1024) // A MB of char's

// Local Function Definitions

/*
 * TODO: comment
 */
bool mm_parse_preprocess(FILE * fp, char * _pf)
{
    bool retval = TRUE;
    char * pf = _pf - 1; //increment before any read!
    int save_space = INITIAL_MAX_INPUT_SIZE;
    bool comment_block = FALSE;
    do
    {
        *(++pf) = fgetc(fp);
        if (feof(fp)) break;
        if (*pf == MM_CHAR_CTRL) //TODO: this ignores the need for whitespace. include? see spec
        {
            *(++pf) = fgetc(fp);
            if (comment_block == FALSE)
            {
                switch (*pf)
                {
                    case MM_CHAR_OPEN_COMMENT:
                        pf -= 1; // other one achieved by comment block
                        comment_block = TRUE;
                        break;
                    case MM_CHAR_CLOSE_COMMENT:
                        printf("Close comment block outside comments.\n");
                        retval = FALSE;
                        break;
                    default:
                        break;
                    //TODO: include handling
                }
            }
            else
            {
                switch (*pf)
                {
                    case MM_CHAR_CLOSE_COMMENT:
                        pf -= 2;
                        comment_block = FALSE;
                        break;
                    case MM_CHAR_OPEN_COMMENT:
                        printf("Open comment block inside comments.\n");
                        retval = FALSE;
                        break;
                    default:
                        break;
                }
            }
            if (feof(fp)) break;
        }
        if (comment_block == TRUE) pf--;
        //TODO: test
        if ( (pf - _pf) > (save_space - 2) )
        {
                printf("realloc memory\n");
            save_space *= 2;
            char* tmp = realloc(_pf, save_space);
            if (tmp == NULL)
            {
                retval = FALSE;
                printf("Out of memory\n");
            }
            else
            {
                pf = tmp + (pf - _pf);
                _pf = tmp;
            }
        }
    } while(retval == TRUE);
    if(comment_block == TRUE) retval = FALSE;
    //TODO: consider EOF -> null char ending
    *pf = '\0';
    // /* DEBUG TODO: tidy!
        FILE* fout = fopen("out.c","w");
        fprintf(fout,"%s",_pf);
        fclose(fout);
    // */
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
        retval &= (preprocessed_file == NULL ? FALSE : TRUE);

        if (retval == TRUE) retval &= mm_parse_preprocess(fp, preprocessed_file);
        fclose(fp); //TODO: error check, combine with other if-case

        if (retval == TRUE) retval &= mm_parse_process(preprocessed_file);

        free(preprocessed_file);
    }

    return retval;
}
