void scan_fits_flippedEta_fullDataAlt6_mjjBinning5()
{
//=========Macro generated from canvas: c1/
//=========  (Fri May 24 16:06:43 2019) by ROOT version6.02/05
   TCanvas *c1 = new TCanvas("c1", "",1,1,700,476);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(31.22078,203.961,98.75325,327.3377);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLeftMargin(0.13);
   c1->SetBottomMargin(0.13);
   c1->SetFrameBorderMode(0);
   Double_t xAxis6[27] = {40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92}; 
   Double_t yAxis6[20] = {220, 225, 230, 235, 240, 245, 250, 255, 260, 265, 270, 275, 280, 285, 290, 295, 300, 305, 310, 315}; 
   
   TH2F *chi2_profile = new TH2F("chi2_profile","",26, xAxis6,19, yAxis6);
   chi2_profile->SetBinContent(110,5.068495e-38);
   chi2_profile->SetBinContent(125,1.673397e-30);
   chi2_profile->SetBinContent(126,9.358468e-26);
   chi2_profile->SetBinContent(127,3.423855e-25);
   chi2_profile->SetBinContent(128,1.452757e-31);
   chi2_profile->SetBinContent(129,1.614878e-27);
   chi2_profile->SetBinContent(130,1.579102e-28);
   chi2_profile->SetBinContent(131,2.743469e-31);
   chi2_profile->SetBinContent(132,3.422186e-34);
   chi2_profile->SetBinContent(133,7.201536e-37);
   chi2_profile->SetBinContent(137,7.457272e-37);
   chi2_profile->SetBinContent(138,8.817948e-35);
   chi2_profile->SetBinContent(151,5.874208e-38);
   chi2_profile->SetBinContent(152,5.158453e-30);
   chi2_profile->SetBinContent(153,3.389979e-22);
   chi2_profile->SetBinContent(154,7.271041e-16);
   chi2_profile->SetBinContent(155,2.541487e-13);
   chi2_profile->SetBinContent(156,4.716606e-17);
   chi2_profile->SetBinContent(157,5.989267e-21);
   chi2_profile->SetBinContent(158,2.505344e-28);
   chi2_profile->SetBinContent(159,6.140818e-22);
   chi2_profile->SetBinContent(160,2.736597e-25);
   chi2_profile->SetBinContent(161,1.1029e-27);
   chi2_profile->SetBinContent(162,1.523064e-29);
   chi2_profile->SetBinContent(163,4.783427e-30);
   chi2_profile->SetBinContent(164,2.310046e-31);
   chi2_profile->SetBinContent(165,4.680463e-31);
   chi2_profile->SetBinContent(166,2.746304e-31);
   chi2_profile->SetBinContent(174,1.216797e-37);
   chi2_profile->SetBinContent(175,3.894947e-30);
   chi2_profile->SetBinContent(177,8.172087e-23);
   chi2_profile->SetBinContent(178,9.185787e-38);
   chi2_profile->SetBinContent(179,1.459733e-17);
   chi2_profile->SetBinContent(180,7.283899e-23);
   chi2_profile->SetBinContent(181,3.170321e-17);
   chi2_profile->SetBinContent(182,3.451654e-12);
   chi2_profile->SetBinContent(183,8.067141e-08);
   chi2_profile->SetBinContent(184,3.92678e-09);
   chi2_profile->SetBinContent(185,2.542314e-11);
   chi2_profile->SetBinContent(186,1.7474e-17);
   chi2_profile->SetBinContent(187,1.122226e-25);
   chi2_profile->SetBinContent(188,7.09312e-18);
   chi2_profile->SetBinContent(189,9.732393e-20);
   chi2_profile->SetBinContent(190,2.351376e-21);
   chi2_profile->SetBinContent(191,1.961232e-22);
   chi2_profile->SetBinContent(192,3.692739e-25);
   chi2_profile->SetBinContent(193,1.29839e-26);
   chi2_profile->SetBinContent(194,3.564584e-27);
   chi2_profile->SetBinContent(200,2.00897e-35);
   chi2_profile->SetBinContent(201,1.542961e-26);
   chi2_profile->SetBinContent(202,9.502901e-22);
   chi2_profile->SetBinContent(203,7.148271e-21);
   chi2_profile->SetBinContent(205,5.907093e-33);
   chi2_profile->SetBinContent(206,7.910147e-14);
   chi2_profile->SetBinContent(207,5.185807e-21);
   chi2_profile->SetBinContent(208,6.172481e-16);
   chi2_profile->SetBinContent(209,5.747129e-12);
   chi2_profile->SetBinContent(210,1.408958e-08);
   chi2_profile->SetBinContent(211,1.954874e-05);
   chi2_profile->SetBinContent(212,3.475495e-05);
   chi2_profile->SetBinContent(213,1.228008e-06);
   chi2_profile->SetBinContent(214,5.81467e-11);
   chi2_profile->SetBinContent(215,6.110954e-17);
   chi2_profile->SetBinContent(216,1.326137e-12);
   chi2_profile->SetBinContent(217,5.904671e-14);
   chi2_profile->SetBinContent(218,1.695224e-15);
   chi2_profile->SetBinContent(219,9.554194e-18);
   chi2_profile->SetBinContent(220,1.813399e-20);
   chi2_profile->SetBinContent(221,5.545766e-22);
   chi2_profile->SetBinContent(222,3.894938e-24);
   chi2_profile->SetBinContent(227,1.13282e-25);
   chi2_profile->SetBinContent(229,2.128079e-17);
   chi2_profile->SetBinContent(230,5.242442e-15);
   chi2_profile->SetBinContent(231,8.187037e-35);
   chi2_profile->SetBinContent(232,4.992557e-28);
   chi2_profile->SetBinContent(233,1.55764e-22);
   chi2_profile->SetBinContent(234,2.038523e-17);
   chi2_profile->SetBinContent(235,7.89683e-13);
   chi2_profile->SetBinContent(236,1.465558e-09);
   chi2_profile->SetBinContent(237,2.406108e-07);
   chi2_profile->SetBinContent(238,1.626978e-05);
   chi2_profile->SetBinContent(239,0.001239427);
   chi2_profile->SetBinContent(240,0.01884861);
   chi2_profile->SetBinContent(241,0.001184681);
   chi2_profile->SetBinContent(242,3.015349e-05);
   chi2_profile->SetBinContent(243,1.197217e-10);
   chi2_profile->SetBinContent(244,6.960663e-17);
   chi2_profile->SetBinContent(245,5.557514e-24);
   chi2_profile->SetBinContent(246,2.915632e-11);
   chi2_profile->SetBinContent(247,1.006817e-13);
   chi2_profile->SetBinContent(248,2.168626e-16);
   chi2_profile->SetBinContent(249,1.080987e-18);
   chi2_profile->SetBinContent(250,4.694397e-21);
   chi2_profile->SetBinContent(255,2.906511e-17);
   chi2_profile->SetBinContent(256,8.484352e-14);
   chi2_profile->SetBinContent(257,7.955667e-36);
   chi2_profile->SetBinContent(258,3.432127e-28);
   chi2_profile->SetBinContent(259,5.748444e-22);
   chi2_profile->SetBinContent(260,3.192801e-17);
   chi2_profile->SetBinContent(261,3.364058e-13);
   chi2_profile->SetBinContent(262,8.206478e-10);
   chi2_profile->SetBinContent(263,4.450629e-07);
   chi2_profile->SetBinContent(264,4.252874e-05);
   chi2_profile->SetBinContent(265,0.001136458);
   chi2_profile->SetBinContent(266,0.006457571);
   chi2_profile->SetBinContent(267,0.0302975);
   chi2_profile->SetBinContent(268,0.1467925);
   chi2_profile->SetBinContent(269,0.1702866);
   chi2_profile->SetBinContent(270,0.002952918);
   chi2_profile->SetBinContent(271,6.109871e-06);
   chi2_profile->SetBinContent(272,3.954387e-10);
   chi2_profile->SetBinContent(273,5.812011e-15);
   chi2_profile->SetBinContent(274,1.138792e-21);
   chi2_profile->SetBinContent(275,6.15517e-31);
   chi2_profile->SetBinContent(276,2.70344e-13);
   chi2_profile->SetBinContent(277,1.904919e-15);
   chi2_profile->SetBinContent(278,1.141886e-17);
   chi2_profile->SetBinContent(282,1.590071e-19);
   chi2_profile->SetBinContent(283,4.421932e-37);
   chi2_profile->SetBinContent(284,5.501478e-29);
   chi2_profile->SetBinContent(285,6.126402e-22);
   chi2_profile->SetBinContent(286,2.67576e-16);
   chi2_profile->SetBinContent(287,1.487944e-11);
   chi2_profile->SetBinContent(288,1.037262e-08);
   chi2_profile->SetBinContent(289,2.743565e-06);
   chi2_profile->SetBinContent(290,0.0002021575);
   chi2_profile->SetBinContent(291,0.006765702);
   chi2_profile->SetBinContent(292,0.06603128);
   chi2_profile->SetBinContent(293,0.2850278);
   chi2_profile->SetBinContent(294,0.7703876);
   chi2_profile->SetBinContent(295,1.194926);
   chi2_profile->SetBinContent(296,1.285053);
   chi2_profile->SetBinContent(297,1.732462);
   chi2_profile->SetBinContent(298,0.1404183);
   chi2_profile->SetBinContent(299,0.002616547);
   chi2_profile->SetBinContent(300,3.758338e-06);
   chi2_profile->SetBinContent(301,1.361197e-09);
   chi2_profile->SetBinContent(302,5.311686e-15);
   chi2_profile->SetBinContent(303,7.069592e-09);
   chi2_profile->SetBinContent(304,9.560678e-11);
   chi2_profile->SetBinContent(305,1.180399e-12);
   chi2_profile->SetBinContent(306,1.100169e-14);
   chi2_profile->SetBinContent(309,1.514692e-29);
   chi2_profile->SetBinContent(311,5.639758e-20);
   chi2_profile->SetBinContent(312,2.770035e-13);
   chi2_profile->SetBinContent(313,0.005528102);
   chi2_profile->SetBinContent(314,1.367003e-05);
   chi2_profile->SetBinContent(315,0.000947732);
   chi2_profile->SetBinContent(316,0.02672519);
   chi2_profile->SetBinContent(317,0.2980744);
   chi2_profile->SetBinContent(318,1.121544);
   chi2_profile->SetBinContent(319,3.665602);
   chi2_profile->SetBinContent(320,6.729325);
   chi2_profile->SetBinContent(321,11.24854);
   chi2_profile->SetBinContent(322,12.72106);
   chi2_profile->SetBinContent(323,13.71029);
   chi2_profile->SetBinContent(324,9.150605);
   chi2_profile->SetBinContent(325,6.310967);
   chi2_profile->SetBinContent(326,1.487449);
   chi2_profile->SetBinContent(327,0.07390997);
   chi2_profile->SetBinContent(328,0.0009835036);
   chi2_profile->SetBinContent(329,2.674727e-06);
   chi2_profile->SetBinContent(330,5.729969e-10);
   chi2_profile->SetBinContent(331,7.636068e-15);
   chi2_profile->SetBinContent(332,6.487442e-20);
   chi2_profile->SetBinContent(333,7.501887e-27);
   chi2_profile->SetBinContent(334,1.176355e-34);
   chi2_profile->SetBinContent(337,1.692157e-20);
   chi2_profile->SetBinContent(338,6.993807e-08);
   chi2_profile->SetBinContent(339,1.559821e-10);
   chi2_profile->SetBinContent(340,4.390308e-08);
   chi2_profile->SetBinContent(341,4.72956e-06);
   chi2_profile->SetBinContent(342,0.0003075765);
   chi2_profile->SetBinContent(343,0.00938342);
   chi2_profile->SetBinContent(344,0.1816441);
   chi2_profile->SetBinContent(345,0.8783169);
   chi2_profile->SetBinContent(346,4.333996);
   chi2_profile->SetBinContent(347,15.797);
   chi2_profile->SetBinContent(348,35.12094);
   chi2_profile->SetBinContent(349,34.36315);
   chi2_profile->SetBinContent(350,30.9104);
   chi2_profile->SetBinContent(351,29.63149);
   chi2_profile->SetBinContent(352,21.96797);
   chi2_profile->SetBinContent(353,13.87825);
   chi2_profile->SetBinContent(354,5.185208);
   chi2_profile->SetBinContent(355,1.308524);
   chi2_profile->SetBinContent(356,0.07108304);
   chi2_profile->SetBinContent(357,0.001291426);
   chi2_profile->SetBinContent(358,2.454861e-06);
   chi2_profile->SetBinContent(359,1.232841e-09);
   chi2_profile->SetBinContent(360,2.318256e-06);
   chi2_profile->SetBinContent(361,1.325485e-07);
   chi2_profile->SetBinContent(362,4.613671e-25);
   chi2_profile->SetBinContent(365,7.780523e-15);
   chi2_profile->SetBinContent(366,3.977164e-15);
   chi2_profile->SetBinContent(367,1.188819e-07);
   chi2_profile->SetBinContent(368,1.39992e-05);
   chi2_profile->SetBinContent(369,0.0004271377);
   chi2_profile->SetBinContent(370,0.008848945);
   chi2_profile->SetBinContent(371,0.1206996);
   chi2_profile->SetBinContent(372,0.7470071);
   chi2_profile->SetBinContent(373,2.697039);
   chi2_profile->SetBinContent(374,8.501795);
   chi2_profile->SetBinContent(375,24.15241);
   chi2_profile->SetBinContent(376,48.26312);
   chi2_profile->SetBinContent(377,71.92319);
   chi2_profile->SetBinContent(378,70.3287);
   chi2_profile->SetBinContent(379,72.60607);
   chi2_profile->SetBinContent(380,59.43874);
   chi2_profile->SetBinContent(381,43.50295);
   chi2_profile->SetBinContent(382,20.13399);
   chi2_profile->SetBinContent(383,6.482916);
   chi2_profile->SetBinContent(384,0.8922752);
   chi2_profile->SetBinContent(385,0.04400067);
   chi2_profile->SetBinContent(386,0.0005335298);
   chi2_profile->SetBinContent(387,2.315374e-06);
   chi2_profile->SetBinContent(388,2.198837e-09);
   chi2_profile->SetBinContent(389,1.056908e-13);
   chi2_profile->SetBinContent(390,4.557695e-07);
   chi2_profile->SetBinContent(393,3.873626e-20);
   chi2_profile->SetBinContent(394,7.200682e-09);
   chi2_profile->SetBinContent(395,2.308498e-05);
   chi2_profile->SetBinContent(396,0.000649909);
   chi2_profile->SetBinContent(397,0.0062063);
   chi2_profile->SetBinContent(398,0.04967592);
   chi2_profile->SetBinContent(399,0.3349461);
   chi2_profile->SetBinContent(400,1.626541);
   chi2_profile->SetBinContent(401,4.801451);
   chi2_profile->SetBinContent(402,11.07818);
   chi2_profile->SetBinContent(403,25.29178);
   chi2_profile->SetBinContent(404,47.08752);
   chi2_profile->SetBinContent(405,83.14414);
   chi2_profile->SetBinContent(406,86.50117);
   chi2_profile->SetBinContent(407,86.83962);
   chi2_profile->SetBinContent(408,76.76147);
   chi2_profile->SetBinContent(409,60.9842);
   chi2_profile->SetBinContent(410,44.12746);
   chi2_profile->SetBinContent(411,24.24869);
   chi2_profile->SetBinContent(412,6.768606);
   chi2_profile->SetBinContent(413,0.8467382);
   chi2_profile->SetBinContent(414,0.05701151);
   chi2_profile->SetBinContent(415,0.001040653);
   chi2_profile->SetBinContent(416,5.087275e-06);
   chi2_profile->SetBinContent(417,3.991036e-09);
   chi2_profile->SetBinContent(418,7.401108e-13);
   chi2_profile->SetBinContent(421,1.51065e-09);
   chi2_profile->SetBinContent(422,3.611205e-06);
   chi2_profile->SetBinContent(423,0.0005471571);
   chi2_profile->SetBinContent(424,0.004686321);
   chi2_profile->SetBinContent(425,0.02632902);
   chi2_profile->SetBinContent(426,0.1255325);
   chi2_profile->SetBinContent(427,0.4549206);
   chi2_profile->SetBinContent(428,1.631579);
   chi2_profile->SetBinContent(429,4.888774);
   chi2_profile->SetBinContent(430,10.06427);
   chi2_profile->SetBinContent(431,19.4639);
   chi2_profile->SetBinContent(432,32.91557);
   chi2_profile->SetBinContent(433,63.65946);
   chi2_profile->SetBinContent(434,79.9631);
   chi2_profile->SetBinContent(435,82.811);
   chi2_profile->SetBinContent(436,73.85635);
   chi2_profile->SetBinContent(437,66.86791);
   chi2_profile->SetBinContent(438,47.03309);
   chi2_profile->SetBinContent(439,32.71746);
   chi2_profile->SetBinContent(440,20.95871);
   chi2_profile->SetBinContent(441,6.947613);
   chi2_profile->SetBinContent(442,1.067003);
   chi2_profile->SetBinContent(443,0.06389811);
   chi2_profile->SetBinContent(444,0.001573915);
   chi2_profile->SetBinContent(445,9.714761e-06);
   chi2_profile->SetBinContent(446,1.785364e-08);
   chi2_profile->SetBinContent(449,3.219472e-05);
   chi2_profile->SetBinContent(450,0.001657106);
   chi2_profile->SetBinContent(451,0.01409062);
   chi2_profile->SetBinContent(452,0.05252374);
   chi2_profile->SetBinContent(453,0.1780884);
   chi2_profile->SetBinContent(454,0.5560433);
   chi2_profile->SetBinContent(455,1.234961);
   chi2_profile->SetBinContent(456,4.182029);
   chi2_profile->SetBinContent(457,8.93021);
   chi2_profile->SetBinContent(458,15.21079);
   chi2_profile->SetBinContent(459,25.77412);
   chi2_profile->SetBinContent(460,42.15558);
   chi2_profile->SetBinContent(461,71.13327);
   chi2_profile->SetBinContent(462,89.27428);
   chi2_profile->SetBinContent(463,98.59809);
   chi2_profile->SetBinContent(464,97.06808);
   chi2_profile->SetBinContent(465,91.02756);
   chi2_profile->SetBinContent(466,75.30122);
   chi2_profile->SetBinContent(467,60.78729);
   chi2_profile->SetBinContent(468,43.40889);
   chi2_profile->SetBinContent(469,20.17065);
   chi2_profile->SetBinContent(470,6.112082);
   chi2_profile->SetBinContent(471,0.9229285);
   chi2_profile->SetBinContent(472,0.08053659);
   chi2_profile->SetBinContent(473,0.002187814);
   chi2_profile->SetBinContent(474,3.083373e-05);
   chi2_profile->SetBinContent(477,0.001435086);
   chi2_profile->SetBinContent(478,0.02990968);
   chi2_profile->SetBinContent(479,0.04998935);
   chi2_profile->SetBinContent(480,0.125519);
   chi2_profile->SetBinContent(481,0.2833778);
   chi2_profile->SetBinContent(482,0.669917);
   chi2_profile->SetBinContent(483,1.574336);
   chi2_profile->SetBinContent(484,4.474887);
   chi2_profile->SetBinContent(485,8.561578);
   chi2_profile->SetBinContent(486,14.96806);
   chi2_profile->SetBinContent(487,26.57424);
   chi2_profile->SetBinContent(488,42.14951);
   chi2_profile->SetBinContent(489,69.42871);
   chi2_profile->SetBinContent(490,86.51972);
   chi2_profile->SetBinContent(491,96.22664);
   chi2_profile->SetBinContent(492,99.05238);
   chi2_profile->SetBinContent(493,99.58429);
   chi2_profile->SetBinContent(494,97.07137);
   chi2_profile->SetBinContent(495,93.3926);
   chi2_profile->SetBinContent(496,68.76598);
   chi2_profile->SetBinContent(497,41.75156);
   chi2_profile->SetBinContent(498,19.8266);
   chi2_profile->SetBinContent(499,5.906458);
   chi2_profile->SetBinContent(500,1.240582);
   chi2_profile->SetBinContent(501,0.09547823);
   chi2_profile->SetBinContent(502,0.005015849);
   chi2_profile->SetBinContent(505,0.005731589);
   chi2_profile->SetBinContent(506,0.1201712);
   chi2_profile->SetBinContent(507,0.1416681);
   chi2_profile->SetBinContent(508,0.277627);
   chi2_profile->SetBinContent(509,0.5945802);
   chi2_profile->SetBinContent(510,1.181412);
   chi2_profile->SetBinContent(511,2.283848);
   chi2_profile->SetBinContent(512,5.777509);
   chi2_profile->SetBinContent(513,10.22814);
   chi2_profile->SetBinContent(514,15.36177);
   chi2_profile->SetBinContent(515,24.53579);
   chi2_profile->SetBinContent(516,35.7937);
   chi2_profile->SetBinContent(517,59.62156);
   chi2_profile->SetBinContent(518,76.21653);
   chi2_profile->SetBinContent(519,95.9882);
   chi2_profile->SetBinContent(520,95.9443);
   chi2_profile->SetBinContent(521,94.83192);
   chi2_profile->SetBinContent(522,87.52157);
   chi2_profile->SetBinContent(523,91.07486);
   chi2_profile->SetBinContent(524,79.75127);
   chi2_profile->SetBinContent(525,74.52573);
   chi2_profile->SetBinContent(526,51.06772);
   chi2_profile->SetBinContent(527,25.13688);
   chi2_profile->SetBinContent(528,8.870192);
   chi2_profile->SetBinContent(529,1.625145);
   chi2_profile->SetBinContent(530,0.2377915);
   chi2_profile->SetBinContent(533,0.01732282);
   chi2_profile->SetBinContent(534,0.2919264);
   chi2_profile->SetBinContent(535,0.3648099);
   chi2_profile->SetBinContent(536,0.6782253);
   chi2_profile->SetBinContent(537,1.158069);
   chi2_profile->SetBinContent(538,2.207656);
   chi2_profile->SetBinContent(539,4.085835);
   chi2_profile->SetBinContent(540,7.919374);
   chi2_profile->SetBinContent(541,12.13858);
   chi2_profile->SetBinContent(542,15.38522);
   chi2_profile->SetBinContent(543,23.79634);
   chi2_profile->SetBinContent(544,35.03737);
   chi2_profile->SetBinContent(545,57.48802);
   chi2_profile->SetBinContent(546,72.08514);
   chi2_profile->SetBinContent(547,92.31129);
   chi2_profile->SetBinContent(548,98.41299);
   chi2_profile->SetBinContent(549,98.95686);
   chi2_profile->SetBinContent(550,94.59518);
   chi2_profile->SetBinContent(551,95.11804);
   chi2_profile->SetBinContent(552,87.01075);
   chi2_profile->SetBinContent(553,83.48103);
   chi2_profile->SetBinContent(554,74.41746);
   chi2_profile->SetBinContent(555,47.72195);
   chi2_profile->SetBinContent(556,23.38044);
   chi2_profile->SetBinContent(557,7.949717);
   chi2_profile->SetBinContent(558,2.436568);
   chi2_profile->SetMinimum(-1e-09);
   chi2_profile->SetMaximum(50);
   chi2_profile->SetEntries(494);
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
   
   TPaletteAxis *palette = new TPaletteAxis(92.33766,220,95.37662,315,chi2_profile);
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
   chi2_profile->GetXaxis()->SetBinLabel(26,"p_{T,ISR} > 90");
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
