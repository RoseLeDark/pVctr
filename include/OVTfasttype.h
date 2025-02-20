//  SPDX-FileCopyrightText: 2025 Amber-Sophia Schröck 
//  SPDX-License-Identifier: MIT
#ifndef __vector_fast_type_h_
#define __vector_fast_type_h_ 1

#include "OVT.h"

#include <stdint.h>
#include <stddef.h>  // Für size_t
#include <limits.h>

// --- Basic Bit Type (fast_bit) ---
typedef struct {
    uint8_t bit : 1;  // Ein Bit im `bit`-Feld
} ovt_bit_t;

// --- Fast Type für eine Anzahl von Bits ---
#define OVT_FAST_TYPE(Bits, TBaseType, TName) \
typedef struct { \
    union { \
        TBaseType value; \
        ovt_bit_t* bits; \
    }; \
    size_t count;  \
    ovt_bool_t alligen; \
    ovt_context_t* context; \
} TName; 

#if OVECTOR_VERSION_1_0 == 1

OVT_FAST_TYPE(sizeof(ovt_schar_t)    * CHAR_BIT, ovt_schar_t,   ovt_fast_schar_t);
OVT_FAST_TYPE(sizeof(ovt_uchar_t)    * CHAR_BIT, ovt_uchar_t,   ovt_fast_uchar_t);
OVT_FAST_TYPE(sizeof(ovt_sshort_t)   * CHAR_BIT, ovt_sshort_t,  ovt_fast_sshort_t);
OVT_FAST_TYPE(sizeof(ovt_ushort_t)   * CHAR_BIT, ovt_ushort_t,  ovt_fast_ushort_t);
OVT_FAST_TYPE(sizeof(ovt_sint_t)     * CHAR_BIT, ovt_sint_t,    ovt_fast_sint_t);
OVT_FAST_TYPE(sizeof(ovt_uint_t)     * CHAR_BIT, ovt_uint_t,    ovt_fast_uint_t);
OVT_FAST_TYPE(sizeof(ovt_slong_t)    * CHAR_BIT, ovt_slong_t,   ovt_fast_slong_t);
OVT_FAST_TYPE(sizeof(ovt_ulong_t)    * CHAR_BIT, ovt_ulong_t,   ovt_fast_ulong_t);

typedef ovt_uchar_t (APIENTRYP FPNONFASTSCHARCREATEPROC) (const ovt_context_t* context, ovt_fast_schar_t *type, const ovt_bool_t allignas, const ovt_schar_t value); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTUCHARCREATEPROC) (const ovt_context_t* context, ovt_fast_uchar_t *type, const ovt_bool_t allignas, const ovt_uchar_t value); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTSSHORTCREATEPROC) (const ovt_context_t* context, ovt_fast_sshort_t *type, const ovt_bool_t allignas, const ovt_sshort_t value); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTUSHORTCREATEPROC) (const ovt_context_t* context, ovt_fast_ushort_t *type, const ovt_bool_t allignas, const ovt_ushort_t value); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTSINTCREATEPROC) (const ovt_context_t* context, ovt_fast_sint_t *type, const ovt_bool_t allignas, const ovt_sint_t value); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTUINTCREATEPROC) (const ovt_context_t* context, ovt_fast_uint_t *type, const ovt_bool_t allignas, const ovt_uint_t value); 

typedef ovt_uchar_t (APIENTRYP FPNONFASTSCHARDESTRYPROC) (const ovt_context_t* context, ovt_fast_schar_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTUCHARDESTRYROC) (const ovt_context_t* context, ovt_fast_uchar_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTSSHORTDESTRYPROC) (const ovt_context_t* context, ovt_fast_sshort_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTUSHORTDESTRYPROC) (const ovt_context_t* context, ovt_fast_ushort_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTSINTDESTRYPROC) (const ovt_context_t* context, ovt_fast_sint_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTUINTDESTRYPROC) (const ovt_context_t* context, ovt_fast_uint_t *type); 

typedef ovt_void_t (APIENTRYP FPNONFASTSCHARRESETPROC) (volatile ovt_void_t *type, const ovt_void_t* value,  const ovt_size_t vsize); 
typedef ovt_void_t (APIENTRYP FPNONFASTSCHARSETBITPROC) (volatile ovt_void_t *type, ovt_size_t pos, ovt_bit_t value); 
typedef ovt_void_t (APIENTRYP FPNONFASTSCHARGETBITPROC) (volatile ovt_void_t *type, ovt_size_t pos, ovt_bit_t* value); 

typedef ovt_void_t (APIENTRYP FPNONFASTSCHAREQUALPROC) (const volatile ovt_void_t *a, const volatile ovt_void_t *b); 
typedef ovt_void_t (APIENTRYP FPNONFASTSCHARGREATERPROC) (const volatile ovt_void_t *a, const volatile ovt_void_t *b); 
typedef ovt_void_t (APIENTRYP FPNONFASTSCHARLESSPROC) (const volatile ovt_void_t *a, const volatile ovt_void_t *b); 
typedef ovt_void_t (APIENTRYP FPNONFASTSCHARGREATEREQUALPROC) (const volatile ovt_void_t *a, const volatile ovt_void_t *b); 
typedef ovt_void_t (APIENTRYP FPNONFASTSCHARLESSEQUALPROC) (const volatile ovt_void_t *a, const volatile ovt_void_t *b); 

