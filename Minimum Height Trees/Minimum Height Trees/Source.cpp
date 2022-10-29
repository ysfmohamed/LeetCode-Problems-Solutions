#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<set>
#include <unordered_map>
using namespace std;

/*
* Problem number: 310
* Difficulty: Medium
*/

unordered_map<int, vector<int>> buildGraph(vector<vector<int>> edges)
{
	unordered_map<int, vector<int>> graph;

	for (int i = 0; i < edges.size(); i++)
	{
		if (graph.find(edges[i][0]) == graph.end()) // vertex is not in the graph
			graph.insert({edges[i][0], vector<int>()});
		if (graph.find(edges[i][1]) == graph.end())
			graph.insert({edges[i][1], vector<int>()});
		
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	return graph;
}

/*
* Bruteforce Solution
* Time Complexity: O(V^2)
* Space Complexity: O(V) 
*/

vector<int> findMinHeightTrees(int n, vector<vector<int>> edges) // 
{
	// {(vertex, distance)}
	unordered_map<int, vector<int>> graph = buildGraph(edges);

	vector<pair<int, int>> vec;

	pair<int, int> vertexDistance;

	pair<int, int> currentVertDis;
	queue<pair<int, int>> queue;
	unordered_map<int, bool> visited;

	for (int i = 0; i < n; i++)
	{
		int maxDistance = INT_MIN;

		vertexDistance.first = i;
		vertexDistance.second = 0;
		queue.push(vertexDistance);
		visited.insert({i, true});

		while (queue.size() > 0)
		{
			currentVertDis = queue.front();
			queue.pop();
			maxDistance = max(maxDistance, currentVertDis.second);

			for (auto neighbour : graph[currentVertDis.first])
			{
				if (visited.find(neighbour) == visited.end())
				{
					vertexDistance.first = neighbour;
					vertexDistance.second = currentVertDis.second + 1;
					queue.push(vertexDistance);
					visited.insert({neighbour, true});
				}
			}
		}
		vec.push_back({i, maxDistance});
		visited.clear();
	}

	int minHeight = vec[0].second;

	for (auto ele : vec)
	{
		if (minHeight > ele.second)
			minHeight = ele.second;
	}

	vector<int> minHeightTrees;
	for (auto ele : vec)
	{
		if (ele.second == minHeight)
			minHeightTrees.push_back(ele.first);
	}

	return minHeightTrees;
}


int main()
{
	vector<int> minHeightTrees;
	minHeightTrees =  findMinHeightTrees(4, { {1,0}, {1,2}, {1,3} });
	for(auto vertex : minHeightTrees)
		cout << vertex << " ";

	cout << endl;

	minHeightTrees = findMinHeightTrees(6, { {3,0}, {3,1}, {3,2}, {3,4}, {5,4} });
	for(auto vertex : minHeightTrees)
		cout << vertex << " ";
	cout << endl;

	minHeightTrees = findMinHeightTrees(1313, {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {0, 5}, {3, 6}, {3, 7}, {6, 8}, {3, 9}, {9, 10}, {9, 11}, {10, 12}, {3, 13}, {2, 14}, {5, 15}, {1, 16}, {5, 17}, {15, 18}, {17, 19}, {12, 20}, {20, 21}, {21, 22}, {2, 23}, {12, 24}, {13, 25}, {23, 26}, {6, 27}, {14, 28}, {7, 29}, {14, 30}, {28, 31}, {3, 32}, {20, 33}, {6, 34}, {28, 35}, {14, 36}, {12, 37}, {25, 38}, {28, 39}, {0, 40}, {11, 41}, {19, 42}, {41, 43}, {24, 44}, {43, 45}, {14, 46}, {36, 47}, {26, 48}, {16, 49}, {42, 50}, {43, 51}, {11, 52}, {7, 53}, {50, 54}, {17, 55}, {9, 56}, {0, 57}, {16, 58}, {26, 59}, {32, 60}, {53, 61}, {30, 62}, {40, 63}, {63, 64}, {45, 65}, {13, 66}, {24, 67}, {42, 68}, {2, 69}, {63, 70}, {39, 71}, {34, 72}, {20, 73}, {20, 74}, {63, 75}, {12, 76}, {57, 77}, {51, 78}, {17, 79}, {24, 80}, {22, 81}, {76, 82}, {4, 83}, {16, 84}, {75, 85}, {21, 86}, {21, 87}, {8, 88}, {28, 89}, {85, 90}, {31, 91}, {53, 92}, {57, 93}, {45, 94}, {67, 95}, {87, 96}, {10, 97}, {95, 98}, {0, 99}, {46, 100}, {39, 101}, {47, 102}, {101, 103}, {72, 104}, {2, 105}, {3, 106}, {78, 107}, {32, 108}, {23, 109}, {73, 110}, {102, 111}, {50, 112}, {8, 113}, {85, 114}, {68, 115}, {87, 116}, {102, 117}, {77, 118}, {62, 119}, {70, 120}, {86, 121}, {13, 122}, {101, 123}, {69, 124}, {37, 125}, {48, 126}, {78, 127}, {40, 128}, {26, 129}, {7, 130}, {80, 131}, {21, 132}, {81, 133}, {62, 134}, {97, 135}, {71, 136}, {123, 137}, {78, 138}, {16, 139}, {5, 140}, {10, 141}, {138, 142}, {21, 143}, {15, 144}, {91, 145}, {0, 146}, {65, 147}, {64, 148}, {28, 149}, {86, 150}, {28, 151}, {111, 152}, {140, 153}, {138, 154}, {77, 155}, {145, 156}, {50, 157}, {87, 158}, {96, 159}, {105, 160}, {59, 161}, {1, 162}, {11, 163}, {121, 164}, {48, 165}, {119, 166}, {133, 167}, {26, 168}, {92, 169}, {63, 170}, {158, 171}, {164, 172}, {115, 173}, {66, 174}, {123, 175}, {33, 176}, {76, 177}, {119, 178}, {114, 179}, {124, 180}, {164, 181}, {85, 182}, {143, 183}, {110, 184}, {53, 185}, {120, 186}, {78, 187}, {131, 188}, {185, 189}, {69, 190}, {168, 191}, {51, 192}, {89, 193}, {159, 194}, {176, 195}, {13, 196}, {51, 197}, {6, 198}, {28, 199}, {46, 200}, {105, 201}, {167, 202}, {148, 203}, {19, 204}, {204, 205}, {6, 206}, {151, 207}, {44, 208}, {54, 209}, {184, 210}, {176, 211}, {173, 212}, {200, 213}, {203, 214}, {106, 215}, {87, 216}, {1, 217}, {173, 218}, {103, 219}, {160, 220}, {118, 221}, {50, 222}, {152, 223}, {25, 224}, {9, 225}, {64, 226}, {6, 227}, {61, 228}, {144, 229}, {212, 230}, {166, 231}, {30, 232}, {196, 233}, {215, 234}, {109, 235}, {183, 236}, {13, 237}, {183, 238}, {18, 239}, {149, 240}, {189, 241}, {149, 242}, {157, 243}, {116, 244}, {99, 245}, {30, 246}, {56, 247}, {239, 248}, {239, 249}, {57, 250}, {31, 251}, {189, 252}, {101, 253}, {101, 254}, {110, 255}, {1, 256}, {113, 257}, {161, 258}, {25, 259}, {44, 260}, {194, 261}, {137, 262}, {218, 263}, {183, 264}, {228, 265}, {153, 266}, {136, 267}, {201, 268}, {265, 269}, {116, 270}, {236, 271}, {32, 272}, {70, 273}, {104, 274}, {82, 275}, {198, 276}, {44, 277}, {262, 278}, {269, 279}, {26, 280}, {91, 281}, {180, 282}, {157, 283}, {36, 284}, {215, 285}, {183, 286}, {1, 287}, {39, 288}, {164, 289}, {110, 290}, {266, 291}, {208, 292}, {258, 293}, {68, 294}, {1, 295}, {100, 296}, {16, 297}, {107, 298}, {135, 299}, {55, 300}, {226, 301}, {155, 302}, {68, 303}, {32, 304}, {149, 305}, {217, 306}, {186, 307}, {69, 308}, {244, 309}, {14, 310}, {216, 311}, {211, 312}, {232, 313}, {148, 314}, {85, 315}, {91, 316}, {168, 317}, {90, 318}, {228, 319}, {216, 320}, {51, 321}, {31, 322}, {230, 323}, {160, 324}, {200, 325}, {94, 326}, {282, 327}, {162, 328}, {130, 329}, {87, 330}, {29, 331}, {295, 332}, {32, 333}, {136, 334}, {219, 335}, {218, 336}, {25, 337}, {233, 338}, {55, 339}, {130, 340}, {319, 341}, {165, 342}, {255, 343}, {15, 344}, {342, 345}, {74, 346}, {172, 347}, {28, 348}, {255, 349}, {47, 350}, {193, 351}, {19, 352}, {303, 353}, {205, 354}, {174, 355}, {172, 356}, {260, 357}, {243, 358}, {186, 359}, {181, 360}, {51, 361}, {34, 362}, {31, 363}, {283, 364}, {283, 365}, {122, 366}, {137, 367}, {225, 368}, {296, 369}, {346, 370}, {235, 371}, {278, 372}, {116, 373}, {31, 374}, {248, 375}, {89, 376}, {20, 377}, {287, 378}, {222, 379}, {33, 380}, {3, 381}, {140, 382}, {185, 383}, {255, 384}, {241, 385}, {164, 386}, {185, 387}, {208, 388}, {347, 389}, {235, 390}, {157, 391}, {88, 392}, {138, 393}, {163, 394}, {69, 395}, {241, 396}, {307, 397}, {271, 398}, {248, 399}, {346, 400}, {265, 401}, {90, 402}, {249, 403}, {43, 404}, {10, 405}, {159, 406}, {383, 407}, {174, 408}, {292, 409}, {288, 410}, {149, 411}, {244, 412}, {174, 413}, {201, 414}, {287, 415}, {94, 416}, {102, 417}, {123, 418}, {10, 419}, {332, 420}, {192, 421}, {377, 422}, {136, 423}, {119, 424}, {187, 425}, {128, 426}, {413, 427}, {3, 428}, {255, 429}, {410, 430}, {303, 431}, {424, 432}, {311, 433}, {246, 434}, {366, 435}, {378, 436}, {360, 437}, {120, 438}, {90, 439}, {353, 440}, {126, 441}, {78, 442}, {23, 443}, {115, 444}, {6, 445}, {359, 446}, {338, 447}, {180, 448}, {71, 449}, {190, 450}, {128, 451}, {408, 452}, {341, 453}, {426, 454}, {14, 455}, {455, 456}, {411, 457}, {107, 458}, {450, 459}, {351, 460}, {235, 461}, {422, 462}, {316, 463}, {272, 464}, {204, 465}, {102, 466}, {145, 467}, {20, 468}, {326, 469}, {186, 470}, {266, 471}, {127, 472}, {144, 473}, {112, 474}, {151, 475}, {200, 476}, {185, 477}, {291, 478}, {438, 479}, {422, 480}, {377, 481}, {261, 482}, {437, 483}, {204, 484}, {324, 485}, {402, 486}, {106, 487}, {268, 488}, {237, 489}, {49, 490}, {253, 491}, {256, 492}, {8, 493}, {115, 494}, {46, 495}, {101, 496}, {325, 497}, {90, 498}, {146, 499}, {252, 500}, {255, 501}, {277, 502}, {129, 503}, {339, 504}, {6, 505}, {462, 506}, {363, 507}, {421, 508}, {7, 509}, {279, 510}, {361, 511}, {35, 512}, {112, 513}, {113, 514}, {194, 515}, {128, 516}, {65, 517}, {26, 518}, {305, 519}, {97, 520}, {352, 521}, {283, 522}, {4, 523}, {497, 524}, {385, 525}, {212, 526}, {76, 527}, {92, 528}, {194, 529}, {344, 530}, {510, 531}, {461, 532}, {89, 533}, {228, 534}, {97, 535}, {194, 536}, {446, 537}, {100, 538}, {120, 539}, {257, 540}, {46, 541}, {230, 542}, {357, 543}, {365, 544}, {265, 545}, {123, 546}, {290, 547}, {100, 548}, {194, 549}, {134, 550}, {538, 551}, {114, 552}, {52, 553}, {251, 554}, {236, 555}, {416, 556}, {264, 557}, {461, 558}, {14, 559}, {376, 560}, {254, 561}, {422, 562}, {233, 563}, {409, 564}, {14, 565}, {190, 566}, {151, 567}, {543, 568}, {516, 569}, {369, 570}, {432, 571}, {343, 572}, {341, 573}, {531, 574}, {77, 575}, {394, 576}, {471, 577}, {293, 578}, {428, 579}, {360, 580}, {524, 581}, {471, 582}, {63, 583}, {556, 584}, {254, 585}, {583, 586}, {491, 587}, {460, 588}, {250, 589}, {329, 590}, {504, 591}, {414, 592}, {353, 593}, {172, 594}, {582, 595}, {474, 596}, {19, 597}, {327, 598}, {464, 599}, {39, 600}, {278, 601}, {234, 602}, {131, 603}, {569, 604}, {466, 605}, {354, 606}, {160, 607}, {466, 608}, {283, 609}, {39, 610}, {321, 611}, {440, 612}, {280, 613}, {142, 614}, {9, 615}, {411, 616}, {519, 617}, {317, 618}, {278, 619}, {412, 620}, {352, 621}, {96, 622}, {540, 623}, {1, 624}, {370, 625}, {274, 626}, {277, 627}, {30, 628}, {79, 629}, {134, 630}, {435, 631}, {21, 632}, {437, 633}, {285, 634}, {461, 635}, {122, 636}, {137, 637}, {550, 638}, {399, 639}, {490, 640}, {405, 641}, {358, 642}, {205, 643}, {352, 644}, {544, 645}, {319, 646}, {412, 647}, {554, 648}, {561, 649}, {100, 650}, {361, 651}, {130, 652}, {151, 653}, {547, 654}, {543, 655}, {230, 656}, {34, 657}, {240, 658}, {533, 659}, {220, 660}, {551, 661}, {635, 662}, {298, 663}, {510, 664}, {32, 665}, {56, 666}, {271, 667}, {386, 668}, {328, 669}, {511, 670}, {648, 671}, {213, 672}, {640, 673}, {620, 674}, {292, 675}, {612, 676}, {231, 677}, {519, 678}, {218, 679}, {158, 680}, {284, 681}, {149, 682}, {180, 683}, {465, 684}, {101, 685}, {97, 686}, {592, 687}, {577, 688}, {501, 689}, {130, 690}, {574, 691}, {483, 692}, {617, 693}, {461, 694}, {308, 695}, {614, 696}, {90, 697}, {362, 698}, {313, 699}, {301, 700}, {562, 701}, {41, 702}, {627, 703}, {408, 704}, {476, 705}, {161, 706}, {282, 707}, {481, 708}, {209, 709}, {576, 710}, {437, 711}, {10, 712}, {548, 713}, {256, 714}, {498, 715}, {129, 716}, {664, 717}, {70, 718}, {185, 719}, {629, 720}, {108, 721}, {360, 722}, {503, 723}, {105, 724}, {213, 725}, {177, 726}, {46, 727}, {104, 728}, {398, 729}, {209, 730}, {89, 731}, {499, 732}, {368, 733}, {680, 734}, {362, 735}, {534, 736}, {443, 737}, {562, 738}, {74, 739}, {353, 740}, {165, 741}, {108, 742}, {438, 743}, {131, 744}, {140, 745}, {37, 746}, {28, 747}, {698, 748}, {523, 749}, {113, 750}, {430, 751}, {695, 752}, {670, 753}, {546, 754}, {366, 755}, {369, 756}, {602, 757}, {415, 758}, {291, 759}, {352, 760}, {560, 761}, {569, 762}, {681, 763}, {55, 764}, {381, 765}, {324, 766}, {740, 767}, {308, 768}, {728, 769}, {374, 770}, {118, 771}, {97, 772}, {646, 773}, {6, 774}, {626, 775}, {444, 776}, {252, 777}, {391, 778}, {503, 779}, {760, 780}, {451, 781}, {728, 782}, {553, 783}, {410, 784}, {487, 785}, {343, 786}, {350, 787}, {579, 788}, {3, 789}, {706, 790}, {213, 791}, {212, 792}, {792, 793}, {99, 794}, {534, 795}, {63, 796}, {167, 797}, {109, 798}, {692, 799}, {597, 800}, {742, 801}, {407, 802}, {256, 803}, {442, 804}, {587, 805}, {313, 806}, {652, 807}, {602, 808}, {665, 809}, {330, 810}, {508, 811}, {683, 812}, {598, 813}, {661, 814}, {709, 815}, {594, 816}, {337, 817}, {219, 818}, {113, 819}, {306, 820}, {651, 821}, {352, 822}, {742, 823}, {37, 824}, {464, 825}, {452, 826}, {165, 827}, {774, 828}, {17, 829}, {280, 830}, {511, 831}, {542, 832}, {439, 833}, {581, 834}, {687, 835}, {758, 836}, {618, 837}, {378, 838}, {697, 839}, {769, 840}, {702, 841}, {606, 842}, {105, 843}, {663, 844}, {157, 845}, {441, 846}, {348, 847}, {676, 848}, {775, 849}, {446, 850}, {722, 851}, {572, 852}, {191, 853}, {765, 854}, {710, 855}, {569, 856}, {134, 857}, {596, 858}, {304, 859}, {20, 860}, {812, 861}, {606, 862}, {689, 863}, {402, 864}, {275, 865}, {367, 866}, {638, 867}, {618, 868}, {231, 869}, {367, 870}, {255, 871}, {740, 872}, {232, 873}, {571, 874}, {668, 875}, {72, 876}, {483, 877}, {599, 878}, {631, 879}, {420, 880}, {352, 881}, {289, 882}, {720, 883}, {556, 884}, {430, 885}, {410, 886}, {728, 887}, {412, 888}, {682, 889}, {839, 890}, {59, 891}, {233, 892}, {272, 893}, {688, 894}, {431, 895}, {310, 896}, {407, 897}, {567, 898}, {743, 899}, {811, 900}, {808, 901}, {246, 902}, {236, 903}, {895, 904}, {657, 905}, {393, 906}, {143, 907}, {442, 908}, {898, 909}, {72, 910}, {282, 911}, {901, 912}, {624, 913}, {697, 914}, {484, 915}, {582, 916}, {4, 917}, {186, 918}, {426, 919}, {753, 920}, {513, 921}, {504, 922}, {821, 923}, {549, 924}, {415, 925}, {634, 926}, {505, 927}, {590, 928}, {866, 929}, {267, 930}, {236, 931}, {343, 932}, {693, 933}, {116, 934}, {543, 935}, {463, 936}, {880, 937}, {126, 938}, {832, 939}, {205, 940}, {33, 941}, {284, 942}, {941, 943}, {940, 944}, {943, 945}, {784, 946}, {785, 947}, {498, 948}, {898, 949}, {715, 950}, {238, 951}, {389, 952}, {951, 953}, {511, 954}, {767, 955}, {332, 956}, {300, 957}, {298, 958}, {317, 959}, {221, 960}, {253, 961}, {438, 962}, {751, 963}, {492, 964}, {384, 965}, {274, 966}, {820, 967}, {376, 968}, {159, 969}, {766, 970}, {909, 971}, {669, 972}, {8, 973}, {957, 974}, {539, 975}, {844, 976}, {470, 977}, {80, 978}, {641, 979}, {172, 980}, {962, 981}, {756, 982}, {195, 983}, {131, 984}, {216, 985}, {503, 986}, {330, 987}, {863, 988}, {446, 989}, {673, 990}, {760, 991}, {871, 992}, {903, 993}, {47, 994}, {810, 995}, {736, 996}, {749, 997}, {951, 998}, {348, 999}, {741, 1000}, {448, 1001}, {809, 1002}, {704, 1003}, {702, 1004}, {113, 1005}, {392, 1006}, {216, 1007}, {58, 1008}, {348, 1009}, {170, 1010}, {695, 1011}, {168, 1012}, {752, 1013}, {168, 1014}, {376, 1015}, {856, 1016}, {302, 1017}, {278, 1018}, {554, 1019}, {844, 1020}, {368, 1021}, {555, 1022}, {283, 1023}, {220, 1024}, {907, 1025}, {356, 1026}, {415, 1027}, {977, 1028}, {433, 1029}, {741, 1030}, {702, 1031}, {202, 1032}, {420, 1033}, {773, 1034}, {929, 1035}, {1020, 1036}, {752, 1037}, {846, 1038}, {909, 1039}, {137, 1040}, {752, 1041}, {728, 1042}, {295, 1043}, {998, 1044}, {52, 1045}, {825, 1046}, {727, 1047}, {871, 1048}, {941, 1049}, {342, 1050}, {579, 1051}, {424, 1052}, {756, 1053}, {50, 1054}, {587, 1055}, {447, 1056}, {1042, 1057}, {171, 1058}, {322, 1059}, {1049, 1060}, {189, 1061}, {384, 1062}, {403, 1063}, {468, 1064}, {666, 1065}, {282, 1066}, {271, 1067}, {407, 1068}, {323, 1069}, {52, 1070}, {571, 1071}, {46, 1072}, {412, 1073}, {616, 1074}, {417, 1075}, {1042, 1076}, {657, 1077}, {940, 1078}, {498, 1079}, {597, 1080}, {95, 1081}, {12, 1082}, {541, 1083}, {519, 1084}, {463, 1085}, {848, 1086}, {1000, 1087}, {788, 1088}, {337, 1089}, {1001, 1090}, {267, 1091}, {378, 1092}, {234, 1093}, {907, 1094}, {826, 1095}, {31, 1096}, {188, 1097}, {502, 1098}, {826, 1099}, {948, 1100}, {879, 1101}, {388, 1102}, {34, 1103}, {461, 1104}, {568, 1105}, {79, 1106}, {319, 1107}, {364, 1108}, {190, 1109}, {605, 1110}, {717, 1111}, {622, 1112}, {385, 1113}, {25, 1114}, {835, 1115}, {1033, 1116}, {1085, 1117}, {240, 1118}, {199, 1119}, {693, 1120}, {68, 1121}, {478, 1122}, {95, 1123}, {842, 1124}, {1109, 1125}, {678, 1126}, {104, 1127}, {918, 1128}, {414, 1129}, {768, 1130}, {421, 1131}, {825, 1132}, {636, 1133}, {290, 1134}, {1083, 1135}, {473, 1136}, {616, 1137}, {1094, 1138}, {28, 1139}, {137, 1140}, {590, 1141}, {654, 1142}, {1140, 1143}, {789, 1144}, {670, 1145}, {475, 1146}, {176, 1147}, {27, 1148}, {1106, 1149}, {430, 1150}, {192, 1151}, {869, 1152}, {546, 1153}, {955, 1154}, {493, 1155}, {643, 1156}, {663, 1157}, {702, 1158}, {823, 1159}, {1022, 1160}, {228, 1161}, {578, 1162}, {655, 1163}, {611, 1164}, {650, 1165}, {1093, 1166}, {1052, 1167}, {966, 1168}, {1095, 1169}, {93, 1170}, {632, 1171}, {875, 1172}, {254, 1173}, {629, 1174}, {55, 1175}, {1134, 1176}, {765, 1177}, {210, 1178}, {388, 1179}, {323, 1180}, {479, 1181}, {160, 1182}, {1174, 1183}, {489, 1184}, {62, 1185}, {875, 1186}, {584, 1187}, {56, 1188}, {1175, 1189}, {592, 1190}, {669, 1191}, {330, 1192}, {876, 1193}, {134, 1194}, {43, 1195}, {1035, 1196}, {760, 1197}, {680, 1198}, {367, 1199}, {409, 1200}, {339, 1201}, {772, 1202}, {1120, 1203}, {347, 1204}, {426, 1205}, {384, 1206}, {1079, 1207}, {454, 1208}, {313, 1209}, {245, 1210}, {61, 1211}, {874, 1212}, {885, 1213}, {702, 1214}, {327, 1215}, {452, 1216}, {1160, 1217}, {1173, 1218}, {872, 1219}, {905, 1220}, {752, 1221}, {918, 1222}, {624, 1223}, {1023, 1224}, {288, 1225}, {479, 1226}, {982, 1227}, {1103, 1228}, {1113, 1229}, {695, 1230}, {760, 1231}, {789, 1232}, {592, 1233}, {902, 1234}, {1164, 1235}, {113, 1236}, {1098, 1237}, {229, 1238}, {99, 1239}, {697, 1240}, {320, 1241}, {464, 1242}, {727, 1243}, {761, 1244}, {307, 1245}, {1215, 1246}, {990, 1247}, {859, 1248}, {598, 1249}, {998, 1250}, {156, 1251}, {489, 1252}, {815, 1253}, {1003, 1254}, {535, 1255}, {1008, 1256}, {246, 1257}, {808, 1258}, {569, 1259}, {148, 1260}, {326, 1261}, {40, 1262}, {68, 1263}, {880, 1264}, {391, 1265}, {189, 1266}, {1035, 1267}, {193, 1268}, {338, 1269}, {77, 1270}, {496, 1271}, {322, 1272}, {1050, 1273}, {801, 1274}, {1211, 1275}, {134, 1276}, {968, 1277}, {296, 1278}, {930, 1279}, {657, 1280}, {890, 1281}, {85, 1282}, {1007, 1283}, {1194, 1284}, {80, 1285}, {1191, 1286}, {178, 1287}, {1162, 1288}, {289, 1289}, {1099, 1290}, {666, 1291}, {291, 1292}, {435, 1293}, {6, 1294}, {1060, 1295}, {219, 1296}, {1216, 1297}, {1282, 1298}, {636, 1299}, {960, 1300}, {558, 1301}, {885, 1302}, {603, 1303}, {1261, 1304}, {728, 1305}, {915, 1306}, {818, 1307}, {943, 1308}, {260, 1309}, {1004, 1310}, {325, 1311}, {875, 1312}} );
	for (auto vertex : minHeightTrees)
		cout << vertex << " ";
	cout << endl;

	return 0;
}