https://github.com/ndb796
https://opentutorials.org : 생활코딩
https://www.facebook.com/groups/174499879257223 : 생활코딩 커뮤니티
https://acmicpc.slack.com : BOJ community
https://www.onlinegdb.com : gdb IDE

10000000 -> 1초
log10 -> 3
log1000 -> 10
log10000 -> 10 +3

-----------------------------------------------------------------------------------------------------

string  		: string str(n,0), 	
		  	  front(), back(), erase(idx, n), erase(iter-1, iter+1), 
	   	 	  str = string.substr(idx, n), i = string.find(ch) == string::npos, 
			  str = to_string(n), stoll(str), stoi(str), stod(str)

stringstream		: <sstream> ss.clear(), ss.str(str), ss << str, while(ss >> str)

vector			: front(), back(), push_back(),
	      		  vector<vector<string>> v(n, vector<int>(n,"")) 	
			  vector<vector<int>> v(n, vector<int>())
			  v.erase(v.begin() + n);	

stack			: <stack> top(), push(), pop()

queue			: <queue> front(), push(), pop()

priority_queue		: <queue> heap 구조
			  top()->O(1), push()->O(logN), pop()->O(logN)
			  priority_queue<int,vector<int>,greater<int>> q;

set			: red black tree
			  find()->O(logN), insert()->O(logN), erase()->O(logN)
			  iter set.lower_bound(n) <- n이상
			  iter set.upper_bound(n) <- n초과
			  set<int, greater<int>>
			  if((iter = st.find()) != st.end())

map			: red black tree
			  map.insert(make_pair("ss",0)) -> map["ss"] = 0 와 같음
			  레코드 없는 상태에서 ++map["ss"] 하면 ss,0 생성 & ++0  

tuple			: <tuple>
			  using tiii = tuple<int,int,int>;
			  tiii tup(1, 'x', "str");
			  auto tup = make_tuple(1, 'x', "str");
		  	  get<0>(tup) -> 1	  

max_element		: <algorithm>
			  iter = max_element(v.begin(), v.end());

-----------------------------------------------------------------------------------------------------
반올림			: <cmath> ceil(double 올림), floor(버림), round(반올림) 

절대값			: abs(int n)

알파벳, 숫자 변환	: isupper(ch), islower(ch), isdigit(ch), toupper(ch)

getline(토큰화)		: stringstream ss(exp);
			  string token;
			  while(getline(ss,token,' '))
				v.push_back(token);

sort			: <algorithm> sort(begin, end, greater<>())

컨테이너 최대값		: max_element(v.begin(), v.end(), comp)
			  bool comp(int a, int b){return a<b}

이진탐색		: <algorithm>
			  bool binary_serach(iter.begin(), iter.end(), n) 
			  iter lower_bound(iter.begin(), iter.end(), n) <- n이상
			  iter upper_bound(iter.begin(), iter.end(), n) <- n초과

-----------------------------------------------------------------------------------------------------

약수의 갯수		: cntDivisor(int n)

n이 소수인지?		: isPrime(int n)  루트n까지만 나눠보면 됨
			  소수란? 1이상의 자연수들중 1과 자신만을 약수로 가지는 수

a ~ b 소수가 몇개?	: eratos(int a, int b) 

순열 			: n개중에 r개 뽑음, 순서상관있음
			  permutation(int detph, int n, int r) <- swap(a,b)

조합			: n개중에 r개 뽑음, 순서상관없음
			  combination(int idx, int n, int r) <- v.push_back()

bitmask_combination	: programmers 순위검색(72412)

최대공약수		: 유클리드 호제법, gcd(a,b) = gcd(b, a%b)

최소공배수 		: lcm(a,b) = a*b/gcd(a,b) 	

멀쩡한 사각형		: x + y - gcd(x,y)

dijkstra		: 그래프구조 - 특정노드에서 최단경로 탐색, 양의 가중치, priority_queue 
			  O(ElogV)

floyd_warsall		: dp algorithm
			  그래프구조 - 모든노드들의 최단경로의 인접행렬 만듬(대각원소는 0)
			  음의 가중치가능, 음수사이클X(대각원소에 음수가 나타나면)
			  O(V^3)

kruskal 		: greed algorithm
			  그래프구조 - 최소신장트리만들기(MST : minimum spanning tree) 
			   -> 사이클을 형성하지않는 최소 가중치의 합을 가진 트리구조의 그래프 
			  최소비용 간선의 노드들을 차례로 합침(union_node(a,b))
			  n개의 노드를 연결한다면 간선의 수는 n-1
			  O(ElogE)

topology_sort		: 그래프구조 - 선수과목을 고려한 학습 순서 정하기
			  의존성 그래프구조에서 진입차수(indegree)가 0인 노드를 큐에 넣으면서 진입차수변경
			  큐에서 빼낸 노드 순서가 위상정렬
			  큐에 한꺼번에 여러 노드가 들어가는 경우 -> 정답 여러개
			  큐에서 빼낸 노드의 갯수가 v가 아니면 -> 사이클 발생
			  O(V+E)

lis			: longest increasing subsequence -> dp algorithm

lcs			: longest common subsequence -> dp algorithm

two_pointer 		: 구간합

