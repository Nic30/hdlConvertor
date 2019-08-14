from utils.antlr4.grammar import Antlr4Symbol, Antlr4Sequence, iAntlr4GramElem, \
    Antlr4Option, Antlr4Iteration, Antlr4Selection


class Antlr4parser():

    def __init__(self):
        self.set_tokens([])
        
    def set_tokens(self, tokens):
        self.tokens = tokens
        self.token_it = iter(tokens)
        self.next_tmp = None
        
    def next(self) -> str:
        if self.next_tmp is not None:
            tmp = self.next_tmp
            self.next_tmp = None
            return tmp
        else:
            return next(self.token_it)

    def back(self, t):
        assert self.next_tmp is None, (self.next_tmp, t)
        self.next_tmp = t

    def from_str(self, s) -> iAntlr4GramElem:
        self.tokens = [ x.strip() for x in s.split() if x.strip()]
        self.token_it = iter(self.tokens) 
        return self._selection()
    
    def _sequence(self):
        items = []
        while True:
            try:
                o = self._any()
            except StopIteration:
                break
            items.append(o)

        if len(items) == 1:
            return items[0]
        else:
            return Antlr4Sequence(items)

    def _selection(self):
        options = []
        while True:
            try:
                o = self._sequence()
            except StopIteration:
                break
            options.append(o)
            try:
                n = self.next()
            except StopIteration:
                break
            if n != "|":
                self.back(n)
                break
        
        if not options:
            raise StopIteration()
        elif len(options) == 1:
            return options[0]
        else:
            return Antlr4Selection(options)
        
    def _group(self):
        item = self._selection()
        group_type = self.next()
        if group_type == ")":
            return item
        elif group_type == ")?":
            return Antlr4Option(item)
        elif group_type == ")*":
            return Antlr4Iteration(item, positive=False)
        elif group_type == ")+":
            return Antlr4Iteration(item, positive=True)
        else:
            raise ValueError(group_type)

    def _id(self, t):
        assert t.isidentifier(), t
        is_terminal = t[0] == "'"
        return Antlr4Symbol(t, is_terminal)
        
    def _any(self):
        t = self.next()
        if t == "(":
            return self._group()
        elif t in [")", ")?", ")*", ")+", "|"]:
            self.back(t)
            raise StopIteration()
        else:
            return self._id(t)
        

if __name__ =="__main__":
    s = """
    (
        identifier ( parameter_value_assignment )? | KW_DOLAR_UNIT
    ) ( 
        DOUBLE_COLON identifier ( parameter_value_assignment )? 
    )*"""
    
    p = Antlr4parser()
    o = p.from_str(s)
    print(o.toAntlr4())