#include "onopch.h"
#include "LoadShaders.h"

namespace Ono
{
	GLuint LoadShaders(ShaderInfo* shaders)
	{
        if (shaders == nullptr) return 0; 

        GLuint program = glCreateProgram();

        ShaderInfo* currentShader = shaders;
        while (currentShader->type != GL_NONE)
        {
            std::ifstream shaderFile(currentShader->filename);
            if (!shaderFile.is_open()) 
            {
                return 0;
            }

            std::stringstream shaderData;
            shaderData << shaderFile.rdbuf();
            shaderFile.close();

            std::string sourceStr = shaderData.str();
            const char* source = sourceStr.c_str();
            GLuint shader = glCreateShader(currentShader->type);
            glShaderSource(shader, 1, &source, nullptr);
            glCompileShader(shader);

            GLint compiled;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
            if (!compiled) {
                GLint logSize;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
                char* logMsg = new char[logSize];
                glGetShaderInfoLog(shader, logSize, nullptr, logMsg);
                std::cerr << "ќшибка компил€ции шейдера " << currentShader->filename << ":\n" << logMsg << std::endl;
                delete[] logMsg;
                return 0;
            }

            glAttachShader(program, shader);
            currentShader->shader = shader;

            ++currentShader;
        }
        glLinkProgram(program);

        GLint linked;
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked) {
            GLint logSize;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
            char* logMsg = new char[logSize];
            glGetProgramInfoLog(program, logSize, nullptr, logMsg);
            std::cerr << "ќшибка линковки программы:\n" << logMsg << std::endl;
            delete[] logMsg;
            return 0;
        }
        currentShader = shaders;
        while (currentShader->type != GL_NONE) {
            glDetachShader(program, currentShader->shader);
            glDeleteShader(currentShader->shader);
            ++currentShader;
        }

        return program;  
    }
}