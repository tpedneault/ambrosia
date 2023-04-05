#pragma once

#include "base.h"

namespace ambr {

struct AMBR_ENGINE_API window_specs {
  string title;
  u32 width;
  u32 height;
  std::any data;

  explicit window_specs(const string &title = "Ambrosia Engine",
                        const u32 width = 800, const u32 height = 600)
      : title(title), width(width), height(height) {}
};

class AMBR_ENGINE_API window {
public:
  static std::shared_ptr<window>
  create(const window_specs &specs);

  explicit window(const window_specs &specs);
  virtual ~window();

  virtual void initialize();
  virtual void update();
  virtual void destroy();

  [[nodiscard]] virtual u32 get_width() const = 0;
  [[nodiscard]] virtual u32 get_height() const = 0;
  [[nodiscard]] virtual void *get_window_handle() const = 0;

protected:
  virtual void on_initialization() = 0;
  virtual void on_update() = 0;
  virtual void on_destroy() = 0;

  window_specs specs_;
};

}; // namespace ambr