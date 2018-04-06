; ModuleID = 'D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c'
target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-n32-S64"
target triple = "armv7-none--eabi"

; Function Attrs: nounwind
define void @copy_buffer(i32* %input, i32* %output) #0 {
  %1 = alloca i32*, align 4
  %2 = alloca i32*, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %index = alloca i32, align 4
  store i32* %input, i32** %1, align 4
  call void @llvm.dbg.declare(metadata !{i32** %1}, metadata !21), !dbg !22
  store i32* %output, i32** %2, align 4
  call void @llvm.dbg.declare(metadata !{i32** %2}, metadata !23), !dbg !24
  call void @llvm.dbg.declare(metadata !{i32* %i}, metadata !25), !dbg !26
  call void @llvm.dbg.declare(metadata !{i32* %j}, metadata !27), !dbg !28
  call void @llvm.dbg.declare(metadata !{i32* %index}, metadata !29), !dbg !30
  store i32 0, i32* %i, align 4, !dbg !31
  br label %3, !dbg !31

; <label>:3                                       ; preds = %26, %0
  %4 = load i32* %i, align 4, !dbg !33
  %5 = icmp ult i32 %4, 1080, !dbg !33
  br i1 %5, label %6, label %29, !dbg !33

; <label>:6                                       ; preds = %3
  store i32 0, i32* %j, align 4, !dbg !36
  br label %7, !dbg !36

; <label>:7                                       ; preds = %22, %6
  %8 = load i32* %j, align 4, !dbg !39
  %9 = icmp ult i32 %8, 1920, !dbg !39
  br i1 %9, label %10, label %25, !dbg !39

; <label>:10                                      ; preds = %7
  %11 = load i32* %i, align 4, !dbg !42
  %12 = mul i32 1920, %11, !dbg !42
  %13 = load i32* %j, align 4, !dbg !42
  %14 = add i32 %12, %13, !dbg !42
  store i32 %14, i32* %index, align 4, !dbg !42
  %15 = load i32* %index, align 4, !dbg !44
  %16 = load i32** %1, align 4, !dbg !44
  %17 = getelementptr inbounds i32* %16, i32 %15, !dbg !44
  %18 = load i32* %17, align 4, !dbg !44
  %19 = load i32* %index, align 4, !dbg !44
  %20 = load i32** %2, align 4, !dbg !44
  %21 = getelementptr inbounds i32* %20, i32 %19, !dbg !44
  store i32 %18, i32* %21, align 4, !dbg !44
  br label %22, !dbg !45

; <label>:22                                      ; preds = %10
  %23 = load i32* %j, align 4, !dbg !46
  %24 = add i32 %23, 1, !dbg !46
  store i32 %24, i32* %j, align 4, !dbg !46
  br label %7, !dbg !46

; <label>:25                                      ; preds = %7
  br label %26, !dbg !47

; <label>:26                                      ; preds = %25
  %27 = load i32* %i, align 4, !dbg !48
  %28 = add i32 %27, 1, !dbg !48
  store i32 %28, i32* %i, align 4, !dbg !48
  br label %3, !dbg !48

; <label>:29                                      ; preds = %3
  ret void, !dbg !49
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata) #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }

!llvm.dbg.cu = !{!0}
!xidane.fname = !{!11, !12}
!xidane.function_argument_annotation = !{!11, !13}
!xidane.function_declaration_type = !{!11, !14}
!xidane.function_declaration_filename = !{!11, !15}
!xidane.ExternC = !{!11}
!llvm.module.flags = !{!16, !17, !18, !19}
!llvm.ident = !{!20}

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"clang version 3.5.0 (tags/RELEASE_350/final)", i1 false, metadata !"", i32 0, metadata !2, metadata !2, metadata !3, metadata !2, metadata !2, metadata !"", i32 1} ; [ DW_TAG_compile_unit ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/../src\copy_buffer.c] [DW_LANG_C99]
!1 = metadata !{metadata !"../src\5Ccopy_buffer.c", metadata !"D:\5CCoding\5CFPGA\5Cworkplace\5Ccnn_simple\5CDebug"}
!2 = metadata !{}
!3 = metadata !{metadata !4}
!4 = metadata !{i32 786478, metadata !5, metadata !6, metadata !"copy_buffer", metadata !"copy_buffer", metadata !"", i32 9, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (i32*, i32*)* @copy_buffer, null, null, metadata !2, i32 9} ; [ DW_TAG_subprogram ] [line 9] [def] [copy_buffer]
!5 = metadata !{metadata !"D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c", metadata !"D:\5CCoding\5CFPGA\5Cworkplace\5Ccnn_simple\5CDebug"}
!6 = metadata !{i32 786473, metadata !5}          ; [ DW_TAG_file_type ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!7 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!8 = metadata !{null, metadata !9, metadata !9}
!9 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 32, i64 32, i64 0, i32 0, metadata !10} ; [ DW_TAG_pointer_type ] [line 0, size 32, align 32, offset 0] [from unsigned int]
!10 = metadata !{i32 786468, null, null, metadata !"unsigned int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ] [unsigned int] [line 0, size 32, align 32, offset 0, enc DW_ATE_unsigned]
!11 = metadata !{void (i32*, i32*)* @copy_buffer}
!12 = metadata !{metadata !"copy_buffer"}
!13 = metadata !{metadata !"input,2073600,,PHYSICAL_CONTIGUOUS.NON_CACHEABLE,,AFI,0,copy,,, output,2073600,,PHYSICAL_CONTIGUOUS.NON_CACHEABLE,,AFI,0,copy,,, "}
!14 = metadata !{metadata !"void.unsigned int *.1.unsigned int *.1"}
!15 = metadata !{metadata !"../src/copy_buffer.h"}
!16 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!17 = metadata !{i32 2, metadata !"Debug Info Version", i32 1}
!18 = metadata !{i32 1, metadata !"wchar_size", i32 4}
!19 = metadata !{i32 1, metadata !"min_enum_size", i32 4}
!20 = metadata !{metadata !"clang version 3.5.0 (tags/RELEASE_350/final)"}
!21 = metadata !{i32 786689, metadata !4, metadata !"input", metadata !6, i32 16777225, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [input] [line 9]
!22 = metadata !{i32 9, i32 33, metadata !4, null}
!23 = metadata !{i32 786689, metadata !4, metadata !"output", metadata !6, i32 33554441, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [output] [line 9]
!24 = metadata !{i32 9, i32 56, metadata !4, null}
!25 = metadata !{i32 786688, metadata !4, metadata !"i", metadata !6, i32 10, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [i] [line 10]
!26 = metadata !{i32 10, i32 11, metadata !4, null}
!27 = metadata !{i32 786688, metadata !4, metadata !"j", metadata !6, i32 10, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [j] [line 10]
!28 = metadata !{i32 10, i32 13, metadata !4, null}
!29 = metadata !{i32 786688, metadata !4, metadata !"index", metadata !6, i32 11, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [index] [line 11]
!30 = metadata !{i32 11, i32 11, metadata !4, null}
!31 = metadata !{i32 12, i32 6, metadata !32, null}
!32 = metadata !{i32 786443, metadata !5, metadata !4, i32 12, i32 2, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!33 = metadata !{i32 12, i32 6, metadata !34, null}
!34 = metadata !{i32 786443, metadata !5, metadata !35, i32 12, i32 6, i32 2, i32 7} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!35 = metadata !{i32 786443, metadata !5, metadata !32, i32 12, i32 6, i32 1, i32 4} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!36 = metadata !{i32 13, i32 7, metadata !37, null}
!37 = metadata !{i32 786443, metadata !5, metadata !38, i32 13, i32 3, i32 0, i32 2} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!38 = metadata !{i32 786443, metadata !5, metadata !32, i32 12, i32 29, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!39 = metadata !{i32 13, i32 7, metadata !40, null}
!40 = metadata !{i32 786443, metadata !5, metadata !41, i32 13, i32 7, i32 2, i32 6} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!41 = metadata !{i32 786443, metadata !5, metadata !37, i32 13, i32 7, i32 1, i32 5} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!42 = metadata !{i32 15, i32 4, metadata !43, null}
!43 = metadata !{i32 786443, metadata !5, metadata !37, i32 13, i32 29, i32 0, i32 3} ; [ DW_TAG_lexical_block ] [D:\Coding\FPGA\workplace\cnn_simple\Debug/D:/Coding/FPGA/workplace/cnn_simple/src/copy_buffer.c]
!44 = metadata !{i32 16, i32 4, metadata !43, null}
!45 = metadata !{i32 17, i32 3, metadata !43, null}
!46 = metadata !{i32 13, i32 25, metadata !37, null}
!47 = metadata !{i32 18, i32 2, metadata !38, null}
!48 = metadata !{i32 12, i32 25, metadata !32, null}
!49 = metadata !{i32 19, i32 1, metadata !4, null}
