#include"mesh.h"
Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices,std::string file)
{
    this->Vertices = vertices;
    this->Indices = indices;
		textureFileName = file;

    setupMesh();
}

void Mesh::setupMesh()
{

	Magick::Blob blob;
	Magick::Image *image;
	image = new Magick::Image(textureFileName.c_str());
	image->write(&blob, "RGBA");

	glGenTextures(1,&texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->columns(), image->rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, blob.data());
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	delete image;

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

void Mesh::Draw() 
{
		glEnableVertexAttribArray(0);
  	glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

  	glBindBuffer(GL_ARRAY_BUFFER, VBO);
  	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,texture));
  	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

  	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  	glDisableVertexAttribArray(0);
  	glDisableVertexAttribArray(1);
  	glDisableVertexAttribArray(2);
} 
