#pragma once

#include "world/nodes/light/SpotLightNode.h"
#include "renderer/renderers/opengl/GLRendererBase.h"
#include "renderer/renderers/opengl/assets/GLShader.h"
#include "renderer/renderers/opengl/basic/GLBasicGeometry.h"

#include <glad/glad.h>


namespace ogl {
struct GLBasicSpotLight : NodeObserver<SpotLightNode, GLRendererBase> {
	GLuint fbo{};
	GLuint shadowMap{};

	GLShader* depthMapShader{ nullptr };

	GLBasicSpotLight(SpotLightNode* node);
	~GLBasicSpotLight() override;

	// render shadow map, then return the matrix needed to move from world to light space
	void RenderShadowMap(const std::vector<GLBasicGeometry*>& geometries);

	void DirtyNodeUpdate(DirtyFlagset nodeDirtyFlagset) override;
};
} // namespace ogl
