#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include "MathGeoLib\include\MathGeoLib.h"
class GameObject;

enum Components_Type
{
	TRANSFORMATION,
	MESH,
	MATERIAL,
	UNKOWN
};


class Components
{
public:

	Components(Components_Type type, GameObject* game_object);
	~Components();


	bool Enable();
	bool Disable();
	
	virtual void Update();
	virtual void Clean_Up();

	
	Components_Type Get_Type()const;
	GameObject* Get_Game_Object()const;


	bool Get_Panel_Opened()const;
	bool Is_Active()const;

private:

	Components_Type type_c;
	bool active_component;
	GameObject* game_object = nullptr;
	bool panels_open = true;

};

#endif // !_COMPONENTS_H_

