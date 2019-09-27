import os


class RuleLoader():

    def __init__(self, grammar_name, rule_lines):
        self.grammar_name = grammar_name
        # name: list of rule lines
        self.rule_lines = rule_lines

    @classmethod
    def from_file(cls, file):
        rule_lines = {}
        rule_name = None
        grammar_name = None
        in_comment = False
        actual_rule_lines = []
        for line in file:
            if line.lstrip().startswith("/*"):
                in_comment = True
            if in_comment:
                if line.rstrip().endswith("*/"):
                    in_comment = False
                continue
            if not line.strip() or line.startswith("options {") or line.startswith("//"):
                continue
            if grammar_name is None:
                if line.startswith("parser grammar "):
                    grammar_name = line.split()[2]
                    if grammar_name.endswith(";"):
                        grammar_name = grammar_name[:-1]
                    continue

            if ":" in line:
                assert rule_name is None, (rule_name, line)
                rule_name = line.split(":")[0]
                assert rule_name not in rule_lines.keys()

            if ";" in line:
                assert rule_name is not None
                actual_rule_lines.append(line)
                assert line.rstrip().endswith(";")
                rule_lines[rule_name] = actual_rule_lines
                actual_rule_lines = []
                rule_name = None
            else:
                actual_rule_lines.append(line)

        assert rule_name is None
        assert len(actual_rule_lines) == 0, actual_rule_lines
        self = cls(grammar_name, rule_lines)
        return self

    @staticmethod
    def extract_rule_name(s):
        name = s.split(":")[0]
        return name.strip()


def get_rule_labels(rule_lines):
    labels = []
    for line in rule_lines:
        if "#" not in line:
            continue

        _, label = line.split("#")
        label = label.strip()
        labels.append(label)

    return labels


def gen_visitor_for_labeled_rule(labels, parser_name):
    visitor_item_template = """\
    if (dynamic_cast<%s::%s*>(ctx)) {
        return VerLiteralParser::visit%s(
                static_cast<%s::%s*>(ctx));
    }
    """
    buff = []
    for label in labels:
        context_cls_name = label + "Context"

        buff.append(visitor_item_template % (
            parser_name, context_cls_name,
            label, parser_name, context_cls_name,))
    return "\n".join(buff)


def gen_method_headers_for_labeled_rule(rule_loader, rule_name,
                                        return_t, prefix=""):
    template = """\
    %s %s visit%s(
            %s::%s *ctx);"""
    buff = []
    for label in get_rule_labels(rule_loader.rule_lines[rule_name]):
        buff.append(template % (prefix, return_t, label,
                                rule_loader.grammar_name, label + "Context"))
    return "\n".join(buff)


def gen_method_for_labeled_rule(rule_loader: RuleLoader, rule_name,
                                return_t, cls_name,
                                default_return):
    template = """\
%s %s::visit%s(
        %s::%s *ctx) {
%s
    NotImplementedLogger::print(
            "%s.visit%s",
            ctx);
    return %s;
}"""
    buff = []
    rule_lines = rule_loader.rule_lines[rule_name]

    def get_rule_lines(label):
        label_str = "#" + label
        label_lines = []
        for line in rule_lines:
            if ":" in line:
                continue

            label_lines.append(line)

            if label_str in line:
                return label_lines

            if "#" in line:
                # this label lines were for different label
                label_lines.clear()

        raise ValueError(label, rule_lines)

    for label in get_rule_labels(rule_lines):
        commented_rule = "".join(["    // " + l for l in get_rule_lines(label)])
        buff.append(template % (return_t, cls_name, label,
                                rule_loader.grammar_name, label + "Context",
                                commented_rule,
                                cls_name, label,
                                default_return))

    return "\n".join(buff)


if __name__ == "__main__":
    with open(os.path.join(os.path.dirname(__file__), "..", "grammars", "sv2017Parser.g4")) as file:
        rule_loader = RuleLoader.from_file(file)
        # print(gen_visitor_for_labeled_rule(rule_loader, "primary"))
        # print(gen_method_headers_for_labeled_rule(rule_loader, "primary",
        #                                           "hdlObjects::iHdlExpr*", prefix="static"))
        print(gen_method_for_labeled_rule(rule_loader, "primary",
                                          "hdlObjects::iHdlExpr*", "VerExprPrimaryParser",
                                          "iHdlExpr::null()"))

