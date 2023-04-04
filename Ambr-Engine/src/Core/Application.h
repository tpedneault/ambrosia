#pragma once

#include "Base.h"

namespace ambr {

class AMBR_ENGINE_API Application {
 public:
  Application();
  virtual ~Application();

  void Start();

 protected:
  virtual void OnInitialize();
  virtual void OnUpdate();
  virtual void OnDestroy();

private:
};

};  // namespace ambr