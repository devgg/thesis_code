#pragma once

#include "kmer.hpp"

namespace genome {

    template<unsigned int N>
    kmer<N>::kmer(std::array<byte, size> data) : m_data(std::move(data)) {
    }

    template<unsigned int N>
    unsigned int kmer<N>::chars_to_int(char c1, char c2, char c3, char c4) {
        unsigned int result = 0;
        return result + (c1 << 24) + (c2 << 16) + (c3 << 8) + c4;
    }

    template<unsigned int N>
    kmer<N>::kmer() {
        static_assert(sizeof(kmer<N>) == kmer<N>::size);
    }

    template<unsigned int N>
    const std::array<byte, kmer<N>::size> &kmer<N>::data() const {
        return m_data;
    }

    template<unsigned int N>
    std::string kmer<N>::string() const {
        std::string result;
//    for(size_t i = 0; i < m_data.size(); i++) {
//        std::string byte_string = m_byte_to_bps.at(m_data[i]);
//        if (i == 0 && N % 4 != 0) {
//            byte_string = byte_string.substr(4 - N % 4, std::string::npos);
//        }
//        result += byte_string;
//    }
        for (size_t i = 0; i < m_data.size(); i++) {
            std::string byte_string = m_byte_to_bps.at(m_data[m_data.size() - i - 1]);
            if (i == 0 && N % 4 != 0) {
                byte_string = byte_string.substr(4 - N % 4, std::string::npos);
            }
            result += byte_string;
        }
        return result;
    }

    template<unsigned int N>
    void kmer<N>::print(std::ostream &ostream) const {
        ostream << string();
    }

