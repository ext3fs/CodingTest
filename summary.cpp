https://github.com/ndb796
https://opentutorials.org : 생활코딩
https://www.facebook.com/groups/174499879257223 : 생활코딩 커뮤니티
https://acmicpc.slack.com : BOJ community
https://www.onlinegdb.com : gdb IDE

10,000    -> 1 ms
10,000,000 -> 1 초

log1024 = 10
log10 -> 3.333..
log1000 -> 10
log10000 -> 10 + 3.33..
log100000 -> 10 + 3.33.. + 3.33..

프로그래머스 
o(10,000,000) -> 100ms
o(1억) -> 1000ms -> 1초 

0x7fffffff -> int max
0x80000000 -> int min
-----------------------------------------------------------------------------------------------------

string  		: string str(n,0), 	
		  	  front(), back(), erase(idx, n), erase(iter-1, iter+1), 
	   	 	  str = string.substr(idx, n) -> idx부터 n개, substr(idx) -> idx부터 끝까지
			  idx = string.find(ch) == string::npos, 
			  idx = string.find("str") == string::npos, 
			  str.replace(idx, n, "str") -> idx부터 n개를 s로 바꿈
			  str = to_string(n)
			  stoi("234AAAA"), stoll(str), stod(str)

stringstream		: <sstream>
		          ss.clear(), ss.str("123AAA"), ss << str
			  while(ss >> token)
				cout << token << endl;
			  while(getline(ss, token, ' '))
				cout << token << endl;

vector			: front(), back(), push_back(),
	      		  vector<vector<string>> v(n, vector<int>(n,"")) 	
			  vector<vector<int>> v(n, vector<int>())
			  v.erase(v.begin() + n);
		  	  v.reserve(n) -> capacity change
			  v.resize(n,0) -> 현재 값을 유지한채 size만 조정됨
			  v.assign(n,0) -> 재할당 & 초기화

stack			: <stack> top(), push(), pop()

queue			: dqueue로 구현, <queue> front(), push(), pop()

priority_queue		: <queue> heap구조(root에 최대값) -> 중복원소 허용
			  top()->O(1), push()->O(logN), pop()->O(logN)
			  priority_queue<int,vector<int>,greater<int>> q;
			  
			  struct cmp{
			  	bool operator()(const int a, const int b) const {
					return a > b;
				}
			  };
			  priority_queue<int,vector<int>,cmp> q(v.begin(),v.end(),cmp);

			  auto cmp = [](int a, int b) { return (a ^ 1) < (b ^ 1); };
			  spriority_queue<int,vector<int>,decltype(cmp)> q(cmp); 

deque			: <deque> front(), push_front(), push_back(), pop_front(), pop_back()

list			: doubly linked list, find() 가능 

set			: <set> red black tree(root에 중간값) -> 중복원소 허용안함
			  find(val)->O(logN), insert(val)->O(logN), erase(val)->O(logN)
			  iter = set.lower_bound(n) <- n이상
			  iter = set.upper_bound(n) <- n초과
			  set<int, greater<int>>
			  if((iter = st.find()) != st.end())

multiset		: <set>
			  mst.erase(val) -> 모든 val 지워짐
			  iter = mst.find(val); mst.erase(iter)로 지워야 하나만 지워짐 
			
map			: <map> red black tree
			  map.insert(make_pair("ss",0)) -> map["ss"] = 0 와 같음
			  레코드 없는 상태에서 ++map["ss"] 하면 ss,0 생성 & ++0
			  map.count(key)  

tuple			: <tuple>
			  using tics = tuple<int,char,string>;
			  tics tup(1, 'x', "str");
			  auto tup = make_tuple(1, 'x', "str");
		  	  get<0>(tup) -> 1	  

max_element		: <algorithm>
			  iter = max_element(v.begin(), v.end());

find			: <algorithm>
			  iter = find(v.begin(), v.end(), val)			  

-----------------------------------------------------------------------------------------------------
반올림			: <cmath> ceil(double 올림), floor(버림), round(반올림) 

절대값			: abs(int n)

알파벳, 숫자 변환	: bool b = isupper(ch), islower(ch), isdigit(ch), isalpha(ch)
			  int i = toupper(ch)

