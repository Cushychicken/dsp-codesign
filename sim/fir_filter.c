#include "fir_filter.h"
#include <string.h>  

void fir_init(FIRFilter *filter, const float *coeffs) {
    memcpy(filter->coeffs, coeffs, sizeof(filter->coeffs));  
    memset(filter->buffer, 0, sizeof(filter->buffer));       
    filter->index = 0;                                       
}

float fir_apply(FIRFilter *filter, float input) {
    filter->buffer[filter->index] = input;
    float output = 0.0f;
    size_t i, j;
    
    for (i = 0, j = filter->index; i < 8; i++) {
        output += filter->coeffs[i] * filter->buffer[j];
        j = (j == 0) ? 7 : j - 1;  
    }

    filter->index = (filter->index + 1) % 8;
    return output;
}
