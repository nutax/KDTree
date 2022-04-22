#include <iostream>
#include "KDTree.hpp"

int main(){
    /* INSERT */
    KDTree<float, 2> tree( { {3,6}, {17,15}, {13,15}, {6,12}, {9,1}, {2,7}, {10,10} } );
    
    /* SEARCH */
    std::cout << tree.contains({3, 6}) << std::endl;
    std::cout << tree.contains({6, 12}) << std::endl;
    std::cout << tree.contains({10, 10}) << std::endl;
    std::cout << tree.contains({17, 15}) << std::endl;
    std::cout << tree.contains({9, 1}) << std::endl;
    std::cout << tree.contains({2, 7}) << std::endl;
    std::cout << tree.contains({13, 15}) << std::endl;
    std::cout << tree.contains({9, 2}) << std::endl;
    std::cout << tree.contains({1, 1}) << std::endl;
    return 0;
}