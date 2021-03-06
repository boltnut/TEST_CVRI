/* **********************************************************************

         Copyright (c) 2002-2013 Beyond Innovation Technology Co., Ltd

        All rights are reserved. Reproduction in whole or in parts is
    prohibited without the prior written consent of the copyright owner.

   ----------------------------------------------------------------------
    Software License Agreement

    The software supplied herewith by Beyond Innovation Technology Co., Ltd
    (the "Company") is intended and supplied to you, the Company's
    customer, for use solely and exclusively on BiTEK products.

    The software is owned by the Company and/or its supplier, and is
    protected under applicable copyright laws. All rights are reserved.
    Any use in violation of the foregoing restrictions may subject the
    user to criminal sanctions under applicable laws, as well as to
    civil liability for the breach of the terms and conditions of this
    license.

    THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
    TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
    IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

   ----------------------------------------------------------------------

    Module: VP.C - Video Processor.

    Purpose: Implementation of VP module.

    Version: 0.01                                   06:37PM  2013/03/16

    Compiler: Keil 8051 C Compiler v9.51

    Reference:

   ----------------------------------------------------------------------
    Modification:

    v0.01 06:37PM  2013/03/16 Jeffrey Chang
    Reason:
        1. Original.
    Solution:

   ********************************************************************** */

#define  _VP_C_


/* ------------------------------------
    Header Files
   ------------------------------------ */
#include "bit1618c.h"
#include "bitek.h"
#include "common.h"
#include "osd.h"
#include "timer.h"
#include "vp.h"


/* ------------------------------------
    Macro Definitions
   ------------------------------------ */
#define VP_DEBUG        OFF

/* ------------------------------------
    Type Definitions
   ------------------------------------ */

/* ------------------------------------
    Variables Definitions
   ------------------------------------ */

