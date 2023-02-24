#include "TH2D.h"
#include "TFile.h"


extern "C" {

  TH2D* TH2DCtor(const char* name, const char* title,
                 int nbinsX, double xmin, double xmax,
                 int nbinsY, double ymin, double ymax){
                 
    TH2D* h = new TH2D(name, title,
                       nbinsX, xmin,xmax,
                       nbinsY, ymin,ymax);
    return h;
  }

  void TH2D_Fill(TH2D* h, double x, double y) {

    h->Fill(x,y);
    
  }
  
  void TH2D_Write(TH2D* h, TFile* f) {

    f->cd();
    h->Write();
      
  }
  
  void TH2D_Delete(TH2D* h) {
    if (h)
      delete h;
  }
  
  int TH2D_FindBin(TH1* h, double x, double y) {
    
    return h->FindBin(x,y);
  }

  double TH2D_GetBinContent(TH1* h, int i) {
    return h->GetBinContent(i);
  }
  
  double TH2D_GetBinContent2(TH1* h, int i, int j) {
    return h->GetBinContent(i,j);
  }

  double TH2D_GetBinError(TH1* h, int i) {
    return h->GetBinError(i);
  }
  
  double TH2D_GetBinError2(TH1* h, int i, int j) {
    return h->GetBinError(i,j);
  }
  
}
