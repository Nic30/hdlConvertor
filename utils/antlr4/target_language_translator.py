

class TargetLangueTranslatorJava():

    def LA(self, index:int):
        return f"_input.LA({index})"


class TargetLangueTranslatorPython():

    def LA(self, index:int):
        return f"self.LA({index})"


class TargetLangueTranslatorCpp():

    def LA(self, index:int):
        return f"_input->LA({index})"
