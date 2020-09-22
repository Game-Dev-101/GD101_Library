#ifndef __GD_101_DEF__
#define __GD_101_DEF__

//----------------------------------------
//	GENERAL DATA TYPE
//----------------------------------------
// FLOAT2
struct FLOAT2
{
    float x;
    float y;

#ifdef __cplusplus
    FLOAT2() {};
    FLOAT2(float _x, float _y) : x(_x), y(_y) {};
    //FLOAT2(const float *pArray);

    //FLOAT2& operator= (const FLOAT2& Float2);
#endif // __cplusplus

};

// FLOAT3
struct FLOAT3
{
    float x;
    float y;
    float z;

#ifdef __cplusplus
    FLOAT3() {};
    FLOAT3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
    //FLOAT3(const float *pArray);

    //FLOAT3& operator= (const FLOAT3& Float3);
#endif // __cplusplus

};

// FLOAT3
struct COLOR4
{
    float r;
    float g;
    float b;
	float a;

#ifdef __cplusplus
    COLOR4() {};
    COLOR4(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {};
    //FLOAT3(const float *pArray);

    //FLOAT3& operator= (const FLOAT3& Float3);
#endif // __cplusplus

};
//----------------------------------------
//	END -------- GENERAL DATA TYPE
//----------------------------------------

#endif // __GD_101_DEF__