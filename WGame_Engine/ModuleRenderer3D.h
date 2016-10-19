#ifndef _MODULERENDER3D_H
#define _MODULERENDER3D_H

#include "Module.h"
#include "Globals.h"
#include "MathGeoLib\include\MathGeoLib.h"
#include "Light.h"

#define MAX_LIGHTS 8

using namespace math;

class ModuleRenderer3D : public Module
{
public:
	ModuleRenderer3D(Application* app, bool start_enabled = true);
	~ModuleRenderer3D();

	bool Init();
	update_status PreUpdate(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

	void OnResize(int width, int height, float fovy);
	void Draw_Geometry(const Mesh* mesh, uint texture, float4x4 transformation_matrix, bool wire);

public:

	Light lights[MAX_LIGHTS];
	SDL_GLContext context;
	float3x3 NormalMatrix;
	float4x4 ModelMatrix, ViewMatrix, ProjectionMatrix;
};

#endif