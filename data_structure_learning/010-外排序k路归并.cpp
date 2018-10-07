//外排序k路归并：指生成初始归并段后，对k个初始归并段依次归并，合成一个大的归并段，反复执行k路归并可以将所有归并段合并
//算法思想：将k个归并段合并成一个大归并段
//        1、划分，并通过内部排序生成初始归并段（置换-选择排序生成初始归并段）
//        2、选定k个初始归并段，分别将每个段首读入内存
//        3、将内存中k个段首排序，选出最小元素写到输出缓存，并用同个归并段的下一个元素代替（选最小可以败者树，减少比较次数）
//        4、重复若干次选最小写出，替换至k个归并段被完全合并
//        5、重复2，3，4至所有归并段被合并（使用最佳归并树，使归并次数最少）
