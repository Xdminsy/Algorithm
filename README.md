# Algorithm

觉的自用刷题项目。

使用 cmake 管理项目，可以使用 clion/visual studio/vscode 进行代码编辑与运行。

使用 cmake 的 `file(GLOB_RECURSE)` 获取每一个 src 下的文件并各自生成一个 Executable target，可以在每一个源文件内写 main 函数并编译运行。

但是由于这种方法的局限性，每次添加新的文件需要 reconfigure，才能让 ide 知悉新的 target 并且运行，`glob` 的 `CONFIGURE_DEPENDS` 选项可以在 `cmake --build` 的时候重新 glob 文件，但是经过尝试 IDE 重新 build 并没有得知新的 target，所以还是得每次添加文件之后 reconfigure 一下，然后就可以使用 IDE 愉快地运行当前编辑文件了。