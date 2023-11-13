import networkx as nx
import matplotlib.pyplot as plt

# Crear un grafo dirigido
G = nx.DiGraph()

# Definir conceptos y relaciones
concepts = [
    {"Concepto": "Sustitución de factores", "Descripción": "Ajuste en la combinación de insumos."},
    {"Concepto": "Rendimientos constantes de escala", "Descripción": "Producción proporcional a cambios en los insumos."},
    {"Concepto": "Rendimientos crecientes de escala", "Descripción": "Producción aumenta más que proporcionalmente a cambios en los insumos."},
    {"Concepto": "Rendimientos decrecientes de escala", "Descripción": "Producción aumenta menos que proporcionalmente a cambios en los insumos."}
]

relaciones = [
    ("Sustitución de factores", "Rendimientos constantes de escala"),
    ("Sustitución de factores", "Rendimientos crecientes de escala"),
    ("Sustitución de factores", "Rendimientos decrecientes de escala")
]

# Agregar nodos y relaciones al grafo
for concepto in concepts:
    G.add_node(concepto["Concepto"], Descripción=concepto["Descripción"])

for relacion in relaciones:
    G.add_edge(relacion[0], relacion[1])

# Dibujar el grafo
pos = nx.spring_layout(G)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw(G, pos, with_labels=True, node_size=2000, node_color="skyblue", font_size=8, font_color="black", font_weight="bold")
nx.draw_networkx_edge_labels(G, pos, edge_labels={(rel[0], rel[1]): "" for rel in relaciones}, font_color="red")

# Mostrar el gráfico
plt.show()
