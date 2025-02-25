#include <nongli.h>

#include <math.h>

// 万年历字典
const int _LunarCalDic[] =
{
    0x04AE53, 0x0A5748, 0x5526BD, 0x0D2650, 0x0D9544, 0x46AAB9, 0x056A4D, 0x09AD42, 0x24AEB6, 0x04AE4A, /*1901-1910*/
    0x6A4DBE, 0x0A4D52, 0x0D2546, 0x5D52BA, 0x0B544E, 0x0D6A43, 0x296D37, 0x095B4B, 0x749BC1, 0x049754, /*1911-1920*/
    0x0A4B48, 0x5B25BC, 0x06A550, 0x06D445, 0x4ADAB8, 0x02B64D, 0x095742, 0x2497B7, 0x04974A, 0x664B3E, /*1921-1930*/
    0x0D4A51, 0x0EA546, 0x56D4BA, 0x05AD4E, 0x02B644, 0x393738, 0x092E4B, 0x7C96BF, 0x0C9553, 0x0D4A48, /*1931-1940*/
    0x6DA53B, 0x0B554F, 0x056A45, 0x4AADB9, 0x025D4D, 0x092D42, 0x2C95B6, 0x0A954A, 0x7B4ABD, 0x06CA51, /*1941-1950*/
    0x0B5546, 0x555ABB, 0x04DA4E, 0x0A5B43, 0x352BB8, 0x052B4C, 0x8A953F, 0x0E9552, 0x06AA48, 0x6AD53C, /*1951-1960*/
    0x0AB54F, 0x04B645, 0x4A5739, 0x0A574D, 0x052642, 0x3E9335, 0x0D9549, 0x75AABE, 0x056A51, 0x096D46, /*1961-1970*/
    0x54AEBB, 0x04AD4F, 0x0A4D43, 0x4D26B7, 0x0D254B, 0x8D52BF, 0x0B5452, 0x0B6A47, 0x696D3C, 0x095B50, /*1971-1980*/
    0x049B45, 0x4A4BB9, 0x0A4B4D, 0xAB25C2, 0x06A554, 0x06D449, 0x6ADA3D, 0x0AB651, 0x093746, 0x5497BB, /*1981-1990*/
    0x04974F, 0x064B44, 0x36A537, 0x0EA54A, 0x86B2BF, 0x05AC53, 0x0AB647, 0x5936BC, 0x092E50, 0x0C9645, /*1991-2000*/
    0x4D4AB8, 0x0D4A4C, 0x0DA541, 0x25AAB6, 0x056A49, 0x7AADBD, 0x025D52, 0x092D47, 0x5C95BA, 0x0A954E, /*2001-2010*/
    0x0B4A43, 0x4B5537, 0x0AD54A, 0x955ABF, 0x04BA53, 0x0A5B48, 0x652BBC, 0x052B50, 0x0A9345, 0x474AB9, /*2011-2020*/
    0x06AA4C, 0x0AD541, 0x24DAB6, 0x04B64A, 0x6A573D, 0x0A4E51, 0x0D2646, 0x5E933A, 0x0D534D, 0x05AA43, /*2021-2030*/
    0x36B537, 0x096D4B, 0xB4AEBF, 0x04AD53, 0x0A4D48, 0x6D25BC, 0x0D254F, 0x0D5244, 0x5DAA38, 0x0B5A4C, /*2031-2040*/
    0x056D41, 0x24ADB6, 0x049B4A, 0x7A4BBE, 0x0A4B51, 0x0AA546, 0x5B52BA, 0x06D24E, 0x0ADA42, 0x355B37, /*2041-2050*/
    0x09374B, 0x8497C1, 0x049753, 0x064B48, 0x66A53C, 0x0EA54F, 0x06B244, 0x4AB638, 0x0AAE4C, 0x092E42, /*2051-2060*/
    0x3C9735, 0x0C9649, 0x7D4ABD, 0x0D4A51, 0x0DA545, 0x55AABA, 0x056A4E, 0x0A6D43, 0x452EB7, 0x052D4B, /*2061-2070*/
    0x8A95BF, 0x0A9553, 0x0B4A47, 0x6B553B, 0x0AD54F, 0x055A45, 0x4A5D38, 0x0A5B4C, 0x052B42, 0x3A93B6, /*2071-2080*/
    0x069349, 0x7729BD, 0x06AA51, 0x0AD546, 0x54DABA, 0x04B64E, 0x0A5743, 0x452738, 0x0D264A, 0x8E933E, /*2081-2090*/
    0x0D5252, 0x0DAA47, 0x66B53B, 0x056D4F, 0x04AE45, 0x4A4EB9, 0x0A4D4C, 0x0D1541, 0x2D92B5            /*2091-2099*/
};

