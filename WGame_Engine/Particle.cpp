#include "Particle.h"
#include "Application.h"
#include "Component_Transformation.h"
#include "MathGeoLib\include\MathGeoLib.h"

using namespace std;

Particle::Particle(float3 pos, float3 scale_, Quat rot_quat, float3 angles_) : position(pos), scale(scale_), quat_rotation(rot_quat), rotation_degrees(angles_)
{
	
	transformation_matrix = transformation_matrix.FromTRS(position, quat_rotation, scale);
}

Particle::~Particle()
{

}

void Particle::Update_Particle(math::float3 force)
{

}


void Particle::Update_Billboarding()
{
	if (App->camera->Get_Camera_Component()->Get_Up().IsZero() == false)
	{

		float3 forward = App->camera->Get_Camera_Component()->Get_Position() - transformation_matrix.TranslatePart().Normalized();

		float4x4 tmp = float4x4::LookAt(localForward, forward.Normalized(), localUp, App->camera->Get_Camera_Component()->Get_Up().Normalized());

		Set_Rotation(RadToDeg(tmp.ToEulerXYZ()));
	}
}

void Particle::Destroy_Particle()
{
	alive = false;
	velocity = float3::zero;
	texture_id = 0;
	age = 0.f;
	lifetime = 0.f;


}

math::float4x4 Particle::Get_Tranformation_Matrix()const
{
	return transformation_matrix;
}

math::float3 Particle::Get_Position()const
{
	return position;
}

math::float3 Particle::Get_Rotation()const
{
	return rotation_degrees;
}

math::float3 Particle::Get_Scale()const
{
	return scale;
}


void Particle::Set_Position(const math::float3 &pos)
{
	position = pos;
	transformation_matrix = transformation_matrix.FromTRS(position, quat_rotation, scale);
}

void Particle::Set_Rotation(const math::float3 &rot_degrees)
{
	rotation_degrees = rot_degrees;
	float3 rotation_radians = DegToRad(rotation_degrees);

	quat_rotation = quat_rotation.FromEulerXYZ(rotation_radians.x, rotation_radians.y, rotation_radians.z);

	transformation_matrix = transformation_matrix.FromTRS(position, quat_rotation, scale);

}

void Particle::Set_Scale(const math::float3 &scal)
{
	scale = scal;
	transformation_matrix = transformation_matrix.FromTRS(position, quat_rotation, scale);
}

