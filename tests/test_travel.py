from subprocess import run, PIPE
import os
import shutil
import pytest

B_FILE_PATH = './bin/travel'
DATA_DIR = './data'
DATA_SAMPLES_DIR = './data_samples'

if os.path.isfile(B_FILE_PATH):
    def test_travel_not_correct_input_1():
        result = run([B_FILE_PATH], input='./gggggg/this_file_doesnt_exist.txt.sdahgasdg', encoding='utf-8', stdout=PIPE, stderr=PIPE)
        assert result.returncode != 0
        assert result.stderr == 'Puck you, Verter!'
    
    def test_travel_1():
        test_file_name = 'travel1.txt'
        test_file_path = os.path.join(DATA_DIR, test_file_name)
        shutil.copy(os.path.join(DATA_SAMPLES_DIR, test_file_name), test_file_path)
        result = run([B_FILE_PATH], input=test_file_path, encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout == 'Yaroslavl\nVladimir\nNizhniyNovgorod\n23'
    
    def test_travel_2():
        test_file_name = 'travel2.txt'
        test_file_path = os.path.join(DATA_DIR, test_file_name)
        shutil.copy(os.path.join(DATA_SAMPLES_DIR, test_file_name), test_file_path)
        result = run([B_FILE_PATH], input=test_file_path, encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout == 'Travel is impossible!'
    
    def test_travel_3():
        test_file_name = 'travel3.txt'
        test_file_path = os.path.join(DATA_DIR, test_file_name)
        shutil.copy(os.path.join(DATA_SAMPLES_DIR, test_file_name), test_file_path)
        result = run([B_FILE_PATH], input=test_file_path, encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout == 'Yaroslavl\nIvanovo\n4'
    
    def test_travel_4():
        test_file_name = 'travel4.txt'
        test_file_path = os.path.join(DATA_DIR, test_file_name)
        shutil.copy(os.path.join(DATA_SAMPLES_DIR, test_file_name), test_file_path)
        result = run([B_FILE_PATH], input=test_file_path, encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout == 'Somewhere\nNowhere\nSomewhere\n20'

if __name__ == "__main__":
    pytest.main()
