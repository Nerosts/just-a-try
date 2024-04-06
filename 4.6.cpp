# 数据
years = [2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022]
total_relief = [4172.6, 4926.3, 5375.6, 5829.8, 5925.4, 5969.7, 5998.3, 5810.8, 5484.1, 5143.6, 4573.8, 4030.9, 3931.9, 4099.4, 3941.9, 3799.9]
subsistence_allowance = [3566.3, 4305.5, 4760.0, 5214.0, 5305.7, 5344.5, 5388.0, 5207.2, 4903.6, 4586.5, 4045.2, 3519.1, 3455.4, 3620.8, 3474.5, 3349.6]
centralized_living = [138.0, 155.6, 171.8, 177.4, 184.5, 185.3, 183.5, 174.3, 162.3, 139.7, 99.6, 86.2, 75.0, 73.9, 69.2, 64.4]
decentralized_living = [393.3, 393.0, 381.6, 378.9, 366.5, 360.3, 353.8, 354.8, 354.4, 357.2, 367.2, 368.8, 364.1, 372.4, 368.1, 370.1]
traditional_relief = [75.0, 72.2, 62.2, 59.5, 68.7, 79.6, 73.0, 74.5, 63.8, 60.2, 61.8, 56.8, 37.4, 32.3, 30.1, 15.8]

# 绘图
plt.figure(figsize = (10, 6))
plt.plot(years, total_relief, marker = 'o', label = 'Total Relief')
plt.plot(years, subsistence_allowance, marker = 'o', label = 'Subsistence Allowance')
plt.plot(years, centralized_living, marker = 'o', label = 'Centralized Living')
plt.plot(years, decentralized_living, marker = 'o', label = 'Decentralized Living')
plt.plot(years, traditional_relief, marker = 'o', label = 'Traditional Relief')

# 添加标题和标签
plt.title('Statistics on Social Assistance for Rural Residents')
plt.xlabel('Year')
plt.ylabel('Number of Persons (10,000)')

# 添加图例
plt.legend()

# 显示图形
plt.grid(True)
plt.show()
#define _CRT_SECURE_NO_WARNINGS 1