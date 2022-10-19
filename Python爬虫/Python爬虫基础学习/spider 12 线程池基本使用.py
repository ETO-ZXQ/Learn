# 使用线程池

import time
# 导入线程池模块对应的类
from multiprocessing.dummy import Pool

start_time = time.time()
def get_page(str):
    print("正在下载：",str)
    time.sleep(2)
    print("下载成功：",str)


url_list = ['baidu', 'zhihu', 'bilibili', 'sougou']

# 实例化一个线程池对象
pool = Pool(4)
# 将列表中每一个列表元素传递给get_page进行处理
pool.map(get_page, url_list)

end_time = time.time()
print(end_time - start_time)