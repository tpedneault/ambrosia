#include "Application.h"

namespace ambr {

Application::Application() {}

Application::~Application() {}

void Application::Start() { std::cout << "Started application!" << std::endl; }

void Application::OnInitialize() {}

void Application::OnUpdate() {}

void Application::OnDestroy() {}

};  // namespace ambr