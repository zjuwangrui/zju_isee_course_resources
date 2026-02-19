/* Include files */

#include "modelInterface.h"
#include "m_C4CON94rsjfh6UYnxBvVqE.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 71,    /* lineNo */
  "RandomIntegerGenerator",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\+comm\\+internal\\RandomIntegerGenerator.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 1,   /* lineNo */
  "RandomNumberSource",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\+comm\\+internal\\RandomNumberSource.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 1,   /* lineNo */
  "Source",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\+comm\\+internal\\Source.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 1,   /* lineNo */
  "Helper",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\compiled\\+comm\\+internal\\Helper.p"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 1,   /* lineNo */
  "System",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\System.p"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 1,   /* lineNo */
  "SystemProp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemProp.p"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 1,   /* lineNo */
  "SystemCore",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 1,   /* lineNo */
  "FiniteSource",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+mixin\\+coder\\FiniteSource.p"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 11,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 28,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 98,  /* lineNo */
  "RandomNumberSource",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\+comm\\+internal\\RandomNumberSource.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 132, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 135, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 137, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 139, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 282, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 284, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 286, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 287, /* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 30,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 35,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 116, /* lineNo */
  "RandomIntegerGenerator",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\+comm\\+internal\\RandomIntegerGenerator.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 126, /* lineNo */
  "RandomIntegerGenerator",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\comm\\comm\\+comm\\+internal\\RandomIntegerGenerator.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 74,  /* lineNo */
  "randi",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\randi.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 107, /* lineNo */
  "rand",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 41, /* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 43, /* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 45, /* lineNo */
  "eml_rand",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 23, /* lineNo */
  "eml_rand_mt19937ar_stateful",       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\private\\eml_rand_mt19937ar_stateful.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 51, /* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 1,     /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 141, /* lineNo */
  13,                                  /* colNo */
  "rng",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 125, /* lineNo */
  13,                                  /* colNo */
  "eml_rand_mt19937ar",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+randfun\\eml_rand_mt19937ar.m"/* pName */
};

static emlrtRSInfo fb_emlrtRSI = { 125,/* lineNo */
  "eml_rand_mt19937ar",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+randfun\\eml_rand_mt19937ar.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 141,/* lineNo */
  "rng",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\randfun\\rng.m"/* pathName */
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static void mw__internal__system__init__fcn
  (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance);
static void mw__internal__call__setup(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp);
static comm_internal_RandomIntegerGenerator
  *RandomIntegerGenerator_RandomIntegerGenerator
  (comm_internal_RandomIntegerGenerator *obj);
static void SystemCore_setup(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp, comm_internal_RandomIntegerGenerator
  *obj);
static real_T now(void);
static real_T b_mod(real_T x);
static void SystemCore_checkTunablePropChange(const emlrtStack *sp,
  comm_internal_RandomIntegerGenerator *obj);
static void mw__internal__call__reset(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp);
static real32_T mw__internal__call__step(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp);
static real_T b_rand(InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance,
                     const emlrtStack *sp);
static const mxArray *emlrt_marshallOut(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp, const mxArray *u);
static uint32_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier);
static uint32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier);
static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier, uint32_T y[625]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, uint32_T y[625]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier, uint32_T y[2]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, uint32_T y[2]);
static comm_internal_RandomIntegerGenerator j_emlrt_marshallIn(const emlrtStack *
  sp, const mxArray *nullptr, const char_T *identifier);
static comm_internal_RandomIntegerGenerator k_emlrt_marshallIn(const emlrtStack *
  sp, const mxArray *u, const emlrtMsgIdentifier *parentId);
