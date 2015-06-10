/* The Khronos Data Format Specification (provisional) - mappings for OpenVX */
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
#ifndef _VX_DATA_FORMAT_H_
#define _VX_DATA_FORMAT_H_

#include <stdint.h>
#include <khr_df.h>

#define VX_DF_BLOCKSIZE_1SAMPLE 40U
#define VX_DF_TOTALSIZE_1SAMPLE 44U
#define VX_DF_BLOCKSIZE_3SAMPLES 72U
#define VX_DF_TOTALSIZE_3SAMPLES 76U
#define VX_DF_BLOCKSIZE_4SAMPLES 88U
#define VX_DF_TOTALSIZE_4SAMPLES 92U
#define VX_DF_BLOCKSIZE_6SAMPLES 120U
#define VX_DF_TOTALSIZE_6SAMPLES 124U

#define _VX_DF_SPACE_MAPPING(VXSPACE) \
    ((VXSPACE) == VX_COLOR_SPACE_NONE ? KHR_DF_PRIMARIES_UNSPECIFIED : \
     (VXSPACE) == VX_COLOR_SPACE_BT601_525 ? KHR_DF_PRIMARIES_BT601_SMPTE : \
     (VXSPACE) == VX_COLOR_SPACE_BT601_625 ? KHR_DF_PRIMARIES_BT601_EBU : \
     KHR_DF_PRIMARIES_BT709)

#define _VX_DF_IMAGE_RGB2(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_3SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_3SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            3U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 3 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_RED << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_GREEN << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_BLUE << 24U, /* Blue channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U) /* sample_upper */ \
        }

/* Note: "RGBA" has no alpha channel - the remaining byte is padding */
#define _VX_DF_IMAGE_RGBX(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_3SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_3SAMPLES << 16U,                            \
            KHR_DF_MODEL_RGBSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 4 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_RED << 24U, /* Red channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_GREEN << 24U, /* Green channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_RGBSDA_BLUE << 24U, /* Blue channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U) /* sample_upper */ \
        }

/* N.B. Assuming JPEG-style UV sample positions */
#define _VX_DF_IMAGE_NV12(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_6SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_6SAMPLES << 16U,                            \
            KHR_DF_MODEL_YUVSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* 2x2x1x1 texel block */ \
            2U | 2U << 8U | 2U << 16U | 0U << 24U, /* Three planes, 2 bytes each */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 2U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            24U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 2U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            32U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_U << 24U, /* U channel */ \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            48U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_V << 24U, /* V channel */ \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U) /* sample_upper */ \
        }

/* N.B. Assuming JPEG-style UV sample positions */
#define _VX_DF_IMAGE_NV21(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_6SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_6SAMPLES << 16U,                            \
            KHR_DF_MODEL_YUVSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* 2x2x1x1 texel block */ \
            2U | 2U << 8U | 2U << 16U | 0U << 24U, /* Three planes, 2 bytes each */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 2U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            24U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 2U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            32U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_V << 24U, /* V channel */ \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            40U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_U << 24U, /* U channel */ \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U) /* sample_upper */ \
        }

#define _VX_DF_IMAGE_UYVY(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_4SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_4SAMPLES << 16U,                            \
            KHR_DF_MODEL_YUVSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* 2x1x1x1 texel block */ \
            4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 4 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_U << 24U, /* U channel */ \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_V << 24U, /* V channel */ \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            24U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U) /* sample_upper */ \
        }

#define _VX_DF_IMAGE_YUYV(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_4SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_4SAMPLES << 16U,                            \
            KHR_DF_MODEL_YUVSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* 2x1x1x1 texel block */ \
            4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 4 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_U << 24U, /* U channel */ \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            24U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_V << 24U, /* V channel */ \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U) /* sample_upper */ \
        }

/* N.B. Assuming JPEG-style UV sample positions */
#define _VX_DF_IMAGE_IYUV(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_6SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_6SAMPLES << 16U,                            \
            KHR_DF_MODEL_YUVSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* 2x2x1x1 texel block */ \
            2U | 2U << 8U | 1U << 16U | 1U << 24U, /* Four planes, 2,2,1,1 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 2U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            24U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            2U | 2U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            32U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_U << 24U, /* U channel */ \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            40U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_V << 24U, /* V channel */ \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U) /* sample_upper */ \
        }

