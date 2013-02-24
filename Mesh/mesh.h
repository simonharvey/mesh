//
//  mesh.h
//  Mesh
//
//  Created by Simon Harvey on 13-02-23.
//  Copyright (c) 2013 Simon Harvey. All rights reserved.
//

#ifndef Mesh_mesh_h
#define Mesh_mesh_h

#include <vector>
#include <map> // fuck that shit
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

namespace mesh
{
	typedef pair<uint, uint> edge_t;
	inline edge_t mirror(const edge_t &edge) { return {edge.second, edge.first}; }
	
	struct position_t
	{
		edge_t edge;
		float s, t; // barycentric coordinates
	};
	
	struct triangle_t
	{
		vec3 a, b, c;
	};
	
	struct Mesh
	{
		vector<vec3> vertices;
		vector<GLubyte> indices;
		map<edge_t, uint> apex_lookup;
		
		Mesh(GLfloat *vertices, size_t n_vertices, GLubyte *indices, size_t n_indices)
		{
			this->vertices.reserve(n_vertices);
			for (int i=0; i<n_vertices; ++i) {
				this->vertices.emplace_back(vec3(vertices[i*3], vertices[i*3+1], vertices[i*3+2]));
			}
			this->indices.reserve(n_indices);
			this->indices.insert(this->indices.begin(), indices, indices+n_indices);
			
			for (int i=0; i<n_indices; i+=3) {
				uint a = indices[i], b = indices[i+1], c = indices[i+2];
				edge_t e0(a, b), e1(b, c), e2(c, a);
				apex_lookup[e0] = c;
				apex_lookup[e1] = a;
				apex_lookup[e2] = b;
			}
		}
		
		//
		
		/*MeshPosition Raycast(const vec3 &origin, const vec3 &direction)
		{
			
		}*/
		
		//
		
		triangle_t GetTriangle(const edge_t &edge)
		{
			return {
				vertices[edge.first],
				vertices[edge.second],
				vertices[apex_lookup[edge]]
			};
		}
	};
	
}

#endif
