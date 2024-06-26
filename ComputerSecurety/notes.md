## 计算机安全
#### 定义
- nsit标准fips 99
- 计算机的容易遭受各种威胁的资产，以及保护这些遭受的资产所采取的各种措施 
- 组成cia(三元组)
    - 机密性  保持对信息的访问，和纰漏的限制，指的是非授权信息泄露
        - 学生成绩可以看做是一个资产，在美国受到家庭教育权利及隐私法的约束
        - 学生注册信息可以看做是一个中等机密信息，只能公开给需要此信息工作的机构
        - 学校名录可以看做是一个低级信息或不上等级，可以完全公开
    - 完整性  非授权的信息修改和破坏
        - 如医院病人数据 高级  论坛中级
    - 可用性 对信息和信息系统的访问和使用的破坏
- 真实性 验证身份与其声明的一致，保证输入的信息都是可信的
- 可说明性 安全目标要求实体目标可以被唯一的追踪
- 对安全违规的机构或个人根据造成的影响分为3类:
    - 低级:带来有限的负面影响
        - 会在任务处理能力少许退化，即使完成了主要职责
        - 导致少许的机构资产破坏
        - 导致少许的财务损失
        - 导致对个人到少许危害
    - 中级:带来严重的负面影响
        - 明显
    高级:
        - 不能完成一个或多个主要职责
        - 严重
需要充分理解这些机制，需要大量的推理论证
在开发某种安全机制时需要充分考虑这些特征的潜在威胁
无论是在物理层面还是逻辑层面都需要考虑
计算机系统资产包括:
硬件，软件，数据，通讯设施和网络

- 利用系统脆弱性产生的威胁，攻击是实施的危害，执行攻击的被称为攻击者
- 攻击分为两类：
    - 主动攻击 改变系统资源或影响其运行
    - 被动攻击 监听或窃取信息
    - 内部攻击 有权限访问资产但非经授权许可使用资源的内部实体
    - 外部攻击 系统安全边界外部的非授权用户发起攻击
- 对策是对付攻击所采取的任何手段，对策应该可以成功阻止特定类型的攻击，当阻止不可能时应该能检测攻击，并从攻击中恢复，执行完对策后可能还会存留风险。
- 威胁：
    - 非授权泄露
        - 入侵
        - 截获
        - 暴露
        - 推理
    - 欺骗：
        - 冒充
        - 抵赖
        - 伪造
    - 破坏：
        - 失能 通过禁用系统组件来阻止
        - 损坏 对系统功能或数据的不利修改来对系统运行进行非期望的改变
        - 阻碍 阻止系统运行或数据传输
    - 篡夺：
        - 盗用 对系统资源采取非授权的逻辑或物理控制
        - 误用 导致系统组件执行对系统安全有害的服务

攻击面和攻击树
- 攻击面：系统中可到达的和可利用的脆弱点构成的
  - 网络攻击面
  - 软件攻击面
  - 人为供给面
- 攻击树：
    - 安全事件是这个树的根节点，攻击者可以迭代的到达这个目标的就是子节点 从子节点到根节点就是攻击路径
    - 与节点 当想达成目标时需要所有子节点被实现
    - 或节点 若想达成完成其中至少一个子目标即可
- 认证相关部分：
    - 用户终端和用户(UT/U)：用户设备作为攻击目标
    - 通信信道(CC): 通信信道作为攻击目标
    - 服务器:针对服务器进行离线攻击
    - 五类攻击可以被识别，每种攻击都利用了以上三个中的一个或多个：
        - 获取用户凭证
        - 命令注入
        - 猜测用户凭证
        - 安全策略违反
        - 利用已知的认证会话
- 安全设计原则：
    - 安全缺省设置 默认情况不允许访问，除非有明确授权，，确保了系统在缺省情况下是安全的，只有在明确允许的情况下才会授予访问权限。这符合安全缺省的原则，减少了因未处理异常情况而导致安全漏洞的风险。
    - 经济机制原则 确保安全机制的效率，在保证安全的同时，尽可能减少系统开销。
    - 绝对中介原则 每一次访问都应依据访问控制机制，而非缓存
    - 开放式设计原则 公开加密算法，这样能被许多专家审查
    - 特权分离原则 对限定资源的访问需要多特权属性的情况定义
    - 最小特权原则 每个用户和进程都应被分配一个最小的特权集
    - 最小共用机制原则 最小化不同用户共享的功能
    - 心里可接受性原则 安全机制不应该过度干涉用户的工作
    - 隔离原则 
        - 公共访问资源应与重要资源分离
        - 用户之间的进程和文件应分离
        - 安全机制也应当被隔离
    - 封装原则 基于面向对象功能的一种特殊形式隔离
    - 模块化原则 将安全功能开发成分离的，受保护的模块
    - 分层原则 使用多重的、重叠的保护办法
    - 最小惊动原则  程序的响应方式应当不出乎用户的意料
----

**时间和类型攻击（Time-of-Check-to-Time-of-Use，TOCTTOU）**：
- 在执行安全策略检查时，检查的时间和执行安全策略检查的时间之间存在窗口，攻击者可以在这个窗口中修改策略，使策略检查失败
- 避免缺陷: 当访问数据时不可修改数据
---- 

## 密码学：
#### 对称加密：提供机密性服务
- 五个基本成分
    - 明文
    - 加密算法
    - 秘密密钥 加密算法的输入，算法所特定的代换和变化依赖于密钥
    - 密文
    - 解密算法 加密算法的逆运算
- 需要满足的要求：
1. 加密算法足够强，敌手拥有一定数量的密文和明文也破译不出密钥
1. 发送者和接收者必须在安全的形势下获得秘密密钥

- 攻击方式：
1. 密码分析学：根据算法特征推导出密钥
1. 蛮力攻击：穷举所有可能的密钥

- 对称分组加密算法：
    - 将定长的明文转换成等长的密文
    - 将敏文划分为一系列定长的块，DES，3DES，AES都使用分组密码
    - DES采用 64位明文和54位密钥加密，其实质是64位密钥，8位用于差错检测
    - 3DES采用64位明文和112或168位密钥加密
    - AES采用128位明文和128，128、192或256位密钥加密
- 数据加密标准

- 高级加密标准
- 3DES: 3DES是DES的扩展,重复基本的DES算法三次
#### 散列函数： 提供消息认证
#### 非对称加密：数字签名和密钥管理

