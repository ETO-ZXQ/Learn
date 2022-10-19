import requests
from lxml import html
etree = html.etree

if __name__ == "__main__":
    # UA伪装
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.5005.63 Safari/537.36 Edg/102.0.1245.33'
    }
    # 登陆数据
    login_url = 'https://jksb.v.zzu.edu.cn/vls6sss/zzujksb.dll/login'
    login_data = {
        'uid': '202102081035',
        'upw': 'ZBH1969zxq@',
        'smbtn': '进入健康状况上报平台',
        'hh28': '754'
    }

    # 创建一个session对象
    session = requests.Session()
    # 使用session对象进行模拟登陆
    login_page_text = session.post(url=login_url, data=login_data, headers=headers).text
    print(login_page_text)




    # 本人填报
    data = {
        'did': '1',
        'door': '',
        'fun18': '381',
        # 'sid': '220609150517464678',
        'men6': 'a',
        'ptopid': 'sBFFE3D81B6BD4F2692C384F5F8CD2C46',
        # 'sid': '220609150517886560',
    }
    # 发起请求
    requests.post(url=url, data=data, headers=headers)

    # 确认填报
    sleep(3) # 先等待3秒
    data2 = {
        'myvs_1': '否',
        'myvs_2': '否',
        'myvs_3': '否',
        'myvs_4': '否',
        'myvs_5': '否',
        'myvs_7': '否',
        'myvs_8': '否',
        'myvs_9': 'x',
        'myvs_11': '否',
        'myvs_12': '否',
        'myvs_13': '否',
        'myvs_15': '否',
        'myvs_13a': '51',
        'myvs_13b': '5105',
        'myvs_13c': '合江县荔城华府',
        'myvs_24': '否',
        'myvs_26': '4',
        'memo22': '成功获取',
        'did': '2',
        'door': '',
        'day6': '',
        'men6': 'a',
        'sheng6': '',
        'shi6': '',
        'fun18': '381',
        'fun3': '',
        'jingdu': '105.827430',
        'weidu': '28.828439',
        'ptopid': 'sBFFE3D81B6BD4F2692C384F5F8CD2C46',
        # 'sid': '220609155623984456'
    }
    requests.post(url=url, data=data2, headers=headers)
