#pragma once
#include <glad/glad.h>

namespace Ono
{
    typedef struct
    {
        GLenum       type;
        const char* filename;
        GLuint       shader;
    } ShaderInfo;

    GLuint LoadShaders(ShaderInfo* shader);
}
