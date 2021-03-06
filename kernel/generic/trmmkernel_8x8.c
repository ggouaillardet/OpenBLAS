#include "common.h"

int CNAME(BLASLONG bm,BLASLONG bn,BLASLONG bk,FLOAT alpha,FLOAT* ba,FLOAT* bb,FLOAT* C,BLASLONG ldc ,BLASLONG offset)
{

    BLASLONG i,j,k;
    FLOAT *C0,*C1,*C2,*C3,*C4,*C5,*C6,*C7,*ptrba,*ptrbb;

    FLOAT res0_0;
    FLOAT res0_1;
    FLOAT res0_2;
    FLOAT res0_3;
    FLOAT res0_4;
    FLOAT res0_5;
    FLOAT res0_6;
    FLOAT res0_7;

    FLOAT res1_0;
    FLOAT res1_1;
    FLOAT res1_2;
    FLOAT res1_3;
    FLOAT res1_4;
    FLOAT res1_5;
    FLOAT res1_6;
    FLOAT res1_7;

    FLOAT res2_0;
    FLOAT res2_1;
    FLOAT res2_2;
    FLOAT res2_3;
    FLOAT res2_4;
    FLOAT res2_5;
    FLOAT res2_6;
    FLOAT res2_7;

    FLOAT res3_0;
    FLOAT res3_1;
    FLOAT res3_2;
    FLOAT res3_3;
    FLOAT res3_4;
    FLOAT res3_5;
    FLOAT res3_6;
    FLOAT res3_7;

    FLOAT res4_0;
    FLOAT res4_1;
    FLOAT res4_2;
    FLOAT res4_3;
    FLOAT res4_4;
    FLOAT res4_5;
    FLOAT res4_6;
    FLOAT res4_7;

    FLOAT res5_0;
    FLOAT res5_1;
    FLOAT res5_2;
    FLOAT res5_3;
    FLOAT res5_4;
    FLOAT res5_5;
    FLOAT res5_6;
    FLOAT res5_7;

    FLOAT res6_0;
    FLOAT res6_1;
    FLOAT res6_2;
    FLOAT res6_3;
    FLOAT res6_4;
    FLOAT res6_5;
    FLOAT res6_6;
    FLOAT res6_7;

    FLOAT res7_0;
    FLOAT res7_1;
    FLOAT res7_2;
    FLOAT res7_3;
    FLOAT res7_4;
    FLOAT res7_5;
    FLOAT res7_6;
    FLOAT res7_7;

    FLOAT a0;
    FLOAT a1;

    FLOAT b0;
    FLOAT b1;
    FLOAT b2;
    FLOAT b3;
    
    FLOAT b4;
    FLOAT b5;
    FLOAT b6;
    FLOAT b7;

    BLASLONG off, temp;

#if !defined(LEFT)
    off = -offset;
#else
    off = 0;
#endif
    for (j=0; j<bn/8; j+=1)
    {
        C0 = C;
        C1 = C0+ldc;
        C2 = C1+ldc;
        C3 = C2+ldc;
	
        C4 = C3+ldc;
        C5 = C4+ldc;
        C6 = C5+ldc;
        C7 = C6+ldc;

#if defined(TRMMKERNEL) && defined(LEFT)
        off = offset;
#endif


        ptrba = ba;

        for (i=0; i<bm/8; i+=1)
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*8;
            ptrbb = bb + off*8;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;
            res0_4 = 0;
            res0_5 = 0;
            res0_6 = 0;
            res0_7 = 0;

            res1_0 = 0;
            res1_1 = 0;
            res1_2 = 0;
            res1_3 = 0;
            res1_4 = 0;
            res1_5 = 0;
            res1_6 = 0;
            res1_7 = 0;

            res2_0 = 0;
            res2_1 = 0;
            res2_2 = 0;
            res2_3 = 0;
            res2_4 = 0;
            res2_5 = 0;
            res2_6 = 0;
            res2_7 = 0;

            res3_0 = 0;
            res3_1 = 0;
            res3_2 = 0;
            res3_3 = 0;
            res3_4 = 0;
            res3_5 = 0;
            res3_6 = 0;
            res3_7 = 0;

            res4_0 = 0;
            res4_1 = 0;
            res4_2 = 0;
            res4_3 = 0;
            res4_4 = 0;
            res4_5 = 0;
            res4_6 = 0;
            res4_7 = 0;

            res5_0 = 0;
            res5_1 = 0;
            res5_2 = 0;
            res5_3 = 0;
            res5_4 = 0;
            res5_5 = 0;
            res5_6 = 0;
            res5_7 = 0;

            res6_0 = 0;
            res6_1 = 0;
            res6_2 = 0;
            res6_3 = 0;
            res6_4 = 0;
            res6_5 = 0;
            res6_6 = 0;
            res6_7 = 0;

            res7_0 = 0;
            res7_1 = 0;
            res7_2 = 0;
            res7_3 = 0;
            res7_4 = 0;
            res7_5 = 0;
            res7_6 = 0;
            res7_7 = 0;

#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+8;	// number of values in A
#else
            temp = off+8;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];
                b4 = ptrbb[4];
                b5 = ptrbb[5];
                b6 = ptrbb[6];
                b7 = ptrbb[7];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;
                res4_0 += a0*b4;
                res5_0 += a0*b5;
                res6_0 += a0*b6;
                res7_0 += a0*b7;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;
                res2_1 += a1*b2;
                res3_1 += a1*b3;
                res4_1 += a1*b4;
                res5_1 += a1*b5;
                res6_1 += a1*b6;
                res7_1 += a1*b7;

                a0 = ptrba[2];
                res0_2 += a0*b0;
                res1_2 += a0*b1;
                res2_2 += a0*b2;
                res3_2 += a0*b3;
                res4_2 += a0*b4;
                res5_2 += a0*b5;
                res6_2 += a0*b6;
                res7_2 += a0*b7;

                a1 = ptrba[3];
                res0_3 += a1*b0;
                res1_3 += a1*b1;
                res2_3 += a1*b2;
                res3_3 += a1*b3;
                res4_3 += a1*b4;
                res5_3 += a1*b5;
                res6_3 += a1*b6;
                res7_3 += a1*b7;

                a0 = ptrba[4];
                res0_4 += a0*b0;
                res1_4 += a0*b1;
                res2_4 += a0*b2;
                res3_4 += a0*b3;
                res4_4 += a0*b4;
                res5_4 += a0*b5;
                res6_4 += a0*b6;
                res7_4 += a0*b7;

                a1 = ptrba[5];
                res0_5 += a1*b0;
                res1_5 += a1*b1;
                res2_5 += a1*b2;
                res3_5 += a1*b3;
                res4_5 += a1*b4;
                res5_5 += a1*b5;
                res6_5 += a1*b6;
                res7_5 += a1*b7;

                a0 = ptrba[6];
                res0_6 += a0*b0;
                res1_6 += a0*b1;
                res2_6 += a0*b2;
                res3_6 += a0*b3;
                res4_6 += a0*b4;
                res5_6 += a0*b5;
                res6_6 += a0*b6;
                res7_6 += a0*b7;

                a1 = ptrba[7];
                res0_7 += a1*b0;
                res1_7 += a1*b1;
                res2_7 += a1*b2;
                res3_7 += a1*b3;
                res4_7 += a1*b4;
                res5_7 += a1*b5;
                res6_7 += a1*b6;
                res7_7 += a1*b7;

                ptrba = ptrba+8;
                ptrbb = ptrbb+8;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;
            res0_4 *= alpha;
            res0_5 *= alpha;
            res0_6 *= alpha;
            res0_7 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;
            res1_2 *= alpha;
            res1_3 *= alpha;
            res1_4 *= alpha;
            res1_5 *= alpha;
            res1_6 *= alpha;
            res1_7 *= alpha;

            res2_0 *= alpha;
            res2_1 *= alpha;
            res2_2 *= alpha;
            res2_3 *= alpha;
            res2_4 *= alpha;
            res2_5 *= alpha;
            res2_6 *= alpha;
            res2_7 *= alpha;

            res3_0 *= alpha;
            res3_1 *= alpha;
            res3_2 *= alpha;
            res3_3 *= alpha;
            res3_4 *= alpha;
            res3_5 *= alpha;
            res3_6 *= alpha;
            res3_7 *= alpha;
	    
            res4_0 *= alpha;
            res4_1 *= alpha;
            res4_2 *= alpha;
            res4_3 *= alpha;
            res4_4 *= alpha;
            res4_5 *= alpha;
            res4_6 *= alpha;
            res4_7 *= alpha;

            res5_0 *= alpha;
            res5_1 *= alpha;
            res5_2 *= alpha;
            res5_3 *= alpha;
            res5_4 *= alpha;
            res5_5 *= alpha;
            res5_6 *= alpha;
            res5_7 *= alpha;

            res6_0 *= alpha;
            res6_1 *= alpha;
            res6_2 *= alpha;
            res6_3 *= alpha;
            res6_4 *= alpha;
            res6_5 *= alpha;
            res6_6 *= alpha;
            res6_7 *= alpha;

            res7_0 *= alpha;
            res7_1 *= alpha;
            res7_2 *= alpha;
            res7_3 *= alpha;
            res7_4 *= alpha;
            res7_5 *= alpha;
            res7_6 *= alpha;
            res7_7 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;
            C0[4] = res0_4;
            C0[5] = res0_5;
            C0[6] = res0_6;
            C0[7] = res0_7;

            C1[0] = res1_0;
            C1[1] = res1_1;
            C1[2] = res1_2;
            C1[3] = res1_3;
            C1[4] = res1_4;
            C1[5] = res1_5;
            C1[6] = res1_6;
            C1[7] = res1_7;

            C2[0] = res2_0;
            C2[1] = res2_1;
            C2[2] = res2_2;
            C2[3] = res2_3;
            C2[4] = res2_4;
            C2[5] = res2_5;
            C2[6] = res2_6;
            C2[7] = res2_7;

            C3[0] = res3_0;
            C3[1] = res3_1;
            C3[2] = res3_2;
            C3[3] = res3_3;
            C3[4] = res3_4;
            C3[5] = res3_5;
            C3[6] = res3_6;
            C3[7] = res3_7;

            C4[0] = res4_0;
            C4[1] = res4_1;
            C4[2] = res4_2;
            C4[3] = res4_3;
            C4[4] = res4_4;
            C4[5] = res4_5;
            C4[6] = res4_6;
            C4[7] = res4_7;

            C5[0] = res5_0;
            C5[1] = res5_1;
            C5[2] = res5_2;
            C5[3] = res5_3;
            C5[4] = res5_4;
            C5[5] = res5_5;
            C5[6] = res5_6;
            C5[7] = res5_7;

            C6[0] = res6_0;
            C6[1] = res6_1;
            C6[2] = res6_2;
            C6[3] = res6_3;
            C6[4] = res6_4;
            C6[5] = res6_5;
            C6[6] = res6_6;
            C6[7] = res6_7;

            C7[0] = res7_0;
            C7[1] = res7_1;
            C7[2] = res7_2;
            C7[3] = res7_3;
            C7[4] = res7_4;
            C7[5] = res7_5;
            C7[6] = res7_6;
            C7[7] = res7_7;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 8; // number of values in A
#else
            temp -= 8; // number of values in B
#endif
            ptrba += temp*8;
            ptrbb += temp*8;
#endif

#ifdef LEFT
            off += 8; // number of values in A
#endif

            C0 = C0+8;
            C1 = C1+8;
            C2 = C2+8;
            C3 = C3+8;
            C4 = C4+8;
            C5 = C5+8;
            C6 = C6+8;
            C7 = C7+8;
        }

        if ( bm & 4 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*4;
            ptrbb = bb + off*8;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;

            res1_0 = 0;
            res1_1 = 0;
            res1_2 = 0;
            res1_3 = 0;

            res2_0 = 0;
            res2_1 = 0;
            res2_2 = 0;
            res2_3 = 0;

            res3_0 = 0;
            res3_1 = 0;
            res3_2 = 0;
            res3_3 = 0;

            res4_0 = 0;
            res4_1 = 0;
            res4_2 = 0;
            res4_3 = 0;

            res5_0 = 0;
            res5_1 = 0;
            res5_2 = 0;
            res5_3 = 0;

            res6_0 = 0;
            res6_1 = 0;
            res6_2 = 0;
            res6_3 = 0;

            res7_0 = 0;
            res7_1 = 0;
            res7_2 = 0;
            res7_3 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+4;	// number of values in A
#else
            temp = off+8;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];
                b4 = ptrbb[4];
                b5 = ptrbb[5];
                b6 = ptrbb[6];
                b7 = ptrbb[7];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;
                res4_0 += a0*b4;
                res5_0 += a0*b5;
                res6_0 += a0*b6;
                res7_0 += a0*b7;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;
                res2_1 += a1*b2;
                res3_1 += a1*b3;
                res4_1 += a1*b4;
                res5_1 += a1*b5;
                res6_1 += a1*b6;
                res7_1 += a1*b7;

                a0 = ptrba[2];
                res0_2 += a0*b0;
                res1_2 += a0*b1;
                res2_2 += a0*b2;
                res3_2 += a0*b3;
                res4_2 += a0*b4;
                res5_2 += a0*b5;
                res6_2 += a0*b6;
                res7_2 += a0*b7;

                a1 = ptrba[3];
                res0_3 += a1*b0;
                res1_3 += a1*b1;
                res2_3 += a1*b2;
                res3_3 += a1*b3;
                res4_3 += a1*b4;
                res5_3 += a1*b5;
                res6_3 += a1*b6;
                res7_3 += a1*b7;

                ptrba = ptrba+4;
                ptrbb = ptrbb+8;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;
            res1_2 *= alpha;
            res1_3 *= alpha;

            res2_0 *= alpha;
            res2_1 *= alpha;
            res2_2 *= alpha;
            res2_3 *= alpha;

            res3_0 *= alpha;
            res3_1 *= alpha;
            res3_2 *= alpha;
            res3_3 *= alpha;

            res4_0 *= alpha;
            res4_1 *= alpha;
            res4_2 *= alpha;
            res4_3 *= alpha;

            res5_0 *= alpha;
            res5_1 *= alpha;
            res5_2 *= alpha;
            res5_3 *= alpha;

            res6_0 *= alpha;
            res6_1 *= alpha;
            res6_2 *= alpha;
            res6_3 *= alpha;

            res7_0 *= alpha;
            res7_1 *= alpha;
            res7_2 *= alpha;
            res7_3 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;

            C1[0] = res1_0;
            C1[1] = res1_1;
            C1[2] = res1_2;
            C1[3] = res1_3;


            C2[0] = res2_0;
            C2[1] = res2_1;
            C2[2] = res2_2;
            C2[3] = res2_3;

            C3[0] = res3_0;
            C3[1] = res3_1;
            C3[2] = res3_2;
            C3[3] = res3_3;

            C4[0] = res4_0;
            C4[1] = res4_1;
            C4[2] = res4_2;
            C4[3] = res4_3;

            C5[0] = res5_0;
            C5[1] = res5_1;
            C5[2] = res5_2;
            C5[3] = res5_3;

            C6[0] = res6_0;
            C6[1] = res6_1;
            C6[2] = res6_2;
            C6[3] = res6_3;

            C7[0] = res7_0;
            C7[1] = res7_1;
            C7[2] = res7_2;
            C7[3] = res7_3;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 4; // number of values in A
