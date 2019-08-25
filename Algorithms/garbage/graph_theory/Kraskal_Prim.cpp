// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <algorithm>

namespace KraskalPrim
{
	static constexpr size_t inf = std::numeric_limits<size_t>::max();

	std::vector<std::vector<size_t>> graph =
	{
	  { inf,	15,		7,		10,		inf,	inf,	inf },
	  { 15,		inf,	inf,	4,		16,		inf,	inf },
	  { 7,		inf,	inf,	inf,	inf,	10,		9 },
	  { 10,		4,		inf,	inf,	3,		inf,	inf },
	  { inf,	16,		inf,	3,		inf,	inf,	inf },
	  { inf,	inf,	10,		inf,	inf,	inf,	5 },
	  { inf,	inf,	9,		inf,	inf,	5,		inf }
	};

	void Kraskal()
	{
		std::vector<size_t> parent(graph.size());
		std::function<size_t(size_t)> find = [&](size_t vertex)
		{
			while (parent[vertex] != vertex)
				vertex = parent[vertex];
			return vertex;
		};
		std::function<void(size_t, size_t)> _union = [&](size_t a, size_t b)
		{
			size_t i = find(a);
			size_t j = find(b);
			parent[i] = j;
		};

		std::function<void()> krsk = [&]()
		{
			unsigned min_cost = 0;
			for (size_t t = 0; t < graph.size(); ++t)
				parent[t] = t;
			size_t edge_count = 0;
			while (edge_count < graph.size() - 1)
			{
				size_t min = inf, a = -1, b = -1;
				for (size_t t = 0; t < graph.size(); ++t)
				{
					for (size_t _t = 0; _t < graph.size(); ++_t)
						if (find(t) != find(_t) && graph[t][_t] < min)
						{
							min = graph[t][_t];
							a = t; b = _t;
						}
				}
				_union(a, b);
				std::cout << "\nEdge:\t" << a << " - " << b;
				edge_count++;
			}
		};
		krsk();
	};
	void Prim()
	{
		std::function<void()> prm = [&]()
		{
			std::vector<bool> visited(graph.size());
			std::vector<size_t> min_edge(graph.size(), inf), last_edge(graph.size(), -1);
			min_edge[0] = 0;
			for (size_t t = 0; t < graph.size(); ++t)
			{
				size_t index = -1;
				for (size_t _t = 0; _t < graph.size(); ++_t)
					if (!visited[_t] && (index == -1 || min_edge[_t] < min_edge[index]))
						index = _t;
				if (min_edge[index] == inf)
				{
					std::cout << "\nCannot found the minimum spanning tree!";
					return;
				}
				visited[index] = true;
				if (last_edge[index] != -1)
					std::cout << "\nEdge:\t" << index << " - " << last_edge[index];
				for (size_t _t = 0; _t < graph.size(); ++_t)
					if (graph[index][_t] < min_edge[_t])
					{
						min_edge[_t] = graph[index][_t];
						last_edge[_t] = index;
					}
			}
		};
		prm();
	}

	int TEST()
	{
		Kraskal();
		std::cout << "\n\n";
		Prim();
		std::cin.get();
		return 0;
	}
};