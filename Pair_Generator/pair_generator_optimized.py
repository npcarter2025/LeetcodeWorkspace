class PairGeneratorOptimized:
    def __init__(self):
        self.partner_history = {}

    def generatePairs(self, studentIDs):

        pairs = []
        assigned = set()
        n = len(studentIDs)

        for i in range(n):

            s1 = studentIDs[i]
            if s1 in assigned:
                continue

            for j in range(i + 1, n):

                s2 = studentIDs[j]
                if s2 in assigned:
                    continue

                s1_partners = self.partner_history.get(s1, set()) # returns empty set if key does not exist
                s2_partners = self.partner_history.get(s2, set())

                if s2 in s1_partners or s1 in s2_partners:
                    continue
                
                pairs.append([s1, s2])
                assigned.add(s1)
                assigned.add(s2)

                self.partner_history.setdefault(s1, set()).add(s2)
                self.partner_history.setdefault(s2, set()).add(s1)


                break
        
        for student in studentIDs:
            if student not in assigned:
                pairs.append([student])

        return pairs



            