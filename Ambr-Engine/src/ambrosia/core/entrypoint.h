#pragma once

#include "application.h"

#ifdef AMBR_WINDOW_WIN32

#include "platform/windows/win32_window.h"

namespace ambr {
extern std::shared_ptr<ambr::application> create_application();
};

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPTSTR pCmdLine, int nCmdShow) {
  ambr::win32_window_specs win32_specs(hInstance, hPrevInstance, pCmdLine,
                                       nCmdShow);
  ambr::window_specs specs;
  specs.data = win32_specs;

  auto app = ambr::create_application();
  app->set_window_specs(specs);
  app->start();

  return 0;
}

#else

int main(int argc, char **argv) {
  auto app = ambr::create_application();
  app->start();
}

#endif