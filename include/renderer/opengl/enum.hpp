/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef RENDERER_ENUM_HPP
#define RENDERER_ENUM_HPP

#include "GL/glcorearb.h"
#include "GL/glext.h"

#include "utility/enumeration.hpp"

#ifdef _WIN32
#	undef NO_ERROR
#endif

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			// TODO: replace lot of enumerations by assert to check the value ?

			enum class ShaderType : unsigned short int
			{
				COMPUTE_SHADER = GL_COMPUTE_SHADER,
				FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
				GEOMETRY_SHADER = GL_GEOMETRY_SHADER,
				VERTEX_SHADER = GL_VERTEX_SHADER,
				TESS_EVALUATION_SHADER = GL_TESS_EVALUATION_SHADER,
				TESS_CONTROL_SHADER = GL_TESS_CONTROL_SHADER
			};

			enum class BufferType : unsigned short int
			{
				ARRAY_BUFFER = GL_ARRAY_BUFFER,
				ATOMIC_COUNTER_BUFFER = GL_ATOMIC_COUNTER_BUFFER,
				COPY_READ_BUFFER = GL_COPY_READ_BUFFER,
				COPY_WRITE_BUFFER = GL_COPY_WRITE_BUFFER,
				DISPATCH_INDIRECT_BUFFER = GL_DISPATCH_INDIRECT_BUFFER,
				DRAW_INDIRECT_BUFFER = GL_DRAW_INDIRECT_BUFFER,
				ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER,
				PIXEL_PACK_BUFFER = GL_PIXEL_PACK_BUFFER,
				PIXEL_UNPACK_BUFFER = GL_PIXEL_UNPACK_BUFFER,
				QUERY_BUFFER = GL_QUERY_BUFFER,
				SHADER_STORAGE_BUFFER = GL_SHADER_STORAGE_BUFFER,
				TEXTURE_BUFFER = GL_TEXTURE_BUFFER,
				TRANSFORM_FEEDBACK_BUFFER = GL_TRANSFORM_FEEDBACK,
				UNIFORM_BUFFER = GL_UNIFORM_BUFFER
			};

			enum class BufferUsage : unsigned short int
			{
				STREAM_DRAW = GL_STREAM_DRAW,
				STREAM_READ = GL_STREAM_READ,
				STREAM_COPY = GL_STREAM_COPY,
				STATIC_DRAW = GL_STATIC_DRAW,
				STATIC_READ = GL_STATIC_READ,
				STATIC_COPY = GL_STATIC_COPY,
				DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
				DYNAMIC_READ = GL_DYNAMIC_READ,
				DYNAMIC_COPY = GL_DYNAMIC_COPY
			};

			enum class DataType : unsigned short int
			{
				BYTE = GL_BYTE,
				UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
				SHORT = GL_SHORT,
				UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
				INT = GL_INT,
				UNSIGNED_INT = GL_UNSIGNED_INT,
				HALF_FLOAT = GL_HALF_FLOAT,
				FLOAT = GL_FLOAT,
				DOUBLE = GL_DOUBLE,
				FIXED = GL_FIXED,
				INT_2_10_10_10_REV = GL_INT_2_10_10_10_REV,
				UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV,
				UNSIGNED_INT_10F_11F_11F_REV = GL_UNSIGNED_INT_10F_11F_11F_REV
			};

			enum class PrimitiveMode : unsigned short int
			{
				POINTS = GL_POINTS,
				LINE_STRIP = GL_LINE_STRIP,
				LINE_LOOP = GL_LINE_LOOP,
				LINES = GL_LINES,
				LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
				LINES_ADJACENCY = GL_LINES_ADJACENCY,
				TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
				TRIANGLE_FAN = GL_TRIANGLE_FAN,
				TRIANGLES = GL_TRIANGLES,
				TRIANGLES_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
				TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
				PATCHES = GL_PATCHES
			};

			EnumFlagsT(unsigned short int, Bitfield)
			{
				COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT,
					DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT,
					STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT
			};

			enum class Capability : unsigned short int
			{
				BLEND = GL_BLEND,
				CLIP_DISTANCE0 = GL_CLIP_DISTANCE0,
				CLIP_DISTANCE1 = GL_CLIP_DISTANCE1,
				CLIP_DISTANCE2 = GL_CLIP_DISTANCE2,
				CLIP_DISTANCE3 = GL_CLIP_DISTANCE3,
				CLIP_DISTANCE4 = GL_CLIP_DISTANCE4,
				CLIP_DISTANCE5 = GL_CLIP_DISTANCE5,
				CLIP_DISTANCE6 = GL_CLIP_DISTANCE6,
				CLIP_DISTANCE7 = GL_CLIP_DISTANCE7,
				COLOR_LOGIC_OP = GL_COLOR_LOGIC_OP,
				CULL_FACE = GL_CULL_FACE,
				DEBUG_OUTPUT = GL_DEBUG_OUTPUT,
				DEBUG_OUTPUT_SYNCHRONOUS = GL_DEBUG_OUTPUT_SYNCHRONOUS,
				DEPTH_CLAMP = GL_DEPTH_CLAMP,
				DEPTH_TEST = GL_DEPTH_TEST,
				DITHER = GL_DITHER,
				FRAMEBUFFER_SRGB = GL_FRAMEBUFFER_SRGB,
				LINE_SMOOTH = GL_LINE_SMOOTH,
				MULTISAMPLE = GL_MULTISAMPLE,
				POLYGON_OFFSET_FILL = GL_POLYGON_OFFSET_FILL,
				POLYGON_OFFSET_LINE = GL_POLYGON_OFFSET_LINE,
				POLYGON_OFFSET_POINT = GL_POLYGON_OFFSET_POINT,
				POLYGON_SMOOTH = GL_POLYGON_SMOOTH,
				PRIMITIVE_RESTART = GL_PRIMITIVE_RESTART,
				PRIMITIVE_RESTART_FIXED_INDEX = GL_PRIMITIVE_RESTART_FIXED_INDEX,
				RASTERIZER_DISCARD = GL_RASTERIZER_DISCARD,
				SAMPLE_ALPHA_TO_COVERAGE = GL_SAMPLE_ALPHA_TO_COVERAGE,
				SAMPLE_ALPHA_TO_ONE = GL_SAMPLE_ALPHA_TO_ONE,
				SAMPLE_COVERAGE = GL_SAMPLE_COVERAGE,
				SAMPLE_SHADING = GL_SAMPLE_SHADING,
				SAMPLE_MASK = GL_SAMPLE_MASK,
				SCISSOR_TEST = GL_SCISSOR_TEST,
				STENCIL_TEST = GL_STENCIL_TEST,
				TEXTURE_CUBE_MAP_SEAMLESS = GL_TEXTURE_CUBE_MAP_SEAMLESS,
				PROGRAM_POINT_SIZE = GL_PROGRAM_POINT_SIZE
			};

			enum class Parameter : unsigned short int
			{
				ACTIVE_TEXTURE = GL_ACTIVE_TEXTURE,
				ALIASED_LINE_WIDTH_RANGE = GL_ALIASED_LINE_WIDTH_RANGE,
				ARRAY_BUFFER_BINDING = GL_ARRAY_BUFFER_BINDING,
				BLEND = GL_BLEND,
				BLEND_COLOR = GL_BLEND_COLOR,
				BLEND_DST_ALPHA = GL_BLEND_DST_ALPHA,
				BLEND_DST_RGB = GL_BLEND_DST_RGB,
				BLEND_EQUATION_RGB = GL_BLEND_EQUATION_RGB,
				BLEND_EQUATION_ALPHA = GL_BLEND_EQUATION_ALPHA,
				BLEND_SRC_ALPHA = GL_BLEND_SRC_ALPHA,
				BLEND_SRC_RGB = GL_BLEND_SRC_RGB,
				COLOR_CLEAR_VALUE = GL_COLOR_CLEAR_VALUE,
				COLOR_LOGIC_OP = GL_COLOR_LOGIC_OP,
				COLOR_WRITEMASK = GL_COLOR_WRITEMASK,
				COMPRESSED_TEXTURE_FORMATS = GL_COMPRESSED_TEXTURE_FORMATS,
				MAX_COMPUTE_SHADER_STORAGE_BLOCKS = GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS,
				MAX_COMBINED_SHADER_STORAGE_BLOCKS = GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS,
				MAX_COMPUTE_UNIFORM_BLOCKS = GL_MAX_COMPUTE_UNIFORM_BLOCKS,
				MAX_COMPUTE_TEXTURE_IMAGE_UNITS = GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS,
				MAX_COMPUTE_UNIFORM_COMPONENTS = GL_MAX_COMPUTE_UNIFORM_COMPONENTS,
				MAX_COMPUTE_ATOMIC_COUNTERS = GL_MAX_COMPUTE_ATOMIC_COUNTERS,
				MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS,
				MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS,
				MAX_COMPUTE_WORK_GROUP_INVOCATIONS = GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS,
				MAX_COMPUTE_WORK_GROUP_COUNT = GL_MAX_COMPUTE_WORK_GROUP_COUNT,
				MAX_COMPUTE_WORK_GROUP_SIZE = GL_MAX_COMPUTE_WORK_GROUP_SIZE,
				DISPATCH_INDIRECT_BUFFER_BINDING = GL_DISPATCH_INDIRECT_BUFFER_BINDING,
				MAX_DEBUG_GROUP_STACK_DEPTH = GL_MAX_DEBUG_GROUP_STACK_DEPTH,
				DEBUG_GROUP_STACK_DEPTH = GL_DEBUG_GROUP_STACK_DEPTH,
				CONTEXT_FLAGS = GL_CONTEXT_FLAGS,
				CULL_FACE = GL_CULL_FACE,
				CULL_FACE_MODE = GL_CULL_FACE_MODE,
				CURRENT_PROGRAM = GL_CURRENT_PROGRAM,
				DEPTH_CLEAR_VALUE = GL_DEPTH_CLEAR_VALUE,
				DEPTH_FUNC = GL_DEPTH_FUNC,
				DEPTH_RANGE = GL_DEPTH_RANGE,
				DEPTH_TEST = GL_DEPTH_TEST,
				DEPTH_WRITEMASK = GL_DEPTH_WRITEMASK,
				DITHER = GL_DITHER,
				DOUBLEBUFFER = GL_DOUBLEBUFFER,
				DRAW_BUFFER = GL_DRAW_BUFFER,
				DRAW_BUFFER0 = GL_DRAW_BUFFER0,
				DRAW_BUFFER1 = GL_DRAW_BUFFER1,
				DRAW_BUFFER2 = GL_DRAW_BUFFER2,
				DRAW_BUFFER3 = GL_DRAW_BUFFER3,
				DRAW_BUFFER4 = GL_DRAW_BUFFER4,
				DRAW_BUFFER5 = GL_DRAW_BUFFER5,
				DRAW_BUFFER6 = GL_DRAW_BUFFER6,
				DRAW_BUFFER7 = GL_DRAW_BUFFER7,
				DRAW_BUFFER8 = GL_DRAW_BUFFER8,
				DRAW_BUFFER9 = GL_DRAW_BUFFER9,
				DRAW_BUFFER10 = GL_DRAW_BUFFER10,
				DRAW_BUFFER11 = GL_DRAW_BUFFER11,
				DRAW_BUFFER12 = GL_DRAW_BUFFER12,
				DRAW_BUFFER13 = GL_DRAW_BUFFER13,
				DRAW_BUFFER14 = GL_DRAW_BUFFER14,
				DRAW_BUFFER15 = GL_DRAW_BUFFER15,
				DRAW_FRAMEBUFFER_BINDING = GL_DRAW_FRAMEBUFFER_BINDING,
				READ_FRAMEBUFFER_BINDING = GL_READ_FRAMEBUFFER_BINDING,
				ELEMENT_ARRAY_BUFFER_BINDING = GL_ELEMENT_ARRAY_BUFFER_BINDING,
				FRAGMENT_SHADER_DERIVATIVE_HINT = GL_FRAGMENT_SHADER_DERIVATIVE_HINT,
				IMPLEMENTATION_COLOR_READ_FORMAT = GL_IMPLEMENTATION_COLOR_READ_FORMAT,
				IMPLEMENTATION_COLOR_READ_TYPE = GL_IMPLEMENTATION_COLOR_READ_TYPE,
				LINE_SMOOTH = GL_LINE_SMOOTH,
				LINE_SMOOTH_HINT = GL_LINE_SMOOTH_HINT,
				LINE_WIDTH = GL_LINE_WIDTH,
				LAYER_PROVOKING_VERTEX = GL_LAYER_PROVOKING_VERTEX,
				LOGIC_OP_MODE = GL_LOGIC_OP_MODE,
				MAJOR_VERSION = GL_MAJOR_VERSION,
				MAX_3D_TEXTURE_SIZE = GL_MAX_3D_TEXTURE_SIZE,
				MAX_ARRAY_TEXTURE_LAYERS = GL_MAX_ARRAY_TEXTURE_LAYERS,
				MAX_CLIP_DISTANCES = GL_MAX_CLIP_DISTANCES,
				MAX_COLOR_TEXTURE_SAMPLES = GL_MAX_COLOR_TEXTURE_SAMPLES,
				MAX_COMBINED_ATOMIC_COUNTERS = GL_MAX_COMBINED_ATOMIC_COUNTERS,
				MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,
				MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,
				MAX_COMBINED_TEXTURE_IMAGE_UNITS = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
				MAX_COMBINED_UNIFORM_BLOCKS = GL_MAX_COMBINED_UNIFORM_BLOCKS,
				MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,
				MAX_CUBE_MAP_TEXTURE_SIZE = GL_MAX_CUBE_MAP_TEXTURE_SIZE,
				MAX_DEPTH_TEXTURE_SAMPLES = GL_MAX_DEPTH_TEXTURE_SAMPLES,
				MAX_DRAW_BUFFERS = GL_MAX_DRAW_BUFFERS,
				MAX_DUAL_SOURCE_DRAW_BUFFERS = GL_MAX_DUAL_SOURCE_DRAW_BUFFERS,
				MAX_ELEMENTS_INDICES = GL_MAX_ELEMENTS_INDICES,
				MAX_ELEMENTS_VERTICES = GL_MAX_ELEMENTS_VERTICES,
				MAX_FRAGMENT_ATOMIC_COUNTERS = GL_MAX_FRAGMENT_ATOMIC_COUNTERS,
				MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS,
				MAX_FRAGMENT_INPUT_COMPONENTS = GL_MAX_FRAGMENT_INPUT_COMPONENTS,
				MAX_FRAGMENT_UNIFORM_COMPONENTS = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
				MAX_FRAGMENT_UNIFORM_VECTORS = GL_MAX_FRAGMENT_UNIFORM_VECTORS,
				MAX_FRAGMENT_UNIFORM_BLOCKS = GL_MAX_FRAGMENT_UNIFORM_BLOCKS,
				MAX_FRAMEBUFFER_WIDTH = GL_MAX_FRAMEBUFFER_WIDTH,
				MAX_FRAMEBUFFER_HEIGHT = GL_MAX_FRAMEBUFFER_HEIGHT,
				MAX_FRAMEBUFFER_LAYERS = GL_MAX_FRAMEBUFFER_LAYERS,
				MAX_FRAMEBUFFER_SAMPLES = GL_MAX_FRAMEBUFFER_SAMPLES,
				MAX_GEOMETRY_ATOMIC_COUNTERS = GL_MAX_GEOMETRY_ATOMIC_COUNTERS,
				MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS,
				MAX_GEOMETRY_INPUT_COMPONENTS = GL_MAX_GEOMETRY_INPUT_COMPONENTS,
				MAX_GEOMETRY_OUTPUT_COMPONENTS = GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,
				MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,
				MAX_GEOMETRY_UNIFORM_BLOCKS = GL_MAX_GEOMETRY_UNIFORM_BLOCKS,
				MAX_GEOMETRY_UNIFORM_COMPONENTS = GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,
				MAX_INTEGER_SAMPLES = GL_MAX_INTEGER_SAMPLES,
				MIN_MAP_BUFFER_ALIGNMENT = GL_MIN_MAP_BUFFER_ALIGNMENT,
				MAX_LABEL_LENGTH = GL_MAX_LABEL_LENGTH,
				MAX_PROGRAM_TEXEL_OFFSET = GL_MAX_PROGRAM_TEXEL_OFFSET,
				MIN_PROGRAM_TEXEL_OFFSET = GL_MIN_PROGRAM_TEXEL_OFFSET,
				MAX_RECTANGLE_TEXTURE_SIZE = GL_MAX_RECTANGLE_TEXTURE_SIZE,
				MAX_RENDERBUFFER_SIZE = GL_MAX_RENDERBUFFER_SIZE,
				MAX_SAMPLE_MASK_WORDS = GL_MAX_SAMPLE_MASK_WORDS,
				MAX_SERVER_WAIT_TIMEOUT = GL_MAX_SERVER_WAIT_TIMEOUT,
				MAX_SHADER_STORAGE_BUFFER_BINDINGS = GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS,
				MAX_TESS_CONTROL_ATOMIC_COUNTERS = GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS,
				MAX_TESS_EVALUATION_ATOMIC_COUNTERS = GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS,
				MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS,
				MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS,
				MAX_TEXTURE_BUFFER_SIZE = GL_MAX_TEXTURE_BUFFER_SIZE,
				MAX_TEXTURE_IMAGE_UNITS = GL_MAX_TEXTURE_IMAGE_UNITS,
				MAX_TEXTURE_LOD_BIAS = GL_MAX_TEXTURE_LOD_BIAS,
				MAX_TEXTURE_SIZE = GL_MAX_TEXTURE_SIZE,
				MAX_UNIFORM_BUFFER_BINDINGS = GL_MAX_UNIFORM_BUFFER_BINDINGS,
				MAX_UNIFORM_BLOCK_SIZE = GL_MAX_UNIFORM_BLOCK_SIZE,
				MAX_UNIFORM_LOCATIONS = GL_MAX_UNIFORM_LOCATIONS,
				MAX_VARYING_COMPONENTS = GL_MAX_VARYING_COMPONENTS,
				MAX_VARYING_VECTORS = GL_MAX_VARYING_VECTORS,
				MAX_VARYING_FLOATS = GL_MAX_VARYING_FLOATS,
				MAX_VERTEX_ATOMIC_COUNTERS = GL_MAX_VERTEX_ATOMIC_COUNTERS,
				MAX_VERTEX_ATTRIBS = GL_MAX_VERTEX_ATTRIBS,
				MAX_VERTEX_SHADER_STORAGE_BLOCKS = GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS,
				MAX_VERTEX_TEXTURE_IMAGE_UNITS = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
				MAX_VERTEX_UNIFORM_COMPONENTS = GL_MAX_VERTEX_UNIFORM_COMPONENTS,
				MAX_VERTEX_UNIFORM_VECTORS = GL_MAX_VERTEX_UNIFORM_VECTORS,
				MAX_VERTEX_OUTPUT_COMPONENTS = GL_MAX_VERTEX_OUTPUT_COMPONENTS,
				MAX_VERTEX_UNIFORM_BLOCKS = GL_MAX_VERTEX_UNIFORM_BLOCKS,
				MAX_VIEWPORT_DIMS = GL_MAX_VIEWPORT_DIMS,
				MAX_VIEWPORTS = GL_MAX_VIEWPORTS,
				MINOR_VERSION = GL_MINOR_VERSION,
				NUM_COMPRESSED_TEXTURE_FORMATS = GL_NUM_COMPRESSED_TEXTURE_FORMATS,
				NUM_EXTENSIONS = GL_NUM_EXTENSIONS,
				NUM_PROGRAM_BINARY_FORMATS = GL_NUM_PROGRAM_BINARY_FORMATS,
				NUM_SHADER_BINARY_FORMATS = GL_NUM_SHADER_BINARY_FORMATS,
				PACK_ALIGNMENT = GL_PACK_ALIGNMENT,
				PACK_IMAGE_HEIGHT = GL_PACK_IMAGE_HEIGHT,
				PACK_LSB_FIRST = GL_PACK_LSB_FIRST,
				PACK_ROW_LENGTH = GL_PACK_ROW_LENGTH,
				PACK_SKIP_IMAGES = GL_PACK_SKIP_IMAGES,
				PACK_SKIP_PIXELS = GL_PACK_SKIP_PIXELS,
				PACK_SKIP_ROWS = GL_PACK_SKIP_ROWS,
				PACK_SWAP_BYTES = GL_PACK_SWAP_BYTES,
				PIXEL_PACK_BUFFER_BINDING = GL_PIXEL_PACK_BUFFER_BINDING,
				PIXEL_UNPACK_BUFFER_BINDING = GL_PIXEL_UNPACK_BUFFER_BINDING,
				POINT_FADE_THRESHOLD_SIZE = GL_POINT_FADE_THRESHOLD_SIZE,
				PRIMITIVE_RESTART_INDEX = GL_PRIMITIVE_RESTART_INDEX,
				PROGRAM_BINARY_FORMATS = GL_PROGRAM_BINARY_FORMATS,
				PROGRAM_PIPELINE_BINDING = GL_PROGRAM_PIPELINE_BINDING,
				PROGRAM_POINT_SIZE = GL_PROGRAM_POINT_SIZE,
				PROVOKING_VERTEX = GL_PROVOKING_VERTEX,
				POINT_SIZE = GL_POINT_SIZE,
				POINT_SIZE_GRANULARITY = GL_POINT_SIZE_GRANULARITY,
				POINT_SIZE_RANGE = GL_POINT_SIZE_RANGE,
				POLYGON_OFFSET_FACTOR = GL_POLYGON_OFFSET_FACTOR,
				POLYGON_OFFSET_UNITS = GL_POLYGON_OFFSET_UNITS,
				POLYGON_OFFSET_FILL = GL_POLYGON_OFFSET_FILL,
				POLYGON_OFFSET_LINE = GL_POLYGON_OFFSET_LINE,
				POLYGON_OFFSET_POINT = GL_POLYGON_OFFSET_POINT,
				POLYGON_SMOOTH = GL_POLYGON_SMOOTH,
				POLYGON_SMOOTH_HINT = GL_POLYGON_SMOOTH_HINT,
				READ_BUFFER = GL_READ_BUFFER,
				RENDERBUFFER_BINDING = GL_RENDERBUFFER_BINDING,
				SAMPLE_BUFFERS = GL_SAMPLE_BUFFERS,
				SAMPLE_COVERAGE_VALUE = GL_SAMPLE_COVERAGE_VALUE,
				SAMPLE_COVERAGE_INVERT = GL_SAMPLE_COVERAGE_INVERT,
				SAMPLER_BINDING = GL_SAMPLER_BINDING,
				SAMPLES = GL_SAMPLES,
				SCISSOR_BOX = GL_SCISSOR_BOX,
				SCISSOR_TEST = GL_SCISSOR_TEST,
				SHADER_COMPILER = GL_SHADER_COMPILER,
				SHADER_STORAGE_BUFFER_BINDING = GL_SHADER_STORAGE_BUFFER_BINDING,
				SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT,
				SHADER_STORAGE_BUFFER_START = GL_SHADER_STORAGE_BUFFER_START,
				SHADER_STORAGE_BUFFER_SIZE = GL_SHADER_STORAGE_BUFFER_SIZE,
				SMOOTH_LINE_WIDTH_RANGE = GL_SMOOTH_LINE_WIDTH_RANGE,
				SMOOTH_LINE_WIDTH_GRANULARITY = GL_SMOOTH_LINE_WIDTH_GRANULARITY,
				STENCIL_BACK_FAIL = GL_STENCIL_BACK_FAIL,
				STENCIL_BACK_FUNC = GL_STENCIL_BACK_FUNC,
				STENCIL_BACK_PASS_DEPTH_FAIL = GL_STENCIL_BACK_PASS_DEPTH_FAIL,
				STENCIL_BACK_PASS_DEPTH_PASS = GL_STENCIL_BACK_PASS_DEPTH_PASS,
				STENCIL_BACK_REF = GL_STENCIL_BACK_REF,
				STENCIL_BACK_VALUE_MASK = GL_STENCIL_BACK_VALUE_MASK,
				STENCIL_BACK_WRITEMASK = GL_STENCIL_BACK_WRITEMASK,
				STENCIL_CLEAR_VALUE = GL_STENCIL_CLEAR_VALUE,
				STENCIL_FAIL = GL_STENCIL_FAIL,
				STENCIL_FUNC = GL_STENCIL_FUNC,
				STENCIL_PASS_DEPTH_FAIL = GL_STENCIL_PASS_DEPTH_FAIL,
				STENCIL_PASS_DEPTH_PASS = GL_STENCIL_PASS_DEPTH_PASS,
				STENCIL_REF = GL_STENCIL_REF,
				STENCIL_TEST = GL_STENCIL_TEST,
				STENCIL_VALUE_MASK = GL_STENCIL_VALUE_MASK,
				STENCIL_WRITEMASK = GL_STENCIL_WRITEMASK,
				STEREO = GL_STEREO,
				SUBPIXEL_BITS = GL_SUBPIXEL_BITS,
				TEXTURE_BINDING_1D = GL_TEXTURE_BINDING_1D,
				TEXTURE_BINDING_1D_ARRAY = GL_TEXTURE_BINDING_1D_ARRAY,
				TEXTURE_BINDING_2D = GL_TEXTURE_BINDING_2D,
				TEXTURE_BINDING_2D_ARRAY = GL_TEXTURE_BINDING_2D_ARRAY,
				TEXTURE_BINDING_2D_MULTISAMPLE = GL_TEXTURE_BINDING_2D_MULTISAMPLE,
				TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,
				TEXTURE_BINDING_3D = GL_TEXTURE_BINDING_3D,
				TEXTURE_BINDING_BUFFER = GL_TEXTURE_BINDING_BUFFER,
				TEXTURE_BINDING_CUBE_MAP = GL_TEXTURE_BINDING_CUBE_MAP,
				TEXTURE_BINDING_RECTANGLE = GL_TEXTURE_BINDING_RECTANGLE,
				TEXTURE_COMPRESSION_HINT = GL_TEXTURE_COMPRESSION_HINT,
				TEXTURE_BUFFER_OFFSET_ALIGNMENT = GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT,
				TIMESTAMP = GL_TIMESTAMP,
				TRANSFORM_FEEDBACK_BUFFER_BINDING = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,
				TRANSFORM_FEEDBACK_BUFFER_START = GL_TRANSFORM_FEEDBACK_BUFFER_START,
				TRANSFORM_FEEDBACK_BUFFER_SIZE = GL_TRANSFORM_FEEDBACK_BUFFER_SIZE,
				UNIFORM_BUFFER_BINDING = GL_UNIFORM_BUFFER_BINDING,
				UNIFORM_BUFFER_OFFSET_ALIGNMENT = GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,
				UNIFORM_BUFFER_SIZE = GL_UNIFORM_BUFFER_SIZE,
				UNIFORM_BUFFER_START = GL_UNIFORM_BUFFER_START,
				UNPACK_ALIGNMENT = GL_UNPACK_ALIGNMENT,
				UNPACK_IMAGE_HEIGHT = GL_UNPACK_IMAGE_HEIGHT,
				UNPACK_LSB_FIRST = GL_UNPACK_LSB_FIRST,
				UNPACK_ROW_LENGTH = GL_UNPACK_ROW_LENGTH,
				UNPACK_SKIP_IMAGES = GL_UNPACK_SKIP_IMAGES,
				UNPACK_SKIP_PIXELS = GL_UNPACK_SKIP_PIXELS,
				UNPACK_SKIP_ROWS = GL_UNPACK_SKIP_ROWS,
				UNPACK_SWAP_BYTES = GL_UNPACK_SWAP_BYTES,
				VERTEX_ARRAY_BINDING = GL_VERTEX_ARRAY_BINDING,
				VERTEX_BINDING_DIVISOR = GL_VERTEX_BINDING_DIVISOR,
				VERTEX_BINDING_OFFSET = GL_VERTEX_BINDING_OFFSET,
				VERTEX_BINDING_STRIDE = GL_VERTEX_BINDING_STRIDE,
				MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET,
				MAX_VERTEX_ATTRIB_BINDINGS = GL_MAX_VERTEX_ATTRIB_BINDINGS,
				VIEWPORT = GL_VIEWPORT,
				VIEWPORT_BOUNDS_RANGE = GL_VIEWPORT_BOUNDS_RANGE,
				VIEWPORT_INDEX_PROVOKING_VERTEX = GL_VIEWPORT_INDEX_PROVOKING_VERTEX,
				VIEWPORT_SUBPIXEL_BITS = GL_VIEWPORT_SUBPIXEL_BITS,
				MAX_ELEMENT_INDEX = GL_MAX_ELEMENT_INDEX
			};

			enum class CullFaceMode : unsigned short int
			{
				FRONT = GL_FRONT,
				BACK = GL_BACK,
				FRONT_AND_BACK = GL_FRONT_AND_BACK
			};

			enum class FrontFaceMode : unsigned short int
			{
				CW = GL_CW,
				CCW = GL_CCW
			};

			enum class InfoGL : unsigned short int
			{
				VENDOR = GL_VENDOR,
				RENDERER = GL_RENDERER,
				VERSION = GL_VERSION,
				SHADING_LANGUAGE_VERSION = GL_SHADING_LANGUAGE_VERSION
			};

			using ExtensionsGL = unsigned short int;
			static constexpr ExtensionsGL EXTENSIONS = GL_EXTENSIONS;

			enum class DepthFunctionCondition : unsigned short int
			{
				NEVER = GL_NEVER,
				LESS = GL_LESS,
				EQUAL = GL_EQUAL,
				LEQUAL = GL_LEQUAL,
				GREATER = GL_GREATER,
				NOTEQUAL = GL_NOTEQUAL,
				GEQUAL = GL_GEQUAL,
				ALWAYS = GL_ALWAYS
			};

			enum class ErrorGL : unsigned short int
			{
				NO_ERROR = GL_NO_ERROR,
				INVALID_ENUM = GL_INVALID_ENUM,
				INVALID_VALUE = GL_INVALID_VALUE,
				INVALID_OPERATION = GL_INVALID_OPERATION,
				INVALID_FRAMEBUFFER_OPERATION = GL_INVALID_FRAMEBUFFER_OPERATION,
				OUT_OF_MEMORY = GL_OUT_OF_MEMORY,
				STACK_UNDERFLOW = GL_STACK_UNDERFLOW,
				STACK_OVERFLOW = GL_STACK_OVERFLOW
			};

			enum class PolygonMode : unsigned short int
			{
				POINT = GL_POINT,
				LINE = GL_LINE,
				FILL = GL_FILL
			};

			enum class TextureTarget : unsigned short int
			{
				TEXTURE_1D = GL_TEXTURE_1D,
				TEXTURE_2D = GL_TEXTURE_2D,
				TEXTURE_3D = GL_TEXTURE_3D,
				TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY,
				TEXTURE_2D_ARRAY = GL_TEXTURE_2D_ARRAY,
				TEXTURE_RECTANGLE = GL_TEXTURE_RECTANGLE,
				TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP,
				TEXTURE_CUBE_MAP_ARRAY = GL_TEXTURE_CUBE_MAP_ARRAY,
				TEXTURE_BUFFER = GL_TEXTURE_BUFFER,
				TEXTURE_2D_MULTISAMPLE = GL_TEXTURE_2D_MULTISAMPLE,
				TEXTURE_2D_MULTISAMPLE_ARRAY = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
			};

			enum class MipmapTarget : unsigned short int
			{
				TEXTURE_1D = GL_TEXTURE_1D,
				TEXTURE_2D = GL_TEXTURE_2D,
				TEXTURE_3D = GL_TEXTURE_3D,
				TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY,
				TEXTURE_2D_ARRAY = GL_TEXTURE_2D_ARRAY,
				TEXTURE_CUBE_MAP = GL_TEXTURE_CUBE_MAP,
				TEXTURE_CUBE_MAP_ARRAY = GL_TEXTURE_CUBE_MAP_ARRAY
			};

			enum class TextureTypeTarget : unsigned short int
			{
				TEXTURE_2D = GL_TEXTURE_2D,
				PROXY_TEXTURE_2D = GL_PROXY_TEXTURE_2D,
				TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY,
				PROXY_TEXTURE_1D_ARRAY = GL_PROXY_TEXTURE_1D_ARRAY,
				TEXTURE_RECTANGLE = GL_TEXTURE_RECTANGLE,
				PROXY_TEXTURE_RECTANGLE = GL_PROXY_TEXTURE_RECTANGLE,
				TEXTURE_CUBE_MAP_POSITIVE_X = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
				TEXTURE_CUBE_MAP_NEGATIVE_X = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
				TEXTURE_CUBE_MAP_POSITIVE_Y = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
				TEXTURE_CUBE_MAP_NEGATIVE_Y = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
				TEXTURE_CUBE_MAP_POSITIVE_Z = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
				TEXTURE_CUBE_MAP_NEGATIVE_Z = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
				PROXY_TEXTURE_CUBE_MAP = GL_PROXY_TEXTURE_CUBE_MAP
			};

			enum class PixelFormat : unsigned short int
			{
				RED = GL_RED,
				RG = GL_RG,
				RGB = GL_RGB,
				BGR = GL_BGR,
				RGBA = GL_RGBA,
				BGRA = GL_BGRA,
				RED_INTEGER = GL_RED_INTEGER,
				RG_INTEGER = GL_RG_INTEGER,
				RGB_INTEGER = GL_RGB_INTEGER,
				BGR_INTEGER = GL_BGR_INTEGER,
				RGBA_INTEGER = GL_RGBA_INTEGER,
				BGRA_INTEGER = GL_BGRA_INTEGER,
				STENCIL_INDEX = GL_STENCIL_INDEX,
				DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
				DEPTH_STENCIL = GL_DEPTH_STENCIL
			};

			enum class PixelInternalFormat : unsigned short int
			{
				DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
				DEPTH_STENCIL = GL_DEPTH_STENCIL,
				RED = GL_RED,
				RG = GL_RG,
				RGB = GL_RGB,
				RGBA = GL_RGBA,
				R8 = GL_R8,
				R8_SNORM = GL_R8_SNORM,
				R16 = GL_R16,
				R16_SNORM = GL_R16_SNORM,
				RG8 = GL_RG8,
				RG8_SNORM = GL_RG8_SNORM,
				RG16 = GL_RG16,
				RG16_SNORM = GL_RG16_SNORM,
				R3_G3_B2 = GL_R3_G3_B2,
				RGB4 = GL_RGB4,
				RGB5 = GL_RGB5,
				RGB8 = GL_RGB8,
				RGB8_SNORM = GL_RGB8_SNORM,
				RGB10 = GL_RGB10,
				RGB12 = GL_RGB12,
				RGB16_SNORM = GL_RGB16_SNORM,
				RGBA2 = GL_RGBA2,
				RGBA4 = GL_RGBA4,
				RGB5_A1 = GL_RGB5_A1,
				RGBA8 = GL_RGBA8,
				RGBA8_SNORM = GL_RGBA8_SNORM,
				RGB10_A2 = GL_RGB10_A2,
				RGB10_A2UI = GL_RGB10_A2UI,
				RGBA12 = GL_RGBA12,
				RGBA16 = GL_RGBA16,
				SRGB8 = GL_SRGB8,
				SRGB8_ALPHA8 = GL_SRGB8_ALPHA8,
				R16F = GL_R16F,
				RG16F = GL_RG16F,
				RGB16F = GL_RGB16F,
				RGBA16F = GL_RGBA16F,
				R32F = GL_R32F,
				RG32F = GL_RG32F,
				RGB32F = GL_RGB32F,
				RGBA32F = GL_RGBA32F,
				R11F_G11F_B10F = GL_R11F_G11F_B10F,
				RGB9_E5 = GL_RGB9_E5,
				R8I = GL_R8I,
				R8UI = GL_R8UI,
				R16I = GL_R16I,
				R16UI = GL_R16UI,
				R32I = GL_R32I,
				R32UI = GL_R32UI,
				RG8I = GL_RG8I,
				RG8UI = GL_RG8UI,
				RG16I = GL_RG16I,
				RG16UI = GL_RG16UI,
				RG32I = GL_RG32I,
				RG32UI = GL_RG32UI,
				RGB8I = GL_RGB8I,
				RGB8UI = GL_RGB8UI,
				RGB16I = GL_RGB16I,
				RGB16UI = GL_RGB16UI,
				RGB32I = GL_RGB32I,
				RGB32UI = GL_RGB32UI,
				RGBA8I = GL_RGBA8I,
				RGBA8UI = GL_RGBA8UI,
				RGBA16I = GL_RGBA16I,
				RGBA16UI = GL_RGBA16UI,
				RGBA32I = GL_RGBA32I,
				RGBA32UI = GL_RGBA32UI,
				COMPRESSED_RED = GL_COMPRESSED_RED,
				COMPRESSED_RG = GL_COMPRESSED_RG,
				COMPRESSED_RGB = GL_COMPRESSED_RGB,
				COMPRESSED_RGBA = GL_COMPRESSED_RGBA,
				COMPRESSED_SRGB = GL_COMPRESSED_SRGB,
				COMPRESSED_SRGB_ALPHA = GL_COMPRESSED_SRGB_ALPHA,
				COMPRESSED_RED_RGTC1 = GL_COMPRESSED_RED_RGTC1,
				COMPRESSED_SIGNED_RED_RGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
				COMPRESSED_RG_RGTC2 = GL_COMPRESSED_RG_RGTC2,
				COMPRESSED_SIGNED_RG_RGTC2 = GL_COMPRESSED_SIGNED_RG_RGTC2,
				COMPRESSED_RGBA_BPTC_UNORM = GL_COMPRESSED_RGBA_BPTC_UNORM,
				COMPRESSED_SRGB_ALPHA_BPTC_UNORM = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
				COMPRESSED_RGB_BPTC_SIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
				COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
			};

			enum class TextureParameter : unsigned short int
			{
				DEPTH_STENCIL_TEXTURE_MODE = GL_DEPTH_STENCIL_TEXTURE_MODE,
				TEXTURE_BASE_LEVEL = GL_TEXTURE_BASE_LEVEL,
				TEXTURE_COMPARE_FUNC = GL_TEXTURE_COMPARE_FUNC,
				TEXTURE_COMPARE_MODE = GL_TEXTURE_COMPARE_MODE,
				TEXTURE_LOD_BIAS = GL_TEXTURE_LOD_BIAS,
				TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER,
				TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER,
				TEXTURE_MIN_LOD = GL_TEXTURE_MIN_LOD,
				TEXTURE_MAX_LOD = GL_TEXTURE_MAX_LOD,
				TEXTURE_MAX_LEVEL = GL_TEXTURE_MAX_LEVEL,
				TEXTURE_SWIZZLE_R = GL_TEXTURE_SWIZZLE_R,
				TEXTURE_SWIZZLE_G = GL_TEXTURE_SWIZZLE_G,
				TEXTURE_SWIZZLE_B = GL_TEXTURE_SWIZZLE_B,
				TEXTURE_SWIZZLE_A = GL_TEXTURE_SWIZZLE_A,
				TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S,
				TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T,
				TEXTURE_WRAP_R = GL_TEXTURE_WRAP_R
			};

			enum class ProgramParameter : unsigned short int
			{
				DELETE_STATUS = GL_DELETE_STATUS,
				LINK_STATUS = GL_LINK_STATUS,
				VALIDATE_STATUS = GL_VALIDATE_STATUS,
				INFO_LOG_LENGTH = GL_INFO_LOG_LENGTH,
				ATTACHED_SHADERS = GL_ATTACHED_SHADERS,
				ACTIVE_ATOMIC_COUNTER_BUFFERS = GL_ACTIVE_ATOMIC_COUNTER_BUFFERS,
				ACTIVE_ATTRIBUTES = GL_ACTIVE_ATTRIBUTES,
				ACTIVE_ATTRIBUTE_MAX_LENGTH = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
				ACTIVE_UNIFORMS = GL_ACTIVE_UNIFORMS,
				ACTIVE_UNIFORM_BLOCKS = GL_ACTIVE_UNIFORM_BLOCKS,
				ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,
				ACTIVE_UNIFORM_MAX_LENGTH = GL_ACTIVE_UNIFORM_MAX_LENGTH,
				COMPUTE_WORK_GROUP_SIZE = GL_COMPUTE_WORK_GROUP_SIZE,
				PROGRAM_BINARY_LENGTH = GL_PROGRAM_BINARY_LENGTH,
				TRANSFORM_FEEDBACK_BUFFER_MODE = GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
				TRANSFORM_FEEDBACK_VARYINGS = GL_TRANSFORM_FEEDBACK_VARYINGS,
				TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,
				GEOMETRY_VERTICES_OUT = GL_GEOMETRY_VERTICES_OUT,
				GEOMETRY_INPUT_TYPE = GL_GEOMETRY_INPUT_TYPE,
				GEOMETRY_OUTPUT_TYPE = GL_GEOMETRY_OUTPUT_TYPE
			};

			enum class ShaderParameter : unsigned short int
			{
				SHADER_TYPE = GL_SHADER_TYPE,
				DELETE_STATUS = GL_DELETE_STATUS,
				COMPILE_STATUS = GL_COMPILE_STATUS,
				INFO_LOG_LENGTH = GL_INFO_LOG_LENGTH,
				SHADER_SOURCE_LENGTH = GL_SHADER_SOURCE_LENGTH
			};

			enum class PixelDataType : unsigned short int
			{
				UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
				BYTE = GL_BYTE,
				UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
				SHORT = GL_SHORT,
				UNSIGNED_INT = GL_UNSIGNED_INT,
				INT = GL_INT,
				FLOAT = GL_FLOAT,
				UNSIGNED_BYTE_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
				UNSIGNED_BYTE_2_3_3_REV = GL_UNSIGNED_BYTE_2_3_3_REV,
				UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
				UNSIGNED_SHORT_5_6_5_REV = GL_UNSIGNED_SHORT_5_6_5_REV,
				UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
				UNSIGNED_SHORT_4_4_4_4_REV = GL_UNSIGNED_SHORT_4_4_4_4_REV,
				UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
				UNSIGNED_SHORT_1_5_5_5_REV = GL_UNSIGNED_SHORT_1_5_5_5_REV,
				UNSIGNED_INT_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
				UNSIGNED_INT_8_8_8_8_REV = GL_UNSIGNED_INT_8_8_8_8_REV,
				UNSIGNED_INT_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
				UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
			};

			enum class TextureUnit : unsigned short int
			{
				TEXTURE0 = GL_TEXTURE0,
				TEXTURE1 = GL_TEXTURE1,
				TEXTURE2 = GL_TEXTURE2,
				TEXTURE3 = GL_TEXTURE3,
				TEXTURE4 = GL_TEXTURE4,
				TEXTURE5 = GL_TEXTURE5,
				TEXTURE6 = GL_TEXTURE6,
				TEXTURE7 = GL_TEXTURE7,
				TEXTURE8 = GL_TEXTURE8,
				TEXTURE9 = GL_TEXTURE9,
				TEXTURE10 = GL_TEXTURE10,
				TEXTURE11 = GL_TEXTURE11,
				TEXTURE12 = GL_TEXTURE12,
				TEXTURE13 = GL_TEXTURE13,
				TEXTURE14 = GL_TEXTURE14,
				TEXTURE15 = GL_TEXTURE15,
				TEXTURE16 = GL_TEXTURE16,
				TEXTURE17 = GL_TEXTURE17,
				TEXTURE18 = GL_TEXTURE18,
				TEXTURE19 = GL_TEXTURE19,
				TEXTURE20 = GL_TEXTURE20,
				TEXTURE21 = GL_TEXTURE21,
				TEXTURE22 = GL_TEXTURE22,
				TEXTURE23 = GL_TEXTURE23,
				TEXTURE24 = GL_TEXTURE24,
				TEXTURE25 = GL_TEXTURE25,
				TEXTURE26 = GL_TEXTURE26,
				TEXTURE27 = GL_TEXTURE27,
				TEXTURE28 = GL_TEXTURE28,
				TEXTURE29 = GL_TEXTURE29,
				TEXTURE30 = GL_TEXTURE30,
				TEXTURE31 = GL_TEXTURE31,
			};

			enum class BlendingFactor : unsigned short int
			{
				ZERO = GL_ZERO,
				ONE = GL_ONE,
				SRC_COLOR = GL_SRC_COLOR,
				ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
				DST_COLOR = GL_DST_COLOR,
				ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
				SRC_ALPHA = GL_SRC_ALPHA,
				ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
				DST_ALPHA = GL_DST_ALPHA,
				ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
				CONSTANT_COLOR = GL_CONSTANT_COLOR,
				ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
				CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
				ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA,
				SRC_ALPHA_SATURATE = GL_SRC_ALPHA_SATURATE,
				SRC1_COLOR = GL_SRC1_COLOR,
				ONE_MINUS_SRC1_COLOR = GL_ONE_MINUS_SRC1_COLOR,
				SRC1_ALPHA = GL_SRC1_ALPHA,
				ONE_MINUS_SRC1_ALPHA = GL_ONE_MINUS_SRC1_ALPHA,
			};

			enum class ContextFlag : unsigned short int
			{
				CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT,
				CONTEXT_FLAG_DEBUG_BIT = GL_CONTEXT_FLAG_DEBUG_BIT,
				CONTEXT_FLAG_ROBUST_ACCESS_BIT = GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT,
				CONTEXT_FLAG_NO_ERROR_BIT = GL_CONTEXT_FLAG_NO_ERROR_BIT
			};

			enum class SourceDebugMessage : unsigned short int
			{
				DEBUG_SOURCE_API = GL_DEBUG_SOURCE_API,
				DEBUG_SOURCE_WINDOW_SYSTEM = GL_DEBUG_SOURCE_WINDOW_SYSTEM,
				DEBUG_SOURCE_SHADER_COMPILER = GL_DEBUG_SOURCE_SHADER_COMPILER,
				DEBUG_SOURCE_THIRD_PARTY = GL_DEBUG_SOURCE_THIRD_PARTY,
				DEBUG_SOURCE_APPLICATION = GL_DEBUG_SOURCE_APPLICATION,
				DEBUG_SOURCE_OTHER = GL_DEBUG_SOURCE_OTHER,
				DONT_CARE = GL_DONT_CARE
			};

			enum class TypeDebugMessage : unsigned short int
			{
				DEBUG_TYPE_ERROR = GL_DEBUG_TYPE_ERROR,
				DEBUG_TYPE_DEPRECATED_BEHAVIOR = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
				DEBUG_TYPE_UNDEFINED_BEHAVIOR = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
				DEBUG_TYPE_PORTABILITY = GL_DEBUG_TYPE_PORTABILITY,
				DEBUG_TYPE_PERFORMANCE = GL_DEBUG_TYPE_PERFORMANCE,
				DEBUG_TYPE_MARKER = GL_DEBUG_TYPE_MARKER,
				DEBUG_TYPE_PUSH_GROUP = GL_DEBUG_TYPE_PUSH_GROUP,
				DEBUG_TYPE_POP_GROUP = GL_DEBUG_TYPE_POP_GROUP,
				DEBUG_TYPE_OTHER = GL_DEBUG_TYPE_OTHER,
				DONT_CARE = GL_DONT_CARE
			};

			enum class SeverityDebugMessage : unsigned short int
			{
				DEBUG_SEVERITY_LOW = GL_DEBUG_SEVERITY_LOW,
				DEBUG_SEVERITY_MEDIUM = GL_DEBUG_SEVERITY_MEDIUM,
				DEBUG_SEVERITY_HIGH = GL_DEBUG_SEVERITY_HIGH,
				DEBUG_SEVERITY_NOTIFICATION = GL_DEBUG_SEVERITY_NOTIFICATION,
				DONT_CARE = GL_DONT_CARE
			};
		}
	} // namespace renderer
} // namespace ece

#endif // RENDERER_ENUM_HPP
