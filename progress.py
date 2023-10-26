from __future__ import annotations
import sys
import re
from typing import TextIO

class ProgressBar(object):
    DEFAULT: str = 'Progress: %(bar)s %(percent)3d%%'
    FULL:str = '%(bar)s %(current)d/%(total)d (%(percent)3d%%) %(remaining)d to go'

    total: int
    width: int
    symbol: str
    output: TextIO
    fmt: str
    current: int

    def __init__(self: ProgressBar, total: int) -> None:

        self.total = total
        self.width = 40
        self.symbol = '='
        self.output = sys.stdout
        self.fmt = re.sub(r'(?P<name>%\(.+?\))d',
            r'\g<name>%dd' % len(str(total)), ProgressBar.DEFAULT)

        self.current = 0

    def __call__(self) -> None:
        percent = self.current / float(self.total)
        size = int(self.width * percent)
        remaining = self.total - self.current
        bar = '[' + self.symbol * size + ' ' * (self.width - size) + ']'

        args = {
            'total': self.total,
            'bar': bar,
            'current': self.current,
            'percent': percent * 100,
            'remaining': remaining
        }
        print('\r' + self.fmt % args, file=self.output, end='')

    def done(self) -> None:
        self.current = self.total
        self()
        print('', file=self.output)
