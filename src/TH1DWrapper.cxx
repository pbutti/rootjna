#include "TH1D.h"
#include "TSystem.h"


extern "C" {

  TH1D* TH1DCtor(const char* name, const char* title, int bins, double xlow, double xhigh) {

    TH1D* h = new TH1D(name,title,bins,xlow,xhigh);
    return h;
  }

  
  int TH1D_GetEntries(TH1D* h) {
    return h->GetEntries();
  }

  
  int TH1D_FindBin(TH1* h, double x) {
    
    return h->FindBin(x);
  }

  double TH1D_GetBinContent(TH1* h, int i) {
    return h->GetBinContent(i);
  }

  double TH1D_GetBinError(TH1* h, int i) {
    return h->GetBinError(i);
  }
  
}
