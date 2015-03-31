/*

  RealLib, a library for efficient exact real computation
  Copyright (C) 2006  Branimir Lambov <barnie@brics.dk>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/ 

#ifndef FILE_KERNELS_H
#define FILE_KERNELS_H

#include "defs.h"

namespace RealLib {

// helper functions on mantissas
// they modify new mantissas

void InitializeKernels(u32 prec);
void FinalizeKernels();

// NormalizeMantissa: substraction can introduce zeroes in most
// significant positions of the mantissa. This function corrects
// such mantissas and returns the value that has to be substracted
// from the exponent. If this value is equal to working precision,
// the substraction function must recognize the value as Zero.
u32 NormalizeMantissa(u32 *man);
// perform the actual addition
// returns true if there is carry
bool AddMantissa(u32 *man,          // destination, pre-initialized by a call to the default constructor
                 const u32 *full,   // the greater value
                 const u32 *part,   // the partial value,
                 i32 start);            // which is shifted by this many words
// adjust for calculations that don't fit the preallocated space.
// an extra pass might be needed if the leftover word introduces more carry.
// returns number of shifts done
u32  AdjustForCarry(u32 *man, 
                    u32 msw);           // most significant word, the one that doesn't fit in
// perform the actual substraction
// returns true if part was greater and the result must be negated
bool SubMantissa(u32 *man,          // destination, pre-initialized by a call to the default constructor
                 const u32 *full,   // the greater value
                 const u32 *part,   // the partial value,
                 i32 start);                // which is shifted by this many words
// negate a mantissa. needed if SubMantissa returned true
void NegMantissa(u32 *man);
// MulMantissa
// perform actual multiplication
// the most significant word of the result is not put in man.
// instead it is returned, so no precision will be lost if
// it is zero
// inputlen tells how many words should actually be multiplied
// inputstart is usually (precision - inputlen), where the multiplication
//    should start
u32 MulMantissa(u32 *man, 
                const u32 *a,
                const u32 *b,
                i32 inputstart,
                i32 inputlen);
// returns whether the kernels would use convolution on this inputlen               
bool MultipliedByConvolution(i32 inputlen);             
// DivMantissa
// perform division. Returns the exponent offset.
// inputstart and inputlen as before, but division needs a temporary 
// mantissa to work on.
// can be inplace in a.
// The LongFloat implementation would only call DivMantissa 
// if MultipliedByConvolution returns false.
// Otherwise it will use Newton iterations.
i32 DivMantissa(u32 *man,
            const u32 *a,
            const u32 *b,
            i32 inputstart,
            i32 inputlen,
            u32 *temp1,
            u32 *temp2);

// scale mantissa: multiplication by u32 multiplier
// implemented for performance. returns carry
u32 ScaleMantissa(u32 *man,
                  const u32 *src,
                  u32 multiplier);
// inverse scaling: division by u32 divisor
// returns exponent offset
i32 InvScaleMantissa(u32 *man,
                  const u32 *src,
                  u32 divisor);
// binary scale mantissa, i.e. multiply by 1<<scale, where scale < 32
u32 BScaleMantissa(u32 *man,
                  const u32 *src,
                  u32 scale);

}   // namespace

#endif  // file
