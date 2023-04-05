#include <ambrosia.h>

class sandbox_application final : public ambr::application {
protected:
  void on_initialize() override {
    std::cout << "initializing the sandbox application" << std::endl;
    window_specs_.width = 1920;
    window_specs_.height = 1080;
  }

  void on_update() override {}

  void on_destroy() override {}
};

std::shared_ptr<ambr::application> ambr::create_application() {
  return std::make_shared<sandbox_application>();
}