#else
            temp -= 8; // number of values in B
#endif
            ptrba += temp*4;
            ptrbb += temp*8;
#endif

#ifdef LEFT
            off += 4; // number of values in A
#endif

            C0 = C0+4;
            C1 = C1+4;
            C2 = C2+4;
            C3 = C3+4;
            C4 = C4+4;
            C5 = C5+4;
            C6 = C6+4;
            C7 = C7+4;

        }

        if ( bm & 2 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*2;
            ptrbb = bb + off*8;
#endif

            res0_0 = 0;
            res0_1 = 0;

            res1_0 = 0;
            res1_1 = 0;

            res2_0 = 0;
            res2_1 = 0;

            res3_0 = 0;
            res3_1 = 0;

            res4_0 = 0;
            res4_1 = 0;

            res5_0 = 0;
            res5_1 = 0;

            res6_0 = 0;
            res6_1 = 0;

            res7_0 = 0;
            res7_1 = 0;

#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+2;	// number of values in A
#else
            temp = off+8;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];
                b4 = ptrbb[4];
                b5 = ptrbb[5];
                b6 = ptrbb[6];
                b7 = ptrbb[7];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;
		res4_0 += a0*b4;
                res5_0 += a0*b5;
                res6_0 += a0*b6;
                res7_0 += a0*b7;
		
                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;
                res2_1 += a1*b2;
                res3_1 += a1*b3;
                res4_1 += a1*b4;
                res5_1 += a1*b5;
                res6_1 += a1*b6;
                res7_1 += a1*b7;

                ptrba = ptrba+2;
                ptrbb = ptrbb+8;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;

            res2_0 *= alpha;
            res2_1 *= alpha;

            res3_0 *= alpha;
            res3_1 *= alpha;
	    
            res4_0 *= alpha;
            res4_1 *= alpha;

            res5_0 *= alpha;
            res5_1 *= alpha;

            res6_0 *= alpha;
            res6_1 *= alpha;

            res7_0 *= alpha;
            res7_1 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;

            C1[0] = res1_0;
            C1[1] = res1_1;

            C2[0] = res2_0;
            C2[1] = res2_1;

            C3[0] = res3_0;
            C3[1] = res3_1;

            C4[0] = res4_0;
            C4[1] = res4_1;

            C5[0] = res5_0;
            C5[1] = res5_1;

            C6[0] = res6_0;
            C6[1] = res6_1;

            C7[0] = res7_0;
            C7[1] = res7_1;

