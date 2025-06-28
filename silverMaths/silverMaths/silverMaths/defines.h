/*
   Silver Sword (2025)
   Created by Christian Orosa
*/

#ifndef _SS_DEFINES_H_                    // Include guard start
#define _SS_DEFINES_H_

// File Related Defines.
enum SS_FILE_TYPE { BB_TEXT_FILE = 1, BB_BINARY_FILE };

enum SS_ENDIAN_TYPE {
    SS_ENDIAN_UNKNOWN = 0, BB_ENDIAN_LITTLE,
    SS_ENDIAN_BIG, BB_ENDIAN_MIDDLE
};

// Math defines, constants, etc.
typedef float scalar;                     // Alias for float
#define PI_CONST  3.14159265358979323846  // Pi constant

#define SS_NULL_FLOAT   1.0E20f           // Represents a "null" float value

#define DEG_TO_RAD(angle)  (angle * PI_CONST / 180)    // Converts degrees to radians
#define RAD_TO_DEG(radian) (radian * 180 / PI_CONST)   // Converts radians to degrees

enum SS_COORDINATE_TYPE { BB_LEFT_HANDED = 1, BB_RIGHT_HANDED };

enum SS_PLANE_STATUS {
    BB_PLANE_FRONT = 1, BB_PLANE_BACK, BB_PLANE_ON_PLANE,
    BB_PLANE_CLIPPED, BB_PLANE_CULLED, BB_PLANE_VISIBLE
};

#define SS_MIN(a, b) (a < b ? a : b)                  // Returns the minimum of two values

#define SIGN(a) (a < 0.0f) ? -1.0f : 1.0f             // Returns the sign of a float

#define SS_MAX_CLIPPING_VERTS 64                     // Maximum number of clipping vertices

// Resource manager defines.
#define SS_NULL_HANDLE  -1                           // Represents an invalid handle

// General defines, etc.
enum BRESULT {
    SS_FAIL = 0, SS_SUCCESS, SS_VERTEX_SHADER_FAIL,
    SS_PIXEL_SHADER_FAIL, SS_SHADER_FAIL,
    SS_PARAMETERS_FAIL, SS_DEVICE_FAIL
};

typedef char SSTATE;                // Boolean-like type
#define SS_TRUE   1                 // Boolean true
#define SS_FALSE  0                 // Boolean false

// Networking defines, etc.
enum SS_NETWORK_MESSAGE_TYPE {
    SS_MESSAGE_SERVER_DISCONNECT = 0,
    SS_MESSAGE_CLIENT_DISCONNECT,
    SS_MESSAGE_FORCE_DISCONNECT,
    SS_MESSAGE_CONNECT_ACCEPTED,
    SS_MESSAGE_SEND_ERROR,
    SS_MESSAGE_RESPOND_REQUIRE,
    SS_MESSAGE_RESPOND_OK
};

enum SS_NETWORK_TYPE { SS_NETWORK_NULL = 0, SS_NETWORK_SERVER, SS_NETWORK_CLIENT };

enum SNETWORKRESULT {
    SS_NO_DATA = 0, SS_DATA_FAIL, SS_PARTIAL_DATA,
    SS_DATA_SUCCESS
};

typedef char SPACKETVALUE;                      // Packet content value type

#define SS_MAX_PACKET_SIZE 256                  // Max size of a network packet

#define SS_NETWORK_CALLBACK(a) void(*a)(int u, int t, char *d, int s)  // Callback prototype for network events

#define SS_NETWORK_SYSTEM_USAGE 0               // Placeholder or usage flag

// Defines, enums, etc dealing with RENDERING.
enum SS_RENDER_STATE {
    SS_DEPTH_TESTING = 1, SS_SMOOTH_SHADING,
    SS_TEXTURE_2D, SS_TEXTURE_CUBE, SS_ALPHA_TESTING,
    SS_BACK_CCW_CULLING, SS_BACK_CW_CULLING,
    SS_FRONT_CCW_CULLING, SS_FRONT_CW_CULLING,
    SS_TOTAL_RENDER_STATES
};

enum SS_ALPHA_STATE { SS_ALPHA_LESS = 1, SS_ALPHA_GREATER };

enum SS_FILTER_TYPE {
    SS_NO_FILTER = 0, SS_MIN_POINT_FILTER, SS_MAG_POINT_FILTER, SS_MIP_POINT_FILTER,
    SS_MIN_LINEAR_FILTER, SS_MAG_LINEAR_FILTER, SS_MIP_LINEAR_FILTER,
    SS_USE_ANSIO_FILTER, SS_S_REPEAT_FILTER, SS_T_REPEAT_FILTER,
    SS_R_REPEAT_FILTER, SS_S_CLAMP_FILTER, SS_T_CLAMP_FILTER,
    SS_R_CLAMP_FILTER, SS_S_EDGE_CLAMP_FILTER,
    SS_T_EDGE_CLAMP_FILTER, SS_R_EDGE_CLAMP_FILTER
};

enum SS_TEXTURE_TYPE { SS_TEX2D_TYPE = 1, SS_CUBE_TYPE };

enum SS_TEXTURE_FORMAT { SS_TEX_UNSIGNED_BYTE = 1, SS_TEX_FLOAT };

#define SS_MAX_TEXTURES 16                        // Max number of textures

enum SS_MATRIX_TYPE {
    SS_PROJECTION_MATRIX = 1, SS_MODELVIEW_MATRIX,
    SS_TEXTURE_MATRIX, SS_MVP_MATRIX
};

