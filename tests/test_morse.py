from subprocess import run, PIPE

import os
import pytest

B_FILE_PATH = './bin/morse'


def run_test_with_error_input(input_str):
    result = run(
        [B_FILE_PATH], input=input_str, encoding='utf-8',
        stdout=PIPE, stderr=PIPE
    )
    assert result.returncode != 0
    assert "Puck you, Verter!" in result.stderr


def run_test_with_correct_input(input_str, expected_stdout):
    result = run([B_FILE_PATH], input=input_str, encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert result.stdout == expected_stdout


if os.path.isfile(B_FILE_PATH):
    def test_bin_folder_containts_morse():
        assert os.path.isfile(B_FILE_PATH)

    def test_morse_incorrect_command_input_1():
        run_test_with_error_input('0\nSOS')

    def test_morse_incorrect_command_input_2():
        run_test_with_error_input('9\nSOS')

    def test_morse_incorrect_command_input_3():
        run_test_with_error_input('777\nSOS')

    def test_morse_incorrect_command_input_4():
        run_test_with_error_input('0\nSOS')

    def test_morse_incorrect_command_input_5():
        run_test_with_error_input('-5\nSOS')

    def test_morse_incorrect_value_input_1():
        run_test_with_error_input('1\nПРИВЕТ')

    def test_morse_incorrect_value_input_2():
        run_test_with_error_input('1\nSOS!')

    def test_morse_incorrect_value_input_3():
        run_test_with_error_input('1\n... --- ...')

    def test_morse_incorrect_value_input_4():
        run_test_with_error_input('2\nSOS')

    def test_morse_incorrect_value_input_5():
        run_test_with_error_input('1\nSos -3')

    def test_letters_into_morse_1():
        run_test_with_correct_input('1\nSOS', '... --- ...')

    def test_letters_into_morse_2():
        run_test_with_correct_input('1\n15', '.---- .....')

    def test_letters_into_morse_3():
        run_test_with_correct_input('1\n15S', '.---- ..... ...')

    def test_letters_into_morse_4():
        input_str = '1\nhello'
        exp_output = '.... . .-.. .-.. ---'
        run_test_with_correct_input(input_str, exp_output)

    def test_letters_into_morse_5():
        input_str = '1\nHELLO'
        exp_output = '.... . .-.. .-.. ---'
        run_test_with_correct_input(input_str, exp_output)

    def test_letters_into_morse_6():
        input_str = '1\nHeLlO'
        exp_output = '.... . .-.. .-.. ---'
        run_test_with_correct_input(input_str, exp_output)

    def test_words_into_morse_1():
        input_str = '1\nHello world'
        exp_output = '.... . .-.. .-.. ---\t.-- --- .-. .-.. -..'
        run_test_with_correct_input(input_str, exp_output)

    def test_words_into_morse_2():
        input_str = '1\nWe can do it'
        exp_output = '.-- .\t-.-. .- -.\t-.. ---\t.. -'
        run_test_with_correct_input(input_str, exp_output)

    def test_words_into_morse_3():
        input_str = '1\n20 000 Leagues Under The Sea'
        exp_output = ('..--- -----\t----- ----- -----\t.-.. . .- --. ..- . ...\t..- -. -.. . .-.\t- .... .\t... . .-')
        run_test_with_correct_input(input_str, exp_output)

    def test_morse_into_letters_1():
        run_test_with_correct_input('2\n...- .. --', 'VIM')

    def test_morse_into_letters_2():
        run_test_with_correct_input('2\n. ... -.-.', 'ESC')

    def test_morse_into_letters_3():
        run_test_with_correct_input('2\n.--- ----- ----.', 'J09')

    def test_morse_into_letters_4():
        run_test_with_correct_input('2\n....- ....', '4H')

    def test_morse_into_letters_5():
        run_test_with_correct_input('2\n..--- ..... --...', '257')

    def test_morse_into_words_1():
        input_str = '2\n.-- .\t-.-. .- -.\t-.. ---\t.. -'
        exp_output = 'WE CAN DO IT'
        run_test_with_correct_input(input_str, exp_output)

    def test_morse_into_words_2():
        input_str = '2\n.... . .-.. .-.. ---\t.-- --- .-. .-.. -..'
        exp_output = 'HELLO WORLD'
        run_test_with_correct_input(input_str, exp_output)

    def test_morse_into_words_3():
        input_str = '2\n..--- ....-\t.... --- ..- .-. ...'
        exp_output = '24 HOURS'
        run_test_with_correct_input(input_str, exp_output)

    def test_morse_into_words_4():
        input_str = '2\n.. -.\t.-- . . -.-\t--...\t-.. .- -.-- ...'
        exp_output = 'IN WEEK 7 DAYS'
        run_test_with_correct_input(input_str, exp_output)

    def test_morse_into_words_5():
        input_str = '2\n----- -----\t----- .----\t..... ----.'
        exp_output = '00 01 59'
        run_test_with_correct_input(input_str, exp_output)


if __name__ == '__main__':
    pytest.main()
