#pragma once

#include <string>

#include "../common_classes/OpenGLWindow.h"
#include "../common_classes/HUD.h"
#include "../common_classes/texture.h"

#include "../common_classes/shader_structs/ambientLight.h"
#include "../common_classes/shader_structs/pointLight.h"

/**
  HUD for tutorial 023 (point lights).
*/
class HUD023 : public HUD
{
public:
    HUD023(const OpenGLWindow& window);

	/** \brief  Renders HUD. */
	void renderHUD() const override {} // Don't need this, but had to override, so that class is not abstract
	void renderHUD(const shader_structs::AmbientLight& ambientLight, const shader_structs::PointLight& pointLight) const;
};
