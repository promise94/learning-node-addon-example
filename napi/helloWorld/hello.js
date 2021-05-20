/*
 * @Author: lixiaowei
 * @Date: 2021-03-25 17:48:17
 * @LastEditors: lixiaowei
 * @LastEditTime: 2021-05-20 14:34:46
 * @Description: file content
 * @FilePath: /node-test/napi/helloWorld/hello.js
 */
// const addon = require("./build/Release/hello.node");
// const addon = require("bindings")("hello");
const addon = require('bindings')('hello');

console.dir(addon.hello());