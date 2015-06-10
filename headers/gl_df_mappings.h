/* The Khronos Data Format Specification (provisional) - mappings for OpenGL */
/*
** Copyright (c) 2015 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/
#ifndef _VK_DATA_FORMAT_H_
#define _VK_DATA_FORMAT_H_

#include <stdint.h>
#include <khr_df.h>

/* Recall that the convention in GL is that the channel listed
   first in the name shall occupy the least significant bit. */

/* Note: I believe the difference between [US]SCALED and [US]INT has no place in the image format
   - this is entirely the choice of the shader in how to process the content, but the actual value stored is the same.
   However, whether the image contains premultiplied or straight alpha *is* a function of the image format
   (in that the content representation is different), and not recorded in the current VK format list.
   In this header, we treat [US]SCALED and [US]INT as synonymous, and arbitrarily define all formats as
   alpha-premultiplied, with the understanding that VK will have to override this in the current spec.
*/

#define GL_DF_BLOCKSIZE_1SAMPLE 40U
#define GL_DF_TOTALSIZE_1SAMPLE 44U
#define GL_DF_BLOCKSIZE_2SAMPLES 56U
#define GL_DF_TOTALSIZE_2SAMPLES 60U
#define GL_DF_BLOCKSIZE_3SAMPLES 72U
#define GL_DF_TOTALSIZE_3SAMPLES 76U
#define GL_DF_BLOCKSIZE_4SAMPLES 88U
#define GL_DF_TOTALSIZE_4SAMPLES 92U
#define GL_DF_BLOCKSIZE_6SAMPLES 120U
#define GL_DF_TOTALSIZE_6SAMPLES 124U

