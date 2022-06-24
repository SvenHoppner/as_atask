#ifndef __ALI_AS_TRACKLET_H__
#define __ALI_AS_TRACKLET_H__

#include "TObject.h"
#include "TVector3.h"

class Ali_AS_Tracklet : public TObject {
   private:
    // Tracklet properties
    Short_t detector;
    TVector3 TV3_offset;
    TVector3 TV3_dir;
    Double_t online_dy;

   public:
    // constructor
    Ali_AS_Tracklet() : detector(0), TV3_offset(), TV3_dir(), online_dy() {}

    // destructor
    ~Ali_AS_Tracklet() {}

    // setters
    void set_detector(Short_t s) { detector = s; }
    void set_TV3_offset(TVector3 tv3) { TV3_offset = tv3; }
    void set_TV3_dir(TVector3 tv3) { TV3_dir = tv3; }
    void set_online_dy(Double_t dy) { online_dy = dy; }

    // getters
    Short_t get_detector() const { return detector; }
    TVector3 get_TV3_offset() const { return TV3_offset; }
    TVector3 get_TV3_dir() const { return TV3_dir; }
    Double_t get_online_dy() const { return online_dy; }

    ClassDef(Ali_AS_Tracklet, 1);  // A simple track of a particle
};

#endif
