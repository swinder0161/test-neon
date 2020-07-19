#include <stdio.h>
#include <vector>
#include <arm_neon.h>

float32_t Sum_float(float32_t *data, const int count)
{
    float32x4_t res = vdupq_n_f32(0.0f);
    for(int i = 0; i < (count & (~15)); i += 16)
    {
        float32x4x4_t v0 = vld1q_f32_x4(data + i);
        v0.val[0] = vaddq_f32(v0.val[0], v0.val[2]);
        v0.val[1] = vaddq_f32(v0.val[1], v0.val[3]);
        res = vaddq_f32(res, vaddq_f32(v0.val[0], v0.val[1]));
    }
    float32x2_t res1 = vadd_f32(vget_low_f32(res), vget_high_f32(res));

    float32_t v0[2];
    vst1_f32(v0, res1);
    v0[0] += v0[1];
    for(int i = count & (~15); i < count; ++i){
        v0[0] += data[i];
    }

    return v0[0];
}