#if 0
        // VID1124-110-174
        // HSD HB070AM18512A 7" (800 (H) x RGB x 480 (V))
        // VP
        UB8 CODE abVP_00A_0FE[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
// 0 */                                                   0x12,0xA3,0xFC,0xAB,0xBF,0x80, // R00E[5]=0 (BCLK=XCLK)
/* 0 */                                                   0x12,0xA3,0xFC,0xAB,0x9F,0x80, // R00E[5]=0 (BCLK=XCLK)
/* 1 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x05,0x2C,0x0C,0x20,0xA1,0x23,0x22,0x01, // R016=004h
/* 2 */ 0x0B,0xF5,0x0C,0x44,0x00,0x80,0x00,0x80,0x09,0x00,0x31,0x44,0x00,0x01,0x37,0x00,
/* 3 */ 0x27,0x38,0x00,0x14,0x15,0x00,0x00,0x09,0x0A,0x80,0x49,0x09,0xBF,0xFB,0x01,0x00,
/* 4 */ 0x00,0x3F,0x3F,0x84,0xE2,0x08,0xA5,0x5A,0x30,0x14,0x38,0x10,0x90,0x4C,0x30,0x0F,
/* 5 */ 0x0E,0x10,0x40,0x58,0x88,0xC3,0xC3,0xE0,0xE0,0x11,0x2C,0x0C,0x20,0x68,0xD0,0x10,
/* 6 */ 0x0B,0xF5,0x00,0x20,0x00,0x03,0x00,0x66,0x00,0x01,0x03,0x00,0xDE,0x00,0x01,0x03,
/* 7 */ 0x6C,0xD8,0x30,0x00,0x6C,0xF1,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xE0,
/* 8 */ 0x2C,0x00,0x10,0x03,0x40,0xC0,0xF6,0x00,0x00,0x03,0x12,0xC0,0x2F,0x35,0x0F,0xA2,
/* 9 */ 0xBD,0x45,0x5B,0x00,0x00,0x00,0xA4,0x03,0x00,0x7B,0x7B,0xFF,0xAC,0xF2,0x04,0xB3,
/* A */ 0x04,0x04,0x00,0x40,0x22,0x78,0x80,0x00,0x00,0x00,0x0D,0x0D,0x00,0x88,0xA0,0x40,
/* B */ 0x19,0x85,0x85,0xEA,0xA4,0x32,0x7F,0x31,0xFE,0xFE,0x40,0x32,0x00,0x08,0x00,0x00,
/* C */ 0x4D,0xFB,0x71,0x80,0xC3,0x92,0x9B,0x01,0x9B,0x01,0x92,0x81,0x00,0xD0,0x00,0x00,
/* D */ 0x00,0x10,0x80,0x5E,0x8D,0x04,0x00,0x00,0x00,0x00,0x15,0x00,0x3F,0x8E,0xD0,0x8F,// R0D4
/* E */ 0x03,0xF8,0x3E,0x25,0x02,0x00,0x00,0x88,0x01,0x00,0x00,0x03,0x00,0x00,0x00,0x00,
// F */ 0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x01,0x70,0x00,0x30,0x64,0x62,0x00,0x00      // R0FB=044h for BL OFF
/* F */ 0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x01,0x70,0x00,0x30,0x44,0x62,0x00,0x00      // R0FB=044h for BL OFF
        };


        #if 0
        UB8 CODE abVP_130_1FF[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*13 */ 0x80,0x80,0x80,0x80,0x80,0x80,0xC6,0x39,0x38,0x80,0x80,0x80,0xC0,0x02,0x40,0x40,
/*14 */ 0x04,0xAA,0x38,0xCF,0x4C,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*15 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x66,0x00,0x00,0x02,0xF0,0x6B,0x04, // 0x15C and 0x15F
/*16 */ 0x00,0x03,0xB8,0x40,0x1C,0x00,0x00,0x00,0x00,0x05,0x01,0x00,0x03,0x00,0x6B,0xF9, // MSF_SRC(0x164[6:5]) = TOUT (00), MSF_TOUT(0x164[1])=0, 0x161=003h
/*17 */ 0x20,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*18 */ 0x11,0x51,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x7C,0x7C,0x00,
/*19 */ 0x00,0x00,0x60,0x00,0xF0,0x00,0xFF,0x00,0x07,0x45,0x07,0x07,0x45,0x07,0x0A,0xFE,
/*1A */ 0x00,0x09,0x09,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x0F,0x10,0x00,0x00,0x00,
/*1B */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*1C */ 0x00,0x00,0x44,0x59,0x06,0x07,0x31,0x00,0x00,0x00,0x1E,0xFA,0x50,0xCA,0x39,0x82,
/*1D */ 0x01,0x8F,0x01,0x8F,0x00,0x13,0x90,0x58,0x20,0x00,0xBA,0x19,0x3E,0xB6,0xD0,0x37,
/*1E */ 0x04,0x00,0x00,0x00,0x00,0x0F,0x8D,0x30,0x99,0x99,0x1B,0x00,0x00,0x20,0x0B,0x00,
/*1F */ 0x53,0x53,0x00,0x00,0x08,0x7E,0x00,0x7E,0x8F,0x00,0x00,0x00,0x00,0x4B,0xFF,0x7E,
        };
        #endif


        UB8 CODE abVP_130_145[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*13 */ 0x80,0x80,0x80,0x80,0x80,0x80,0xC6,0x39,0x38,0x80,0x80,0x80,0xC0,0x02,0x40,0x40, // R138[6]=0 YUV Gamma OFF
/*14 */ 0x04,0xAA,0x38,0xCF,0x4C,0x2B
        };


        UB8 CODE abM8051_160_163[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*16 */ 0x00,0x03,0xB8,0x40                                                              // IC default + 24C32
        };


        UB8 CODE abPWM_17F_183[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*17 */                                                                            0x00,
/*18 */ 0x11,0x51,0x00,0x20
        };


        UB8 CODE abPLL_198_19E[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*19 */                                         0x07,0x45,0x07,0x07,0x45,0x07,0x0A
        };


        #if 0
        UB8 CODE abAOSD_146_15F[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*14 */                               0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*15 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x66,0x00,0x00,0x02,0xF0,0x6B,0x04, // 0x15C=002h
        };
        
        UB8 CODE abDMA_164_170[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*16 */                     0x1C,0x00,0x00,0x00,0x00,0x05,0x01,0x00,0x03,0x00,0x6B,0xF9, // IC default + 24C32
/*17 */ 0x20
        };

        UB8 CODE abIR_174_17E[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*17 */                     0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
        };

        UB8 CODE abSPI_185_189[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*18 */                          0x00,0x00,0x00,0x00,0x00
        };

        UB8 CODE abGPI_18C_194[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*18 */                                                             0x00,0x7C,0x7C,0x00,
/*19 */ 0x00,0x00,0x60,0x00,0xF0
        };

        UB8 CODE abSARADC_19F_1A9[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*19 */                                                                            0xFE,
/*1A */ 0x00,0x09,0x09,0x20,0x00,0x00,0x00,0x00,0x00,0x00
        };

        UB8 CODE abI2C_1AE_1B5[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*1A */                                                                       0x00,0x00,
/*1B */ 0x00,0x00,0x00,0x00,0x00,0x00
        };

        // For CPU Panel !
        UB8 CODE abCPU_1B9_1BD[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*1B */                                              0x00,0x00,0x00,0x00,0x00,
        };
        #endif
