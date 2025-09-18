//
// Created by zahar on 11.09.2025.
//

#ifndef ASTROLLIB_TIME_HPP
#define ASTROLLIB_TIME_HPP


/**
 * @brief Класс времени
 *
 */
class Time
{
private:
    double jdInt_;
    double jdFrac_;
public:
    static constexpr double MJD_OFFSET = 2400000.5;
    static constexpr double SECONDS_PER_DAY = 86400;

    Time(double jd1=0, double jd2=0) noexcept{
        jdInt_=(int)jd1;
        jdFrac_=jd2 - (int)jd2 + jd1 - (int)jd1;
    }
    [[nodiscard]] double jdInt() const noexcept {return jdInt_;}
    [[nodiscard]] double jdFrac() const noexcept {return jdFrac_;}
    [[nodiscard]] double jd() const noexcept {return jdInt_ + jdFrac_;}
    [[nodiscard]] double mjd() const noexcept {return  jdInt_ - MJD_OFFSET + jdFrac_;}

    auto operator<=>(const Time& other) const noexcept = default;
};

inline double operator-(const Time& first, const Time& second) noexcept {
    if (first.jdFrac() - second.jdFrac()<=0) {
        return first.jdInt() - second.jdInt() - 1 + first.jdFrac() - second.jdFrac() + 1;
    }
    return first.jdInt() - second.jdInt() + first.jdFrac() - second.jdFrac();
}
inline Time operator+(const Time& first, const double seconds) noexcept {
    double jdFormattedSecond = seconds / Time::SECONDS_PER_DAY;
    return Time{first.jd() + jdFormattedSecond};
}

inline Time operator-(const Time& first, const double seconds) noexcept {
    double jdFormattedSecond = seconds / Time::SECONDS_PER_DAY;
    return Time{first.jd() - jdFormattedSecond};
}

#endif //ASTROLLIB_TIME_HPP