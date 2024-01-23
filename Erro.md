# Erro

- run the command

  ```
  PS E:\LLVM\build\Debug\bin> .\clang.exe -Xclang -fpass-plugin="LLVMHello.dll" E:\Temp\Windows\Desktop\test\calculate.c -o E:\Temp\Windows\Desktop\test\calculate.exe
  ```

  get erro

  ```
  [+] registerPipelineStartEPCallback()
  Assertion failed: AnalysisPasses.count(PassT::ID()) && "This analysis pass was not registered prior to being queried", file E:\LLVM\Win\OLLVM\llvm17.0.6\llvm\include\llvm/IR/PassManager.h, line 776
  PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and associated run script.
  Stack dump:
  0.      Program arguments: E:\\LLVM\\Win\\OLLVM\\build\\Debug\\bin\\clang.exe -cc1 -triple x86_64-pc-windows-msvc19.38.33134 -emit-obj -mrelax-all -mincremental-linker-compatible -dumpdir E:\\Temp\\Windows\\Desktop\\test\\calculate.exe- -disable-free -clear-ast-before-backend -main-file-name calculate.c -mrelocation-model pic -pic-level 2 -mframe-pointer=none -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -fcoverage-compilation-dir=E:\\LLVM\\Win\\OLLVM\\build\\Debug\\bin -resource-dir E:\\LLVM\\Win\\OLLVM\\build\\Debug\\lib\\clang\\17 -internal-isystem E:\\LLVM\\Win\\OLLVM\\build\\Debug\\lib\\clang\\17\\include -internal-isystem "E:\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.38.33130\\include" -internal-isystem "E:\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.38.33130\\atlmfc\\include" -internal-isystem "E:\\Windows Kits\\10\\Include\\10.0.22621.0\\ucrt" -internal-isystem "E:\\Windows Kits\\10\\Include\\10.0.22621.0\\shared" -internal-isystem "E:\\Windows Kits\\10\\Include\\10.0.22621.0\\um" -internal-isystem "E:\\Windows Kits\\10\\Include\\10.0.22621.0\\winrt" -internal-isystem "E:\\Windows Kits\\10\\Include\\10.0.22621.0\\cppwinrt" -fdebug-compilation-dir=E:\\LLVM\\Win\\OLLVM\\build\\Debug\\bin -ferror-limit 19 -fmessage-length=146 -fno-use-cxa-atexit -fms-extensions -fms-compatibility -fms-compatibility-version=19.38.33134 -fdelayed-template-parsing -fcolor-diagnostics -fpass-plugin=LLVMHello.dll -faddrsig -o E:\\Temp\\User\\calculate-8a3281.o -x c E:\\Temp\\Windows\\Desktop\\test\\calculate.c
  1.      <eof> parser at end of file
  2.      Optimizer
  Exception Code: 0x80000003
   #0 0x00007ff61f4a6515 HandleAbort (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x1a76515)
   #1 0x00007ffa9f3a90ed (C:\Windows\SYSTEM32\ucrtbased.dll+0xa90ed)
   #2 0x00007ffa9f3aae49 (C:\Windows\SYSTEM32\ucrtbased.dll+0xaae49)
   #3 0x00007ffa9f3b1345 (C:\Windows\SYSTEM32\ucrtbased.dll+0xb1345)
   #4 0x00007ffa9f3b0bd7 (C:\Windows\SYSTEM32\ucrtbased.dll+0xb0bd7)
   #5 0x00007ffa9f3aeba1 (C:\Windows\SYSTEM32\ucrtbased.dll+0xaeba1)
   #6 0x00007ffa9f3b18af (C:\Windows\SYSTEM32\ucrtbased.dll+0xb18af)
   #7 0x00007ffa33f63504 llvm::ModuleToFunctionPassAdaptor::run(class llvm::Module &, class llvm::AnalysisManager<class llvm::Module> &) (E:\LLVM\Win\OLLVM\build\Debug\bin\LLVMHello.dll+0x33504)
   #8 0x00007ffa33f55402 llvm::detail::PassModel<class llvm::Module, class llvm::ModuleToFunctionPassAdaptor, class llvm::PreservedAnalyses, class llvm::AnalysisManager<class llvm::Module>>::run(class llvm::Module &, class llvm::AnalysisManager<class llvm::Module> &) E:\LLVM\Win\OLLVM\llvm17.0.6\llvm\include\llvm\IR\PassManagerInternal.h:89:0
   #9 0x00007ff61ede4dfc llvm::PassManager<class llvm::Module, class llvm::AnalysisManager<class llvm::Module>>::run(class llvm::Module &, class llvm::AnalysisManager<class llvm::Module> &) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x13b4dfc)
  #10 0x00007ff61f95c0d8 llvm::PrettyStackTraceString::`scalar deleting dtor'(unsigned int) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x1f2c0d8)
  #11 0x00007ff61f9595ae llvm::PrettyStackTraceString::`scalar deleting dtor'(unsigned int) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x1f295ae)
  #12 0x00007ff61f946527 clang::EmitBackendOutput(class clang::DiagnosticsEngine &, class clang::HeaderSearchOptions const &, class clang::CodeGenOptions const &, class clang::TargetOptions const &, class clang::LangOptions const &, class llvm::StringRef, class llvm::Module *, enum clang::BackendAction, class llvm::IntrusiveRefCntPtr<class llvm::vfs::FileSystem>, class std::unique_ptr<class llvm::raw_pwrite_stream, struct std::default_delete<class llvm::raw_pwrite_stream>>) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x1f16527)
  #13 0x00007ff62477f599 clang::BackendConsumer::HandleTranslationUnit(class clang::ASTContext &) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x6d4f599)
  #14 0x00007ff621c090e2 clang::ParseAST(class clang::Sema &, bool, bool) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x41d90e2)
  #15 0x00007ff6203de6f9 clang::ASTFrontendAction::ExecuteAction(void) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x29ae6f9)
  #16 0x00007ff624776e6c clang::CodeGenAction::ExecuteAction(void) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x6d46e6c)
  #17 0x00007ff6203ddfe8 clang::FrontendAction::Execute(void) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x29adfe8)
  #18 0x00007ff62038777a clang::CompilerInstance::ExecuteAction(class clang::FrontendAction &) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x295777a)
  #19 0x00007ff6204bfb0e clang::ExecuteCompilerInvocation(class clang::CompilerInstance *) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x2a8fb0e)
  #20 0x00007ff61dba0138 cc1_main(class llvm::ArrayRef<char const *>, char const *, void *) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x170138)
  #21 0x00007ff61db9cadb clang::DiagnosticConsumer::EndSourceFile(void) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x16cadb)
  #22 0x00007ff61db95f10 clang_main(int, char **, struct llvm::ToolContext const &) (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x165f10)
  #23 0x00007ff61dbb48d4 main (E:\LLVM\Win\OLLVM\build\Debug\bin\clang.exe+0x1848d4)
  #24 0x00007ff623b32c69 invoke_main D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl:79:0
  #25 0x00007ff623b32b0e __scrt_common_main_seh D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl:288:0
  #26 0x00007ff623b329ce __scrt_common_main D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl:331:0
  #27 0x00007ff623b32cfe mainCRTStartup D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\exe_main.cpp:17:0
  #28 0x00007ffb2bb5257d (C:\Windows\System32\KERNEL32.DLL+0x1257d)
  #29 0x00007ffb2c5aaa58 (C:\Windows\SYSTEM32\ntdll.dll+0x5aa58)
  clang: error: clang frontend command failed due to signal (use -v to see invocation)
  clang version 17.0.6 (https://github.com/llvm/llvm-project.git 54afda0e70f83cb45212a100f21e887d07253be7)
  Target: x86_64-pc-windows-msvc
  Thread model: posix
  InstalledDir: E:\LLVM\Win\OLLVM\build\Debug\bin
  clang: note: diagnostic msg:
  ********************
  
  PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:
  Preprocessed source(s) and associated run script(s) are located at:
  clang: note: diagnostic msg: E:\Temp\User\calculate-d27eda.c
  clang: note: diagnostic msg: E:\Temp\User\calculate-d27eda.sh
  clang: note: diagnostic msg:
  
  ********************
  ```

- run command

  ```
  .\opt.exe --load-pass-plugin=./LLVMHello.dll --passes='NewPassHelloWorld' E:\Temp\Windows\Desktop\test\a.ll -o E:\Temp\Windows\Desktop\test\a.ll
  ```

  just get

  ```
  [+] registerPipelineParsingCallback
  [+] registerPipelineParsingCallback
  ```

  