#endif


        // VID1232_100_128
        // InnoLux AT070TN94 7" (800 (H) x RGB x 480 (V))
        // VP
        UB8 CODE abVP_00A_0FE[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
// 0 */                                                   0x12,0x84,0xFC,0xA9,0xA9,0x00, // R00E[5]=0 (BCLK=XCLK)
/* 0 */                                                   0x12,0x84,0xFC,0xA9,0x89,0x00, // R00E[5]=0 (BCLK=XCLK)
/* 1 */ 0x00,0x00,0x00,0x00,0x22,0x00,0x04,0x00,0x0A,0x2D,0x4D,0x30,0xF8,0xC3,0x33,0x05, // R010=000h, R016=004h
/* 2 */ 0x08,0xE9,0x00,0x49,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x20,0x00,0x00,0x00,0x00,
/* 3 */ 0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x01,0x17,0x80,0x17,0x03,0x40,0x00,0x07,0x00,
/* 4 */ 0x00,0x3F,0x3F,0x84,0xE0,0x08,0xAA,0x7A,0x30,0x17,0x3E,0x10,0xA0,0x70,0x30,0x17,
/* 5 */ 0x17,0x10,0x40,0x58,0x88,0xC3,0xC3,0x20,0x80,0x23,0x2D,0x4D,0x30,0xA7,0x27,0x30,
/* 6 */ 0x18,0xF8,0x01,0x20,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x88,0x06,0x00,0x01,0x03,
/* 7 */ 0x6C,0xD8,0x30,0x88,0x6C,0xF1,0x30,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xE0,
/* 8 */ 0x8F,0xA4,0xA0,0x03,0x40,0xC0,0x77,0x2C,0x20,0x03,0x17,0x00,0x00,0x00,0x14,0xFB,
/* 9 */ 0x00,0x00,0xFB,0x00,0x00,0x00,0xA4,0x03,0x00,0x7B,0x7B,0xFF,0xAC,0xF2,0x04,0xB3,
/* A */ 0x04,0x04,0x00,0x40,0x22,0x78,0x80,0x00,0x00,0x00,0x0D,0x0D,0x00,0x88,0xA0,0x40,
/* B */ 0x19,0x8D,0x85,0xEA,0xA4,0x32,0x7F,0x31,0x80,0xFE,0x40,0x32,0x00,0x08,0x00,0x00,
/* C */ 0x4D,0xFB,0x71,0x80,0xC3,0x92,0x9B,0x01,0x9B,0x01,0x92,0x81,0x00,0xD0,0x00,0x00,
/* D */ 0x00,0x10,0x80,0x5E,0x8D,0x04,0x04,0x00,0x00,0x00,0x15,0x00,0x3F,0x8E,0xD0,0x8F,// R0D4
/* E */ 0x03,0x00,0x00,0x00,0x02,0x00,0x00,0x88,0x01,0x00,0x00,0x03,0x00,0x00,0x00,0x00,
/* F */ 0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x80,0x00,0x80,0x00,0x02,0x04,0x00      // R0FB=044h for BL OFF
        };


        #if 0
        UB8 CODE abVP_130_1FF[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*13 */ 0x80,0x80,0x80,0x80,0x80,0x80,0xC6,0x39,0x30,0x80,0x80,0x80,0xC0,0x02,0x40,0x40,
/*14 */ 0x04,0xAA,0x38,0xC2,0xCC,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*15 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x06,0x00,0x00,0x02,0x00,0x6B,0x00, // 0x15C and 0x15F
/*16 */ 0x00,0x03,0x80,0x40,0x00,0x00,0x00,0x6B,0x86,0x85,0x09,0x00,0x00,0x00,0x00,0x00, // MSF_SRC(0x164[6:5]) = TOUT (00), MSF_TOUT(0x164[1])=0, 0x161=003h
/*17 */ 0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,
/*18 */ 0x11,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x00,0x00,0x7C,0x7C,0x00,
/*19 */ 0x00,0x00,0x60,0x00,0xF0,0x7C,0xE7,0x00,0x01,0x16,0x04,0x0E,0x76,0x02,0x0A,0xFC,
/*1A */ 0x00,0x12,0x12,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0xF4,0x0E,0x00,0x00,0x00,0x00,
/*1B */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*1C */ 0x00,0x00,0x44,0x59,0x07,0x06,0x31,0x00,0x00,0x00,0x1B,0xFA,0x50,0xAA,0xEA,0x87,
/*1D */ 0x0B,0x51,0xFF,0xFA,0x01,0x30,0xB1,0x58,0xFD,0x00,0xB7,0x19,0xC7,0x80,0x16,0x30,
/*1E */ 0x04,0x00,0x00,0x00,0x00,0x2F,0x8D,0x46,0x84,0x80,0x13,0x00,0x00,0x00,0x01,0x00,
/*1F */ 0x00,0xF0,0xFD,0x7F,0x04,0x00,0x00,0x00,0x89,0x00,0x00,0x00,0x00,0x4B,0xFF,0x46,
        };
        #endif


        UB8 CODE abVP_130_145[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*13 */ 0x80,0x80,0x80,0x80,0x80,0x80,0xC6,0x39,0x30,0x80,0x80,0x80,0xC0,0x02,0x40,0x40, // R138[6]=0 YUV Gamma OFF, R138[7]=0 RGB Gamma OFF
/*14 */ 0x04,0xAA,0x38,0xC2,0xCC,0x2B
        };


        UB8 CODE abM8051_160_163[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*16 */ 0x00,0x0B,0x80,0x40                                                              // IC default + 24C32, R161=0Bh
        };

        UB8 CODE abPWM_17F_183[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*17 */                                                                            0x10,
/*18 */ 0x11,0x47,0x00,0x00
        };

        UB8 CODE abPLL_198_19E[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/*19 */                                         0x01,0x16,0x04,0x0E,0x76,0x02,0x0A
        };







