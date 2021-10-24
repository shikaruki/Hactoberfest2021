# Amazon_Laptop_Scraper

A script to scrap all the laptop information from Amazon website.
I used scrapy a useful python web scraping framework to scrap any website with very ease.
This python web crawler, crawl all the links of laptop products and store all the specified information about that products in json file.


# Technology Used

scrapy

Request Module

Restful APIs 


# Run From the Terminal

Run ```C:\Users\your_user_name\Amazon_Laptop_Scraper> cd amazonscraper```

Run ```scrapy crawl amazon```

If you want to store the info into json file then,

Run ```scrapy crawl amazon -o filename.json```

If you want to store the info into csv file then,

Run ```scrapy crawl amazon -o filename.csv```


# Output

This python script runs and output a json or csv file what ever you choose.
This json or csv file contains item price, discount price and link to that product. 

## json file'''

{"name": "HP 15 (2021) Thin & Light 10th Gen Intel Core i3 Laptop, 8GB RAM, 512GB SSD, 39.62 cms (15.6\") FHD Screen, Windows 10, MS Office, Jet Black (15s-du1516TU)", "price": "49,999", "discprice": "41,990", "link": "https://www.amazon.in/HP-Laptop-Screen-Windows-15s-du1516TU/dp/B095YC5VH4?dchild=1"},
{"name": "Dell 15 (2021) Laptop i3-1115G4, 8GB, 256GB SSD, Win 10 + MS Office, Integrated Graphics, 15.6\" (39.61 cms) FHD Display, Carbon Color (Inspiron 3511, D560581WIN9BE)", "price": "56,776", "discprice": "41,990", "link": "https://www.amazon.in/Dell-i3-1115G4-Integrated-3511-D560581WIN9BE/dp/B09F3QP9JS?dchild=1"},
{"name": "Dell 15 (2021) i3-1005G1 Laptop, 8GB, 256GB SSD, Win 10 + MS Office, Integrated Graphics, 15.6\" (39.62 cms) FHD Display, Accent Black (Inspiron 3511, D560496WIN9BE)", "price": "55,534", "discprice": "38,990", "link": "https://www.amazon.in/Dell-i3-1005G1-Integrated-3511-D560496WIN9BE/dp/B09F3QG7ZJ?dchild=1"},
{"name": "Lenovo IdeaPad Slim 3 10th Gen Intel Core i3 15.6\" (39.62cm) HD Thin & Light Laptop (8GB/256GB SSD/Win10/MS/Platinum Grey/1.85Kg), 81WE01P5IN + 15.6\" Slim Backpack.", "link": "https://www.amazon.in/Lenovo-IdeaPad-Platinum-81WE01P5IN-Backpack/dp/B09HCH6YF2?dchild=1"},
{"name": "AVITA Cosmos 2 in 1 Celeron Dual Core - (4 GB/64 GB EMMC Storage/Windows 10 Home) NS12T5IN021P 2 in 1 Laptop (11.6 inch, Charcoal Grey, 1.327 kg)", "price": "23,490", "discprice": "16,990", "link": "https://www.amazon.in/AVITA-Cosmos-Celeron-Dual-Core/dp/B09HKBR46P?dchild=1"},

## '''

# Author
https://github.com/das88768
