#ifndef NIGMA_CAOL_H
#define NIGMA_CAOL_H

#include "utilities.h"

//Set's the specified area <pBuff> -> <size> bytes to zero.
extern void caolOPZEROArea(void *pBuff, caolSAddr size);
//Set's the specified area <pBuff> -> <size> bytes to <value>.
extern void caolOPSETArea(void *pBuff, caolU8 value, caolSAddr size);
//Moves the specified area <pBuff> -> <count * offset>(And hence byte aligned by <offset>) horizontally to the Left <offset> many bytes.
extern void caolOPMOVLArea(void *pBuff, caolSAddr offset, caolSAddr count);
//Moves the specified area <pBuff> -> <count * offset>(And hence byte aligned by <offset>) horizontally to the Right <offset> many bytes.
extern void caolOPMOVRArea(void *pBuff, caolSAddr offset, caolSAddr count);
//Copies <size> bytes from the specified source area <pSrc> -> <size> into the specified destination area <pDest> -> <size>.
extern void caolOPCPYArea(const void *pSrc, void *pDest, caolSAddr size);
//Swaps <size> bytes from the specified source area <pBuffA> -> <size> with the specified destination area <pBuffB> -> <size>.
extern void caolOPSWPArea(void *pBuffA, void *pBuffB, caolSAddr size);

//Checks 'size' bytes for 'value' in the specified area <pBuff> -> <size>, sets 'pIndex' either upon finding 'value' or reaching 'size'.
extern void caolOPFINDValIndex(caolSAddr *pIndex, void *pBuff, caolU8 value, caolSAddr size);

extern void caolOPCONVStrToNum(caolU64 *pValue, void *pBuff);
extern void caolOPCONVNumToStr_8B (void *pBuff, caolU8 value);
extern void caolOPCONVNumToStr_16B(void *pBuff, caolU16 value);
extern void caolOPCONVNumToStr_32B(void *pBuff, caolU32 value);
extern void caolOPCONVNumToStr_64B(void *pBuff, caolU64 value);

extern void caolOPSWPEndian_16B(caolU16 *pValue);
extern void caolOPSWPEndian_32B(caolU32 *pValue);
extern void caolOPSWPEndian_64B(caolU64 *pValue);

#endif