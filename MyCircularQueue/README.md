##循环队列

1.确定一个循环队列需要几个参数？

    2个。front与rear。

    front是指向第一个元素；rear是指向最后一个元素的下一个元素。

2.怎样判断循环队列为空？

    front与rear的值相等。

3.怎样判断循环队列已满？

    a.多定义一个参数用来统计循环队列中元素的个数。

    b.定义长度为n的循环队列中存放(n-1)个元素的时候，循环队列为满，则front与rear相邻，循环队列就满。

        if((rear+1)%数组长度 == front ){
            //满
        } else {
            //未满
        }    