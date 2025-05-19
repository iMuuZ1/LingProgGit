Inf = 9999

matrix = [
    [0, 5, 1, 2, Inf, Inf, Inf, Inf, Inf],
    [5, 0, Inf, Inf, Inf, Inf, Inf, Inf, 3],
    [1, Inf, 0, Inf, 1, Inf, Inf, Inf, Inf],
    [2, Inf, Inf, 0, Inf, 1, Inf, Inf, Inf],
    [Inf, Inf, 1, Inf, 0, Inf, Inf, 1, Inf],
    [Inf, Inf, Inf, 1, Inf, 0, 1, Inf, Inf],
    [Inf, Inf, Inf, Inf, Inf, 1, 0, 3, 2],
    [Inf, 1, Inf, Inf, Inf, 1, Inf, 0, 3],
    [Inf, 3, Inf, Inf, Inf, Inf, 2, Inf, 0]
]

def dijkstra(graph, start, end):
    n = len(graph)
    dist = [Inf] * n
    prev = [None] * n
    visited = [False] * n

    dist[start] = 0

    for _ in range(n):
        min_dist = Inf
        u = -1
        for i in range(n):
            if not visited[i] and dist[i] < min_dist:
                min_dist = dist[i]
                u = i

        if u == -1:
            break

        visited[u] = True

        for v in range(n):
            if graph[u][v] != Inf and not visited[v]:
                alt = dist[u] + graph[u][v]
                if alt < dist[v]:
                    dist[v] = alt
                    prev[v] = u

    path = []
    u = end
    while u is not None:
        path.insert(0, u)
        u = prev[u]

    return dist[end], path

# Interação com o usuário
n = len(matrix)
print(f"O grafo possui {n} vértices (de 0 a {n - 1}).")
try:
    s = int(input("Digite o número do nó de origem (s): "))
    t = int(input("Digite o número do nó de destino (t): "))
    if s < 0 or s >= n or t < 0 or t >= n:
        print("Erro: índices fora do intervalo permitido.")
    else:
        distancia, caminho = dijkstra(matrix, s, t)
        if distancia == Inf:
            print(f"Não existe caminho de {s} para {t}.")
        else:
            print(f"Menor distância de {s} para {t}: {distancia}")
            print(f"Caminho: {caminho}")
except ValueError:
    print("Erro: você deve digitar números inteiros.")
