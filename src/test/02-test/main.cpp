//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    //创建空 umap 容器
    unordered_map<string, string> umap;

    cout << "umap 初始桶数: " << umap.bucket_count() << endl;
    cout << "umap 初始负载因子: " << umap.load_factor() << endl;
    cout << "umap 最大负载因子: " << umap.max_load_factor() << endl;

    //设置 umap 使用最适合存储 9 个键值对的桶数
    umap.reserve(3);
    cout << "*********************" << endl;
    cout << "umap 新桶数: " << umap.bucket_count() << endl;
    cout << "umap 新负载因子: " << umap.load_factor() << endl;
    //向 umap 容器添加 3 个键值对
    umap["Python教程"] = "http://c.biancheng.net/python/";
    umap["Java教程"] = "http://c.biancheng.net/java/";
    umap["Linux教程"] = "http://c.biancheng.net/linux/";

    umap["Python教程1"] = "http://c.biancheng.net/python/";
    umap["Java教程1"] = "http://c.biancheng.net/java/";
    umap["Linux教程1"] = "http://c.biancheng.net/linux/";

    umap["Python教程2"] = "http://c.biancheng.net/python/";
    umap["Java教程2"] = "http://c.biancheng.net/java/";
    umap["Linux教程2"] = "http://c.biancheng.net/linux/";

    cout << "*********************" << endl;
    cout << "umap 新桶数: " << umap.bucket_count() << endl;
    cout << "umap 新负载因子: " << umap.load_factor() << endl;
    //调用 bucket() 获取指定键值对位于桶的编号
    cout << "以\"Python教程\"为键的键值对，位于桶的编号为:" << umap.bucket("Python教程") << endl;
    //自行计算某键值对位于哪个桶
    auto fn = umap.hash_function();
    cout << "计算以\"Python教程\"为键的键值对，位于桶的编号为：" << fn("Python教程") % (umap.bucket_count()) << endl;
    return 0;
}