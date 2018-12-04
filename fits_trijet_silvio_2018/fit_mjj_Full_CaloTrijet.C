void fit_mjj_Full_CaloTrijet()
{
//=========Macro generated from canvas: c/c
//=========  (Wed Jul 25 18:41:03 2018) by ROOT version6.02/05
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
   c_1->Range(195.7419,-4.69897,768.6452,3.903181);
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
   Double_t xAxis1[13] = {296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740}; 
   
   TH1F *data_obs_density1 = new TH1F("data_obs_density1","Dijet Mass",12, xAxis1);
   data_obs_density1->SetMinimum(2e-05);
   data_obs_density1->SetMaximum(2000);
   data_obs_density1->SetEntries(9.488505e+07);
   data_obs_density1->SetLineColor(0);
   data_obs_density1->SetLineWidth(0);
   data_obs_density1->SetMarkerColor(0);
   data_obs_density1->GetXaxis()->SetRange(1,12);
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
   
   TF1 *CaloTrijet_bkg_unbin1 = new TF1("*CaloTrijet_bkg_unbin",296,740,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet_bkg_unbin = new TF1("CaloTrijet_bkg_unbin",,296,740,1);
   CaloTrijet_bkg_unbin1->SetRange(296,740);
   CaloTrijet_bkg_unbin1->SetName("CaloTrijet_bkg_unbin");
   CaloTrijet_bkg_unbin1->SetTitle("");
   CaloTrijet_bkg_unbin1->SetSavedPoint(0,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(1,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(2,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(3,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(4,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(5,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(6,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(7,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(8,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(9,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(10,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(11,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(12,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(13,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(14,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(15,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(16,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(17,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(18,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(19,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(20,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(21,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(22,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(23,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(24,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(25,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(26,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(27,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(28,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(29,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(30,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(31,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(32,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(33,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(34,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(35,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(36,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(37,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(38,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(39,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(40,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(41,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(42,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(43,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(44,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(45,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(46,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(47,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(48,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(49,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(50,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(51,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(52,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(53,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(54,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(55,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(56,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(57,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(58,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(59,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(60,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(61,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(62,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(63,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(64,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(65,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(66,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(67,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(68,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(69,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(70,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(71,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(72,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(73,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(74,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(75,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(76,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(77,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(78,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(79,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(80,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(81,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(82,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(83,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(84,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(85,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(86,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(87,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(88,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(89,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(90,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(91,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(92,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(93,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(94,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(95,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(96,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(97,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(98,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(99,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(100,1);
   CaloTrijet_bkg_unbin1->SetSavedPoint(101,296);
   CaloTrijet_bkg_unbin1->SetSavedPoint(102,740);
   CaloTrijet_bkg_unbin1->SetFillColor(19);
   CaloTrijet_bkg_unbin1->SetFillStyle(0);
   CaloTrijet_bkg_unbin1->SetLineColor(2);
   CaloTrijet_bkg_unbin1->SetLineWidth(2);
   CaloTrijet_bkg_unbin1->GetXaxis()->SetLabelFont(42);
   CaloTrijet_bkg_unbin1->GetXaxis()->SetLabelSize(0.035);
   CaloTrijet_bkg_unbin1->GetXaxis()->SetTitleSize(0.035);
   CaloTrijet_bkg_unbin1->GetXaxis()->SetTitleFont(42);
   CaloTrijet_bkg_unbin1->GetYaxis()->SetLabelFont(42);
   CaloTrijet_bkg_unbin1->GetYaxis()->SetLabelSize(0.035);
   CaloTrijet_bkg_unbin1->GetYaxis()->SetTitleSize(0.035);
   CaloTrijet_bkg_unbin1->GetYaxis()->SetTitleFont(42);
   CaloTrijet_bkg_unbin1->SetParameter(0,1.882105);
   CaloTrijet_bkg_unbin1->SetParError(0,0);
   CaloTrijet_bkg_unbin1->SetParLimits(0,0,0);
   CaloTrijet_bkg_unbin1->Draw("csame");
   TLatex *   tex = new TLatex(0.7,0.94,"35 fb^{-1} (13 TeV)");
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
   
   TLegend *leg = new TLegend(0.7,0.7,0.89,0.89,NULL,"brNDC");
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
   entry=leg->AddEntry("CaloTrijet_bkg_unbin","Fit","l");
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
   AText = pt->AddText("#chi^{2} / NDF = 399893.3 / 6 = 66648.9");
   AText = pt->AddText("Wide Calo-jets");
   AText = pt->AddText("0.30 < m_{jj} < 0.74 TeV");
   AText = pt->AddText("|#eta| < 2.5, |#Delta#eta| < 1.3");
   pt->Draw();
   
   TF1 *CaloTrijet_bkg_unbin2 = new TF1("*CaloTrijet_bkg_unbin",296,740,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet_bkg_unbin = new TF1("CaloTrijet_bkg_unbin",,296,740,1);
   CaloTrijet_bkg_unbin2->SetRange(296,740);
   CaloTrijet_bkg_unbin2->SetName("CaloTrijet_bkg_unbin");
   CaloTrijet_bkg_unbin2->SetTitle("");
   CaloTrijet_bkg_unbin2->SetSavedPoint(0,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(1,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(2,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(3,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(4,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(5,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(6,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(7,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(8,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(9,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(10,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(11,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(12,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(13,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(14,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(15,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(16,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(17,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(18,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(19,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(20,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(21,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(22,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(23,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(24,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(25,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(26,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(27,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(28,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(29,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(30,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(31,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(32,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(33,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(34,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(35,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(36,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(37,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(38,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(39,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(40,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(41,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(42,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(43,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(44,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(45,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(46,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(47,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(48,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(49,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(50,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(51,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(52,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(53,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(54,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(55,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(56,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(57,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(58,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(59,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(60,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(61,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(62,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(63,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(64,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(65,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(66,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(67,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(68,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(69,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(70,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(71,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(72,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(73,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(74,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(75,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(76,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(77,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(78,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(79,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(80,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(81,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(82,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(83,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(84,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(85,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(86,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(87,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(88,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(89,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(90,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(91,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(92,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(93,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(94,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(95,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(96,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(97,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(98,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(99,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(100,1);
   CaloTrijet_bkg_unbin2->SetSavedPoint(101,296);
   CaloTrijet_bkg_unbin2->SetSavedPoint(102,740);
   CaloTrijet_bkg_unbin2->SetFillColor(19);
   CaloTrijet_bkg_unbin2->SetFillStyle(0);
   CaloTrijet_bkg_unbin2->SetLineColor(2);
   CaloTrijet_bkg_unbin2->SetLineWidth(2);
   CaloTrijet_bkg_unbin2->GetXaxis()->SetLabelFont(42);
   CaloTrijet_bkg_unbin2->GetXaxis()->SetLabelSize(0.035);
   CaloTrijet_bkg_unbin2->GetXaxis()->SetTitleSize(0.035);
   CaloTrijet_bkg_unbin2->GetXaxis()->SetTitleFont(42);
   CaloTrijet_bkg_unbin2->GetYaxis()->SetLabelFont(42);
   CaloTrijet_bkg_unbin2->GetYaxis()->SetLabelSize(0.035);
   CaloTrijet_bkg_unbin2->GetYaxis()->SetTitleSize(0.035);
   CaloTrijet_bkg_unbin2->GetYaxis()->SetTitleFont(42);
   CaloTrijet_bkg_unbin2->SetParameter(0,1.882105);
   CaloTrijet_bkg_unbin2->SetParError(0,0);
   CaloTrijet_bkg_unbin2->SetParLimits(0,0,0);
   CaloTrijet_bkg_unbin2->Draw("csame");
   
   Double_t g_data_clone_fx3001[12] = {
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
   716.5};
   Double_t g_data_clone_fy3001[12] = {
   7.82927,
   5.64995,
   4.059175,
   2.894218,
   2.075264,
   1.48537,
   1.068369,
   0.7715106,
   0.5563618,
   0.4017348,
   0.290452,
   0.2106982};
   Double_t g_data_clone_felx3001[12] = {
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
   23.5};
   Double_t g_data_clone_fely3001[12] = {
   0.002742356,
   0.002329622,
   0.001879776,
   0.001563043,
   0.001303945,
   0.001072083,
   0.0008968545,
   0.0007423364,
   0.0006148212,
   0.0005101496,
   0.0004288179,
   0.0003533812};
   Double_t g_data_clone_fehx3001[12] = {
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
   23.5};
   Double_t g_data_clone_fehy3001[12] = {
   0.002743317,
   0.002330583,
   0.001880647,
   0.001563887,
   0.001304765,
   0.001072857,
   0.0008976077,
   0.000743051,
   0.000615501,
   0.0005107979,
   0.0004294514,
   0.0003539744};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(12,g_data_clone_fx3001,g_data_clone_fy3001,g_data_clone_felx3001,g_data_clone_fehx3001,g_data_clone_fely3001,g_data_clone_fehy3001);
   grae->SetName("g_data_clone");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_g_data_clone3001 = new TH1F("Graph_g_data_clone3001","Dijet Mass",100,251.6,784.4);
   Graph_g_data_clone3001->SetMinimum(0.1893103);
   Graph_g_data_clone3001->SetMaximum(8.59418);
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
   
   Double_t Graph_from_data_obs_rebin_fx3002[12] = {
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
   716.5};
   Double_t Graph_from_data_obs_rebin_fy3002[12] = {
   7.82927,
   5.64995,
   4.059175,
   2.894218,
   2.075264,
   1.48537,
   1.068369,
   0.7715106,
   0.5563618,
   0.4017348,
   0.290452,
   0.2106982};
   Double_t Graph_from_data_obs_rebin_felx3002[12] = {
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
   23.5};
   Double_t Graph_from_data_obs_rebin_fely3002[12] = {
   0.002742356,
   0.002329622,
   0.001879776,
   0.001563043,
   0.001303945,
   0.001072083,
   0.0008968545,
   0.0007423364,
   0.0006148212,
   0.0005101496,
   0.0004288179,
   0.0003533812};
   Double_t Graph_from_data_obs_rebin_fehx3002[12] = {
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
   23.5};
   Double_t Graph_from_data_obs_rebin_fehy3002[12] = {
   0.002743317,
   0.002330583,
   0.001880647,
   0.001563887,
   0.001304765,
   0.001072857,
   0.0008976077,
   0.000743051,
   0.000615501,
   0.0005107979,
   0.0004294514,
   0.0003539744};
   grae = new TGraphAsymmErrors(12,Graph_from_data_obs_rebin_fx3002,Graph_from_data_obs_rebin_fy3002,Graph_from_data_obs_rebin_felx3002,Graph_from_data_obs_rebin_fehx3002,Graph_from_data_obs_rebin_fely3002,Graph_from_data_obs_rebin_fehy3002);
   grae->SetName("Graph_from_data_obs_rebin");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph_from_data_obs_rebin3002 = new TH1F("Graph_Graph_from_data_obs_rebin3002","Dijet Mass",100,251.6,784.4);
   Graph_Graph_from_data_obs_rebin3002->SetMinimum(0.1893103);
   Graph_Graph_from_data_obs_rebin3002->SetMaximum(8.59418);
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
   c_2->Range(195.7419,-7.269231,768.6452,3.5);
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
   Double_t xAxis2[13] = {296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740}; 
   
   TH1D *h_fit_residual_vs_mass2 = new TH1D("h_fit_residual_vs_mass2","h_fit_residual_vs_mass",12, xAxis2);
   h_fit_residual_vs_mass2->SetBinContent(1,411.237);
   h_fit_residual_vs_mass2->SetBinContent(2,257.595);
   h_fit_residual_vs_mass2->SetBinContent(3,144.7729);
   h_fit_residual_vs_mass2->SetBinContent(4,50.41142);
   h_fit_residual_vs_mass2->SetBinContent(5,-17.77912);
   h_fit_residual_vs_mass2->SetBinContent(6,-72.68503);
   h_fit_residual_vs_mass2->SetBinContent(7,-107.6611);
   h_fit_residual_vs_mass2->SetBinContent(8,-132.1447);
   h_fit_residual_vs_mass2->SetBinContent(9,-149.7191);
   h_fit_residual_vs_mass2->SetBinContent(10,-160.4089);
   h_fit_residual_vs_mass2->SetBinContent(11,-167.3815);
   h_fit_residual_vs_mass2->SetBinContent(12,-173.5106);
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
   h_fit_residual_vs_mass2->SetMinimum(-3.5);
   h_fit_residual_vs_mass2->SetMaximum(3.5);
   h_fit_residual_vs_mass2->SetEntries(12);
   h_fit_residual_vs_mass2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   h_fit_residual_vs_mass2->SetFillColor(ci);
   h_fit_residual_vs_mass2->GetXaxis()->SetTitle("Dijet mass [TeV]");
   h_fit_residual_vs_mass2->GetXaxis()->SetRange(1,12);
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
   TLine *line = new TLine(296,0,740,0);
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
