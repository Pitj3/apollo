#ifndef apollo_window_h__
#define apollo_window_h__

#include <string>
#include <apollo/core/macros.h>

namespace apollo
{
    class Window
    {
        public:
            Window() = default;
            ~Window() = default;

            Window(u32 width, u32 height, std::string_view title) noexcept;

            APOLLO_NO_COPY_MOVE(Window);

            APOLLO_NO_DISCARD std::string title() const noexcept;
            APOLLO_NO_DISCARD u32 width() const noexcept;
            APOLLO_NO_DISCARD u32 height() const noexcept;
            APOLLO_NO_DISCARD bool shouldClose() const noexcept;

            void refresh();
            void close();

        private:
            struct WindowData;
            WindowData* _data;
        };
}

#endif // apollo_window_h__