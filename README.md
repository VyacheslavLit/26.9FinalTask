# 26.9FinalTask
2.	Результат работы программы.

 

 
3.	Описание результатов работы программы.

Программа сама определила количество ядер в процессоре, а также возможное количество самостоятельных потоков компилятора, с учетом количества ядер.
Как видно из результатов при подсчете 100 тысяч чисел, исполнение без много поточности выдает значительно лучший результат, также стоит отметить, что при превышении количества потоков над количеством ядер 
(то есть выполнение нескольких потоков на одном ядре) производительность падает кратно.
При 10 миллионах чисел, результаты меняются, сейчас много поточность быстрее одного потока, но не кратно количеству потоков, а незначительно меньше, также можно отметить что 10 потоков от 5 отличаются совсем не значительно, на 12%, вместо ожидаемого 2-х кратного увеличения, а при 20 потоках (то есть при превышении количества потоков над количеством ядер), результат хуже чем при 10 потоках, и примерно равен результату при 5 потоках. 

