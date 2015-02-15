#ifndef UTILITRON_VECTOR_VECTOR_H_
#   define UTILITRON_VECTOR_VECTOR_H_

#include <cmath>
#include <iostream>
#include <sstream>

#include "MathUtil.hpp"
#include "exceptions/CollectionException.hpp"

namespace util {

/****************************************\
| Mutable vector classes and vector math |
\****************************************/
namespace vec {

/***************************************************************************\
| A two dimensional vector that provides component access, basic operators, |
| and constructor functions.                                                |
\***************************************************************************/
class Vector2 {


    //--------------------------------------------------------------------------
    //                              FRIEND FUNCTIONS
    //--------------------------------------------------------------------------

    /** Prints this vector to the output stream
    @param output the output steam to print to
    @param v the vector to print
    @return the modified output stream */
    inline friend std::ostream& operator <<(std::ostream& output,
        const Vector2& v) {

        output << v.toString();

        return output;
    }

public:


    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //------------------------POSITION COMPONENT ACCESS-------------------------

    //! x position access component
    float x;
    //! y position access component
    float y;

    //-------------------------COLOUR COMPONENT ACCESS--------------------------

    //! red colour access component (alias of x)
    float& r;
    //! green colour access component (alias of y)
    float& g;

    //-----------------------MEASUREMENT COMPONENT ACCESS-----------------------

    //! width measurement access component (alias of x)
    float& width;
    //! height measurement access component (alias of y)
    float& height;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new two dimensional vector with components
    initialised as zero */
    inline Vector2() :
        x(0),
        y(0),
        r(x),
        g(y),
        width(x),
        height(y)
        {
    }

    /** Creates a new two dimensional vector with the given values
    @param p_x the x value of the vector
    @param p_y the y value of the vector */
    inline Vector2(float p_x, float p_y) :
        x(p_x),
        y(p_y),
        r(x),
        g(y),
        width(x),
        height(y) {
    }

    /** Creates a new two dimensional vector by the copying the values from
    the given 2d vector
    @param v2 the 2d vector copy from */
    inline Vector2(const Vector2& v2) :
        x(v2.x),
        y(v2.y),
        r(x),
        g(y),
        width(x),
        height(y) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    inline ~Vector2() {
    }

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    //--------------------------------ASSIGNMENT--------------------------------

    /** Sets the values of this vector by copying the values from the
    other given vector
    @param other the vector to copy from */
    inline Vector2& operator =(const Vector2& other) {

        x = other.x;
        y = other.y;

        return *this;
    }

    /** Sets the values of the vector to the given scalar
    @param scalar the scalar to set all values to */
    inline Vector2& operator =(float scalar) {

        x = scalar;
        y = scalar;

        return *this;
    }

    //---------------------------------EQUALITY---------------------------------

    /** @return if this vector and the other given vector are equal */
    inline bool operator ==(const Vector2& other) const {

        return x == other.x && y == other.y;
    }

    /** @return if this vector and the other given vector are not equal */
    inline bool operator !=(const Vector2& other) const {

        return !((*this) == other);
    }

    //--------------------------------SUBSCRIPT---------------------------------

    /** Gets the component of the vector at the given index
    @param index the component to get
    @return the value of the component */
    inline float& operator [](unsigned index) {

        // check that the index is within bounds
        if (index > 1) {

            util::ex::IndexOutOfBoundsException("index is greater than 1.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            default: {

                return y;
            }
        }
    }

    /** Gets the component of the vector at the given index
    @param index the component to get
    @return the value of the component */
    inline const float& operator [](unsigned index) const {

        // check that the index is within bounds
        if (index > 1) {

            util::ex::IndexOutOfBoundsException("index is greater than 1.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            default: {

                return y;
            }
        }
    }

    //----------------------------------UNARY-----------------------------------

    /** @return a copy of the vector which has been negated */
    inline Vector2 operator -() const {

        return Vector2(-x, -y);
    }

    //---------------------------------ADDITION---------------------------------

    /** Creates a new vector as the result of the addition of the components
    of this vector with the given scalar
    @param scalar the scalar to add
    @return the result of the addition */
    inline Vector2 operator +(float scalar) const {

        return Vector2(x + scalar, y + scalar);
    }

    /** Adds the given scalar to the components of this vector
    @param scalar the scalar to add */
    inline void operator +=(float scalar) {

        x += scalar;
        y += scalar;
    }

