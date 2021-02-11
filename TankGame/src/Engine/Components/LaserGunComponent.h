#ifndef LASERGUNCOMPONENT_H
#define LASERGUNCOMPONENT_H
#include "Component.h"
#include "../GameObjects/BulletGameObject.h"

class LaserGunComponent : public Component
{
public:
	LaserGunComponent(float);
	~LaserGunComponent();

	virtual void initialize() override;
	virtual void shutdown() override;
	virtual void tick(float dt) override;
	virtual void render() override;
	virtual const std::string getTypename() const override { return "laser gun component"; };
	void shoot();
	float getCooldown() { return m_currentCooldown; };
private:
	float m_maxCooldown;
	float m_currentCooldown;
	bool m_canShoot = true;
	std::vector<std::shared_ptr<BulletGameObject>> m_bullets;
	int m_bulletCacheLimit = 250;
};

#endif // !LASERGUNCOMPONENT_H