//
// Created by zahar on 25.09.2025.
//

#ifndef ASTROLLIB_TIMECONVERTER_HPP
#define ASTROLLIB_TIMECONVERTER_HPP

#include "Astrolib/Time/Time.hpp"
#include "sofa/sofa.h"

template<typename To, typename From>
struct convertImpl {
    template<typename DutContainer>
    static To convert(const From&, const DutContainer&) {}
};
// enum class Scale{TAI, TT, UTC, UT1, TDB};



/****************************From TAI to _ **************************/
template<>
struct convertImpl<Time<Scale::TT>, Time<Scale::TAI>> {
    template<typename DutContainer>
    static Time<Scale::TT> convert(const Time<Scale::TAI>& time, const DutContainer& dutContainer) {
        double tt1, tt2;
        iauTaitt(time.jdInt(), time.jdFrac(), &tt1, &tt2);
        return {tt1, tt2};
    }
};
template<>
struct convertImpl<Time<Scale::UTC>, Time<Scale::TAI>> {
    template<typename DutContainer>
    static Time<Scale::UTC> convert(const Time<Scale::TAI>& time, const DutContainer& dutContainer) {
        double utc1, utc2;
        iauTaiutc(time.jdInt(), time.jdFrac(), &utc1, &utc2);
        return {utc1, utc2};
    }
};

template<>
struct convertImpl<Time<Scale::UT1>, Time<Scale::UTC>> {
    template<typename DutContainer>
    static Time<Scale::UT1> convert(const Time<Scale::UTC>& time, const DutContainer& dutContainer) {
        double ut11, ut12;
        iauUtcut1(time.jdInt(), time.jdFrac(), dutContainer.dut(time.mjd()), &ut11, &ut12);
        return {ut11, ut12};
    }
};

template<>
struct convertImpl<Time<Scale::UT1>, Time<Scale::TAI>> {
    template<typename DutContainer>
    static Time<Scale::UT1> convert(const Time<Scale::TAI>& time, const DutContainer& dutContainer) {
        auto utc = convertImpl<Time<Scale::UTC>, Time<Scale::TAI>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::UT1>, Time<Scale::UTC>>::convert(utc, dutContainer);
    }
};
template<>
struct convertImpl<Time<Scale::TDB>, Time<Scale::TAI>> {
    template<typename DutContainer>
    static Time<Scale::TDB> convert(const Time<Scale::TAI>& time, const DutContainer& dutContainer) {
        auto ttTime = convertImpl<Time<Scale::TT>, Time<Scale::TAI>>::convert(time, dutContainer);
        return ttTime.jd() + 0.001657 * sin(9.80665);
    }
};



/**************************** From TT to _ **************************/
template<>
struct convertImpl<Time<Scale::TAI>, Time<Scale::TT>> {
    template<typename DutContainer>
    static Time<Scale::TAI> convert(const Time<Scale::TT>& time, const DutContainer& dutContainer) {
        double tai1, tai2;
        iauTttai(time.jdInt(), time.jdFrac(), &tai1, &tai2);
        return {tai1, tai2};
    }
};
template<>
struct convertImpl<Time<Scale::UTC>, Time<Scale::TT>> {
    template<typename DutContainer>
    static Time<Scale::UTC> convert(const Time<Scale::TT>& time, const DutContainer& dutContainer) {
        auto taiTime = convertImpl<Time<Scale::TAI>, Time<Scale::TT>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::UTC>, Time<Scale::TAI>>::convert(taiTime, dutContainer);;
    }
};
template<>
struct convertImpl<Time<Scale::UT1>, Time<Scale::TT>> {
    template<typename DutContainer>
    static Time<Scale::UT1> convert(const Time<Scale::TT>& time, const DutContainer& dutContainer) {
        auto utc = convertImpl<Time<Scale::UTC>, Time<Scale::TT>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::UT1>, Time<Scale::UTC>>::convert(utc, dutContainer);
    }
};
template<>
struct convertImpl<Time<Scale::TDB>, Time<Scale::TT>> {
    template<typename DutContainer>
    static Time<Scale::TDB> convert(const Time<Scale::TT>& time, const DutContainer& dutContainer) {
        return time.jd() + 0.001657 * sin(6.24+0.017202*time.jd()-2451545);
    }
};



/****************************From UTC to _ **************************/
template<>
struct convertImpl<Time<Scale::TAI>, Time<Scale::UTC>> {
    template<typename DutContainer>
    static Time<Scale::TAI> convert(const Time<Scale::UTC>& time, const DutContainer& dutContainer) {
        double tai1, tai2;
        iauUtctai(time.jdInt(), time.jdFrac(), &tai1, &tai2);
        return {tai1, tai2};
    }
};
template<>
struct convertImpl<Time<Scale::TT>, Time<Scale::UTC>> {
    template<typename DutContainer>
    static Time<Scale::TT> convert(const Time<Scale::UTC>& time, const DutContainer& dutContainer) {
        auto taiTime = convertImpl<Time<Scale::TAI>, Time<Scale::UTC>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::TT>, Time<Scale::TAI>>::convert(taiTime, dutContainer);
    }
};

