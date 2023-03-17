static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";
static const char col_krtpurple[] = "#0024ff";
static const char col_krtlightblue[] = "#3384d0";
static const char col_krttraygrey[] = "#646158";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_krttraygrey, col_gray2},
    [SchemeSel] = {col_gray4, col_gray2, col_krtpurple},
};
