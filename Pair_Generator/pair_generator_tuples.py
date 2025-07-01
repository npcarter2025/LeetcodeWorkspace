class PairGeneratorTuples:
    def __init__(self):
        self.pair_history = set()

    def generator_pairs(self, student_ids):

        n = len(student_ids)
        assigned = set()
        pairs = []

        for s1 in range(n):
            if student_ids[s1] in assigned:
                continue

            for s2 in range(s1 + 1, n):
                if student_ids[s2] in assigned:
                    continue

                pair = tuple(sorted((student_ids[s1], student_ids[s2])))

                if pair not in self.pair_history:
                    self.pair_history.add(pair)
                    pairs.append(pair)
                    assigned.add(student_ids[s1])
                    assigned.add(student_ids[s2])
                    break

        for student in student_ids:
            if student not in assigned:
                pairs.append((student,))
        return pairs