    template<unsigned int N>
    const std::map<unsigned int, byte> kmer<N>::m_bps_to_byte = {
            {1094795585, 0}, {1128350017, 1}, {1195458881, 2}, {1413562689, 3}, {1094926657, 4},
            {1128481089, 5}, {1195589953, 6}, {1413693761, 7}, {1095188801, 8}, {1128743233, 9},
            {1195852097, 10}, {1413955905, 11}, {1096040769, 12}, {1129595201, 13}, {1196704065, 14},
            {1414807873, 15}, {1094796097, 16}, {1128350529, 17}, {1195459393, 18}, {1413563201, 19},
            {1094927169, 20}, {1128481601, 21}, {1195590465, 22}, {1413694273, 23}, {1095189313, 24},
            {1128743745, 25}, {1195852609, 26}, {1413956417, 27}, {1096041281, 28}, {1129595713, 29},
            {1196704577, 30}, {1414808385, 31}, {1094797121, 32}, {1128351553, 33}, {1195460417, 34},
            {1413564225, 35}, {1094928193, 36}, {1128482625, 37}, {1195591489, 38}, {1413695297, 39},
            {1095190337, 40}, {1128744769, 41}, {1195853633, 42}, {1413957441, 43}, {1096042305, 44},
            {1129596737, 45}, {1196705601, 46}, {1414809409, 47}, {1094800449, 48}, {1128354881, 49},
            {1195463745, 50}, {1413567553, 51}, {1094931521, 52}, {1128485953, 53}, {1195594817, 54},
            {1413698625, 55}, {1095193665, 56}, {1128748097, 57}, {1195856961, 58}, {1413960769, 59},
            {1096045633, 60}, {1129600065, 61}, {1196708929, 62}, {1414812737, 63}, {1094795587, 64},
            {1128350019, 65}, {1195458883, 66}, {1413562691, 67}, {1094926659, 68}, {1128481091, 69},
            {1195589955, 70}, {1413693763, 71}, {1095188803, 72}, {1128743235, 73}, {1195852099, 74},
            {1413955907, 75}, {1096040771, 76}, {1129595203, 77}, {1196704067, 78}, {1414807875, 79},
            {1094796099, 80}, {1128350531, 81}, {1195459395, 82}, {1413563203, 83}, {1094927171, 84},
            {1128481603, 85}, {1195590467, 86}, {1413694275, 87}, {1095189315, 88}, {1128743747, 89},
            {1195852611, 90}, {1413956419, 91}, {1096041283, 92}, {1129595715, 93}, {1196704579, 94},
            {1414808387, 95}, {1094797123, 96}, {1128351555, 97}, {1195460419, 98}, {1413564227, 99},
            {1094928195, 100}, {1128482627, 101}, {1195591491, 102}, {1413695299, 103}, {1095190339, 104},
            {1128744771, 105}, {1195853635, 106}, {1413957443, 107}, {1096042307, 108}, {1129596739, 109},
            {1196705603, 110}, {1414809411, 111}, {1094800451, 112}, {1128354883, 113}, {1195463747, 114},
            {1413567555, 115}, {1094931523, 116}, {1128485955, 117}, {1195594819, 118}, {1413698627, 119},
            {1095193667, 120}, {1128748099, 121}, {1195856963, 122}, {1413960771, 123}, {1096045635, 124},
            {1129600067, 125}, {1196708931, 126}, {1414812739, 127}, {1094795591, 128}, {1128350023, 129},
            {1195458887, 130}, {1413562695, 131}, {1094926663, 132}, {1128481095, 133}, {1195589959, 134},
            {1413693767, 135}, {1095188807, 136}, {1128743239, 137}, {1195852103, 138}, {1413955911, 139},
            {1096040775, 140}, {1129595207, 141}, {1196704071, 142}, {1414807879, 143}, {1094796103, 144},
            {1128350535, 145}, {1195459399, 146}, {1413563207, 147}, {1094927175, 148}, {1128481607, 149},
            {1195590471, 150}, {1413694279, 151}, {1095189319, 152}, {1128743751, 153}, {1195852615, 154},
            {1413956423, 155}, {1096041287, 156}, {1129595719, 157}, {1196704583, 158}, {1414808391, 159},
            {1094797127, 160}, {1128351559, 161}, {1195460423, 162}, {1413564231, 163}, {1094928199, 164},
            {1128482631, 165}, {1195591495, 166}, {1413695303, 167}, {1095190343, 168}, {1128744775, 169},
            {1195853639, 170}, {1413957447, 171}, {1096042311, 172}, {1129596743, 173}, {1196705607, 174},
            {1414809415, 175}, {1094800455, 176}, {1128354887, 177}, {1195463751, 178}, {1413567559, 179},
            {1094931527, 180}, {1128485959, 181}, {1195594823, 182}, {1413698631, 183}, {1095193671, 184},
            {1128748103, 185}, {1195856967, 186}, {1413960775, 187}, {1096045639, 188}, {1129600071, 189},
            {1196708935, 190}, {1414812743, 191}, {1094795604, 192}, {1128350036, 193}, {1195458900, 194},
            {1413562708, 195}, {1094926676, 196}, {1128481108, 197}, {1195589972, 198}, {1413693780, 199},
            {1095188820, 200}, {1128743252, 201}, {1195852116, 202}, {1413955924, 203}, {1096040788, 204},
            {1129595220, 205}, {1196704084, 206}, {1414807892, 207}, {1094796116, 208}, {1128350548, 209},
            {1195459412, 210}, {1413563220, 211}, {1094927188, 212}, {1128481620, 213}, {1195590484, 214},
            {1413694292, 215}, {1095189332, 216}, {1128743764, 217}, {1195852628, 218}, {1413956436, 219},
            {1096041300, 220}, {1129595732, 221}, {1196704596, 222}, {1414808404, 223}, {1094797140, 224},
            {1128351572, 225}, {1195460436, 226}, {1413564244, 227}, {1094928212, 228}, {1128482644, 229},
            {1195591508, 230}, {1413695316, 231}, {1095190356, 232}, {1128744788, 233}, {1195853652, 234},
            {1413957460, 235}, {1096042324, 236}, {1129596756, 237}, {1196705620, 238}, {1414809428, 239},
            {1094800468, 240}, {1128354900, 241}, {1195463764, 242}, {1413567572, 243}, {1094931540, 244},
            {1128485972, 245}, {1195594836, 246}, {1413698644, 247}, {1095193684, 248}, {1128748116, 249},
            {1195856980, 250}, {1413960788, 251}, {1096045652, 252}, {1129600084, 253}, {1196708948, 254},
            {1414812756, 255} };

