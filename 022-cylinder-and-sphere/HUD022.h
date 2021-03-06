#pragma once

#include <string>

#include "../common_classes/OpenGLWindow.h"
#include "../common_classes/HUD.h"
#include "../common_classes/texture.h"

#include "../common_classes/shader_structs/material.h"

/**
  HUD for tutorial 022 (cylinder and sphere).
*/
class HUD022 : public HUD
{
public:
	HUD022(const OpenGLWindow& window);

	/** \brief  Renders HUD. */
	void renderHUD() const override {} // Don't need this, but had to override, so that class is not abstract
	void renderHUD(const glm::vec3& diffuseLightDirection, bool displayNormals, bool updateSpaceEntities, int sphereSlices, int sphereStacks) const;
};
 