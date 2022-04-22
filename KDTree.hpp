#include <array>
#include <vector>
#include <algorithm>


template<typename T, size_t DIM>
class KDTree{
    public:
    using Point = std::array<T, DIM>;

    private:
    struct Node{
        Point point;
        Node *left;
        Node *right;
    };
    using Pointer = Node*;
    Pointer root;

    void insert(std::vector<Point>& points, const size_t from, const size_t to, Pointer& current, const size_t depth){
        if(from == to) return;
        const size_t axis = depth % DIM;
        const size_t median = (from+to)/2;
        std::sort(points.begin()+from, points.begin()+to, [axis](Point const& a, Point const& b){return a[axis] < b[axis];});
        current = new Node{points[median], nullptr, nullptr};
        insert(points, from, median, current->left, depth + 1);
        insert(points, median + 1, to, current->right, depth + 1);
    }

    void clear(Pointer current){
        if(current == nullptr) return;
        clear(current->left);
        clear(current->right);
        delete current;
    }

    public:
    KDTree(std::vector<Point>&& points){
        insert(points, 0, points.size(), root, 0);
    }
    ~KDTree(){
        clear(root);
    }
    bool contains(Point const& point){
        size_t depth = 0;
        Pointer current = root;
        while(current){
            if(point == current->point) return true;
            if(point[depth%DIM] < current->point[depth%DIM]) current = current->left;
            else current = current->right; 
            depth += 1;
        }
        return false;
    }
};