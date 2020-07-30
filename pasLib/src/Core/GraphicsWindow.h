#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <string>

namespace pasLib
{
    class GraphicsWindow
    {
        public:
            GraphicsWindow(std::string title_in);
            ~GraphicsWindow(void);
            void Destroy(void);
        private:
            std::string title;
            bool cleanedUp;
    };
}

#endif
