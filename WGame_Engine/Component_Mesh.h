#ifndef _COMPONENT_MESH_H_
#define _COMPONENT_MESH_H_

#include "Components.h"

struct Mesh;


class Component_Mesh : public Components
{
public:

	Component_Mesh(Components_Type type, GameObject* game_object, Mesh* mesh_);
	~Component_Mesh();

	void Update();

public:

	Mesh* mesh;
	bool active = false;
	unsigned int id_image = 0;
};

#endif // !_COMPONENT_MESH_H_

