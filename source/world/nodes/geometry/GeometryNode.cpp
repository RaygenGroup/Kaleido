#include "world/nodes/geometry/GeometryNode.h"
#include "asset/AssetManager.h"
#include "core/MathAux.h"

GeometryNode::GeometryNode()
{
	m_model = AssetManager::GetOrCreate<ModelPod>("/genEmptyModel");
}

void GeometryNode::SetModel(PodHandle<ModelPod> newModel)
{
	m_model = newModel;
	SetDirty(DF::ModelChange);
}

void ::GeometryNode::DirtyUpdate(DirtyFlagset dirtyFlags)
{
	if (dirtyFlags[DF::ModelChange]) {
		m_localBB = m_model.Lock()->bbox;
		CalculateWorldAABB();
	}
}
