import csv
import os

dir_path = os.path.dirname(os.path.realpath(__file__))

with open(dir_path + '/pre_processed_csv.csv', 'w') as f:
    # iterate over the directories and files and add each one to the csv
    writer = csv.writer(f)
    for root, dirs, files in os.walk(dir_path + '/pre_processed'):
        for name in files:
            if name.endswith('.jpeg'):
                path = name # f"{dir_path}\\{name}"
                value = name + ';' + os.path.basename(root)
                #writer.writerow([name, os.path.basename(root)])
                writer.writerow([value])
    
    