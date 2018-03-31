# include <ncurses.h>

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

class Window {
public:
    Window();
    Window(const Window &src);
    ~Window();
    Window &operator=(const Window &src);

    void init();
    void refresh();
    void updateDisplay(int x, int y, const char *str);
    void init_main_window();

private:
    WINDOW *win;
};

#endif
