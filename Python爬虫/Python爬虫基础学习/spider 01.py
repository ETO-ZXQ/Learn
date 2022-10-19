# 爬取搜狗首页
import requests
if __name__ == '__main__':
    # 01 指定url
    url = "https://www.sogou.com/"

    # 02 发起请求
    # get 方法返回一个响应对象
    response = requests.get(url=url)
    # 03 获取响应数据（text返回的是字符串形式的响应数据）
    page_text = response.text
    # print(page_text) print(type(response),end='\n')
    # 04 持久化存储
    with open("./sougou.html", 'w', encoding='utf-8') as fp:
        fp.write(page_text)
    print("爬取数据结束！！！")


