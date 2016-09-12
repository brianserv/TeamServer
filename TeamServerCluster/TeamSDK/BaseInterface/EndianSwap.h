
#ifndef __ENDIAN_SWAP_H__
#define __ENDIAN_SWAP_H__


#if defined (_WIN32) || defined (_WIN64)
  #include "sysdef.h"
#pragma  warning(disable: 4200)
#else
  #include <stdint.h>

#endif




inline uint16_t Endian_Swap16(uint16_t x) { return((x<<8)|(x>>8));}

inline uint32_t Endian_Swap32(uint32_t x) {
        return((x<<24)|((x<<8)&0x00FF0000)|((x>>8)&0x0000FF00)|(x>>24));
}


inline uint64_t Endian_Swap64(uint64_t x) {
        uint32_t hi, lo;

        /* Separate into high and low 32-bit values and swap them */
        lo = (uint32_t)(x&0xFFFFFFFF);
        x >>= 32;
        hi = (uint32_t)(x&0xFFFFFFFF);
        x = Endian_Swap32(lo);
        x <<= 32;
        x |= Endian_Swap32(hi);
        return(x);

}

void Endian_Swap16_buf(uint16_t *dst, uint16_t *src, int w);

#ifndef WORDS_BIGENDIAN
#define Endian_SwapLE16(X) (X)
#define Endian_SwapLE32(X) (X)
#define Endian_SwapLE64(X) (X)
#define Endian_SwapBE16(X) Endian_Swap16(X)
#define Endian_SwapBE32(X) Endian_Swap32(X)
#define Endian_SwapBE64(X) Endian_Swap64(X)
#else
#define Endian_SwapLE16(X) Endian_Swap16(X)
#define Endian_SwapLE32(X) Endian_Swap32(X)
#define Endian_SwapLE64(X) Endian_Swap64(X)
#define Endian_SwapBE16(X) (X)
#define Endian_SwapBE32(X) (X)
#define Endian_SwapBE64(X) (X)
#endif


#endif  /* __ENDIAN_SWAP_H__ */
