// Copyright 2009-2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#include "../common/tutorial/tutorial.h"

namespace embree
{
  struct Tutorial : public TutorialApplication
  {
    Tutorial()
      : TutorialApplication("bvh_builder",FEATURE_RTCORE)
    {
      interactive = false;
    }
  };

}

int main(int argc, char** argv) {
  return embree::Tutorial().main(argc,argv);
}
