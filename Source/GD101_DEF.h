#ifndef __GD_101_DEF__
#define __GD_101_DEF__

//----------------------------------------
//	GENERAL DATA TYPE
//----------------------------------------
// FLOAT2
typedef struct FLOAT2
{
    float x;
    float y;

#ifdef __cplusplus
    FLOAT2() {};
    FLOAT2(float _x, float _y) : x(_x), y(_y) {};
    FLOAT2(const float *pArray);

    FLOAT2& operator= (const FLOAT2& Float2);
#endif // __cplusplus

} FLOAT2;

// FLOAT3
typedef struct FLOAT3
{
    float x;
    float y;
    float z;

#ifdef __cplusplus
    FLOAT3() {};
    FLOAT3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
    FLOAT3(const float *pArray);

    FLOAT3& operator= (const FLOAT3& Float3);
#endif // __cplusplus

} FLOAT3;

//----------------------------------------
//	END -------- GENERAL DATA TYPE
//----------------------------------------

#endif // __GD_101_DEF__