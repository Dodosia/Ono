#pragma once

#include <glad/glad.h>
#include "Ono/Renderer/Renderer.h"

namespace Ono
{
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

	private:
		void Init() override;
		void Clear() override;

		enum VAO_IDs { Triangles, NumVAOs };
		enum Buffer_IDs { ArrayBuffer, NumBuffers };
		enum Attrib_IDs { vPosition = 0 };

		GLuint VAOs [NumVAOs];
		GLuint Buffers [NumBuffers];

		static const GLuint NumVertices = 6;
	};
}