#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 2; // number of values in A
#else
            temp -= 8; // number of values in B
#endif
            ptrba += temp*2;
            ptrbb += temp*8;
#endif

#ifdef LEFT
            off += 2; // number of values in A
#endif

            C0 = C0+2;
            C1 = C1+2;
            C2 = C2+2;
            C3 = C3+2;
            C4 = C4+2;
            C5 = C5+2;
            C6 = C6+2;
            C7 = C7+2;

        }

        if ( bm & 1 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*1;
            ptrbb = bb + off*8;
#endif

            res0_0 = 0;
            res1_0 = 0;
            res2_0 = 0;
            res3_0 = 0;
            res4_0 = 0;
            res5_0 = 0;
            res6_0 = 0;
            res7_0 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+1;	// number of values in A
#else
            temp = off+8;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];
                b4 = ptrbb[4];
                b5 = ptrbb[5];
                b6 = ptrbb[6];
                b7 = ptrbb[7];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;
                res4_0 += a0*b4;
                res5_0 += a0*b5;
                res6_0 += a0*b6;
                res7_0 += a0*b7;

                ptrba = ptrba+1;
                ptrbb = ptrbb+8;
            }

            res0_0 *= alpha;
            res1_0 *= alpha;
            res2_0 *= alpha;
            res3_0 *= alpha;
	    res4_0 *= alpha;
            res5_0 *= alpha;
            res6_0 *= alpha;
            res7_0 *= alpha;

            C0[0] = res0_0;
            C1[0] = res1_0;
            C2[0] = res2_0;
            C3[0] = res3_0;
            C4[0] = res4_0;
            C5[0] = res5_0;
            C6[0] = res6_0;
            C7[0] = res7_0;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 1; // number of values in A
