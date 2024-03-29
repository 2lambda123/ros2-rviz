/*
 * Copyright (c) 2008, Willow Garage, Inc.
 * Copyright (c) 2018, Bosch Software Innovations GmbH.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RVIZ_RENDERING__MESH_LOADER_HELPERS__STL_LOADER_HPP_
#define RVIZ_RENDERING__MESH_LOADER_HELPERS__STL_LOADER_HPP_

#include <string>
#include <vector>

#include <OgreVector.h>
#include <OgreMesh.h>

namespace rviz_rendering
{

class STLLoader
{
public:
  STLLoader() = default;
  ~STLLoader() = default;

  bool load(uint8_t * buffer, size_t num_bytes, const std::string & origin);

  Ogre::MeshPtr toMesh(const std::string & name);

  struct Triangle
  {
    Ogre::Vector3 vertices_[3];
    Ogre::Vector3 normal_;
  };

  typedef std::vector<Triangle> V_Triangle;
  V_Triangle triangles_;

protected:
  //! Load a binary STL file
  bool loadBinary(uint8_t * buffer);
};

}  // namespace rviz_rendering

#endif  // RVIZ_RENDERING__MESH_LOADER_HELPERS__STL_LOADER_HPP_
