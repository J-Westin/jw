#include "collision/vec2.h"

#include <ostream>
#include <cmath>

namespace jw {

    vec2d::vec2d()
        : x(0.0d), y(0.0d) {}

    vec2d::vec2d(const double x, const double y)
        : x(x), y(y) {}

    vec2d::vec2d(const vec2d& other)
        : x(other.get_x()), y(other.get_y()) {}

    vec2d::~vec2d() {}

    double vec2d::get_x() const { return x; }
    double vec2d::get_y() const { return y; }

    double vec2d::magnitude() {
        return std::sqrt(x*x + y*y);
    }

    void vec2d::rot90cw() {
        double x_old(x), y_old(y);
        x =  y_old;
        y = -x_old;
    }

    void vec2d::rot90ccw() {
        double x_old(x), y_old(y);
        x = -y_old;
        y =  x_old;
    }

    void vec2d::rot180() {
        x = -x;
        y = -y;
    }

    void vec2d::operator=(const vec2d& other) {
        x = other.get_x();
        y = other.get_y();
    }

    void vec2d::operator+=(const vec2d& other) {
        x += other.get_x();
        y += other.get_y();
    }

    void vec2d::operator-=(const vec2d& other) {
        x -= other.get_x();
        y -= other.get_y();
    }

    vec2d rot90cw(const vec2d& u) {
        return vec2d(u.get_y(), -u.get_x());
    }

    vec2d rot90ccw(const vec2d& u) {
        return vec2d(-u.get_y(), u.get_x());
    }

    vec2d rot180(const vec2d& u) {
        return -u;
    }

    vec2d operator-(const vec2d& u) {
        return vec2d(-u.get_x(), -u.get_y());
    }

    vec2d operator+(const vec2d& u, const vec2d& v) {
        return vec2d(u.get_x()+v.get_x(), u.get_y()+v.get_y());
    }

    vec2d operator-(const vec2d& u, const vec2d& v) {
        return u + (-v);
    }

    double operator*(const vec2d& u, const vec2d& v) {
        return u.get_x()*v.get_x() + u.get_y()*v.get_y();
    }

    std::ostream& operator<<(std::ostream& ostr, const vec2d& v) {
        return ostr << '<' << v.get_x() << ',' << v.get_y() << '>';
    }

} // namespace jw
