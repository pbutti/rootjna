#include "TH1D.h"
#include "TSystem.h"


extern "C" {
  
  int TH1D_GetEntries(TH1D* h) {
    return h->GetEntries();
  }
  
}