static int32_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void cgxe_mdl_set_sim_state(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const mxArray *st);
static const mxArray *message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location);
static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static void error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  emlrtMCInfo *location);
static const mxArray *b_message(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location);
static uint32_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static boolean_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, uint32_T ret[625]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, uint32_T ret[2]);
static int32_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static real_T eml_rand_mt19937ar(const emlrtStack *sp, uint32_T d_state[625]);
static void init_simulink_io_address(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  init_simulink_io_address(moduleInstance);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__system__init__fcn(moduleInstance);
  mw__internal__call__setup(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_initialize(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "communication_toolbox", 2);
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__reset(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_outputs(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  *moduleInstance->b_y0 = mw__internal__call__step(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_update(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  cgxertSetGcb(moduleInstance->S, -1, -1);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void mw__internal__system__init__fcn
  (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance)
{
  static uint32_T uv[625] = { 5489U, 1301868182U, 2938499221U, 2950281878U,
    1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U, 219885934U,
    2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U, 3418470598U,
    951210697U, 3693558366U, 2923482051U, 1793174584U, 2982310801U, 1586906132U,
    1951078751U, 1808158765U, 1733897588U, 431328322U, 4202539044U, 530658942U,
    1714810322U, 3025256284U, 3342585396U, 1937033938U, 2640572511U, 1654299090U,
    3692403553U, 4233871309U, 3497650794U, 862629010U, 2943236032U, 2426458545U,
    1603307207U, 1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U,
    761573964U, 3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U,
    3295982469U, 1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
    699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
    1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U, 3570962471U,
    4287636090U, 4087307012U, 3603343627U, 202242161U, 2995682783U, 1620962684U,
    3704723357U, 371613603U, 2814834333U, 2111005706U, 624778151U, 2094172212U,
    4284947003U, 1211977835U, 991917094U, 1570449747U, 2962370480U, 1259410321U,
    170182696U, 146300961U, 2836829791U, 619452428U, 2723670296U, 1881399711U,
    1161269684U, 1675188680U, 4132175277U, 780088327U, 3409462821U, 1036518241U,
    1834958505U, 3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U,
    1924681712U, 3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
    3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U, 2339662006U,
    501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U, 3393774360U,
    1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U, 819755096U,
    2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U, 1029741190U,
    2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U, 2701024045U,
    4117700889U, 759495121U, 3332270341U, 2313004527U, 2277067795U, 4131855432U,
    2722057515U, 1264804546U, 3848622725U, 2211267957U, 4100593547U, 959123777U,
    2130745407U, 3194437393U, 486673947U, 1377371204U, 17472727U, 352317554U,
    3955548058U, 159652094U, 1232063192U, 3835177280U, 49423123U, 3083993636U,
    733092U, 2120519771U, 2573409834U, 1112952433U, 3239502554U, 761045320U,
    1087580692U, 2540165110U, 641058802U, 1792435497U, 2261799288U, 1579184083U,
    627146892U, 2165744623U, 2200142389U, 2167590760U, 2381418376U, 1793358889U,
    3081659520U, 1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
    3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
    3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
    354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
    1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U, 1684529556U,
    1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U, 171579916U,
    3878728600U, 2475806724U, 2030324028U, 3331164912U, 1708711359U, 1970023127U,
    2859691344U, 2588476477U, 2748146879U, 136111222U, 2967685492U, 909517429U,
    2835297809U, 3206906216U, 3186870716U, 341264097U, 2542035121U, 3353277068U,
    548223577U, 3170936588U, 1678403446U, 297435620U, 2337555430U, 466603495U,
    1132321815U, 1208589219U, 696392160U, 894244439U, 2562678859U, 470224582U,
    3306867480U, 201364898U, 2075966438U, 1767227936U, 2929737987U, 3674877796U,
    2654196643U, 3692734598U, 3528895099U, 2796780123U, 3048728353U, 842329300U,
    191554730U, 2922459673U, 3489020079U, 3979110629U, 1022523848U, 2202932467U,
    3583655201U, 3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U,
    396426791U, 3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
    3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
    2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U, 1521001832U,
    3605886097U, 2802786495U, 2728923319U, 3996284304U, 903417639U, 1171249804U,
    1020374987U, 2824535874U, 423621996U, 1988534473U, 2493544470U, 1008604435U,
    1756003503U, 1488867287U, 1386808992U, 732088248U, 1780630732U, 2482101014U,
    976561178U, 1543448953U, 2602866064U, 2021139923U, 1952599828U, 2360242564U,
    2117959962U, 2753061860U, 2388623612U, 4138193781U, 2962920654U, 2284970429U,
    766920861U, 3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
    3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U, 686850534U,
    1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U, 4195430425U,
    607905174U, 3902331779U, 2454067926U, 1708133115U, 1170874362U, 2008609376U,
    3260320415U, 2211196135U, 433538229U, 2728786374U, 2189520818U, 262554063U,
    1182318347U, 3710237267U, 1221022450U, 715966018U, 2417068910U, 2591870721U,
    2870691989U, 3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
    4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U, 1123218514U,
    551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U, 422862282U,
    3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U, 1324564878U,
    1928816105U, 1786535431U, 2878099422U, 3290185549U, 539474248U, 1657512683U,
    552370646U, 1671741683U, 3655312128U, 1552739510U, 2605208763U, 1441755014U,
    181878989U, 3124053868U, 1447103986U, 3183906156U, 1728556020U, 3502241336U,
    3055466967U, 1013272474U, 818402132U, 1715099063U, 2900113506U, 397254517U,
    4194863039U, 1009068739U, 232864647U, 2540223708U, 2608288560U, 2415367765U,
    478404847U, 3455100648U, 3182600021U, 2115988978U, 434269567U, 4117179324U,
    3461774077U, 887256537U, 3545801025U, 286388911U, 3451742129U, 1981164769U,
    786667016U, 3310123729U, 3097811076U, 2224235657U, 2959658883U, 3370969234U,
    2514770915U, 3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
    4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U, 1477814055U,
    4043852216U, 1876372354U, 3133294443U, 3871104810U, 3177020907U, 2074304428U,
    3479393793U, 759562891U, 164128153U, 1839069216U, 2114162633U, 3989947309U,
    3611054956U, 1333547922U, 835429831U, 494987340U, 171987910U, 1252001001U,
    370809172U, 3508925425U, 2535703112U, 1276855041U, 1922855120U, 835673414U,
    3030664304U, 613287117U, 171219893U, 3423096126U, 3376881639U, 2287770315U,
    1658692645U, 1262815245U, 3957234326U, 1168096164U, 2968737525U, 2655813712U,
    2132313144U, 3976047964U, 326516571U, 353088456U, 3679188938U, 3205649712U,
    2654036126U, 1249024881U, 880166166U, 691800469U, 2229503665U, 1673458056U,
    4032208375U, 1851778863U, 2563757330U, 376742205U, 1794655231U, 340247333U,
    1505873033U, 396524441U, 879666767U, 3335579166U, 3260764261U, 3335999539U,
    506221798U, 4214658741U, 975887814U, 2080536343U, 3360539560U, 571586418U,
    138896374U, 4234352651U, 2737620262U, 3928362291U, 1516365296U, 38056726U,
    3599462320U, 3585007266U, 3850961033U, 471667319U, 1536883193U, 2310166751U,
    1861637689U, 2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
    2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
    643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U, 3285177704U,
    1948416081U, 1311525291U, 1183517742U, 1739192232U, 3979815115U, 2567840007U,
    4116821529U, 213304419U, 4125718577U, 1473064925U, 2442436592U, 1893310111U,
    4195361916U, 3747569474U, 828465101U, 2991227658U, 750582866U, 1205170309U,
    1409813056U, 678418130U, 1171531016U, 3821236156U, 354504587U, 4202874632U,
    3882511497U, 1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U,
    3725758099U, 831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U,
    3358210805U, 4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U,
    190157081U, 3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
    2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
    453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U, 3541393095U,
    4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U, 1795580598U,
    2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U, 705213300U,
    363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U, 2199989172U,
    1987356470U, 4026755612U, 2147252133U, 270400031U, 1367820199U, 2369854699U,
    2844269403U, 79981964U, 624U };

  emlrtStack st;
  int32_T i;
  for (i = 0; i < 625; i++) {
    moduleInstance->state[i] = uv[i];
  }

  st.site = NULL;
  moduleInstance->seed = 0U;
  moduleInstance->seed_not_empty = true;
  st.site = NULL;
  moduleInstance->method = 7U;
  moduleInstance->method_not_empty = true;
  st.site = NULL;
  moduleInstance->state_not_empty = true;
  st.site = NULL;
  for (i = 0; i < 2; i++) {
    moduleInstance->b_state[i] = 158852560U * (uint32_T)i + 362436069U;
  }

  moduleInstance->b_state_not_empty = true;
  st.site = NULL;
  moduleInstance->c_state = 1144108930U;
  moduleInstance->c_state_not_empty = true;
}

static void mw__internal__call__setup(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &i_emlrtRSI;
    RandomIntegerGenerator_RandomIntegerGenerator(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &j_emlrtRSI;
  SystemCore_setup(moduleInstance, &st, &moduleInstance->sysobj);
}

static comm_internal_RandomIntegerGenerator
  *RandomIntegerGenerator_RandomIntegerGenerator
  (comm_internal_RandomIntegerGenerator *obj)
{
  comm_internal_RandomIntegerGenerator *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  b_obj = obj;
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  c_st.site = &c_emlrtRSI;
  d_st.site = &d_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  f_st.site = &f_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  b_obj->TunablePropsChanged = false;
  f_st.site = &g_emlrtRSI;
  b_obj->isInitialized = 0;
  c_st.site = &c_emlrtRSI;
  d_st.site = &h_emlrtRSI;
  return b_obj;
}

static void SystemCore_setup(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp, comm_internal_RandomIntegerGenerator
  *obj)
{
  static const int32_T iv[2] = { 1, 51 };

  static const int32_T iv1[2] = { 1, 51 };

  static const int32_T iv2[2] = { 1, 5 };

  static const int32_T iv3[2] = { 1, 22 };

  static const int32_T iv4[2] = { 1, 22 };

  static char_T b_u[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  static char_T f_u[22] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'n', 'g',
    ':', 'b', 'a', 'd', 'S', 'e', 't', 't', 'i', 'n', 'g', 's' };

  static char_T d_u[5] = { 's', 'e', 't', 'u', 'p' };

  time_t b_eTime;
  time_t eTime;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  real_T s;
  real_T x;
  int32_T exitg1;
  int32_T r;
  int32_T t;
  uint32_T b_r;
  char_T u[51];
  char_T e_u[22];
  char_T c_u[5];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (obj->isInitialized != 0) {
    for (r = 0; r < 51; r++) {
      u[r] = b_u[r];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 51, m, &u[0]);
    emlrtAssign(&y, m);
    for (r = 0; r < 51; r++) {
      u[r] = b_u[r];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 51, m, &u[0]);
    emlrtAssign(&b_y, m);
    for (r = 0; r < 5; r++) {
      c_u[r] = d_u[r];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 5, m, &c_u[0]);
    emlrtAssign(&c_y, m);
    st.site = &g_emlrtRSI;
    error(&st, y, getString(&st, message(&st, b_y, c_y, &emlrtMCI), &emlrtMCI),
          &emlrtMCI);
  }

  obj->isInitialized = 1;
  st.site = &g_emlrtRSI;
  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  x = now() * 8.64E+6;
  s = b_mod(muDoubleScalarFloor(x));
  d_st.site = &q_emlrtRSI;
  eTime = time(NULL);
  do {
    exitg1 = 0;
    d_st.site = &r_emlrtRSI;
    b_eTime = time(NULL);
    if ((int32_T)b_eTime <= (int32_T)eTime + 1) {
      d_st.site = &s_emlrtRSI;
      x = now() * 8.64E+6;
      if (s != b_mod(muDoubleScalarFloor(x))) {
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  x = muDoubleScalarRound(s);
  if (x < 4.294967296E+9) {
    if (x >= 0.0) {
      moduleInstance->seed = (uint32_T)x;
    } else {
      moduleInstance->seed = 0U;
    }
  } else if (x >= 4.294967296E+9) {
    moduleInstance->seed = MAX_uint32_T;
  } else {
    moduleInstance->seed = 0U;
  }

  if (moduleInstance->method == 7U) {
    c_st.site = &m_emlrtRSI;
    b_r = moduleInstance->seed;
    moduleInstance->state[0] = moduleInstance->seed;
    for (r = 0; r < 623; r++) {
      b_r = ((b_r ^ b_r >> 30U) * 1812433253U + (uint32_T)r) + 1U;
      moduleInstance->state[r + 1] = b_r;
    }

    moduleInstance->state[624] = 624U;
  } else if (moduleInstance->method == 5U) {
    c_st.site = &n_emlrtRSI;
    moduleInstance->b_state[0] = 362436069U;
    moduleInstance->b_state[1] = moduleInstance->seed;
    if (moduleInstance->b_state[1] == 0U) {
      moduleInstance->b_state[1] = 521288629U;
    }
  } else if (moduleInstance->method == 4U) {
    c_st.site = &o_emlrtRSI;
    r = (int32_T)(moduleInstance->seed >> 16U);
    t = (int32_T)(moduleInstance->seed & 32768U);
    moduleInstance->c_state = (uint32_T)r << 16U;
    moduleInstance->c_state = moduleInstance->seed - moduleInstance->c_state;
    moduleInstance->c_state -= (uint32_T)t;
    moduleInstance->c_state <<= 16U;
    moduleInstance->c_state += (uint32_T)t;
    moduleInstance->c_state += (uint32_T)r;
    if (moduleInstance->c_state < 1U) {
      moduleInstance->c_state = 1144108930U;
    } else if (moduleInstance->c_state > 2147483646U) {
      moduleInstance->c_state = 2147483646U;
    }
  } else {
    for (r = 0; r < 22; r++) {
      e_u[r] = f_u[r];
    }

    d_y = NULL;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&b_st, 22, m, &e_u[0]);
    emlrtAssign(&d_y, m);
    for (r = 0; r < 22; r++) {
      e_u[r] = f_u[r];
    }

    e_y = NULL;
    m = emlrtCreateCharArray(2, &iv4[0]);
    emlrtInitCharArrayR2013a(&b_st, 22, m, &e_u[0]);
    emlrtAssign(&e_y, m);
    c_st.site = &gb_emlrtRSI;
    error(&c_st, d_y, getString(&c_st, b_message(&c_st, e_y, &b_emlrtMCI),
           &b_emlrtMCI), &b_emlrtMCI);
  }

  st.site = &g_emlrtRSI;
  SystemCore_checkTunablePropChange(&st, obj);
  obj->TunablePropsChanged = false;
}

static real_T now(void)
{
  time_t rawtime;
  struct tm expl_temp;
  real_T y;
  int32_T r;
  int16_T cDaysMonthWise[12];
  boolean_T guard1;
  cDaysMonthWise[0] = 0;
  cDaysMonthWise[1] = 31;
  cDaysMonthWise[2] = 59;
  cDaysMonthWise[3] = 90;
  cDaysMonthWise[4] = 120;
  cDaysMonthWise[5] = 151;
  cDaysMonthWise[6] = 181;
  cDaysMonthWise[7] = 212;
  cDaysMonthWise[8] = 243;
  cDaysMonthWise[9] = 273;
  cDaysMonthWise[10] = 304;
  cDaysMonthWise[11] = 334;
  time(&rawtime);
  expl_temp = *localtime(&rawtime);
  y = ((((365.0 * (real_T)(expl_temp.tm_year + 1900) + muDoubleScalarCeil
          ((real_T)(expl_temp.tm_year + 1900) / 4.0)) - muDoubleScalarCeil
         ((real_T)(expl_temp.tm_year + 1900) / 100.0)) + muDoubleScalarCeil
        ((real_T)(expl_temp.tm_year + 1900) / 400.0)) + (real_T)
       cDaysMonthWise[expl_temp.tm_mon]) + (real_T)expl_temp.tm_mday;
  if (expl_temp.tm_mon + 1 > 2) {
    if (expl_temp.tm_year + 1900 == 0) {
      r = 0;
    } else {
      r = (int32_T)muDoubleScalarRem((real_T)(expl_temp.tm_year + 1900), 4.0);
      if (r == 0) {
        r = 0;
      } else if (r < 0) {
        r += 4;
      }
    }

    guard1 = false;
    if (r == 0) {
      if (expl_temp.tm_year + 1900 == 0) {
        r = 0;
      } else {
        r = (int32_T)muDoubleScalarRem((real_T)(expl_temp.tm_year + 1900), 100.0);
        if (r == 0) {
          r = 0;
        } else if (r < 0) {
          r += 100;
        }
      }

      if (r != 0) {
        y++;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (expl_temp.tm_year + 1900 == 0) {
        r = 0;
      } else {
        r = (int32_T)muDoubleScalarRem((real_T)(expl_temp.tm_year + 1900), 400.0);
        if (r == 0) {
          r = 0;
        } else if (r < 0) {
          r += 400;
        }
      }

      if (r == 0) {
        y++;
      }
    }
  }

  y += (((real_T)expl_temp.tm_hour * 3600.0 + (real_T)expl_temp.tm_min * 60.0) +
        (real_T)expl_temp.tm_sec) / 86400.0;
  return y;
}

static real_T b_mod(real_T x)
{
  real_T r;
  if (muDoubleScalarIsNaN(x) || muDoubleScalarIsInf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = muDoubleScalarRem(x, 2.147483647E+9);
    if (r == 0.0) {
      r = 0.0;
    } else if (r < 0.0) {
      r += 2.147483647E+9;
    }
  }

  return r;
}

static void SystemCore_checkTunablePropChange(const emlrtStack *sp,
  comm_internal_RandomIntegerGenerator *obj)
{
  static const int32_T iv[2] = { 1, 44 };

  static const int32_T iv1[2] = { 1, 44 };

  static char_T b_u[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[44];
  st.prev = sp;
  st.tls = sp->tls;
  if (obj->TunablePropsChanged) {
    for (i = 0; i < 44; i++) {
      u[i] = b_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 44, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 44; i++) {
      u[i] = b_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 44, m, &u[0]);
    emlrtAssign(&b_y, m);
    st.site = &g_emlrtRSI;
    error(&st, y, getString(&st, b_message(&st, b_y, &emlrtMCI), &emlrtMCI),
          &emlrtMCI);
  }
}

static void mw__internal__call__reset(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp)
{
  static const int32_T iv[2] = { 1, 45 };

  static const int32_T iv1[2] = { 1, 44 };

  static const int32_T iv2[2] = { 1, 45 };

  static const int32_T iv3[2] = { 1, 44 };

  static const int32_T iv4[2] = { 1, 5 };

  static char_T c_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  static char_T d_u[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  static char_T f_u[5] = { 'r', 'e', 's', 'e', 't' };

  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  char_T u[45];
  char_T b_u[44];
  char_T e_u[5];
  boolean_T tunablePropChangedBeforeResetImpl;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &i_emlrtRSI;
    RandomIntegerGenerator_RandomIntegerGenerator(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &t_emlrtRSI;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&y, m);
    for (i = 0; i < 45; i++) {
      u[i] = c_u[i];
    }

    c_y = NULL;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 45, m, &u[0]);
    emlrtAssign(&c_y, m);
    for (i = 0; i < 5; i++) {
      e_u[i] = f_u[i];
    }

    e_y = NULL;
    m = emlrtCreateCharArray(2, &iv4[0]);
    emlrtInitCharArrayR2013a(&st, 5, m, &e_u[0]);
    emlrtAssign(&e_y, m);
    b_st.site = &g_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, c_y, e_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }

  tunablePropChangedBeforeResetImpl = moduleInstance->sysobj.TunablePropsChanged;
  if ((int32_T)tunablePropChangedBeforeResetImpl != (int32_T)
      moduleInstance->sysobj.TunablePropsChanged) {
    for (i = 0; i < 44; i++) {
      b_u[i] = d_u[i];
    }

    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&st, 44, m, &b_u[0]);
    emlrtAssign(&b_y, m);
    for (i = 0; i < 44; i++) {
      b_u[i] = d_u[i];
    }

    d_y = NULL;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&st, 44, m, &b_u[0]);
    emlrtAssign(&d_y, m);
    b_st.site = &g_emlrtRSI;
    error(&b_st, b_y, getString(&b_st, b_message(&b_st, d_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }
}

static real32_T mw__internal__call__step(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T r;
  real32_T c_y0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &i_emlrtRSI;
    RandomIntegerGenerator_RandomIntegerGenerator(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &u_emlrtRSI;
  if (moduleInstance->sysobj.isInitialized != 1) {
    b_st.site = &g_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    SystemCore_setup(moduleInstance, &c_st, &moduleInstance->sysobj);
  }

  b_st.site = &g_emlrtRSI;
  if (moduleInstance->sysobj.TunablePropsChanged) {
    moduleInstance->sysobj.TunablePropsChanged = false;
  }

  b_st.site = &g_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  d_st.site = &w_emlrtRSI;
  e_st.site = &x_emlrtRSI;
  r = b_rand(moduleInstance, &e_st);
  c_y0 = (real32_T)muDoubleScalarFloor(r * 2.0);
  b_st.site = &g_emlrtRSI;
  SystemCore_checkTunablePropChange(&b_st, &moduleInstance->sysobj);
  return c_y0;
}

static real_T b_rand(InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance,
                     const emlrtStack *sp)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T r;
  int32_T hi;
  uint32_T test1;
  uint32_T test2;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (moduleInstance->method == 4U) {
    b_st.site = &ab_emlrtRSI;
    hi = (int32_T)(moduleInstance->c_state / 127773U);
    test1 = 16807U * (moduleInstance->c_state - (uint32_T)hi * 127773U);
    test2 = 2836U * (uint32_T)hi;
    if (test1 < test2) {
      moduleInstance->c_state = ~(test2 - test1) & 2147483647U;
    } else {
      moduleInstance->c_state = test1 - test2;
    }

    r = (real_T)moduleInstance->c_state * 4.6566128752457969E-10;
  } else if (moduleInstance->method == 5U) {
    b_st.site = &bb_emlrtRSI;
    test1 = 69069U * moduleInstance->b_state[0] + 1234567U;
    test2 = moduleInstance->b_state[1] ^ moduleInstance->b_state[1] << 13;
    test2 ^= test2 >> 17;
    test2 ^= test2 << 5;
    moduleInstance->b_state[0] = test1;
    moduleInstance->b_state[1] = test2;
    r = (real_T)(test1 + test2) * 2.328306436538696E-10;
  } else {
    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    r = eml_rand_mt19937ar(&c_st, moduleInstance->state);
  }

  return r;
}

static const mxArray *emlrt_marshallOut(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  static const int32_T iv[1] = { 625 };

  static const int32_T iv1[1] = { 2 };

  static const char_T *sv[2] = { "isInitialized", "TunablePropsChanged" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *y;
  int32_T i;
  int32_T u;
  uint32_T *pData;
  boolean_T b_u;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(12, 1));
  b_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m) = moduleInstance->method;
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  c_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->method_not_empty);
  emlrtAssign(&c_y, m);
  emlrtSetCell(y, 1, c_y);
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m) = moduleInstance->seed;
  emlrtAssign(&d_y, m);
  emlrtSetCell(y, 2, d_y);
  e_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->seed_not_empty);
  emlrtAssign(&e_y, m);
  emlrtSetCell(y, 3, e_y);
  f_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m) = moduleInstance->c_state;
  emlrtAssign(&f_y, m);
  emlrtSetCell(y, 4, f_y);
  g_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&iv[0], mxUINT32_CLASS, mxREAL);
  pData = (uint32_T *)emlrtMxGetData(m);
  u = 0;
  for (i = 0; i < 625; i++) {
    pData[u] = moduleInstance->state[i];
    u++;
  }

  emlrtAssign(&g_y, m);
  emlrtSetCell(y, 5, g_y);
  h_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&iv1[0], mxUINT32_CLASS, mxREAL);
  pData = (uint32_T *)emlrtMxGetData(m);
  u = 0;
  for (i = 0; i < 2; i++) {
    pData[u] = moduleInstance->b_state[i];
    u++;
  }

  emlrtAssign(&h_y, m);
  emlrtSetCell(y, 6, h_y);
  i_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->c_state_not_empty);
  emlrtAssign(&i_y, m);
  emlrtSetCell(y, 7, i_y);
  j_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->state_not_empty);
  emlrtAssign(&j_y, m);
  emlrtSetCell(y, 8, j_y);
  k_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->b_state_not_empty);
  emlrtAssign(&k_y, m);
  emlrtSetCell(y, 9, k_y);
  l_y = NULL;
  emlrtAssign(&l_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  u = moduleInstance->sysobj.isInitialized;
  m_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&m_y, m);
  emlrtSetFieldR2017b(l_y, 0, "isInitialized", m_y, 0);
  b_u = moduleInstance->sysobj.TunablePropsChanged;
  n_y = NULL;
  m = emlrtCreateLogicalScalar(b_u);
  emlrtAssign(&n_y, m);
  emlrtSetFieldR2017b(l_y, 0, "TunablePropsChanged", n_y, 1);
  emlrtSetCell(y, 10, l_y);
  o_y = NULL;
  m = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&o_y, m);
  emlrtSetCell(y, 11, o_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const emlrtStack *sp, const mxArray *u)
{
  emlrtMsgIdentifier thisId;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  thisId.fIdentifier = "method";
  moduleInstance->method = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)
    sp, &thisId, u, 0)), "method");
  thisId.fIdentifier = "method_not_empty";
  moduleInstance->method_not_empty = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 1)), "method_not_empty");
  thisId.fIdentifier = "seed";
  moduleInstance->seed = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)
    sp, &thisId, u, 2)), "seed");
  thisId.fIdentifier = "seed_not_empty";
  moduleInstance->seed_not_empty = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 3)), "seed_not_empty");
  thisId.fIdentifier = "state";
  moduleInstance->c_state = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void
    *)sp, &thisId, u, 4)), "state");
  thisId.fIdentifier = "state";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)sp, &thisId, u, 5)),
                     "state", moduleInstance->state);
  thisId.fIdentifier = "state";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)sp, &thisId, u, 6)),
                     "state", moduleInstance->b_state);
  thisId.fIdentifier = "state_not_empty";
  moduleInstance->c_state_not_empty = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 7)), "state_not_empty");
  thisId.fIdentifier = "state_not_empty";
  moduleInstance->state_not_empty = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 8)), "state_not_empty");
  thisId.fIdentifier = "state_not_empty";
  moduleInstance->b_state_not_empty = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 9)), "state_not_empty");
  thisId.fIdentifier = "sysobj";
  moduleInstance->sysobj = j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((void *)
    sp, &thisId, u, 10)), "sysobj");
  thisId.fIdentifier = "sysobj_not_empty";
  moduleInstance->sysobj_not_empty = d_emlrt_marshallIn(sp, emlrtAlias
    (emlrtGetCell((void *)sp, &thisId, u, 11)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
}

static uint32_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  uint32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static uint32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  uint32_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier, uint32_T y[625])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  g_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, uint32_T y[625])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
  const char_T *identifier, uint32_T y[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  i_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, uint32_T y[2])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static comm_internal_RandomIntegerGenerator j_emlrt_marshallIn(const emlrtStack *
  sp, const mxArray *nullptr, const char_T *identifier)
{
  comm_internal_RandomIntegerGenerator y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = k_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static comm_internal_RandomIntegerGenerator k_emlrt_marshallIn(const emlrtStack *
  sp, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = { "isInitialized", "TunablePropsChanged"
  };

  comm_internal_RandomIntegerGenerator y;
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 2, (const char_T **)
    &fieldNames[0], 0U, (const void *)&dims);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y.TunablePropsChanged = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b
    ((emlrtConstCTX)sp, u, 0, 1, "TunablePropsChanged")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance, const mxArray *st)
{
  emlrtStack b_st = { NULL,            /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  b_st.tls = moduleInstance->emlrtRootTLSGlobal;
  emlrt_marshallIn(moduleInstance, &b_st, emlrtAlias(st));
  emlrtDestroyArray(&st);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *m1, const
  mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
    "message", true, location);
}

