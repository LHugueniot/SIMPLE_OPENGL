#include "ImportGeometry.h"

aiScene const * importScene(std::string const & scenePath, 
                            unsigned int importFlags = aiProcess_CalcTangentSpace | 
                                                       aiProcess_Triangulate | 
                                                       aiProcess_JoinIdenticalVertices | 
                                                       aiProcess_SortByPType){
    aiScene const * scene = aiImportFile(scenePath.c_str(), importFlags);
    if(scene==nullptr)
    {
        std::cout<<scenePath<<" failed to load with error:"<<std::endl;
        std::cout<<aiGetErrorString()<<std::endl;
    }
    return scene;
}

std::vector<aiMesh*> 
    getMeshesFromScene(aiScene * scene){

    std::vector<aiMesh*> ret;
    if(scene->HasMeshes()){
        ret.resize(scene->mNumMeshes);
        for(size_t meshIdx=0; meshIdx<scene->mNumMeshes; meshIdx++)
            ret[meshIdx] = scene->mMeshes[meshIdx];
    }
    return ret;
}

bool getMeshData(aiMesh const & mesh,  // Assume mesh is exclusively triangulated
                 std::vector<float> & vertexPositions, 
                 std::vector<uint> & edgeIndices,
                 std::vector<uint> & triFaceIndices){

    if(mesh.mNumVertices < 1 || mesh.mNumFaces < 1)
        return false;
    std::set<std::array<uint,2>> edgeSet;

    vertexPositions.resize(mesh.mNumVertices * 3);
    for(size_t v=0; v<mesh.mNumVertices; v++){
        vertexPositions[v * 3] = mesh.mVertices[v].x;
        vertexPositions[v * 3 + 1] = mesh.mVertices[v].y;
        vertexPositions[v * 3 + 2] = mesh.mVertices[v].z;
    }
    // Assimp sorts faces in clockwise order so no other processing necessary
    triFaceIndices.resize(mesh.mNumFaces*3);

    for(size_t f=0; f<mesh.mNumFaces; f++){
        auto fi0 = mesh.mFaces[f].mIndices[0];
        auto fi1 = mesh.mFaces[f].mIndices[1];
        auto fi2 = mesh.mFaces[f].mIndices[2];
        triFaceIndices[f * 3]     = fi0;
        triFaceIndices[f * 3 + 1] = fi1;
        triFaceIndices[f * 3 + 2] = fi2;
        edgeSet.insert({(fi0 < fi1 ? fi0 : fi1), (fi0 > fi1 ? fi0 : fi1)});
        edgeSet.insert({(fi1 < fi2 ? fi1 : fi2), (fi1 > fi2 ? fi1 : fi2)});
        edgeSet.insert({(fi2 < fi0 ? fi2 : fi0), (fi2 > fi0 ? fi2 : fi0)});
    }
    edgeIndices.resize(edgeSet.size() * 2);

    size_t e = 0;
    for(auto const & edge : edgeSet){
        edgeIndices[e * 2] = edge[0];
        edgeIndices[e * 2 + 1] = edge[1];
        e++;
    }
    return true;
}
