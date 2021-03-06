#ifndef _COMPONENT_EMITTER_H_
#define _COMPONENT_EMITTER_H_

#include "Components.h"
#include <vector>
class Particle;


class Component_Emitter : public Components
{
public:

	Component_Emitter(Components_Type type, GameObject* game_object, unsigned int amount_particles);
	~Component_Emitter();

	void Update();
	void Clean_Up();
	void Create_Particle();

	void Render_Panel();
	void Resize_Particles_Vector();
	void Update_Particles_Billboarding();
	void Render_Emmiter();
	void Render_Particles();

	//Checkbox bool
	bool Is_Checkbox_Active()const;
	void Set_Checkbox(bool on);

	//Particles Behaviors
	void Clean_Particles_List();

	bool Is_Smoke_Behavior_Active()const;
	bool Is_Firework_Behavior_Active()const;

private:

	math::float3 position_emitter = float3::zero;
	float3 max_initial_velocity = float3::zero;
	float3 min_initial_velocity = float3::zero;
	float size_particles = 0.f;
	float lifetime = 0.f;
	math::float3 force = float3::zero;

	//Frustum Box
	float min_width = 0.f;
	float max_width = 0.f;
	float min_height = 0.f;
	float max_height = 0.f;
	float min_depth = 0.f;
	float max_depth = 0.f;

	//Number of particles that we will have to create
	int number_particles = 0;

	std::vector<Particle*> particles_container;

	//Billboard variables
	float3 localForward = float3(0, 0, 1);
	float3 localUp = float3(0, 1, 0);

	bool active_checkbox = false;
	bool smoke_behavior = false;
	bool fireworks_behavior = false;

	//Firework Particles
	float3 max_fireowks_children_initial_velocity = float3::zero;
	float3 min_fireowks_children_initial_velocity = float3::zero;
	float size_fireowks_children_particles = 0;
	float lifetimefireowks_children = 0;
	float3 force_firework_children = float3::zero;
	bool draw_emmiter = false;
};

#endif