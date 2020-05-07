#pragma once

#include <vector>

#include "pins.h"

// Read only Net
class Net {
    std::vector<unsigned> connected_pins;

   public:
    Net();
    Net(Net &&net);
    Net(std::vector<unsigned> &&conn);

    Net &operator=(Net &&net);

    unsigned at(unsigned index) const;

    unsigned hpwl(const std::vector<Pin> &pin_list) const;
};
