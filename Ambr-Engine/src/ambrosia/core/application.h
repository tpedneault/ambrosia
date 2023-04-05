#pragma once

#include "base.h"
#include "window.h"

namespace ambr {

class AMBR_ENGINE_API application {
public:
  application();
  virtual ~application();

  void start();
  void set_window_specs(const window_specs &specs);

protected:
  virtual void on_initialize() = 0;
  virtual void on_update() = 0;
  virtual void on_destroy() = 0;

  window_specs window_specs_;
  std::shared_ptr<window> window_;
  bool running_;
};

}; // namespace ambr