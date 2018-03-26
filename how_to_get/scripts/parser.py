import xml.etree.ElementTree as ET
import csv
import collections

tree = ET.parse('0001.xml')
root = tree.getroot()

l1 = []
l2 = []

# pobranie wartosci z xml, w miare sensowanie
for przystanek in root.iter('przystanek'):
    l1.append(przystanek.attrib)
    # print(przystanek.attrib)

for tabliczka in root.iter('tabliczka'):
    l2.append(tabliczka.attrib)
    # print(tabliczka.attrib)


index = 0
l3 = []
# wyciagniecie tylko trasy w jedna strone
# niestety mniej lopatologicznego sposobu nie znalazlem
for x in range(len(l1)):
    index = index + 1
    if index < 23:
        l3.append(l1[x])
        # print(l3[x])

# usuniecie zbednych danych
for x in range(len(l3)):
    l3[x].pop('cechy')
    l3[x].pop('id')

for x in range(len(l3)):
    l2[x].pop('id')

# sumowanie listy l2 i l3
for x in range(len(l3)):
    l3[x].update(l2[x])

# posortowanie słowników czas-przystanek-nazwa
for x in l3:
    for y in x.keys():
        sorted(x.items(), key=lambda t: len(t[1]))

for x in range(len(l3)):
    print(l3[x])

# zapis do pliku csv
keys = l3[0].keys()
with open('data_for_graph.csv', 'w') as output_file:
    dict_writer = csv.DictWriter(output_file, keys)
    dict_writer.writeheader()
    dict_writer.writerows(l3)
