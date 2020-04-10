#include "headers/block_cipher.h"
#include "headers/random.h"
#include "headers/frequency_analysis.h"
#include "headers/rsa.h"

#define MAX_SEQUENCE_LENGTH 10000
#define M 10
#define MAX_TEXT_LENGTH 10000
#define ALPHABET_LENGTH 26

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s lab_num", argv[0]);
        exit(-1);
    }

    int op = strtol(argv[1], NULL, 10);

    switch (op) {
    case 1: {
        char test_num[MAX_SEQUENCE_LENGTH] = "s;vie,bhfjdhruegcndj";
        uint64 test_K = 10000010101010100;
        printf("%s, %llu - number, K before encryption\n", test_num, test_K);
        encrypt((char *)&test_num, &test_K, strlen(test_num));
        printf("%s, %llu - number, K after encryption\n", test_num, test_K);
        decrypt((char *)&test_num, &test_K, strlen(test_num));
        printf("%s, %llu - number, K after decryption\n", test_num, test_K);

        break;
    }
    case 2:{
        double_t sequence[MAX_SEQUENCE_LENGTH];
        struct periodic_values pv;
        __uint32_t counts[M];
        korobov_modification(sequence, MAX_SEQUENCE_LENGTH, 100, 7);
        find_periodic_values(sequence, MAX_SEQUENCE_LENGTH, 500, &pv);
        double_t chi = chi_metric(sequence, MAX_SEQUENCE_LENGTH, counts, M);
        printf("L = %d, l = %d\n", pv.L, pv.l);
        for (int i = 0; i < 10; i++) printf("%f -- %f\n", sequence[i], sequence[i + pv.L - 1]);
        for (int i = 0; i < M; i++) printf("%d ", counts[i]);
        printf("\n%f\n", chi);

        break;
    }
    case 3: {
        if (decode("rsa.txt", 517829673878357, 12731) == -1) {
            printf("Couldn't decode");
        }
        break;
    }
    case 4:break;
    }

    //LAB 5
    /*char *text = malloc(sizeof(char) * MAX_TEXT_LENGTH);
    strcpy(text, "pyt viqebov, xp q bqcvmc oxgvmzv jylof myc bvtexc tyrqocr-ptvv tvfxzctxhlcxym yp cwv btystqe hr qoo cwyzv jwy tvgvxnv gybxvz fxtvgcor yt xmfxtvgcor cwtylsw ryl, cwvm cwv ymor jqr ryl gylof zqcxzpr hycw xc qmf cwxz oxgvmzv jylof hv cy tvptqxm vmcxtvor ptye fxzctxhlcxym yp cwv btystqe. xp qmr bytcxym yp cwxz zvgcxym xz wvof xmnqoxf yt lmvmpytgvqhov lmfvt qmr bqtcxgloqt gxtglezcqmgv, cwv hqoqmgv yp cwv zvgcxym xz xmcvmfvf cy qbbor qmf cwv zvgcxym qz q jwyov xz xmcvmfvf cy qbbor xm ycwvt gxtglezcqmgvz. xc xz myc cwv bltbyzv yp cwxz zvgcxym cy xmflgv ryl cy xmptxmsv qmr bqcvmcz yt ycwvt btybvtcr txswc goqxez yt cy gymcvzc nqoxfxcr yp qmr zlgw goqxez; cwxz zvgcxym wqz cwv zyov bltbyzv yp btycvgcxms cwv xmcvstxcr yp cwv ptvv zypcjqtv fxzctxhlcxym zrzcve, jwxgw xz xebovevmcvf hr blhoxg oxgvmzv btqgcxgvz. eqmr bvybov wqnv eqfv svmvtylz gymctxhlcxymz cy cwv jxfv tqmsv yp zypcjqtv fxzctxhlcvf cwtylsw cwqc zrzcve xm tvoxqmgv ym gymzxzcvmc qbboxgqcxym yp cwqc zrzcve; xc xz lb cy cwv qlcwyt/fymyt cy fvgxfv xp wv yt zwv xz jxooxms cy fxzctxhlcv zypcjqtv cwtylsw qmr ycwvt zrzcve qmf q oxgvmzvv gqmmyc xebyzv cwqc gwyxgv. cwxz zvgcxym xz xmcvmfvf cy eqdv cwytylswor govqt jwqc xz hvoxvnvf cy hv q gymzvalvmgv yp cwv tvzc yp cwxz oxgvmzv. xp cwv fxzctxhlcxym qmf/yt lzv yp cwv btystqe xz tvzctxgcvf xm gvtcqxm gylmctxvz vxcwvt hr bqcvmcz yt hr gybrtxswcvf xmcvtpqgvz, cwv ytxsxmqo gybrtxswc wyofvt jwy boqgvz cwv btystqe lmfvt cwxz oxgvmzv eqr qff qm viboxgxc svystqbwxgqo fxzctxhlcxym oxexcqcxym vigolfxms cwyzv gylmctxvz, zy cwqc fxzctxhlcxym xz bvtexccvf ymor xm yt qeyms gylmctxvz myc cwlz vigolfvf. xm zlgw gqzv, cwxz oxgvmzv xmgytbytqcvz cwv oxexcqcxym qz xp jtxccvm xm cwv hyfr yp cwxz oxgvmzv. cwv ptvv zypcjqtv pylmfqcxym eqr blhoxzw tvnxzvf qmf/yt mvj nvtzxymz yp cwv svmvtqo blhoxg oxgvmzv ptye cxev cy cxev. zlgw mvj nvtzxymz jxoo hv zxexoqt xm zbxtxc cy cwv btvzvmc nvtzxym, hlc eqr fxppvt xm fvcqxo cy qfftvzz mvj btyhovez yt gymgvtmz. vqgw nvtzxym xz sxnvm q fxzcxmslxzwxms nvtzxym mlehvt. xp cwv btystqe zbvgxpxvz q nvtzxym mlehvt yp cwxz oxgvmzv jwxgw qbboxvz cy xc qmf \"qmr oqcvt nvtzxym\", ryl wqnv cwv ybcxym yp pyooyjxms cwv cvtez qmf gymfxcxymz vxcwvt yp cwqc nvtzxym yt yp qmr oqcvt nvtzxym blhoxzwvf hr cwv ptvv zypcjqtv pylmfqcxym. xp cwv btystqe fyvz myc zbvgxpr q nvtzxym mlehvt yp cwxz oxgvmzv, ryl eqr gwyyzv qmr nvtzxym vnvt blhoxzwvf hr cwv ptvv zypcjqtv pylmfqcxym. xp ryl jxzw cy xmgytbytqcv bqtcz yp cwv btystqe xmcy ycwvt ptvv btystqez jwyzv fxzctxhlcxym gymfxcxymz qtv fxppvtvmc, jtxcv cy cwv qlcwyt cy qzd pyt bvtexzzxym. pyt zypcjqtv jwxgw xz gybrtxswcvf hr cwv ptvv zypcjqtv pylmfqcxym, jtxcv cy cwv ptvv zypcjqtv pylmfqcxym; jv zyevcxevz eqdv vigvbcxymz pyt cwxz. ylt fvgxzxym jxoo hv slxfvf hr cwv cjy syqoz yp btvzvtnxms cwv ptvv zcqclz yp qoo fvtxnqcxnvz yp ylt ptvv zypcjqtv qmf yp btyeycxms cwv zwqtxms qmf tvlzv yp zypcjqtv svmvtqoor. hvgqlzv cwv btystqe xz oxgvmzvf ptvv yp gwqtsv, cwvtv xz my jqttqmcr pyt cwv btystqe, cy cwv vicvmc bvtexccvf hr qbboxgqhov oqj. vigvbc jwvm ycwvtjxzv zcqcvf xm jtxcxms cwv gybrtxswc wyofvtz qmf/yt ycwvt bqtcxvz btynxfv cwv btystqe \"qz xz\" jxcwylc jqttqmcr yp qmr dxmf, vxcwvt vibtvzzvf yt xeboxvf, xmgolfxms, hlc myc oxexcvf cy, cwv xeboxvf jqttqmcxvz yp evtgwqmcqhxoxcr qmf pxcmvzz pyt q bqtcxgloqt bltbyzv. cwv vmcxtv txzd qz cy cwv alqoxcr qmf bvtpyteqmgv yp cwv btystqe xz jxcw ryl. zwylof cwv btystqe btynv fvpvgcxnv, ryl qzzlev cwv gyzc yp qoo mvgvzzqtr zvtnxgxms, tvbqxt yt gyttvgcxym");

    struct frequency_pair alphabet_frequencies[] = {
            {.letter = 'a', .frequency = 7.96f},
            {.letter = 'b', .frequency = 1.60f},
            {.letter = 'c', .frequency = 2.84f},
            {.letter = 'd', .frequency = 4.01f},
            //{.letter = 'e', .frequency = 12.86f},
            //{.letter = 'f', .frequency = 2.62f},
            {.letter = 'g', .frequency = 1.99f},
            //{.letter = 'h', .frequency = 5.39f},
            //{.letter = 'i', .frequency = 7.77f},
            {.letter = 'j', .frequency = 0.16f},
            {.letter = 'k', .frequency = 0.41f},
            {.letter = 'l', .frequency = 3.51f},
            {.letter = 'm', .frequency = 2.43f},
            {.letter = 'n', .frequency = 7.51f},
            {.letter = 'o', .frequency = 6.62f},
            //{.letter = 'p', .frequency = 1.81f},
            {.letter = 'q', .frequency = 0.17f},
            //{.letter = 'r', .frequency = 6.83f},
            {.letter = 's', .frequency = 6.62f},
            //{.letter = 't', .frequency = 9.72f},
            {.letter = 'u', .frequency = 2.48f},
            {.letter = 'v', .frequency = 1.15f},
            {.letter = 'w', .frequency = 1.80f},
            {.letter = 'x', .frequency = 0.17f},
            {.letter = 'y', .frequency = 1.52f},
            {.letter = 'z', .frequency = 0.05f}
    };
    int length = sizeof(alphabet_frequencies) / sizeof(struct frequency_pair);
    struct frequency_pair text_frequencies[sizeof(alphabet_frequencies) / sizeof(struct frequency_pair)];

    struct known_pair kp[] = {
            {.alphabet_letter = 't', .text_letter = 'c'},
            {.alphabet_letter = 'h', .text_letter = 'w'},
            {.alphabet_letter = 'e', .text_letter = 'v'},
            {.alphabet_letter = 'o', .text_letter = 'y'},
            {.alphabet_letter = 'f', .text_letter = 'p'},
            {.alphabet_letter = 'r', .text_letter = 't'}
    };

    decipher(text_frequencies, alphabet_frequencies, length, text, strlen(text), kp, ALPHABET_LENGTH - length);
    printf("%s", text);

    free(text);*/

    return 0;
}