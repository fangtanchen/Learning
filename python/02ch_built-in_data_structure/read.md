- python不需要显式声明数据类型，根据上下文语境
- 基本数据类型
    - Boolean
    - Numbers
        - Integers, Floats, Fractions
    - Strings
    - Bytes
    - Lists:有序列表
    - Tuples:有序而不可变大值序列
    - Set:无序值的包裹
    - Dictionaries: 键值对大无序包裹

- Boolean 类型
    - 上下文中，可以使用任意表达式
    - 仅 True 和 False
- Numbers类型
    - 小数点来分辨 Integer和Float
    - Integer和Float的强制转换
        - float()
        - int():直接取整
    - int可以任意大，float最高精度15位
    - Fractions: 分数类型

- 列表
    - 可以容纳任何对象，并可在添加新元素时进行动态拓展
    - 创建列表 []
    - 列表切片 L[ia:ib]
        - ia:第一个取得位置
        - ib:第一个不取的位置
    - 新增项
        - +
            - 会创建一个新的表，浪费内存
        - append
            - 添加一项
        - extend
            - 添加一个列表内容
        - insert
            - 再某位置插入元素
    - 检索
        - count
        - index
        - in
    - 删除
        - remove: 会填补缝隙
        - pop()

- 元组tuples
    - 元素不可变的列表
    - a_tuple=("a","b",1.0)
    - 与列表相互转换
        - list() 融化元祖
        - tuple()冻结列表
    - 可以同时赋多个值
- 集合
    - 无序的
    - 创建集合
        - a_set={"a","b"}
        - 由列表转换 set()
    - 修改集合
        - add()
        - update()
    - 删除元素
        - remove:删除不存在元素时KeyError
        - discard:删除不存在元素时不报错

- 字典
    - 无序键值对
    - a={'a':12,'b':"fda"}




