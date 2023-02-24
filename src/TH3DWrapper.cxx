#include "TH3D.h"
#include "TFile.h"


extern "C" {

  TH3D* TH3DCtor(const char* name, const char* title,
                 int nbinsX, double xmin, double xmax,
                 int nbinsY, double ymin, double ymax,
                 int nbinsZ, double zmin, double zmax) {


    TH3D* h = new TH3D(name, title,
                       nbinsX, xmin,xmax,
                       nbinsY, ymin,ymax,
                       nbinsZ, zmin,zmax);
    
    
    return h;
  }

  void TH3D_Fill(TH3D* h, double x, double y, double z) {

    h->Fill(x,y,z);
    
  }

  void TH3D_Write(TH3D* h, TFile* f) {

    f->cd();
    h->Write();
      
  }

  void TH3D_Delete(TH3D* h) {
    if (h)
      delete h;
  }
  
}
