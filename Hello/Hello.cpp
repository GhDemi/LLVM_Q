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
                [](llvm::ModulePassManager &MPM,
                   OptimizationLevel Level) {
                  std::cout << "[+] registerPipelineStartEPCallback()" << std::endl;
                  FunctionPassManager FPM;
                  FPM.addPass(NewPassHelloWorld());
                  MPM.addPass(
                      createModuleToFunctionPassAdaptor(std::move(FPM)));
                  //MPM.addPass(createModuleToFunctionPassAdaptor(NewPassHelloWorld()));   use this replace above is not work too
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
