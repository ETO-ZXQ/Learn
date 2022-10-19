import requests
import json
if __name__ == "__main__":
    # UA伪装：将对应的User-Agent封装到一个字典中
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 指定url
    url = 'https://movie.douban.com/j/chart/top_list'
    param = {
        'type': '11',
        'interval_id': '100:90',
        'action': '',
        'start': '0',  # 从库中的第几部电影去取
        'limit': '20',  # 一次取几个
    }
    response = requests.get(url=url, params=param, headers=headers)
    list_data = response.json()

    # 持久化存储
    fileName = './' + 'douban.json'
    fp = open(fileName, 'w', encoding='utf-8')
    json.dump(list_data, fp=fp, ensure_ascii=False)

    print('爬取完成！！！\n源数据保存成功！！！')
