package org.hps.recon.tracking.gbl; 

import com.sun.jna.Library; 
import com.sun.jna.Native; 
import com.sun.jna.Pointer; 



public class TH1DJna {

    public interface TH1DInterface extends Library {

        TH1DInterface INSTANCE = (TH1DInterface) Native.loadLibrary("rootjna", TH1DInterface.class);
        Pointer TH1DCtor(String name, String title, int bins, double xlow, double xhigh);
        int TH1D_GetEntries(Pointer self);
        
    }

    private Pointer self;


    public TH1DJna(Pointer h) {
        self = h;
    }
  
    public TH1DJna(String name, String title, int bins, double xlow, double xhigh) {

        self = TH1DInterface.INSTANCE.TH1DCtor(name,title,bins,xlow,xhigh);
    
    }


    public int getEntries() {
        return TH1DInterface.INSTANCE.TH1D_GetEntries(self);
    }
  
}
