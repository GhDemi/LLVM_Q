//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

/*#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "hello"

STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct Hello : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    Hello() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      ++HelloCounter;
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }
  };
}

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass");

namespace {
  // Hello2 - The second implementation with getAnalysisUsage implemented.
  struct Hello2 : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    Hello2() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      ++HelloCounter;
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }

    // We don't modify the program, so we preserve all analyses.
    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.setPreservesAll();
    }
  };
}

char Hello2::ID = 0;
static RegisterPass<Hello2>
Y("hello2", "Hello World Pass (with getAnalysisUsage implemented)");*/

#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#include <Windows.h>
#include <iostream>

namespace llvm {

class NewPassHelloWorld : public PassInfoMixin<NewPassHelloWorld> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM) {
    std::cout << "[+] NewPassHelloWorld Loaded" << std::endl;
    errs() << "MyPass:";
    errs() << F.getName() << "\n";
    return PreservedAnalyses::all();
  }
  bool isRequird() { return true; }
};

} // namespace llvm
// This part is the new way of registering your pass
extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
llvmGetPassPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "NewPassHelloWorld", "v0.1",
          [](PassBuilder &PB) {
            PB.registerPipelineStartEPCallback(
                [](llvm::ModulePassManager &MPM, // clang 加载  最开始运行
                   OptimizationLevel Level) {
                  //__debugbreak();
                  Sleep(10000);
                  std::cout << "[+] registerPipelineStartEPCallback()" << std::endl;
                  FunctionPassManager FPM;
                  FPM.addPass(NewPassHelloWorld());
                  MPM.addPass(
                      createModuleToFunctionPassAdaptor(std::move(FPM)));  //转移对象

                  //到此运行应该都是正常的，由于这里把 function 适配成了 module，但是 run 里面的是 function pass，好像导致出错
                }
            );
            PB.registerPipelineParsingCallback(
                [](StringRef PassName, FunctionPassManager &FPM, ...) {
                  std::cout << "[+] registerPipelineParsingCallback" << std::endl;
                  if (PassName == "NewPassHelloWorld") {
                    FPM.addPass(NewPassHelloWorld());
                    return true;
                  }
                  return false;
                });
          }};
}

//#include "llvm/IR/PassManager.h"
//#include "llvm/Passes/PassBuilder.h"
//#include "llvm/Passes/PassPlugin.h"
//#include "llvm/Support/raw_ostream.h"
//
//using namespace llvm;
//
//#include <iostream>
//
//namespace llvm {
//
//struct NewPassHelloWorld : public PassInfoMixin<NewPassHelloWorld> {
//
//  PreservedAnalyses run(Module &F, ModuleAnalysisManager &AM) {
//    std::cout << "NewPassHelloWorld Loaded" << std::endl;
//    errs() << "MyPass:";
//    errs() << F.getName() << "\n";
//    return PreservedAnalyses::all();
//  }
//  bool isRequird() { return true; }
//};
//
//} // namespace llvm
//// This part is the new way of registering your pass
//extern "C" ::llvm::PassPluginLibraryInfo LLVM_ATTRIBUTE_WEAK
//llvmGetPassPluginInfo() {
//  return {LLVM_PLUGIN_API_VERSION, "NewPassHelloWorld", "v0.1",
//          [](PassBuilder &PB) {
//            PB.registerPipelineParsingCallback(
//                [](StringRef PassName, ModulePassManager &FPM, ...) {
//                  if (PassName == "NewPassHelloWorld") {
//                    FPM.addPass(NewPassHelloWorld());
//                    return true;
//                  }
//                  return false;
//                });
//          }};
//}