uint32_t df_GL_FMT_R8[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    1U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 1 byte */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_RED << 24U, /* Bits 0..7, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    255U /* upper_limit - normalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_R8_SNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    1U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 1 byte */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 8U << 16U | (KHR_DF_CHANNEL_RGBSDA_RED | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, /* Bits 0..7, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    ((uint32_t) -127), /* lower_limit */
    127U /* upper_limit - unnormalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_R16[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    2U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 2 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 16U << 16U | KHR_DF_CHANNEL_RGBSDA_RED << 24U, /* Bits 0..15, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    65535U /* upper_limit - normalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_R16_SNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    1U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 1 byte */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 16U << 16U | (KHR_DF_CHANNEL_RGBSDA_RED | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, /* Bits 0..7, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    ((uint32_t) -32767), /* lower_limit */
    32767U /* upper_limit - unnormalized integer representation of 1.0 */
};

















#define _GL_DF_SIMPLE_FORMAT_R(RED_BITS, NORM, SIGNED, FLOAT, SRGB, TOTALBYTES) \
    {                                                                   \
        GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */              \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            GL_DF_BLOCKSIZE_1SAMPLE << 16U,                             \
            KHR_DF_MODEL_RGBSDA |                                       \
            KHR_DF_PRIMARIES_SRGB << 8U |                               \
            (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U | \
            KHR_DF_FLAG_ALPHA_PREMULTIPLIED << 24U,                     \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            TOTALBYTES | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | RED_BITS << 16U |                                      \
            (KHR_DF_CHANNEL_RGBSDA_RED | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << RED_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (RED_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U) /* sample_upper */ \
        }

#define _GL_DF_SIMPLE_FORMAT_RG(RED_BITS, GREEN_BITS, NORM, SIGNED, FLOAT, SRGB, TOTALBYTES) \
    {                                                                   \
        GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            GL_DF_BLOCKSIZE_2SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            KHR_DF_PRIMARIES_SRGB << 8U |                               \
            (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U | \
            KHR_DF_FLAG_ALPHA_PREMULTIPLIED << 24U,                     \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            TOTALBYTES | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | RED_BITS << 16U |                                      \
            (KHR_DF_CHANNEL_RGBSDA_RED | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << RED_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 1.0f : NORM ? (1U << (RED_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            RED_BITS | GREEN_BITS << 16U |                              \
            (KHR_DF_CHANNEL_RGBSDA_GREEN | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << GREEN_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (GREEN_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U) /* sample_upper */ \
        }

#define _GL_DF_SIMPLE_FORMAT_RGB(RED_BITS, GREEN_BITS, BLUE_BITS, NORM, SIGNED, FLOAT, SRGB, TOTALBYTES) \
    {                                                                   \
        GL_DF_TOTALSIZE_3SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            GL_DF_BLOCKSIZE_3SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            KHR_DF_PRIMARIES_SRGB << 8U |                               \
            (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U | \
            KHR_DF_FLAG_ALPHA_PREMULTIPLIED << 24U,                     \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            TOTALBYTES | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | RED_BITS << 16U |                                      \
            (KHR_DF_CHANNEL_RGBSDA_RED | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << RED_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (RED_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            RED_BITS | GREEN_BITS << 16U |                              \
            (KHR_DF_CHANNEL_RGBSDA_GREEN | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << GREEN_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (GREEN_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            (RED_BITS + GREEN_BITS) | BLUE_BITS << 16U |            \
            (KHR_DF_CHANNEL_RGBSDA_BLUE | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Blue channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << BLUE_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (BLUE_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U) /* sample_upper */ \
            }

#define _GL_DF_SIMPLE_FORMAT_BGR(BLUE_BITS, GREEN_BITS, RED_BITS, NORM, SIGNED, FLOAT, SRGB, TOTALBYTES) \
    {                                                                   \
        GL_DF_TOTALSIZE_3SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            GL_DF_BLOCKSIZE_3SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            KHR_DF_PRIMARIES_SRGB << 8U |                               \
            (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U | \
            KHR_DF_FLAG_ALPHA_PREMULTIPLIED << 24U,                     \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            TOTALBYTES | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | BLUE_BITS << 16U |                                     \
            (KHR_DF_CHANNEL_RGBSDA_BLUE | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Blue channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << BLUE_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (BLUE_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            BLUE_BITS | GREEN_BITS << 16U |                              \
            (KHR_DF_CHANNEL_RGBSDA_GREEN | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << GREEN_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (GREEN_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            (BLUE_BITS + GREEN_BITS) | RED_BITS << 16U |                \
            (KHR_DF_CHANNEL_RGBSDA_RED | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << RED_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (RED_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U) /* sample_upper */ \
            }

#define _GL_DF_SIMPLE_FORMAT_RGBA(RED_BITS, GREEN_BITS, BLUE_BITS, ALPHA_BITS, NORM, SIGNED, FLOAT, SRGB, TOTALBYTES) \
    {                                                                   \
        GL_DF_TOTALSIZE_4SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            GL_DF_BLOCKSIZE_4SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            KHR_DF_PRIMARIES_SRGB << 8U |                               \
            (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U | \
            KHR_DF_FLAG_ALPHA_PREMULTIPLIED << 24U,                     \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            TOTALBYTES | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | RED_BITS << 16U |                                      \
            (KHR_DF_CHANNEL_RGBSDA_RED | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << RED_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (RED_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            RED_BITS | GREEN_BITS << 16U |                              \
            (KHR_DF_CHANNEL_RGBSDA_GREEN | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << GREEN_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (GREEN_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            (RED_BITS + GREEN_BITS) | BLUE_BITS << 16U |                \
            (KHR_DF_CHANNEL_RGBSDA_BLUE | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Blue channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << BLUE_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (BLUE_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            (RED_BITS + GREEN_BITS + BLUE_BITS) | ALPHA_BITS << 16U |   \
            (KHR_DF_CHANNEL_RGBSDA_ALPHA | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Alpha channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << ALPHA_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (ALPHA_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U) /* sample_upper */ \
            }

#define _GL_DF_SIMPLE_FORMAT_BGRA(BLUE_BITS, GREEN_BITS, RED_BITS, ALPHA_BITS, NORM, SIGNED, FLOAT, SRGB, TOTALBYTES) \
    {                                                                   \
        GL_DF_TOTALSIZE_4SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            GL_DF_BLOCKSIZE_4SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            KHR_DF_PRIMARIES_SRGB << 8U |                               \
            (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U | \
            KHR_DF_FLAG_ALPHA_PREMULTIPLIED << 24U,                     \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            TOTALBYTES | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | BLUE_BITS << 16U |                                     \
            (KHR_DF_CHANNEL_RGBSDA_BLUE | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Blue channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << BLUE_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (BLUE_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            BLUE_BITS | GREEN_BITS << 16U |                              \
            (KHR_DF_CHANNEL_RGBSDA_GREEN | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << GREEN_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (GREEN_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            (BLUE_BITS + GREEN_BITS) | RED_BITS << 16U |                \
            (KHR_DF_CHANNEL_RGBSDA_RED | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << RED_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (RED_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U), /* sample_upper */ \
            (RED_BITS + GREEN_BITS + BLUE_BITS) | ALPHA_BITS << 16U |   \
            (KHR_DF_CHANNEL_RGBSDA_ALPHA | (SIGNED?KHR_DF_SAMPLE_DATATYPE_SIGNED:0) | (FLOAT?KHR_DF_SAMPLE_DATATYPE_FLOAT:0)) << 24U, /* Alpha channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            (FLOAT ? (SIGNED ? 0xbf800000U : 0U) : NORM ? (SIGNED ? (1U << ALPHA_BITS) - 1U : 0U) : (SIGNED ? ((uint32_t) -1) : 0U)), /* sample_lower */ \
            (FLOAT ? 0x3f800000U : NORM ? (1U << (ALPHA_BITS - (SIGNED ? 1U : 0U))) - 1U : 1U) /* sample_upper */ \
            }

/* RED [, GREEN [, BLUE [, ALPHA]]],  NORMALIZED, SIGNED, FLOAT, SRGB, TOTALBYTES */
uint32_t df_GL_FMT_R4G4_UNORM[] = _GL_DF_SIMPLE_FORMAT_RG(4U, 4U,                        1U, 0U, 0U, 0U, 1U);
uint32_t df_GL_FMT_R4G4_USCALED[] = _GL_DF_SIMPLE_FORMAT_RG(4U, 4U,                      0U, 0U, 0U, 0U, 1U);
uint32_t df_GL_FMT_R4G4B4A4_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(4U, 4U, 4U, 4U,          1U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R4G4B4A4_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(4U, 4U, 4U, 4U,        0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R5G6B5_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGB(5U, 6U, 5U,                 1U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R5G6B5_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGB(5U, 6U, 5U,               0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R5G5B5A1_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(5U, 5U, 5U, 1U,          1U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R5G5B5A1_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(5U, 5U, 5U, 1U,        0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R8_UNORM[] = _GL_DF_SIMPLE_FORMAT_R(8U,                               1U, 0U, 0U, 0U, 1U);
uint32_t df_GL_FMT_R8_SNORM[] = _GL_DF_SIMPLE_FORMAT_R(8U,                               1U, 1U, 0U, 0U, 1U);
uint32_t df_GL_FMT_R8_USCALED[] = _GL_DF_SIMPLE_FORMAT_R(8U,                             0U, 0U, 0U, 0U, 1U);
uint32_t df_GL_FMT_R8_SSCALED[] = _GL_DF_SIMPLE_FORMAT_R(8U,                             0U, 1U, 0U, 0U, 1U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R8_UINT[] = _GL_DF_SIMPLE_FORMAT_R(8U,                                0U, 0U, 0U, 0U, 1U);
uint32_t df_GL_FMT_R8_SINT[] = _GL_DF_SIMPLE_FORMAT_R(8U,                                0U, 1U, 0U, 0U, 1U);

uint32_t df_GL_FMT_R8_SRGB[] = _GL_DF_SIMPLE_FORMAT_R(8U,                                1U, 0U, 0U, 1U, 1U);
uint32_t df_GL_FMT_R8G8_UNORM[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                        1U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R8G8_SNORM[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                        1U, 1U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R8G8_USCALED[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                      0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R8G8_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                      0U, 1U, 0U, 0U, 2U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R8G8_UINT[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                         0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R8G8_SINT[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                         0U, 1U, 0U, 0U, 2U);

uint32_t df_GL_FMT_R8G8_SRGB[] = _GL_DF_SIMPLE_FORMAT_RG(8U, 8U,                         1U, 0U, 0U, 1U, 2U);
uint32_t df_GL_FMT_R8G8B8_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,                 1U, 0U, 0U, 0U, 3U);
uint32_t df_GL_FMT_R8G8B8_SNORM[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,                 1U, 1U, 0U, 0U, 3U);
uint32_t df_GL_FMT_R8G8B8_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,               0U, 0U, 0U, 0U, 3U);
uint32_t df_GL_FMT_R8G8B8_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,               0U, 1U, 0U, 0U, 3U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R8G8B8_UINT[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,                  0U, 0U, 0U, 0U, 3U);
uint32_t df_GL_FMT_R8G8B8_SINT[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,                  0U, 1U, 0U, 0U, 3U);

uint32_t df_GL_FMT_R8G8B8_SRGB[] = _GL_DF_SIMPLE_FORMAT_RGB(8U, 8U, 8U,                  1U, 0U, 0U, 1U, 3U);
uint32_t df_GL_FMT_R8G8B8A8_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,          1U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R8G8B8A8_SNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,          1U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R8G8B8A8_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,        0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R8G8B8A8_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,        0U, 1U, 0U, 0U, 4U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R8G8B8A8_UINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,           0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R8G8B8A8_SINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,           0U, 1U, 0U, 0U, 4U);

uint32_t df_GL_FMT_R8G8B8A8_SRGB[] = _GL_DF_SIMPLE_FORMAT_RGBA(8U, 8U, 8U, 8U,           1U, 0U, 0U, 1U, 4U);
uint32_t df_GL_FMT_R10G10B10A2_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(10U, 10U, 10U, 2U,    1U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R10G10B10A2_SNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(10U, 10U, 10U, 2U,    1U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R10G10B10A2_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(10U, 10U, 10U, 2U,  0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R10G10B10A2_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(10U, 10U, 10U, 2U,  0U, 1U, 0U, 0U, 4U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R10G10B10A2_UINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(10U, 10U, 10U, 2U,     0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R10G10B10A2_SINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(10U, 10U, 10U, 2U,     0U, 1U, 0U, 0U, 4U);

uint32_t df_GL_FMT_R16_UNORM[] = _GL_DF_SIMPLE_FORMAT_R(16U,                             1U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R16_SNORM[] = _GL_DF_SIMPLE_FORMAT_R(16U,                             1U, 1U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R16_USCALED[] = _GL_DF_SIMPLE_FORMAT_R(16U,                           0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R16_SSCALED[] = _GL_DF_SIMPLE_FORMAT_R(16U,                           0U, 1U, 0U, 0U, 2U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R16_UINT[] = _GL_DF_SIMPLE_FORMAT_R(16U,                              0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_R16_SINT[] = _GL_DF_SIMPLE_FORMAT_R(16U,                              0U, 1U, 0U, 0U, 2U);

uint32_t df_GL_FMT_R16_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_R(16U,                            0U, 1U, 1U, 0U, 2U);
uint32_t df_GL_FMT_R16G16_UNORM[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                    1U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R16G16_SNORM[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                    1U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R16G16_USCALED[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                  0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R16G16_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                  0U, 1U, 0U, 0U, 4U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R16G16_UINT[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                     0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R16G16_SINT[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                     0U, 1U, 0U, 0U, 4U);

uint32_t df_GL_FMT_R16G16_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RG(16U, 16U,                   0U, 1U, 1U, 0U, 4U);
uint32_t df_GL_FMT_R16G16B16_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,           1U, 0U, 0U, 0U, 6U);
uint32_t df_GL_FMT_R16G16B16_SNORM[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,           1U, 1U, 0U, 0U, 6U);
uint32_t df_GL_FMT_R16G16B16_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,         0U, 0U, 0U, 0U, 6U);
uint32_t df_GL_FMT_R16G16B16_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,         0U, 1U, 0U, 0U, 6U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R16G16B16_UINT[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,                  0U, 0U, 0U, 0U, 6U);
uint32_t df_GL_FMT_R16G16B16_SINT[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,                  0U, 1U, 0U, 0U, 6U);

uint32_t df_GL_FMT_R16G16B16_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGB(16U, 16U, 16U,                0U, 1U, 1U, 0U, 8U);
uint32_t df_GL_FMT_R16G16B16A16_UNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,        1U, 0U, 0U, 0U, 8U);
uint32_t df_GL_FMT_R16G16B16A16_SNORM[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,        1U, 1U, 0U, 0U, 8U);
uint32_t df_GL_FMT_R16G16B16A16_USCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,      0U, 0U, 0U, 0U, 8U);
uint32_t df_GL_FMT_R16G16B16A16_SSCALED[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,      0U, 1U, 0U, 0U, 8U);

/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_R16G16B16A16_UINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,         0U, 0U, 0U, 0U, 8U);
uint32_t df_GL_FMT_R16G16B16A16_SINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,         0U, 1U, 0U, 0U, 8U);

uint32_t df_GL_FMT_R16G16B16A16_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGBA(16U, 16U, 16U, 16U,       0U, 1U, 1U, 0U, 8U);
uint32_t df_GL_FMT_R32_UINT[] = _GL_DF_SIMPLE_FORMAT_R(32U,                                    0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R32_SINT[] = _GL_DF_SIMPLE_FORMAT_R(32U,                                    0U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_R32_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_R(32U,                                  0U, 1U, 1U, 0U, 4U);
uint32_t df_GL_FMT_R32G32_UINT[] = _GL_DF_SIMPLE_FORMAT_RG(32U, 32U,                           0U, 0U, 0U, 0U, 8U);
uint32_t df_GL_FMT_R32G32_SINT[] = _GL_DF_SIMPLE_FORMAT_RG(32U, 32U,                           0U, 1U, 0U, 0U, 8U);
uint32_t df_GL_FMT_R32G32_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RG(32U, 32U,                         0U, 1U, 1U, 0U, 8U);
uint32_t df_GL_FMT_R32G32B32_UINT[] = _GL_DF_SIMPLE_FORMAT_RGB(32U, 32U, 32U,                  0U, 0U, 0U, 0U, 12U);
uint32_t df_GL_FMT_R32G32B32_SINT[] = _GL_DF_SIMPLE_FORMAT_RGB(32U, 32U, 32U,                  0U, 1U, 0U, 0U, 12U);
uint32_t df_GL_FMT_R32G32B32_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGB(32U, 32U, 32U,                0U, 1U, 1U, 0U, 12U);
uint32_t df_GL_FMT_R32G32B32A32_UINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(32U, 32U, 32U, 32U,         0U, 0U, 0U, 0U, 16U);
uint32_t df_GL_FMT_R32G32B32A32_SINT[] = _GL_DF_SIMPLE_FORMAT_RGBA(32U, 32U, 32U, 32U,         0U, 1U, 0U, 0U, 16U);
uint32_t df_GL_FMT_R32G32B32A32_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGBA(32U, 32U, 32U, 32U,       0U, 1U, 1U, 0U, 16U);
/* N.B. 64-bit float formats rely on promotion to specify sample_lower and sample_upper */
uint32_t df_GL_FMT_R64_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_R(64U,                                  0U, 1U, 1U, 0U, 8U);
uint32_t df_GL_FMT_R64G64_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RG(64U, 64U,                         0U, 1U, 1U, 0U, 16U);
uint32_t df_GL_FMT_R64G64B64_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGB(64U, 64U, 64U,                0U, 1U, 1U, 0U, 24U);
uint32_t df_GL_FMT_R64G64B64A64_SFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGBA(64U, 64U, 64U, 64U,       0U, 1U, 1U, 0U, 32U);

uint32_t df_GL_FMT_R11G11B10_UFLOAT[] = _GL_DF_SIMPLE_FORMAT_RGB(11U, 11U, 10U,                0U, 0U, 1U, 0U, 4U);

/* Now for formats that do not conveniently map into a macro */
/* Confirm the bit ordering for this */
uint32_t df_GL_FMT_R9G9B9E5_UFLOAT[] = {
    GL_DF_TOTALSIZE_6SAMPLES, /* Total size in bytes */
    KHR_DF_VENDORID_KHRONOS |
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_6SAMPLES << 16U, /* Format block size in bytes */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 4 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 9U << 16U | KHR_DF_CHANNEL_RGBSDA_RED << 24U, /* Bits 0..8, red channel unsigned mantissa */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U << 8U, /* upper_limit - integer representation of the mantissa at 1.0 */
    27U | 5U << 16U | (KHR_DF_CHANNEL_RGBSDA_RED | KHR_DF_SAMPLE_DATATYPE_EXPONENT) << 24U, /* Unsigned exponent (red) */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* Any exponent is possible to encode 0, but we will assume 0 is canonical */
    15U, /* upper_limit - exponent bias */
    9U | 9U << 16U | KHR_DF_CHANNEL_RGBSDA_GREEN << 24U, /* Bits 9..17, green channel unsigned mantissa */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U << 8U, /* upper_limit - integer representation of the mantissa at 1.0 */
    27U | 5U << 16U | (KHR_DF_CHANNEL_RGBSDA_GREEN | KHR_DF_SAMPLE_DATATYPE_EXPONENT) << 24U, /* Unsigned exponent (green) */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* Any exponent is possible to encode 0, but we will assume 0 is canonical */
    15U, /* upper_limit - exponent bias */
    18U | 9U << 16U | KHR_DF_CHANNEL_RGBSDA_BLUE << 24U, /* Bits 0..8, blue channel unsigned mantissa */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U << 8U, /* upper_limit - integer representation of the mantissa at 1.0 */
    27U | 5U << 16U | (KHR_DF_CHANNEL_RGBSDA_BLUE | KHR_DF_SAMPLE_DATATYPE_EXPONENT) << 24U, /* Unsigned exponent (blue) */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* Any exponent is possible to encode 0, but we will assume 0 is canonical */
    15U /* upper_limit - exponent bias */
};

uint32_t df_GL_FMT_D16_UNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    2U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 2 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 16U << 16U | KHR_DF_CHANNEL_RGBSDA_DEPTH << 24U, /* Bits 0..15, unsigned depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFFF /* upper_limit - normalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_D24_UNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    3U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 3 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 24U << 16U | KHR_DF_CHANNEL_RGBSDA_DEPTH << 24U, /* Bits 0..23, unsigned depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFFFFFU /* upper_limit - normalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_D32_SFLOAT[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 4 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 32U << 16U | (KHR_DF_SAMPLE_DATATYPE_FLOAT | KHR_DF_CHANNEL_RGBSDA_DEPTH) << 24U, /* Bits 0..31, signed float depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0xbf800000U, /* lower_limit - IEEE754 -1.0 */
    0x3f800000U /* upper_limit - IEEE754 1.0 */
};

uint32_t df_GL_FMT_S8_UINT[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    1U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 1 byte */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 0..7, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

#ifdef _GL_DATA_FORMAT_DS_PLANAR

uint32_t df_GL_FMT_D16_UNORM_S8_UINT[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    2U | 1U << 8U | 0U << 16U | 0U << 24U, /* Two planes of 2 and 1 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 16U << 16U | KHR_DF_CHANNEL_RGBSDA_DEPTH << 24U, /* Bits 0..15, unsigned depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFFFU /* upper_limit - normalized integer representation of 1.0 */
    16U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 16..23, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_D24_UNORM_S8_UINT[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    3U | 1U << 8U | 0U << 16U | 0U << 24U, /* Two planes of 3 and 1 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 24U << 16U | KHR_DF_CHANNEL_RGBSDA_DEPTH << 24U, /* Bits 0..23, unsigned depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFFFFFU /* upper_limit - normalized integer representation of 1.0 */
    24U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 24..31, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_D32_SFLOAT_S8_UINT[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    4U | 1U << 8U | 0U << 16U | 0U << 24U, /* Two planes of 4 and 1 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 32U << 16U | (KHR_DF_SAMPLE_DATATYPE_FLOAT | KHR_DF_CHANNEL_RGBSDA_DEPTH) << 24U, /* Bits 0..31, signed float depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0xbf800000U, /* lower_limit - IEEE754 -1.0 */
    0x3f800000U /* upper_limit - IEEE754 1.0 */
    32U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 24..31, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

#else /* _GL_DATA_FORMAT_DS_PLANAR */

uint32_t df_GL_FMT_D16_UNORM_S8_UINT[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    3U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 3 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 16U << 16U | KHR_DF_CHANNEL_RGBSDA_DEPTH << 24U, /* Bits 0..15, unsigned depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFFFU, /* upper_limit - normalized integer representation of 1.0 */
    16U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 16..23, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_D24_UNORM_S8_UINT[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane 4 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 24U << 16U | KHR_DF_CHANNEL_RGBSDA_DEPTH << 24U, /* Bits 0..23, unsigned depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFFFFFU, /* upper_limit - normalized integer representation of 1.0 */
    24U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 24..31, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

uint32_t df_GL_FMT_D32_SFLOAT_S8_UINT[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_RGBSDA |
    KHR_DF_PRIMARIES_SRGB << 8U | /* Irrelevant */
    KHR_DF_TRANSFER_LINEAR << 16U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */
    5U | 0U << 8U | 0U << 16U | 0U << 24U, /* One planes of 5 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 32U << 16U | (KHR_DF_SAMPLE_DATATYPE_FLOAT | KHR_DF_CHANNEL_RGBSDA_DEPTH) << 24U, /* Bits 0..31, signed float depth channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0xbf800000U, /* lower_limit - IEEE754 -1.0 */
    0x3f800000U, /* upper_limit - IEEE754 1.0 */
    32U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_STENCIL << 24U, /* Bits 24..31, unsigned stencil channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    1U /* upper_limit - unnormalized integer representation of 1.0 */
};

#endif /* _GL_DATA_FORMAT_DS_PLANAR */

uint32_t df_GL_FMT_BC1_RGB_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC1A |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_DXT1A_COLOR << 24U, /* Bits 0..63, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC1_RGB_SRGB[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC1A |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_DXT1A_COLOR << 24U, /* Bits 0..63, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC1_RGBA_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC1A |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | 0U << 24U, /* Bits 0..63, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | KHR_DF_CHANNEL_DXT1A_COLOR << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    0U | 64U << 16U | KHR_DF_CHANNEL_DXT1A_ALPHAPRESENT << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC1_RGBA_SRGB[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC1A |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_DXT1A_COLOR << 24U, /* Bits 0..63, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    0U | 64U << 16U | KHR_DF_CHANNEL_DXT1A_ALPHAPRESENT << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC2_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_BC2_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_BC2_COLOR << 24U, /* Bits 64..127, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC2_SRGB[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_BC2_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_BC2_COLOR << 24U, /* Bits 64..127, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC3_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC3 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_BC3_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_BC3_COLOR << 24U, /* Bits 64..127, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC3_SRGB[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC3 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_BC3_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_BC3_COLOR << 24U, /* Bits 64..127, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC4_UNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC4 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_BC4_DATA << 24U, /* Bits 0..63, unsigned color+alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC4_SNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC4 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | /* Bits 0..63, signed color+alpha channel */
    (KHR_DF_CHANNEL_BC4_DATA | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    (uint32_t) INT32_MIN, /* lower_limit */
    (uint32_t) INT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC5_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC5 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_BC5_RED << 24U, /* Bits 0..63, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_BC5_GREEN << 24U, /* Bits 64..127, unsigned green channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC5_SNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_BC5 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | /* Bits 0..63, signed red channel */
    (KHR_DF_CHANNEL_BC5_RED | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    (uint32_t) INT32_MIN, /* lower_limit */
    (uint32_t) INT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | /* Bits 64..127, signed green channel */
    (KHR_DF_CHANNEL_BC5_GREEN | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    (uint32_t) INT32_MIN, /* lower_limit */
    (uint32_t) INT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC6H_UFLOAT[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC6H |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 128U << 16U | /* Bits 0..127, unsigned color+alpha channel */
    (KHR_DF_CHANNEL_BC6H_COLOR | KHR_DF_SAMPLE_DATATYPE_FLOAT) << 24U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0x3f800000U /* upper_limit - IEEE754 1.0 */
};

uint32_t df_GL_FMT_BC6H_SFLOAT[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC6H |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 128U << 16U | /* Bits 0..127, signed color+alpha channel */
    (KHR_DF_CHANNEL_BC6H_COLOR | KHR_DF_SAMPLE_DATATYPE_FLOAT | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U,
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0xbf800000U, /* lower_limit - IEEE754 -1.0 */
    0x3f800000U /* upper_limit - IEEE754 1.0 */
};

uint32_t df_GL_FMT_BC7_UNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC7 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 128U << 16U | KHR_DF_CHANNEL_BC7_DATA << 24U, /* Bits 0..127, unsigned color+alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_BC7_SRGB[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_BC7 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 128U << 16U | KHR_DF_CHANNEL_BC7_DATA << 24U, /* Bits 0..127, unsigned color+alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_ETC2_R8G8B8_UNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_COLOR << 24U, /* Bits 0..63, unsigned RGB channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_ETC2_R8G8B8_SRGB[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_COLOR << 24U, /* Bits 0..63, unsigned RGB channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_ETC2_R8G8B8A1_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_COLOR << 24U, /* Bits 0..63, unsigned RGB channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFU, /* upper_limit - normalized integer (unnormalized is "1") */
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_ETC2_R8G8B8A1_SRGB[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_COLOR << 24U, /* Bits 0..63, unsigned RGB channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFU, /* upper_limit - normalized integer (unnormalized is "1") */
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_ETC2_R8G8B8A8_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFU, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_ETC2_COLOR << 24U, /* Bits 0..63, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_ETC2_R8G8B8A8_SRGB[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_SRGB << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_ALPHA << 24U, /* Bits 0..63, unsigned alpha channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    0xFFU, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_ETC2_COLOR << 24U, /* Bits 0..63, unsigned color channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_EAC_R11_UNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_RED << 24U, /* Bits 0..63, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_EAC_R11_SNORM[] = {
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    8U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 8 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | (KHR_DF_CHANNEL_ETC2_RED | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, /* Bits 0..63, signed red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    (uint32_t) INT32_MIN, /* lower_limit */
    (uint32_t) INT32_MAX  /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_EAC_R11G11_UNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | KHR_DF_CHANNEL_ETC2_RED << 24U, /* Bits 0..63, unsigned red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | KHR_DF_CHANNEL_ETC2_GREEN << 24U, /* Bits 64..127, unsigned green channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    0U, /* lower_limit */
    UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

uint32_t df_GL_FMT_EAC_R11G11_SNORM[] = {
    GL_DF_TOTALSIZE_2SAMPLES, /* Total size in bytes */
    KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,
    0U /* Version number */ |
    GL_DF_BLOCKSIZE_2SAMPLES << 16U, /* Format block size in bytes (2 samples) */
    KHR_DF_MODEL_ETC2 |
    KHR_DF_PRIMARIES_SRGB << 8U |
    KHR_DF_TRANSFER_LINEAR << 16U,
    3U | 3U << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */
    16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */
    0U | 0U << 8U | 0U << 16U | 0U << 24U,
    0U | 64U << 16U | (KHR_DF_CHANNEL_ETC2_RED | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, /* Bits 0..63, signed red channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    (uint32_t) INT32_MIN, /* lower_limit */
    (uint32_t) INT32_MAX, /* upper_limit - normalized integer (unnormalized is "1") */
    64U | 64U << 16U | (KHR_DF_CHANNEL_ETC2_GREEN | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, /* Bits 64..127, signed green channel */
    0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */
    (uint32_t) INT32_MIN, /* lower_limit */
    (uint32_t) INT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */
};

#define _df_GL_DF_ASTC_FORMAT(WIDTH, HEIGHT, SRGB) \
    { \
    GL_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */ \
        KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U, \
        0U /* Version number */ | \
        GL_DF_BLOCKSIZE_1SAMPLE << 16U, /* Format block size in bytes (1 sample) */ \
        KHR_DF_MODEL_ASTC | \
        KHR_DF_PRIMARIES_SRGB << 8U | \
        (SRGB ? KHR_DF_TRANSFER_SRGB : KHR_DF_TRANSFER_LINEAR) << 16U,      \
        (WIDTH - 1U) | (HEIGHT - 1U) << 8U | 0U << 16U | 0U << 24U, /* 4x4x1x1 texel block */ \
        16U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane of 16 bytes */ \
        0U | 0U << 8U | 0U << 16U | 0U << 24U, \
        0U | 128U << 16U | KHR_DF_CHANNEL_ASTC_DATA << 24U, /* Bits 0..127, ASTC channel */ \
        0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
        0U, /* lower_limit */ \
        UINT32_MAX /* upper_limit - normalized integer (unnormalized is "1") */ \
    }

uint32_t df_GL_FMT_ASTC_4x4_UNORM[] = _df_GL_DF_ASTC_FORMAT(4,4,0);
uint32_t df_GL_FMT_ASTC_4x4_SRGB[] = _df_GL_DF_ASTC_FORMAT(4,4,1);
uint32_t df_GL_FMT_ASTC_5x4_UNORM[] = _df_GL_DF_ASTC_FORMAT(5,4,0);
uint32_t df_GL_FMT_ASTC_5x4_SRGB[] = _df_GL_DF_ASTC_FORMAT(5,4,1);
uint32_t df_GL_FMT_ASTC_5x5_UNORM[] = _df_GL_DF_ASTC_FORMAT(5,5,0);
uint32_t df_GL_FMT_ASTC_5x5_SRGB[] = _df_GL_DF_ASTC_FORMAT(5,5,1);
uint32_t df_GL_FMT_ASTC_6x5_UNORM[] = _df_GL_DF_ASTC_FORMAT(6,5,0);
uint32_t df_GL_FMT_ASTC_6x5_SRGB[] = _df_GL_DF_ASTC_FORMAT(6,5,1);
uint32_t df_GL_FMT_ASTC_6x6_UNORM[] = _df_GL_DF_ASTC_FORMAT(6,6,0);
uint32_t df_GL_FMT_ASTC_6x6_SRGB[] = _df_GL_DF_ASTC_FORMAT(6,6,1);
uint32_t df_GL_FMT_ASTC_8x5_UNORM[] = _df_GL_DF_ASTC_FORMAT(8,5,0);
uint32_t df_GL_FMT_ASTC_8x5_SRGB[] = _df_GL_DF_ASTC_FORMAT(8,5,1);
uint32_t df_GL_FMT_ASTC_8x6_UNORM[] = _df_GL_DF_ASTC_FORMAT(8,6,0);
uint32_t df_GL_FMT_ASTC_8x6_SRGB[] = _df_GL_DF_ASTC_FORMAT(8,6,1);
uint32_t df_GL_FMT_ASTC_8x8_UNORM[] = _df_GL_DF_ASTC_FORMAT(8,8,0);
uint32_t df_GL_FMT_ASTC_8x8_SRGB[] = _df_GL_DF_ASTC_FORMAT(8,8,1);
uint32_t df_GL_FMT_ASTC_10x5_UNORM[] = _df_GL_DF_ASTC_FORMAT(10,5,0);
uint32_t df_GL_FMT_ASTC_10x5_SRGB[] = _df_GL_DF_ASTC_FORMAT(10,5,1);
uint32_t df_GL_FMT_ASTC_10x6_UNORM[] = _df_GL_DF_ASTC_FORMAT(10,6,0);
uint32_t df_GL_FMT_ASTC_10x6_SRGB[] = _df_GL_DF_ASTC_FORMAT(10,6,1);
uint32_t df_GL_FMT_ASTC_10x8_UNORM[] = _df_GL_DF_ASTC_FORMAT(10,8,0);
uint32_t df_GL_FMT_ASTC_10x8_SRGB[] = _df_GL_DF_ASTC_FORMAT(10,8,1);
uint32_t df_GL_FMT_ASTC_10x10_UNORM[] = _df_GL_DF_ASTC_FORMAT(10,10,0);
uint32_t df_GL_FMT_ASTC_10x10_SRGB[] = _df_GL_DF_ASTC_FORMAT(10,10,1);
uint32_t df_GL_FMT_ASTC_12x10_UNORM[] = _df_GL_DF_ASTC_FORMAT(12,10,0);
uint32_t df_GL_FMT_ASTC_12x10_SRGB[] = _df_GL_DF_ASTC_FORMAT(12,10,1);
uint32_t df_GL_FMT_ASTC_12x12_UNORM[] = _df_GL_DF_ASTC_FORMAT(12,12,0);
uint32_t df_GL_FMT_ASTC_12x12_SRGB[] = _df_GL_DF_ASTC_FORMAT(12,12,1);

/* "Reversed" formats (blue in the least-significant bit) */
uint32_t df_GL_FMT_B4G4R4A4_UNORM[] = _GL_DF_SIMPLE_FORMAT_BGRA(4U, 4U, 4U, 4U,          1U, 0U, 0U, 0U, 2U);
/* Is there a reason that this exists in RGB but not in BGR? */
uint32_t df_GL_FMT_B4G4R4A4_USCALED[] = _GL_DF_SIMPLE_FORMAT_BGRA(4U, 4U, 4U, 4U,        0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_B5G5R5A1_UNORM[] = _GL_DF_SIMPLE_FORMAT_BGRA(5U, 5U, 5U, 1U,          1U, 0U, 0U, 0U, 2U);
/* Is there a reason that this exists in RGB but not in BGR? */
uint32_t df_GL_FMT_B5G5R5A1_USCALED[] = _GL_DF_SIMPLE_FORMAT_BGRA(5U, 5U, 5U, 1U,        0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_B5G6R5_UNORM[] = _GL_DF_SIMPLE_FORMAT_BGR(5U, 6U, 5U,                 1U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_B5G6R5_USCALED[] = _GL_DF_SIMPLE_FORMAT_BGR(5U, 6U, 5U,               0U, 0U, 0U, 0U, 2U);
uint32_t df_GL_FMT_B8G8R8_UNORM[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,                 1U, 0U, 0U, 0U, 3U);
uint32_t df_GL_FMT_B8G8R8_SNORM[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,                 1U, 1U, 0U, 0U, 3U);
uint32_t df_GL_FMT_B8G8R8_USCALED[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,               0U, 0U, 0U, 0U, 3U);
uint32_t df_GL_FMT_B8G8R8_SSCALED[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,               0U, 1U, 0U, 0U, 3U);
/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_B8G8R8_UINT[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,                  0U, 0U, 0U, 0U, 3U);
uint32_t df_GL_FMT_B8G8R8_SINT[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,                  0U, 1U, 0U, 0U, 3U);
uint32_t df_GL_FMT_B8G8R8_SRGB[] = _GL_DF_SIMPLE_FORMAT_BGR(8U, 8U, 8U,                  1U, 0U, 0U, 1U, 3U);
uint32_t df_GL_FMT_B8G8R8A8_UNORM[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,          1U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B8G8R8A8_SNORM[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,          1U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B8G8R8A8_USCALED[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,        0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B8G8R8A8_SSCALED[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,        0U, 1U, 0U, 0U, 4U);
/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_B8G8R8A8_UINT[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,           0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B8G8R8A8_SINT[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,           0U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B8G8R8A8_SRGB[] = _GL_DF_SIMPLE_FORMAT_BGRA(8U, 8U, 8U, 8U,           1U, 0U, 0U, 1U, 4U);
uint32_t df_GL_FMT_B10G10R10A2_UNORM[] = _GL_DF_SIMPLE_FORMAT_BGRA(2U, 10U, 10U, 10U,    1U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B10G10R10A2_SNORM[] = _GL_DF_SIMPLE_FORMAT_BGRA(2U, 10U, 10U, 10U,    1U, 1U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B10G10R10A2_USCALED[] = _GL_DF_SIMPLE_FORMAT_BGRA(10U, 10U, 10U, 2U,  0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B10G10R10A2_SSCALED[] = _GL_DF_SIMPLE_FORMAT_BGRA(10U, 10U, 10U, 2U,  0U, 1U, 0U, 0U, 4U);
/* INT and SCALED have identical in-memory representations of content, and do not differ in format */
uint32_t df_GL_FMT_B10G10R10A2_UINT[] = _GL_DF_SIMPLE_FORMAT_BGRA(10U, 10U, 10U, 2U,     0U, 0U, 0U, 0U, 4U);
uint32_t df_GL_FMT_B10G10R10A2_SINT[] = _GL_DF_SIMPLE_FORMAT_BGRA(10U, 10U, 10U, 2U,     0U, 1U, 0U, 0U, 4U);

/* This distinction affects the use of the data but not the format in memory */
enum df_GL_INT_VS_SCALED_e {
    DF_GL_INT, /* Data is interpreted as an integer value */
    DF_GL_SCALED /* Data is interpreted as a floating point representation of the integer value */
    /* Note that we use "scaled" for floating point values despite there being no "scaling". */
};

typedef struct _df_vk_format_list_entry {
    uint32_t *format_block;
    enum df_GL_INT_VS_SCALED_e intOrScaled; /* API-specific information */
} df_vk_format_list_entry;

/* Note: Implementation may wish to define this list to be expandable for user formats.
   The following array assumes the enumeration order provided in the OpenGL 4.5 core profile document at the time of writing.
   Some additional commented-out formats were defined in the format query spreadsheet. */
df_vk_format_list_entry vkDFDefaultList[] = {
    { (uint32_t *)0, DF_GL_SCALED }, /* "Undefined" */ 
    { df_GL_FMT_R4G4_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R4G4_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R4G4B4A4_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R4G4B4A4_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R5G6B5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R5G6B5_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R5G5B5A1_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R5G5B5A1_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R8_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R8_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R8_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R8_UINT, DF_GL_INT },
    { df_GL_FMT_R8_SINT, DF_GL_INT },
    { df_GL_FMT_R8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_R8G8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R8G8_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R8G8_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R8G8_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R8G8_UINT, DF_GL_INT },
    { df_GL_FMT_R8G8_SINT, DF_GL_INT },
    { df_GL_FMT_R8G8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8_UINT, DF_GL_INT },
    { df_GL_FMT_R8G8B8_SINT, DF_GL_INT },
    { df_GL_FMT_R8G8B8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8A8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8A8_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8A8_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8A8_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R8G8B8A8_UINT, DF_GL_INT },
    { df_GL_FMT_R8G8B8A8_SINT, DF_GL_INT },
    { df_GL_FMT_R8G8B8A8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_R10G10B10A2_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R10G10B10A2_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R10G10B10A2_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R10G10B10A2_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R10G10B10A2_UINT, DF_GL_INT },
    { df_GL_FMT_R10G10B10A2_SINT, DF_GL_INT },
    { df_GL_FMT_R16_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R16_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R16_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R16_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R16_UINT, DF_GL_INT },
    { df_GL_FMT_R16_SINT, DF_GL_INT },
    { df_GL_FMT_R16_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R16G16_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R16G16_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R16G16_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R16G16_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R16G16_UINT, DF_GL_INT },
    { df_GL_FMT_R16G16_SINT, DF_GL_INT },
    { df_GL_FMT_R16G16_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16_UINT, DF_GL_INT },
    { df_GL_FMT_R16G16B16_SINT, DF_GL_INT },
    { df_GL_FMT_R16G16B16_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16A16_UNORM, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16A16_SNORM, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16A16_USCALED, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16A16_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_R16G16B16A16_UINT, DF_GL_INT },
    { df_GL_FMT_R16G16B16A16_SINT, DF_GL_INT },
    { df_GL_FMT_R16G16B16A16_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R32_UINT, DF_GL_INT },
    { df_GL_FMT_R32_SINT, DF_GL_INT },
    { df_GL_FMT_R32_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R32G32_UINT, DF_GL_INT },
    { df_GL_FMT_R32G32_SINT, DF_GL_INT },
    { df_GL_FMT_R32G32_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R32G32B32_UINT, DF_GL_INT },
    { df_GL_FMT_R32G32B32_SINT, DF_GL_INT },
    { df_GL_FMT_R32G32B32_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R32G32B32A32_UINT, DF_GL_INT },
    { df_GL_FMT_R32G32B32A32_SINT, DF_GL_INT },
    { df_GL_FMT_R32G32B32A32_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R64_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R64G64_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R64G64B64_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R64G64B64A64_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R11G11B10_UFLOAT, DF_GL_SCALED },
    { df_GL_FMT_R9G9B9E5_UFLOAT, DF_GL_SCALED },
    { df_GL_FMT_D16_UNORM, DF_GL_SCALED },
    { df_GL_FMT_D24_UNORM, DF_GL_SCALED },
    { df_GL_FMT_D32_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_S8_UINT, DF_GL_INT },
    { df_GL_FMT_D16_UNORM_S8_UINT, DF_GL_SCALED /* Both! */ },
    { df_GL_FMT_D24_UNORM_S8_UINT, DF_GL_SCALED /* Both! */ },
    { df_GL_FMT_D32_SFLOAT_S8_UINT, DF_GL_SCALED /* Both! */ },
    { df_GL_FMT_BC1_RGB_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC1_RGB_SRGB, DF_GL_SCALED },
    { df_GL_FMT_BC1_RGBA_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC1_RGBA_SRGB, DF_GL_SCALED },
    { df_GL_FMT_BC2_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC2_SRGB, DF_GL_SCALED },
    { df_GL_FMT_BC3_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC3_SRGB, DF_GL_SCALED },
    { df_GL_FMT_BC4_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC4_SNORM, DF_GL_SCALED },
    { df_GL_FMT_BC5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC5_SNORM, DF_GL_SCALED },
    { df_GL_FMT_BC6H_UFLOAT, DF_GL_SCALED },
    { df_GL_FMT_BC6H_SFLOAT, DF_GL_SCALED },
    { df_GL_FMT_BC7_UNORM, DF_GL_SCALED },
    { df_GL_FMT_BC7_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ETC2_R8G8B8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ETC2_R8G8B8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ETC2_R8G8B8A1_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ETC2_R8G8B8A1_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ETC2_R8G8B8A8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ETC2_R8G8B8A8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_EAC_R11_UNORM, DF_GL_SCALED },
    { df_GL_FMT_EAC_R11_SNORM, DF_GL_SCALED },
    { df_GL_FMT_EAC_R11G11_UNORM, DF_GL_SCALED },
    { df_GL_FMT_EAC_R11G11_SNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_4x4_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_4x4_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_5x4_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_5x4_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_5x5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_5x5_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_6x5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_6x5_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_6x6_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_6x6_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_8x5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_8x5_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_8x6_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_8x6_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_8x8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_8x8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x5_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x6_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x6_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x10_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_10x10_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_12x10_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_12x10_SRGB, DF_GL_SCALED },
    { df_GL_FMT_ASTC_12x12_UNORM, DF_GL_SCALED },
    { df_GL_FMT_ASTC_12x12_SRGB, DF_GL_SCALED },
    { df_GL_FMT_B4G4R4A4_UNORM, DF_GL_SCALED },
    { df_GL_FMT_B5G5R5A1_UNORM, DF_GL_SCALED },
    { df_GL_FMT_B5G6R5_UNORM, DF_GL_SCALED },
    { df_GL_FMT_B5G6R5_USCALED, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8_SNORM, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8_USCALED, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8_UINT, DF_GL_INT },
    { df_GL_FMT_B8G8R8_SINT, DF_GL_INT },
    { df_GL_FMT_B8G8R8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8A8_UNORM, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8A8_SNORM, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8A8_USCALED, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8A8_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_B8G8R8A8_UINT, DF_GL_INT },
    { df_GL_FMT_B8G8R8A8_SINT, DF_GL_INT },
    { df_GL_FMT_B8G8R8A8_SRGB, DF_GL_SCALED },
    { df_GL_FMT_B10G10R10A2_UNORM, DF_GL_SCALED },
    { df_GL_FMT_B10G10R10A2_SNORM, DF_GL_SCALED },
    { df_GL_FMT_B10G10R10A2_USCALED, DF_GL_SCALED },
    { df_GL_FMT_B10G10R10A2_SSCALED, DF_GL_SCALED },
    { df_GL_FMT_B10G10R10A2_UINT, DF_GL_INT },
    { df_GL_FMT_B10G10R10A2_SINT, DF_GL_INT }
};

#endif
