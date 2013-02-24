//
//  scene.h
//  Mesh
//
//  Created by Simon Harvey on 13-02-23.
//  Copyright (c) 2013 Simon Harvey. All rights reserved.
//

#ifndef Mesh_scene_h
#define Mesh_scene_h

#include <cmath>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "mesh.h"
#include "icosahedron.h"
#include "shogles.h"

using namespace glm;
using namespace std;
using namespace shogles;
using namespace mesh;

struct Scene
{
	struct {
		mat4 projection, camera, model;
	} matrices;
	unique_ptr<Mesh> mesh;
	position_t pos;
	
	Scene()
	{
		mesh = unique_ptr<Mesh>(new Mesh(&ico_vertices[0][0], sizeof(ico_vertices)/sizeof(float)/3, &ico_indices[0][0], sizeof(ico_indices)));
		matrices.camera = translate(mat4(1.0f), vec3(0, 0, -5));
		
		edge_t edge(0, 1);
		pos = {edge, .5, .5};
	}
	
	void SetSize(float w, float h)
	{
		matrices.projection = glm::perspective(45.0f, w/h, 0.1f, 100.f);
	}
	
	void Render()
	{
		glClearColor(.33, .33, .33, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		static auto shader = ResourceManager::get_instance().get_shader("Assets/color.shader");
		shader->use();
		UNIFORM(shader, u_Projection);
		UNIFORM(shader, u_Color);
		ATTRIB(shader, a_Position);
		ENABLE_ATTRIB(a_Position);
		
		auto mvp = matrices.projection*matrices.camera*matrices.model;
		
		glUniform4f(u_Color, 1, 1, 1, 1);
		glUniformMatrix4fv(u_Projection, 1, false, value_ptr(mvp));
		glVertexAttribPointer(a_Position, 3, GL_FLOAT, false, 0, mesh->vertices.data());
		glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_BYTE, mesh->indices.data());
	
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		
		auto &indices = mesh->indices;
		vector<GLubyte> wireframe_indices;
		for (int i=0; i<indices.size(); i+=3) {
			wireframe_indices.push_back(indices[i]);
			wireframe_indices.push_back(indices[i+1]);
			
			wireframe_indices.push_back(indices[i+1]);
			wireframe_indices.push_back(indices[i+2]);
			
			wireframe_indices.push_back(indices[i+2]);
			wireframe_indices.push_back(indices[i]);
		}
		
		glUniform4f(u_Color, 0, 0, 0, 1);
		glDrawElements(GL_LINES, wireframe_indices.size(), GL_UNSIGNED_BYTE, wireframe_indices.data());
	}
};

#endif
