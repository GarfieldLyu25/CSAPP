make clean & make

(base) xf@xf:~/garfieldlyu/project/CSAPP/labs/datalab-handout$ ./btest
Score   Rating  Errors  Function
 1      1       0       bitXor
 1      1       0       tmin
 1      1       0       isTmax
 2      2       0       allOddBits
 2      2       0       negate
 3      3       0       isAsciiDigit
 3      3       0       conditional
 3      3       0       isLessOrEqual
 4      4       0       logicalNeg
 4      4       0       howManyBits
 4      4       0       floatScale2
 4      4       0       floatFloat2Int
 4      4       0       floatPower2
Total points: 36/36


1️⃣ 文件结构

你需要修改的核心文件：

bits.c：你要写函数的地方
bits.h：函数声明
btest.c / tests.c / decl.c 等：测试框架，用来验证你的代码
dlc：检查你的实现是否符合位操作限制（操作符数量、禁止控制流等）
ishow / fshow：辅助工具，查看整数和浮点的二进制表示

2️⃣ 开发流程
读题和写代码
打开 bits.c，每个函数上面有要求和限制
确定你可用的操作符数量和类型

检查合法性

./dlc bits.c
./dlc -e bits.c   # 显示每个函数使用的操作符数量
dlc 会报告违规，比如使用了 if 或 * / 等
确认操作符数量没超限制

编译和测试

make btest
./btest          # 测试所有函数
./btest -f foo   # 测试指定函数 foo
./btest -f foo -1 27 -2 0xf  # 指定输入
btest 会针对每个函数跑大量测试，包括边界值
输出错误的输入和期望结果
调试技巧
对整数位操作，可以用 ishow 检查二进制
对浮点操作，用 fshow 查看 IEEE-754 位表示
3️⃣ 常用工具

ishow：

./ishow 0x27    # 查看 0x27 的十进制、二进制、符号
./ishow 27

fshow：

./fshow 0x15213243   # 查看浮点表示
./fshow 15213243

这些工具对做 float_abs, float_neg, float_i2f 特别有用。