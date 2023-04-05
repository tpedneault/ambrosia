#pragma once

#include "ambrosia/core/base.h"
#include "ambrosia/core/window.h"

namespace ambr {

LRESULT CALLBACK window_proc(HWND hwnd, UINT umsg, WPARAM wparam,
                             LPARAM lparam);

struct AMBR_ENGINE_API win32_window_specs {
  HINSTANCE hinstance;
  HINSTANCE hprevious;
  LPTSTR cmdline;
  int ncmdshow;

  win32_window_specs(HINSTANCE hinstance, HINSTANCE hprevious, LPTSTR cmdline,
                     int ncmdshow);
};

class AMBR_ENGINE_API win32_window final : public window {
public:
  explicit win32_window(const window_specs &specs);

  [[nodiscard]] u32 get_width() const override;
  [[nodiscard]] u32 get_height() const override;
  [[nodiscard]] void *get_window_handle() const override;

protected:
  void on_initialization() override;
  void on_update() override;
  void on_destroy() override;

private:
  static bool class_name_registered_;
  HWND window_handle_;
};

}; // namespace ambr