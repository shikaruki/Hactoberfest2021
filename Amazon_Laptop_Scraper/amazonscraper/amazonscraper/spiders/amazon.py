import scrapy
from scrapy.loader import ItemLoader
from amazonscraper.items import AmazonscraperItem

class AmazonSpider(scrapy.Spider):
    name = 'amazon'
    allowed_domains = ['www.amazon.in']
    start_urls = ['https://www.amazon.in/s?k=laptops&ref=nb_sb_noss_2']

    def parse(self, response):
        products = response.css('.sg-col-12-of-20 .sg-col-inner')
        items = []
        clean_items = []
        for product in products:
            loader = ItemLoader(item=AmazonscraperItem(), selector=product)
            loader.add_css('name', '.s-line-clamp-2 .a-text-normal::text')
            loader.add_css('price', '.a-spacing-none .sg-col-inner .a-text-price .a-offscreen::text')
            loader.add_css('discprice', '.a-spacing-none .sg-col-inner .a-price-whole::text')

            t_link = product.css('.s-line-clamp-2 .a-text-normal::attr(href)').get()
            good_link = response.urljoin(t_link)

            loader.add_value('link', good_link)

            items.append(loader.load_item())

        for i in range(0, len(items), 3):
            clean_items.append(items[i])
        yield from clean_items

        next_page = response.css('li.a-last a::attr(href)').get()
        if next_page is not None:
            next_page = response.urljoin(next_page)
            yield response.follow(next_page, callback=self.parse)