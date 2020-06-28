#include <apollo/core/window.h>

#include <glad/gl.h>
#include <glfw/glfw3.h>

#if defined(APOLLO_PLATFORM_WINDOWS)
#define GLFW_EXPOSE_NATIVE_WIN32
#elif defined(APOLLO_PLATFORM_LINUX)
#define GLFW_EXPOSE_NATIVE_X11
#endif
#include <glfw/glfw3native.h>

#include <apollo/core/log.h>

namespace apollo
{
    static GLFWwindow* _internalWindow = nullptr;

    static bool glfwinit()
    {
        const bool init = glfwInit();
        atexit([]() {glfwTerminate(); });

        return init;
    }

    static bool glfwInitializer = glfwinit();

    struct Window::WindowData 
    {
        std::string title;
        u32 width = ~0U;
        u32 height = ~0U;

        bool allowResizing = false;
        bool shouldClose = false;

        u32 currentMonitor = ~0U;
    };

    Window::Window(u32 width, u32 height, std::string_view title) noexcept
    {
        if (!glfwInitializer)
        {
            APOLLO_INTERNAL_CRITICAL("Failed to initialize GLFW");
            return;
        }

        _data = new WindowData();

        _data->width = width;
        _data->height = height;
        _data->title = title;
        _data->shouldClose = false;

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        _internalWindow = glfwCreateWindow(static_cast<s32>(_data->width), static_cast<s32>(_data->height), _data->title.c_str(), nullptr, nullptr);
        if (_internalWindow == nullptr)
        {
            APOLLO_INTERNAL_CRITICAL("Failed to create window");
            glfwTerminate();
            return;
        }

        APOLLO_INTERNAL_INFO("Created window ({0}, {1}) with title \"{2}\"", _data->width, _data->height, _data->title);

        // TODO (Roderick): Implement Graphics API Initialization
    }

    APOLLO_NO_DISCARD std::string Window::title() const noexcept
    {
        return _data->title;
    }

    APOLLO_NO_DISCARD u32 Window::width() const noexcept
    {
        return _data->width;
    }

    APOLLO_NO_DISCARD u32 Window::height() const noexcept
    {
        return _data->height;
    }

    APOLLO_NO_DISCARD bool Window::shouldClose() const noexcept
    {
        return _data->shouldClose;
    }

    void Window::refresh()
    {
        glfwSwapBuffers(_internalWindow);
        glfwPollEvents();
    }

    void Window::close()
    {
        _data->shouldClose = true;
    }
}