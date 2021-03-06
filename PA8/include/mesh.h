#include"graphics_headers.h"
#include <vector>
class Mesh {
    public:
        /*  Mesh Data  */
        std::vector<Vertex> Vertices;
        std::vector<unsigned int> Indices;

        //vector<Texture> textures;
        /*  Functions  */
        Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, std::string file);
        void Draw();
    private:
        /*  Render data  */
        unsigned int VAO, VBO, EBO;

				GLuint texture;
				std::string textureFileName;
        /*  Functions    */
        void setupMesh();
};
