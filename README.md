# Nongli Library

这个库以函数的方式，帮助计算农历信息和节气信息。
可以便捷使用在日历项目的农历信息生成。

## Features

- 根据当前公历月份生成农历信息
- 根据当前年份，计算每月节气的日子

## Installation

要安装此库，可以克隆仓库或下载ZIP文件并将其添加到您的Arduino库文件夹中。

1. 克隆仓库：
   ```sh
   git clone https://github.com/JADE-Jerry/nongli.git
   ```
2. 或者下载ZIP文件并将其解压到您的Arduino库文件夹中。

## Usage

在您的项目中使用此库，请在代码中包含头文件：

```cpp
#include <nongli.h>
```

### Example

以下是如何使用此库的简单示例：

```cpp
#include <Arduino.h>
#include <nongli.h>

void setup() {
    Serial.begin(115200);

    int year = 2023;
    int month = 10;
    int lunarInfo[31]; // 假设一个月最多有31天

    nl_month_days(year, month, lunarInfo);

    Serial.println("Lunar Info:");
    for (int i = 0; i < 31; i++) {
        Serial.println(lunarInfo[i]);
    }

    int jqList[24];
    nl_year_jq(year, jqList);

    Serial.println("Solar Terms:");
    for (int i = 0; i < 24; i++) {
        Serial.println(jqList[i]);
    }
}

void loop() {
    // 您的代码
}
```

## License

此项目使用MIT许可证授权。详情请参阅LICENSE文件。

## Author

Jerry
jerry@jade-solution.com
https://github.com/JADE-Jerry