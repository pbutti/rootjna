#include "TFile.h"
#include "TObject.h"
#include "TH1D.h"
#include "TH2D.h"

#include "TSystem.h"

extern "C" {
  
  TFile* TFileCtor(const char* fname, const char* option) {
    //std::cout<<"Trying to load file:"<<fname<<" with option "<<option<<std::endl;

    //This is necessary in order to reset the signals that root sends to jvm and cause it to crash.
    gSystem->ResetSignals();

    
    TFile *tfile = new TFile(fname,option);
    return tfile;
  }


  void TFile_Close(TFile* self) {
    self->Close();
  }

  void TFile_ls(TFile* self) {
    self->ls();
  }
  
  void TFile_delete(TFile* self) {
    if (self)
      delete self;
  }

  //void TFile_Get(TFile* self, const char* name) {
  //  
  //  TObject* o = (TObject*)self->Get(name);
  //
  //  return o; 
  //}

  TH1D* TFile_Get1DHisto(TFile* self, const char* name) {
    TH1D* h = (TH1D*) self->Get(name);
    return h;
  }

  TH2D* TFile_Get2DHisto(TFile* self, const char* name) {
    TH2D* h = (TH2D*) self->Get(name);
    return h;
  }
  
  
}
