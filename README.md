# Nongli Library
这个库以函数的方式，帮助计算农历信息和节气信息。
可以便捷使用在日历项目的农历信息生成。

## Features
- 根据当前公历月份生成农历信息
- 根据当前年份，计算全年节气

## Installation
要安装此库，可以克隆仓库或下载ZIP文件并将其添加到您的Arduino库文件夹中。

1. 克隆仓库：
   ```sh
   git clone https://github.com/JADE-Jerry/nongli.git
   ```
2. 或者下载ZIP文件并将其解压到您的Arduino库文件夹中。
3. 如果是使用PlatformIO开发，加入platformio.ini的库配置里面
   ```ini
   lib_deps = 
       https://github.com/JADE-Jerry/nongli.git
   ```

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

    int year = 2025;
    int month = 2;
    int lunarInfo[31]; // 假设一个月最多有31天
    nl_month_days(year, month, lunarInfo);

    Serial.print("Lunar Dates: ");
    for (int i = 0; i < 31; i++) {
        Serial.println(lunarInfo[i]);
    }
    Serial.println();
    // Lunar Dates: 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 201 0 0 0 

    int jqList[24];
    nl_year_jq(year, jqList);

    Serial.print("JieQi Dates: ");
    for (int i = 0; i < 24; i++) {
        Serial.println(jqList[i]);
    }
    Serial.println();
    // JieQi Dates: 5 20 34 49 64 79 94 110 125 141 156 172 188 203 219 235 250 266 281 296 311 326 341 355 

    int tg = nl_tg(year);
    int dz = nl_dz(year);
    Serial.println("This year: %s%s年 %s", nl_tg_text[tg], nl_dz_text[dz], nl_sx_text[dz]);
    Serial.println();
    // This year: 乙巳年 蛇
}

void loop() {
    // 您的代码
}
```

## Releases
### 1.0.1
* 增加天干、地支的计算。
### 1.0.0
* First release.

## License
此项目使用MIT许可证授权。详情请参阅LICENSE文件。

## Author
Jerry<br>
jerry@jade-solution.com<br>
https://github.com/JADE-Jerry

### ★★★库还不错，支持一下★★★
<img src="./assets/img/buymeacoffee.jpg" width="31.1%">
<img src="./assets/img/likeit.jpg" width="30%"><br>

 Copyright © 2023-2025. All Rights Reserved.