/*
 *  Copyright (C) 2016 Intel Corporation
 *    Author: Puunithaaraj Gopal <puunithaaraj.gopal@intel.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1
 *  of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301 USA
 */

#ifndef GST_MFX_SINK_BIN_H
#define GST_MFX_SINK_BIN_H

#include <gst-libs/mfx/gstmfxvalue.h>
#include <gst-libs/mfx/gstmfxfilter.h>
#include <gst-libs/mfx/gstmfxdisplay.h>
#include <gst-libs/mfx/gstmfxcontrolbindingproxy.h>

G_BEGIN_DECLS

#define GST_TYPE_MFX_SINK_BIN (gst_mfx_sink_bin_get_type ())
#define GST_MFX_SINK_BIN(obj) \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_MFX_SINK_BIN, GstMfxSinkBin))
#define GST_MFX_SINK_BIN_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST ((klass), GST_TYPE_MFX_SINK_BIN, GstMfxSinkBinClass))
#define GST_IS_AUTO_DETECT(obj) \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), GST_TYPE_MFX_SINK_BIN))
#define GST_MFX_SINK_BIN_GET_CLASS(obj) \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_MFX_SINK_BIN, GstMfxSinkBinClass))

typedef struct __GstMfxSinkBin {
  /* Private */
  GstBin parent;

  GstElement *postproc;
  GstElement *sink;

  guint                   width;
  guint                   height;

  /* Deinterlacing */
  GstMfxDeinterlaceMode   deinterlace_mode;

  /* Basic filter values */
  guint                   denoise_level;
  guint                   detail_level;

  /* Color balance filter values */
  gfloat                  hue;
  gfloat                  saturation;
  gfloat                  brightness;
  gfloat                  contrast;

  /* Rotation angle */
  GstMfxRotation          angle;

  guint                   keep_aspect : 1;
  GstMfxDisplayType       display_type;

  guint                   handle_events : 1;
  guint                   fullscreen : 1;
  guint                   no_frame_drop : 1;
} GstMfxSinkBin;

typedef struct __GstMfxSinkBinClass {
  GstBinClass parent_class;
} GstMfxSinkBinClass;

GType gst_mfx_sink_bin_get_type (void);

G_END_DECLS;

#endif /* GST_MFX_SINK_BIN_H */
