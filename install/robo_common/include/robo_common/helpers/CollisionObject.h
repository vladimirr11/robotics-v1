#ifndef ROBO_COMMON_COLLISIONOBJECT_H_
#define ROBO_COMMON_COLLISIONOBJECT_H_

//System headers
#include <cstddef>

//Other libraries headers
#include "utils/drawing/Rectangle.h"

//Own components headers

//Forward declarations

using CollisionObjHandle = size_t;

enum class CollisionDamageImpact {
  YES, NO
};

enum class CollisionWatchStatus {
  ON, OFF
};

inline constexpr CollisionObjHandle INVALID_COLLISION_OBJ_HANDLE = 0xFFFFFFFF;

class CollisionObject {
public:
  virtual ~CollisionObject() noexcept = default;

  virtual void registerCollision(const Rectangle& intersectRect,
                                 CollisionDamageImpact impact) = 0;
  virtual Rectangle getBoundary() const = 0;

protected:
  CollisionObjHandle _collisionObjHandle = INVALID_COLLISION_OBJ_HANDLE;
};

#endif /* ROBO_COMMON_COLLISIONOBJECT_H_ */
