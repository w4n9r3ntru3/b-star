#pragma once

#include <string>
#include <utility>
#include <vector>

#include "pins.h"

class BStar {
    std::vector<unsigned> nodes;

   public:
    BStar();
    BStar(std::vector<Pin> &pin_list, unsigned width, unsigned height);

    unsigned get_size() const;
    unsigned get_root() const;
    void check(const std::vector<Pin> &pin_list) const;
    std::pair<int, int> update(std::vector<Pin> &pin_list) const;

    void flip(std::vector<Pin> &pin_list) const;

    void permute(std::vector<Pin> &pin_list, const unsigned idx) const;
    void swap(std::vector<Pin> &pin_list, const unsigned i, const unsigned j);
    void delete_insert(std::vector<Pin> &pin_list, const unsigned from,
                       const unsigned to, const bool from_side,
                       const bool to_side) const;
    void mirror(std::vector<Pin> &pin_list, const unsigned i) const;

    unsigned random_permute(std::vector<Pin> &pin_list) const;
    std::pair<unsigned, unsigned> random_swap(std::vector<Pin> &pin_list);
    std::pair<std::pair<unsigned, bool>, std::pair<unsigned, bool>>
    random_delete_insert(std::vector<Pin> &pin_list) const;
    unsigned random_mirror(std::vector<Pin> &pin_list) const;

    void revert_permute(std::vector<Pin> &pin_list,
                        const unsigned action) const;
    void revert_swap(std::vector<Pin> &pin_list,
                     const std::pair<unsigned, unsigned> action);
    void revert_delete_insert(
        std::vector<Pin> &pin_list,
        const std::pair<std::pair<unsigned, bool>, std::pair<unsigned, bool>>
            action) const;
    void revert_mirror(std::vector<Pin> &pin_list, const unsigned action) const;
};
