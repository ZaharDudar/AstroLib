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
    Time(double jd1=0, double jd2=0) noexcept{
        jdInt_=(int)jd1;
        jdInt_=jd2 - (int)jd2;
    }
    [[nodiscard]] double jdInt() const noexcept {return jdInt_;}
    [[nodiscard]] double jdFrac() const noexcept {return jdFrac_;}
    [[nodiscard]] double jd() const noexcept {return jdInt_ + jdFrac_;}
    [[nodiscard]] double mjd() const noexcept {return jdInt_ - 2400000 + jdFrac_;}


    static Time mjdEpoch() noexcept {return Time{2400000, 0.5};}
};

inline Time operator-(const Time& first, const Time& second) noexcept {
    if (first.jdFrac() - second.jdFrac()<=0) {
        return Time{first.jdInt() - second.jdInt() - 1, first.jdFrac() - second.jdFrac() + 1};
    }
    return Time{first.jdInt() - second.jdInt(), first.jdFrac() - second.jdFrac()};
}
inline Time operator+(const Time& first, const Time& second) noexcept {
    if (first.jdFrac() + second.jdFrac() >= 1) {
        return Time{first.jdInt() - second.jdInt() + 1, first.jdFrac() - second.jdFrac() - 1};
    }
    return Time{first.jdInt() + second.jdInt(), first.jdFrac() + second.jdFrac()};
}

#endif //ASTROLLIB_TIME_HPP