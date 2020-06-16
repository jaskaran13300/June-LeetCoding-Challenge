from ipaddress import ip_address, IPv6Address
class Solution:
    def validIPAddress(self, IP: str) -> str:
        try:
            return "IPv6" if type(ip_address(IP)) is IPv6Address else "IPv4"
        except ValueError:
            return "Neither"
            
#Alternative

class Solution:
    def validate_IPv4(self, IP: str) -> str:
        nums = IP.split('.')
        for x in nums:
            if len(x) == 0 or len(x) > 3:
                return "Neither"
            if x[0] == '0' and len(x) != 1 or not x.isdigit() or int(x) > 255:
                return "Neither"
        return "IPv4"
    
    def validate_IPv6(self, IP: str) -> str:
        nums = IP.split(':')
        hexdigits = '0123456789abcdefABCDEF'
        for x in nums:
            if len(x) == 0 or len(x) > 4 or not all(c in hexdigits for c in x):
                return "Neither"
        return "IPv6"
        
    def validIPAddress(self, IP: str) -> str:
        if IP.count('.') == 3:
            return self.validate_IPv4(IP)
        elif IP.count(':') == 7:
            return self.validate_IPv6(IP)
        else:
            return "Neither"
            
            
            
            
#Alternative

class Solution:
    def ipv4(self,IP):
        arr=IP.split('.')
        for ele in arr:
            try:
                st=str(ele)
            except:
                return 'Neither'
            if st.isnumeric() == False:
                return 'Neither'
            if len(st)==1:
                continue
            if len(st)>1 and st[0]=='0':
                return 'Neither'
            if not(int(ele)>=0 and int(ele)<=255):
                return 'Neither'
        return 'IPv4'
    def ipv6(self,IP):
        arr=IP.split(':')
        for ele in arr:
            try:
                st=str(ele)
            except:
                return 'Neither'
            if st.isalnum()==False:
                return 'Neither'
            if len(st)==0 or len(st)>4:
                return 'Neither'
            for e in st:
                if e.isalpha() and e.isupper() and e>='G':
                    # print(e)
                    return 'Neither'
                elif e.isalpha() and e.islower() and e>='g':
                    # print(e)
                    return 'Neither'
            
        return 'IPv6'
    def validIPAddress(self, IP: str) -> str:
        dot=IP.count('.')
        colon=IP.count(':')
        ans="Neither"
        if dot==3:
            ans=self.ipv4(IP)
        elif colon==7:
            ans=self.ipv6(IP)
        return ans
