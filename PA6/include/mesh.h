#include"graphics_headers.h"
#include <vector>
class Mesh {
    public:
        /*  Mesh Data  */
        std::vector<Vertex> Vertices;
        std::vector<unsigned int> Indices;
	GLuint texture;
        //vector<Texture> textures;
        /*  Functions  */
        Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices/*, vector<Texture> textures*/);
        void Draw();
    private:
        /*  Render data  */
        unsigned int VAO, VBO, EBO;
        /*  Functions    */
        void setupMesh();
};
