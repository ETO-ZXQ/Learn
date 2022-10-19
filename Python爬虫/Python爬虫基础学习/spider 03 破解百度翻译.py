import requests
import json
if __name__ == "__main__":
    # UA伪装：将对应的User-Agent封装到一个字典中
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 指定url
    post_url = 'https://fanyi.baidu.com/sug'

    # post请求参数处理（同get请求一致 ）：封装到字典中
    word = input('enter a word:')
    data = {
        'kw': word
    }
    # 发送请求
    response = requests.post(url=post_url, data=data, headers=headers)
    # 获取响应数据:json()方法返回的是obj(确认响应数据是josn类型才行)
    dic_obj = response.json()
    # print(dic_obj, type(dic_obj))

    # 数据处理打印
    word_list = dic_obj.get('data')
    for d in word_list:
        key = d.get('k')
        value = d.get('v')
        print(key)
        print('\t', value)


    # 持久化存储
    fileName = './'+word+'_source.json'
    fp = open(fileName, 'w', encoding='utf-8')
    json.dump(dic_obj, fp=fp, ensure_ascii=False)

    print('爬取完成！！！\n源数据保存成功！！！')
