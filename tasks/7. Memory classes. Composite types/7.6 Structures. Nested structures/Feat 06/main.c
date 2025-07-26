/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191315/step/8?unit=1204303}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  char fname[WORD_LENGTH]; // имя
  char otch[WORD_LENGTH];  // отчество
  char lname[WORD_LENGTH]; // фамилия

  size_t fname_size = sizeof(fname) / sizeof(*fname);
  size_t otch_size = sizeof(otch) / sizeof(*otch);
  size_t lname_size = sizeof(lname) / sizeof(*lname);

  short old;    // возраст
  short height; // рост
  short weight; // вес

  struct tag_student st = {};

  // get name, patronymic, last name
  getline(fname, sizeof(fname));
  getline(otch, sizeof(otch));
  getline(lname, sizeof(lname));

  // get the age, height and weight data
  if (get_input_data(&old, &height, &weight) == -1) {
    return 1;
  }

  // TODO! Move that logic to the function like
  // fill_tag_student_struct_instance(tag_student *st, char *fname, char *otch,
  //  char *lname, short old, short height, short weight);

  // fill the @link{st} with got data copy name
  if (strlen(fname) <= fname_size) {
    strcpy(st.fio.firstname, fname);
  }

  // copy otch (i.e. patronymic)
  if (strlen(otch) <= otch_size) {
    strcpy(st.fio.otch, otch);
  }

  // copy last name
  if (strlen(lname) <= lname_size) {
    strcpy(st.fio.lastname, lname);
  }

  // copy age, height, weight
  st.old = old;
  st.height = height;
  st.weight = weight;

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
