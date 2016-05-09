#pragma once

#include "GameID.hpp"

#include <Windows.h>

#include <cstdint>
#include <string>

namespace glrage {

class Context
{
public:
    virtual void init() = 0;
    virtual void attach(HWND hwnd) = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual LRESULT windowProc(
        HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;
    virtual BOOL enumWindowsProc(HWND hwnd) = 0;
    virtual bool isFullscreen() = 0;
    virtual void setFullscreen(bool fullscreen) = 0;
    virtual void toggleFullscreen() = 0;
    virtual void setDisplaySize(int32_t width, int32_t height) = 0;
    virtual int32_t getDisplayWidth() = 0;
    virtual int32_t getDisplayHeight() = 0;
    virtual void setWindowSize(int32_t width, int32_t height) = 0;
    virtual int32_t getWindowWidth() = 0;
    virtual int32_t getWindowHeight() = 0;
    virtual void setupViewport() = 0;
    virtual void swapBuffers() = 0;
    virtual void renderBegin() = 0;
    virtual bool isRendered() = 0;
    virtual HWND getHWnd() = 0;
    virtual std::wstring getBasePath() = 0;
    virtual GameID getGameID() = 0;
    virtual void setGameID(GameID gameID) = 0;
};

} // namespace glrage