    template<unsigned int N>
    const std::map<byte, std::string> kmer<N>::m_byte_to_bps = {
            {0, "AAAA"}, {1, "AAAC"}, {2, "AAAG"}, {3, "AAAT"}, {4, "AACA"}, {5, "AACC"}, {6, "AACG"}, {7, "AACT"},
            {8, "AAGA"}, {9, "AAGC"}, {10, "AAGG"}, {11, "AAGT"}, {12, "AATA"}, {13, "AATC"}, {14, "AATG"}, {15, "AATT"},
            {16, "ACAA"}, {17, "ACAC"}, {18, "ACAG"}, {19, "ACAT"}, {20, "ACCA"}, {21, "ACCC"}, {22, "ACCG"}, {23, "ACCT"},
            {24, "ACGA"}, {25, "ACGC"}, {26, "ACGG"}, {27, "ACGT"}, {28, "ACTA"}, {29, "ACTC"}, {30, "ACTG"}, {31, "ACTT"},
            {32, "AGAA"}, {33, "AGAC"}, {34, "AGAG"}, {35, "AGAT"}, {36, "AGCA"}, {37, "AGCC"}, {38, "AGCG"}, {39, "AGCT"},
            {40, "AGGA"}, {41, "AGGC"}, {42, "AGGG"}, {43, "AGGT"}, {44, "AGTA"}, {45, "AGTC"}, {46, "AGTG"}, {47, "AGTT"},
            {48, "ATAA"}, {49, "ATAC"}, {50, "ATAG"}, {51, "ATAT"}, {52, "ATCA"}, {53, "ATCC"}, {54, "ATCG"}, {55, "ATCT"},
            {56, "ATGA"}, {57, "ATGC"}, {58, "ATGG"}, {59, "ATGT"}, {60, "ATTA"}, {61, "ATTC"}, {62, "ATTG"}, {63, "ATTT"},
            {64, "CAAA"}, {65, "CAAC"}, {66, "CAAG"}, {67, "CAAT"}, {68, "CACA"}, {69, "CACC"}, {70, "CACG"}, {71, "CACT"},
            {72, "CAGA"}, {73, "CAGC"}, {74, "CAGG"}, {75, "CAGT"}, {76, "CATA"}, {77, "CATC"}, {78, "CATG"}, {79, "CATT"},
            {80, "CCAA"}, {81, "CCAC"}, {82, "CCAG"}, {83, "CCAT"}, {84, "CCCA"}, {85, "CCCC"}, {86, "CCCG"}, {87, "CCCT"},
            {88, "CCGA"}, {89, "CCGC"}, {90, "CCGG"}, {91, "CCGT"}, {92, "CCTA"}, {93, "CCTC"}, {94, "CCTG"}, {95, "CCTT"},
            {96, "CGAA"}, {97, "CGAC"}, {98, "CGAG"}, {99, "CGAT"}, {100, "CGCA"}, {101, "CGCC"}, {102, "CGCG"}, {103, "CGCT"},
            {104, "CGGA"}, {105, "CGGC"}, {106, "CGGG"}, {107, "CGGT"}, {108, "CGTA"}, {109, "CGTC"}, {110, "CGTG"}, {111, "CGTT"},
            {112, "CTAA"}, {113, "CTAC"}, {114, "CTAG"}, {115, "CTAT"}, {116, "CTCA"}, {117, "CTCC"}, {118, "CTCG"}, {119, "CTCT"},
            {120, "CTGA"}, {121, "CTGC"}, {122, "CTGG"}, {123, "CTGT"}, {124, "CTTA"}, {125, "CTTC"}, {126, "CTTG"}, {127, "CTTT"},
            {128, "GAAA"}, {129, "GAAC"}, {130, "GAAG"}, {131, "GAAT"}, {132, "GACA"}, {133, "GACC"}, {134, "GACG"}, {135, "GACT"},
            {136, "GAGA"}, {137, "GAGC"}, {138, "GAGG"}, {139, "GAGT"}, {140, "GATA"}, {141, "GATC"}, {142, "GATG"}, {143, "GATT"},
            {144, "GCAA"}, {145, "GCAC"}, {146, "GCAG"}, {147, "GCAT"}, {148, "GCCA"}, {149, "GCCC"}, {150, "GCCG"}, {151, "GCCT"},
            {152, "GCGA"}, {153, "GCGC"}, {154, "GCGG"}, {155, "GCGT"}, {156, "GCTA"}, {157, "GCTC"}, {158, "GCTG"}, {159, "GCTT"},
            {160, "GGAA"}, {161, "GGAC"}, {162, "GGAG"}, {163, "GGAT"}, {164, "GGCA"}, {165, "GGCC"}, {166, "GGCG"}, {167, "GGCT"},
            {168, "GGGA"}, {169, "GGGC"}, {170, "GGGG"}, {171, "GGGT"}, {172, "GGTA"}, {173, "GGTC"}, {174, "GGTG"}, {175, "GGTT"},
            {176, "GTAA"}, {177, "GTAC"}, {178, "GTAG"}, {179, "GTAT"}, {180, "GTCA"}, {181, "GTCC"}, {182, "GTCG"}, {183, "GTCT"},
            {184, "GTGA"}, {185, "GTGC"}, {186, "GTGG"}, {187, "GTGT"}, {188, "GTTA"}, {189, "GTTC"}, {190, "GTTG"}, {191, "GTTT"},
            {192, "TAAA"}, {193, "TAAC"}, {194, "TAAG"}, {195, "TAAT"}, {196, "TACA"}, {197, "TACC"}, {198, "TACG"}, {199, "TACT"},
            {200, "TAGA"}, {201, "TAGC"}, {202, "TAGG"}, {203, "TAGT"}, {204, "TATA"}, {205, "TATC"}, {206, "TATG"}, {207, "TATT"},
            {208, "TCAA"}, {209, "TCAC"}, {210, "TCAG"}, {211, "TCAT"}, {212, "TCCA"}, {213, "TCCC"}, {214, "TCCG"}, {215, "TCCT"},
            {216, "TCGA"}, {217, "TCGC"}, {218, "TCGG"}, {219, "TCGT"}, {220, "TCTA"}, {221, "TCTC"}, {222, "TCTG"}, {223, "TCTT"},
            {224, "TGAA"}, {225, "TGAC"}, {226, "TGAG"}, {227, "TGAT"}, {228, "TGCA"}, {229, "TGCC"}, {230, "TGCG"}, {231, "TGCT"},
            {232, "TGGA"}, {233, "TGGC"}, {234, "TGGG"}, {235, "TGGT"}, {236, "TGTA"}, {237, "TGTC"}, {238, "TGTG"}, {239, "TGTT"},
            {240, "TTAA"}, {241, "TTAC"}, {242, "TTAG"}, {243, "TTAT"}, {244, "TTCA"}, {245, "TTCC"}, {246, "TTCG"}, {247, "TTCT"},
            {248, "TTGA"}, {249, "TTGC"}, {250, "TTGG"}, {251, "TTGT"}, {252, "TTTA"}, {253, "TTTC"}, {254, "TTTG"}, {255, "TTTT"}};
}