#else
            temp -= 8; // number of values in B
#endif
            ptrba += temp*1;
            ptrbb += temp*8;
#endif

#ifdef LEFT
            off += 1; // number of values in A
#endif

            C0 = C0+1;
            C1 = C1+1;
            C2 = C2+1;
            C3 = C3+1;
            C4 = C4+1;
            C5 = C5+1;
            C6 = C6+1;
            C7 = C7+1;

        }


#if defined(TRMMKERNEL) && !defined(LEFT)
        off += 8;
#endif

        k = (bk<<3);
        bb = bb+k;
        i = (ldc<<3);
        C = C+i;
    }

    if (bn&4)
    {
        C0 = C;
        C1 = C0+ldc;
        C2 = C1+ldc;
        C3 = C2+ldc;

#if defined(TRMMKERNEL) && defined(LEFT)
        off = offset;
#endif


        ptrba = ba;

        for (i=0; i<bm/8; i+=1)
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*8;
            ptrbb = bb + off*4;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;
            res0_4 = 0;
            res0_5 = 0;
            res0_6 = 0;
            res0_7 = 0;

            res1_0 = 0;
            res1_1 = 0;
            res1_2 = 0;
            res1_3 = 0;
            res1_4 = 0;
            res1_5 = 0;
            res1_6 = 0;
            res1_7 = 0;

            res2_0 = 0;
            res2_1 = 0;
            res2_2 = 0;
            res2_3 = 0;
            res2_4 = 0;
            res2_5 = 0;
            res2_6 = 0;
            res2_7 = 0;

            res3_0 = 0;
            res3_1 = 0;
            res3_2 = 0;
            res3_3 = 0;
            res3_4 = 0;
            res3_5 = 0;
            res3_6 = 0;
            res3_7 = 0;



#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+8;	// number of values in A
#else
            temp = off+4;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;
                res2_1 += a1*b2;
                res3_1 += a1*b3;

                a0 = ptrba[2];
                res0_2 += a0*b0;
                res1_2 += a0*b1;
                res2_2 += a0*b2;
                res3_2 += a0*b3;

                a1 = ptrba[3];
                res0_3 += a1*b0;
                res1_3 += a1*b1;
                res2_3 += a1*b2;
                res3_3 += a1*b3;

                a0 = ptrba[4];
                res0_4 += a0*b0;
                res1_4 += a0*b1;
                res2_4 += a0*b2;
                res3_4 += a0*b3;

                a1 = ptrba[5];
                res0_5 += a1*b0;
                res1_5 += a1*b1;
                res2_5 += a1*b2;
                res3_5 += a1*b3;

                a0 = ptrba[6];
                res0_6 += a0*b0;
                res1_6 += a0*b1;
                res2_6 += a0*b2;
                res3_6 += a0*b3;

                a1 = ptrba[7];
                res0_7 += a1*b0;
                res1_7 += a1*b1;
                res2_7 += a1*b2;
                res3_7 += a1*b3;

                ptrba = ptrba+8;
                ptrbb = ptrbb+4;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;
            res0_4 *= alpha;
            res0_5 *= alpha;
            res0_6 *= alpha;
            res0_7 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;
            res1_2 *= alpha;
            res1_3 *= alpha;
            res1_4 *= alpha;
            res1_5 *= alpha;
            res1_6 *= alpha;
            res1_7 *= alpha;

            res2_0 *= alpha;
            res2_1 *= alpha;
            res2_2 *= alpha;
            res2_3 *= alpha;
            res2_4 *= alpha;
            res2_5 *= alpha;
            res2_6 *= alpha;
            res2_7 *= alpha;

            res3_0 *= alpha;
            res3_1 *= alpha;
            res3_2 *= alpha;
            res3_3 *= alpha;
            res3_4 *= alpha;
            res3_5 *= alpha;
            res3_6 *= alpha;
            res3_7 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;
            C0[4] = res0_4;
            C0[5] = res0_5;
            C0[6] = res0_6;
            C0[7] = res0_7;

            C1[0] = res1_0;
            C1[1] = res1_1;
            C1[2] = res1_2;
            C1[3] = res1_3;
            C1[4] = res1_4;
            C1[5] = res1_5;
            C1[6] = res1_6;
            C1[7] = res1_7;

            C2[0] = res2_0;
            C2[1] = res2_1;
            C2[2] = res2_2;
            C2[3] = res2_3;
            C2[4] = res2_4;
            C2[5] = res2_5;
            C2[6] = res2_6;
            C2[7] = res2_7;

            C3[0] = res3_0;
            C3[1] = res3_1;
            C3[2] = res3_2;
            C3[3] = res3_3;
            C3[4] = res3_4;
            C3[5] = res3_5;
            C3[6] = res3_6;
            C3[7] = res3_7;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 8; // number of values in A
#else
            temp -= 4; // number of values in B
#endif
            ptrba += temp*8;
            ptrbb += temp*4;
#endif

#ifdef LEFT
            off += 8; // number of values in A
#endif

            C0 = C0+8;
            C1 = C1+8;
            C2 = C2+8;
            C3 = C3+8;
        }

        if ( bm & 4 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*4;
            ptrbb = bb + off*4;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;

            res1_0 = 0;
            res1_1 = 0;
            res1_2 = 0;
            res1_3 = 0;

            res2_0 = 0;
            res2_1 = 0;
            res2_2 = 0;
            res2_3 = 0;

            res3_0 = 0;
            res3_1 = 0;
            res3_2 = 0;
            res3_3 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+4;	// number of values in A
#else
            temp = off+4;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;
                res2_1 += a1*b2;
                res3_1 += a1*b3;

                a0 = ptrba[2];
                res0_2 += a0*b0;
                res1_2 += a0*b1;
                res2_2 += a0*b2;
                res3_2 += a0*b3;

                a1 = ptrba[3];
                res0_3 += a1*b0;
                res1_3 += a1*b1;
                res2_3 += a1*b2;
                res3_3 += a1*b3;

                ptrba = ptrba+4;
                ptrbb = ptrbb+4;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;
            res1_2 *= alpha;
            res1_3 *= alpha;

            res2_0 *= alpha;
            res2_1 *= alpha;
            res2_2 *= alpha;
            res2_3 *= alpha;

            res3_0 *= alpha;
            res3_1 *= alpha;
            res3_2 *= alpha;
            res3_3 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;

            C1[0] = res1_0;
            C1[1] = res1_1;
            C1[2] = res1_2;
            C1[3] = res1_3;


            C2[0] = res2_0;
            C2[1] = res2_1;
            C2[2] = res2_2;
            C2[3] = res2_3;

            C3[0] = res3_0;
            C3[1] = res3_1;
            C3[2] = res3_2;
            C3[3] = res3_3;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 4; // number of values in A
#else
            temp -= 4; // number of values in B
#endif
            ptrba += temp*4;
            ptrbb += temp*4;
#endif

#ifdef LEFT
            off += 4; // number of values in A
#endif

            C0 = C0+4;
            C1 = C1+4;
            C2 = C2+4;
            C3 = C3+4;

        }

        if ( bm & 2 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*2;
            ptrbb = bb + off*4;
#endif

            res0_0 = 0;
            res0_1 = 0;

            res1_0 = 0;
            res1_1 = 0;

            res2_0 = 0;
            res2_1 = 0;

            res3_0 = 0;
            res3_1 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+2;	// number of values in A
#else
            temp = off+4;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;
                res2_1 += a1*b2;
                res3_1 += a1*b3;

                ptrba = ptrba+2;
                ptrbb = ptrbb+4;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;

            res2_0 *= alpha;
            res2_1 *= alpha;

            res3_0 *= alpha;
            res3_1 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;

            C1[0] = res1_0;
            C1[1] = res1_1;

            C2[0] = res2_0;
            C2[1] = res2_1;

            C3[0] = res3_0;
            C3[1] = res3_1;

#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 2; // number of values in A
#else
            temp -= 4; // number of values in B
#endif
            ptrba += temp*2;
            ptrbb += temp*4;
#endif

#ifdef LEFT
            off += 2; // number of values in A
#endif

            C0 = C0+2;
            C1 = C1+2;
            C2 = C2+2;
            C3 = C3+2;

        }

        if ( bm & 1 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*1;
            ptrbb = bb + off*4;
#endif

            res0_0 = 0;
            res1_0 = 0;
            res2_0 = 0;
            res3_0 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+1;	// number of values in A
#else
            temp = off+4;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];
                b2 = ptrbb[2];
                b3 = ptrbb[3];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;
                res2_0 += a0*b2;
                res3_0 += a0*b3;

                ptrba = ptrba+1;
                ptrbb = ptrbb+4;
            }

            res0_0 *= alpha;
            res1_0 *= alpha;
            res2_0 *= alpha;
            res3_0 *= alpha;

            C0[0] = res0_0;
            C1[0] = res1_0;
            C2[0] = res2_0;
            C3[0] = res3_0;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 1; // number of values in A
