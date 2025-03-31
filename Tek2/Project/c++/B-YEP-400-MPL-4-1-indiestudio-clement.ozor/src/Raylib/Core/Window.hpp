/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Window.hpp
*/

#ifndef INDIESTUDIO_WINDOW_HPP
#define INDIESTUDIO_WINDOW_HPP

#include "Essentials.hpp"
#include "raylib.h"

// TODO:
//bool IsWindowFullscreen(void);                                          // Check if window is currently fullscreen
//bool IsWindowHidden(void);                                              // Check if window is currently hidden (only PLATFORM_DESKTOP)
//bool IsWindowMinimized(void);                                           // Check if window is currently minimized (only PLATFORM_DESKTOP)
//bool IsWindowMaximized(void);                                           // Check if window is currently maximized (only PLATFORM_DESKTOP)
//bool IsWindowFocused(void);                                             // Check if window is currently focused (only PLATFORM_DESKTOP)
//bool IsWindowResized(void);                                             // Check if window has been resized last frame
//bool IsWindowState(unsigned int flag);                                  // Check if one specific window flag is enabled
//void SetWindowState(unsigned int flags);                                // Set window configuration state using flags
//void ClearWindowState(unsigned int flags);                              // Clear window configuration state flags
//void MaximizeWindow(void);                                              // Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
//void MinimizeWindow(void);                                              // Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
//void RestoreWindow(void);                                               // Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
//void SetWindowMonitor(int monitor);                                     // Set monitor for the current window (fullscreen mode)
//void SetWindowMinSize(int width, int height);                           // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
//void *GetWindowHandle(void);                                            // Get native window handle
//int GetMonitorCount(void);                                              // Get number of connected monitors
//Vector2 GetMonitorPosition(int monitor);                                // Get specified monitor position
//int GetMonitorPhysicalWidth(int monitor);                               // Get specified monitor physical width in millimetres
//int GetMonitorPhysicalHeight(int monitor);                              // Get specified monitor physical height in millimetres
//const char *GetMonitorName(int monitor);                                // Get the human-readable, UTF-8 encoded name of the primary monitor
//void SetClipboardText(const char *text);                                // Set clipboard text content
//const char *GetClipboardText(void);

namespace Raylib {
    namespace Core {
        class Window {
            public:
                Window(int width, int height, std::string title);
                ~Window();

                // Window management
                bool shouldClose();
                bool isReady();
                void toggleFullscreen();

                // Setters
                void setIcon(Image icon);
                void setTitle(std::string title);
                void setPosition(int x, int y);
                void setSize(int width, int height);

                // Getters
                int getWidth();
                int getHeight();
                Vector2 getPosition();

            private:
                int _width;
                int _height;
                int _x;
                int _y;
                std::string _title;
                Image _icon;
        };
    }
}

#endif
