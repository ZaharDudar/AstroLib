//
// Created by zahar on 25.09.2025.
//

#ifndef ASTROLLIB_DUTCONTAINER_HPP
#define ASTROLLIB_DUTCONTAINER_HPP
#include <vector>

class BasicDutContainer {
private:
    std::vector<double> dutValues_;
    double mjdStart_;

    [[nodiscard]] double interpolate(const double f0,const double f1,const double x0,const double x1,const double x) const {
        return f0 + (f1-f0) * (x-x0) / (x1-x0);
    }
public:
    BasicDutContainer(const std::vector<double>& dutValues, const double mjdStart) : dutValues_(dutValues), mjdStart_(mjdStart) {}
    template<typename Time>
    [[nodiscard]] double dut(const Time mjd) const {
        // if ((dutValues_.size() - 1) <= mjd-mjdStart_) {
        //     return interpolate(dutValues_[dutValues_.size() - 2],
        //                        dutValues_[dutValues_.size() - 1],
        //                        dutValues_.size() - 2,
        //                        dutValues_.size() - 1,
        //                        mjd-mjdStart_);
        // }
        // else {
        if (mjd-mjdStart_ >= 0 && mjd-mjdStart_ <= (dutValues_.size()-1)) {
            auto idx = static_cast<size_t>(mjd - mjdStart_);
            return interpolate( dutValues_[idx],
                                dutValues_[idx+1],
                                idx,
                                idx+1,
                                mjd-mjdStart_ );
        }
        return 0.;
    }
};

#endif //ASTROLLIB_DUTCONTAINER_HPP