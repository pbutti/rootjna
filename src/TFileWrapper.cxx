#include "TFile.h"
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
  
}
