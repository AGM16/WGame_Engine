#ifndef _EDITOR_H_
#define _EDITOR_H_


#include "Module.h"
#include "Globals.h"
#include "Panel_Windows.h"


class Editor : public Module
{
public:
	Editor(bool start_enabled = true);
	~Editor();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	bool Is_Saving()const;
	bool Is_Loading()const;

	void Render_Panel_Save_As();
	void Render_Panel_Load();

private:

	//ImGUi Variable
	bool show_test_window;
	Primitive_Plane plane;

	//Panels
	Panel_Windows panels;

	bool save = false;
	bool load = false;
	bool get_xml_Files = false;
	char last_name_file_saved[100] = "";
	vector<string> xml_files;


	

};

#endif