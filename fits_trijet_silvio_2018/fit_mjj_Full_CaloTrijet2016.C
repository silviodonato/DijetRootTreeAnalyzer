void fit_mjj_Full_CaloTrijet2016()
{
//=========Macro generated from canvas: c/c
//=========  (Mon May 13 14:21:43 2019) by ROOT version6.02/05
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
   c_1->Range(117.4194,-4.69897,1046.452,4.978449);
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
   Double_t xAxis1[19] = {280, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000}; 
   
   TH1D *data_obs_density1 = new TH1D("data_obs_density1","Dijet Mass",18, xAxis1);
   data_obs_density1->SetMinimum(2e-05);
   data_obs_density1->SetMaximum(20000);
   data_obs_density1->SetEntries(5018);
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
   
   TF1 *CaloTrijet2016_bkg_unbin1 = new TF1("*CaloTrijet2016_bkg_unbin",280,1000,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet2016_bkg_unbin = new TF1("CaloTrijet2016_bkg_unbin",,280,1000,1);
   CaloTrijet2016_bkg_unbin1->SetRange(280,1000);
   CaloTrijet2016_bkg_unbin1->SetName("CaloTrijet2016_bkg_unbin");
   CaloTrijet2016_bkg_unbin1->SetTitle("");
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(0,171.4057);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(1,160.6031);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(2,150.1472);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(3,140.1422);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(4,130.6492);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(5,121.6985);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(6,113.299);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(7,105.4453);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(8,98.12185);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(9,91.30706);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(10,84.9754);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(11,79.0993);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(12,73.65042);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(13,68.60047);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(14,63.92184);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(15,59.58794);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(16,55.57348);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(17,51.8546);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(18,48.40891);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(19,45.21553);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(20,42.25504);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(21,39.50944);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(22,36.96209);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(23,34.59761);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(24,32.40186);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(25,30.36179);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(26,28.46539);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(27,26.70164);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(28,25.06037);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(29,23.53227);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(30,22.10877);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(31,20.78198);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(32,19.54466);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(33,18.39015);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(34,17.31233);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(35,16.30557);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(36,15.36467);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(37,14.48486);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(38,13.66175);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(39,12.89129);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(40,12.16973);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(41,11.49364);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(42,10.85983);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(43,10.26536);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(44,9.707529);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(45,9.183822);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(46,8.691921);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(47,8.229682);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(48,7.795117);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(49,7.386386);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(50,7.001783);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(51,6.639727);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(52,6.29875);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(53,5.977489);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(54,5.67468);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(55,5.389145);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(56,5.119792);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(57,4.865603);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(58,4.625631);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(59,4.398995);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(60,4.184872);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(61,3.982498);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(62,3.791158);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(63,3.610185);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(64,3.438957);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(65,3.276893);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(66,3.123451);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(67,2.978122);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(68,2.840431);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(69,2.709936);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(70,2.586219);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(71,2.468892);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(72,2.357589);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(73,2.251969);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(74,2.151711);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(75,2.056514);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(76,1.966097);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(77,1.880193);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(78,1.798554);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(79,1.720947);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(80,1.647151);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(81,1.57696);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(82,1.51018);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(83,1.446627);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(84,1.38613);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(85,1.328526);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(86,1.273663);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(87,1.221397);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(88,1.171593);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(89,1.124121);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(90,1.078863);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(91,1.035704);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(92,0.9945365);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(93,0.9552595);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(94,0.9177773);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(95,0.8819993);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(96,0.8478401);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(97,0.815219);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(98,0.7840596);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(99,0.7542897);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(100,0.7258409);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(101,280);
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
   CaloTrijet2016_bkg_unbin1->SetParameter(0,6.366135e-08);
   CaloTrijet2016_bkg_unbin1->SetParError(0,0);
   CaloTrijet2016_bkg_unbin1->SetParLimits(0,0,0);
   CaloTrijet2016_bkg_unbin1->Draw("csame");
   TLatex *   tex = new TLatex(0.7,0.94,"2.0 fb^{-1} (13 TeV)");
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
   AText = pt->AddText("#chi^{2} / NDF = 13.3 / 14 = 1.0");
   AText = pt->AddText("Wide Calo-jets");
   AText = pt->AddText("0.28 < m_{jj} < 1.00 TeV");
   AText = pt->AddText("|#eta| < 2.5, |#Delta#eta| < 1.1");
   pt->Draw();
   
   TF1 *CaloTrijet2016_bkg_unbin2 = new TF1("*CaloTrijet2016_bkg_unbin",280,1000,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet2016_bkg_unbin = new TF1("CaloTrijet2016_bkg_unbin",,280,1000,1);
   CaloTrijet2016_bkg_unbin2->SetRange(280,1000);
   CaloTrijet2016_bkg_unbin2->SetName("CaloTrijet2016_bkg_unbin");
   CaloTrijet2016_bkg_unbin2->SetTitle("");
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(0,171.4057);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(1,160.6031);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(2,150.1472);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(3,140.1422);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(4,130.6492);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(5,121.6985);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(6,113.299);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(7,105.4453);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(8,98.12185);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(9,91.30706);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(10,84.9754);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(11,79.0993);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(12,73.65042);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(13,68.60047);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(14,63.92184);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(15,59.58794);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(16,55.57348);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(17,51.8546);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(18,48.40891);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(19,45.21553);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(20,42.25504);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(21,39.50944);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(22,36.96209);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(23,34.59761);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(24,32.40186);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(25,30.36179);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(26,28.46539);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(27,26.70164);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(28,25.06037);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(29,23.53227);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(30,22.10877);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(31,20.78198);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(32,19.54466);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(33,18.39015);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(34,17.31233);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(35,16.30557);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(36,15.36467);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(37,14.48486);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(38,13.66175);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(39,12.89129);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(40,12.16973);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(41,11.49364);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(42,10.85983);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(43,10.26536);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(44,9.707529);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(45,9.183822);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(46,8.691921);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(47,8.229682);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(48,7.795117);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(49,7.386386);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(50,7.001783);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(51,6.639727);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(52,6.29875);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(53,5.977489);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(54,5.67468);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(55,5.389145);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(56,5.119792);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(57,4.865603);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(58,4.625631);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(59,4.398995);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(60,4.184872);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(61,3.982498);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(62,3.791158);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(63,3.610185);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(64,3.438957);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(65,3.276893);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(66,3.123451);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(67,2.978122);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(68,2.840431);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(69,2.709936);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(70,2.586219);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(71,2.468892);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(72,2.357589);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(73,2.251969);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(74,2.151711);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(75,2.056514);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(76,1.966097);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(77,1.880193);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(78,1.798554);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(79,1.720947);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(80,1.647151);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(81,1.57696);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(82,1.51018);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(83,1.446627);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(84,1.38613);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(85,1.328526);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(86,1.273663);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(87,1.221397);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(88,1.171593);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(89,1.124121);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(90,1.078863);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(91,1.035704);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(92,0.9945365);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(93,0.9552595);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(94,0.9177773);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(95,0.8819993);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(96,0.8478401);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(97,0.815219);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(98,0.7840596);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(99,0.7542897);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(100,0.7258409);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(101,280);
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
   CaloTrijet2016_bkg_unbin2->SetParameter(0,6.366135e-08);
   CaloTrijet2016_bkg_unbin2->SetParError(0,0);
   CaloTrijet2016_bkg_unbin2->SetParLimits(0,0,0);
   CaloTrijet2016_bkg_unbin2->Draw("csame");
   
   Double_t g_data_clone_fx3001[18] = {
   288,
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
   159.4485,
   128.924,
   96.57798,
   71.35509,
   52.06788,
   37.97243,
   27.65325,
   20.12864,
   14.66093,
   10.64939,
   7.731589,
   5.606631,
   4.067782,
   2.957674,
   2.163665,
   1.582725,
   1.154042,
   0.845767};
   Double_t g_data_clone_felx3001[18] = {
   8,
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
   0.07073184,
   0.04724247,
   0.04088884,
   0.03345817,
   0.02814445,
   0.02367879,
   0.01963752,
   0.01652612,
   0.01373767,
   0.01141919,
   0.009500901,
   0.007998145,
   0.006591655,
   0.005561847,
   0.004660949,
   0.003908997,
   0.003275504,
   0.002753565};
   Double_t g_data_clone_fehx3001[18] = {
   8,
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
   0.07076322,
   0.04725979,
   0.04090616,
   0.03347387,
   0.02815966,
   0.02369356,
   0.01965147,
   0.0165397,
   0.01375055,
   0.01143144,
   0.009512583,
   0.008009562,
   0.006602345,
   0.005572316,
   0.004671001,
   0.003918664,
   0.003284814,
   0.002762544};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(18,g_data_clone_fx3001,g_data_clone_fy3001,g_data_clone_felx3001,g_data_clone_fehx3001,g_data_clone_fely3001,g_data_clone_fehy3001);
   grae->SetName("g_data_clone");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_g_data_clone3001 = new TH1F("Graph_g_data_clone3001","Dijet Mass",100,208,1072);
   Graph_g_data_clone3001->SetMinimum(0.7587121);
   Graph_g_data_clone3001->SetMaximum(175.3869);
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
   288,
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
   159.4485,
   128.924,
   96.57798,
   71.35509,
   52.06788,
   37.97243,
   27.65325,
   20.12864,
   14.66093,
   10.64939,
   7.731589,
   5.606631,
   4.067782,
   2.957674,
   2.163665,
   1.582725,
   1.154042,
   0.845767};
   Double_t Graph_from_data_obs_rebin_felx3002[18] = {
   8,
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
   0.07073184,
   0.04724247,
   0.04088884,
   0.03345817,
   0.02814445,
   0.02367879,
   0.01963752,
   0.01652612,
   0.01373767,
   0.01141919,
   0.009500901,
   0.007998145,
   0.006591655,
   0.005561847,
   0.004660949,
   0.003908997,
   0.003275504,
   0.002753565};
   Double_t Graph_from_data_obs_rebin_fehx3002[18] = {
   8,
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
   0.07076322,
   0.04725979,
   0.04090616,
   0.03347387,
   0.02815966,
   0.02369356,
   0.01965147,
   0.0165397,
   0.01375055,
   0.01143144,
   0.009512583,
   0.008009562,
   0.006602345,
   0.005572316,
   0.004671001,
   0.003918664,
   0.003284814,
   0.002762544};
   grae = new TGraphAsymmErrors(18,Graph_from_data_obs_rebin_fx3002,Graph_from_data_obs_rebin_fy3002,Graph_from_data_obs_rebin_felx3002,Graph_from_data_obs_rebin_fehx3002,Graph_from_data_obs_rebin_fely3002,Graph_from_data_obs_rebin_fehy3002);
   grae->SetName("Graph_from_data_obs_rebin");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph_from_data_obs_rebin3002 = new TH1F("Graph_Graph_from_data_obs_rebin3002","Dijet Mass",100,208,1072);
   Graph_Graph_from_data_obs_rebin3002->SetMinimum(0.7587121);
   Graph_Graph_from_data_obs_rebin3002->SetMaximum(175.3869);
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
      tex = new TLatex(275.5733,10000,"10^{7}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,1000,"10^{6}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,100,"10^{5}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,10,"10^{4}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,1,"10^{3}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,0.1,"10^{2}");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,0.01,"10");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,0.001,"1");
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(275.5733,0.0001,"10^{#minus1}");
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
   c_2->Range(117.4194,-7.269231,1046.452,3.5);
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
   Double_t xAxis2[19] = {280, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000}; 
   
   TH1D *h_fit_residual_vs_mass2 = new TH1D("h_fit_residual_vs_mass2","h_fit_residual_vs_mass",18, xAxis2);
   h_fit_residual_vs_mass2->SetBinContent(1,-0.676937);
   h_fit_residual_vs_mass2->SetBinContent(2,1.485145);
   h_fit_residual_vs_mass2->SetBinContent(3,-0.8873656);
   h_fit_residual_vs_mass2->SetBinContent(4,-1.172049);
   h_fit_residual_vs_mass2->SetBinContent(5,0.8477082);
   h_fit_residual_vs_mass2->SetBinContent(6,0.317057);
   h_fit_residual_vs_mass2->SetBinContent(7,0.09752896);
   h_fit_residual_vs_mass2->SetBinContent(8,0.10803);
   h_fit_residual_vs_mass2->SetBinContent(9,-0.05864891);
   h_fit_residual_vs_mass2->SetBinContent(10,-0.1284022);
   h_fit_residual_vs_mass2->SetBinContent(11,0.9464905);
   h_fit_residual_vs_mass2->SetBinContent(12,-0.676359);
   h_fit_residual_vs_mass2->SetBinContent(13,-1.419426);
   h_fit_residual_vs_mass2->SetBinContent(14,-0.5725187);
   h_fit_residual_vs_mass2->SetBinContent(15,0.9636846);
   h_fit_residual_vs_mass2->SetBinContent(16,1.526958);
   h_fit_residual_vs_mass2->SetBinContent(17,-0.05911124);
   h_fit_residual_vs_mass2->SetBinContent(18,-0.8095156);
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
   TLine *line = new TLine(280,0,1000,0);
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