static const mxArray *getString(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "getString",
    true, location);
}

static void error(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                  emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 2, &pArrays[0], "error",
                        true, location);
}

static const mxArray *b_message(const emlrtStack *sp, const mxArray *m1,
  emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 1, &pArray, "message",
    true, location);
}

static uint32_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint32", false, 0U, (
    const void *)&dims);
  ret = *(uint32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 0U, (
    const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, uint32_T ret[625])
{
  static const int32_T dims[1] = { 625 };

  int32_T i;
  uint32_T (*r)[625];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint32", false, 1U, (
    const void *)&dims[0]);
  r = (uint32_T (*)[625])emlrtMxGetData(src);
  for (i = 0; i < 625; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, uint32_T ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i;
  uint32_T (*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint32", false, 1U, (
    const void *)&dims[0]);
  r = (uint32_T (*)[2])emlrtMxGetData(src);
  for (i = 0; i < 2; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static int32_T q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  int32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "int32", false, 0U, (
    const void *)&dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T eml_rand_mt19937ar(const emlrtStack *sp, uint32_T d_state[625])
{
  static const int32_T iv[2] = { 1, 37 };

  static const int32_T iv1[2] = { 1, 37 };

  static char_T c_u[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  int32_T exitg1;
  int32_T k;
  int32_T kk;
  uint32_T u[2];
  uint32_T mti;
  uint32_T y;
  char_T b_u[37];
  boolean_T exitg2;
  boolean_T isvalid;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on: */
  /*  */
  /*  A C-program for MT19937, with initialization improved 2002/1/26. */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto. */
  /*  */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /*  All rights reserved. */
  /*  */
  /*  Redistribution and use in source and binary forms, with or without */
  /*  modification, are permitted provided that the following conditions */
  /*  are met: */
  /*  */
  /*    1. Redistributions of source code must retain the above copyright */
  /*       notice, this list of conditions and the following disclaimer. */
  /*  */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer */
  /*       in the documentation and/or other materials provided with the */
  /*       distribution. */
  /*  */
  /*    3. The names of its contributors may not be used to endorse or */
  /*       promote products derived from this software without specific */
  /*       prior written permission. */
  /*  */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  /*  */
  /* =============================   END   ================================= */
  do {
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = d_state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (d_state[kk] & 2147483648U) | (d_state[kk + 1] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          d_state[kk] = d_state[kk + 397] ^ y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (d_state[kk + 227] & 2147483648U) | (d_state[kk + 228] &
            2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          d_state[kk + 227] = d_state[kk] ^ y;
        }

        y = (d_state[623] & 2147483648U) | (d_state[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        d_state[623] = d_state[396] ^ y;
        mti = 1U;
      }

      y = d_state[(int32_T)mti - 1];
      d_state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      y ^= y >> 18U;
      u[k] = y;
    }

    mti = u[0] >> 5U;
    y = u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      if ((d_state[624] >= 1U) && (d_state[624] < 625U)) {
        isvalid = true;
      } else {
        isvalid = false;
      }

      if (isvalid) {
        isvalid = false;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k + 1 < 625)) {
          if (d_state[k] == 0U) {
            k++;
          } else {
            isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!isvalid) {
        for (k = 0; k < 37; k++) {
          b_u[k] = c_u[k];
        }

        b_y = NULL;
        m = emlrtCreateCharArray(2, &iv[0]);
        emlrtInitCharArrayR2013a(&st, 37, m, &b_u[0]);
        emlrtAssign(&b_y, m);
        for (k = 0; k < 37; k++) {
          b_u[k] = c_u[k];
        }

        c_y = NULL;
        m = emlrtCreateCharArray(2, &iv1[0]);
        emlrtInitCharArrayR2013a(&st, 37, m, &b_u[0]);
        emlrtAssign(&c_y, m);
        b_st.site = &fb_emlrtRSI;
        error(&b_st, b_y, getString(&b_st, b_message(&b_st, c_y, &c_emlrtMCI),
               &c_emlrtMCI), &c_emlrtMCI);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return 1.1102230246251565E-16 * ((real_T)mti * 6.7108864E+7 + (real_T)y);
}

static void init_simulink_io_address(InstanceStruct_C4CON94rsjfh6UYnxBvVqE
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->b_y0 = (real32_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    0);
}

/* CGXE Glue Code */
static void mdlOutputs_C4CON94rsjfh6UYnxBvVqE(SimStruct *S, int_T tid)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_C4CON94rsjfh6UYnxBvVqE(SimStruct *S, int_T tid)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static mxArray* getSimState_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_C4CON94rsjfh6UYnxBvVqE(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
  InstanceStruct_C4CON94rsjfh6UYnxBvVqE *moduleInstance =
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE *)calloc(1, sizeof
    (InstanceStruct_C4CON94rsjfh6UYnxBvVqE));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_C4CON94rsjfh6UYnxBvVqE);
  ssSetmdlInitializeConditions(S, mdlInitialize_C4CON94rsjfh6UYnxBvVqE);
  ssSetmdlUpdate(S, mdlUpdate_C4CON94rsjfh6UYnxBvVqE);
  ssSetmdlDerivatives(S, mdlDerivatives_C4CON94rsjfh6UYnxBvVqE);
  ssSetmdlTerminate(S, mdlTerminate_C4CON94rsjfh6UYnxBvVqE);
  ssSetmdlEnable(S, mdlEnable_C4CON94rsjfh6UYnxBvVqE);
  ssSetmdlDisable(S, mdlDisable_C4CON94rsjfh6UYnxBvVqE);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_C4CON94rsjfh6UYnxBvVqE(SimStruct *S)
{
}

void method_dispatcher_C4CON94rsjfh6UYnxBvVqE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_C4CON94rsjfh6UYnxBvVqE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_C4CON94rsjfh6UYnxBvVqE(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_C4CON94rsjfh6UYnxBvVqE(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_C4CON94rsjfh6UYnxBvVqE(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: C4CON94rsjfh6UYnxBvVqE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_C4CON94rsjfh6UYnxBvVqE_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxArray * elem_10;
  mxArray * elem_11;
  mxArray * elem_12;
  mxArray * elem_13;
  mxArray * elem_14;
  mxArray * elem_15;
  mxArray * elem_16;
  double * pointer;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(1,4);
  elem_4 = mxCreateString("addIncludeFiles");
  mxSetCell(elem_3,0,elem_4);
  elem_5 = mxCreateCellMatrix(1,1);
  elem_6 = mxCreateString("<time.h>");
  mxSetCell(elem_5,0,elem_6);
  mxSetCell(elem_3,1,elem_5);
  elem_7 = mxCreateCellMatrix(1,1);
  elem_8 = mxCreateString("");
  mxSetCell(elem_7,0,elem_8);
  mxSetCell(elem_3,2,elem_7);
  elem_9 = mxCreateCellMatrix(1,1);
  elem_10 = mxCreateString("");
  mxSetCell(elem_9,0,elem_10);
  mxSetCell(elem_3,3,elem_9);
  mxSetCell(elem_1,1,elem_3);
  elem_11 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_11);
  elem_12 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_12);
  elem_13 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_13);
  elem_14 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_14);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_15 = mxCreateDoubleMatrix(0,0, mxREAL);
  pointer = mxGetPr(elem_15);
  mxSetCell(mxBIArgs,1,elem_15);
  elem_16 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_16);
  return mxBIArgs;
}

mxArray *cgxe_C4CON94rsjfh6UYnxBvVqE_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("time");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
