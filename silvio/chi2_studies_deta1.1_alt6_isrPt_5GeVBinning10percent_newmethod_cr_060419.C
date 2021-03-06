void chi2_studies_deta1.1_alt6_isrPt_5GeVBinning10percent_newmethod_cr_060419()
{
//=========Macro generated from canvas: c1/
//=========  (Mon Apr  8 19:54:11 2019) by ROOT version6.02/05
   TCanvas *c1 = new TCanvas("c1", "",1,1,700,476);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(31.55844,203.1169,96.49351,332.987);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.13);
   c1->SetBottomMargin(0.13);
   c1->SetFrameBorderMode(0);
   Double_t xAxis4[26] = {40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90}; 
   Double_t yAxis4[21] = {220, 225, 230, 235, 240, 245, 250, 255, 260, 265, 270, 275, 280, 285, 290, 295, 300, 305, 310, 315, 320}; 
   
   TH2F *chi2_profile = new TH2F("chi2_profile","",25, xAxis4,20, yAxis4);
   chi2_profile->SetBinContent(32,6.073084e-35);
   chi2_profile->SetBinContent(33,1.979823e-27);
   chi2_profile->SetBinContent(34,2.472769e-22);
   chi2_profile->SetBinContent(35,6.945749e-19);
   chi2_profile->SetBinContent(36,4.137339e-16);
   chi2_profile->SetBinContent(37,1.729986e-13);
   chi2_profile->SetBinContent(38,1.31219e-11);
   chi2_profile->SetBinContent(39,7.718819e-16);
   chi2_profile->SetBinContent(40,1.616476e-20);
   chi2_profile->SetBinContent(41,1.41577e-20);
   chi2_profile->SetBinContent(42,1.566668e-22);
   chi2_profile->SetBinContent(43,2.828442e-28);
   chi2_profile->SetBinContent(44,2.980172e-05);
   chi2_profile->SetBinContent(45,3.043577e-05);
   chi2_profile->SetBinContent(46,9.702586e-05);
   chi2_profile->SetBinContent(47,0.0002331824);
   chi2_profile->SetBinContent(48,0.0012071);
   chi2_profile->SetBinContent(49,0.01343975);
   chi2_profile->SetBinContent(50,0.03993765);
   chi2_profile->SetBinContent(51,0.05673788);
   chi2_profile->SetBinContent(52,0.08485325);
   chi2_profile->SetBinContent(53,0.2579227);
   chi2_profile->SetBinContent(57,6.949357e-34);
   chi2_profile->SetBinContent(58,3.408844e-26);
   chi2_profile->SetBinContent(59,6.390613e-21);
   chi2_profile->SetBinContent(60,6.1041e-17);
   chi2_profile->SetBinContent(61,3.119055e-14);
   chi2_profile->SetBinContent(62,3.873815e-12);
   chi2_profile->SetBinContent(63,3.018419e-10);
   chi2_profile->SetBinContent(64,2.301277e-08);
   chi2_profile->SetBinContent(65,9.930466e-07);
   chi2_profile->SetBinContent(66,5.060052e-05);
   chi2_profile->SetBinContent(67,6.648339e-05);
   chi2_profile->SetBinContent(68,0.0001831324);
   chi2_profile->SetBinContent(69,0.000456831);
   chi2_profile->SetBinContent(70,0.002153548);
   chi2_profile->SetBinContent(71,9.631698e-11);
   chi2_profile->SetBinContent(72,0.003471622);
   chi2_profile->SetBinContent(73,0.006623825);
   chi2_profile->SetBinContent(76,0.1160516);
   chi2_profile->SetBinContent(77,0.1625271);
   chi2_profile->SetBinContent(78,0.1128322);
   chi2_profile->SetBinContent(79,0.1737923);
   chi2_profile->SetBinContent(80,0.3316861);
   chi2_profile->SetBinContent(84,1.558965e-20);
   chi2_profile->SetBinContent(85,6.833536e-17);
   chi2_profile->SetBinContent(86,5.403231e-14);
   chi2_profile->SetBinContent(87,1.644674e-11);
   chi2_profile->SetBinContent(88,1.030382e-09);
   chi2_profile->SetBinContent(89,2.987974e-08);
   chi2_profile->SetBinContent(90,8.232379e-07);
   chi2_profile->SetBinContent(91,2.638784e-05);
   chi2_profile->SetBinContent(92,0.0006127332);
   chi2_profile->SetBinContent(93,0.01070355);
   chi2_profile->SetBinContent(94,0.06608964);
   chi2_profile->SetBinContent(95,0.07724819);
   chi2_profile->SetBinContent(96,0.116754);
   chi2_profile->SetBinContent(97,0.04703451);
   chi2_profile->SetBinContent(98,0.003035053);
   chi2_profile->SetBinContent(99,3.881331e-07);
   chi2_profile->SetBinContent(100,1.268028e-12);
   chi2_profile->SetBinContent(101,7.525577e-24);
   chi2_profile->SetBinContent(103,0.3822911);
   chi2_profile->SetBinContent(104,0.4520511);
   chi2_profile->SetBinContent(105,0.3247164);
   chi2_profile->SetBinContent(106,0.4539596);
   chi2_profile->SetBinContent(111,6.45568e-13);
   chi2_profile->SetBinContent(112,6.273404e-11);
   chi2_profile->SetBinContent(113,2.802771e-09);
   chi2_profile->SetBinContent(114,1.009688e-07);
   chi2_profile->SetBinContent(115,1.698994e-06);
   chi2_profile->SetBinContent(116,1.756725e-05);
   chi2_profile->SetBinContent(117,0.000191919);
   chi2_profile->SetBinContent(118,0.001246381);
   chi2_profile->SetBinContent(119,0.02174927);
   chi2_profile->SetBinContent(120,0.1195417);
   chi2_profile->SetBinContent(121,0.7088807);
   chi2_profile->SetBinContent(122,2.690565);
   chi2_profile->SetBinContent(123,3.763629);
   chi2_profile->SetBinContent(124,1.852914);
   chi2_profile->SetBinContent(125,0.4269197);
   chi2_profile->SetBinContent(126,0.04891293);
   chi2_profile->SetBinContent(127,0.0003208893);
   chi2_profile->SetBinContent(128,1.442555);
   chi2_profile->SetBinContent(129,8.97413e-20);
   chi2_profile->SetBinContent(130,8.335088e-34);
   chi2_profile->SetBinContent(132,0.7399436);
   chi2_profile->SetBinContent(138,8.390664e-09);
   chi2_profile->SetBinContent(139,7.725049e-08);
   chi2_profile->SetBinContent(140,7.237823e-07);
   chi2_profile->SetBinContent(141,1.058606e-05);
   chi2_profile->SetBinContent(142,3.981246e-05);
   chi2_profile->SetBinContent(143,0.0003816656);
   chi2_profile->SetBinContent(144,0.003046657);
   chi2_profile->SetBinContent(145,0.01832473);
   chi2_profile->SetBinContent(146,0.2034232);
   chi2_profile->SetBinContent(147,0.8648702);
   chi2_profile->SetBinContent(148,3.135785);
   chi2_profile->SetBinContent(149,10.60756);
   chi2_profile->SetBinContent(150,15.12108);
   chi2_profile->SetBinContent(151,6.666745);
   chi2_profile->SetBinContent(152,1.786004);
   chi2_profile->SetBinContent(153,0.3247976);
   chi2_profile->SetBinContent(154,0.02993275);
   chi2_profile->SetBinContent(155,4.192205e-06);
   chi2_profile->SetBinContent(156,1.700439e-12);
   chi2_profile->SetBinContent(157,4.479606e-23);
   chi2_profile->SetBinContent(158,1.14255);
   chi2_profile->SetBinContent(161,0.8650134);
   chi2_profile->SetBinContent(165,4.316772e-06);
   chi2_profile->SetBinContent(166,1.297014e-05);
   chi2_profile->SetBinContent(167,4.913715e-05);
   chi2_profile->SetBinContent(168,0.0003367126);
   chi2_profile->SetBinContent(169,0.001261548);
   chi2_profile->SetBinContent(170,0.005881473);
   chi2_profile->SetBinContent(171,0.03384744);
   chi2_profile->SetBinContent(172,0.1354692);
   chi2_profile->SetBinContent(173,0.8872018);
   chi2_profile->SetBinContent(174,2.860718);
   chi2_profile->SetBinContent(175,6.908574);
   chi2_profile->SetBinContent(176,20.7238);
   chi2_profile->SetBinContent(177,34.15972);
   chi2_profile->SetBinContent(178,16.48873);
   chi2_profile->SetBinContent(179,6.322404);
   chi2_profile->SetBinContent(180,1.865718);
   chi2_profile->SetBinContent(181,0.3466768);
   chi2_profile->SetBinContent(182,0.007310604);
   chi2_profile->SetBinContent(183,2.025796e-06);
   chi2_profile->SetBinContent(184,7.657393e-14);
   chi2_profile->SetBinContent(185,1.853609);
   chi2_profile->SetBinContent(186,2.867803e-31);
   chi2_profile->SetBinContent(187,1.922895);
   chi2_profile->SetBinContent(188,1.43853);
   chi2_profile->SetBinContent(191,3.257418e-23);
   chi2_profile->SetBinContent(192,0.0001604249);
   chi2_profile->SetBinContent(193,0.0002233702);
   chi2_profile->SetBinContent(194,0.0005660135);
   chi2_profile->SetBinContent(195,0.003412132);
   chi2_profile->SetBinContent(196,0.01253228);
   chi2_profile->SetBinContent(197,0.04897678);
   chi2_profile->SetBinContent(198,0.2672528);
   chi2_profile->SetBinContent(199,1.2428);
   chi2_profile->SetBinContent(200,4.695396);
   chi2_profile->SetBinContent(201,11.74825);
   chi2_profile->SetBinContent(202,24.9663);
   chi2_profile->SetBinContent(203,39.76297);
   chi2_profile->SetBinContent(204,54.9818);
   chi2_profile->SetBinContent(205,30.2021);
   chi2_profile->SetBinContent(206,14.08251);
   chi2_profile->SetBinContent(207,6.103811);
   chi2_profile->SetBinContent(208,1.401478);
   chi2_profile->SetBinContent(209,0.09523623);
   chi2_profile->SetBinContent(210,0.0001481033);
   chi2_profile->SetBinContent(211,1.525912e-10);
   chi2_profile->SetBinContent(212,9.789087e-18);
   chi2_profile->SetBinContent(213,1.126224e-23);
   chi2_profile->SetBinContent(214,1.866583e-36);
   chi2_profile->SetBinContent(215,2.052292);
   chi2_profile->SetBinContent(217,1.48263e-27);
   chi2_profile->SetBinContent(218,7.574029e-06);
   chi2_profile->SetBinContent(219,0.0002572601);
   chi2_profile->SetBinContent(220,0.0003524785);
   chi2_profile->SetBinContent(221,0.01150486);
   chi2_profile->SetBinContent(222,0.06899919);
   chi2_profile->SetBinContent(223,0.2212157);
   chi2_profile->SetBinContent(224,0.5479151);
   chi2_profile->SetBinContent(225,1.982538);
   chi2_profile->SetBinContent(226,6.208096);
   chi2_profile->SetBinContent(227,17.32154);
   chi2_profile->SetBinContent(228,37.50917);
   chi2_profile->SetBinContent(229,52.3653);
   chi2_profile->SetBinContent(230,64.85556);
   chi2_profile->SetBinContent(231,75.02248);
   chi2_profile->SetBinContent(232,52.80378);
   chi2_profile->SetBinContent(233,31.50176);
   chi2_profile->SetBinContent(234,17.8764);
   chi2_profile->SetBinContent(235,6.21526);
   chi2_profile->SetBinContent(236,1.660239);
   chi2_profile->SetBinContent(237,0.1932635);
   chi2_profile->SetBinContent(238,0.0003233406);
   chi2_profile->SetBinContent(239,9.101445e-09);
   chi2_profile->SetBinContent(240,5.11217e-13);
   chi2_profile->SetBinContent(241,5.382414);
   chi2_profile->SetBinContent(242,3.475657e-31);
   chi2_profile->SetBinContent(244,2.859052e-08);
   chi2_profile->SetBinContent(245,0.0001497855);
   chi2_profile->SetBinContent(246,0.0008441114);
   chi2_profile->SetBinContent(247,0.004337741);
   chi2_profile->SetBinContent(248,0.101574);
   chi2_profile->SetBinContent(249,1.98468);
   chi2_profile->SetBinContent(250,4.03632);
   chi2_profile->SetBinContent(251,7.426322);
   chi2_profile->SetBinContent(252,16.17613);
   chi2_profile->SetBinContent(253,28.95411);
   chi2_profile->SetBinContent(254,45.6974);
   chi2_profile->SetBinContent(255,62.20381);
   chi2_profile->SetBinContent(256,75.8442);
   chi2_profile->SetBinContent(257,80.2343);
   chi2_profile->SetBinContent(258,89.84343);
   chi2_profile->SetBinContent(259,75.3596);
   chi2_profile->SetBinContent(260,50.93165);
   chi2_profile->SetBinContent(261,35.68711);
   chi2_profile->SetBinContent(262,14.14358);
   chi2_profile->SetBinContent(263,5.235068);
   chi2_profile->SetBinContent(264,2.086961);
   chi2_profile->SetBinContent(265,0.03515557);
   chi2_profile->SetBinContent(266,5.455418e-05);
   chi2_profile->SetBinContent(267,2.422383e-07);
   chi2_profile->SetBinContent(268,9.74611);
   chi2_profile->SetBinContent(269,1.5245e-20);
   chi2_profile->SetBinContent(271,1.378273e-06);
   chi2_profile->SetBinContent(272,0.0004297883);
   chi2_profile->SetBinContent(273,0.008581417);
   chi2_profile->SetBinContent(274,0.07237854);
   chi2_profile->SetBinContent(275,0.8628935);
   chi2_profile->SetBinContent(276,12.20773);
   chi2_profile->SetBinContent(277,25.82306);
   chi2_profile->SetBinContent(278,34.61296);
   chi2_profile->SetBinContent(279,49.2841);
   chi2_profile->SetBinContent(280,68.11711);
   chi2_profile->SetBinContent(281,74.56777);
   chi2_profile->SetBinContent(282,78.66399);
   chi2_profile->SetBinContent(283,83.3216);
   chi2_profile->SetBinContent(284,88.53775);
   chi2_profile->SetBinContent(285,90.37683);
   chi2_profile->SetBinContent(286,86.06303);
   chi2_profile->SetBinContent(287,78.75242);
   chi2_profile->SetBinContent(288,60.30279);
   chi2_profile->SetBinContent(289,31.33144);
   chi2_profile->SetBinContent(290,15.68945);
   chi2_profile->SetBinContent(291,8.390911);
   chi2_profile->SetBinContent(292,2.301398);
   chi2_profile->SetBinContent(293,0.07222649);
   chi2_profile->SetBinContent(294,0.003354279);
   chi2_profile->SetBinContent(295,1.672381e-06);
   chi2_profile->SetBinContent(296,5.529208e-11);
   chi2_profile->SetBinContent(298,2.356417e-06);
   chi2_profile->SetBinContent(299,0.01535411);
   chi2_profile->SetBinContent(300,1.648467);
   chi2_profile->SetBinContent(301,5.980252);
   chi2_profile->SetBinContent(302,29.23579);
   chi2_profile->SetBinContent(303,62.06769);
   chi2_profile->SetBinContent(304,79.54478);
   chi2_profile->SetBinContent(305,85.0435);
   chi2_profile->SetBinContent(306,89.31366);
   chi2_profile->SetBinContent(307,91.45547);
   chi2_profile->SetBinContent(308,86.15936);
   chi2_profile->SetBinContent(309,85.30437);
   chi2_profile->SetBinContent(310,85.71131);
   chi2_profile->SetBinContent(311,88.33703);
   chi2_profile->SetBinContent(312,89.29796);
   chi2_profile->SetBinContent(313,88.72378);
   chi2_profile->SetBinContent(314,77.94751);
   chi2_profile->SetBinContent(315,70.4864);
   chi2_profile->SetBinContent(316,47.97979);
   chi2_profile->SetBinContent(317,27.12334);
   chi2_profile->SetBinContent(318,17.04827);
   chi2_profile->SetBinContent(319,6.503885);
   chi2_profile->SetBinContent(320,0.834582);
   chi2_profile->SetBinContent(321,0.1671344);
   chi2_profile->SetBinContent(322,0.0007004872);
   chi2_profile->SetBinContent(323,1.853585e-07);
   chi2_profile->SetBinContent(325,7.170122e-06);
   chi2_profile->SetBinContent(326,0.1749936);
   chi2_profile->SetBinContent(327,15.5127);
   chi2_profile->SetBinContent(328,42.59926);
   chi2_profile->SetBinContent(329,66.22359);
   chi2_profile->SetBinContent(330,82.06215);
   chi2_profile->SetBinContent(331,90.61982);
   chi2_profile->SetBinContent(332,88.96215);
   chi2_profile->SetBinContent(333,91.1972);
   chi2_profile->SetBinContent(334,91.0584);
   chi2_profile->SetBinContent(335,85.34742);
   chi2_profile->SetBinContent(336,83.99953);
   chi2_profile->SetBinContent(337,84.28629);
   chi2_profile->SetBinContent(338,87.17377);
   chi2_profile->SetBinContent(339,88.11926);
   chi2_profile->SetBinContent(340,87.74989);
   chi2_profile->SetBinContent(341,77.79623);
   chi2_profile->SetBinContent(342,69.96315);
   chi2_profile->SetBinContent(343,60.55298);
   chi2_profile->SetBinContent(344,42.55664);
   chi2_profile->SetBinContent(345,33.95163);
   chi2_profile->SetBinContent(346,15.24656);
   chi2_profile->SetBinContent(347,6.32963);
   chi2_profile->SetBinContent(348,3.980769);
   chi2_profile->SetBinContent(349,0.1768204);
   chi2_profile->SetBinContent(350,0.001772711);
   chi2_profile->SetBinContent(352,1.787788e-05);
   chi2_profile->SetBinContent(353,0.5064883);
   chi2_profile->SetBinContent(354,26.92293);
   chi2_profile->SetBinContent(355,54.76948);
   chi2_profile->SetBinContent(356,69.75011);
   chi2_profile->SetBinContent(357,84.05764);
   chi2_profile->SetBinContent(358,91.60435);
   chi2_profile->SetBinContent(359,89.56829);
   chi2_profile->SetBinContent(360,90.42091);
   chi2_profile->SetBinContent(361,90.0934);
   chi2_profile->SetBinContent(362,83.8746);
   chi2_profile->SetBinContent(363,82.80326);
   chi2_profile->SetBinContent(364,82.82681);
   chi2_profile->SetBinContent(365,85.91566);
   chi2_profile->SetBinContent(366,86.97462);
   chi2_profile->SetBinContent(367,87.16872);
   chi2_profile->SetBinContent(368,76.74194);
   chi2_profile->SetBinContent(369,69.56815);
   chi2_profile->SetBinContent(370,64.73715);
   chi2_profile->SetBinContent(371,60.60717);
   chi2_profile->SetBinContent(372,52.62119);
   chi2_profile->SetBinContent(373,26.06917);
   chi2_profile->SetBinContent(374,14.84321);
   chi2_profile->SetBinContent(375,11.43012);
   chi2_profile->SetBinContent(376,1.790356);
   chi2_profile->SetBinContent(377,0.147327);
   chi2_profile->SetBinContent(379,0.001656768);
   chi2_profile->SetBinContent(380,3.375002);
   chi2_profile->SetBinContent(381,41.99382);
   chi2_profile->SetBinContent(382,63.16481);
   chi2_profile->SetBinContent(383,71.31545);
   chi2_profile->SetBinContent(384,82.99038);
   chi2_profile->SetBinContent(385,90.61449);
   chi2_profile->SetBinContent(386,88.40945);
   chi2_profile->SetBinContent(387,89.38294);
   chi2_profile->SetBinContent(388,89.14844);
   chi2_profile->SetBinContent(389,82.51328);
   chi2_profile->SetBinContent(390,81.40907);
   chi2_profile->SetBinContent(391,82.97984);
   chi2_profile->SetBinContent(392,85.75742);
   chi2_profile->SetBinContent(393,87.54367);
   chi2_profile->SetBinContent(394,86.87976);
   chi2_profile->SetBinContent(395,80.03998);
   chi2_profile->SetBinContent(396,75.18028);
   chi2_profile->SetBinContent(397,77.78819);
   chi2_profile->SetBinContent(398,73.40253);
   chi2_profile->SetBinContent(399,70.83279);
   chi2_profile->SetBinContent(400,46.10036);
   chi2_profile->SetBinContent(401,28.10756);
   chi2_profile->SetBinContent(402,27.81339);
   chi2_profile->SetBinContent(403,12.60835);
   chi2_profile->SetBinContent(404,1.999912);
   chi2_profile->SetBinContent(406,3.651762);
   chi2_profile->SetBinContent(407,40.41624);
   chi2_profile->SetBinContent(408,61.29101);
   chi2_profile->SetBinContent(409,75.36034);
   chi2_profile->SetBinContent(410,80.85875);
   chi2_profile->SetBinContent(411,88.38683);
   chi2_profile->SetBinContent(412,91.25873);
   chi2_profile->SetBinContent(413,88.14068);
   chi2_profile->SetBinContent(414,88.74223);
   chi2_profile->SetBinContent(415,88.03864);
   chi2_profile->SetBinContent(416,80.86874);
   chi2_profile->SetBinContent(417,80.54249);
   chi2_profile->SetBinContent(418,81.68072);
   chi2_profile->SetBinContent(419,84.87074);
   chi2_profile->SetBinContent(420,86.46761);
   chi2_profile->SetBinContent(421,86.09978);
   chi2_profile->SetBinContent(422,80.14876);
   chi2_profile->SetBinContent(423,76.77879);
   chi2_profile->SetBinContent(424,80.25767);
   chi2_profile->SetBinContent(425,77.25233);
   chi2_profile->SetBinContent(426,82.6655);
   chi2_profile->SetBinContent(427,73.30995);
   chi2_profile->SetBinContent(428,66.66075);
   chi2_profile->SetBinContent(429,49.42917);
   chi2_profile->SetBinContent(430,37.56759);
   chi2_profile->SetBinContent(431,16.23107);
   chi2_profile->SetBinContent(433,11.73211);
   chi2_profile->SetBinContent(434,44.4839);
   chi2_profile->SetBinContent(435,60.27115);
   chi2_profile->SetBinContent(436,70.89574);
   chi2_profile->SetBinContent(437,75.71175);
   chi2_profile->SetBinContent(438,83.14176);
   chi2_profile->SetBinContent(439,91.29299);
   chi2_profile->SetBinContent(440,88.55248);
   chi2_profile->SetBinContent(441,89.21403);
   chi2_profile->SetBinContent(442,88.35307);
   chi2_profile->SetBinContent(443,80.63036);
   chi2_profile->SetBinContent(444,78.89735);
   chi2_profile->SetBinContent(445,80.53209);
   chi2_profile->SetBinContent(446,84.09252);
   chi2_profile->SetBinContent(447,85.86346);
   chi2_profile->SetBinContent(448,84.73294);
   chi2_profile->SetBinContent(449,78.67953);
   chi2_profile->SetBinContent(450,75.35611);
   chi2_profile->SetBinContent(451,79.38074);
   chi2_profile->SetBinContent(452,78.52126);
   chi2_profile->SetBinContent(453,84.50286);
   chi2_profile->SetBinContent(454,82.15083);
   chi2_profile->SetBinContent(455,79.18421);
   chi2_profile->SetBinContent(456,79.79126);
   chi2_profile->SetBinContent(457,54.44936);
   chi2_profile->SetBinContent(458,32.49385);
   chi2_profile->SetBinContent(460,34.4266);
   chi2_profile->SetBinContent(461,59.63591);
   chi2_profile->SetBinContent(462,69.27205);
   chi2_profile->SetBinContent(463,80.63822);
   chi2_profile->SetBinContent(464,85.25288);
   chi2_profile->SetBinContent(465,90.47784);
   chi2_profile->SetBinContent(466,93.80449);
   chi2_profile->SetBinContent(467,90.7605);
   chi2_profile->SetBinContent(468,90.81874);
   chi2_profile->SetBinContent(469,89.04063);
   chi2_profile->SetBinContent(470,81.10804);
   chi2_profile->SetBinContent(471,79.44807);
   chi2_profile->SetBinContent(472,83.03838);
   chi2_profile->SetBinContent(473,85.07794);
   chi2_profile->SetBinContent(474,85.99939);
   chi2_profile->SetBinContent(475,85.22012);
   chi2_profile->SetBinContent(476,77.48567);
   chi2_profile->SetBinContent(477,73.83588);
   chi2_profile->SetBinContent(478,77.58938);
   chi2_profile->SetBinContent(479,76.7296);
   chi2_profile->SetBinContent(480,83.03127);
   chi2_profile->SetBinContent(481,81.05408);
   chi2_profile->SetBinContent(482,79.21309);
   chi2_profile->SetBinContent(483,78.34066);
   chi2_profile->SetBinContent(484,61.6753);
   chi2_profile->SetBinContent(485,45.44744);
   chi2_profile->SetBinContent(487,33.03044);
   chi2_profile->SetBinContent(488,57.90929);
   chi2_profile->SetBinContent(489,67.17107);
   chi2_profile->SetBinContent(490,78.95057);
   chi2_profile->SetBinContent(491,82.62057);
   chi2_profile->SetBinContent(492,89.27599);
   chi2_profile->SetBinContent(493,93.04078);
   chi2_profile->SetBinContent(494,89.73178);
   chi2_profile->SetBinContent(495,89.94198);
   chi2_profile->SetBinContent(496,87.92181);
   chi2_profile->SetBinContent(497,79.46222);
   chi2_profile->SetBinContent(498,77.77622);
   chi2_profile->SetBinContent(499,81.47446);
   chi2_profile->SetBinContent(500,83.78717);
   chi2_profile->SetBinContent(501,84.55779);
   chi2_profile->SetBinContent(502,83.76774);
   chi2_profile->SetBinContent(503,76.75262);
   chi2_profile->SetBinContent(504,73.97742);
   chi2_profile->SetBinContent(505,78.07524);
   chi2_profile->SetBinContent(506,75.80663);
   chi2_profile->SetBinContent(507,81.42349);
   chi2_profile->SetBinContent(508,79.34093);
   chi2_profile->SetBinContent(509,77.75526);
   chi2_profile->SetBinContent(510,80.81185);
   chi2_profile->SetBinContent(511,62.80122);
   chi2_profile->SetBinContent(512,50.33222);
   chi2_profile->SetBinContent(514,39.62619);
   chi2_profile->SetBinContent(515,67.10614);
   chi2_profile->SetBinContent(516,68.57364);
   chi2_profile->SetBinContent(517,80.32699);
   chi2_profile->SetBinContent(518,88.40588);
   chi2_profile->SetBinContent(519,92.4603);
   chi2_profile->SetBinContent(520,94.15938);
   chi2_profile->SetBinContent(521,90.61248);
   chi2_profile->SetBinContent(522,90.25285);
   chi2_profile->SetBinContent(523,88.63727);
   chi2_profile->SetBinContent(524,81.01797);
   chi2_profile->SetBinContent(525,75.93336);
   chi2_profile->SetBinContent(526,82.08031);
   chi2_profile->SetBinContent(527,83.55747);
   chi2_profile->SetBinContent(528,84.74387);
   chi2_profile->SetBinContent(529,82.19485);
   chi2_profile->SetBinContent(530,74.81302);
   chi2_profile->SetBinContent(531,72.01763);
   chi2_profile->SetBinContent(532,76.32612);
   chi2_profile->SetBinContent(533,74.11948);
   chi2_profile->SetBinContent(534,79.72173);
   chi2_profile->SetBinContent(535,78.36716);
   chi2_profile->SetBinContent(536,76.37261);
   chi2_profile->SetBinContent(537,81.56074);
   chi2_profile->SetBinContent(538,65.21487);
   chi2_profile->SetBinContent(539,58.3837);
   chi2_profile->SetBinContent(541,40.23958);
   chi2_profile->SetBinContent(542,53.75811);
   chi2_profile->SetBinContent(543,61.77887);
   chi2_profile->SetBinContent(544,74.51187);
   chi2_profile->SetBinContent(545,79.3128);
   chi2_profile->SetBinContent(546,88.66396);
   chi2_profile->SetBinContent(547,92.82746);
   chi2_profile->SetBinContent(548,90.47711);
   chi2_profile->SetBinContent(549,91.71454);
   chi2_profile->SetBinContent(550,92.34921);
   chi2_profile->SetBinContent(551,86.76073);
   chi2_profile->SetBinContent(552,87.60509);
   chi2_profile->SetBinContent(553,91.06776);
   chi2_profile->SetBinContent(554,92.90054);
   chi2_profile->SetBinContent(555,93.79858);
   chi2_profile->SetBinContent(556,92.99726);
   chi2_profile->SetBinContent(557,88.6219);
   chi2_profile->SetBinContent(558,88.07316);
   chi2_profile->SetBinContent(559,88.94818);
   chi2_profile->SetBinContent(560,87.06847);
   chi2_profile->SetBinContent(561,89.3758);
   chi2_profile->SetBinContent(562,85.95201);
   chi2_profile->SetBinContent(563,87.05151);
   chi2_profile->SetBinContent(564,94.31674);
   chi2_profile->SetBinContent(565,87.14782);
   chi2_profile->SetBinContent(566,86.59836);
   chi2_profile->SetBinContent(568,47.47306);
   chi2_profile->SetBinContent(569,62.49486);
   chi2_profile->SetBinContent(570,66.11959);
   chi2_profile->SetBinContent(571,79.52862);
   chi2_profile->SetBinContent(572,84.57767);
   chi2_profile->SetBinContent(573,92.14594);
   chi2_profile->SetBinContent(574,94.73962);
   chi2_profile->SetBinContent(575,91.3589);
   chi2_profile->SetBinContent(576,91.00547);
   chi2_profile->SetBinContent(577,92.41093);
   chi2_profile->SetBinContent(578,86.13219);
   chi2_profile->SetBinContent(579,84.38245);
   chi2_profile->SetBinContent(580,91.03191);
   chi2_profile->SetBinContent(581,92.41663);
   chi2_profile->SetBinContent(582,93.24499);
   chi2_profile->SetBinContent(583,92.34377);
   chi2_profile->SetBinContent(584,87.55388);
   chi2_profile->SetBinContent(585,86.79762);
   chi2_profile->SetBinContent(586,87.84548);
   chi2_profile->SetBinContent(587,85.98914);
   chi2_profile->SetBinContent(588,88.76675);
   chi2_profile->SetBinContent(589,85.0863);
   chi2_profile->SetBinContent(590,86.06684);
   chi2_profile->SetBinContent(591,93.81329);
   chi2_profile->SetBinContent(592,86.65353);
   chi2_profile->SetBinContent(593,86.17417);
   chi2_profile->SetMinimum(-1e-09);
   chi2_profile->SetMaximum(50);
   chi2_profile->SetEntries(546);
   chi2_profile->SetStats(0);
   chi2_profile->SetContour(20);
   chi2_profile->SetContourLevel(0,-1e-09);
   chi2_profile->SetContourLevel(1,2.5);
   chi2_profile->SetContourLevel(2,5);
   chi2_profile->SetContourLevel(3,7.5);
   chi2_profile->SetContourLevel(4,10);
   chi2_profile->SetContourLevel(5,12.5);
   chi2_profile->SetContourLevel(6,15);
   chi2_profile->SetContourLevel(7,17.5);
   chi2_profile->SetContourLevel(8,20);
   chi2_profile->SetContourLevel(9,22.5);
   chi2_profile->SetContourLevel(10,25);
   chi2_profile->SetContourLevel(11,27.5);
   chi2_profile->SetContourLevel(12,30);
   chi2_profile->SetContourLevel(13,32.5);
   chi2_profile->SetContourLevel(14,35);
   chi2_profile->SetContourLevel(15,37.5);
   chi2_profile->SetContourLevel(16,40);
   chi2_profile->SetContourLevel(17,42.5);
   chi2_profile->SetContourLevel(18,45);
   chi2_profile->SetContourLevel(19,47.5);
   
   TPaletteAxis *palette = new TPaletteAxis(90.32468,220,93.24675,320,chi2_profile);
