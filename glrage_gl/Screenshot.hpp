#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <glrage_gl/gl_core_3_3.h>

namespace glrage {
namespace gl {

class Screenshot
{
public:
    static void capture(const std::wstring& path);
    static void capture(std::vector<uint8_t>& buffer, GLint& width,
        GLint& height, GLint depth, GLenum format, GLenum type,
        bool vflip = false);
};

} // namespace gl
} // namespace glrage