/* ------------------------------------
    Function Prototypes
   ------------------------------------ */


/* -------------------------------------------------------------------
    Name: VP_Init -
    Purpose: To initiate VP module.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void VP_Init (void)
{
    // PLL
    BITEK_TxBurst(BITEK_198_PLL_DM_M0, sizeof(abPLL_198_19E), abPLL_198_19E);

    // VP Default Values !
    BITEK_TxBurst(BITEK_00A_CLK_ATTR0, sizeof(abVP_00A_0FE), abVP_00A_0FE);

    // VP Default Values !
    BITEK_TxBurst(BITEK_130_BRIGHTNESS_R, sizeof(abVP_130_145), abVP_130_145);

    // M8051
    BITEK_TxBurst(BITEK_160_M8051_DUMMY, sizeof(abM8051_160_163), abM8051_160_163);

    // PWM
    BITEK_TxBurst(BITEK_17F180_PWMx_FREQ, sizeof(abPWM_17F_183), abPWM_17F_183);

} /* VP_Init */



#if (VP_SET_BRIGHTNESS)
/* -------------------------------------------------------------------
    Name: VP_SetBrightness -
    Purpose: This function sets the VP Brightness.
    Passed:
    Returns: None.
    Notes: [1]63
   ------------------------------------------------------------------- */
void VP_SetBrightness (UB8 bBrightness)
{
    BITEK_TxByte(BITEK_13A_BRIGHTNESS, BRIGHTNESS_OFFSET + BRIGHTNESS_SLOPE * bBrightness);

    #if 0
    if (bBrightness > BRIGHTNESS_DEFAULT)
        BITEK_TxByte(BITEK_1F1_DAC_AMP, 94);
    else
        BITEK_TxByte(BITEK_1F1_DAC_AMP, 154 - 2 * bBrightness);
    #endif

    #if (VP_DEBUG)
    OSD_ShowValue(VP_SHOW_DEBUG_A, BITEK_RxByte(BITEK_13A_BRIGHTNESS), 100, ' ');
    OSD_ShowValue(VP_SHOW_DEBUG_B, BITEK_RxByte(BITEK_1F1_DAC_AMP), 100, ' ');
    #endif
} // VP_SetBrightness
#endif


#if (VP_SET_CONTRAST)
/* -------------------------------------------------------------------
    Name: VP_SetContrast -
    Purpose: This function sets the VP Contrast.
    Passed:
        0x00 = 0.0
        0x80 = 1.0
        0xFF = 1.9922
    Returns: None.
    Notes: [1]63
   ------------------------------------------------------------------- */
void VP_SetContrast (UB8 bContrast)
{
    BITEK_TxByte(BITEK_13B_CONTRAST, CONTRAST_OFFSET + CONTRAST_SLOPE * bContrast);
} // VP_SetContrast
#endif


