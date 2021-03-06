/*
 *  ccsha2_internal.h
 *  corecrypto
 *
 *  Created on 12/07/2010
 *
 *  Copyright (c) 2010,2011,2012,2014,2015 Apple Inc. All rights reserved.
 *
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _CORECRYPTO_CCSHA2_INTERNAL_H_
#define _CORECRYPTO_CCSHA2_INTERNAL_H_

#include <corecrypto/ccdigest.h>

void ccsha256_ltc_compress(ccdigest_state_t state, size_t nblocks, const void *buf);
void ccsha256_v6m_compress(ccdigest_state_t state, size_t nblocks, const void *buf);
void ccsha512_ltc_compress(ccdigest_state_t state, size_t nblocks, const void *in);

#if  CCSHA2_VNG_INTEL
#if defined __x86_64__
void ccsha256_vng_intel_avx2_compress(ccdigest_state_t state, size_t nblocks, const void *in);
void ccsha256_vng_intel_avx1_compress(ccdigest_state_t state, size_t nblocks, const void *in);
void ccsha256_vng_intel_ssse3_compress(ccdigest_state_t state, size_t nblocks, const void *in);
void ccsha512_vng_intel_avx2_compress(ccdigest_state_t state, size_t nblocks, const void *in);
void ccsha512_vng_intel_avx1_compress(ccdigest_state_t state, size_t nblocks, const void *in);
void ccsha512_vng_intel_ssse3_compress(ccdigest_state_t state, size_t nblocks, const void *in);
#endif
void ccsha256_vng_intel_sse3_compress(ccdigest_state_t state, size_t nblocks, const void *in);
#endif

void ccsha512_final(const struct ccdigest_info *di, ccdigest_ctx_t ctx, unsigned char *digest);

extern const uint32_t ccsha224_initial_state[8];
extern const uint32_t ccsha256_initial_state[8];
extern const uint64_t ccsha384_initial_state[8];
extern const uint64_t ccsha512_initial_state[8];

#endif /* _CORECRYPTO_CCSHA2_INTERNAL_H_ */
