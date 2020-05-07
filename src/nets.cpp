#include "nets.h"

#include <assert.h>

#include <memory>
#include <unordered_set>
#include <utility>

using namespace std;

Net::Net() : connected_pins(vector<unsigned>()) {}

Net::Net(Net &&net) : connected_pins(move(net.connected_pins)) {}

Net::Net(vector<unsigned> &&conn) : connected_pins(move(conn)) {}

Net &Net::operator=(Net &&net) {
    connected_pins = move(net.connected_pins);
    return *this;
}

unsigned Net::at(unsigned index) const {
    return this->connected_pins.at(index);
}

static pair<unsigned, unsigned> get_center(const Pin &pin) {
    if (!pin.area_nonzero()) {
        assert(pin.get_width() == 0);
        assert(pin.get_height() == 0);
    }
    return make_pair(pin.get_xpos() + (pin.get_width() >> 1),
                     pin.get_ypos() + (pin.get_height() >> 1));
}

unsigned Net::hpwl(const vector<Pin> &pin_list) const {
    unsigned max_w, min_w, max_h, min_h;
    auto center = get_center(pin_list[connected_pins[0]]);

    max_w = min_w = center.first;
    max_h = min_h = center.second;
    const Pin &pin = pin_list[connected_pins[0]];

    for (unsigned i = 1, x, y; i < connected_pins.size(); ++i) {
        center = get_center(pin_list[connected_pins[i]]);
        x = center.first;
        y = center.second;
        const Pin &pin = pin_list[connected_pins[i]];
        if (max_w < x) max_w = x;
        if (min_w > x) min_w = x;
        if (max_h < y) max_h = y;
        if (min_h > y) min_h = y;
    }
    assert(max_w >= min_w);
    assert(max_h >= min_h);
    return max_w - min_w + max_h - min_h;
}
