/**
    CSC: Circular Sequence Comparison
    Copyright (C) 2015 Solon P. Pissis. 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef __CSC__
#define __CSC__

#include <sdsl/bit_vectors.hpp>
#define ALLOC_SIZE              1048576
#define DEL                     '$'
#define DEL_STR                 "$"
#define METHOD_H                "hCSC"
#define METHOD_N                "nCSC"
#define METHOD_SA               "saCSC"
#define ALPHABET_DNA            "DNA"
#define ALPHABET_PROT           "PROT"
#define ALPHABET_IUPAC          "IUPAC"
#define DNA                     "ACGTN"                         //DNA alphabet
#define PROT                    "ARNDCQEGHILKMFPSTWYV"          //Proteins alphabet
#define IUPAC                   "ACGTUWSMKRYBDHVN"          	//IUPAC alphabet
#define max(a,b) ((a) > (b)) ? (a) : (b)
#define min(a,b) ((a) < (b)) ? (a) : (b)

using namespace sdsl;
using namespace std;

#ifdef _USE_64
typedef int64_t INT;
#endif

#ifdef _USE_32
typedef int32_t INT;
#endif

struct TSwitch
{
    char *               input_filename;         // the input file name
    char *               output_filename;        // the output file name
    char *               alphabet;               // the output file name
    char *               method;                 // algorithm/method
    unsigned int         b;                      // block size/number
    unsigned int         q;                      // q-gram size
};

struct TPOcc
{
    unsigned int         err;
    unsigned int         rot;
};

double gettime( void );
int decode_switches ( int argc, char * argv [], struct TSwitch * sw );
void usage ( void );
unsigned int LCParray ( unsigned char *text, INT n, INT * SA, INT * ISA, INT * LCP );
void partitioning ( INT i, INT j, INT f, INT m, INT * mf, INT * ind );
unsigned int circular_sequence_comparison (  unsigned char * x, unsigned char * y, struct TSwitch  sw, unsigned int * rotation, unsigned int * distance );
unsigned int create_rotation ( unsigned char * x, unsigned int offset, unsigned char * rotation );

#endif
