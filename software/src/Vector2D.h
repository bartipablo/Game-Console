#ifndef Vector2D_H
#define Vector2D_H


/**
 * @brief Class representing a two-dimensional vector.
 * 
 */
class Vector2D {
public:        
    Vector2D() : x_(0), y_(0) {}

    Vector2D(int x, int y) : x_(x), y_(y) {}  

    int x() const {
        return x_;
    }

    int y() const {
        return y_;
    }

    /**
     * @brief Equality operator.
     * 
     * Compares two vectors and returns true if they have the same x and y coordinates, otherwise false.
     * 
     * @param other The vector to compare with.
     * @return True if the vectors are equal, false otherwise.
     */
    bool operator==(const Vector2D& other) const {
        return x_ == other.x() && y_ == other.y();
    }

    /**
     * @brief Less than operator.
     * 
     * Compares two vectors and returns true if the calling vector is "less than" the other vector.
     * Comparison order is first by x-coordinate, and if equal, by y-coordinate.
     * Required for std::map!
     * 
     * @param other The vector to compare with.
     * @return True if the calling vector is less than the other vector, false otherwise.
     */
    bool operator<(const Vector2D& other) const {
        if (x_ == other.x()) {
            return y_ < other.y();
        }
        return x_ < other.x();
    }

private:
    int x_;

    int y_;
};

#endif