#pragma once

#include "world/nodes/Node.h"
#include "asset/assets/ImageAsset.h"

class SkyHDRNode : public Node
{
	ImageAsset* m_hdrTexture;

public:
	SkyHDRNode(Node* parent);
	~SkyHDRNode() = default;
		
	bool LoadAttributesFromXML(const tinyxml2::XMLElement* xmlData) override;

	ImageAsset* GetSkyHDR() const { return m_hdrTexture; }

protected:
	std::string ToString(bool verbose, uint depth) const override;

public:

	void ToString(std::ostream& os) const override { os << "node-type: SkyHDRNode, name: " << GetName(); }
};
