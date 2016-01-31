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
 * @file mm_parse.h
 * The public declarations of the parsing engine.
 */

#ifndef MM_PARSE_H
#define MM_PARSE_H

// Includes
#include "types.h"

// Preprocessor defines

/*
 * TODO: comment
 * ret TRUE iff correct input
 */
bool mm_parse_input(char * input_file);

#endif //MM_PARSE_H
