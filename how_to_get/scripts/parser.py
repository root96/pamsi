import xml.etree.ElementTree as ET
import csv

tree = ET.parse('0001_test.xml')
root = tree.getroot()

l1 = []
l2 = []

for przystanek in root.iter('przystanek'):
    l1.append(przystanek.attrib)
    # print(przystanek.attrib)

for tabliczka in root.iter('tabliczka'):
    l2.append(tabliczka.attrib)
    # print(tabliczka.attrib)

for x in range(len(l1)):
    l1[x].pop('cechy')
    l1[x].pop('id')

for y in range(len(l2)):
    l2[y].pop('id')

for x in range(len(l2)):
    l1[x].update(l2[x])

keys = l1[0].keys()
with open('data_for_graph.csv', 'w') as output_file:
    dict_writer = csv.DictWriter(output_file, keys)
    dict_writer.writeheader()
    dict_writer.writerows(l1)
