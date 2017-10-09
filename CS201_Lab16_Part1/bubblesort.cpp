//
//  bubblesort.cpp
//  Playground
//
//  Created by Chris Hartman on 10/6/17.
//  Copyright © 2017 Chris Hartman. All rights reserved.
//  Written in class CS 201 Fall 2017

#include "bubblesort.hpp"

void bubblesort(std::vector<int> &v) {
    for(auto top = v.size()-1; top >= 1; --top) {
        for(auto lo = 0u; lo < top; lo++) {
            auto hi = lo+1;
            if (v[lo] > v[hi]) {
                auto save_lo = v[lo];
                v[lo] = v[hi];
                v[hi] = save_lo;
            }
        }
    }
}