// 根据当前日期计算当前月每日农历，以整形数数组返回
void nl_month_days(int year, int month, int* result){
    if (year < 1900 || year > 2099 || month < 1 || month > 12) {
        return;
    }

    int daysofmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year = year + 1900;
    if (year % 4 == 0 && year % 100 != 0) {
        daysofmonth[1] = 29;
    }


    int lunarInfo = _LunarCalDic[year - 1];

    int newYearDay = lunarInfo & 0x0000001F;          // 春节公历月份
    int newYearMonth = (lunarInfo >> 5) & 0x00000003; // 春节公历日期
    int leapMonth = (lunarInfo >> 20) & 0x0000000F;   // 闰月
    if (newYearMonth > month) {
        // 还未到春节，需要根据前一年的日历数据计算（情况仅为一种：当前为一月份，而春节为二月份）
        int daysCount = newYearDay - 1 + daysofmonth[0];
        int lastLunarInfo = _LunarCalDic[year - 2];
        int lastLeapMonth = (lastLunarInfo >> 20) & 0x0000000F; // 闰月
        int isLargeMonthLast12 = (lastLunarInfo >> (7 + (lastLeapMonth > 0 ? 0 : 1))) & 0x1;
        int isLargeMonthLast11 = (lastLunarInfo >> (8 + (lastLeapMonth > 0 ? 0 : 1))) & 0x1;
        int begin = 29 + isLargeMonthLast12 + 29 + isLargeMonthLast11 - daysCount + 1;
        for (int i = 0; i < daysofmonth[0]; i++) {
            if (begin + i <= 29 + isLargeMonthLast11) {
                result[i] = 1100 + begin + i;
            } else {
                result[i] = 1200 + i + begin - 29 - isLargeMonthLast11;
            }
        }
    } else if (newYearMonth == month) {
        // 当月春节
        int lastLunarInfo = _LunarCalDic[year - 2];
        int lastLeapMonth = (lastLunarInfo >> 20) & 0x0000000F; // 闰月
        int isLastLargeMonth = (lastLunarInfo >> (7 + (lastLeapMonth > 0 ? 0 : 1))) & 0x1;
        int lastLunarDayInMonth = 29 + isLastLargeMonth;
        // 新年的农历
        for (int i = 0; i <= daysofmonth[newYearMonth - 1] - newYearDay; i++) {
            result[newYearDay + i - 1] = 100 + i + 1;
        }
        // 陈年的农历
        for (int i = 0; i < newYearDay - 1; i ++) {
            result[i] = 1200 + lastLunarDayInMonth - newYearDay + 2 + i;
        }
    } else {
        // 已过春节月份
        // 当前月份1号与春节的间隔天数
        int daysCount = -newYearDay + 1;
        for (int i = newYearMonth; i < month; i++) {
            daysCount += daysofmonth[i - 1];
        }

        int lunarMonth = 0;
        int isLargeMonth = 0;
        int lunarDayInMonth = 0;
        while (1) {
            isLargeMonth = (lunarInfo >> (19 - lunarMonth)) & 0x1;
            lunarDayInMonth = 29 + isLargeMonth;

            if (daysCount >= lunarDayInMonth) {
                daysCount -= lunarDayInMonth;
                lunarMonth++;
            } else {
                break;
            }
        }
        // Serial.printf("lunarDayInMonth: %d\n", lunarDayInMonth);
        for (int i = 0; i < daysofmonth[month - 1]; i++) {
            if (daysCount >= lunarDayInMonth) { // 进入下一个月
                daysCount -= lunarDayInMonth;
                lunarMonth++;
            }
            // lunarMonth + 1 为当前月的计数月份
            if (leapMonth == 0 || leapMonth >= lunarMonth + 1) {
                result[i] = (lunarMonth + 1) * 100 + daysCount + 1; // 无闰月或闰月未到
            } else if (leapMonth == lunarMonth) {
                result[i] = lunarMonth * -100 + daysCount + 1; // 当月闰月
            } else {
                result[i] = lunarMonth * 100 + daysCount + 1; // 已过闰月
            }

            daysCount++;

        }
    }
}

const char* nl_jq_text[24] = {
    "小寒", "大寒", "立春", "雨水", "惊蛰", "春分",
    "清明", "谷雨", "立夏", "小满", "芒种", "夏至",
    "小暑", "大暑", "立秋", "处暑", "白露", "秋分",
    "寒露", "霜降", "立冬", "小雪", "大雪", "冬至"
};

/**
 * 节气计算, 返回节气在本月的日期
 */
void nl_year_jq(int year, int* jqList) {
    if (year < 1900 || year > 2099) {
        return;
    }

    int d = year / 4;
    int m = year % 4;
    int jr = (m == 0)? (1461 * d - 1) : (1461 * d + 365 * m); // 当年第一天的积日数
    for(int i = 0; i < 24; i ++) {
        float x = 365.242 * (year) + 6.2 + 15.22 * i - 1.9 * sin(0.262*i);
        jqList[i] = (int)(x - jr);
    }
}