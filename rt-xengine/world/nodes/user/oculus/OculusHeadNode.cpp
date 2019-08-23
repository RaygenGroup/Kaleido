#include "pch.h"
#include "OculusHeadNode.h"

#include "world/World.h"

namespace World
{
	OculusHeadNode::OculusHeadNode(Node* parent)
		: Node(parent),
		m_eyes{ nullptr, nullptr }
	{
	}

	std::string OculusHeadNode::ToString(bool verbose, uint depth) const
	{
		return std::string("    ") * depth + "|--Head " + Node::ToString(verbose, depth);
	}

	bool OculusHeadNode::LoadAttributesFromXML(const tinyxml2::XMLElement* xmlData)
	{
		return Node::LoadAttributesFromXML(xmlData);
	}

	Node* OculusHeadNode::LoadSpecificChild(const tinyxml2::XMLElement* xmlChildData)
	{
		const std::string type = xmlChildData->Name();
		if (type == "left_eye")
		{
			m_eyes[ET_LEFT] = GetWorld()->LoadNode<CameraNode>(this, xmlChildData);
			return m_eyes[ET_LEFT];
		}
		else if (type == "right_eye")
		{
			m_eyes[ET_RIGHT] = GetWorld()->LoadNode<CameraNode>(this, xmlChildData);
			return m_eyes[ET_RIGHT];
		}
		return nullptr;
	}

	bool OculusHeadNode::PostChildrenLoaded()
	{
		return m_eyes[ET_LEFT] && m_eyes[ET_RIGHT];
	}

	//void OculusHeadNode::OnUpdate(const CTickEvent& event)
	//{
	//	/*auto& oculusHMD = GetOculusHMD();

	//	SetLocalOrientation(oculusHMD.headLocalOrientation);
	//	m_eyes[ET_LEFT]->SetLocalOrientation(oculusHMD.eyeLocalOrientation[ET_LEFT]);
	//	m_eyes[ET_RIGHT]->SetLocalOrientation(oculusHMD.eyeLocalOrientation[ET_RIGHT]);

	//	SetLocalTranslation(oculusHMD.headLocalTranslation);
	//	m_eyes[ET_LEFT]->SetLocalTranslation(oculusHMD.eyeLocalTranslation[ET_LEFT]);
	//	m_eyes[ET_RIGHT]->SetLocalTranslation(oculusHMD.eyeLocalTranslation[ET_RIGHT]);*/
	//}
}
