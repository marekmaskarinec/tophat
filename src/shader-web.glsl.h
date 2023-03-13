#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Cmdline: sokol-shdc --input shader.glsl --output src\shader-web.glsl.h --slang glsl100

    Overview:

        Shader program 'th':
            Get shader desc: th_shader_desc(sg_query_backend());
            Vertex shader: th_vs
                Attribute slots:
                    ATTR_th_vs_pos = 0
                    ATTR_th_vs_uv0 = 1
                    ATTR_th_vs_color0 = 2
            Fragment shader: th_fs
                Image 'tex':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_tex = 0


    Shader descriptor structs:

        sg_shader th = sg_make_shader(th_shader_desc(sg_query_backend()));

    Vertex attribute locations for vertex shader 'th_vs':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_th_vs_pos] = { ... },
                    [ATTR_th_vs_uv0] = { ... },
                    [ATTR_th_vs_color0] = { ... },
                },
            },
            ...});

    Image bind slots, use as index in sg_bindings.vs_images[] or .fs_images[]

        SLOT_tex = 0;

*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#if !defined(SOKOL_SHDC_ALIGN)
  #if defined(_MSC_VER)
    #define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
  #else
    #define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
  #endif
#endif
#define ATTR_th_vs_pos (0)
#define ATTR_th_vs_uv0 (1)
#define ATTR_th_vs_color0 (2)
#define SLOT_tex (0)
/*
    #version 100
    
    attribute vec2 pos;
    varying vec2 uv;
    attribute vec2 uv0;
    varying vec4 color;
    attribute vec4 color0;
    
    void main()
    {
        vec2 _17 = pos * 2.0;
        vec2 _53 = _17;
        _53.y = _17.y * (-1.0);
        gl_Position = vec4(_53 + vec2(-1.0, 1.0), -0.100000001490116119384765625, 1.0);
        uv = uv0;
        color = color0;
    }
    
*/
static const char th_vs_source_glsl100[325] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x31,0x30,0x30,0x0a,0x0a,0x61,0x74,
    0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x20,0x76,0x65,0x63,0x32,0x20,0x70,0x6f,0x73,
    0x3b,0x0a,0x76,0x61,0x72,0x79,0x69,0x6e,0x67,0x20,0x76,0x65,0x63,0x32,0x20,0x75,
    0x76,0x3b,0x0a,0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x20,0x76,0x65,0x63,
    0x32,0x20,0x75,0x76,0x30,0x3b,0x0a,0x76,0x61,0x72,0x79,0x69,0x6e,0x67,0x20,0x76,
    0x65,0x63,0x34,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x61,0x74,0x74,0x72,0x69,
    0x62,0x75,0x74,0x65,0x20,0x76,0x65,0x63,0x34,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x30,
    0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,
    0x0a,0x20,0x20,0x20,0x20,0x76,0x65,0x63,0x32,0x20,0x5f,0x31,0x37,0x20,0x3d,0x20,
    0x70,0x6f,0x73,0x20,0x2a,0x20,0x32,0x2e,0x30,0x3b,0x0a,0x20,0x20,0x20,0x20,0x76,
    0x65,0x63,0x32,0x20,0x5f,0x35,0x33,0x20,0x3d,0x20,0x5f,0x31,0x37,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x5f,0x35,0x33,0x2e,0x79,0x20,0x3d,0x20,0x5f,0x31,0x37,0x2e,0x79,
    0x20,0x2a,0x20,0x28,0x2d,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x67,
    0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x76,0x65,0x63,
    0x34,0x28,0x5f,0x35,0x33,0x20,0x2b,0x20,0x76,0x65,0x63,0x32,0x28,0x2d,0x31,0x2e,
    0x30,0x2c,0x20,0x31,0x2e,0x30,0x29,0x2c,0x20,0x2d,0x30,0x2e,0x31,0x30,0x30,0x30,
    0x30,0x30,0x30,0x30,0x31,0x34,0x39,0x30,0x31,0x31,0x36,0x31,0x31,0x39,0x33,0x38,
    0x34,0x37,0x36,0x35,0x36,0x32,0x35,0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x75,0x76,0x20,0x3d,0x20,0x75,0x76,0x30,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x63,0x6f,0x6c,0x6f,0x72,0x30,0x3b,
    0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 100
    precision mediump float;
    precision highp int;
    
    uniform highp sampler2D tex;
    
    varying highp vec4 color;
    varying highp vec2 uv;
    
    void main()
    {
        gl_FragData[0] = color * texture2D(tex, uv);
    }
    
*/
static const char th_fs_source_glsl100[207] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x31,0x30,0x30,0x0a,0x70,0x72,0x65,
    0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,0x6d,0x65,0x64,0x69,0x75,0x6d,0x70,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x3b,0x0a,0x70,0x72,0x65,0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,
    0x68,0x69,0x67,0x68,0x70,0x20,0x69,0x6e,0x74,0x3b,0x0a,0x0a,0x75,0x6e,0x69,0x66,
    0x6f,0x72,0x6d,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,
    0x72,0x32,0x44,0x20,0x74,0x65,0x78,0x3b,0x0a,0x0a,0x76,0x61,0x72,0x79,0x69,0x6e,
    0x67,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x34,0x20,0x63,0x6f,0x6c,
    0x6f,0x72,0x3b,0x0a,0x76,0x61,0x72,0x79,0x69,0x6e,0x67,0x20,0x68,0x69,0x67,0x68,
    0x70,0x20,0x76,0x65,0x63,0x32,0x20,0x75,0x76,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,
    0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,
    0x5f,0x46,0x72,0x61,0x67,0x44,0x61,0x74,0x61,0x5b,0x30,0x5d,0x20,0x3d,0x20,0x63,
    0x6f,0x6c,0x6f,0x72,0x20,0x2a,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x32,0x44,
    0x28,0x74,0x65,0x78,0x2c,0x20,0x75,0x76,0x29,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#if !defined(SOKOL_GFX_INCLUDED)
  #error "Please include sokol_gfx.h before shader-web.glsl.h"
#endif
static inline const sg_shader_desc* th_shader_desc(sg_backend backend) {
  if (backend == SG_BACKEND_GLES2) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "pos";
      desc.attrs[1].name = "uv0";
      desc.attrs[2].name = "color0";
      desc.vs.source = th_vs_source_glsl100;
      desc.vs.entry = "main";
      desc.fs.source = th_fs_source_glsl100;
      desc.fs.entry = "main";
      desc.fs.images[0].name = "tex";
      desc.fs.images[0].image_type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "th_shader";
    }
    return &desc;
  }
  return 0;
}