#define _VX_DF_IMAGE_YUV4(SPACE, RANGE)                                 \
    {                                                                   \
        VX_DF_TOTALSIZE_3SAMPLES, /* Total size in bytes */             \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_3SAMPLES << 16U,                            \
            KHR_DF_MODEL_YUVSDA |                                       \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            1U | 1U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            1U | 1U << 8U | 1U << 16U | 0U << 24U, /* Three planes, 1 byte each */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_Y << 24U, /* Y channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U), /* sample_upper */ \
            8U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_U << 24U, /* U channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U), /* sample_upper */ \
            16U | 8U << 16U | KHR_DF_CHANNEL_YUVSDA_V << 24U, /* V channel */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* Sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 240U) /* sample_upper */ \
        }

#define _VX_DF_IMAGE_U8(SPACE, RANGE)                                   \
    {                                                                   \
        VX_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */              \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_1SAMPLE << 16U,                             \
            KHR_DF_MODEL_UNSPECIFIED |                                  \
            _VX_DF_SPACE_MAPPING(SPACE) << 8U |                         \
            KHR_DF_TRANSFER_UNSPECIFIED << 16U,                         \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            1U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 1 byte */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 8U << 16U | KHR_DF_CHANNEL_UNSPECIFIED_0 << 24U,       \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 0U : 16U), /* sample_lower */ \
            ((RANGE) == VX_CHANNEL_RANGE_FULL ? 255U : 235U) /* sample_upper */ \
        }

/* Ignoring space and range for this format */
#define _VX_DF_IMAGE_U16                                                \
    {                                                                   \
        VX_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */              \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_1SAMPLE << 16U,                             \
            KHR_DF_MODEL_UNSPECIFIED |                                  \
            KHR_DF_PRIMARIES_UNSPECIFIED << 8U |                        \
            KHR_DF_TRANSFER_UNSPECIFIED << 16U,                         \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 2 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 16U << 16U | KHR_DF_CHANNEL_UNSPECIFIED_0 << 24U,      \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            0U, /* sample_lower */                                      \
            65535U /* sample_upper */                                   \
        }

/* Ignoring space and range for this format */
#define _VX_DF_IMAGE_S16                                                \
    {                                                                   \
        VX_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */              \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_1SAMPLE << 16U,                             \
            KHR_DF_MODEL_UNSPECIFIED |                                  \
            KHR_DF_PRIMARIES_UNSPECIFIED << 8U |                        \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            2U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 2 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 16U << 16U | (KHR_DF_CHANNEL_UNSPECIFIED_0 | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            32768U, /* sample_lower (=-32768) */                        \
            32767U /* sample_upper */                                   \
        }

/* Ignoring space and range for this format */
#define _VX_DF_IMAGE_U32                                                \
    {                                                                   \
        VX_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */              \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_1SAMPLE << 16U,                             \
            KHR_DF_MODEL_UNSPECIFIED |                                  \
            KHR_DF_PRIMARIES_UNSPECIFIED << 8U |                        \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 4 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 32U << 16U | KHR_DF_CHANNEL_UNSPECIFIED_0 << 24U,      \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            0U, /* sample_lower */                                      \
            ~0U /* sample_upper */                                      \
        }

/* Ignoring space and range for this format */
#define _VX_DF_IMAGE_S32                                                \
    {                                                                   \
        VX_DF_TOTALSIZE_1SAMPLE, /* Total size in bytes */              \
            KHR_DF_VENDORID_KHRONOS |                                   \
            KHR_DF_KHR_DESCRIPTORTYPE_BASICFORMAT << 16U,               \
            0U /* Version number */ |                                   \
            VX_DF_BLOCKSIZE_1SAMPLE << 16U,                             \
            KHR_DF_MODEL_UNSPECIFIED |                                  \
            KHR_DF_PRIMARIES_UNSPECIFIED << 8U |                        \
            KHR_DF_TRANSFER_ITU << 16U,                                 \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* 1x1x1x1 texel block */ \
            4U | 0U << 8U | 0U << 16U | 0U << 24U, /* One plane, 4 bytes */ \
            0U | 0U << 8U | 0U << 16U | 0U << 24U,                      \
            0U | 16U << 16U | (KHR_DF_CHANNEL_UNSPECIFIED_0 | KHR_DF_SAMPLE_DATATYPE_SIGNED) << 24U, \
            0U | 0U << 8U | 0U << 16U | 0U << 24U, /* One sample location */ \
            1U << 31U, /* sample_lower (=1<<32-1) */                    \
            (1U << 31U)-1U /* sample_upper =-(1<<32) */                 \
        }

/* Representation of a look-up table TBD */

#endif
