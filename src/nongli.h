// 根据日期计算农历信息
//
// Author: Jerry (jerry@jade-solution.com)
// Version: 1.0.0
// 
// https://github.com/JADE-Jerry/nongli
// 
// Copyright (C) 2024-2025 JADE Software Co., Ltd.
// 
// MIT License
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __NONGLI_H__
#define __NONGLI_H__

extern const char* nl_jq_text[24];
extern const char* nl_tg_text[10]; // 天干
extern const char* nl_dz_text[12]; // 地支
extern const char* nl_sx_text[12]; // 生肖

void nl_month_days(int year, int month, int* result);
void nl_year_jq(int year, int* jqList);
int nl_tg(int year);
int nl_dz(int year);

#endif