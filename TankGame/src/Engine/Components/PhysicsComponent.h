#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H
#include "Component.h"

enum class ColliderType
{
	unassigned = -1,
	circle = 1,
	rectangle = 2
};

class PhysicsComponent : public Component
{
public:
	PhysicsComponent(ColliderType type);
	~PhysicsComponent();

	virtual void initialize() override;
	virtual void shutdown() override;
	virtual void tick(float dt) override;
	virtual void render() override;
	virtual const std::string getTypename() const override { return "physics component"; };
	ColliderType getColliderType()
	{
		return m_type;
	};

private:
	ColliderType m_type = ColliderType::unassigned;
};

#endif // !PHYSICSCOMPONENT_H