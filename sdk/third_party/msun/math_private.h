/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 */

#pragma once

#include <stdint.h>

typedef float  float_t;
typedef double double_t;

typedef uint8_t  u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint64_t u_int64_t;

typedef union
{
	double value;
	struct
	{
		u_int32_t lsw;
		u_int32_t msw;
	} parts;
	struct
	{
		u_int64_t w;
	} xparts;
} ieee_double_shape_type;

/* Get two 32 bit ints from a double.  */

#define EXTRACT_WORDS(ix0, ix1, d)                                             \
	do                                                                         \
	{                                                                          \
		ieee_double_shape_type ew_u;                                           \
		ew_u.value = (d);                                                      \
		(ix0)      = ew_u.parts.msw;                                           \
		(ix1)      = ew_u.parts.lsw;                                           \
	} while (0)

/* Set a double from two 32 bit ints.  */

#define INSERT_WORDS(d, ix0, ix1)                                              \
	do                                                                         \
	{                                                                          \
		ieee_double_shape_type iw_u;                                           \
		iw_u.parts.msw = (ix0);                                                \
		iw_u.parts.lsw = (ix1);                                                \
		(d)            = iw_u.value;                                           \
	} while (0)

/* Get the more significant 32 bit int from a double.  */

#define GET_HIGH_WORD(i, d)                                                    \
	do                                                                         \
	{                                                                          \
		ieee_double_shape_type gh_u;                                           \
		gh_u.value = (d);                                                      \
		(i)        = gh_u.parts.msw;                                           \
	} while (0)

/* Get the less significant 32 bit int from a double.  */

#define GET_LOW_WORD(i, d)                                                     \
	do                                                                         \
	{                                                                          \
		ieee_double_shape_type gl_u;                                           \
		gl_u.value = (d);                                                      \
		(i)        = gl_u.parts.lsw;                                           \
	} while (0)

#define SET_HIGH_WORD(d, v)                                                    \
	do                                                                         \
	{                                                                          \
		ieee_double_shape_type sh_u;                                           \
		sh_u.value     = (d);                                                  \
		sh_u.parts.msw = (v);                                                  \
		(d)            = sh_u.value;                                           \
	} while (0)

#define SET_LOW_WORD(d, v)                                                     \
	do                                                                         \
	{                                                                          \
		ieee_double_shape_type sl_u;                                           \
		sl_u.value     = (d);                                                  \
		sl_u.parts.lsw = (v);                                                  \
		(d)            = sl_u.value;                                           \
	} while (0)

/*
 * A union which permits us to convert between a float and a 32 bit
 * int.
 */

typedef union
{
	float value;
	/* FIXME: Assumes 32 bit int.  */
	unsigned int word;
} ieee_float_shape_type;

/* Get a 32 bit int from a float.  */

#define GET_FLOAT_WORD(i, d)                                                   \
	do                                                                         \
	{                                                                          \
		ieee_float_shape_type gf_u;                                            \
		gf_u.value = (d);                                                      \
		(i)        = gf_u.word;                                                \
	} while (0)

/* Set a float from a 32 bit int.  */

#define SET_FLOAT_WORD(d, i)                                                   \
	do                                                                         \
	{                                                                          \
		ieee_float_shape_type sf_u;                                            \
		sf_u.word = (i);                                                       \
		(d)       = sf_u.value;                                                \
	} while (0)

#define STRICT_ASSIGN(type, lval, rval)                                        \
	do                                                                         \
	{                                                                          \
		volatile type __lval;                                                  \
                                                                               \
		if (sizeof(type) >= sizeof(long double))                               \
			(lval) = (rval);                                                   \
		else                                                                   \
		{                                                                      \
			__lval = (rval);                                                   \
			(lval) = __lval;                                                   \
		}                                                                      \
	} while (0)
