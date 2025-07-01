class PairGenerator:
    def __init__(self):
        self.global_history = []

    def generatePairs(self, studentIDs):

        pairs = []
        assigned = []
        n = len(studentIDs)

        for S1 in range(n):
            if studentIDs[S1] in assigned:
                continue
            for S2 in range(n):
                if studentIDs[S2] in assigned:
                    continue
                if studentIDs[S1] == studentIDs[S2]:
                    continue

                currentGrp = []

                currentGrp.append(studentIDs[S1])
                currentGrp.append(studentIDs[S2])

                if currentGrp in self.global_history or currentGrp[::-1] in self.global_history:
                    continue

                self.global_history.append(currentGrp)

                pairs.append(currentGrp)
                assigned.append(studentIDs[S1])
                assigned.append(studentIDs[S2])

                break
        
        for student in studentIDs:
            if student not in assigned:
                pairs.append([student])

        return pairs



            