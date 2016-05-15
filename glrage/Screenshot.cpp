#include "Screenshot.hpp"

#include "GLRage.hpp"

#include <glrage_util/StringUtils.hpp>
#include <glrage_gl/Screenshot.hpp>

#include <cstdint>
#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace glrage {

void Screenshot::schedule(bool schedule)
{
    m_schedule = schedule;
}

void Screenshot::captureScheduled()
{
    if (m_schedule) {
        capture();
        m_schedule = false;
    }
}

void Screenshot::capture()
{
    // find unused screenshot file name
    std::wstring basePath = GLRage::getContext().getBasePath();
    std::wstring path;
    DWORD dwAttrib;
    do {
        std::string fileName =
            StringUtils::format("screenshot%04d.tga", 20, m_index++);
        path = basePath + L"\\" + StringUtils::utf8ToWide(fileName);
        dwAttrib = GetFileAttributes(path.c_str());
    } while (dwAttrib != INVALID_FILE_ATTRIBUTES && m_index < 9999);

    // rather unlikely, but better safe than sorry
    if (dwAttrib != INVALID_FILE_ATTRIBUTES) {
        throw std::runtime_error("All available screenshot slots are used up!");
    }

    // actual capture
    gl::Screenshot::capture(path);
}

} // namespace glrage