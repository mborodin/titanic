
void test_TEfficiency(float cl=0.95){

TH1F h1("h1","h1",3,0,2);
TH1F h2("h2","h2",3,0,2);


h1.SetBinContent(1,87); 
h1.SetBinContent(2,248); 
h1.SetBinContent(3,83); 
h2.SetBinContent(1,418); 
h2.SetBinContent(2,418); 
h2.SetBinContent(3,418); 


TEfficiency* pEff = 0;
TFile* pFile = new TFile("test_TEfficiency.root","recreate");
//h_pass and h_total are valid and consistent histograms
if(TEfficiency::CheckConsistency(h1,h2))
{
  pEff = new TEfficiency(h1,h2);
  pEff->SetStatisticOption(TEfficiency::kFCP);
  pEff->SetConfidenceLevel(cl);
  //this will attach the TEfficiency object to the current directory
  pEff->SetDirectory(gDirectory);

 cout << "sdvgargsrgs" << endl;

 for(int i=0;i<3;i++){
 double c = pEff->GetEfficiency(i+1);
 double l = pEff->GetEfficiencyErrorLow(i+1);
 double u = pEff->GetEfficiencyErrorUp(i+1);
 printf("%d %f %f %f\n",i,c,c-l,c+u);

 }

  pFile->Write();
}


}