    /** Creates a new vector as the result of the addition of this vector
    and the other given vector
    @param other the vector to add to this
    @return the result of the addition */
    inline Vector2 operator +(const Vector2& other) const {

        return Vector2(x + other.x, y + other.y);
    }

    /** Adds the given vector to this vector
    @param other the vector to add to this */
    inline void operator +=(const Vector2& other) {

        x += other.x;
        y += other.y;
    }

    //-------------------------------SUBTRACTION--------------------------------

    /** Creates a new vector as the result of the subtraction of the
    scalar from the components of this vector
    @param scalar the scalar to subtract from the components
    @return the result of the subtraction */
    inline Vector2 operator -(float scalar) const {

        return Vector2(x - scalar, y - scalar);
    }

    /** Subtracts the given scalar from the components of this vector
    @param scalar the scalar to subtract from the components */
    inline void operator -=(float scalar) {

        x -= scalar;
        y -= scalar;
    }

    /** Creates a new vector as the result of the subtraction of the
    given vector from this vector
    @param other the vector to subtract from this
    @return the result of the subtraction */
    inline Vector2 operator -(const Vector2& other) const {

        return Vector2(x - other.x, y - other.y);
    }

    /** Subtracts the given vector from this vector
    @param other the vector to subtract from this */
    inline void operator -=(const Vector2& other) {

        x -= other.x;
        y -= other.y;
    }

    //------------------------------MULTIPLICATION------------------------------

    /** Creates a new vector as the result of the multiplication of the
    components of this vector by the given scalar
    @param scalar the scalar to multiply the components by
    @return the result of the multiplication */
    inline Vector2 operator *(float scalar) const {

        return Vector2(x * scalar, y * scalar);
    }

    /** Multiplies the components of this vector by the given scalar
    @param scalar the scalar to multiply the components by */
    inline void operator *=(float scalar) {

        x *= scalar;
        y *= scalar;
    }

    //---------------------------------DIVISION---------------------------------

    /** Creates a new vector as the result of the division of the
    components of this vector by the given scalar
    @param scalar the scalar to divide the components by
    @return the result of the division */
    inline Vector2 operator /(float scalar) const {

        return Vector2(x / scalar, y / scalar);
    }

    /** Divides the components of this vector by the given scalar
    @param scalar the scalar to divide the components by */
    inline void operator /=(float scalar) {

        x /= scalar;
        y /= scalar;
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //-----------------------STATIC CONSTRUCTOR FUNCTIONS-----------------------

    /** @return the zero two dimensional vector */
    inline static Vector2 zero() {

        return Vector2(0, 0);
    }

    /** @return the x axis vector */
    inline static Vector2 xAxis() {

        return Vector2(1, 0);
    }

    /** @return the y axis vector */
    inline static Vector2 yAxis() {

        return Vector2(0, 1);
    }

    //--------------------------CONSTRUCTOR FUNCTIONS---------------------------

    /** @return a copy of this vector */
    inline Vector2 clone() const {

        return Vector2(x, y);
    }

    /** #Hidden */
    inline Vector2 xy() const {

        return Vector2(x, y);
    }

    /** #Hidden */
    inline Vector2 yx() const {

        return Vector2(y, x);
    }

    //---------------------------FORMATING FUNCTIONS----------------------------

    /** @return the vector in string format */
    inline std::string toString() const {

        std::stringstream ss;
        ss << "[" << x << ", " << y << "]";

        return ss.str();
    }
};


/*****************************************************************************\
| A three dimensional vector that provides component access, basic operators, |
| and constructor functions.                                                  |
\*****************************************************************************/
class Vector3 {

    //--------------------------------------------------------------------------
    //                              FRIEND FUNCTIONS
    //--------------------------------------------------------------------------

    /** Prints the vector to the output stream
    @param output the output stream to print to
    @param v the vector to print
    @return the modified output stream */
    inline friend std::ostream& operator <<(std::ostream& output,
        const Vector3& v) {

        output << v.toString();

        return output;
    }

public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //------------------------POSITION COMPONENT ACCESS-------------------------

    //! x position access component
    float x;
    //! y position access component
    float y;
    //! z position access component
    float z;

    //-------------------------COLOUR COMPONENT ACCESS--------------------------

    //! red colour access component (alias of x)
    float& r;
    //! green colour access component (alias of y)
    float& g;
    //! blue colour access component (alias of z)
    float& b;

    //-----------------------MEASUREMENT COMPONENT ACCESS-----------------------

