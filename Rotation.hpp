
#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "Coordinate.hpp"
#include "Constants.hpp"
#include <cmath>
#include <vector>

/**
 * Rotates the given point around the origin,
 * by a certain number of degrees
 * Modifies the point!
 */
void rotate(Coordinate& point, double degrees)
{
    double temp_x = point.x;
    double costh = std::cos(degrees * values::toRadians);
    double sinth = std::sin(degrees * values::toRadians);

    point.x = costh*temp_x + -sinth*point.y;
    point.y = sinth*temp_x +  costh*point.y;
}
/**
 * Same as above, but rotates the point about
 * the given axis instead of (0, 0)
 */
void rotate(Coordinate& point, double degrees, const Coordinate& axis)
{
    /// Current Method, probably a bit of unneeded arithmetic:
    /// 1. Translate the points to make the rotation be around (0,0)
    /// 2. Do normal rotation.
    /// 3. Reverse the translation.
    double costh = std::cos(degrees * values::toRadians);
    double sinth = std::sin(degrees * values::toRadians);

    /// 1:
    point.x -= axis.x;
    point.y -= axis.y;
    double temp_x = point.x;
    /// 2:
    point.x = costh*temp_x + -sinth*point.y;
    point.y = sinth*temp_x +  costh*point.y;
    /// 3:
    point.x += axis.x;
    point.y += axis.y;
    /// Done!
}

/**
 * Rotates the set of points, by the given angle,
 * about the origin (0, 0) [the z-axis].
 * Mutates the given points.
 *
 * Convenient if the set of points represents
 * one shape or curve.
 */
void rotate(std::vector<Coordinate>& points, double degrees)
{
    double costh = std::cos(degrees * values::toRadians);
    double sinth = std::sin(degrees * values::toRadians);
    for (std::size_t i = 0; i < points.size(); i++)
    {
        double temp_x = points[i].x;
        points[i].x = costh*temp_x + -sinth*points[i].y;
        points[i].y = sinth*temp_x +  costh*points[i].y;
    }
}
/**
 * Rotates the set of points, by the given angle,
 * about the given (x, y) point's axis.
 * Mutates the given points.
 */
void rotate(std::vector<Coordinate>& points, double degrees, const Coordinate& axis)
{
    /// Same method as the single-point rotation about an arbitrary axis.
    double costh = std::cos(degrees * values::toRadians);
    double sinth = std::sin(degrees * values::toRadians);

    for (std::size_t i = 0; i < points.size(); i++)
    {
        /// 1:
        points[i].x -= axis.x;
        points[i].y -= axis.y;
        double temp_x = points[i].x;
        /// 2:
        points[i].x = costh*temp_x + -sinth*points[i].y;
        points[i].y = sinth*temp_x +  costh*points[i].y;
        /// 3:
        points[i].x += axis.x;
        points[i].y += axis.y;
    }
}

#endif // ROTATION_HPP
