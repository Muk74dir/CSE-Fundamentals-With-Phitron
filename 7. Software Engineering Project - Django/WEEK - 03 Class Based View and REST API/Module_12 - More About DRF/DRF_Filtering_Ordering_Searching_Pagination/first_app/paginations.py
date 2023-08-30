from rest_framework.pagination import PageNumberPagination, LimitOffsetPagination, CursorPagination

class ProductPagination(PageNumberPagination):
    page_size = 2 # Total Page
    page_query_param = 'p'
    page_size_query_param = 'size' # content number in a page 
    max_page_size  = 5
    
class ProductLimitOffsetPagination(LimitOffsetPagination):
    default_limit = 2
    limit_query_param = 'l'
    offset_query_param = 'start'
    max_limit = 3

class ProductCursorPagination(CursorPagination):
    page_size = 3
    ordering = 'price' 
    cursor_query_param = 'data'