    //! width measurement access component (alias of x)
    float& width;
    //! height measurement access component (alias of x)
    float& height;
    //! depth measurement access component (alias of x)
    float& depth;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new three dimensional vector with components
    initialised as zero */
    inline Vector3() :
        x(0),
        y(0),
        z(0),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new three dimensional vector with the given values
    @param p_x the x component of the vector
    @param p_y the y component of the vector
    @param p_z the z component of the vector */
    inline Vector3(float p_x, float p_y, float p_z) :
        x(p_x),
        y(p_y),
        z(p_z),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new three dimensional vector by the copying the values from
    the given 3d vector
    @param v3 the 3d vector to copy from */
    inline Vector3(const Vector3& v3) :
        x(v3.x),
        y(v3.y),
        z(v3.z),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new three dimensional vector by copying the x and y components
    from the given 2d vector and the z component from the given value
    @param v2 the 2d vector to copy from
    @param p_z the z value of the vector */
    inline Vector3(const Vector2& v2, float p_z) :
        x(v2.x),
        y(v2.y),
        z(p_z),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new three dimensional from the given x value and copying
    the y and z components from the given 2d vector
    @param p_x the x value of the vector
    @param v2 the 2d vector to copy from */
    inline Vector3(float p_x, const Vector2& v2) :
        x(p_x),
        y(v2.x),
        z(v2.y),
        r(x),
        g(y),
        b(z),
        width(x),
        height(y),
        depth(z) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    inline ~Vector3() {
    }

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    //--------------------------------ASSIGNMENT--------------------------------

    /** Sets the values of this vector by copying the values from the
    other given vector
    @param other the vector to copy from */
    inline Vector3& operator =(const Vector3& other) {

        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }

    /** Sets the values of the vector to the given scalar
    @param scalar the scalar to set all values to */
    inline Vector3& operator =(float scalar) {

        x = scalar;
        y = scalar;
        z = scalar;

        return *this;
    }

    //---------------------------------EQUALITY---------------------------------

    /** @return if this vector and the other given vector are equal */
    inline bool operator ==(const Vector3& other) const {

        return x == other.x && y == other.y && z == other.z;
    }

    /** @return if this vector and the other given vector are not equal */
    inline bool operator !=(const Vector3& other) const {

        return !((*this) == other);
    }

    //--------------------------------SUBSCRIPT---------------------------------

    /** Gets the component of the vector at the given index
    @param index the component to get
    @return the value of the component */
    inline float& operator [](unsigned index) {

        // check that the index is within bounds
        if (index > 2) {

            util::ex::IndexOutOfBoundsException("index is greater than 2.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            case 1: {

                return y;
            }
            default: {

                return z;
            }
        }
    }

    /** Gets the component of the vector at the given index
    @param index the component to get
    @return the value of the component */
    inline const float& operator [](unsigned index) const {

        // check that the index is within bounds
        if (index > 2) {

            util::ex::IndexOutOfBoundsException("index is greater than 2.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            case 1: {

                return y;
            }
            default: {

                return z;
            }
        }
    }

    //----------------------------------UNARY-----------------------------------

    /** @return a copy of the vector which has been negated */
    inline Vector3 operator -() const {

        return Vector3(-x, -y, -z);
    }

    //---------------------------------ADDITION---------------------------------

    /** Creates a new vector as the result of the addition of the components
    of this vector with the given scalar
    @param scalar the scalar to add
    @return the result of the addition */
    inline Vector3 operator +(float scalar) const {

        return Vector3(x + scalar, y + scalar, z + scalar);
    }

    /** Adds the given scalar to the components of this vector
    @param scalar the scalar to add */
    inline void operator +=(float scalar) {

        x += scalar;
        y += scalar;
        z += scalar;
    }