#else
            temp -= 4; // number of values in B
#endif
            ptrba += temp*1;
            ptrbb += temp*4;
#endif

#ifdef LEFT
            off += 1; // number of values in A
#endif

            C0 = C0+1;
            C1 = C1+1;
            C2 = C2+1;
            C3 = C3+1;

        }


#if defined(TRMMKERNEL) && !defined(LEFT)
        off += 4;
#endif

        k = (bk<<2);
        bb = bb+k;
        i = (ldc<<2);
        C = C+i;
    }


    for (j=0; j<(bn&2); j+=2)
    {
        C0 = C;
        C1 = C0+ldc;

#if defined(TRMMKERNEL) && defined(LEFT)
        off = offset;
#endif


        ptrba = ba;

        for (i=0; i<bm/8; i+=1)
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*8;
            ptrbb = bb + off*2;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;
            res0_4 = 0;
            res0_5 = 0;
            res0_6 = 0;
            res0_7 = 0;

            res1_0 = 0;
            res1_1 = 0;
            res1_2 = 0;
            res1_3 = 0;
            res1_4 = 0;
            res1_5 = 0;
            res1_6 = 0;
            res1_7 = 0;



#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+8;	// number of values in A
#else
            temp = off+2;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;

                a0 = ptrba[2];
                res0_2 += a0*b0;
                res1_2 += a0*b1;

                a1 = ptrba[3];
                res0_3 += a1*b0;
                res1_3 += a1*b1;

                a0 = ptrba[4];
                res0_4 += a0*b0;
                res1_4 += a0*b1;

                a1 = ptrba[5];
                res0_5 += a1*b0;
                res1_5 += a1*b1;

                a0 = ptrba[6];
                res0_6 += a0*b0;
                res1_6 += a0*b1;

                a1 = ptrba[7];
                res0_7 += a1*b0;
                res1_7 += a1*b1;

                ptrba = ptrba+8;
                ptrbb = ptrbb+2;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;
            res0_4 *= alpha;
            res0_5 *= alpha;
            res0_6 *= alpha;
            res0_7 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;
            res1_2 *= alpha;
            res1_3 *= alpha;
            res1_4 *= alpha;
            res1_5 *= alpha;
            res1_6 *= alpha;
            res1_7 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;
            C0[4] = res0_4;
            C0[5] = res0_5;
            C0[6] = res0_6;
            C0[7] = res0_7;

            C1[0] = res1_0;
            C1[1] = res1_1;
            C1[2] = res1_2;
            C1[3] = res1_3;
            C1[4] = res1_4;
            C1[5] = res1_5;
            C1[6] = res1_6;
            C1[7] = res1_7;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 8; // number of values in A
#else
            temp -= 2; // number of values in B
#endif
            ptrba += temp*8;
            ptrbb += temp*2;
#endif

#ifdef LEFT
            off += 8; // number of values in A
#endif

            C0 = C0+8;
            C1 = C1+8;
        }

        if ( bm & 4 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*4;
            ptrbb = bb + off*2;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;

            res1_0 = 0;
            res1_1 = 0;
            res1_2 = 0;
            res1_3 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+4;	// number of values in A
#else
            temp = off+2;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;

                a0 = ptrba[2];
                res0_2 += a0*b0;
                res1_2 += a0*b1;

                a1 = ptrba[3];
                res0_3 += a1*b0;
                res1_3 += a1*b1;

                ptrba = ptrba+4;
                ptrbb = ptrbb+2;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;
            res1_2 *= alpha;
            res1_3 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;

            C1[0] = res1_0;
            C1[1] = res1_1;
            C1[2] = res1_2;
            C1[3] = res1_3;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 4; // number of values in A
#else
            temp -= 2; // number of values in B
#endif
            ptrba += temp*4;
            ptrbb += temp*2;
#endif

#ifdef LEFT
            off += 4; // number of values in A
#endif

            C0 = C0+4;
            C1 = C1+4;

        }

        if ( bm & 2 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*2;
            ptrbb = bb + off*2;
#endif

            res0_0 = 0;
            res0_1 = 0;

            res1_0 = 0;
            res1_1 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+2;	// number of values in A
#else
            temp = off+2;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;

                a1 = ptrba[1];
                res0_1 += a1*b0;
                res1_1 += a1*b1;

                ptrba = ptrba+2;
                ptrbb = ptrbb+2;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;

            res1_0 *= alpha;
            res1_1 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;

            C1[0] = res1_0;
            C1[1] = res1_1;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 2; // number of values in A
#else
            temp -= 2; // number of values in B
#endif
            ptrba += temp*2;
            ptrbb += temp*2;
#endif

#ifdef LEFT
            off += 2; // number of values in A
#endif

            C0 = C0+2;
            C1 = C1+2;

        }

        if ( bm & 1 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*1;
            ptrbb = bb + off*2;
#endif

            res0_0 = 0;

            res1_0 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+1;	// number of values in A
#else
            temp = off+2;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];
                b1 = ptrbb[1];

                a0 = ptrba[0];
                res0_0 += a0*b0;
                res1_0 += a0*b1;

                ptrba = ptrba+1;
                ptrbb = ptrbb+2;
            }

            res0_0 *= alpha;

            res1_0 *= alpha;

            C0[0] = res0_0;

            C1[0] = res1_0;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 1; // number of values in A
