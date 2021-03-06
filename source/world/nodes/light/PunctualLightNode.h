#pragma once

#include "world/nodes/light/LightNode.h"

class PunctualLightNode : public LightNode {
	REFLECTED_NODE(PunctualLightNode, LightNode) { REFLECT_VAR(m_attenuationMode); }

	glm::mat4 m_projectionMatrix{};
	std::array<glm::mat4, 6> m_viewMatrices{};
	std::array<glm::mat4, 6> m_viewProjectionMatrices{};

	enum AttenuationMode : int32
	{
		CONSTANT = 0,
		LINEAR = 1,
		QUADRATIC = 2
	} m_attenuationMode{ AttenuationMode::LINEAR };

	void CalculateWorldAABB() override;

	void RecalculateProjectionMatrix();
	void RecalculateViewMatrices();
	void RecalculateViewProjectionMatrices();

public:
	void DirtyUpdate(DirtyFlagset flags) override;

	[[nodiscard]] glm::mat4 GetProjectionMatrix() const { return m_projectionMatrix; }
	[[nodiscard]] const std::array<glm::mat4, 6>& GetViewMatrices() const { return m_viewMatrices; }
	[[nodiscard]] const std::array<glm::mat4, 6>& GetViewProjectionMatrices() const { return m_viewProjectionMatrices; }
	[[nodiscard]] AttenuationMode GetAttenuationMode() const { return m_attenuationMode; }

	bool IsNodeInsideAABB(Node* node) const { return m_aabb.IntersectsAABB(node->GetAABB()); }
};
