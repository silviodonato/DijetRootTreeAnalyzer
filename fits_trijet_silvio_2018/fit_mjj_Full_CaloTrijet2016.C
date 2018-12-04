void fit_mjj_Full_CaloTrijet2016()
{
//=========Macro generated from canvas: c/c
//=========  (Thu Jul 26 15:18:00 2018) by ROOT version6.02/05
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
   c_1->Range(208.129,-4.69897,1041.677,3.903181);
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
   Double_t xAxis1[16] = {354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000}; 
   
   TH1F *data_obs_density1 = new TH1F("data_obs_density1","Dijet Mass",15, xAxis1);
   data_obs_density1->SetMinimum(2e-05);
   data_obs_density1->SetMaximum(2000);
   data_obs_density1->SetEntries(9.488506e+07);
   data_obs_density1->SetLineColor(0);
   data_obs_density1->SetLineWidth(0);
   data_obs_density1->SetMarkerColor(0);
   data_obs_density1->GetXaxis()->SetRange(1,15);
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
   
   TF1 *CaloTrijet2016_bkg_unbin1 = new TF1("*CaloTrijet2016_bkg_unbin",354,1000,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet2016_bkg_unbin = new TF1("CaloTrijet2016_bkg_unbin",,354,1000,1);
   CaloTrijet2016_bkg_unbin1->SetRange(354,1000);
   CaloTrijet2016_bkg_unbin1->SetName("CaloTrijet2016_bkg_unbin");
   CaloTrijet2016_bkg_unbin1->SetTitle("");
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(0,4.783995);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(1,4.467875);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(2,4.172498);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(3,3.897326);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(4,3.641448);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(5,3.403767);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(6,3.183115);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(7,2.978318);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(8,2.788233);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(9,2.611769);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(10,2.447898);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(11,2.295657);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(12,2.154155);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(13,2.022564);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(14,1.900124);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(15,1.786131);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(16,1.67994);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(17,1.580956);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(18,1.488635);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(19,1.402475);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(20,1.322016);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(21,1.246835);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(22,1.176544);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(23,1.110785);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(24,1.04923);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(25,0.9915763);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(26,0.9375459);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(27,0.8868824);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(28,0.8393494);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(29,0.7947292);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(30,0.7528205);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(31,0.7134378);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(32,0.6764095);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(33,0.641577);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(34,0.6087936);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(35,0.5779234);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(36,0.5488407);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(37,0.5214289);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(38,0.4955798);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(39,0.4711931);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(40,0.4481756);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(41,0.4264408);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(42,0.4059082);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(43,0.3865029);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(44,0.3681554);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(45,0.3508006);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(46,0.3343782);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(47,0.3188319);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(48,0.3041091);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(49,0.2901607);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(50,0.2769409);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(51,0.264407);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(52,0.252519);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(53,0.2412395);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(54,0.2305334);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(55,0.2203682);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(56,0.210713);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(57,0.2015391);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(58,0.1928197);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(59,0.1845294);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(60,0.1766445);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(61,0.1691429);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(62,0.1620036);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(63,0.1552069);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(64,0.1487345);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(65,0.142569);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(66,0.1366941);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(67,0.1310945);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(68,0.1257556);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(69,0.1206639);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(70,0.1158065);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(71,0.1111715);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(72,0.1067473);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(73,0.1025232);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(74,0.09848919);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(75,0.09463559);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(76,0.09095338);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(77,0.08743404);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(78,0.08406951);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(79,0.08085216);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(80,0.0777748);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(81,0.0748306);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(82,0.07201312);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(83,0.06931626);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(84,0.06673424);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(85,0.0642616);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(86,0.06189315);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(87,0.05962399);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(88,0.05744945);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(89,0.05536514);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(90,0.05336685);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(91,0.05145063);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(92,0.04961271);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(93,0.04784951);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(94,0.04615763);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(95,0.04453386);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(96,0.04297512);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(97,0.0414785);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(98,0.04004125);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(99,0.03866072);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(100,0.03733442);
   CaloTrijet2016_bkg_unbin1->SetSavedPoint(101,354);
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
   CaloTrijet2016_bkg_unbin1->SetParameter(0,0.0004379726);
   CaloTrijet2016_bkg_unbin1->SetParError(0,0);
   CaloTrijet2016_bkg_unbin1->SetParLimits(0,0,0);
   CaloTrijet2016_bkg_unbin1->Draw("csame");
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
   AText = pt->AddText("#chi^{2} / NDF = 11.4 / 11 = 1.0");
   AText = pt->AddText("Wide Calo-jets");
   AText = pt->AddText("0.30 < m_{jj} < 0.74 TeV");
   AText = pt->AddText("|#eta| < 2.5, |#Delta#eta| < 1.3");
   pt->Draw();
   
   TF1 *CaloTrijet2016_bkg_unbin2 = new TF1("*CaloTrijet2016_bkg_unbin",354,1000,1);
    //The original function :  had originally been created by:
    //TF1 *CaloTrijet2016_bkg_unbin = new TF1("CaloTrijet2016_bkg_unbin",,354,1000,1);
   CaloTrijet2016_bkg_unbin2->SetRange(354,1000);
   CaloTrijet2016_bkg_unbin2->SetName("CaloTrijet2016_bkg_unbin");
   CaloTrijet2016_bkg_unbin2->SetTitle("");
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(0,4.783995);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(1,4.467875);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(2,4.172498);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(3,3.897326);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(4,3.641448);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(5,3.403767);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(6,3.183115);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(7,2.978318);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(8,2.788233);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(9,2.611769);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(10,2.447898);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(11,2.295657);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(12,2.154155);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(13,2.022564);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(14,1.900124);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(15,1.786131);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(16,1.67994);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(17,1.580956);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(18,1.488635);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(19,1.402475);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(20,1.322016);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(21,1.246835);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(22,1.176544);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(23,1.110785);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(24,1.04923);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(25,0.9915763);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(26,0.9375459);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(27,0.8868824);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(28,0.8393494);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(29,0.7947292);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(30,0.7528205);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(31,0.7134378);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(32,0.6764095);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(33,0.641577);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(34,0.6087936);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(35,0.5779234);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(36,0.5488407);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(37,0.5214289);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(38,0.4955798);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(39,0.4711931);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(40,0.4481756);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(41,0.4264408);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(42,0.4059082);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(43,0.3865029);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(44,0.3681554);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(45,0.3508006);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(46,0.3343782);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(47,0.3188319);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(48,0.3041091);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(49,0.2901607);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(50,0.2769409);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(51,0.264407);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(52,0.252519);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(53,0.2412395);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(54,0.2305334);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(55,0.2203682);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(56,0.210713);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(57,0.2015391);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(58,0.1928197);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(59,0.1845294);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(60,0.1766445);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(61,0.1691429);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(62,0.1620036);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(63,0.1552069);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(64,0.1487345);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(65,0.142569);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(66,0.1366941);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(67,0.1310945);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(68,0.1257556);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(69,0.1206639);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(70,0.1158065);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(71,0.1111715);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(72,0.1067473);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(73,0.1025232);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(74,0.09848919);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(75,0.09463559);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(76,0.09095338);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(77,0.08743404);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(78,0.08406951);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(79,0.08085216);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(80,0.0777748);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(81,0.0748306);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(82,0.07201312);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(83,0.06931626);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(84,0.06673424);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(85,0.0642616);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(86,0.06189315);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(87,0.05962399);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(88,0.05744945);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(89,0.05536514);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(90,0.05336685);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(91,0.05145063);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(92,0.04961271);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(93,0.04784951);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(94,0.04615763);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(95,0.04453386);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(96,0.04297512);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(97,0.0414785);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(98,0.04004125);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(99,0.03866072);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(100,0.03733442);
   CaloTrijet2016_bkg_unbin2->SetSavedPoint(101,354);
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
   CaloTrijet2016_bkg_unbin2->SetParameter(0,0.0004379726);
   CaloTrijet2016_bkg_unbin2->SetParError(0,0);
   CaloTrijet2016_bkg_unbin2->SetParLimits(0,0,0);
   CaloTrijet2016_bkg_unbin2->Draw("csame");
   
   Double_t g_data_clone_fx3001[15] = {
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
   Double_t g_data_clone_fy3001[15] = {
   4.059175,
   2.894218,
   2.075264,
   1.48537,
   1.068369,
   0.7715106,
   0.5563618,
   0.4017348,
   0.290452,
   0.2106982,
   0.1531064,
   0.1111538,
   0.08151275,
   0.05937893,
   0.04380472};
   Double_t g_data_clone_felx3001[15] = {
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
   Double_t g_data_clone_fely3001[15] = {
   0.001879776,
   0.001563043,
   0.001303945,
   0.001072083,
   0.0008968545,
   0.0007423364,
   0.0006148212,
   0.0005101496,
   0.0004288179,
   0.0003533812,
   0.0002980836,
   0.0002488507,
   0.0002089646,
   0.0001750173,
   0.0001476141};
   Double_t g_data_clone_fehx3001[15] = {
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
   Double_t g_data_clone_fehy3001[15] = {
   0.001880647,
   0.001563887,
   0.001304765,
   0.001072857,
   0.0008976077,
   0.000743051,
   0.000615501,
   0.0005107979,
   0.0004294514,
   0.0003539744,
   0.0002986645,
   0.0002494085,
   0.000209501,
   0.0001755339,
   0.0001481123};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(15,g_data_clone_fx3001,g_data_clone_fy3001,g_data_clone_felx3001,g_data_clone_fehx3001,g_data_clone_fely3001,g_data_clone_fehy3001);
   grae->SetName("g_data_clone");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0);
   
   TH1F *Graph_g_data_clone3001 = new TH1F("Graph_g_data_clone3001","Dijet Mass",100,289.4,1064.6);
   Graph_g_data_clone3001->SetMinimum(0.03929139);
   Graph_g_data_clone3001->SetMaximum(4.462795);
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
   
   Double_t Graph_from_data_obs_rebin_fx3002[15] = {
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
   Double_t Graph_from_data_obs_rebin_fy3002[15] = {
   4.059175,
   2.894218,
   2.075264,
   1.48537,
   1.068369,
   0.7715106,
   0.5563618,
   0.4017348,
   0.290452,
   0.2106982,
   0.1531064,
   0.1111538,
   0.08151275,
   0.05937893,
   0.04380472};
   Double_t Graph_from_data_obs_rebin_felx3002[15] = {
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
   Double_t Graph_from_data_obs_rebin_fely3002[15] = {
   0.001879776,
   0.001563043,
   0.001303945,
   0.001072083,
   0.0008968545,
   0.0007423364,
   0.0006148212,
   0.0005101496,
   0.0004288179,
   0.0003533812,
   0.0002980836,
   0.0002488507,
   0.0002089646,
   0.0001750173,
   0.0001476141};
   Double_t Graph_from_data_obs_rebin_fehx3002[15] = {
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
   Double_t Graph_from_data_obs_rebin_fehy3002[15] = {
   0.001880647,
   0.001563887,
   0.001304765,
   0.001072857,
   0.0008976077,
   0.000743051,
   0.000615501,
   0.0005107979,
   0.0004294514,
   0.0003539744,
   0.0002986645,
   0.0002494085,
   0.000209501,
   0.0001755339,
   0.0001481123};
   grae = new TGraphAsymmErrors(15,Graph_from_data_obs_rebin_fx3002,Graph_from_data_obs_rebin_fy3002,Graph_from_data_obs_rebin_felx3002,Graph_from_data_obs_rebin_fehx3002,Graph_from_data_obs_rebin_fely3002,Graph_from_data_obs_rebin_fehy3002);
   grae->SetName("Graph_from_data_obs_rebin");
   grae->SetTitle("Dijet Mass");
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.9);
   
   TH1F *Graph_Graph_from_data_obs_rebin3002 = new TH1F("Graph_Graph_from_data_obs_rebin3002","Dijet Mass",100,289.4,1064.6);
   Graph_Graph_from_data_obs_rebin3002->SetMinimum(0.03929139);
   Graph_Graph_from_data_obs_rebin3002->SetMaximum(4.462795);
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
   c_2->Range(208.129,-7.269231,1041.677,3.5);
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
   Double_t xAxis2[16] = {354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000}; 
   
   TH1D *h_fit_residual_vs_mass2 = new TH1D("h_fit_residual_vs_mass2","h_fit_residual_vs_mass",15, xAxis2);
   h_fit_residual_vs_mass2->SetBinContent(1,0.08460594);
   h_fit_residual_vs_mass2->SetBinContent(2,-0.7796938);
   h_fit_residual_vs_mass2->SetBinContent(3,1.941714);
   h_fit_residual_vs_mass2->SetBinContent(4,-1.198289);
   h_fit_residual_vs_mass2->SetBinContent(5,-0.678288);
   h_fit_residual_vs_mass2->SetBinContent(6,0.1696031);
   h_fit_residual_vs_mass2->SetBinContent(7,0.0408142);
   h_fit_residual_vs_mass2->SetBinContent(8,0.8945685);
   h_fit_residual_vs_mass2->SetBinContent(9,-0.3469587);
   h_fit_residual_vs_mass2->SetBinContent(10,0.008580342);
   h_fit_residual_vs_mass2->SetBinContent(11,0.7922354);
   h_fit_residual_vs_mass2->SetBinContent(12,-1.225719);
   h_fit_residual_vs_mass2->SetBinContent(13,0.5509256);
   h_fit_residual_vs_mass2->SetBinContent(14,-1.044039);
   h_fit_residual_vs_mass2->SetBinContent(15,0.796338);
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
   h_fit_residual_vs_mass2->SetMinimum(-3.5);
   h_fit_residual_vs_mass2->SetMaximum(3.5);
   h_fit_residual_vs_mass2->SetEntries(15);
   h_fit_residual_vs_mass2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   h_fit_residual_vs_mass2->SetFillColor(ci);
   h_fit_residual_vs_mass2->GetXaxis()->SetTitle("Dijet mass [TeV]");
   h_fit_residual_vs_mass2->GetXaxis()->SetRange(1,15);
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
   TLine *line = new TLine(354,0,1000,0);
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
