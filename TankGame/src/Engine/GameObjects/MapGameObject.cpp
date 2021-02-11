#include "MapGameObject.h"
#include "../Engine.h"
#include "../Systems/SFMLSystem.h"

using namespace sf;

MapGameObject::MapGameObject()
{
	auto line1 = std::make_shared<RectangleShape>(Vector2f(755.0f, 5.0f));
	line1->rotate(90.f);
	line1->setFillColor(Color::White);
	line1->setPosition(25.f, 25.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(line1));

	//right side

	auto line2 = std::make_shared<RectangleShape>(Vector2f(750.0f, 5.0f));
	line2->rotate(90.f);
	line2->setFillColor(Color::White);
	line2->setPosition(775.f, 25.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(line2));

	//top line

	auto line3 = std::make_shared<RectangleShape> (Vector2f(750.0f, 5.0f));
	line3->setFillColor(Color::White);
	line3->setPosition(25.f, 25.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(line3));


	//bottom line

	auto line4 = std::make_shared<RectangleShape>(Vector2f(750.0f, 5.0f));
	line4->setFillColor(Color::White);
	line4->setPosition(25.f, 775.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(line4));

	/*
	// 60 triangles

	auto triangle = std::make_shared<CircleShape>(30.f, 3);
	triangle->setPosition(375.f, 735.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(triangle));

	auto triangle1 = std::make_shared<CircleShape>(30.f, 3);
	triangle1->setPosition(415.f, 0.f);
	triangle1->rotate(60.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(triangle1));

	auto triangle2 = std::make_shared<CircleShape>(30.f, 3);
	triangle2->setPosition(745.f, 350.f);
	triangle2->rotate(30.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(triangle2));


	auto triangle3 = std::make_shared<CircleShape>(30.f, 3);
	triangle3->setPosition(65.f, 355.f);
	triangle3->rotate(90.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(triangle3));

	//90 triangles
	auto right = std::make_shared<ConvexShape>();
	right->setPointCount(3);
	right->setPoint(0, sf::Vector2f(0.f, 0.f));
	right->setPoint(1, sf::Vector2f(60.f, 0.f));
	right->setPoint(2, sf::Vector2f(0.f, 60.f));
	right->setPosition(25.f, 25.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(right));

	auto right2 = std::make_shared<ConvexShape>();
	right2->setPointCount(3);
	right2->setPoint(0, sf::Vector2f(60.f, 0.f));
	right2->setPoint(1, sf::Vector2f(0.f, 0.f));
	right2->setPoint(2, sf::Vector2f(0.f, 60.f));
	right2->setPosition(775.f, 25.f);
	right2->rotate(90.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(right2));


	auto right3 = std::make_shared<ConvexShape>();
	right3->setPointCount(3);
	right3->setPoint(0, sf::Vector2f(60.f, 0.f));
	right3->setPoint(1, sf::Vector2f(0.f, 0.f));
	right3->setPoint(2, sf::Vector2f(0.f, 60.f));
	right3->setPosition(775.f, 775.f);
	right3->rotate(180.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(right3));

	auto right4 = std::make_shared<ConvexShape>();
	right4->setPointCount(3);
	right4->setPoint(0, sf::Vector2f(60.f, 0.f));
	right4->setPoint(1, sf::Vector2f(0.f, 0.f));
	right4->setPoint(2, sf::Vector2f(0.f, 60.f));
	right4->setPosition(25.f, 775.f);
	right4->rotate(270.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(right4));

	//middle square

	auto square = std::make_shared<RectangleShape>(Vector2f(50.f, 50.f));
	square->rotate(45.f);
	square->setFillColor(Color::White);
	square->setPosition(400.f, 350.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(square));
	//collide(line2);
	//inner big triangles

	auto big = std::make_shared<ConvexShape>();
	big->setPointCount(3);
	big->setPoint(0, sf::Vector2f(150.f, 0.f));
	big->setPoint(1, sf::Vector2f(0.f, 0.f));
	big->setPoint(2, sf::Vector2f(0.f, 150.f));
	big->setPosition(175.f, 175.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(big));

	auto big1 = std::make_shared<ConvexShape>();
	big1->setPointCount(3);
	big1->setPoint(0, sf::Vector2f(150.f, 0.f));
	big1->setPoint(1, sf::Vector2f(0.f, 0.f));
	big1->setPoint(2, sf::Vector2f(0.f, 150.f));
	big1->setPosition(625.f, 625.f);
	big1->rotate(180.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(big1));

	//lines to contain players

	auto p1con = std::make_shared<RectangleShape>(Vector2f(100.0f, 5.0f));
	p1con->setFillColor(Color::White);
	p1con->setPosition(250.f, 575.f);
	p1con->rotate(90.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(p1con));

	auto p1con2 = std::make_shared<RectangleShape>(Vector2f(100.0f, 5.0f));
	p1con2->setFillColor(Color::White);
	p1con2->setPosition(570.f, 250.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(p1con2));

	auto p2con = std::make_shared<RectangleShape>(Vector2f(100.0f, 5.0f));
	p2con->setFillColor(Color::White);
	p2con->setPosition(575.f, 150.f);
	p2con->rotate(90.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(p2con));

	auto p2con2 = std::make_shared<RectangleShape>(Vector2f(100.0f, 5.0f));
	p2con2->setFillColor(Color::White);
	p2con2->setPosition(150.f, 575.f);
	p2con2->rotate(0.f);
	m_mapShapes.push_back(std::dynamic_pointer_cast<Shape>(p2con2));
	*/
}
void MapGameObject::initialize()
{
	GameObject::initialize();
}
void MapGameObject::shutdown()
{
	GameObject::shutdown();
}
void MapGameObject::tick(float dt)
{
	GameObject::tick(dt);
}
void MapGameObject::render()
{
	GameObject::render();
	for (auto& shape : m_mapShapes)
	{
		auto window = Engine::get().getSFMLSystem().getWindow();
		window->draw(*shape);
	}

}

void MapGameObject::physicsCallback(std::shared_ptr<GameObject>)
{

}