palette->SetLabelColor(1);
palette->SetLabelFont(42);
palette->SetLabelOffset(0.005);
palette->SetLabelSize(0.035);
palette->SetTitleOffset(1);
palette->SetTitleSize(0.035);
   palette->SetFillColor(100);
   palette->SetFillStyle(1001);
   chi2_profile->GetListOfFunctions()->Add(palette,"br");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   chi2_profile->SetLineColor(ci);
   chi2_profile->GetXaxis()->SetBinLabel(1,"p_{T,ISR} > 40");
   chi2_profile->GetXaxis()->SetBinLabel(2,"p_{T,ISR} > 42");
   chi2_profile->GetXaxis()->SetBinLabel(3,"p_{T,ISR} > 44");
   chi2_profile->GetXaxis()->SetBinLabel(4,"p_{T,ISR} > 46");
   chi2_profile->GetXaxis()->SetBinLabel(5,"p_{T,ISR} > 48");
   chi2_profile->GetXaxis()->SetBinLabel(6,"p_{T,ISR} > 50");
   chi2_profile->GetXaxis()->SetBinLabel(7,"p_{T,ISR} > 52");
   chi2_profile->GetXaxis()->SetBinLabel(8,"p_{T,ISR} > 54");
   chi2_profile->GetXaxis()->SetBinLabel(9,"p_{T,ISR} > 56");
   chi2_profile->GetXaxis()->SetBinLabel(10,"p_{T,ISR} > 58");
   chi2_profile->GetXaxis()->SetBinLabel(11,"p_{T,ISR} > 60");
   chi2_profile->GetXaxis()->SetBinLabel(12,"p_{T,ISR} > 62");
   chi2_profile->GetXaxis()->SetBinLabel(13,"p_{T,ISR} > 64");
   chi2_profile->GetXaxis()->SetBinLabel(14,"p_{T,ISR} > 66");
   chi2_profile->GetXaxis()->SetBinLabel(15,"p_{T,ISR} > 68");
   chi2_profile->GetXaxis()->SetBinLabel(16,"p_{T,ISR} > 70");
   chi2_profile->GetXaxis()->SetBinLabel(17,"p_{T,ISR} > 72");
   chi2_profile->GetXaxis()->SetBinLabel(18,"p_{T,ISR} > 74");
   chi2_profile->GetXaxis()->SetBinLabel(19,"p_{T,ISR} > 76");
   chi2_profile->GetXaxis()->SetBinLabel(20,"p_{T,ISR} > 78");
   chi2_profile->GetXaxis()->SetBinLabel(21,"p_{T,ISR} > 80");
   chi2_profile->GetXaxis()->SetBinLabel(22,"p_{T,ISR} > 82");
   chi2_profile->GetXaxis()->SetBinLabel(23,"p_{T,ISR} > 84");
   chi2_profile->GetXaxis()->SetBinLabel(24,"p_{T,ISR} > 86");
   chi2_profile->GetXaxis()->SetBinLabel(25,"p_{T,ISR} > 88");
   chi2_profile->GetXaxis()->SetBit(TAxis::kLabelsUp);
   chi2_profile->GetXaxis()->SetLabelFont(42);
   chi2_profile->GetXaxis()->SetLabelOffset(0.007);
   chi2_profile->GetXaxis()->SetLabelSize(0.035);
   chi2_profile->GetXaxis()->SetTitleSize(0.035);
   chi2_profile->GetXaxis()->SetTitleOffset(1.4);
   chi2_profile->GetXaxis()->SetTitleFont(42);
   chi2_profile->GetYaxis()->SetBinLabel(1,"220 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(2,"225 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(3,"230 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(4,"235 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(5,"240 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(6,"245 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(7,"250 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(8,"255 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(9,"260 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(10,"265 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(11,"270 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(12,"275 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(13,"280 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(14,"285 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(15,"290 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(16,"295 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(17,"300 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(18,"305 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(19,"310 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetBinLabel(20,"315 < m_{jj} < 1000");
   chi2_profile->GetYaxis()->SetLabelFont(42);
   chi2_profile->GetYaxis()->SetLabelSize(0.035);
   chi2_profile->GetYaxis()->SetTitleSize(0.035);
   chi2_profile->GetYaxis()->SetTitleOffset(1.6);
   chi2_profile->GetYaxis()->SetTitleFont(42);
   chi2_profile->GetZaxis()->SetLabelFont(42);
   chi2_profile->GetZaxis()->SetLabelSize(0.035);
   chi2_profile->GetZaxis()->SetTitleSize(0.035);
   chi2_profile->GetZaxis()->SetTitleFont(42);
   chi2_profile->Draw("COLZ,TEXT");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
