#include "Ambrosia.h"

class SandboxApplication : public ambr::Application {

};

int main() {
  std::cout << "Hello, world!" << std::endl;

	SandboxApplication app;
  app.Start();

	return 0;
}