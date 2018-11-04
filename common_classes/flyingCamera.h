#pragma once

#include <functional>

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class FlyingCamera
{
public:
	FlyingCamera(const glm::vec3& position, const glm::vec3& viewPoint, const glm::vec3& upVector, float moveSpeed = 10.0f);

	/** \brief  Sets movement speed of camera (how fast camera moves forward / backward).
	*   \param moveSpeed Movement speed (distance travelled per second)
	*/
	void setMoveSpeed(float moveSpeed);

	void setMouseSensitivity(float mouseSensitivity);

	/** \brief  Sets keys to control camera with
	*   \param forwardKeyCode     Key to move forward
	*   \param backwardKeyCode    Key to move backward
	*   \param strafeLeftKeyCode  Key to strafe left
	*   \param strafeRightKeyCode Key to strafe right
	*/
	void setControls(int forwardKeyCode, int backwardKeyCode, int strafeLeftKeyCode, int strafeRightKeyCode);

	void setWindowCenterPosition(glm::i32vec2 windowCenterPosition);

	/** \brief  Gets the current view matrix, depending on position and viewpoint of camera.
	*   \return 4x4 view matrix.
	*/
	glm::mat4 getViewMatrix() const;

	/** \brief  Updates camera - reacts on key presses and updates camera's internal state (position, view vector...)
	*   \param keyInputFunc        Function that detects key presses
	*   \param speedCorrectionFunc Function, that corrects floating point value according to the time passed
	*/
	void update(std::function<bool(int)> keyInputFunc,
		std::function<glm::i32vec2()> getCursorPosFunc,
		std::function<void(const glm::i32vec2&)> setCursorPosFunc,
		std::function<float(float)> speedCorrectionFunc);

private:

	/** \brief  Moves camera by specified distance (positive = forward, negative = backward)
	*   \param distance Distance to travel by
	*/
	void moveBy(float distance);

	void strafeBy(float distance);

	/** \brief  Rotates camera view by specified angle.
	*   \param angleInDegrees Angle to rotate by, in degrees
	*/
	void rotateLeftRight(float angleInDegrees);

	void rotateUpDown(float angleInDegrees);

	/** \brief  Gets normalized view vector.
	*   \return Normalized view vector.
	*/
	glm::vec3 getNormalizedViewVector() const;

	glm::vec3 _position; ///< Camera's position (eye position)
	glm::vec3 _viewPoint; ///< Viewpoint - where does camera look to
	glm::vec3 _upVector; ///< Up vector of the camera

	glm::i32vec2 _lastMousePosition;
	glm::i32vec2 _windowCenterPosition;
	float _mouseSensitivity;

	float _moveSpeed; ///< How fast the camera is moving forwards and backwards
	int _forwardKeyCode; ///< Key to move forward
	int _backwardKeyCode; ///< Key to move backward
	int _strafeLeftKeyCode; ///< Key to rotate left
	int _strafeRightKeyCode; ///< Key to rotate right
};