#else
            temp -= 2; // number of values in B
#endif
            ptrba += temp*1;
            ptrbb += temp*2;
#endif

#ifdef LEFT
            off += 1; // number of values in A
#endif

            C0 = C0+1;
            C1 = C1+1;

        }


#if defined(TRMMKERNEL) && !defined(LEFT)
        off += 2;
#endif

        k = (bk<<1);
        bb = bb+k;
        i = (ldc<<1);
        C = C+i;
    }

    for (j=0; j<(bn&1); j+=1)
    {
        C0 = C;

#if defined(TRMMKERNEL) &&  defined(LEFT)
        off = offset;
#endif

        ptrba = ba;

        for (i=0; i<bm/8; i+=1)
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*8;
            ptrbb = bb + off*1;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;
            res0_4 = 0;
            res0_5 = 0;
            res0_6 = 0;
            res0_7 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+8;	// number of values in A
#else
            temp = off+1;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];

                a0 = ptrba[0];
                res0_0 += a0*b0;

                a1 = ptrba[1];
                res0_1 += a1*b0;

                a0 = ptrba[2];
                res0_2 += a0*b0;

                a1 = ptrba[3];
                res0_3 += a1*b0;

                a0 = ptrba[4];
                res0_4 += a0*b0;

                a1 = ptrba[5];
                res0_5 += a1*b0;

                a0 = ptrba[6];
                res0_6 += a0*b0;

                a1 = ptrba[7];
                res0_7 += a1*b0;

                ptrba = ptrba+8;
                ptrbb = ptrbb+1;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;
            res0_4 *= alpha;
            res0_5 *= alpha;
            res0_6 *= alpha;
            res0_7 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;
            C0[4] = res0_4;
            C0[5] = res0_5;
            C0[6] = res0_6;
            C0[7] = res0_7;

