#pragma once


#include "AST.h"
#include "helper.h"
#include "Target.h"

namespace CppParser {
    using namespace CppParser::AST;
    struct CppParserOptions {
        CppParserOptions();
        ~CppParserOptions();

        VECTOR_STRING(Arguments)
        std::string libraryFile;

        VECTOR_STRING(SourceFiles)

        VECTOR_STRING(IncludeDirs)
        VECTOR_STRING(SystemIncludeDirs)
        VECTOR_STRING(Defines)
        VECTOR_STRING(Undefines)
        VECTOR_STRING(LibraryDirs)
        VECTOR_STRING(SupportedStdTypes)

        ASTContext * ASTContext;

        int toolSetToUse;
        std::string targetTriple;
        std::string currentDir;
        CppAbi abi;

        bool noStandardIncludes;
        bool noBuiltinIncludes;
        bool microsoftMode;
        bool verbose;
        bool unityBuild;

    };

    enum class ParserDiagnosticLevel {
        Ignored,
        Note,
        Warning,
        Error,
        Fatal
    };

    struct ParserDiagnostic{
        ParserDiagnostic();
        ParserDiagnostic(const ParserDiagnostic&);
        std::string fileName;
        std::string message;
        ParserDiagnosticLevel level;
        int lineNumber;
        int columnNumber;
    };

    enum class ParserResultKind {
        Success,
        Error,
        FileNotFound
    };

    class Parser;

    struct ParserResult {
        ParserResult();
        ParserResult(const ParserResult&);
        ~ParserResult();

        ParserResultKind kind;
        VECTOR(ParserDiagnostic,Diagnostics)

        NativeLibrary* library;
        ParserTargetInfo* targetInfo;
        Parser* codeParser;
    };

    enum class SourceLocationKind {
        Invalid,
        Builtin,
        CommandLine,
        System,
        User
    };

    class ClangParser {
    public:
        static ParserResult* ParseHeader(CppParserOptions* Opts);
        static ParserResult* ParseLibrary(CppParserOptions* Opts);
    };
}



