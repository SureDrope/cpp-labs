.mode columns
.headers off

/*
 * 3. Создайте при помощи команды языка SQL таблицу в соответствии с
 * заданием (см. задание к лабораторной работе № 1).
 */
CREATE TABLE
	IF NOT EXISTS students (
		id INTEGER PRIMARY KEY,
		surname VARCHAR(50) UNIQUE NOT NULL,
		university VARCHAR(50) NOT NULL,
		faculty VARCHAR(50) NOT NULL,
		year INTEGER NOT NULL
	);

/*
 * 4. Поместите в таблицу 3-­5 записей произвольного содержания.
 */
INSERT INTO
	students (surname, university, faculty, year)
VALUES
	('Кушалиев', 'СПбГУТ', 'ИБ', 2),
	('Цыплаков', 'СПбГУТ', 'ИБ', 2),
	('Шалапаев', 'МГУ', 'ГИБ', 1),
	('Макрон', 'МГТУ', 'ИБ', 3),
	('Матвеев', 'АГТУ', 'АБОБА', 4);

/*
 * 5. Создайте запросы к таблице, позволяющие просмотреть содержимое всех ее
 * полей. Сравните с ожидаемыми результатами.
 */
.print "Содержимое таблицы:"

SELECT
	*
FROM
	students;

/*
 * 6. Измените запросы предыдущего пункта таким образом, чтобы вывод данных
 * осуществлялся в отсортированном виде (по возрастанию, по убыванию).
 * Поле, по которому выполняется сортировка, выбрать произвольно.
 */
.print "Содержимое таблицы, отсортированное по году обучения:"

SELECT
	*
FROM
	students
ORDER BY
	year;

/*
 * 7. Сформулируйте условие отбора данных и создайте запрос на выборку,
 * соответствующий этом условию.
 */
.print "Список студентов, обучающихся в МГУ:"

SELECT
	*
FROM
	students
WHERE
	university = 'МГУ';

/*
 * 8. Сформулируйте два условия отбора и создайте запрос на выборку,
 * соответствующий обоим условиям.
 */
.print "Список студентов, обучающихся на ИБ и на 2 курсе:"

SELECT
	*
FROM
	students
WHERE
	faculty = 'ИБ'
	AND year = 2;

/*
 * 9. Добавьте в таблицу еще одну запись.
 */
INSERT INTO
	students (surname, university, faculty, year)
VALUES
	('Валадай', 'ТТУ', 'МОМ', 1);

/*
 * 10. Отредактируйте любую из записей таким образом, чтобы в одном из полей
 * появились повторяющиеся значения.
 */
UPDATE students
SET
	faculty = "МГУ"
WHERE
	id = 3;

/*
 * 11. Посчитайте, сколько различных значений находится в поле с
 * повторяющимися значениями. Определите, сколько раз встречается
 * конкретное значение в этом поле.
 */
.print "Список университетов и сколько раз они встречаются:"

SELECT
	university,
	COUNT(*) AS count
FROM
	students
GROUP BY
	university;

/*
 * 12. Определите при помощи запроса, сколько всего записей имеется в таблице.
 * Удалите одну запись и посчитайте количество записей еще раз.
 */
.print "Количество записей в таблице:"

SELECT
	COUNT(*)
FROM
	students;

DELETE FROM students
WHERE
	surname = 'Валадай';

.print "Количество записей в таблице после удаления одной записи:"

SELECT
	COUNT(*)
FROM
	students;