#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 8; // number of values in A
#else
            temp -= 1; // number of values in B
#endif
            ptrba += temp*8;
            ptrbb += temp*1;
#endif

#ifdef LEFT
            off += 8; // number of values in A
#endif

            C0 = C0+8;
        }

        if ( bm & 4 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*4;
            ptrbb = bb + off*1;
#endif

            res0_0 = 0;
            res0_1 = 0;
            res0_2 = 0;
            res0_3 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+4;	// number of values in A
#else
            temp = off+1;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];

                a0 = ptrba[0];
                res0_0 += a0*b0;

                a1 = ptrba[1];
                res0_1 += a1*b0;

                a0 = ptrba[2];
                res0_2 += a0*b0;

                a1 = ptrba[3];
                res0_3 += a1*b0;

                ptrba = ptrba+4;
                ptrbb = ptrbb+1;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;
            res0_2 *= alpha;
            res0_3 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;
            C0[2] = res0_2;
            C0[3] = res0_3;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 4; // number of values in A
#else
            temp -= 1; // number of values in B
#endif
            ptrba += temp*4;
            ptrbb += temp*1;
#endif

#ifdef LEFT
            off += 4; // number of values in A
#endif

            C0 = C0+4;

        }

        if ( bm & 2 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*2;
            ptrbb = bb + off*1;
#endif

            res0_0 = 0;
            res0_1 = 0;



#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+2;	// number of values in A
#else
            temp = off+1;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];

                a0 = ptrba[0];
                res0_0 += a0*b0;

                a1 = ptrba[1];
                res0_1 += a1*b0;

                ptrba = ptrba+2;
                ptrbb = ptrbb+1;
            }

            res0_0 *= alpha;
            res0_1 *= alpha;

            C0[0] = res0_0;
            C0[1] = res0_1;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 2; // number of values in A
