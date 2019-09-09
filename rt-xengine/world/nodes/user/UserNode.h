#pragma once

#include "world/nodes/Node.h"

class UserNode : public Node
{
protected:
	// TODO: turning speed with delta is not working properly on different fps profiles
	float m_movementSpeed;
	float m_turningSpeed;

public:
	UserNode(Node* parent);
	~UserNode() = default;

	void ToString(std::ostream& os) const { os << "node-type: UserNode, name: " << m_name; }
};