#if (VP_SET_SATURATION)
/* -------------------------------------------------------------------
    Name: VP_SetSaturation -
    Purpose: This function sets the VP Saturation.
    Passed: 0x00..0x7F
    Returns: None.
    Notes: [1]63
   ------------------------------------------------------------------- */
void VP_SetSaturation (UB8 bSaturation)
{
    VP_SetColorKiller(bSaturation);

    #if 1
    bSaturation = SATURATION_OFFSET + SATURATION_SLOPE * bSaturation;
    #endif

    #if 0
    if (bSaturation < SATURATION_DEFAULT)
        bSaturation = SATURATION_OFFSET + SATURATION_SLOPE * bSaturation;
    else
        bSaturation = SATURATION_OFFSET2 + 3 * bSaturation / 2;
    #endif

    #if (VP_DEBUG)
    OSD_ShowValue(VP_SHOW_DEBUG_A, bSaturation, 100, ' ');
    #endif

    BITEK_TxByte(BITEK_13E_SAT_U, bSaturation);
    BITEK_TxByte(BITEK_13F_SAT_V, bSaturation);
} // VP_SetSaturation
#endif


#if (VP_SET_COLORKILLER)
/* -------------------------------------------------------------------
    Name: VP_SetColorKiller -
    Purpose: This function sets the COLOR KILLER.
    Passed: 0x00..0x7F
    Returns: None.
    Notes: [1]63
   ------------------------------------------------------------------- */
void VP_SetColorKiller (UB8 bSaturation)
{
    UB8 bColorKiller;


    bColorKiller = BITEK_RxByte(BITEK_140_KILL_COLOR_ATTR);

    if (bSaturation)
        // Color Killer OFF (0x140[1] = 0)
        bColorKiller &= ~BITEK_MASK_KILL_COLOR;
    else
        // Color Killer ON  (0x140[1] = 1)
        bColorKiller |= BITEK_MASK_KILL_COLOR;

    BITEK_TxByte(BITEK_140_KILL_COLOR_ATTR, bColorKiller);
} // VP_SetColorKiller
#endif


#if (VP_STD_DETECT)
/* -------------------------------------------------------------------
    Name: VP_STD_Detect -
    Purpose: To detect/show color standard.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void VP_STD_Detect (void)
{
    #define MSG_COLOR_STD_SIZE      10

    UB8 CODE * CODE apbCOLOR_STD[] =
    {
       //1234567890
        "       PAL",   // 0
        "     PAL-N",   // 1
        "     SECAM",   // 2
        "     PAL-M",   // 3
        "NTSC443 50",   // 4
        "    NTSC-M",   // 5
        "NTSC443 60",   // 6
        "BlackWhite",   // 7
        "    PAL-60",   // 8
        " No Signal",   // 9
        "      480i",   // 10
        "      576i",   // 11
        "      480p",   // 12
        "      576p",   // 13
    };


    UB8 bSTD;


    // H-LOCK (0x1E5[1]) = 1
    bSTD = BITEK_RxByte(BITEK_1E5_VD_INFO_O) & 0x0E;
    if (bSTD == 0x0E)
    {
        // VD STD mode
        bSTD = BITEK_RxByte(BITEK_1E6_STD_INFO_O) & 0x0F;
      //OSD_ShowHex(VP_SHOW_VD_STATUS + 6, bSTD);          // ROW5: Debug Only

        switch (bSTD)
        {
            case BITEK_MASK_STD_PAL_M:              // 3 + 8
            case BITEK_MASK_STD_NTSC_M:             // 5 + 8
            case BITEK_MASK_STD_NTSC443_60:         // 6 + 8
            case BITEK_MASK_STD_BLACK_WHITE60:      // 7 + 8
                bSTD -= 8;

            case BITEK_MASK_STD_PAL:                // 0
            case BITEK_MASK_STD_PAL_N:              // 1
            case BITEK_MASK_STD_SECAM:              // 2
            case BITEK_MASK_STD_NTSC443_50:         // 4
            case BITEK_MASK_STD_BLACK_WHITE50:      // 7
            case BITEK_MASK_STD_PAL_60:             // 8
            default:
                break;
        } // switch bSTD

    }
    else
        bSTD = 9;

    // Show Color Standard string
    BITEK_TxBurst(VP_SHOW_COLOR_STD, MSG_COLOR_STD_SIZE, apbCOLOR_STD[ bSTD ]);
    BITEK_TxByte(BITEK_10D_OSD0_ATTR2, OSD0_ON);

    bOSD_Cnt = OSD_AUTO_START;
} /* VP_STD_Detect */
#endif


