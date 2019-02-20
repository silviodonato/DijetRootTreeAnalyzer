void fit_mjj_Full_CaloTrijet2016()
{
//=========Macro generated from canvas: c/c
//=========  (Mon Jan 21 10:36:53 2019) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",0,0,600,700);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->SetHighLightColor(2);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetTopMargin(0.04761905);
   c->SetBottomMargin(0.05);
   c->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: c_1
   TPad *c_1 = new TPad("c_1", "c_1",0.01,0.37,0.99,0.98);
   c_1->Draw();
   c_1->cd();
   c_1->Range(105.1613,-4.69897,1047.097,4.978449);
   c_1->SetFillColor(0);
   c_1->SetBorderMode(0);
   c_1->SetBorderSize(2);
   c_1->SetLogy();
   c_1->SetTickx(1);
   c_1->SetTicky(1);
   c_1->SetLeftMargin(0.175);
   c_1->SetRightMargin(0.05);
   c_1->SetTopMargin(0.07);
   c_1->SetBottomMargin(0);
   c_1->SetFrameFillStyle(0);
   c_1->SetFrameBorderMode(0);
   c_1->SetFrameFillStyle(0);
   c_1->SetFrameBorderMode(0);
   Double_t xAxis1[19] = {270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000}; 
   
   TH1F *data_obs_density1 = new TH1F("data_obs_density1","Dijet Mass",18, xAxis1);
   data_obs_density1->SetMinimum(2e-05);
   data_obs_density1->SetMaximum(20000);
   data_obs_density1->SetEntries(1.237625e+08);
   data_obs_density1->SetLineColor(0);
   data_obs_density1->SetLineWidth(0);
   data_obs_density1->SetMarkerColor(0);
   data_obs_density1->GetXaxis()->SetRange(1,18);
   data_obs_density1->GetXaxis()->SetLabelFont(42);
   data_obs_density1->GetXaxis()->SetLabelSize(0.035);
   data_obs_density1->GetXaxis()->SetTitleSize(0.035);
   data_obs_density1->GetXaxis()->SetTitleFont(42);
   data_obs_density1->GetYaxis()->SetTitle("d#sigma/dm_{jj} [pb/TeV]");
   data_obs_density1->GetYaxis()->SetLabelFont(42);
   data_obs_density1->GetYaxis()->SetLabelOffset(1000);
   data_obs_density1->GetYaxis()->SetLabelSize(0.05);
   data_obs_density1->GetYaxis()->SetTitleSize(0.07);
   data_obs_density1->GetYaxis()->SetTitleFont(42);
   data_obs_density1->GetZaxis()->SetLabelFont(42);
   data_obs_density1->GetZaxis()->SetLabelSize(0.035);
   data_obs_density1->GetZaxis()->SetTitleSize(0.035);
   data_obs_density1->GetZaxis()->SetTitleFont(42);
   data_obs_density1->Draw("axis");
   
   TF1 *CaloTrijet2016_bkg_unbin1 = new TF1("*CaloTrijet2016_bkg_unbin",270,1000,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet2016_bkg_unbin = new TF1("CaloTrijet2016_bkg_unbin",,270,1000,1);
   CaloTrijet2016_bkg_unbin1->SetRange(270,1000);
   CaloTrijet2016_bkg_unbin1->SetName("CaloTrijet2016_bkg_unbin");
   CaloTrijet2016_bkg_unbin1->SetTitle("");
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(0,617.0933);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(1,597.0345);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(2,573.0606);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(3,546.7559);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(4,519.2674);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(5,491.4185);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(6,463.7927);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(7,436.7962);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(8,410.7035);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(9,385.6924);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(10,361.8694);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(11,339.289);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(12,317.968);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(13,297.8964);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(14,279.0454);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(15,261.3733);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(16,244.8301);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(17,229.3608);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(18,214.9079);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(19,201.4128);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(20,188.8176);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(21,177.0658);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(22,166.1025);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(23,155.8754);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(24,146.3349);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(25,137.434);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(26,129.1283);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(27,121.3765);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(28,114.1396);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(29,107.3815);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(30,101.0685);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(31,95.16913);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(32,89.65424);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(33,84.49677);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(34,79.67159);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(35,75.15541);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(36,70.92664);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(37,66.96527);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(38,63.25277);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(39,59.77195);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(40,56.5069);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(41,53.44288);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(42,50.56621);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(43,47.86424);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(44,45.32523);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(45,42.93827);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(46,40.69327);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(47,38.58086);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(48,36.59234);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(49,34.71963);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(50,32.95522);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(51,31.29215);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(52,29.72392);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(53,28.24453);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(54,26.84835);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(55,25.53016);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(56,24.28511);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(57,23.10867);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(58,21.99662);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(59,20.94502);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(60,19.95021);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(61,19.00876);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(62,18.11748);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(63,17.27337);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(64,16.47365);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(65,15.71572);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(66,14.99713);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(67,14.3156);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(68,13.669);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(69,13.05532);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(70,12.4727);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(71,11.91938);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(72,11.3937);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(73,10.89414);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(74,10.41924);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(75,9.967638);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(76,9.538062);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(77,9.129311);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(78,8.740258);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(79,8.369843);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(80,8.017071);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(81,7.681002);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(82,7.360755);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(83,7.055499);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(84,6.764451);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(85,6.486874);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(86,6.222072);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(87,5.969389);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(88,5.728208);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(89,5.497946);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(90,5.27805);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(91,5.068002);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(92,4.867311);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(93,4.675511);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(94,4.492165);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(95,4.316858);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(96,4.149198);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(97,3.988813);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(98,3.835352);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(99,3.688484);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(100,3.547892);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(101,270);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(102,1000);
   CaloTrijet2016_bkg_unbin1->SetFillColor(19);
   CaloTrijet2016_bkg_unbin1->SetFillStyle(0);
   CaloTrijet2016_bkg_unbin1->SetLineColor(2);
   CaloTrijet2016_bkg_unbin1->SetLineWidth(2);
   CaloTrijet2016_bkg_unbin1->GetXaxis()->SetLabelFont(42);
   CaloTrijet2016_bkg_unbin1->GetXaxis()->SetLabelSize(0.035);
   CaloTrijet2016_bkg_unbin1->GetXaxis()->SetTitleSize(0.035);
   CaloTrijet2016_bkg_unbin1->GetXaxis()->SetTitleFont(42);
   CaloTrijet2016_bkg_unbin1->GetYaxis()->SetLabelFont(42);
   CaloTrijet2016_bkg_unbin1->GetYaxis()->SetLabelSize(0.035);
   CaloTrijet2016_bkg_unbin1->GetYaxis()->SetTitleSize(0.035);
   CaloTrijet2016_bkg_unbin1->GetYaxis()->SetTitleFont(42);
   CaloTrijet2016_bkg_unbin1->SetParameter(0,9.326059e-06);
   CaloTrijet2016_bkg_unbin1->SetParError(0,0);
   CaloTrijet2016_bkg_unbin1->SetParLimits(0,0,0);
   CaloTrijet2016_bkg_unbin1->Draw("csame");
   TLatex *   tex = new TLatex(0.7,0.94,"0 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.22,0.85,"CMS");
tex->SetNDC();
   tex->SetTextSize(0.065);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.58,0.55,0.87,0.87,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph_from_data_obs_rebin","Data","pe");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.9);
   entry->SetTextFont(42);
   entry=leg->AddEntry("CaloTrijet2016_bkg_unbin","Fit","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2,0.03,0.5,0.22,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextAlign(11);
   pt->SetTextFont(42);
   pt->SetTextSize(0.045);
   AText = pt->AddText("#chi^{2} / NDF = 27.3 / 14 = 1.9");
   AText = pt->AddText("Wide Calo-jets");
   AText = pt->AddText("0.27 < m_{jj} < 1.00 TeV");
   AText = pt->AddText("|#eta| < 2.5, |#Delta#eta| < 1.1");
   pt->Draw();
   
   TF1 *CaloTrijet2016_bkg_unbin2 = new TF1("*CaloTrijet2016_bkg_unbin",270,1000,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet2016_bkg_unbin = new TF1("CaloTrijet2016_bkg_unbin",,270,1000,1);
   CaloTrijet2016_bkg_unbin2->SetRange(270,1000);
   CaloTrijet2016_bkg_unbin2->SetName("CaloTrijet2016_bkg_unbin");
   CaloTrijet2016_bkg_unbin2->SetTitle("");
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(0,617.0933);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(1,597.0345);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(2,573.0606);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(3,546.7559);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(4,519.2674);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(5,491.4185);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(6,463.7927);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(7,436.7962);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(8,410.7035);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(9,385.6924);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(10,361.8694);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(11,339.289);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(12,317.968);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(13,297.8964);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(14,279.0454);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(15,261.3733);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(16,244.8301);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(17,229.3608);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(18,214.9079);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(19,201.4128);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(20,188.8176);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(21,177.0658);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(22,166.1025);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(23,155.8754);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(24,146.3349);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(25,137.434);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(26,129.1283);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(27,121.3765);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(28,114.1396);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(29,107.3815);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(30,101.0685);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(31,95.16913);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(32,89.65424);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(33,84.49677);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(34,79.67159);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(35,75.15541);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(36,70.92664);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(37,66.96527);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(38,63.25277);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(39,59.77195);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(40,56.5069);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(41,53.44288);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(42,50.56621);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(43,47.86424);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(44,45.32523);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(45,42.93827);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(46,40.69327);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(47,38.58086);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(48,36.59234);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(49,34.71963);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(50,32.95522);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(51,31.29215);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(52,29.72392);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(53,28.24453);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(54,26.84835);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(55,25.53016);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(56,24.28511);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(57,23.10867);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(58,21.99662);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(59,20.94502);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(60,19.95021);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(61,19.00876);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(62,18.11748);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(63,17.27337);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(64,16.47365);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(65,15.71572);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(66,14.99713);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(67,14.3156);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(68,13.669);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(69,13.05532);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(70,12.4727);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(71,11.91938);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(72,11.3937);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(73,10.89414);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(74,10.41924);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(75,9.967638);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(76,9.538062);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(77,9.129311);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(78,8.740258);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(79,8.369843);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(80,8.017071);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(81,7.681002);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(82,7.360755);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(83,7.055499);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(84,6.764451);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(85,6.486874);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(86,6.222072);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(87,5.969389);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(88,5.728208);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(89,5.497946);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(90,5.27805);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(91,5.068002);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(92,4.867311);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(93,4.675511);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(94,4.492165);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(95,4.316858);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(96,4.149198);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(97,3.988813);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(98,3.835352);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(99,3.688484);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(100,3.547892);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(101,270);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(102,1000);
   CaloTrijet2016_bkg_unbin2->SetFillColor(19);
   CaloTrijet2016_bkg_unbin2->SetFillStyle(0);
   CaloTrijet2016_bkg_unbin2->SetLineColor(2);
   CaloTrijet2016_bkg_unbin2->SetLineWidth(2);
   CaloTrijet2016_bkg_unbin2->GetXaxis()->SetLabelFont(42);
   CaloTrijet2016_bkg_unbin2->GetXaxis()->SetLabelSize(0.035);
   CaloTrijet2016_bkg_unbin2->GetXaxis()->SetTitleSize(0.035);
   CaloTrijet2016_bkg_unbin2->GetXaxis()->SetTitleFont(42);
   CaloTrijet2016_bkg_unbin2->GetYaxis()->SetLabelFont(42);
   CaloTrijet2016_bkg_unbin2->GetYaxis()->SetLabelSize(0.035);
   CaloTrijet2016_bkg_unbin2->GetYaxis()->SetTitleSize(0.035);
   CaloTrijet2016_bkg_unbin2->GetYaxis()->SetTitleFont(42);
   CaloTrijet2016_bkg_unbin2->SetParameter(0,9.326059e-06);
   CaloTrijet2016_bkg_unbin2->SetParError(0,0);
   CaloTrijet2016_bkg_unbin2->SetParLimits(0,0,0);
   CaloTrijet2016_bkg_unbin2->Draw("csame");
   
   Double_t g_data_clone_fx3001[18] = {
   283,
   310.5,
   339.5,
   370,
   402.5,
   436,
   471,
   507.5,
   545.5,
   585.5,
   627.5,
   671,
   716.5,
   764,
   813,
   864,
   917,
   972};
   Double_t g_data_clone_fy3001[18] = {
   577.0381,
   476.8166,
   373.8143,
   285.4472,
   213.5628,
   159.1555,
   117.9024,
   87.28998,
   64.53556,
   47.49125,
   34.96103,
   25.72205,
   18.8925,
   13.94982,
   10.26437,
   7.597441,
   5.620666,
   4.140356};
   Double_t g_data_clone_felx3001[18] = {
   13,
   14.5,
   14.5,
   16,
   16.5,
   17,
   18,
   18.5,
   19.5,
   20.5,
   21.5,
   22,
   23.5,
   24,
   25,
   26,
   27,
   28};
   Double_t g_data_clone_fely3001[18] = {
   0.1511873,
   0.1301297,
   0.1152202,
   0.09584902,
   0.0816405,
   0.06943385,
   0.05807775,
   0.04929253,
   0.0412826,
   0.03453939,
   0.02893728,
   0.02453727,
   0.02034677,
   0.01730069,
   0.01454055,
   0.01226681,
   0.01035372,
   0.008726183};
   Double_t g_data_clone_fehx3001[18] = {
   13,
   14.5,
   14.5,
   16,
   16.5,
   17,
   18,
   18.5,
   19.5,
   20.5,
   21.5,
   22,
   23.5,
   24,
   25,
   26,
   27,
   28};
   Double_t g_data_clone_fehy3001[18] = {
   0.1512269,
   0.1301652,
   0.1152558,
   0.09588121,
   0.08167171,
   0.06946414,
   0.05810637,
   0.04932037,
   0.04130901,
   0.03456452,
   0.02896124,
   0.02456069,
   0.0203687,
   0.01732215,
   0.01456116,
   0.01228663,
   0.01037281,
   0.008744593};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(18,g_data_clone_fx3001,g_data_clone_fy3001,g_data_clone_felx3001,g_data_clone_fehx3001,g_data_clone_fely3001,g_data_clone_fehy3001);
   grae->SetName("g_data_clone");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_g_data_clone3001 = new TH1F("Graph_g_data_clone3001","Dijet Mass",100,197,1073);
   Graph_g_data_clone3001->SetMinimum(3.718467);
   Graph_g_data_clone3001->SetMaximum(634.4951);
   Graph_g_data_clone3001->SetDirectory(0);
   Graph_g_data_clone3001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_g_data_clone3001->SetLineColor(ci);
   Graph_g_data_clone3001->GetXaxis()->SetLabelFont(42);
   Graph_g_data_clone3001->GetXaxis()->SetLabelSize(0.035);
   Graph_g_data_clone3001->GetXaxis()->SetTitleSize(0.035);
   Graph_g_data_clone3001->GetXaxis()->SetTitleFont(42);
   Graph_g_data_clone3001->GetYaxis()->SetLabelFont(42);
   Graph_g_data_clone3001->GetYaxis()->SetLabelSize(0.035);
   Graph_g_data_clone3001->GetYaxis()->SetTitleSize(0.035);
   Graph_g_data_clone3001->GetYaxis()->SetTitleFont(42);
   Graph_g_data_clone3001->GetZaxis()->SetLabelFont(42);
   Graph_g_data_clone3001->GetZaxis()->SetLabelSize(0.035);
   Graph_g_data_clone3001->GetZaxis()->SetTitleSize(0.035);
   Graph_g_data_clone3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_g_data_clone3001);
   
   grae->Draw("zp");
   
   Double_t Graph_from_data_obs_rebin_fx3002[18] = {
   283,
   310.5,
   339.5,
   370,
   402.5,
   436,
   471,
   507.5,
   545.5,
   585.5,
   627.5,
   671,
   716.5,
   764,
   813,
   864,
   917,
   972};
   Double_t Graph_from_data_obs_rebin_fy3002[18] = {
   577.0381,
   476.8166,
   373.8143,
   285.4472,
   213.5628,
   159.1555,
   117.9024,
   87.28998,
   64.53556,
   47.49125,
   34.96103,
   25.72205,
   18.8925,
   13.94982,
   10.26437,
   7.597441,
   5.620666,
   4.140356};
   Double_t Graph_from_data_obs_rebin_felx3002[18] = {
   13,
   14.5,
   14.5,
   16,
   16.5,
   17,
   18,
   18.5,
   19.5,
   20.5,
   21.5,
   22,
   23.5,
   24,
   25,
   26,
   27,
   28};
   Double_t Graph_from_data_obs_rebin_fely3002[18] = {
   0.1511873,
   0.1301297,
   0.1152202,
   0.09584902,
   0.0816405,
   0.06943385,
   0.05807775,
   0.04929253,
   0.0412826,
   0.03453939,
   0.02893728,
   0.02453727,
   0.02034677,
   0.01730069,
   0.01454055,
   0.01226681,
   0.01035372,
   0.008726183};
   Double_t Graph_from_data_obs_rebin_fehx3002[18] = {
   13,
   14.5,
   14.5,
   16,
   16.5,
   17,
   18,
   18.5,
   19.5,
   20.5,
   21.5,
   22,
   23.5,
   24,
   25,
   26,
   27,
   28};
   Double_t Graph_from_data_obs_rebin_fehy3002[18] = {
   0.1512269,
   0.1301652,
   0.1152558,
   0.09588121,
   0.08167171,
   0.06946414,
   0.05810637,
   0.04932037,
   0.04130901,
   0.03456452,
   0.02896124,
   0.02456069,
   0.0203687,
   0.01732215,
   0.01456116,
   0.01228663,
   0.01037281,
   0.008744593};
   grae = new TGraphAsymmErrors(18,Graph_from_data_obs_rebin_fx3002,Graph_from_data_obs_rebin_fy3002,Graph_from_data_obs_rebin_felx3002,Graph_from_data_obs_rebin_fehx3002,Graph_from_data_obs_rebin_fely3002,Graph_from_data_obs_rebin_fehy3002);
   grae->SetName("Graph_from_data_obs_rebin");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph_from_data_obs_rebin3002 = new TH1F("Graph_Graph_from_data_obs_rebin3002","Dijet Mass",100,197,1073);
   Graph_Graph_from_data_obs_rebin3002->SetMinimum(3.718467);
   Graph_Graph_from_data_obs_rebin3002->SetMaximum(634.4951);
   Graph_Graph_from_data_obs_rebin3002->SetDirectory(0);
   Graph_Graph_from_data_obs_rebin3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_from_data_obs_rebin3002->SetLineColor(ci);
   Graph_Graph_from_data_obs_rebin3002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_from_data_obs_rebin3002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_from_data_obs_rebin3002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_from_data_obs_rebin3002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_from_data_obs_rebin3002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_from_data_obs_rebin3002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_from_data_obs_rebin3002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_from_data_obs_rebin3002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_from_data_obs_rebin3002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_from_data_obs_rebin3002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_from_data_obs_rebin3002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_from_data_obs_rebin3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_from_data_obs_rebin3002);
   
   grae->Draw("zp");
      tex = new TLatex(290,1000,"10^{6}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,100,"10^{5}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,10,"10^{4}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,1,"10^{3}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,0.1,"10^{2}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,0.01,"10");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,0.001,"1");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(290,0.0001,"10^{#minus1}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   c_1->Modified();
   c->cd();
  
// ------------>Primitives in pad: c_2
   TPad *c_2 = new TPad("c_2", "c_2",0.01,0.02,0.99,0.36);
   c_2->Draw();
   c_2->cd();
   c_2->Range(105.1613,-7.269231,1047.097,3.5);
   c_2->SetFillColor(0);
   c_2->SetBorderMode(0);
   c_2->SetBorderSize(2);
   c_2->SetTickx(1);
   c_2->SetTicky(1);
   c_2->SetLeftMargin(0.175);
   c_2->SetRightMargin(0.05);
   c_2->SetTopMargin(0);
   c_2->SetBottomMargin(0.35);
   c_2->SetFrameBorderMode(0);
   c_2->SetFrameBorderMode(0);
   Double_t xAxis2[19] = {270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000}; 
   
   TH1D *h_fit_residual_vs_mass2 = new TH1D("h_fit_residual_vs_mass2","h_fit_residual_vs_mass",18, xAxis2);
   h_fit_residual_vs_mass2->SetBinContent(1,-0.7412418);
   h_fit_residual_vs_mass2->SetBinContent(2,2.294092);
   h_fit_residual_vs_mass2->SetBinContent(3,-1.080883);
   h_fit_residual_vs_mass2->SetBinContent(4,-1.113561);
   h_fit_residual_vs_mass2->SetBinContent(5,-0.7336093);
   h_fit_residual_vs_mass2->SetBinContent(6,0.7759479);
   h_fit_residual_vs_mass2->SetBinContent(7,-0.8369579);
   h_fit_residual_vs_mass2->SetBinContent(8,1.328524);
   h_fit_residual_vs_mass2->SetBinContent(9,1.414175);
   h_fit_residual_vs_mass2->SetBinContent(10,-0.4118419);
   h_fit_residual_vs_mass2->SetBinContent(11,1.190146);
   h_fit_residual_vs_mass2->SetBinContent(12,-0.3009625);
   h_fit_residual_vs_mass2->SetBinContent(13,-2.568305);
   h_fit_residual_vs_mass2->SetBinContent(14,0.6579019);
   h_fit_residual_vs_mass2->SetBinContent(15,-1.622321);
   h_fit_residual_vs_mass2->SetBinContent(16,0.3128685);
   h_fit_residual_vs_mass2->SetBinContent(17,1.415403);
   h_fit_residual_vs_mass2->SetBinContent(18,0.03287753);
   h_fit_residual_vs_mass2->SetBinError(1,1);
   h_fit_residual_vs_mass2->SetBinError(2,1);
   h_fit_residual_vs_mass2->SetBinError(3,1);
   h_fit_residual_vs_mass2->SetBinError(4,1);
   h_fit_residual_vs_mass2->SetBinError(5,1);
   h_fit_residual_vs_mass2->SetBinError(6,1);
   h_fit_residual_vs_mass2->SetBinError(7,1);
   h_fit_residual_vs_mass2->SetBinError(8,1);
   h_fit_residual_vs_mass2->SetBinError(9,1);
   h_fit_residual_vs_mass2->SetBinError(10,1);
   h_fit_residual_vs_mass2->SetBinError(11,1);
   h_fit_residual_vs_mass2->SetBinError(12,1);
   h_fit_residual_vs_mass2->SetBinError(13,1);
   h_fit_residual_vs_mass2->SetBinError(14,1);
   h_fit_residual_vs_mass2->SetBinError(15,1);
   h_fit_residual_vs_mass2->SetBinError(16,1);
   h_fit_residual_vs_mass2->SetBinError(17,1);
   h_fit_residual_vs_mass2->SetBinError(18,1);
   h_fit_residual_vs_mass2->SetMinimum(-3.5);
   h_fit_residual_vs_mass2->SetMaximum(3.5);
   h_fit_residual_vs_mass2->SetEntries(18);
   h_fit_residual_vs_mass2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   h_fit_residual_vs_mass2->SetFillColor(ci);
   h_fit_residual_vs_mass2->GetXaxis()->SetTitle("Dijet mass [TeV]");
   h_fit_residual_vs_mass2->GetXaxis()->SetRange(1,18);
   h_fit_residual_vs_mass2->GetXaxis()->SetLabelFont(42);
   h_fit_residual_vs_mass2->GetXaxis()->SetLabelOffset(1000);
   h_fit_residual_vs_mass2->GetXaxis()->SetLabelSize(0.1);
   h_fit_residual_vs_mass2->GetXaxis()->SetTitleSize(0.12);
   h_fit_residual_vs_mass2->GetXaxis()->SetTitleFont(42);
   h_fit_residual_vs_mass2->GetYaxis()->SetTitle("#frac{(Data-Fit)}{Uncertainty}");
   h_fit_residual_vs_mass2->GetYaxis()->SetNdivisions(210);
   h_fit_residual_vs_mass2->GetYaxis()->SetLabelFont(42);
   h_fit_residual_vs_mass2->GetYaxis()->SetLabelSize(0.1);
   h_fit_residual_vs_mass2->GetYaxis()->SetTitleSize(0.12);
   h_fit_residual_vs_mass2->GetYaxis()->SetTitleOffset(0.6);
   h_fit_residual_vs_mass2->GetYaxis()->SetTitleFont(42);
   h_fit_residual_vs_mass2->GetZaxis()->SetLabelFont(42);
   h_fit_residual_vs_mass2->GetZaxis()->SetLabelSize(0.035);
   h_fit_residual_vs_mass2->GetZaxis()->SetTitleSize(0.035);
   h_fit_residual_vs_mass2->GetZaxis()->SetTitleFont(42);
   h_fit_residual_vs_mass2->Draw("hist");
   TLine *line = new TLine(270,0,1000,0);
   line->Draw();
      tex = new TLatex(400,-4,"0.4");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(600,-4,"0.6");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(800,-4,"0.8");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1000,-4,"1");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1200,-4,"1.2");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1400,-4,"1.4");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1600,-4,"1.6");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(1800,-4,"1.8");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(2000,-4,"2");
   tex->SetTextAlign(22);
   tex->SetTextFont(42);
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   c_2->Modified();
   c->cd();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
