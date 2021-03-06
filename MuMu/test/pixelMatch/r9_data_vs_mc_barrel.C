{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Jun  7 10:31:00 2011) by ROOT version5.22/00d
   TCanvas *c1 = new TCanvas("c1", "c1",4,21,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(0.1379747,-20.60976,1.150633,137.9268);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.16);
   c1->SetRightMargin(0.05);
   c1->SetTopMargin(0.05);
   c1->SetBottomMargin(0.13);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
   
   TH1 *hs_z = new TH1F("hs_z","",80,0.3,1.1);
   hs_z->SetBinContent(0,3.848357);
   hs_z->SetBinContent(1,1.079966);
   hs_z->SetBinContent(2,0.7150761);
   hs_z->SetBinContent(3,1.825815);
   hs_z->SetBinContent(4,0.9795811);
   hs_z->SetBinContent(5,0.1034028);
   hs_z->SetBinContent(6,0.7086725);
   hs_z->SetBinContent(7,1.313383);
   hs_z->SetBinContent(8,0.08766553);
   hs_z->SetBinContent(9,1.242183);
   hs_z->SetBinContent(10,1.51822);
   hs_z->SetBinContent(11,0.9424144);
   hs_z->SetBinContent(12,2.877516);
   hs_z->SetBinContent(13,2.829045);
   hs_z->SetBinContent(14,2.406032);
   hs_z->SetBinContent(15,2.957331);
   hs_z->SetBinContent(16,3.375385);
   hs_z->SetBinContent(17,3.832014);
   hs_z->SetBinContent(18,1.883533);
   hs_z->SetBinContent(19,1.672423);
   hs_z->SetBinContent(20,1.737488);
   hs_z->SetBinContent(21,4.054103);
   hs_z->SetBinContent(22,2.742174);
   hs_z->SetBinContent(23,1.311895);
   hs_z->SetBinContent(24,1.693844);
   hs_z->SetBinContent(25,4.129623);
   hs_z->SetBinContent(26,4.039645);
   hs_z->SetBinContent(27,2.247714);
   hs_z->SetBinContent(28,3.422525);
   hs_z->SetBinContent(29,4.560732);
   hs_z->SetBinContent(30,5.265826);
   hs_z->SetBinContent(31,4.552757);
   hs_z->SetBinContent(32,2.99564);
   hs_z->SetBinContent(33,3.8335);
   hs_z->SetBinContent(34,3.014956);
   hs_z->SetBinContent(35,2.953909);
   hs_z->SetBinContent(36,4.447932);
   hs_z->SetBinContent(37,3.612489);
   hs_z->SetBinContent(38,6.345923);
   hs_z->SetBinContent(39,6.661031);
   hs_z->SetBinContent(40,2.644643);
   hs_z->SetBinContent(41,4.602107);
   hs_z->SetBinContent(42,5.139136);
   hs_z->SetBinContent(43,4.540734);
   hs_z->SetBinContent(44,3.257758);
   hs_z->SetBinContent(45,5.940638);
   hs_z->SetBinContent(46,3.886729);
   hs_z->SetBinContent(47,4.234691);
   hs_z->SetBinContent(48,3.002449);
   hs_z->SetBinContent(49,3.451066);
   hs_z->SetBinContent(50,5.515964);
   hs_z->SetBinContent(51,6.398148);
   hs_z->SetBinContent(52,4.757617);
   hs_z->SetBinContent(53,4.483064);
   hs_z->SetBinContent(54,5.380349);
   hs_z->SetBinContent(55,4.022025);
   hs_z->SetBinContent(56,6.625014);
   hs_z->SetBinContent(57,3.857584);
   hs_z->SetBinContent(58,3.475323);
   hs_z->SetBinContent(59,7.421212);
   hs_z->SetBinContent(60,8.161477);
   hs_z->SetBinContent(61,11.3456);
   hs_z->SetBinContent(62,11.57751);
   hs_z->SetBinContent(63,32.36403);
   hs_z->SetBinContent(64,49.20179);
   hs_z->SetBinContent(65,93.58243);
   hs_z->SetBinContent(66,115.7105);
   hs_z->SetBinContent(67,47.25025);
   hs_z->SetBinContent(68,6.023829);
   hs_z->SetBinContent(72,0.1729992);
   hs_z->SetMinimum(0);
   hs_z->SetMaximum(130);
   hs_z->SetEntries(2640);
   hs_z->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#99ccff");
   hs_z->SetFillColor(ci);

   ci = TColor::GetColor("#99ccff");
   hs_z->SetLineColor(ci);
   hs_z->SetLineStyle(0);
   hs_z->SetMarkerStyle(20);
   hs_z->GetXaxis()->SetTitle("photon R9");
   hs_z->GetXaxis()->SetLabelFont(42);
   hs_z->GetXaxis()->SetLabelOffset(0.007);
   hs_z->GetXaxis()->SetLabelSize(0.05);
   hs_z->GetXaxis()->SetTitleSize(0.06);
   hs_z->GetXaxis()->SetTitleOffset(0.9);
   hs_z->GetXaxis()->SetTitleFont(42);
   hs_z->GetYaxis()->SetTitle("Events / 0.1");
   hs_z->GetYaxis()->SetLabelFont(42);
   hs_z->GetYaxis()->SetLabelOffset(0.007);
   hs_z->GetYaxis()->SetLabelSize(0.05);
   hs_z->GetYaxis()->SetTitleSize(0.06);
   hs_z->GetYaxis()->SetTitleOffset(1.25);
   hs_z->GetYaxis()->SetTitleFont(42);
   hs_z->GetZaxis()->SetLabelFont(42);
   hs_z->GetZaxis()->SetLabelOffset(0.007);
   hs_z->GetZaxis()->SetLabelSize(0.05);
   hs_z->GetZaxis()->SetTitleSize(0.06);
   hs_z->GetZaxis()->SetTitleFont(42);
   hs_z->Draw("");
   
   TH1 *hs_zj = new TH1F("hs_zj","",80,0.3,1.1);
   hs_zj->SetBinContent(0,0.6189898);
   hs_zj->SetBinContent(3,0.7535509);
   hs_zj->SetBinContent(4,0.02237564);
   hs_zj->SetBinContent(10,0.02237564);
   hs_zj->SetBinContent(15,0.2946132);
   hs_zj->SetBinContent(16,0.09905647);
   hs_zj->SetBinContent(17,0.04873234);
   hs_zj->SetBinContent(23,0.03903776);
   hs_zj->SetBinContent(26,0.06793335);
   hs_zj->SetBinContent(27,0.01133862);
   hs_zj->SetBinContent(29,0.03446788);
   hs_zj->SetBinContent(31,1.288356);
   hs_zj->SetBinContent(33,0.05644836);
   hs_zj->SetBinContent(34,0.06081479);
   hs_zj->SetBinContent(36,0.001180554);
   hs_zj->SetBinContent(38,0.1439044);
   hs_zj->SetBinContent(39,0.6066473);
   hs_zj->SetBinContent(40,0.02030587);
   hs_zj->SetBinContent(42,0.03903776);
   hs_zj->SetBinContent(44,0.005572285);
   hs_zj->SetBinContent(45,0.05367296);
   hs_zj->SetBinContent(49,0.02237564);
   hs_zj->SetBinContent(50,0.85382);
   hs_zj->SetBinContent(51,0.6024159);
   hs_zj->SetBinContent(54,0.05367296);
   hs_zj->SetBinContent(56,0.02237564);
   hs_zj->SetBinContent(57,0.01133862);
   hs_zj->SetBinContent(58,0.1829421);
   hs_zj->SetBinContent(60,0.04465581);
   hs_zj->SetBinContent(62,0.05986219);
   hs_zj->SetBinContent(63,0.08344371);
   hs_zj->SetBinContent(64,0.2760015);
   hs_zj->SetBinContent(65,0.6391214);
   hs_zj->SetBinContent(66,1.767213);
   hs_zj->SetBinContent(67,1.113394);
   hs_zj->SetMinimum(0.0001);
   hs_zj->SetMaximum(1000);
   hs_zj->SetEntries(84);
   hs_zj->SetStats(0);

   ci = TColor::GetColor("#99cc33");
   hs_zj->SetFillColor(ci);

   ci = TColor::GetColor("#99cc33");
   hs_zj->SetLineColor(ci);
   hs_zj->SetLineStyle(0);
   hs_zj->SetMarkerStyle(20);
   hs_zj->GetXaxis()->SetTitle("photon R9");
   hs_zj->GetXaxis()->SetLabelFont(42);
   hs_zj->GetXaxis()->SetLabelOffset(0.007);
   hs_zj->GetXaxis()->SetLabelSize(0.05);
   hs_zj->GetXaxis()->SetTitleSize(0.06);
   hs_zj->GetXaxis()->SetTitleOffset(0.9);
   hs_zj->GetXaxis()->SetTitleFont(42);
   hs_zj->GetYaxis()->SetTitle("Events / 0.1");
   hs_zj->GetYaxis()->SetLabelFont(42);
   hs_zj->GetYaxis()->SetLabelOffset(0.007);
   hs_zj->GetYaxis()->SetLabelSize(0.05);
   hs_zj->GetYaxis()->SetTitleSize(0.06);
   hs_zj->GetYaxis()->SetTitleOffset(1.25);
   hs_zj->GetYaxis()->SetTitleFont(42);
   hs_zj->GetZaxis()->SetLabelFont(42);
   hs_zj->GetZaxis()->SetLabelOffset(0.007);
   hs_zj->GetZaxis()->SetLabelSize(0.05);
   hs_zj->GetZaxis()->SetTitleSize(0.06);
   hs_zj->GetZaxis()->SetTitleFont(42);
   hs_zj->Draw("same");
   
   TH1 *hs_tt = new TH1F("hs_tt","",80,0.3,1.1);
   hs_tt->SetBinContent(4,0.02237564);
   hs_tt->SetBinContent(10,0.02237564);
   hs_tt->SetBinContent(15,0.06081479);
   hs_tt->SetBinContent(17,0.04873234);
   hs_tt->SetBinContent(23,0.03903776);
   hs_tt->SetBinContent(26,0.06793335);
   hs_tt->SetBinContent(27,0.01133862);
   hs_tt->SetBinContent(29,0.03446788);
   hs_tt->SetBinContent(31,0.05037638);
   hs_tt->SetBinContent(33,0.05644836);
   hs_tt->SetBinContent(34,0.06081479);
   hs_tt->SetBinContent(36,0.001180554);
   hs_tt->SetBinContent(42,0.03903776);
   hs_tt->SetBinContent(44,0.005572285);
   hs_tt->SetBinContent(45,0.05367296);
   hs_tt->SetBinContent(49,0.02237564);
   hs_tt->SetBinContent(51,0.05433845);
   hs_tt->SetBinContent(54,0.05367296);
   hs_tt->SetBinContent(56,0.02237564);
   hs_tt->SetBinContent(57,0.01133862);
   hs_tt->SetBinContent(58,0.03903776);
   hs_tt->SetBinContent(60,0.04465581);
   hs_tt->SetBinContent(62,0.05986219);
   hs_tt->SetBinContent(63,0.08344371);
   hs_tt->SetBinContent(64,0.06741033);
   hs_tt->SetBinContent(65,0.2334365);
   hs_tt->SetBinContent(66,0.3557069);
   hs_tt->SetBinContent(67,0.1596319);
   hs_tt->SetMinimum(0.0001);
   hs_tt->SetMaximum(1000);
   hs_tt->SetEntries(65);
   hs_tt->SetStats(0);

   ci = TColor::GetColor("#ffcc33");
   hs_tt->SetFillColor(ci);

   ci = TColor::GetColor("#ffcc33");
   hs_tt->SetLineColor(ci);
   hs_tt->SetLineStyle(0);
   hs_tt->SetMarkerStyle(20);
   hs_tt->GetXaxis()->SetTitle("photon R9");
   hs_tt->GetXaxis()->SetLabelFont(42);
   hs_tt->GetXaxis()->SetLabelOffset(0.007);
   hs_tt->GetXaxis()->SetLabelSize(0.05);
   hs_tt->GetXaxis()->SetTitleSize(0.06);
   hs_tt->GetXaxis()->SetTitleOffset(0.9);
   hs_tt->GetXaxis()->SetTitleFont(42);
   hs_tt->GetYaxis()->SetTitle("Events / 0.1");
   hs_tt->GetYaxis()->SetLabelFont(42);
   hs_tt->GetYaxis()->SetLabelOffset(0.007);
   hs_tt->GetYaxis()->SetLabelSize(0.05);
   hs_tt->GetYaxis()->SetTitleSize(0.06);
   hs_tt->GetYaxis()->SetTitleOffset(1.25);
   hs_tt->GetYaxis()->SetTitleFont(42);
   hs_tt->GetZaxis()->SetLabelFont(42);
   hs_tt->GetZaxis()->SetLabelOffset(0.007);
   hs_tt->GetZaxis()->SetLabelSize(0.05);
   hs_tt->GetZaxis()->SetTitleSize(0.06);
   hs_tt->GetZaxis()->SetTitleFont(42);
   hs_tt->Draw("same");
   
   TH1 *hs_w = new TH1F("hs_w","",80,0.3,1.1);
   hs_w->SetBinContent(17,0.04873234);
   hs_w->SetBinContent(36,9.886684e-06);
   hs_w->SetMinimum(0.0001);
   hs_w->SetMaximum(1000);
   hs_w->SetEntries(2);
   hs_w->SetStats(0);

   ci = TColor::GetColor("#cc3333");
   hs_w->SetFillColor(ci);

   ci = TColor::GetColor("#cc3333");
   hs_w->SetLineColor(ci);
   hs_w->SetLineStyle(0);
   hs_w->SetMarkerStyle(20);
   hs_w->GetXaxis()->SetTitle("photon R9");
   hs_w->GetXaxis()->SetLabelFont(42);
   hs_w->GetXaxis()->SetLabelOffset(0.007);
   hs_w->GetXaxis()->SetLabelSize(0.05);
   hs_w->GetXaxis()->SetTitleSize(0.06);
   hs_w->GetXaxis()->SetTitleOffset(0.9);
   hs_w->GetXaxis()->SetTitleFont(42);
   hs_w->GetYaxis()->SetTitle("Events / 0.1");
   hs_w->GetYaxis()->SetLabelFont(42);
   hs_w->GetYaxis()->SetLabelOffset(0.007);
   hs_w->GetYaxis()->SetLabelSize(0.05);
   hs_w->GetYaxis()->SetTitleSize(0.06);
   hs_w->GetYaxis()->SetTitleOffset(1.25);
   hs_w->GetYaxis()->SetTitleFont(42);
   hs_w->GetZaxis()->SetLabelFont(42);
   hs_w->GetZaxis()->SetLabelOffset(0.007);
   hs_w->GetZaxis()->SetLabelSize(0.05);
   hs_w->GetZaxis()->SetTitleSize(0.06);
   hs_w->GetZaxis()->SetTitleFont(42);
   hs_w->Draw("same");
   
   TH1 *hs_qcd = new TH1F("hs_qcd","",80,0.3,1.1);
   hs_qcd->SetMinimum(0.0001);
   hs_qcd->SetMaximum(1000);
   hs_qcd->SetStats(0);

   ci = TColor::GetColor("#ffff66");
   hs_qcd->SetFillColor(ci);

   ci = TColor::GetColor("#ffff66");
   hs_qcd->SetLineColor(ci);
   hs_qcd->SetLineStyle(0);
   hs_qcd->SetMarkerStyle(20);
   hs_qcd->GetXaxis()->SetTitle("photon R9");
   hs_qcd->GetXaxis()->SetLabelFont(42);
   hs_qcd->GetXaxis()->SetLabelOffset(0.007);
   hs_qcd->GetXaxis()->SetLabelSize(0.05);
   hs_qcd->GetXaxis()->SetTitleSize(0.06);
   hs_qcd->GetXaxis()->SetTitleOffset(0.9);
   hs_qcd->GetXaxis()->SetTitleFont(42);
   hs_qcd->GetYaxis()->SetTitle("Events / 0.1");
   hs_qcd->GetYaxis()->SetLabelFont(42);
   hs_qcd->GetYaxis()->SetLabelOffset(0.007);
   hs_qcd->GetYaxis()->SetLabelSize(0.05);
   hs_qcd->GetYaxis()->SetTitleSize(0.06);
   hs_qcd->GetYaxis()->SetTitleOffset(1.25);
   hs_qcd->GetYaxis()->SetTitleFont(42);
   hs_qcd->GetZaxis()->SetLabelFont(42);
   hs_qcd->GetZaxis()->SetLabelOffset(0.007);
   hs_qcd->GetZaxis()->SetLabelSize(0.05);
   hs_qcd->GetZaxis()->SetTitleSize(0.06);
   hs_qcd->GetZaxis()->SetTitleFont(42);
   hs_qcd->Draw("same");
   
   TH1 *hdata = new TH1F("hdata","",80,0.3,1.1);
   hdata->SetBinContent(0,2);
   hdata->SetBinContent(1,2);
   hdata->SetBinContent(3,1);
   hdata->SetBinContent(4,2);
   hdata->SetBinContent(6,3);
   hdata->SetBinContent(7,3);
   hdata->SetBinContent(8,3);
   hdata->SetBinContent(9,3);
   hdata->SetBinContent(10,2);
   hdata->SetBinContent(11,2);
   hdata->SetBinContent(12,1);
   hdata->SetBinContent(15,2);
   hdata->SetBinContent(16,2);
   hdata->SetBinContent(17,5);
   hdata->SetBinContent(18,1);
   hdata->SetBinContent(19,5);
   hdata->SetBinContent(20,4);
   hdata->SetBinContent(21,3);
   hdata->SetBinContent(22,5);
   hdata->SetBinContent(23,2);
   hdata->SetBinContent(24,5);
   hdata->SetBinContent(25,5);
   hdata->SetBinContent(26,3);
   hdata->SetBinContent(27,2);
   hdata->SetBinContent(28,4);
   hdata->SetBinContent(29,4);
   hdata->SetBinContent(30,3);
   hdata->SetBinContent(31,2);
   hdata->SetBinContent(32,4);
   hdata->SetBinContent(33,5);
   hdata->SetBinContent(34,4);
   hdata->SetBinContent(35,3);
   hdata->SetBinContent(36,1);
   hdata->SetBinContent(37,3);
   hdata->SetBinContent(38,8);
   hdata->SetBinContent(39,2);
   hdata->SetBinContent(40,6);
   hdata->SetBinContent(41,4);
   hdata->SetBinContent(42,4);
   hdata->SetBinContent(43,3);
   hdata->SetBinContent(44,6);
   hdata->SetBinContent(45,3);
   hdata->SetBinContent(46,5);
   hdata->SetBinContent(47,5);
   hdata->SetBinContent(48,3);
   hdata->SetBinContent(49,5);
   hdata->SetBinContent(50,3);
   hdata->SetBinContent(51,5);
   hdata->SetBinContent(52,7);
   hdata->SetBinContent(53,6);
   hdata->SetBinContent(54,4);
   hdata->SetBinContent(55,6);
   hdata->SetBinContent(56,10);
   hdata->SetBinContent(57,5);
   hdata->SetBinContent(58,4);
   hdata->SetBinContent(59,5);
   hdata->SetBinContent(60,7);
   hdata->SetBinContent(61,8);
   hdata->SetBinContent(62,12);
   hdata->SetBinContent(63,20);
   hdata->SetBinContent(64,46);
   hdata->SetBinContent(65,72);
   hdata->SetBinContent(66,111);
   hdata->SetBinContent(67,70);
   hdata->SetBinContent(68,14);
   hdata->SetBinContent(69,1);
   hdata->SetBinContent(71,1);
   hdata->SetBinContent(79,1);
   hdata->SetBinContent(81,1);
   hdata->SetEntries(574);
   hdata->SetStats(0);
   hdata->SetLineStyle(0);
   hdata->SetMarkerStyle(20);
   hdata->GetXaxis()->SetTitle("photon R9");
   hdata->GetXaxis()->SetLabelFont(42);
   hdata->GetXaxis()->SetLabelOffset(0.007);
   hdata->GetXaxis()->SetLabelSize(0.05);
   hdata->GetXaxis()->SetTitleSize(0.06);
   hdata->GetXaxis()->SetTitleOffset(0.9);
   hdata->GetXaxis()->SetTitleFont(42);
   hdata->GetYaxis()->SetTitle("Events / 0.1");
   hdata->GetYaxis()->SetLabelFont(42);
   hdata->GetYaxis()->SetLabelOffset(0.007);
   hdata->GetYaxis()->SetLabelSize(0.05);
   hdata->GetYaxis()->SetTitleSize(0.06);
   hdata->GetYaxis()->SetTitleOffset(1.25);
   hdata->GetYaxis()->SetTitleFont(42);
   hdata->GetZaxis()->SetLabelFont(42);
   hdata->GetZaxis()->SetLabelOffset(0.007);
   hdata->GetZaxis()->SetLabelSize(0.05);
   hdata->GetZaxis()->SetTitleSize(0.06);
   hdata->GetZaxis()->SetTitleFont(42);
   hdata->Draw("e1 same");
   
   TH1 *hs_z = new TH1F("hs_z","",80,0.3,1.1);
   hs_z->SetBinContent(0,3.848357);
   hs_z->SetBinContent(1,1.079966);
   hs_z->SetBinContent(2,0.7150761);
   hs_z->SetBinContent(3,1.825815);
   hs_z->SetBinContent(4,0.9795811);
   hs_z->SetBinContent(5,0.1034028);
   hs_z->SetBinContent(6,0.7086725);
   hs_z->SetBinContent(7,1.313383);
   hs_z->SetBinContent(8,0.08766553);
   hs_z->SetBinContent(9,1.242183);
   hs_z->SetBinContent(10,1.51822);
   hs_z->SetBinContent(11,0.9424144);
   hs_z->SetBinContent(12,2.877516);
   hs_z->SetBinContent(13,2.829045);
   hs_z->SetBinContent(14,2.406032);
   hs_z->SetBinContent(15,2.957331);
   hs_z->SetBinContent(16,3.375385);
   hs_z->SetBinContent(17,3.832014);
   hs_z->SetBinContent(18,1.883533);
   hs_z->SetBinContent(19,1.672423);
   hs_z->SetBinContent(20,1.737488);
   hs_z->SetBinContent(21,4.054103);
   hs_z->SetBinContent(22,2.742174);
   hs_z->SetBinContent(23,1.311895);
   hs_z->SetBinContent(24,1.693844);
   hs_z->SetBinContent(25,4.129623);
   hs_z->SetBinContent(26,4.039645);
   hs_z->SetBinContent(27,2.247714);
   hs_z->SetBinContent(28,3.422525);
   hs_z->SetBinContent(29,4.560732);
   hs_z->SetBinContent(30,5.265826);
   hs_z->SetBinContent(31,4.552757);
   hs_z->SetBinContent(32,2.99564);
   hs_z->SetBinContent(33,3.8335);
   hs_z->SetBinContent(34,3.014956);
   hs_z->SetBinContent(35,2.953909);
   hs_z->SetBinContent(36,4.447932);
   hs_z->SetBinContent(37,3.612489);
   hs_z->SetBinContent(38,6.345923);
   hs_z->SetBinContent(39,6.661031);
   hs_z->SetBinContent(40,2.644643);
   hs_z->SetBinContent(41,4.602107);
   hs_z->SetBinContent(42,5.139136);
   hs_z->SetBinContent(43,4.540734);
   hs_z->SetBinContent(44,3.257758);
   hs_z->SetBinContent(45,5.940638);
   hs_z->SetBinContent(46,3.886729);
   hs_z->SetBinContent(47,4.234691);
   hs_z->SetBinContent(48,3.002449);
   hs_z->SetBinContent(49,3.451066);
   hs_z->SetBinContent(50,5.515964);
   hs_z->SetBinContent(51,6.398148);
   hs_z->SetBinContent(52,4.757617);
   hs_z->SetBinContent(53,4.483064);
   hs_z->SetBinContent(54,5.380349);
   hs_z->SetBinContent(55,4.022025);
   hs_z->SetBinContent(56,6.625014);
   hs_z->SetBinContent(57,3.857584);
   hs_z->SetBinContent(58,3.475323);
   hs_z->SetBinContent(59,7.421212);
   hs_z->SetBinContent(60,8.161477);
   hs_z->SetBinContent(61,11.3456);
   hs_z->SetBinContent(62,11.57751);
   hs_z->SetBinContent(63,32.36403);
   hs_z->SetBinContent(64,49.20179);
   hs_z->SetBinContent(65,93.58243);
   hs_z->SetBinContent(66,115.7105);
   hs_z->SetBinContent(67,47.25025);
   hs_z->SetBinContent(68,6.023829);
   hs_z->SetBinContent(72,0.1729992);
   hs_z->SetMinimum(0.0001);
   hs_z->SetMaximum(1000);
   hs_z->SetEntries(2640);
   hs_z->SetDirectory(0);
   hs_z->SetStats(0);

   ci = TColor::GetColor("#99ccff");
   hs_z->SetFillColor(ci);

   ci = TColor::GetColor("#99ccff");
   hs_z->SetLineColor(ci);
   hs_z->SetLineStyle(0);
   hs_z->SetMarkerStyle(20);
   hs_z->GetXaxis()->SetTitle("photon R9");
   hs_z->GetXaxis()->SetLabelFont(42);
   hs_z->GetXaxis()->SetLabelOffset(0.007);
   hs_z->GetXaxis()->SetLabelSize(0.05);
   hs_z->GetXaxis()->SetTitleSize(0.06);
   hs_z->GetXaxis()->SetTitleOffset(0.9);
   hs_z->GetXaxis()->SetTitleFont(42);
   hs_z->GetYaxis()->SetTitle("Events / 0.1");
   hs_z->GetYaxis()->SetLabelFont(42);
   hs_z->GetYaxis()->SetLabelOffset(0.007);
   hs_z->GetYaxis()->SetLabelSize(0.05);
   hs_z->GetYaxis()->SetTitleSize(0.06);
   hs_z->GetYaxis()->SetTitleOffset(1.25);
   hs_z->GetYaxis()->SetTitleFont(42);
   hs_z->GetZaxis()->SetLabelFont(42);
   hs_z->GetZaxis()->SetLabelOffset(0.007);
   hs_z->GetZaxis()->SetLabelSize(0.05);
   hs_z->GetZaxis()->SetTitleSize(0.06);
   hs_z->GetZaxis()->SetTitleFont(42);
   hs_z->Draw("sameaxis");
   TLatex *   tex = new TLatex(0.15,0.96,"CMS Preliminary 2011");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.75,0.96,"#sqrt{s} = 7 TeV");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1979866,0.5786713,"Barrel");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.875,"42X data + MC");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.8,"Total events: 574");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.725,"L = 241 pb^{-1}");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.65,"E_{T}^{#gamma} > 20 GeV");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
