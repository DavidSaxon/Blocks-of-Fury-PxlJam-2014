#ifndef UTILITRON_MATHUTIL_H_
#   define UTILITRON_MATHUTIL_H_

#include <cmath>

namespace util {

/***************************************\
| Utilities functions relating to math. |
\***************************************/
namespace math {

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

static const float DEGREES_TO_RADIANS = 0.0174532925f;
static const float RADIANS_TO_DEGREES = 57.2957795f;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/** Clamps a value between two thresholds
@param v the value to clamp
@param lower the lower threshold
@param upper the upper threshold
@return the result of the clamping */
template<typename T>
inline T clamp(T v, T lower, T upper) {

    if (v < lower) {

        return lower;
    }
    if (v > upper) {

        return upper;
    }

    return v;
}

/** Clamps a value above a threshold (so that the value is always equal to or
greater than the threshold)
@param v the value to clamp
@param threshold the theshold to clamp above
@return the result of the clamping */
template<typename T>
inline T clampAbove(T v, T threshold) {

    if (v < threshold) {

        return threshold;
    }

    return v;
}

/** Clamps a value below a threshold (so that the value is always equal to
or less than the threshold)
@param v the value to clamp
@param threshold the threshold to clamp below
@return the result of the clamping */
template<typename T>
inline T clampBelow(T v, T threshold) {

    if (v > threshold) {

        return threshold;
    }

    return v;
}

/** Checks if two values are within a distance of each other
@param a the first value to compare
@param b the second value to compare
@param distance the greatest distance the values can be apart
@return if the values are within the given distance of each other */
template<typename T>
inline bool withinDistance(T a, T b, T distance) {

    // return if abs is less than
    return abs(a - b) <= distance;
}

/** Checks if two values are within a distance of each other
@param a the first value to compare
@param b the second value to compare
@param distance the greatest distance the values can be apart
@return if the values are within the given distance of each other */
template<>
inline bool withinDistance(float a, float b, float distance) {

    // return if abs is less than
    return fabs(a - b) <= distance;
}

/** Checks if two values are within a distance of each other
@param a the first value to compare
@param b the second value to compare
@param distance the greatest distance the values can be apart
@return if the values are within the given distance of each other */
template<>
inline bool withinDistance(double a, double b, double distance) {

    // return if abs is less than
    return fabs(a - b) <= distance;
}

/** Returns the sine of the given angle being in degrees
@param angle the angle in degrees to compute the sine of */
inline float sind(float angle) {

    return sin(angle * DEGREES_TO_RADIANS);
}

/** Returns the co-sine of the given angle being in degrees
@param angle the angle in degrees to compute the co-sine of */
inline float cosd(float angle) {

    return cos(angle * DEGREES_TO_RADIANS);
}

} // namespace math

} // namespace util

#endif
