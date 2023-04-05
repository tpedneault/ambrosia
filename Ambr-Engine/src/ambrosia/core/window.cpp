#include "window.h"

#ifdef GLCORE_PLATFORM_WINDOWS
#include "platform/windows/win32_window.h"
#endif

namespace ambr {

std::shared_ptr<window> window::create(const window_specs &specs) {
#ifdef GLCORE_PLATFORM_WINDOWS
  return std::make_shared<win32_window>(specs);
#else
  return nullptr;
#endif
}

window::window(const window_specs &specs) : specs_(specs) {}

window::~window() = default;

void window::initialize() { on_initialization(); }

void window::update() { on_update(); }

void window::destroy() { on_destroy(); }

}; // namespace ambr