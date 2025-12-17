# C语言与嵌入式代码积累仓库

![C语言](https://img.shields.io/badge/language-C-blue)
![嵌入式](https://img.shields.io/badge/platform-Embedded-green)
![License](https://img.shields.io/badge/license-MIT-blue)

一个用于积累和整理C语言编程经验及嵌入式系统开发的代码仓库。

## 🚀 快速开始

```bash
# 克隆仓库
git clone https://github.com/YOUR_USERNAME/c-embedded-collection.git
cd c-embedded-collection

# 编译示例
mkdir build && cd build
cmake .. && make

├── src/                          # 源代码
│   ├── embedded/                # 嵌入式组件
│   │   ├── timers/             # 定时器(软件定时器、硬件定时器)
│   │   ├── buffers/            # 缓冲区(环形缓冲区、FIFO)
│   │   ├── state_machines/     # 状态机实现
│   │   ├── rtos/               # RTOS相关(FreeRTOS、RT-Thread)
│   │   └── protocols/          # 通信协议(自定义协议解析)
│   ├── algorithms/             # 算法实现
│   ├── data_structures/        # 数据结构
│   ├── system/                 # 系统编程
│   ├── drivers/                # 设备驱动模型
│   └── utils/                  # 工具函数
├── include/                     # 公共头文件
├── tests/                       # 测试代码
├── docs/                        # 文档
├── examples/                    # 使用示例
├── projects/                    # 完整项目示例
├── scripts/                     # 构建和工具脚本
└── build/                       # 构建输出目录
