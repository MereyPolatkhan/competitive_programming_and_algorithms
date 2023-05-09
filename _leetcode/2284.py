class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        focus_mocus = dict()

        def word_counter(string):
            a = string.split() 
            return len(a)


        for i, sender in enumerate(senders):
            if sender not in focus_mocus:
                focus_mocus[sender] = word_counter(messages[i]) 
            else:
                focus_mocus[sender] += word_counter(messages[i]) 

        max_word = sorted(focus_mocus.values())[-1]

        a = [] 

        for key, value in focus_mocus.items():
            if value == max_word:
                a.append(key)


        return (sorted(a)[-1])