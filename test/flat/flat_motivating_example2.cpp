// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "boost/pfr.hpp"

struct my_struct { // no ostream operator defined!
    std::string s;
    int i;
};

int main() {
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
    using namespace boost::pfr::flat_ops; // C++17 out-of-the-box ostream operators for aggregate initializables!

    my_struct s{{"Das ist fantastisch!"}, 100};
    std::cout << "my_struct has " << boost::pfr::flat_tuple_size<my_struct>::value
        << " fields: " << s << "\n";
#endif
}