    /** Creates a new vector as the result of the addition of this vector
    and the other given vector
    @param other the vector to add to this
    @return the result of the addition */
    inline Vector3 operator +(const Vector3& other) const {

        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    /** Adds the given vector to this vector
    @param other the vector to add to this */
    inline void operator +=(const Vector3& other) {

        x += other.x;
        y += other.y;
        z += other.z;
    }

    //-------------------------------SUBTRACTION--------------------------------

    /** Creates a new vector as the result of the subtraction of the
    scalar from the components of this vector
    @param scalar the scalar to subtract from the components
    @return the result of the subtraction */
    inline Vector3 operator -(float scalar) const {

        return Vector3(x - scalar, y - scalar, z - scalar);
    }

    /** Subtracts the given scalar from the components of this vector
    @param scalar the scalar to subtract from the components */
    inline void operator -=(float scalar) {

        x -= scalar;
        y -= scalar;
        z -= scalar;
    }

    /** Creates a new vector as the result of the subtraction of the
    given vector from this vector
    @param other the vector to subtract from this
    @return the result of the subtraction */
    inline Vector3 operator -(const Vector3& other) const {

        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    /** Subtracts the given vector from this vector
    @param other the vector to subtract from this */
    inline void operator -=(const Vector3& other) {

        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    //------------------------------MULTIPLICATION------------------------------

    /** Creates a new vector as the result of the multiplication of the
    components of this vector by the given scalar
    @param scalar the scalar to multiply the components by
    @return the result of the multiplication */
    inline Vector3 operator *(float scalar) const {

        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    /** Multiplies the components of this vector by the given scalar
    @param scalar the scalar to multiply the components by */
    inline void operator *=(float scalar) {

        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    //---------------------------------DIVISION---------------------------------

    /** Creates a new vector as the result of the division of the
    components of this vector by the given scalar
    @param scalar the scalar to divide the components by
    @return the result of the division */
    inline Vector3 operator /(float scalar) const {

        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    /** Divides the components of this vector by the given scalar
    @param scalar the scalar to divide the components by */
    inline void operator /=(float scalar) {

        x /= scalar;
        y /= scalar;
        z /= scalar;
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //-----------------------STATIC CONSTRUCTOR FUNCTIONS-----------------------

    /** @return the zero three dimensional vector */
    inline static Vector3 zero() {

        return Vector3(0, 0, 0);
    }

    /** @return the x axis vector */
    inline static Vector3 xAxis() {

        return Vector3(1, 0, 0);
    }

    /** @return the y axis vector */
    inline static Vector3 yAxis() {

        return Vector3(0, 1, 0);
    }

    /** @return the z axis vector */
    inline static Vector3 zAxis() {

        return Vector3(0, 0, 1);
    }

    //--------------------------CONSTRUCTOR FUNCTIONS---------------------------

    /** @returns a copy of this vector */
    inline Vector3 clone() const {

        return Vector3(x, y, z);
    }

    /** #Hidden */
    inline Vector2 xy() const {

        return Vector2(x, y);
    }

    /** #Hidden */
    inline Vector2 yx() const {

        return Vector2(y, x);
    }

    /** #Hidden */
    inline Vector2 yz() const {

        return Vector2(y, z);
    }

    /** #Hidden */
    inline Vector2 zy() const {

        return Vector2(z, y);
    }

    /** #Hidden */
    inline Vector2 xz() const {

        return Vector2(x, z);
    }

    /** #Hidden */
    inline Vector2 zx() const {

        return Vector2(z, x);
    }

    /** #Hidden */
    inline Vector3 xyz() const {

        return Vector3(x, y, z);
    }

    /** #Hidden */
    inline Vector3 xzy() const {

        return Vector3(x, z, y);
    }

    /** #Hidden */
    inline Vector3 yxz() const {

        return Vector3(y, x, z);
    }

    /** #Hidden */
    inline Vector3 yzx() const {

        return Vector3(y, z, x);
    }

    /** #Hidden */
    inline Vector3 zxy() const {

        return Vector3(z, x, y);
    }

    /** #Hidden */
    inline Vector3 zyx() const {

        return Vector3(z, y, x);
    }

    //---------------------------FORMATTING FUNCTIONS---------------------------

    /** @return the vector in string format */
    inline std::string toString() const {

        std::stringstream ss;
        ss << "[" << x << ", " << y << ", " << z << "]";

        return ss.str();
    }
};

/***************************************************************************\
| A two dimensional vector that provides component access, basic operators, |
| and constructor functions                                                 |
\***************************************************************************/
class Vector4 {

    //--------------------------------------------------------------------------
    //                              FRIEND FUNCTIONS
    //--------------------------------------------------------------------------

    /** Prints the vector to the output stream
    @param output the output stream to print to
    @param v the vector to print
    @return the modified output stream */
    inline friend std::ostream& operator <<(std::ostream& output,
        const Vector4& v) {

        output << v.toString();

        return output;
    }

public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //------------------------POSITION COMPONENT ACCESS-------------------------

    //! x position access component
    float x;
    //! y position access component
    float y;
    //! z position access component
    float z;
    //! w position access component
    float w;

    //-------------------------COLOUR COMPONENT ACCESS--------------------------

    //! red colour access component (alias of x)
    float& r;
    //! green colour access component (alias of y)
    float& g;
    //! blue colour access component (alias of z)
    float& b;
    //! alpha colour access component (alias of w)
    float& a;

    //-----------------------MEASUREMENT COMPONENT ACCESS-----------------------

    //! width measurement access component (alias of x)
    float& width;
    //! height measurement access component (alias of x)
    float& height;
    //! depth measurement access component (alias of x)
    float& depth;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a new four dimensional vector with components
    initialised as zero */
    inline Vector4() :
        x(0),
        y(0),
        z(0),
        w(0),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector with the given values
    @param p_x the x value of the vector
    @param p_y the y value of the vector
    @param p_z the z value of the vector
    @param p_w the w value of the vector */
    inline Vector4(float p_x, float p_y, float p_z, float p_w) :
        x(p_x),
        y(p_y),
        z(p_z),
        w(p_w),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by the copying the values from
    the given 4d vector
    @param v4 the 4d vector to copy from */
    inline Vector4(const Vector4& v4) :
        x(v4.x),
        y(v4.y),
        z(v4.z),
        w(v4.w),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by setting the x and y components
    from the given 2d vector and sets the z and w components from the
    given values
    @param v2 the 2d vector to copy from
    @param p_z the z value of the vector
    @param p_w the w value of the vector */
    inline Vector4(const Vector2& v2, float p_z, float p_w) :
        x(v2.x),
        y(v2.y),
        z(p_z),
        w(p_w),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by setting the y and z components
    from the given 2d vector and sets the x and w components from the
    given values
    @param p_x the x value of the vector
    @param v2 the 2d vector to copy from
    @param p_w the w value of the vector */
    inline Vector4(float p_x, const Vector2& v2, float p_w) :
        x(p_x),
        y(v2.x),
        z(v2.y),
        w(p_w),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by setting the z and w components
    from the given 2d vector and sets the x and y components from the
    given values
    @param p_x the x value of the vector
    @param p_y the y value of the vector
    @param v2 the 2d vector to copy from */
    inline Vector4(float p_x, float p_y, const Vector2& v2) :
        x(p_x),
        y(p_y),
        z(v2.x),
        w(v2.y),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by setting the x and y components
    from the first 2d vector and the z and w components from the second
    2d vector
    @param firstV2 the first 2d vector
    @param secondV2 the second 2d vector */
    inline Vector4(const Vector2& firstV2, const Vector2& secondV2) :
        x(firstV2.x),
        y(firstV2.y),
        z(secondV2.x),
        w(secondV2.y),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by setting the x, y, and z
    components from the given 3d vector and sets the w component
    from the given value
    @param v3 the 3d vector to copy from
    @param p_w the w value of the vector */
    inline Vector4(const Vector3& v3, float p_w) :
        x(v3.x),
        y(v3.y),
        z(v3.z),
        w(p_w),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    /** Creates a new four dimensional vector by setting the y, x, and w
    components from the given 3d vector and sets the x component
    from the given value
    @param p_x the x value of the vector
    @param v3 the 3d vector to copy from */
    inline Vector4(float p_x, const Vector3& v3) :
        x(p_x),
        y(v3.x),
        z(v3.y),
        w(v3.z),
        r(x),
        g(y),
        b(z),
        a(w),
        width(x),
        height(y),
        depth(z) {
    }

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    inline ~Vector4() {
    }

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    //--------------------------------ASSIGNMENT--------------------------------

    /** Sets the values of this vector by copying the values from the
    other given vector
    @param other the vector to copy from */
    inline Vector4& operator =(const Vector4& other) {

        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;

        return *this;
    }

    /** Sets the values of the vector to the given scalar
    @param scalar the scalar to set all values to */
    inline Vector4& operator =(float scalar) {

        x = scalar;
        y = scalar;
        z = scalar;
        w = scalar;
        
        return *this;
    }

    //---------------------------------EQUALITY---------------------------------

    /** @return if this vector and the other given vector are equal */
    inline bool operator ==(const Vector4& other) const {

        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    /** @return if this vector and the other given vector are not equal */
    inline bool operator !=(const Vector4& other) const {

        return !((*this) == other);
    }

    //--------------------------------SUBSCRIPT---------------------------------

    /** Gets the component of the vector at the given index
    @param index the component to get
    @return the value of the component */
    inline float& operator [](unsigned index) {

        // check that the index is within bounds
        if (index > 3) {

            util::ex::IndexOutOfBoundsException("index is greater than 3.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            case 1: {

                return y;
            }
            case 2: {

                return z;
            }
            default: {

                return w;
            }
        }
    }

    /** Gets the component of the vector at the given index
    @param index the component to get
    @return the value of the component */
    inline const float& operator [](unsigned index) const {

        // check that the index is within bounds
        if (index > 3) {

            util::ex::IndexOutOfBoundsException("index is greater than 3.");
        }

        switch (index) {

            case 0: {

                return x;
            }
            case 1: {

                return y;
            }
            case 2: {

                return z;
            }
            default: {

                return w;
            }
        }
    }

    //----------------------------------UNARY-----------------------------------

    /** @return a copy of the vector which has been negated */
    inline Vector4 operator -() const {

        return Vector4(-x, -y, -z, -w);
    }

    //---------------------------------ADDITION---------------------------------

    /** Creates a new vector as the result of the addition of the components
    of this vector with the given scalar
    @param scalar the scalar to add
    @return the result of the addition */
    inline Vector4 operator +(float scalar) const {

        return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
    }

    /** Adds the given scalar to the components of this vector
    @param scalar the scalar to add */
    inline void operator +=(float scalar) {

        x += scalar;
        y += scalar;
        z += scalar;
        w += scalar;
    }

    /** Creates a new vector as the result of the addition of this vector
    and the other given vector
    @param other the vector to add to this
    @return the result of the addition */
    inline Vector4 operator +(const Vector4& other) const {

        return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    /** Adds the given vector to this vector
    @param other the vector to add to this */
    inline void operator +=(const Vector4& other) {

        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
    }

    //-------------------------------SUBTRACTION--------------------------------

    /** Creates a new vector as the result of the subtraction of the
    scalar from the components of this vector
    @param scalar the scalar to subtract from the components
    @return the result of the subtraction */
    inline Vector4 operator -(float scalar) const {

        return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
    }

    /** Subtracts the given scalar from the components of this vector
    @param scalar the scalar to subtract from the components */
    inline void operator -=(float scalar) {

        x -= scalar;
        y -= scalar;
        z -= scalar;
        w -= scalar;
    }

    /** Creates a new vector as the result of the subtraction of the
    given vector from this vector
    @param other the vector to subtract from this
    @return the result of the subtraction */
    inline Vector4 operator -(const Vector4& other) const {

        return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    /** Subtracts the given vector from this vector
    @param other the vector to subtract from this */
    inline void operator -=(const Vector4& other) {

        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
    }

    //------------------------------MULTIPLICATION------------------------------

    /** Creates a new vector as the result of the multiplication of the
    components of this vector by the given scalar
    @param scalar the scalar to multiply the components by
    @return the result of the multiplication */
    inline Vector4 operator *(float scalar) const {

        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    /** Multiplies the components of this vector by the given scalar
    @param scalar the scalar to multiply the components by */
    inline void operator *=(float scalar) {

        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
    }

    //---------------------------------DIVISION---------------------------------

    /** Creates a new vector as the result of the division of the
    components of this vector by the given scalar
    @param scalar the scalar to divide the components by
    @return the result of the division */
    inline Vector4 operator /(float scalar) const {

        return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    /** Divides the components of this vector by the given scalar
    @param scalar the scalar to divide the components by */
    inline void operator /=(float scalar) {

        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    //-----------------------STATIC CONSTRUCTOR FUNCTIONS-----------------------

    /** @return the zero three dimensional vector */
    inline static Vector4 zero() {

        return Vector4(0, 0, 0, 0);
    }

    /** @return the x axis vector */
    inline static Vector4 xAxis() {

        return Vector4(1, 0, 0, 0);
    }

    /** @return the y axis vector */
    inline static Vector4 yAxis() {

        return Vector4(0, 1, 0, 0);
    }

    /** @return the z axis vector */
    inline static Vector4 zAxis() {

        return Vector4(0, 0, 1, 0);
    }

    /** @return the w axis vector */
    inline static Vector4 wAxis() {

        return Vector4(0, 0, 0, 1);
    }

    //--------------------------CONSTRUCTOR FUNCTIONS---------------------------

    /** @returns a clone of this vector */
    inline Vector4 clone() const {

        return Vector4(x, y, z, w);
    }

    /** #Hidden */
    inline Vector2 xy() const {

        return Vector2(x, y);
    }

    /** #Hidden */
    inline Vector2 xz() const {

        return Vector2(x, z);
    }

    /** #Hidden */
    inline Vector2 xw() const {

        return Vector2(x, w);
    }

    /** #Hidden */
    inline Vector2 yx() const {

        return Vector2(y, x);
    }

    /** #Hidden */
    inline Vector2 yz() const {

        return Vector2(y, z);
    }

    /** #Hidden */
    inline Vector2 yw() const {

        return Vector2(y, w);
    }

    /** #Hidden */
    inline Vector2 zx() const {

        return Vector2(z, x);
    }

    /** #Hidden */
    inline Vector2 zy() const {

        return Vector2(z, y);
    }

    /** #Hidden */
    inline Vector2 zw() const {

        return Vector2(z, w);
    }

    /** #Hidden */
    inline Vector3 xyz() const {

        return Vector3(x, y, z);
    }

    /** #Hidden */
    inline Vector3 xyw() const {

        return Vector3(x, y, w);
    }

    /** #Hidden */
    inline Vector3 xzy() const {

        return Vector3(x, z, y);
    }

    /** #Hidden */
    inline Vector3 xzw() const {

        return Vector3(x, z, w);
    }

    /** #Hidden */
    inline Vector3 xwy() const {

        return Vector3(x, w, y);
    }

    /** #Hidden */
    inline Vector3 xwz() const {

        return Vector3(x, w, z);
    }

    /** #Hidden */
    inline Vector3 yxz() const {

        return Vector3(y, x, z);
    }

    /** #Hidden */
    inline Vector3 yxw() const {

        return Vector3(y, x, w);
    }

    /** #Hidden */
    inline Vector3 yzx() const {

        return Vector3(y, z, x);
    }

    /** #Hidden */
    inline Vector3 yzw() const {

        return Vector3(y, z, w);
    }

    /** #Hidden */
    inline Vector3 ywx() const {

        return Vector3(y, w, x);
    }

    /** #Hidden */
    inline Vector3 ywz() const {

        return Vector3(y, w, z);
    }

    /** #Hidden */
    inline Vector3 zxy() const {

        return Vector3(z, x, y);
    }

    /** #Hidden */
    inline Vector3 zxw() const {

        return Vector3(z, x, w);
    }

    /** #Hidden */
    inline Vector3 zyx() const {

        return Vector3(z, y, x);
    }

    /** #Hidden */
    inline Vector3 zyw() const {

        return Vector3(z, y, w);
    }

    /** #Hidden */
    inline Vector3 zwx() const {

        return Vector3(z, w, x);
    }

    /** #Hidden */
    inline Vector3 zwy() const {

        return Vector3(z, w, y);
    }

    /** #Hidden */
    inline Vector3 wxy() const {

        return Vector3(w, x, y);
    }

    /** #Hidden */
    inline Vector3 wxz() const {

        return Vector3(w, x, z);
    }

    /** #Hidden */
    inline Vector3 wyx() const {

        return Vector3(w, y, x);
    }

    /** #Hidden */
    inline Vector3 wyz() const {

        return Vector3(w, y, z);
    }

    /** #Hidden */
    inline Vector3 wzx() const {

        return Vector3(w, z, x);
    }

    /** #Hidden */
    inline Vector3 wzy() const {

        return Vector3(w, z, y);
    }

    /** #Hidden */
    inline Vector4 xyzw() const {

        return Vector4(x, y, z, w);
    }

    /** #Hidden */
    inline Vector4 xywz() const {

        return Vector4(x, y, w, z);
    }

    /** #Hidden */
    inline Vector4 xzyw() const {

        return Vector4(x, z, y, w);
    }

    /** #Hidden */
    inline Vector4 xwyz() const {

        return Vector4(x, w, y, z);
    }

    /** #Hidden */
    inline Vector4 yxzw() const {

        return Vector4(y, x, z, w);
    }

    /** #Hidden */
    inline Vector4 yxwz() const {

        return Vector4(y, x, w, z);
    }

    /** #Hidden */
    inline Vector4 yzxw() const {

        return Vector4(y, z, x, w);
    }

    /** #Hidden */
    inline Vector4 yzwx() const {

        return Vector4(y, z, w, x);
    }

    /** #Hidden */
    inline Vector4 ywxz() const {

        return Vector4(y, w, x, z);
    }

    /** #Hidden */
    inline Vector4 ywzx() const {

        return Vector4(y, w, z, x);
    }

    /** #Hidden */
    inline Vector4 zxyw() const {

        return Vector4(z, x, y, w);
    }

    /** #Hidden */
    inline Vector4 zxwy() const {

        return Vector4(z, x, y, w);
    }

    /** #Hidden */
    inline Vector4 zyxw() const {

        return Vector4(z, y, x, w);
    }

    /** #Hidden */
    inline Vector4 zywx() const {

        return Vector4(z, y, w, x);
    }

    /** #Hidden */
    inline Vector4 zwxy() const {

        return Vector4(z, y, w, x);
    }

    /** #Hidden */
    inline Vector4 zwyx() const {

        return Vector4(z, w, y, x);
    }

    //---------------------------FORMATTING FUNCTIONS---------------------------

    /** @return the vector in string format */
    inline std::string toString() const {

        std::stringstream ss;
        ss << "[" << x << ", " << y << ", " << z <<  ", " << w << "]";

        return ss.str();
    }
};

//------------------------------------------------------------------------------
//                             VECTOR MATH FUNCTIONS
//------------------------------------------------------------------------------

/** Computes the magnitude of the given vector
@param v the vector to compute the magnitude
@return the magnitude */
inline float magnitude(const Vector2& v) {

    return sqrt((v.x * v.x) + (v.y * v.y));
}

/** Computes the magnitude of the given vector
@param v the vector to compute the magnitude
@return the magnitude */
inline float magnitude(const Vector3& v) {

    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/** Computes the magnitude of the given vector
@param v the vector to compute the magnitude
@return the magnitude */
inline float magnitude(const Vector4& v) {

    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w + v.w));
}

/** Computes a normalised version of the given vector
@param v the vector to normalise
@return the normalised vector */
inline Vector2 normalise(const Vector2& v) {

    float mag = magnitude(v);

    return Vector2(v.x / mag, v.y / mag);
}

/** Computes a normalised version of the given vector
@param v the vector to normalise
@return the normalised vector */
inline Vector3 normalise(const Vector3& v) {

    float mag = magnitude(v);

    return Vector3(v.x / mag, v.y / mag, v.z / mag);
}

/** Computes a normalised version of the given vector
@param v the vector to normalise
@return the normalised vector */
inline Vector4 normalise(const Vector4& v) {

    float mag = magnitude(v);

    return Vector4(v.x / mag, v.y / mag, v.z / mag, v.w / mag);
}

/** Computes the dot product of the two given vectors
@param a the first vector
@param b the second vector
@return the result of dot product */
inline float dot(const Vector2& a, const Vector2& b) {

    return (a.x * b.x) + (a.y * b.y);
}

/** Computes the dot product of the two given vectors
@param a the first vector
@param b the second vector
@return the result of dot product */
inline float dot(const Vector3& a, const Vector3& b) {

    return (a.x * b.x) + (a.y * b.y) * (a.z * b.z);
}

/** Computes the dot product of the two given vectors
@param a the first vector
@param b the second vector
@return the result of dot product */
inline float dot(const Vector4& a, const Vector4& b) {

    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

/** Computes the cross product of the two given vectors
@param a the first vector
@param b the second vector
@return the result of cross product */
inline Vector3 cross(const Vector3& a, const Vector3& b) {

    // the cross product values
    float cx = (a.y * b.z) - (a.z * b.y);
    float cy = (a.x * b.z) - (a.z * b.x);
    float cz = (a.x * b.y) - (a.y * b.x);

    return Vector3(cx, cy, cz);
}

/** Calculates the distance between the two vectors
@param a the first vector
@param b the second vector
@return the distance between the vectors */
inline float distance(const Vector2& a, const Vector2& b) {

    return sqrt(pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f));
}

/** @Calculates the distance between the two vectors
@param a the first vector
@param b the second vector
@return the distance between the vectors */
inline float distance(const Vector3& a, const Vector3& b) {

    return sqrt(pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f) +
        pow(a.z - b.z, 2.0f));
}

/** @Calculates the distance between the two vectors
@param a the first vector
@param b the second vector
@return the distance between the vectors */
inline float distance(const Vector4& a, const Vector4& b) {

    return sqrt(pow(a.x - b.x, 2.0f) + pow(a.y - b.y, 2.0f) +
        pow(a.z - b.z, 2.0f) + pow(a.w - b.w, 2.0f));
}

/** @return the angle between the two vectors
@param a the first vector
@param b the second vector
@return the angle between the vectors */
inline float angleBetween(const Vector2& a, const Vector2& b) {

    return (-1.0f * atan2(a.y - b.y, a.x - b.x)) * math::RADIANS_TO_DEGREES;
}

} // namespace vec

} // namespace util

#endif
