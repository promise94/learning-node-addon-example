<!--
 * @Author: lixiaowei
 * @Date: 2021-05-20 16:54:45
 * @LastEditors: lixiaowei
 * @LastEditTime: 2021-05-20 17:24:11
 * @Description: file content
 * @FilePath: /node-test/README.md
-->

# node-addon-example

node c++插件学习

## napi

N-API 是用于构建本机插件的 API。 它独立于底层 JavaScript 运行时（例如 V8），并作为 Node.js 本身的一部分进行维护。 此 API 将是跨 Node.js 版本的应用程序二进制接口（Application Binary Interface，ABI）稳定版。 它旨在将插件与底层 JavaScript 引擎中的更改隔离开来，并允许为一个版本编译的模块在更高版本的 Node.js 上运行而无需重新编译。 插件使用本文档中概述的相同方法/工具（node-gyp 等）构建/打包。 唯一的区别是原始代码使用的 API 集。 不使用 V8 或 Node.js 的原生抽象，而是使用 N-API 中可用的功能。

## 构建

项目的顶层创建一个名为`binding.gyp`的文件，它使用一个类似于 JSON 的格式来描述模块的构建配置。该文件会被`node-gyp`使用。

```json
{
  "targets": [
    {
      "target_name": "addon",
      "sources": ["hello.cc"]
    }
  ]
}
```