#ifdef NOT_JUNK
/* -------------------------------------------------------------------
    Name: VP_ResetPLL -
    Purpose: To reset PLL.
    Passed: None.
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void VP_ResetPLL (void)
{
    UB8 bCnt;


    // Toggle PLL POR (0x0DD[0]) !
    // 0x0DD[0] = 1
    BITEK_TxByte(BITEK_0DD_PLL_ATTR, BITEK_RxByte(BITEK_0DD_PLL_ATTR) | 0x01);

    // Toggle DVP Clock Domain 2 Clock (0x00F[1]) !
    // 0x00F[1] = 1
  //BITEK_TxByte(BITEK_00F_CLK_ATTR5, BITEK_RxByte(BITEK_00F_CLK_ATTR5) | 0x02);

    for (bCnt = 255; bCnt; bCnt--)
        ;

    // 0x0DD[0] = 0
    BITEK_TxByte(BITEK_0DD_PLL_ATTR, BITEK_RxByte(BITEK_0DD_PLL_ATTR) & 0xFE);

    // 0x00F[1] = 0
  //BITEK_TxByte(BITEK_00F_CLK_ATTR5, BITEK_RxByte(BITEK_00F_CLK_ATTR5) & 0xFD);
}




#if (VP_SET_SHARPNESS)
/* -------------------------------------------------------------------
    Name: VP_SetSharpness -
    Purpose: To set Sharpness of VP.
    Passed:
    Returns:
    Notes: [1]67
   ------------------------------------------------------------------- */
void VP_SetSharpness (UB8 bSharpness)
{
    bSharpness = SHARPNESS_OFFSET + bSharpness;

    VP_TxByte(VP_MAD, VP_08A_SHARPNESS, bSharpness);
} /* VP_SetSharpness */
#endif



#if (VP_SET_TCON_MODE)
/* -------------------------------------------------------------------
    Name: VP_SetTCON_Mode -
    Purpose: To set the video processor TCON Mode.
    Passed:
        UB8 bTCON_Mode  TCON_MODE_RU    or
                        TCON_MODE_LU    or
                        TCON_MODE_LD    or
                        TCON_MODE_RD
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void VP_SetTCON_Mode (UB8 bTCON_Mode)
{
    #if (PROJECT == DMO012006200)    ||  \
        (PROJECT == DMO012007900)

    switch (bTCON_Mode)
    {
        case TCON_MODE_RU:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x20);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x44);
            break;

        case TCON_MODE_LU:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x00);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x46);
            break;

        case TCON_MODE_LD:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x10);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x47);
            break;

        case TCON_MODE_RD:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x30);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x45);
            break;
    } // switch

    #elif (PROJECT == DMO025000100)     ||  \
          (PROJECT == DMO025006500)     ||  \
          (PROJECT == DMO049000100)

    switch (bTCON_Mode)
    {
        case TCON_MODE_RU:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x0B);
            break;

        case TCON_MODE_LU:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x01);
            break;

        case TCON_MODE_LD:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x04);
            break;

        case TCON_MODE_RD:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x0E);
            break;
    } // switch

    #elif (PROJECT == DMO032006200)

    switch (bTCON_Mode)
    {
        case TCON_MODE_RU:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x20);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x44);
            break;

        case TCON_MODE_LU:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x00);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x46);
            break;

        case TCON_MODE_LD:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x10);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x47);
            break;

        case TCON_MODE_RD:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x30);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x45);
            break;
    } // switch

    #elif (PROJECT == DMO032006400)     ||  \
          (PROJECT == DMO032006401)     ||  \
          (PROJECT == DMO032006402)

    switch (bTCON_Mode)
    {
        case TCON_MODE_RU:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x20);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x44);
            break;

        case TCON_MODE_LU:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x00);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x46);
            break;

        case TCON_MODE_LD:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x10);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x47);
            break;

        case TCON_MODE_RD:
            VP_TxByte(VP_MAD, VP_00A_GPO_REG, 0x30);
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x45);
            break;
    } // switch

    #elif (PROJECT == DMO059000100)     ||  \
          (PROJECT == DMO059000101)     ||  \
          (PROJECT == DMO059000102)     ||  \
          (PROJECT == DMO069000100)     ||  \
          (PROJECT == DMO069000101)     ||  \
          (PROJECT == DMO069000102)     ||  \
          (PROJECT == DMO069000103)     ||  \
          (PROJECT == DMO069000104)     ||  \
          (PROJECT == DMO069000105)

    switch (bTCON_Mode)
    {
        case TCON_MODE_RU:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x0A);
            break;

        case TCON_MODE_LU:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x00);
            break;

        case TCON_MODE_LD:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x05);
            break;

        case TCON_MODE_RD:
            VP_TxByte(VP_MAD, VP_032_TCON_ATTR1, 0x0F);
            break;
    } // switch

    #else
        #error VP.C - Invalid PROJECT !
    #endif
} // VP_SetTCON_Mode
#endif


#if (VP_SET_TESTPATTERN)
/* -------------------------------------------------------------------
    Name: VP_SetTestPattern -
    Purpose: VP Background and Test Pattern.
    Passed:
    Returns: None
    Notes: [1]40
   ------------------------------------------------------------------- */
