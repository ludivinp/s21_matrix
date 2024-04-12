# ludivinp
# INFO:
#
# Makefile
# https://www.gnu.org/software/make/manual/html_node/index.html
# https://makefiletutorial.com/#static-pattern-rules
# https://21-school-by-students.notion.site/77c02c29089d4964ba38656f100b98fb
#
# LCOV
# https://ltp.sourceforge.net/coverage/lcov.php
# http://reedmedia.net/~reed/qa/lcov-2016/
# https://ps-group.github.io/cxx/coverage_gcc
#
# Flags info
# https://stackoverflow.com/questions/28840261/gcov-what-is-the-difference-between-coverage-and-ftest-coverage-when-buildi
# https://stackoverflow.com/questions/2127797/significance-of-pthread-flag-when-compiling


CC :=gcc
CFLAGS =-Wall -Werror -Wextra -std=c11 -O2
GCOV_FLAGS :=--coverage #--fprofile-arcs --ftest-coverage // Тоже самое что и --coverage
GCOV_FLAGS_TEMP :=


SOURCE_DIR = functions functions/* functions/*/*
SOURCE =$(foreach current_dir, $(SOURCE_DIR), $(wildcard $(current_dir)/s21_*.c)) 
OBJECTS =$(patsubst %.c,%.o, ${SOURCE})
EXECUTABLE_NAME =s21_matrix.a

ifeq ($(shell uname -s), Linux) # Linux
	ADD_LIB =-lrt -pthread -lsubunit -lm
else
	ADD_LIB =-lm
endif


TEST_SOURCE_DIR = tests tests/* tests/*/*
TEST_SOURCE =$(foreach current_dir, $(TEST_SOURCE_DIR), $(wildcard $(current_dir)/s21_*.c))
TEST_OBJECTS =$(patsubst %.c,%.o, ${TEST_SOURCE})
TEST_EXECUTABLE_NAME =s21_matrix_test
ADD_TEST_LIB =-lcheck

GCOV_REPORT_NAME =$(TEST_EXECUTABLE_NAME)_gcov_report
REPORT_LIB =gcov_report


all: clean $(EXECUTABLE_NAME) test


# Компиляция основного файла
$(EXECUTABLE_NAME): clean_exe clean_obj ${OBJECTS}
# 	Создание статической библиотеки:
	ar rc $@ ${OBJECTS}
# 	Обновляет объектные файлы в статической библиотеки: Но зачем это нужно хз
#	ranlib $@ 
#	флаг -s подавляет вывод
	@make -s clean_obj


${OBJECTS}: 
	$(CC) $(CFLAGS) $(GCOV_FLAGS_TEMP) -c $(patsubst %.o,%.c, $@) -o $@ ${ADD_LIB}

# Компиляция тестов
$(TEST_EXECUTABLE_NAME): clean_test_exe $(EXECUTABLE_NAME) ${TEST_OBJECTS}
# 	Компиляция объектных файлов (-с)
#	${CC} -c ${CFLAGS} ${TEST_SOURCE} -o ${TEST_OBJECTS} ${ADD_LIB}
# 	Компиляция исполняющих файлов
	${CC} ${CFLAGS} ${TEST_OBJECTS} $(EXECUTABLE_NAME) -o $@ ${ADD_TEST_LIB} ${ADD_LIB} 
	@make -s clean_obj

${TEST_OBJECTS}:
	$(CC) $(CFLAGS) -c $(patsubst %.o,%.c, $@) -o $@ ${ADD_TEST_LIB} ${ADD_LIB}

# Запуск тестов
test: ${EXECUTABLE_NAME} $(TEST_EXECUTABLE_NAME)
	./$(TEST_EXECUTABLE_NAME)

# запуск тестов и создание gcov_report'a
gcov_report: clean_test_exe clean_gcov_test gcov_compile ${OBJECTS} ${TEST_OBJECTS} 
#	${CC} -c ${CFLAGS} ${GCOV_FLAGS} ${SOURCE} -o test_${EXECUTABLE_NAME} ${ADD_LIB}
	${CC} ${CFLAGS} ${GCOV_FLAGS} ${OBJECTS} ${TEST_OBJECTS} -o ${GCOV_REPORT_NAME} ${ADD_TEST_LIB} ${ADD_LIB}
	@make -s clean_obj
	./${GCOV_REPORT_NAME}
#  	| --capture \ -c | --test-name \ -t |  --output-file \ -o | --directory \ -d | --directory .
	lcov --capture  --test-name "${GCOV_REPORT_NAME}" --output-file ${GCOV_REPORT_NAME}.info --directory .
#	| --output-directory \ -o |
	genhtml --output-directory $(REPORT_LIB)/html_info ${GCOV_REPORT_NAME}.info
	@make -s clean_gcov_test
# открывем файл
	open $(REPORT_LIB)/html_info/index.html

clean_obj:
	rm -f *.o */*.o */*/*.o */*/*/*.o */*/*/*/*.o

clean_gcov_test:
	rm -f *.gcno */*.gcno */*/*.gcno */*/*/*.gcno */*/*/*/*.gcno
	rm -f *.gcov */*.gcov */*/*.gcov */*/*/*.gcov */*/*/*/*.gcov
	rm -f *.info */*.info */*/*.info */*/*/*.info */*/*/*/*.info
	rm -f *.gcda */*.gcda */*/*.gcda */*/*/*.gcda */*/*/*/*.gcda
#	lcov -z -d . выдаёт ошибку если нечего удалять 

clean_exe: 
	rm -f $(EXECUTABLE_NAME)

clean_test_exe: 
	rm -f $(TEST_EXECUTABLE_NAME)
	rm -f ${GCOV_REPORT_NAME}

clean_gcov_test_exe:
	rm -rf $(REPORT_LIB)

clean: clean_obj clean_exe clean_test_exe clean_gcov_test_exe clean_gcov_test

gcov_compile: $($(eval gcov_report: GCOV_FLAGS_TEMP += $(GCOV_FLAGS)))

clang:
	clang-format -i -style=google ${SOURCE} ${TEST_SOURCE}

clang_check:
	clang-format -n -style=google ${SOURCE} ${TEST_SOURCE}

# Нужна для того чтобы обозначить имеющиеся цели.
.PHONY: all $(EXECUTABLE_NAME) $(TEST_EXECUTABLE_NAME) all test gcov_report clean_obj clean_gcov_test clean_exe clean_test_exe clean_gcov_test_exe clean, clang, clang_check
