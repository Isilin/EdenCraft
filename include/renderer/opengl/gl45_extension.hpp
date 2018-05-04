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


#ifndef GL45_EXTENSION_HPP
#define GL45_EXTENSION_HPP

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

namespace ece
{
    using utility::indexing::Version;
	using renderer::opengl::OpenGLExtensionException;
}

inline void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index);
inline void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index);
inline void glNamedBufferData(GLuint buffer, GLsizei size, const GLvoid *data, GLenum usage);
inline void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizei size, const GLvoid *data);
inline void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizei length, GLbitfield access);
inline void * glMapNamedBuffer(GLuint buffer, GLenum access);
inline void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizei length);
inline GLboolean glUnmapNamedBuffer(GLuint buffer);
inline void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizei size);
inline void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params);
inline void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params);
inline void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizei size, GLvoid *data);
inline void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, GLvoid ** params);
inline void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
inline void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params);
inline void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
inline void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
inline void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
inline void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
inline void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
inline void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
inline void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
inline void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
inline void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
inline void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
inline void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
inline void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer);
inline void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param);
inline void glTextureParameteri(GLuint texture, GLenum pname, GLint param);
inline void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param);
inline void glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param);
inline void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params);
inline void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params);
inline void glGenerateTextureMipmap(GLuint texture);
inline void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params);
inline void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params);
inline void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params);
inline void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params);
inline void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params);
inline void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params);
inline void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels);
inline void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels);
inline void glGetnCompressedTexImage(GLenum target, GLint level, GLsizei bufSize, GLvoid *pixels);
inline void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, GLvoid *pixels);
inline void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid *data);
inline void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode);
inline void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
inline void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf);
inline void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs);
inline void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
inline void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
inline void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
inline void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
inline void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
inline void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
inline void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
inline void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
inline void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
inline GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target);
inline void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
inline void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params);
inline GLenum glGetGraphicsResetStatus();
inline void glCreateBuffers(GLsizei n, GLuint *buffers);
inline void glNamedBufferStorage(GLuint buffer, GLsizei size, const GLvoid * data, GLbitfield flags);
inline void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const GLvoid *data);
inline void glCreateProgramPipelines(GLsizei n, GLuint *pipelines);
inline void glMemoryBarrierByRegion(GLbitfield barriers);
inline void glBindTextureUnit(GLuint unit, GLuint texture);
inline void glCreateTextures(GLenum target, GLsizei n, GLuint *textures);
inline void glCreateSamplers(GLsizei n, GLuint *samplers);
inline void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizei size);
inline void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, GLvoid *pixels);
inline void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, GLvoid *pixels);
inline void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
inline void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
inline void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
inline void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
inline void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
inline void glCreateFramebuffers(GLsizei n, GLuint *ids);
inline void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param);
inline void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param);
inline void glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers);
inline void glTextureBarrier();
inline void glCreateVertexArrays(GLsizei n, GLuint *arrays);
inline void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer);
inline void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
inline void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
inline void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
inline void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
inline void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
inline void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
inline void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor);
inline void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param);
inline void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
inline void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
inline void glCreateTransformFeedbacks(GLsizei n, GLuint *ids);
inline void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizei size);
inline void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer);
inline void glClipControl(GLenum origin, GLenum depth);
inline void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
inline void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
inline void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param);
inline void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param);
inline void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);

/**
 * fn CALLGL45(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.5 extension and call it.
 */
#define CALLGL45(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 5 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy();

/**
 * fn R_CALLGL45(SIGNATURE, NAME)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 4.5 extension and call it.
 */
#define R_CALLGL45(SIGNATURE, NAME) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 5 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL45_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.5 extension and call it.
 */
#define CALLGL45_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 5 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	proxy(__VA_ARGS__);

/**
 * fn R_CALLGL45_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 4.5 extension and call it.
 */
#define R_CALLGL45_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::renderer::opengl::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 4, 5 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl45_extension.inl"

#endif // GL45_EXTENSION_HPP
