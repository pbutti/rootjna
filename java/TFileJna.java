package test; 

import com.sun.jna.Library; 
import com.sun.jna.Native; 
import com.sun.jna.Pointer; 



public class TFileJna {

    public interface TFileInterface extends Library {

        TFileInterface INSTANCE = (TFileInterface) Native.loadLibrary("rootjna", TFileInterface.class);

        //TFile* TFileCtor(const char* fname, const char* option) {
        // not sure if I should pass a char[]
        Pointer TFileCtor(String fname, String option);
        void TFile_Close(Pointer self);
        void TFile_ls(Pointer self);
        void TFile_delete(Pointer self);
    }

    private Pointer self;

    public TFileJna(String name, String option) {

        self = TFileInterface.INSTANCE.TFileCtor(name,option);
    
    }
  
    public void close() {

        TFileInterface.INSTANCE.TFile_Close(self);
    }

    public void ls() {
        TFileInterface.INSTANCE.TFile_ls(self);
    }


    public void delete() {
        TFileInterface.INSTANCE.TFile_delete(self);
    }

}