VECTORAPI ovt_uchar_t APIENTRY ovt_fast_schar_create(const ovt_context_t* context, ovt_fast_schar_t *type, const ovt_bool_t allignas, const ovt_schar_t value);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_uchar_create(const ovt_context_t* context, ovt_fast_uchar_t *type, const ovt_bool_t allignas, const ovt_uchar_t value);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_sshort_create(const ovt_context_t* context, ovt_fast_sshort_t *type, const ovt_bool_t allignas, const ovt_sshort_t value);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_ushort_create(const ovt_context_t* context, ovt_fast_ushort_t *type, const ovt_bool_t allignas, const ovt_ushort_t value);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_sint_create(const ovt_context_t* context, ovt_fast_sint_t *type, const ovt_bool_t allignas, const ovt_sint_t value);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_uint_create(const ovt_context_t* context, ovt_fast_uint_t *type, const ovt_bool_t allignas, const ovt_uint_t value);

VECTORAPI ovt_uchar_t APIENTRY ovt_fast_schar_destroy(const ovt_context_t* context, ovt_fast_schar_t *type);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_uchar_destroy(const ovt_context_t* context, ovt_fast_schar_t *type);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_sshort_destroy(const ovt_context_t* context, ovt_fast_schar_t *type);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_ushort_destroy(const ovt_context_t* context, ovt_fast_schar_t *type);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_sint_destroy(const ovt_context_t* context, ovt_fast_schar_t *type);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_uint_destroy(const ovt_context_t* context, ovt_fast_schar_t *type);

#if OPENVECTOR_SUPPORT_INT64 == 1

typedef ovt_uchar_t (APIENTRYP PFNOVFASTSLONGCREATEPROC) (const ovt_context_t* context, const ovt_bool_t allignas, const ovt_fast_slong_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTULONGCREATEPROC) (const ovt_context_t* context, const ovt_bool_t allignas, const ovt_fast_ulong_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTSLONGDESTROYEPROC) (const ovt_context_t* context, ovt_fast_slong_t *type); 
typedef ovt_uchar_t (APIENTRYP PFNOVFASTULONGCDESTPOYPROC) (const ovt_context_t* context, ovt_fast_ulong_t *type); 

VECTORAPI ovt_uchar_t APIENTRY ovt_fast_slong_create(const ovt_context_t* context, ovt_fast_slong_t *type, const ovt_bool_t allignas, const ovt_slong_t value);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_ulong_create(const ovt_context_t* context, ovt_fast_ulong_t *type, const ovt_bool_t allignas, const ovt_ulong_t value);

VECTORAPI ovt_uchar_t APIENTRY ovt_fast_slong_destroy(const ovt_context_t* context, ovt_fast_slong_t *type);
VECTORAPI ovt_uchar_t APIENTRY ovt_fast_ulong_destroy(const ovt_context_t* context, ovt_fast_ulong_t *type);
#endif //OPENVECTOR_SUPPORT_INT64

VECTORAPI ovt_size_t APIENTRY ovt_fast_type_reset(volatile ovt_void_t *type, const ovt_void_t* value,  const ovt_size_t vsize);
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_set_bit(volatile ovt_void_t *type, ovt_size_t pos, ovt_bit_t value); 
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_get_bit(volatile ovt_void_t *type, ovt_size_t pos, ovt_bit_t* value) ; 
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_equal(const volatile ovt_void_t *a, const volatile ovt_void_t *b);
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_greater(const volatile ovt_void_t *a, const volatile ovt_void_t *b);
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_less(const volatile ovt_void_t *a, const volatile ovt_void_t *b);
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_greater_eq(const volatile ovt_void_t *a, const volatile ovt_void_t *b);
VECTORAPI ovt_bool_t APIENTRY ovt_fast_type_less_eq(const volatile ovt_void_t *a, const volatile ovt_void_t *b);
#endif

#if OVECTOR_VERSION_1_1 == 1  
    #if OPENVECTOR_SUPPORT_FLOAT == 1

    OVT_FAST_TYPE(sizeof(ovt_float_t)    * CHAR_BIT, ovt_float_t,   ovt_fast_float_t);

    typedef ovt_uchar_t (APIENTRYP FPNONFASTFLOATCREATEPROC) (const ovt_context_t* context, ovt_fast_float_t *type, const ovt_bool_t allignas,const ovt_float_t value); 
    typedef ovt_uchar_t (APIENTRYP PFNOVFASTFLOATDESTROYPROC) (const ovt_context_t* context, ovt_fast_ulong_t *type); 
    VECTORAPI ovt_uchar_t APIENTRY ovt_fast_float_create(const ovt_context_t* context, ovt_fast_float_t *type, const ovt_bool_t allignas, const ovt_float_t value);
    VECTORAPI ovt_uchar_t APIENTRY ovt_fast_float_destroy(const ovt_context_t* context, ovt_fast_float_t *type);

    #endif // OPENVECTOR_SUPPORT_FLOAT == 1
    
    #if OPENVECTOR_SUPPORT_DOUBLE == 1

    OVT_FAST_TYPE(sizeof(ovt_double_t)    * CHAR_BIT, ovt_double_t,   ovt_fast_double_t);

    typedef ovt_uchar_t (APIENTRYP FPNONFASTDOUBLECREATEPROC) (const ovt_context_t* context, ovt_fast_double_t *type, const ovt_bool_t allignas, const ovt_double_t value); 
    typedef ovt_uchar_t (APIENTRYP PFNOVFASTDOUBLEDESTROYPROC) (const ovt_context_t* context, ovt_fast_ulong_t *type); 

    VECTORAPI ovt_uchar_t APIENTRY ovt_fast_double_create(const ovt_context_t* context, ovt_fast_double_t *type, const ovt_bool_t allignas, const ovt_double_t value);
    VECTORAPI ovt_uchar_t APIENTRY ovt_fast_double_destroy(const ovt_context_t* context, ovt_fast_double_t *type);
    #endif // OPENVECTOR_SUPPORT_DOUBLE == 1

#endif // OVECTOR_VERSION_1_1 == 1  

#endif  //__vector_fast_type_h_