template<>
struct convertImpl<Time<Scale::TDB>, Time<Scale::UTC>> {
    template<typename DutContainer>
    static Time<Scale::TDB> convert(const Time<Scale::UTC>& time, const DutContainer& dutContainer) {
        auto ttTime = convertImpl<Time<Scale::TT>, Time<Scale::UTC>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::TDB>, Time<Scale::TT>>::convert(ttTime, dutContainer);
    }
};


/**************************** From UT1 to _ **************************/
template<>
struct convertImpl<Time<Scale::UTC>, Time<Scale::UT1>> {
    template<typename DutContainer>
    static Time<Scale::UTC> convert(const Time<Scale::UT1>& time, const DutContainer& dutContainer) {
        double utc1, utc2;
        iauUt1utc(time.jdInt(), time.jdFrac(), dutContainer.dut(time.mjd()), &utc1, &utc2);
        return {utc1, utc2};
    }
};
template<>
struct convertImpl<Time<Scale::TAI>, Time<Scale::UT1>> {
    template<typename DutContainer>
    static Time<Scale::TAI> convert(const Time<Scale::UT1>& time, const DutContainer& dutContainer) {
        auto utc = convertImpl<Time<Scale::UTC>, Time<Scale::UT1>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::TAI>, Time<Scale::UTC>>::convert(utc, dutContainer);
    }
};
template<>
struct convertImpl<Time<Scale::TT>, Time<Scale::UT1>> {
    template<typename DutContainer>
    static Time<Scale::TT> convert(const Time<Scale::UT1>& time, const DutContainer& dutContainer) {
        auto utc = convertImpl<Time<Scale::UTC>, Time<Scale::UT1>>::convert(time, dutContainer);
        return convertImpl<Time<Scale::TT>, Time<Scale::UTC>>::convert(utc, dutContainer);
    }
};

template<>
struct convertImpl<Time<Scale::TDB>, Time<Scale::UT1>> {
    template<typename DutContainer>
    static Time<Scale::TDB> convert(const Time<Scale::UT1>& time, const DutContainer& dutContainer) {
        auto ttTime = convertImpl<Time<Scale::TT>, Time<Scale::UT1>>::convert(time, dutContainer);
        return  convertImpl<Time<Scale::TDB>, Time<Scale::TT>>::convert(ttTime, dutContainer);
    }
};


/****************************From TDB to _ **************************/
template<>
struct convertImpl<Time<Scale::TT>, Time<Scale::TDB>> {
    template<typename DutContainer>
    static Time<Scale::TT> convert(const Time<Scale::TDB>& time, const DutContainer& dutContainer) {
        return time.jd() - 0.001657 * sin(9.80665);
    }
};
template<>
struct convertImpl<Time<Scale::TAI>, Time<Scale::TDB>> {
    template<typename DutContainer>
    static Time<Scale::TAI> convert(const Time<Scale::TDB>& time, const DutContainer& dutContainer) {
        auto ttTime = convertImpl<Time<Scale::TT>, Time<Scale::TDB>>::convert(time, dutContainer);
        return  convertImpl<Time<Scale::TAI>, Time<Scale::TT>>::convert(ttTime, dutContainer);
    }
};
template<>
struct convertImpl<Time<Scale::UT1>, Time<Scale::TDB>> {
    template<typename DutContainer>
    static Time<Scale::UT1> convert(const Time<Scale::TDB>& time, const DutContainer& dutContainer) {
        auto ttTime = convertImpl<Time<Scale::TT>, Time<Scale::TDB>>::convert(time, dutContainer);
        return  convertImpl<Time<Scale::UT1>, Time<Scale::TT>>::convert(ttTime, dutContainer);
    }
};
template<>
struct convertImpl<Time<Scale::UTC>, Time<Scale::TDB>> {
    template<typename DutContainer>
    static Time<Scale::UTC> convert(const Time<Scale::TDB>& time, const DutContainer& dutContainer) {
        auto ttTime = convertImpl<Time<Scale::TT>, Time<Scale::TDB>>::convert(time, dutContainer);
        return  convertImpl<Time<Scale::UTC>, Time<Scale::TT>>::convert(ttTime, dutContainer);
    }
};








template<typename DutContainer>
class TimeConverter {
private:
    DutContainer dutContainer_;
public:
    TimeConverter(const DutContainer& dutContainer): dutContainer_(dutContainer){}
    template<Scale To, Scale From>
    Time<To> convert(const Time<From>& time) const {
        return convertImpl<Time<To>, Time<From>>::convert(time, dutContainer_);
    }
};



#endif //ASTROLLIB_TIMECONVERTER_HPP