void VP_SetTestPattern (
UB8 bColorR,
UB8 bColorG,
UB8 bColorB,
UB8 bPatternType,   // Pattern Type
UB8 bMode           // Freerun/Background
)
{
    UB8     b42;


    b42 = VP_RxByte(VP_MAD, BITEK_042_TESTPAT_ATTR)                         &
          (VP_MASK_PATTERN_HV | VP_MASK_PATTERN_DIR | VP_MASK_PATTERN_TYPE);

    VP_TxByte(VP_MAD, BITEK_03F_R_ATTR, bColorR);
    VP_TxByte(VP_MAD, BITEK_040_G_ATTR, bColorG);
    VP_TxByte(VP_MAD, BITEK_041_B_ATTR, bColorB);

    VP_TxByte(VP_MAD, BITEK_042_TESTPAT_ATTR, b42 | bMode | bPatternType);
} /* VP_SetTestPattern */
#endif


#endif


#if (VP_SET_GAMMA_YUV)
/* -------------------------------------------------------------------
    Name: VP_SetGAMMA_YUV -
    Purpose:
    Passed:
    Returns: None.
    Notes:
   ------------------------------------------------------------------- */
void VP_SetGAMMA_YUV (void)
{
        UB8 CODE abGAMMA_Y00_7F[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/* 0 */ 0x00,0x01,0x01,0x02,0x03,0x03,0x04,0x04,0x05,0x06,0x06,0x07,0x08,0x08,0x09,0x0A,
/* 1 */ 0x0B,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x16,0x17,0x18,0x19,0x1B,
/* 2 */ 0x1C,0x1D,0x1F,0x20,0x21,0x23,0x24,0x26,0x27,0x29,0x2A,0x2B,0x2D,0x2E,0x30,0x31,
/* 3 */ 0x33,0x34,0x36,0x37,0x39,0x3A,0x3B,0x3D,0x3E,0x40,0x41,0x43,0x44,0x46,0x47,0x48,
/* 4 */ 0x4A,0x4B,0x4D,0x4E,0x4F,0x51,0x52,0x53,0x55,0x56,0x57,0x59,0x5A,0x5B,0x5C,0x5E,
/* 5 */ 0x5F,0x60,0x61,0x63,0x64,0x65,0x66,0x67,0x68,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70,
/* 6 */ 0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,0x80,
/* 7 */ 0x80,0x81,0x82,0x83,0x83,0x84,0x85,0x85,0x86,0x87,0x87,0x88,0x89,0x8A,0x8B,0x8B,
    };

        UB8 CODE abGAMMA_Y80_FF[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/* 8 */ 0x8C,0x8D,0x8D,0x8E,0x8F,0x8F,0x90,0x91,0x91,0x92,0x93,0x93,0x94,0x95,0x95,0x96,
/* 9 */ 0x97,0x97,0x98,0x99,0x9A,0x9A,0x9B,0x9C,0x9D,0x9D,0x9E,0x9F,0xA0,0xA1,0xA2,0xA2,
/* A */ 0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,0xB0,0xB1,
/* B */ 0xB2,0xB3,0xB4,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,0xC0,
/* C */ 0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCD,0xCF,0xCF,
/* D */ 0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
/* E */ 0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
/* F */ 0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFD,0xFE,
/* F */
    };

        UB8 CODE abGAMMA_U00_7F[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/* 0 */ 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
/* 1 */ 0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
/* 2 */ 0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
/* 3 */ 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
/* 4 */ 0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
/* 5 */ 0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
/* 6 */ 0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
/* 7 */ 0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
    };

        UB8 CODE abGAMMA_U80_FF[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/* 8 */ 0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
/* 9 */ 0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
/* A */ 0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
/* B */ 0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,
/* C */ 0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
/* D */ 0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
/* E */ 0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
/* F */ 0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,
    };


            UB8 CODE abGAMMA_V00_7F[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/* 0 */ 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
/* 1 */ 0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
/* 2 */ 0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,
/* 3 */ 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
/* 4 */ 0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
/* 5 */ 0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,
/* 6 */ 0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,
/* 7 */ 0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,
    };

        UB8 CODE abGAMMA_V80_FF[] = {
        // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
/* 8 */ 0x80,0x82,0x83,0x84,0x85,0x89,0x8A,0x8C,0x8D,0x8E,0x8F,0x90,0x92,0x93,0x94,0x95,
/* 9 */ 0x96,0x97,0x98,0x99,0x9A,0x9C,0x9D,0x9E,0x9F,0xA0,0xA1,0xA2,0xA3,0xA3,0xA4,0xA5,
/* A */ 0xA6,0xA7,0xA8,0xA9,0xA9,0xAA,0xAB,0xAC,0xAC,0xAD,0xAE,0xAF,0xAF,0xB0,0xB1,0xB2,
/* B */ 0xB2,0xB3,0xB4,0xB5,0xB6,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBE,0xBF,
/* C */ 0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,
/* D */ 0xD0,0xD1,0xD2,0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0xDA,0xDB,0xDC,0xDD,0xDE,0xDF,
/* E */ 0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF,
/* F */ 0xF0,0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,
    };

    // 0x138
    // 7 6 5 4 3 2 1 0
    // | | | | | | | |_ Contrast RGB mode: 0=Type, 1=Type2
    // | | | | | |_|___ Dither mode: 00=Disable, 01=RGB666, 10=RGB565, 11=RGB555
    // | | | | |_______ Gamma R/W mode: 0=RGB Gamma RAM, 1=YUV Gamma RAM
    // | | |_|_________ Gamma Select:
    // | |                  00=R if Gamma R/W mode=0
    // | |                  01=G if Gamma R/W mode=0
    // | |                  10=B if Gamma R/W mode=0
    // | |                  11=RGB Write only if Gamma R/W mode=0
    // | |                  00=Y if Gamma R/W mode=1
    // | |                  01=U if Gamma R/W mode=1
    // | |                  10=V if Gamma R/W mode=1
    // | |                  11=YUV Write only if Gamma R/W mode=1
    // | |_____________ Gamma YUV Enalbe: 0=Gamma R/W RAM mode if Gamma R/W mode=1
    // |_______________ Gamma RGB Enalbe: 0=Gamma R/W RAM mode if Gamma R/W mode=0
    // 0 0 0 0 1 0 0 0  0x08 For Gamma Y R/W mode
    // 0 0 0 1 1 0 0 0  0x18 For Gamma U R/W mode
    // 0 0 1 0 1 0 0 0  0x28 For Gamma V R/W mode
    // 0 1 1 0 1 0 0 0  0x68 For Gamma YUV enable
    // Setup Gamma Y
    BITEK_TxByte(BITEK_138_GAMMA_ATTR, 0x008);
    BITEK_TxBurst(BITEK_200_2FF_GAMMA + 0x00, sizeof(abGAMMA_Y00_7F), abGAMMA_Y00_7F);
    BITEK_TxBurst(BITEK_200_2FF_GAMMA + 0x80, sizeof(abGAMMA_Y80_FF), abGAMMA_Y80_FF);

    // Setup Gamma U
    BITEK_TxByte(BITEK_138_GAMMA_ATTR, 0x018);
    BITEK_TxBurst(BITEK_200_2FF_GAMMA + 0x00, sizeof(abGAMMA_U00_7F), abGAMMA_U00_7F);
    BITEK_TxBurst(BITEK_200_2FF_GAMMA + 0x80, sizeof(abGAMMA_U80_FF), abGAMMA_U80_FF);

    // Setup Gamma V
    BITEK_TxByte(BITEK_138_GAMMA_ATTR, 0x028);
    BITEK_TxBurst(BITEK_200_2FF_GAMMA + 0x00, sizeof(abGAMMA_V00_7F), abGAMMA_V00_7F);
    BITEK_TxBurst(BITEK_200_2FF_GAMMA + 0x80, sizeof(abGAMMA_V80_FF), abGAMMA_V80_FF);

    // Enable Gamma YUV
    BITEK_TxByte(BITEK_138_GAMMA_ATTR, 0x068);
} // VP_SetGAMMA
#endif



/* **********************************************************************

    Description:

   ********************************************************************** */

/* %% End Of File %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
