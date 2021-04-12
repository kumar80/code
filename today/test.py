import unittest
from day import *


class TestSum(unittest.TestCase):

    def test_list_int(self):
        d = [{'2020-01-01': 4, '2020-01-02': 4, '2020-01-03': 6, '2020-01-04': 8, '2020-01-05': 2,
              '2020-01-06': -6, '2020-01-07': 2, '2020-01-08': -2}, {'2020-01-01': 6, '2020-01-04': 12, '2020-01-05': 14,
                                                                     '2020-01-06': 2, '2020-01-07': 4}]

        d_ans = [{'Sun': 2,
                  'Mon': -6,
                  'Tue': 2,
                  'Wed': 2,
                  'Thu': 4,
                  'Fri': 6,
                  'Sat': 8}, {'Sun': 14,
                              'Mon': 2,
                              'Tue': 4,
                              'Wed': 6,
                              'Thu': 8,
                              'Fri': 10,
                              'Sat': 12}]

        for i in range(2):
            with self.subTest(i=i):
                res = sum(d[i])
                self.assertDictEqual(res, d_ans[i])


if __name__ == '__main__':

    unittest.main()
