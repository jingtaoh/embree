// ======================================================================== //
// Copyright 2009-2019 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#include "../common/device.h"

#if defined(EMBREE_DPCPP_SUPPORT)

#include <CL/sycl.hpp>

namespace embree
{
  namespace gpu
  {
    class AABB {
    public:
      cl::sycl::float4 lower;
      cl::sycl::float4 upper;
      AABB() = default;

      inline void init()
      {
	const float pos_inf =  INFINITY;
	const float neg_inf = -INFINITY;       
	lower = (cl::sycl::float4)(pos_inf,pos_inf,pos_inf,0);
	upper = (cl::sycl::float4)(neg_inf,neg_inf,neg_inf,0);	
      }

      inline void extend(class AABB &aabb)
      {
	lower = min(lower,aabb.lower);
	upper = max(upper,aabb.upper);	
      }

      inline void extend(const cl::sycl::float4 &v)
      {
	lower = min(lower,v);
	upper = max(upper,v);	
      }

      inline void enlarge(const cl::sycl::float4 &v)
      {
	lower -= v;
	upper += v;	
      }

      inline cl::sycl::float4 size()
      {
	return upper - lower;
      }

      inline cl::sycl::float4 centroid2()
      {
	return upper + lower;
      }

      

    };
  };
};

#endif
