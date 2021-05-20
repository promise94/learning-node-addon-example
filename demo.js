/*
 * @Author: lixiaowei
 * @Date: 2021-03-30 19:55:09
 * @LastEditors: lixiaowei
 * @LastEditTime: 2021-03-30 20:11:05
 * @Description: file content
 * @FilePath: /node-test/demo.js
 */

/**
 * 输出给定起止日期之间的年月给定起⽌日期，返回中间所有的月份;  参数是字符串格式，格式固定用-分割；比如输入 2018-09 2019-01 ；返回数组【2018-10 2018-11 2018-12】
 */

function dataRange(startDate, endDate) {
  const result = [];
  let start = startDate.split("-");
  let end = endDate.split("-");
  if (start.length === 2 && end.length === 2) {
    console.log(start, end);
    if (start[0] > end[0] || (start[0] === end[0] && start[1] > end[1])) {
      const temp = start;
      start = end;
      end = temp;
    }
    let flag = true;
    while (flag) {
      if (start[0] == end[0] && start[1] == (end[1] - 1)) {
        flag = false;
        break;
      }

      if (start[1] == 12) {
        start[0] = start[0] * 1 + 1;
        start[1] = 0;
      }
      start[1] = start[1] * 1 + 1;
      result.push(`${start[0]}-${start[1]}`);
    }
  }



  return result;
}

console.log(dataRange('2020-10', '2021-2'));