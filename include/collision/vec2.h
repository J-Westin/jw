#ifndef VEC2_H
#define VEC2_H

#include <ostream>

namespace jw {

    class vec2d{
    private:
        double x, y;

    public:
        vec2d();
        vec2d(const double x, const double y);
        vec2d(const vec2d& other);
        ~vec2d();

        double get_x() const;
        double get_y() const;

        double magnitude();

        void rot90cw();
        void rot90ccw();
        void rot180();

        void operator= (const vec2d& other);
        void operator+=(const vec2d& other);
        void operator-=(const vec2d& other);
    };

    vec2d rot90cw (const vec2d& u);
    vec2d rot90ccw(const vec2d& u);
    vec2d rot180  (const vec2d& u);

    vec2d operator-(const vec2d& u); // Negation

    vec2d operator+(const vec2d& u, const vec2d& v);
    vec2d operator-(const vec2d& u, const vec2d& v);

    double operator*(const vec2d& u, const vec2d& v);

    std::ostream& operator<<(std::ostream& ostr, const vec2d& v);


} // namespace jw

#endif // VEC2_H
