void sconvGemmNHWC(char trans,
                    unsigned b, unsigned h, unsigned w, unsigned c,
                    unsigned kn, unsigned kh, unsigned kw,
                    unsigned vpadding, unsigned hpadding,
                    unsigned vstride, unsigned hstride,
                    unsigned vdilation, unsigned hdilation,
                    const float *in,
                    const float *x,
                    float *out, const float *bias_vector,
                    float *ac_pack, float *bc_pack);

void sconvGemmNHWC_back(unsigned b, unsigned h, unsigned w, unsigned c,
                        unsigned kn, unsigned kh, unsigned kw,
                        unsigned vstride, unsigned hstride,
                        unsigned vpadding, unsigned hpadding,
                        unsigned vdilation, unsigned hdilation,
                        const float *weights,
                        const float *dy, float *dx,
                        float *ac_pack, float *bc_pack);

void sconvGemmNCHW(char trans,
                    unsigned b, unsigned c, unsigned h, unsigned w,
                    unsigned kn, unsigned kh, unsigned kw,
                    unsigned vpadding, unsigned hpadding,
                    unsigned vstride, unsigned hstride,
                    unsigned vdilation, unsigned hdilation,
                    const float *in,
                    const float *x,
                    float *out, const float *bias_vector,
                    const float *bn_running_mean, const float *bn_inv_std,
                    const float *bn_gamma, const float *bn_beta, bool relu,
                    float *ac_pack, float *bc_pack);

void sconvGemmNCHW_back(unsigned b, unsigned c, unsigned h, unsigned w,
                        unsigned kn, unsigned kh, unsigned kw,
                        unsigned vstride, unsigned hstride,
                        unsigned vpadding, unsigned hpadding,
                        unsigned vdilation, unsigned hdilation,
                        const float *weights,
                        const float *dy, float *dx,
                        float *ac_pack, float *bc_pack);

typedef struct {
    int batch, height, width, channel, kn, kheight, kwidth, vstride, hstride, vpadding, hpadding, vdilation, hdilation, oheight, owidth;
} convol_dim;

typedef void (*pack_func)(char orderM, char transM, int mc, int nc, const float *M, int ldM, float *Mc, int RR, const convol_dim *d, int start_row, int start_col);

typedef void (*post_func)(int mr, int nr, const float *Cc, int ldCc, float beta, float *C, int ldC, const convol_dim *dim, const float *bias_vector,                     const float *bn_running_mean, const float *bn_inv_std, const float *bn_gamma, const float *bn_beta, bool relu, int start_row, int start_col, bool last);

static inline double get_time()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}
