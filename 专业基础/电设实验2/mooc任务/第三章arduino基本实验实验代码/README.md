How to build PlatformIO based project
=====================================

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-atmelavr/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-atmelavr/examples/arduino-external-libs

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Clean build files
$ pio run --target clean
```


本项目包括mooc第三章的三个小实验，完整代码分别在lib里面。lm35是温度传感器实验，lcd是液晶显示屏实验，relay是继电器实验。三个实验的代码都可以顺利单独运行，跑之前把文件放到src里面并改成main.cpp就行。