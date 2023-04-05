#include "win32_window.h"

namespace ambr {

LRESULT CALLBACK window_proc(HWND hwnd, UINT umsg, WPARAM wparam,
                             LPARAM lparam) {
  switch (umsg) {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  default:
    return DefWindowProc(hwnd, umsg, wparam, lparam);
  }
}

win32_window_specs::win32_window_specs(HINSTANCE hinstance, HINSTANCE hprevious,
                                       LPTSTR cmdline, int ncmdshow)
    : hinstance(hinstance), hprevious(hprevious), cmdline(cmdline),
      ncmdshow(ncmdshow) {}

bool win32_window::class_name_registered_ = false;

win32_window::win32_window(const window_specs &specs)
    : window(specs), window_handle_(nullptr) {}

u32 win32_window::get_width() const { return specs_.width; }

u32 win32_window::get_height() const { return specs_.height; }

void *win32_window::get_window_handle() const { return nullptr; }

void win32_window::on_initialization() {
  auto w32_specs = std::any_cast<win32_window_specs>(specs_.data);
  static wchar_t class_name[] = L"AmbrosiaEngine";
  if (!class_name_registered_) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = window_proc;
    wc.hInstance = w32_specs.hinstance;
    wc.lpszClassName = class_name;
    RegisterClass(&wc);
  }

  window_handle_ =
      CreateWindowEx(0, class_name, L"Ambrosia Window", WS_OVERLAPPEDWINDOW,
                     CW_USEDEFAULT, CW_USEDEFAULT, specs_.width, specs_.height,
                     NULL, NULL, w32_specs.hinstance, NULL);

  if (!window_handle_)
  {
    return;
  }

  ShowWindow(window_handle_, w32_specs.ncmdshow);
}

void win32_window::on_update()
{
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

void win32_window::on_destroy() {}

}; // namespace ambr