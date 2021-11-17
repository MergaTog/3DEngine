#include "PhysicsComponent.h"
#include "Engine.h"

void nc::PhysicsComponent::Update()
{
	velocity += acceleration * owner->scene->engine->time.deltaTime;
	owner->transform.position += velocity * owner->scene->engine->time.deltaTime;
	velocity *= damping;

	acceleration = glm::vec3{ 0 };
}

bool nc::PhysicsComponent::Write(const rapidjson::Value& value) const
{
	return false;
}

bool nc::PhysicsComponent::Read(const rapidjson::Value& value)
{
	JSON_READ(value, damping)

	return false;
}

