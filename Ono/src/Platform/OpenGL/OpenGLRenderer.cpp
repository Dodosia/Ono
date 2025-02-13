#include "onopch.h"
#include "OpenGLRenderer.h"
#include "Shaders/LoadShaders.h"

#define BUFFER_OFFSET(offset) ((void *) (offset))

namespace Ono
{
    //Renderer* Renderer::Create()
    //{
    //    return new OpenGLRenderer();
    //}

    OpenGLRenderer::OpenGLRenderer()
    {
        Init();
    }

    OpenGLRenderer::~OpenGLRenderer()
    {
        Clear();
    }

    void OpenGLRenderer::Init()
    {
        const GLfloat vertices[NumVertices] [2] =
        {
            { -0.90, -0.90 },
            {  0.85, -0.90 },
            { -0.90,  0.85 },
            {  0.90, -0.85 },
            {  0.90,  0.90 },
            { -0.85,  0.90 }
        };

        glCreateVertexArrays(NumVAOs, VAOs);
        glCreateBuffers(NumBuffers, Buffers);
        glNamedBufferStorage(Buffers[ArrayBuffer], sizeof(vertices), vertices, 0);
        ShaderInfo  shaders[] = 
        {
            { GL_VERTEX_SHADER, "triangles.vert" },
            { GL_FRAGMENT_SHADER, "triangles.frag" },
            { GL_NONE, NULL }
        };

        GLuint program = LoadShaders(shaders);
        glClearColor(1.0, 0.3, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glBindVertexArray(VAOs[Triangles]);
        glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
        glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(vPosition);
        glDrawArrays(GL_TRIANGLES, 0, NumVertices);
    }

    void OpenGLRenderer::Clear()
    {

    }
}
