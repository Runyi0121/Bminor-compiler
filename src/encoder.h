/* encoder.h */

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* Constants */
/* Structures */

/* Functions */
int string_decode( const char *es, char *s );
int string_encode( const char *s, char *es );