getline(토큰화)		: stringstream ss(exp);
			  string token;
			  while(getline(ss,token,' '))
				v.push_back(token);
			  while(getline(cin,token))
				v.push_back(token);

regex_replace		: <regex>
			  string s = "search";
			  s = regex_replace(s, regex("ch"), "1"); -> "sear1"	

sort			: <algorithm>
			  sort(v.begin(), v.end(), greater<>())
			  stable_sort()	
			  
reverse			: <algorithm>
		  	  reverse(v.begin(), v.end());	  

컨테이너 최대값		: max_element(v.begin(), v.end(), comp)
			  bool comp(int a, int b){return a<b}

이분탐색		: <algorithm>
			  bool binary_serach(v.begin(), v.end(), n) 
			  iter lower_bound(v.begin(), v.end(), n) <- n이상
			  iter upper_bound(v.begin(), v.end(), n) <- n초과
			 

- algorithm -----------------------------------------------------------------------------------

n진수 만들기		: nMod(int n, int val)

약수의 갯수		: cntDivisor(int n)

n이 소수인지?		: isPrime(int n)  루트n까지만 나눠보면 됨
			  소수란? 2이상의 자연수들중 1과 자신만을 약수로 가지는 수

a ~ b 소수가 몇개?	: eratos(int a, int b) -> amortized O(n) 

순열 			: n개중에 r개 뽑음, 순서상관있음
			  permutation(int n, int r) -> 방문체크

조합			: n개중에 r개 뽑음, 순서상관없음
			  combination(int start, int n, int r)

최대공약수		: <numeric>
			  유클리드 호제법, gcd(a,b) = gcd(b, a%b), (a%b == 0) 되면 a가 답 

최소공배수 		: <numeric>
			  lcm(a,b) = a*b/gcd(a,b) 	

dijkstra		: 가중치 그래프구조 - 특정노드에서 최단경로 탐색, priority_queue 
			  O(ElogE)

floyd_warshall		: 가중치 그래프구조 - dp algorithm
			  모든노드들의 최단경로의 인접행렬 만듬(대각원소는 0)
			  음의 가중치가능, 음수사이클X(대각원소에 음수가 나타나면)
			  O(V^3)

kruskal 		: 가중치 그래프구조 - greed algorithm
			  최소신장트리만들기(MST : minimum spanning tree) 
			   -> 사이클을 형성하지않는 최소 가중치의 합을 가진 트리구조의 그래프 
			  최소비용 간선의 노드들을 차례로 합침(union_node(a,b), find_root(a)) 
			  n개의 노드를 연결한다면 간선의 수는 n-1
			  O(ElogE) - 간선의 수가 작을때 사용

prim			: 임의의 노드에서 최단경로의 노드를 하나씩 추가 -> 최소신장트리를 만들어 나감
			  O(ElogV) - 간선의 수가 많을때 사용	

topology_sort		: 방향성 그래프구조
			  방향성에 따라 노드들을 줄세우기 -> 선수과목을 고려한 학습 순서 정하기
			  의존성 그래프구조에서 진입차수(indegree)가 0인 노드를 큐에 넣으면서 진입차수변경
			  큐에서 빼낸 노드 순서가 위상정렬
			  큐에 한꺼번에 여러 노드가 들어가는 경우 -> 정답 여러개
			  큐에서 빼낸 노드의 갯수가 v가 아니면 -> 사이클 발생
			  O(V+E)

lis			: longest increasing subsequence -> dp algorithm

lcs			: longest common subsequence -> dp algorithm

-----------------------------------------------------------------------------------------------------
비트연산		: n  & -n   -> 마지막 1의 위치에 1
			  ~n & -~n  -> 마지막 0의 위치에 1 

멀쩡한 사각형		: programmers(62048) -> 시작점(0,0)에서 목적지(h,w)로 갈때 밟는 타일의 갯수

행렬의 곱셈		: programmers(12949)

숫자의 표현		: programmers(12924) -> 구간합 & two pointer

N-Queen			: programmers(12952) -> back tracking(dfs 가지치기)

멀리뛰기		: programmers(12914) -> dp : 순서를 고려한 경우의 수    