enum SS_MATRIX_FORMAT {
    SS_IDENTITY_MATRIX = 1, SS_TRANSPOSE_MATRIX,
    SS_INVERSE_MATRIX, SS_INVERSE_TRANSPOSE_MATRIX
};

enum SS_PROJECTION_TYPE {
    SS_PROJECTION_NULL = 0,
    SS_PERSPECTIVE_TYPE, BB_ORTHO_TYPE
};

enum SS_ELEMENT_TYPE {
    SS_ELEMENT_TYPE_NULL = 0, SS_ELEMENT_TYPE_IGNORE_2F,
    SS_ELEMENT_TYPE_IGNORE_3F, SS_ELEMENT_TYPE_VERTEX_3F,
    SS_ELEMENT_TYPE_NORMAL_3F, SS_ELEMENT_TYPE_COLOR_3F,
    SS_ELEMENT_TYPE_TEX1_2F, SS_ELEMENT_TYPE_TEX2_2F,
    SS_ELEMENT_TYPE_TEX3_2F, SS_ELEMENT_TYPE_TEX4_2F,
    SS_ELEMENT_TYPE_TEX5_2F, SS_ELEMENT_TYPE_TEX6_2F,
    SS_ELEMENT_TYPE_TEX7_2F, SS_ELEMENT_TYPE_TEX8_2F,
    SS_ELEMENT_TYPE_TEX1_3F, SS_ELEMENT_TYPE_TEX2_3F,
    SS_ELEMENT_TYPE_TEX3_3F, SS_ELEMENT_TYPE_TEX4_3F,
    SS_ELEMENT_TYPE_TEX5_3F, SS_ELEMENT_TYPE_TEX6_3F,
    SS_ELEMENT_TYPE_TEX7_3F, SS_ELEMENT_TYPE_TEX8_3F
};

enum SS_PRIMITIVE_TYPE {
    SS_PRIMITIVE_NULL = 0, SS_PRIMITIVE_POINT_LIST,
    SS_PRIMITIVE_TRI_LIST, SS_PRIMITIVE_TRI_STRIP,
    SS_PRIMITIVE_LINE_LIST, SS_PRIMITIVE_LINE_STRIP
};

enum SS_SHADER_TYPE { SS_VERTEX_SHADER = 1, SS_PIXEL_SHADER };

#define SS_MAX_LOD         3                      // Maximum level of detail supported

#define SS_FILTER_LIST     std::vector<SS_FILTER_TYPE>   // Filter list type alias
#define SS_FILTER_LIST_PTR SS_FILTER_LIST*              // Pointer to filter list

enum SS_OCTREE_NODE_ID
{
    TOP_FRONT_LEFT = 0, TOP_FRONT_RIGHT,
    TOP_BACK_LEFT, TOP_BACK_RIGHT,
    BOTTOM_FRONT_LEFT, BOTTOM_FRONT_RIGHT,
    BOTTOM_BACK_LEFT, BOTTOM_BACK_RIGHT
};

// Defines, enums, etc dealing with INPUT.
#define SS_KEYBOARD_KEY_NUM   256                  // Total number of keyboard keys supported

enum SS_INPUT_BUTTON {
    SS_BUTTON_LEFT_SHOULDER = 1, SS_BUTTON_RIGHT_SHOULDER,
    SS_BUTTON_LEFT_TRIGGER, SS_BUTTON_RIGHT_TRIGGER, SS_BUTTON_LEFT_THUMB,
    SS_BUTTON_RIGHT_THUMB, SS_BUTTON_START, SS_BUTTON_BACK, SS_BUTTON_ARROW_UP,
    SS_BUTTON_ARROW_DOWN, SS_BUTTON_ARROW_LEFT, SS_BUTTON_ARROW_RIGHT,
    SS_BUTTON_A, SS_BUTTON_B, SS_BUTTON_X, SS_BUTTON_Y, SS_BUTTON_MOUSE_LEFT,
    SS_BUTTON_MOUSE_RIGHT, SS_BUTTON_0, SS_BUTTON_1, SS_BUTTON_2, SS_BUTTON_3,
    SS_BUTTON_4, SS_BUTTON_5, SS_BUTTON_6, SS_BUTTON_7, SS_BUTTON_8, SS_BUTTON_9,
    /*SS_BUTTON_A, SS_BUTTON_B,*/ SS_BUTTON_C, SS_BUTTON_D, SS_BUTTON_E, SS_BUTTON_F,
    SS_BUTTON_G, SS_BUTTON_H, SS_BUTTON_I, SS_BUTTON_J, SS_BUTTON_K, SS_BUTTON_L,
    SS_BUTTON_M, SS_BUTTON_N, SS_BUTTON_O, SS_BUTTON_P, SS_BUTTON_Q, SS_BUTTON_R,
    SS_BUTTON_S, SS_BUTTON_T, SS_BUTTON_U, SS_BUTTON_V, SS_BUTTON_W, /*SS_BUTTON_X,
    SS_BUTTON_Y,*/ SS_BUTTON_Z, SS_BUTTON_ESCAPE, SS_BUTTON_SPACE,
    SS_BUTTON_ENTER, SS_TOTAL_BUTTONS
};

#define SS_X360_DEADZONE (0.24 * FLOAT(0x7FFF))    // Xbox 360 controller deadzone threshold
#define SS_X360_DEADZONE_CHECK(stickX, stickY, val) if((stickX < val && \
   stickX > -val) && (stickY < val && stickY > -val)) \
   { stickX = 0; stickY = 0; }                      // Checks if stick is in deadzone

#endif // _SS_DEFINES_H_
