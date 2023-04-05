#include "application.h"

namespace ambr {

application::application() : running_(false) {}

application::~application() = default;

void application::start() {
  // Initialize the engine.
  on_initialize();

  // Create the window to render to.
  window_ = window::create(window_specs_);
  window_->initialize();

  running_ = true;

  // Start the main loop.
  while (running_) {
    window_->update();
    on_update();
  }

  // Cleanup allocated resources.
  window_->destroy();
  on_destroy();
}

void application::set_window_specs(const window_specs &specs) {
  window_specs_ = specs;
}

}; // namespace ambr