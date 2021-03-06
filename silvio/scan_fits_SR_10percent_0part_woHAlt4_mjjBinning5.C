void scan_fits_SR_10percent_0part_woHAlt4_mjjBinning5()
{
//=========Macro generated from canvas: c1/
//=========  (Tue May 14 09:28:12 2019) by ROOT version6.02/05
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
   Double_t xAxis12[27] = {40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92}; 
   Double_t yAxis12[20] = {220, 225, 230, 235, 240, 245, 250, 255, 260, 265, 270, 275, 280, 285, 290, 295, 300, 305, 310, 315}; 
   
   TH2F *chi2_profile = new TH2F("chi2_profile","",26, xAxis12,19, yAxis12);
   chi2_profile->SetBinContent(41,2.106743e-26);
   chi2_profile->SetBinContent(42,1.633431e-16);
   chi2_profile->SetBinContent(43,4.283829e-12);
   chi2_profile->SetBinContent(44,2.035169e-11);
   chi2_profile->SetBinContent(45,1.703436e-16);
   chi2_profile->SetBinContent(46,2.21841e-23);
   chi2_profile->SetBinContent(47,1.732136e-32);
   chi2_profile->SetBinContent(68,8.446649e-36);
   chi2_profile->SetBinContent(69,8.325436e-24);
   chi2_profile->SetBinContent(70,7.115583e-15);
   chi2_profile->SetBinContent(71,2.713659e-09);
   chi2_profile->SetBinContent(72,2.906017e-06);
   chi2_profile->SetBinContent(73,2.679167e-08);
   chi2_profile->SetBinContent(74,4.437966e-12);
   chi2_profile->SetBinContent(75,1.406436e-17);
   chi2_profile->SetBinContent(76,6.197443e-30);
   chi2_profile->SetBinContent(96,8.238892e-33);
   chi2_profile->SetBinContent(97,4.032749e-22);
   chi2_profile->SetBinContent(98,5.59348e-14);
   chi2_profile->SetBinContent(99,6.09943e-08);
   chi2_profile->SetBinContent(100,0.0001440266);
   chi2_profile->SetBinContent(101,0.0003908296);
   chi2_profile->SetBinContent(102,2.921272e-06);
   chi2_profile->SetBinContent(103,5.042751e-09);
   chi2_profile->SetBinContent(104,5.240544e-17);
   chi2_profile->SetBinContent(105,1.043207e-28);
   chi2_profile->SetBinContent(123,6.501041e-38);
   chi2_profile->SetBinContent(124,9.380783e-28);
   chi2_profile->SetBinContent(125,7.85644e-19);
   chi2_profile->SetBinContent(126,7.184113e-12);
   chi2_profile->SetBinContent(127,6.725771e-07);
   chi2_profile->SetBinContent(128,0.0008177593);
   chi2_profile->SetBinContent(129,0.02402661);
   chi2_profile->SetBinContent(130,0.001666883);
   chi2_profile->SetBinContent(131,0.0001368931);
   chi2_profile->SetBinContent(132,2.274397e-09);
   chi2_profile->SetBinContent(133,8.212644e-17);
   chi2_profile->SetBinContent(134,1.149496e-26);
   chi2_profile->SetBinContent(150,1.200525e-37);
   chi2_profile->SetBinContent(151,1.196161e-28);
   chi2_profile->SetBinContent(152,5.963854e-21);
   chi2_profile->SetBinContent(153,3.389643e-14);
   chi2_profile->SetBinContent(154,5.5456e-09);
   chi2_profile->SetBinContent(155,1.233523e-05);
   chi2_profile->SetBinContent(156,0.005425603);
   chi2_profile->SetBinContent(157,0.1250588);
   chi2_profile->SetBinContent(158,0.05068077);
   chi2_profile->SetBinContent(159,0.01881179);
   chi2_profile->SetBinContent(160,4.516299e-05);
   chi2_profile->SetBinContent(161,1.220756e-09);
   chi2_profile->SetBinContent(162,1.398266e-15);
   chi2_profile->SetBinContent(163,5.578314e-26);
   chi2_profile->SetBinContent(177,1.567185e-32);
   chi2_profile->SetBinContent(178,1.653842e-25);
   chi2_profile->SetBinContent(179,2.424689e-19);
   chi2_profile->SetBinContent(180,6.70209e-15);
   chi2_profile->SetBinContent(181,1.36227e-10);
   chi2_profile->SetBinContent(182,2.753181e-07);
   chi2_profile->SetBinContent(183,0.0001654825);
   chi2_profile->SetBinContent(184,0.02444227);
   chi2_profile->SetBinContent(185,0.3443001);
   chi2_profile->SetBinContent(186,0.2995395);
   chi2_profile->SetBinContent(187,0.2724484);
   chi2_profile->SetBinContent(188,0.01766227);
   chi2_profile->SetBinContent(189,4.303596e-05);
   chi2_profile->SetBinContent(190,1.786026e-08);
   chi2_profile->SetBinContent(191,1.599376e-15);
   chi2_profile->SetBinContent(192,6.705111e-25);
   chi2_profile->SetBinContent(193,9.029757e-37);
   chi2_profile->SetBinContent(203,9.585838e-38);
   chi2_profile->SetBinContent(204,1.570648e-29);
   chi2_profile->SetBinContent(205,4.805776e-23);
   chi2_profile->SetBinContent(206,1.224402e-17);
   chi2_profile->SetBinContent(207,1.06859e-13);
   chi2_profile->SetBinContent(208,1.750986e-10);
   chi2_profile->SetBinContent(209,1.812476e-07);
   chi2_profile->SetBinContent(210,4.014539e-05);
   chi2_profile->SetBinContent(211,0.003401581);
   chi2_profile->SetBinContent(212,0.1536701);
   chi2_profile->SetBinContent(213,0.6702886);
   chi2_profile->SetBinContent(214,0.9688089);
   chi2_profile->SetBinContent(215,1.449113);
   chi2_profile->SetBinContent(216,0.7112468);
   chi2_profile->SetBinContent(217,0.01831201);
   chi2_profile->SetBinContent(218,0.0002123936);
   chi2_profile->SetBinContent(219,7.09231e-09);
   chi2_profile->SetBinContent(220,4.903116e-15);
   chi2_profile->SetBinContent(221,3.902097e-23);
   chi2_profile->SetBinContent(222,1.087906e-34);
   chi2_profile->SetBinContent(230,2.318678e-32);
   chi2_profile->SetBinContent(231,2.720343e-25);
   chi2_profile->SetBinContent(232,1.043898e-19);
   chi2_profile->SetBinContent(233,3.324901e-15);
   chi2_profile->SetBinContent(234,2.849622e-11);
   chi2_profile->SetBinContent(235,6.590671e-09);
   chi2_profile->SetBinContent(236,7.296462e-07);
   chi2_profile->SetBinContent(237,9.554464e-05);
   chi2_profile->SetBinContent(238,0.002792576);
   chi2_profile->SetBinContent(239,0.06056542);
   chi2_profile->SetBinContent(240,0.4956498);
   chi2_profile->SetBinContent(241,1.275948);
   chi2_profile->SetBinContent(242,1.754251);
   chi2_profile->SetBinContent(243,3.446105);
   chi2_profile->SetBinContent(244,3.533922);
   chi2_profile->SetBinContent(245,0.4865005);
   chi2_profile->SetBinContent(246,0.01066045);
   chi2_profile->SetBinContent(247,0.0001029501);
   chi2_profile->SetBinContent(248,1.718895e-08);
   chi2_profile->SetBinContent(249,4.669129e-14);
   chi2_profile->SetBinContent(250,7.243977e-22);
   chi2_profile->SetBinContent(256,1.95495e-35);
   chi2_profile->SetBinContent(257,4.545913e-25);
   chi2_profile->SetBinContent(258,4.746834e-19);
   chi2_profile->SetBinContent(259,1.346883e-14);
   chi2_profile->SetBinContent(260,6.324524e-11);
   chi2_profile->SetBinContent(261,4.26076e-08);
   chi2_profile->SetBinContent(262,6.588145e-06);
   chi2_profile->SetBinContent(263,0.000139106);
   chi2_profile->SetBinContent(264,0.001734412);
   chi2_profile->SetBinContent(265,0.02476877);
   chi2_profile->SetBinContent(266,0.170047);
   chi2_profile->SetBinContent(267,0.608096);
   chi2_profile->SetBinContent(268,1.177843);
   chi2_profile->SetBinContent(269,1.768259);
   chi2_profile->SetBinContent(270,2.771666);
   chi2_profile->SetBinContent(271,5.967142);
   chi2_profile->SetBinContent(272,7.015901);
   chi2_profile->SetBinContent(273,5.253479);
   chi2_profile->SetBinContent(274,0.6668186);
   chi2_profile->SetBinContent(275,0.03631677);
   chi2_profile->SetBinContent(276,0.0002496485);
   chi2_profile->SetBinContent(277,6.146502e-08);
   chi2_profile->SetBinContent(278,3.783342e-13);
   chi2_profile->SetBinContent(283,5.261139e-33);
   chi2_profile->SetBinContent(284,3.577498e-23);
   chi2_profile->SetBinContent(285,2.917477e-17);
   chi2_profile->SetBinContent(286,3.936111e-13);
   chi2_profile->SetBinContent(287,9.084741e-10);
   chi2_profile->SetBinContent(288,1.757232e-07);
   chi2_profile->SetBinContent(289,2.735038e-05);
   chi2_profile->SetBinContent(290,0.0006840399);
   chi2_profile->SetBinContent(291,0.005306626);
   chi2_profile->SetBinContent(292,0.05713554);
   chi2_profile->SetBinContent(293,0.3318624);
   chi2_profile->SetBinContent(294,0.9248657);
   chi2_profile->SetBinContent(295,1.644588);
   chi2_profile->SetBinContent(296,2.133273);
   chi2_profile->SetBinContent(297,2.358552);
   chi2_profile->SetBinContent(298,3.777761);
   chi2_profile->SetBinContent(299,8.200095);
   chi2_profile->SetBinContent(300,9.955157);
   chi2_profile->SetBinContent(301,19.76772);
   chi2_profile->SetBinContent(302,11.84655);
   chi2_profile->SetBinContent(303,1.75893);
   chi2_profile->SetBinContent(304,0.08165038);
   chi2_profile->SetBinContent(305,0.0002225629);
   chi2_profile->SetBinContent(306,3.30652e-08);
   chi2_profile->SetBinContent(311,4.476212e-22);
   chi2_profile->SetBinContent(312,1.73301e-16);
   chi2_profile->SetBinContent(313,5.482875e-12);
   chi2_profile->SetBinContent(314,5.802728e-09);
   chi2_profile->SetBinContent(315,1.408824e-06);
   chi2_profile->SetBinContent(316,6.341686e-05);
   chi2_profile->SetBinContent(317,0.002161747);
   chi2_profile->SetBinContent(318,0.0200785);
   chi2_profile->SetBinContent(319,0.08706291);
   chi2_profile->SetBinContent(320,0.5322113);
   chi2_profile->SetBinContent(321,1.778502);
   chi2_profile->SetBinContent(322,1.857625);
   chi2_profile->SetBinContent(323,2.206553);
   chi2_profile->SetBinContent(324,2.797949);
   chi2_profile->SetBinContent(325,2.995057);
   chi2_profile->SetBinContent(326,4.567399);
   chi2_profile->SetBinContent(327,9.426413);
   chi2_profile->SetBinContent(328,11.14346);
   chi2_profile->SetBinContent(329,27.14122);
   chi2_profile->SetBinContent(330,29.32393);
   chi2_profile->SetBinContent(331,5.025351);
   chi2_profile->SetBinContent(332,0.599806);
   chi2_profile->SetBinContent(333,0.03093122);
   chi2_profile->SetBinContent(334,5.93538e-05);
   chi2_profile->SetBinContent(338,7.691059e-34);
   chi2_profile->SetBinContent(339,3.252588e-14);
   chi2_profile->SetBinContent(340,5.140693e-10);
   chi2_profile->SetBinContent(341,8.594296e-07);
   chi2_profile->SetBinContent(342,7.903996e-05);
   chi2_profile->SetBinContent(343,0.002293197);
   chi2_profile->SetBinContent(344,0.02063674);
   chi2_profile->SetBinContent(345,0.1692327);
   chi2_profile->SetBinContent(346,0.5245963);
   chi2_profile->SetBinContent(347,1.094247);
   chi2_profile->SetBinContent(348,3.445319);
   chi2_profile->SetBinContent(349,5.176689);
   chi2_profile->SetBinContent(350,4.00889);
   chi2_profile->SetBinContent(351,4.363183);
   chi2_profile->SetBinContent(352,5.10663);
   chi2_profile->SetBinContent(353,5.35568);
   chi2_profile->SetBinContent(354,7.427545);
   chi2_profile->SetBinContent(355,13.51242);
   chi2_profile->SetBinContent(356,14.33927);
   chi2_profile->SetBinContent(357,32.40554);
   chi2_profile->SetBinContent(358,48.08022);
   chi2_profile->SetBinContent(359,15.41075);
   chi2_profile->SetBinContent(360,2.802351);
   chi2_profile->SetBinContent(361,0.6166074);
   chi2_profile->SetBinContent(362,0.008232975);
   chi2_profile->SetBinContent(366,2.014329e-20);
   chi2_profile->SetBinContent(367,2.25442e-07);
   chi2_profile->SetBinContent(368,0.0001081323);
   chi2_profile->SetBinContent(369,0.003754005);
   chi2_profile->SetBinContent(370,0.04671039);
   chi2_profile->SetBinContent(371,0.2994693);
   chi2_profile->SetBinContent(372,0.6129946);
   chi2_profile->SetBinContent(373,1.776812);
   chi2_profile->SetBinContent(374,1.716537);
   chi2_profile->SetBinContent(375,3.156146);
   chi2_profile->SetBinContent(376,7.25772);
   chi2_profile->SetBinContent(377,10.70105);
   chi2_profile->SetBinContent(378,7.691556);
   chi2_profile->SetBinContent(379,7.874834);
   chi2_profile->SetBinContent(380,9.145175);
   chi2_profile->SetBinContent(381,9.109976);
   chi2_profile->SetBinContent(382,11.77671);
   chi2_profile->SetBinContent(383,19.00603);
   chi2_profile->SetBinContent(384,20.04214);
   chi2_profile->SetBinContent(385,37.67554);
   chi2_profile->SetBinContent(386,60.32117);
   chi2_profile->SetBinContent(387,55.99284);
   chi2_profile->SetBinContent(388,20.71085);
   chi2_profile->SetBinContent(389,3.772808);
   chi2_profile->SetBinContent(390,0.1573032);
   chi2_profile->SetBinContent(393,1.364909e-24);
   chi2_profile->SetBinContent(394,1.31001e-11);
   chi2_profile->SetBinContent(395,0.00180048);
   chi2_profile->SetBinContent(396,0.06403811);
   chi2_profile->SetBinContent(397,0.4852429);
   chi2_profile->SetBinContent(398,0.9988422);
   chi2_profile->SetBinContent(399,1.802343);
   chi2_profile->SetBinContent(400,2.365739);
   chi2_profile->SetBinContent(401,5.325709);
   chi2_profile->SetBinContent(402,4.468104);
   chi2_profile->SetBinContent(403,7.177158);
   chi2_profile->SetBinContent(404,14.33004);
   chi2_profile->SetBinContent(405,17.09474);
   chi2_profile->SetBinContent(406,11.47959);
   chi2_profile->SetBinContent(407,11.02991);
   chi2_profile->SetBinContent(408,12.52295);
   chi2_profile->SetBinContent(409,11.42698);
   chi2_profile->SetBinContent(410,13.65885);
   chi2_profile->SetBinContent(411,19.8104);
   chi2_profile->SetBinContent(412,18.9123);
   chi2_profile->SetBinContent(413,33.73422);
   chi2_profile->SetBinContent(414,60.46178);
   chi2_profile->SetBinContent(415,76.26334);
   chi2_profile->SetBinContent(416,42.26523);
   chi2_profile->SetBinContent(417,19.88282);
   chi2_profile->SetBinContent(418,2.756567);
   chi2_profile->SetBinContent(421,3.177252e-15);
   chi2_profile->SetBinContent(422,1.410937e-06);
   chi2_profile->SetBinContent(423,0.04693392);
   chi2_profile->SetBinContent(424,0.4177557);
   chi2_profile->SetBinContent(425,1.357259);
   chi2_profile->SetBinContent(426,2.634912);
   chi2_profile->SetBinContent(427,5.846353);
   chi2_profile->SetBinContent(428,7.747639);
   chi2_profile->SetBinContent(429,12.75622);
   chi2_profile->SetBinContent(430,10.29584);
   chi2_profile->SetBinContent(431,13.21434);
   chi2_profile->SetBinContent(432,25.73404);
   chi2_profile->SetBinContent(433,29.25432);
   chi2_profile->SetBinContent(434,21.35501);
   chi2_profile->SetBinContent(435,19.84776);
   chi2_profile->SetBinContent(436,19.6517);
   chi2_profile->SetBinContent(437,17.41533);
   chi2_profile->SetBinContent(438,20.59786);
   chi2_profile->SetBinContent(439,27.13294);
   chi2_profile->SetBinContent(440,23.7723);
   chi2_profile->SetBinContent(441,37.44812);
   chi2_profile->SetBinContent(442,62.81571);
   chi2_profile->SetBinContent(443,84.15845);
   chi2_profile->SetBinContent(444,67.03235);
   chi2_profile->SetBinContent(445,39.98308);
   chi2_profile->SetBinContent(446,11.84941);
   chi2_profile->SetBinContent(449,1.041897e-08);
   chi2_profile->SetBinContent(450,0.0006368318);
   chi2_profile->SetBinContent(451,0.3744487);
   chi2_profile->SetBinContent(452,0.9946029);
   chi2_profile->SetBinContent(453,2.18989);
   chi2_profile->SetBinContent(454,3.505838);
   chi2_profile->SetBinContent(455,7.376365);
   chi2_profile->SetBinContent(456,12.95201);
   chi2_profile->SetBinContent(457,24.76028);
   chi2_profile->SetBinContent(458,19.55362);
   chi2_profile->SetBinContent(459,23.78985);
   chi2_profile->SetBinContent(460,43.82898);
   chi2_profile->SetBinContent(461,45.52306);
   chi2_profile->SetBinContent(462,35.61316);
   chi2_profile->SetBinContent(463,30.5904);
   chi2_profile->SetBinContent(464,29.68526);
   chi2_profile->SetBinContent(465,26.13928);
   chi2_profile->SetBinContent(466,28.27106);
   chi2_profile->SetBinContent(467,35.42735);
   chi2_profile->SetBinContent(468,28.22698);
   chi2_profile->SetBinContent(469,39.7499);
   chi2_profile->SetBinContent(470,60.06947);
   chi2_profile->SetBinContent(471,85.50607);
   chi2_profile->SetBinContent(472,95.9399);
   chi2_profile->SetBinContent(473,67.41381);
   chi2_profile->SetBinContent(474,30.99686);
   chi2_profile->SetBinContent(477,9.860201e-05);
   chi2_profile->SetBinContent(478,0.04184489);
   chi2_profile->SetBinContent(479,2.254095);
   chi2_profile->SetBinContent(480,3.732519);
   chi2_profile->SetBinContent(481,5.215201);
   chi2_profile->SetBinContent(482,8.862531);
   chi2_profile->SetBinContent(483,15.22255);
   chi2_profile->SetBinContent(484,23.07265);
   chi2_profile->SetBinContent(485,37.14568);
   chi2_profile->SetBinContent(486,31.04008);
   chi2_profile->SetBinContent(487,35.45661);
   chi2_profile->SetBinContent(488,54.21627);
   chi2_profile->SetBinContent(489,55.27266);
   chi2_profile->SetBinContent(490,44.07655);
   chi2_profile->SetBinContent(491,39.43081);
   chi2_profile->SetBinContent(492,39.66082);
   chi2_profile->SetBinContent(493,33.77824);
   chi2_profile->SetBinContent(494,36.26033);
   chi2_profile->SetBinContent(495,39.72702);
   chi2_profile->SetBinContent(496,30.55982);
   chi2_profile->SetBinContent(497,42.03127);
   chi2_profile->SetBinContent(498,58.35818);
   chi2_profile->SetBinContent(499,74.56331);
   chi2_profile->SetBinContent(500,92.37956);
   chi2_profile->SetBinContent(501,89.15252);
   chi2_profile->SetBinContent(502,59.05193);
   chi2_profile->SetBinContent(505,0.006712021);
   chi2_profile->SetBinContent(506,0.3930252);
   chi2_profile->SetBinContent(507,5.543293);
   chi2_profile->SetBinContent(508,6.098193);
   chi2_profile->SetBinContent(509,7.993694);
   chi2_profile->SetBinContent(510,13.26742);
   chi2_profile->SetBinContent(511,27.44776);
   chi2_profile->SetBinContent(512,34.00738);
   chi2_profile->SetBinContent(513,55.62661);
   chi2_profile->SetBinContent(514,47.83413);
   chi2_profile->SetBinContent(515,64.63104);
   chi2_profile->SetBinContent(516,75.2802);
   chi2_profile->SetBinContent(517,76.83324);
   chi2_profile->SetBinContent(518,75.57676);
   chi2_profile->SetBinContent(519,72.73473);
   chi2_profile->SetBinContent(520,69.6863);
   chi2_profile->SetBinContent(521,62.55509);
   chi2_profile->SetBinContent(522,71.53851);
   chi2_profile->SetBinContent(523,73.42635);
   chi2_profile->SetBinContent(524,65.80389);
   chi2_profile->SetBinContent(525,75.44368);
   chi2_profile->SetBinContent(526,89.18369);
   chi2_profile->SetBinContent(527,94.97253);
   chi2_profile->SetBinContent(528,99.20206);
   chi2_profile->SetBinContent(529,92.31812);
   chi2_profile->SetBinContent(530,69.92493);
   chi2_profile->SetBinContent(533,0.04959695);
   chi2_profile->SetBinContent(534,1.658723);
   chi2_profile->SetBinContent(535,13.76924);
   chi2_profile->SetBinContent(536,16.87822);
   chi2_profile->SetBinContent(537,19.49852);
   chi2_profile->SetBinContent(538,22.85315);
   chi2_profile->SetBinContent(539,37.41156);
   chi2_profile->SetBinContent(540,43.02778);
   chi2_profile->SetBinContent(541,65.19566);
   chi2_profile->SetBinContent(542,67.80876);
   chi2_profile->SetBinContent(543,76.76261);
   chi2_profile->SetBinContent(544,85.91961);
   chi2_profile->SetBinContent(545,86.16715);
   chi2_profile->SetBinContent(546,86.85761);
   chi2_profile->SetBinContent(547,87.36756);
   chi2_profile->SetBinContent(548,84.08453);
   chi2_profile->SetBinContent(549,78.28085);
   chi2_profile->SetBinContent(550,83.21516);
   chi2_profile->SetBinContent(551,84.17527);
   chi2_profile->SetBinContent(552,76.54715);
   chi2_profile->SetBinContent(553,81.42184);
   chi2_profile->SetBinContent(554,91.64024);
   chi2_profile->SetBinContent(555,93.33874);
   chi2_profile->SetBinContent(556,97.10048);
   chi2_profile->SetBinContent(557,97.75338);
   chi2_profile->SetBinContent(558,84.65473);
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
