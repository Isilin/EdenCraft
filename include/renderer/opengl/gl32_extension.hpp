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


#ifndef GL32_EXTENSION_HPP
#define GL32_EXTENSION_HPP

#include <GL/glcorearb.h>

#include "utility/indexing/version.hpp"
#include "renderer/opengl/extension_loader.hpp"
#include "renderer/opengl/opengl_exception.hpp"

inline GLenum glGetError();
inline void glVertexAttrib1f(GLuint index, GLfloat v0);
inline void glVertexAttrib1s(GLuint index, GLshort v0);
inline void glVertexAttrib1d(GLuint index, GLdouble v0);
inline void glVertexAttribI1i(GLuint index, GLint v0);
inline void glVertexAttribI1ui(GLuint index, GLuint v0);
inline void glVertexAttrib2f(GLuint index, GLfloat v0,	GLfloat v1);
inline void glVertexAttrib2s(GLuint index, GLshort v0,	GLshort v1);
inline void glVertexAttrib2d(GLuint index, GLdouble v0, GLdouble v1);
inline void glVertexAttribI2i(GLuint index, GLint v0, GLint v1);
inline void glVertexAttribI2ui(GLuint index, GLuint v0, GLuint v1);
inline void glVertexAttrib3f(GLuint index, GLfloat v0,	GLfloat v1,	GLfloat v2);
inline void glVertexAttrib3s(GLuint index, GLshort v0,	GLshort v1,	GLshort v2);
inline void glVertexAttrib3d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2);
inline void glVertexAttribI3i(GLuint index, GLint v0, GLint v1, GLint v2);
inline void glVertexAttribI3ui(GLuint index, GLuint v0, GLuint v1, GLuint v2);
inline void glVertexAttrib4f(GLuint index, GLfloat v0,	GLfloat v1,	GLfloat v2,	GLfloat v3);
inline void glVertexAttrib4s(GLuint index, GLshort v0, GLshort v1,GLshort v2, GLshort v3);
inline void glVertexAttrib4d(GLuint index, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
inline void glVertexAttrib4Nub(GLuint index, GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3);
inline void glVertexAttribI4i(GLuint index, GLint v0, GLint v1, GLint v2, GLint v3);
inline void glVertexAttribI4ui(GLuint index, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
inline void glVertexAttrib1fv(GLuint index, const GLfloat *v);
inline void glVertexAttrib1sv(GLuint index, const GLshort *v);
inline void glVertexAttrib1dv(GLuint index, const GLdouble *v);
inline void glVertexAttribI1iv(GLuint index, const GLint *v);
inline void glVertexAttribI1uiv(GLuint index, const GLuint *v);
inline void glVertexAttrib2fv(GLuint index, const GLfloat *v);
inline void glVertexAttrib2sv(GLuint index, const GLshort *v);
inline void glVertexAttrib2dv(GLuint index, const GLdouble *v);
inline void glVertexAttribI2iv(GLuint index, const GLint *v);
inline void glVertexAttribI2uiv(GLuint index, const GLuint *v);
inline void glVertexAttrib3fv(GLuint index, const GLfloat *v);
inline void glVertexAttrib3sv(GLuint index, const GLshort *v);
inline void glVertexAttrib3dv(GLuint index, const GLdouble *v);
inline void glVertexAttribI3iv(GLuint index, const GLint *v);
inline void glVertexAttribI3uiv(GLuint index, const GLuint *v);
inline void glVertexAttrib4fv(GLuint index, const GLfloat *v);
inline void glVertexAttrib4sv(GLuint index, const GLshort *v);
inline void glVertexAttrib4dv(GLuint index, const GLdouble *v);
inline void glVertexAttrib4iv(GLuint index, const GLint *v);
inline void glVertexAttrib4bv(GLuint index, const GLbyte *v);
inline void glVertexAttrib4ubv(GLuint index, const GLubyte *v);
inline void glVertexAttrib4usv(GLuint index, const GLushort *v);
inline void glVertexAttrib4uiv(GLuint index, const GLuint *v);
inline void glVertexAttrib4Nbv(GLuint index, const GLbyte *v);
inline void glVertexAttrib4Nsv(GLuint index, const GLshort *v);
inline void glVertexAttrib4Niv(GLuint index, const GLint *v);
inline void glVertexAttrib4Nubv(GLuint index, const GLubyte *v);
inline void glVertexAttrib4Nusv(GLuint index, const GLushort *v);
inline void glVertexAttrib4Nuiv(GLuint index, const GLuint *v);
inline void glVertexAttribI4bv(GLuint index, const GLbyte *v);
inline void glVertexAttribI4ubv(GLuint index, const GLubyte *v);
inline void glVertexAttribI4sv(GLuint index, const GLshort *v);
inline void glVertexAttribI4usv(GLuint index, const GLushort * v);
inline void glVertexAttribI4iv(GLuint index, const GLint * v);
inline void glVertexAttribI4uiv(GLuint index, const GLuint * v);
inline void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
inline void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
inline void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
inline void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
inline void glEnableVertexAttribArray(GLuint index);
inline void glDisableVertexAttribArray(GLuint index);
inline void glEnable(GLenum cap);
inline void glDisable(GLenum cap);
inline void glEnablei(GLenum cap, GLuint index);
inline void glDisablei(GLenum cap, GLuint index);
inline void glPrimitiveRestartIndex(GLuint index);
inline void glDrawArrays(GLenum mode, GLint first, GLsizei count);
inline void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
inline void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
inline void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount);
inline void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
inline void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
inline void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei primcount);
inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex);
inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid * indices, GLint basevertex);
inline void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount, GLint basevertex);
inline void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei drawcount, const GLint * basevertex);
inline void glGenBuffers(GLsizei n, GLuint * buffers);
inline void glDeleteBuffers(GLsizei n, const GLuint * buffers);
inline void glDeleteBuffers(GLsizei n, const GLuint * buffers);
inline void glBindBuffer(GLenum target, GLuint buffer);
inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
inline void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
inline void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
inline void * glMapBuffer(GLenum target, GLenum access);
inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
inline GLboolean glUnmapBuffer(GLenum target);
inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
inline void glGenVertexArrays(GLsizei n, GLuint *arrays);
inline void glDeleteVertexArrays(GLsizei n, const GLuint *arrays);
inline void glBindVertexArray(GLuint array);
inline GLboolean glIsBuffer(GLuint buffer);
inline void glGetBufferParameteriv(GLenum target, GLenum value, GLint * data);
inline void glGetBufferParameteri64v(GLenum target, GLenum value, GLint64 * data);
inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
inline void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
inline GLboolean glIsVertexArray(GLuint array);
inline void glDepthRange(GLdouble nearVal, GLdouble farVal);
inline void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
inline void glClampColor(GLenum target, GLenum clamp);
inline void glProvokingVertex(GLenum provokeMode);
inline void glBeginConditionalRender(GLuint id, GLenum mode);
inline void glEndConditionalRender();
inline void glBeginTransformFeedback(GLenum primitiveMode);
inline void glEndTransformFeedback();
inline void glBeginQuery(GLenum target, GLuint id);
inline void glEndQuery(GLenum target);
inline void glGenQueries(GLsizei n, GLuint * ids);
inline void glDeleteQueries(GLsizei n, const GLuint * ids);
inline GLboolean glIsQuery(GLuint id);
inline void glGetQueryiv(GLenum target, GLenum pname, GLint * params);
inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params);
inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params);
inline void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params);
inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params);
inline GLuint glCreateShader(GLenum shaderType);
inline void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length);
inline void glCompileShader(GLuint shader);
inline void glDeleteShader(GLuint shader);
inline GLuint glCreateProgram();
inline void glAttachShader(GLuint program, GLuint shader);
inline void glDetachShader(GLuint program, GLuint shader);
inline void glLinkProgram(GLuint program);
inline void glUseProgram(GLuint program);
inline void glDeleteProgram(GLuint program);
inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
inline GLint glGetAttribLocation(GLuint program, const GLchar *name);
inline void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name);
inline GLint glGetUniformLocation(GLuint program, const GLchar *name);
inline GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName);
inline void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
inline void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
inline void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar **uniformNames, GLuint *uniformIndices);
inline void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
inline void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
inline void glUniform1f(GLint location, GLfloat v0);
inline void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
inline void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
inline void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
inline void glUniform1i(GLint location, GLint v0);
inline void glUniform2i(GLint location, GLint v0, GLint v1);
inline void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
inline void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
inline void glUniform1ui(GLint location, GLuint v0);
inline void glUniform2ui(GLint location, GLuint v0, GLuint v1);
inline void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
inline void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
inline void glUniform1fv(GLint location, GLsizei count, const GLfloat *value);
inline void glUniform2fv(GLint location, GLsizei count, const GLfloat *value);
inline void glUniform3fv(GLint location, GLsizei count, const GLfloat *value);
inline void glUniform4fv(GLint location, GLsizei count, const GLfloat *value);
inline void glUniform1iv(GLint location, GLsizei count, const GLint *value);
inline void glUniform2iv(GLint location, GLsizei count, const GLint *value);
inline void glUniform3iv(GLint location, GLsizei count, const GLint *value);
inline void glUniform4iv(GLint location, GLsizei count, const GLint *value);
inline void glUniform1uiv(GLint location, GLsizei count, const GLuint *value);
inline void glUniform2uiv(GLint location, GLsizei count, const GLuint *value);
inline void glUniform3uiv(GLint location, GLsizei count, const GLuint *value);
inline void glUniform4uiv(GLint location, GLsizei count, const GLuint *value);
inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
inline void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar **varyings, GLenum bufferMode);
inline void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
inline void glValidateProgram(GLuint program);
inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params);
inline void glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar * name);
inline GLint glGetFragDataLocation(GLuint program, const GLchar * name);
inline GLboolean glIsShader(GLuint shader);
inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params);
inline void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
inline void glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
inline void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
inline void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params);
inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params);
inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params);
inline void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params);
inline void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params);
inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer);
inline void glGetUniformfv(GLuint program, GLint location, GLfloat *params);
inline void glGetUniformiv(GLuint program, GLint location, GLint *params);
inline void glGetUniformuiv(GLuint program, GLint location, GLuint *params);
inline GLboolean glIsProgram(GLuint program);
inline void glGetProgramInfoLog(GLuint program, GLsizei maxLength, GLsizei *length, GLchar *infoLog);
inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val);
inline void glPointSize(GLfloat size);
inline void glPointParameterf(GLenum pname, GLfloat param);
inline void glPointParameteri(GLenum pname, GLint param);
inline void glPointParameterfv(GLenum pname, const GLfloat * params);
inline void glPointParameteriv(GLenum pname, const GLint * params);
inline void glLineWidth(GLfloat width);
inline void glFrontFace(GLenum mode);
inline void glCullFace(GLenum mode);
inline void glPolygonMode(GLenum face, GLenum mode);
inline void glPolygonOffset(GLfloat factor, GLfloat units);
inline void glPixelStoref(GLenum pname, GLfloat param);
inline void glPixelStorei(GLenum pname, GLint param);
inline void glActiveTexture(GLenum texture);
inline void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data);
inline void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data);
inline void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * data);
inline void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
inline void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
inline void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
inline void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
inline void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
inline void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
inline void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
inline void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
inline void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
inline void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
inline void glTexBuffer(GLenum target, GLenum internalFormat, GLuint buffer);
inline void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
inline void glTexParameteri(GLenum target, GLenum pname, GLint param);
inline void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
inline void glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
inline void glTexParameterIiv(GLenum target, GLenum pname, const GLint * params);
inline void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params);
inline void glGenerateMipmap(GLenum target);
inline void glBindTexture(GLenum target, GLuint texture);
inline void glDeleteTextures(GLsizei n, const GLuint * textures);
inline void glGenTextures(GLsizei n, GLuint * textures);
inline void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
inline void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
inline void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params);
inline void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params);
inline void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params);
inline void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params);
inline void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
inline void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * pixels);
inline GLboolean glIsTexture(GLuint texture);
inline void glHint(GLenum target, GLenum mode);
inline void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data);
inline void glReadBuffer(GLenum mode);
inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
inline void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
inline void glSampleCoverage(GLfloat value, GLboolean invert);
inline void glSampleMaski(GLuint maskNumber, GLbitfield mask);
inline void glStencilFunc(GLenum func, GLint ref, GLuint mask);
inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
inline void glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass);
inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
inline void glDepthFunc(GLenum func);
inline void glBlendEquation(GLenum mode);
inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
inline void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
inline void glBlendFunc(GLenum sfactor, GLenum dfactor);
inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
inline void glLogicOp(GLenum opcode);
inline void glDrawBuffer(GLenum buf);
inline void glDrawBuffers(GLsizei n, const GLenum *bufs);
inline void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
inline void glColorMaski(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
inline void glDepthMask(GLboolean flag);
inline void glStencilMask(GLuint mask);
inline void glStencilMaskSeparate(GLenum face, GLuint mask);
inline void glClear(GLbitfield mask);
inline void glClearColor(GLfloat red, 	GLfloat green, GLfloat blue, GLfloat alpha);
inline void glClearDepth(GLdouble depth);
inline void glClearStencil(GLint s);
inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value);
inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value);
inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value);
inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
inline void glBindFramebuffer(GLenum target, GLuint framebuffer);
inline void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers);
inline void glGenFramebuffers(GLsizei n, GLuint *ids);
inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
inline void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers);
inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers);
inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
inline void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
inline void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);
inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
inline GLenum glCheckFramebufferStatus(GLenum target);
inline GLboolean glIsFramebuffer(GLuint framebuffer);
inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params);
inline GLboolean glIsRenderbuffer(GLuint renderbuffer);
inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params);
inline void glFlush();
inline void glFinish();
inline GLsync glFenceSync(GLenum condition, GLbitfield flags);
inline void glDeleteSync(GLsync sync);
inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
inline void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
inline GLboolean glIsSync(GLsync sync);
inline void glGetBooleanv(GLenum pname, GLboolean * data);
inline void glGetDoublev(GLenum pname, GLdouble * data);
inline void glGetFloatv(GLenum pname, GLfloat * data);
inline void glGetIntegerv(GLenum pname, GLint * data);
inline void glGetInteger64v(GLenum pname, GLint64 * data);
inline void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data);
inline void glGetIntegeri_v(GLenum target, GLuint index, GLint * data);
inline void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data);
inline GLboolean glIsEnabled(GLenum cap);
inline GLboolean glIsEnabledi(GLenum cap, GLuint index);
inline const GLubyte *glGetString(GLenum name);
inline const GLubyte *glGetStringi(GLenum name, GLuint index);
inline void glQueryCounter(GLuint id, GLenum target);
inline void glGenSamplers(GLsizei n, GLuint *samplers);
inline void glBindSampler(GLuint unit, GLuint sampler);
inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * params);
inline void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * params);
inline void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *params);
inline void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *params);
inline void glDeleteSamplers(GLsizei n, const GLuint * samplers);
inline GLboolean glIsSampler(GLuint id);
inline void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params);
inline void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params);
inline void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params);
inline void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params);
inline void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
inline GLint glGetFragDataIndex(GLuint program, const GLchar * name);

/**
 * fn CALLGL32(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @brief Load the opengl 3.2 extension and call it.
 */
#define CALLGL32(SIGNATURE, NAME) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 3, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy();

/**
 * fn CALLGL32_V(SIGNATURE, NAME, ...)
 * @param[in] SIGNATURE The opengl function to call.
 * @param[in] NAME The name of the opengl function.
 * @param[in] ... The parameters to forward to the function.
 * @brief Load the opengl 3.2 extension and call it.
 */
#define CALLGL32_V(SIGNATURE, NAME, ...) \
	static auto proxy = ece::loadOpenGLProc<SIGNATURE>(NAME, ece::Version<2>{ 3, 2 }); \
	if (!proxy) { \
		throw ece::OpenGLExtensionException(NAME); \
	} \
	return proxy(__VA_ARGS__);

#include "renderer/opengl/gl32_extension.inl"

#endif // GL32_EXTENSION_HPP