#else
            temp -= 1; // number of values in B
#endif
            ptrba += temp*2;
            ptrbb += temp*1;
#endif

#ifdef LEFT
            off += 2; // number of values in A
#endif

            C0 = C0+2;

        }

        if ( bm & 1 )
        {

#if (defined(LEFT) &&  defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            ptrbb = bb;
#else
            ptrba += off*1;
            ptrbb = bb + off*1;
#endif

            res0_0 = 0;


#if (defined(LEFT) && !defined(TRANSA)) || (!defined(LEFT) && defined(TRANSA))
            temp = bk-off;
#elif defined(LEFT)
            temp = off+1;	// number of values in A
#else
            temp = off+1;	// number of values in B
#endif

            for (k=0; k<temp; k++)
            {
                b0 = ptrbb[0];

                a0 = ptrba[0];
                res0_0 += a0*b0;

                ptrba = ptrba+1;
                ptrbb = ptrbb+1;
            }

            res0_0 *= alpha;

            C0[0] = res0_0;


#if ( defined(LEFT) && defined(TRANSA)) || (!defined(LEFT) && !defined(TRANSA))
            temp = bk - off;
#ifdef LEFT
            temp -= 1; // number of values in A
#else
            temp -= 1; // number of values in B
#endif
            ptrba += temp*1;
            ptrbb += temp*1;
#endif

#ifdef LEFT
            off += 1; // number of values in A
#endif

            C0 = C0+1;

        }



#if defined(TRMMKERNEL) && !defined(LEFT)
        off += 1;
#endif

        k = (bk<<0);
        bb = bb+k;
        C = C+ldc;
    }
    return 0;
}
