#include "Loaders.hpp"

namespace omi {

namespace loader {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

Geometry* geoFromWavefront(const std::string& filePath) {

    // the unsorted lists of geometry data
    t_VertexArray vertices;
    t_UVArray     uv;
    t_NormalArray normals;
    // the sorted lists of geometry data
    t_VertexArray sortedVertices;
    t_UVArray     sortedUV;
    t_NormalArray sortedNormals;

    // open the file
    std::ifstream file(filePath.c_str());

    // iterate over the file
    while (file.good()) {

        // get the current line as a string
        char lineBuffer[1024];
        file.getline(lineBuffer, 1024);
        std::string line(lineBuffer);

        // split the line
        std::vector<std::string> elements;
        util::str::split(line, ' ', elements);

        // go to the next line if this is empty
        if (elements.size() == 0) {

            continue;
        }

        // vertex coord
        if (!elements[0].compare("v")) {

            // check that the line has a enough elements
            if (elements.size() < 4 || elements.size() > 4) {

                //TODO: throw an exception
                std::cout <<
                    "WAVEFRONT LOADER: wrong number of vertex coords" <<
                    std::endl;
            }

            // TODO: check if valid floats

            // add to the list of all vertices
            vertices.push_back(util::vec::Vector3(
                    static_cast<float>(atof(elements[1].c_str())),
                    static_cast<float>(atof(elements[2].c_str())),
                    static_cast<float>(atof(elements[3].c_str()))));
        }
        // UV coordinate
        else if (!elements[0].compare("vt")) {

            // check that the line has a enough elements
            if (elements.size() < 3 || elements.size() > 3) {

                //TODO: throw an exception
                std::cout <<
                    "WAVEFRONT LOADER: wrong number of uv coords" <<
                    std::endl;
            }

            // TODO: check if valid floats

            // add to the list of all UV coordinates
            uv.push_back(util::vec::Vector2(
                    static_cast<float>(atof(elements[1].c_str())),
                    static_cast<float>(atof(elements[2].c_str()))));
        }
        // normal
        else if (!elements[0].compare("vn")) {

            // check that the line has a enough elements
            if (elements.size() < 4 || elements.size() > 4) {

                //TODO: throw an exception
                std::cout <<
                    "WAVEFRONT LOADER: wrong number of normal coords" <<
                    std::endl;
            }

            // TODO: check if valid floats

            // add to the list of all vertices
            normals.push_back(util::vec::Vector3(
                    static_cast<float>(atof(elements[1].c_str())),
                    static_cast<float>(atof(elements[2].c_str())),
                    static_cast<float>(atof(elements[3].c_str()))));
        }
        // face
        else if (!elements[0].compare("f")) {

            // check that the line has a enough elements
            if (elements.size() < 4 || elements.size() > 4) {

                //TODO: throw an exception
                std::cout <<
                    "WAVEFRONT LOADER: wrong number of face coords" <<
                    std::endl;
            }

            // iterate over the coordinates
            for (unsigned i = 0; i < 3; ++i) {

                //split again
                line = elements[i + 1];
                std::vector<std::string> faceCoords;
                util::str::split(line, '/', faceCoords);

                // TODO: check indices are valid unsigned ints

                // vertices only
                if (faceCoords.size() == 1) {

                    sortedVertices.push_back(
                        vertices[atoi(faceCoords[0].c_str()) - 1]);
                }
                // vertices and normals
                else if (faceCoords.size() == 2) {

                    sortedVertices.push_back(
                        vertices[atoi(faceCoords[0].c_str()) - 1]);
                    sortedNormals.push_back(
                        normals [atoi(faceCoords[1].c_str()) - 1]);
                }
                // vertices, UV coordinates, and normals
                else if (faceCoords.size() == 3) {

                    //add to the sorted lists
                    sortedVertices.push_back(
                        vertices[atoi(faceCoords[0].c_str()) - 1]);
                    sortedUV.push_back(
                        uv      [atoi(faceCoords[1].c_str()) - 1]);
                    sortedNormals.push_back(
                        normals [atoi(faceCoords[2].c_str()) - 1]);
                }
                else {

                    // TODO: error that shit!
                }
            }
        }
    }

    return new Geometry(sortedVertices, sortedUV, sortedNormals);
}

} // namespace loader

} // namespace omi