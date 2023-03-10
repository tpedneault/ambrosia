#pragma once

#include "Editor/Editor.h"
#include "Core/System.h"

namespace ambr {

enum class FontID : U8 {
  RubikRegular,
  RubikBold,
};

struct Font {
  const FontID id;
  const U8 pixelSize;
  ImFont* imGuiFont;
};

class FontManager final : public System {
 public:
  virtual String GetName() override { return "FontManager"; }

  void OnInitialization(void* specs) override;
  void OnUpdate() override;
  void OnDestroy() override;

  Font LoadFont(const FontID id, const String& path, const U8 size);
  Font GetFont(const FontID id);

  [[nodiscard]] std::vector<std::shared_ptr<System>> GetDependencies() const override;

  /**
   * \brief Processes the received event.
   * \param e event to handle
   */
  void ProcessEvent(const Event& e) override;

private:
  std::vector<Font> m_Fonts;
};

};  // namespace ambr