#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include <stddef.h>

typedef struct {
    float coeffs[8];  
    float buffer[8];  
    size_t index;     
} FIRFilter;

void fir_init(FIRFilter *filter, const float *coeffs);
float fir_apply(FIRFilter *filter, float input);

#endif
