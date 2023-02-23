#include "TFile.h"
#include "TSystem.h"

extern "C" {
  
  //  TFile* TFileCtor(const char* fname, const char* option) {
  int64_t TFileCtor() {
    //std::cout<<"Trying to load file:"<<fname<<" with option "<<option<<std::endl;
    gSystem->ResetSignals();
    TFile *tfile = new TFile("Example.root");
    return (int64_t)tfile;
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
