old_list = [1, 2, 3]
new_list = (i for i in old_list if i in old_list)
old_list = [0, 1, 2]
print(list(new_list))

# # ↑ 等价于 ↓
# old_list1 = [1, 2, 3]
# old_list2 = [0, 1, 2]
# new_list = (i for i in old_list1 if i in old_list2)
# print(list(new_list))

# PEP 289的解释：
# Only the outermost for-expression is evaluated immediately, the other expressions are deferred until the generator is run:
#
# old_list = [1, 2, 3]
#
# def __gen(a):
#     for i in a:
#         if i in old_list:
#             yield i
#
# g = __gen(iter(old_list))
# old_list = [0, 1, 2]
# print(list(g))
