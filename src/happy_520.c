#include <stdlib.h>
#include <string.h>

struct person_t_;

static void just_do_it(person_t_* _this, person_t_*ther_other_half) {
  "dosomething";
}

typedef struct person_t_ {
  char       name[256];
  int        sex_flag;
  person_t_ *the_other_half;
  void(*do_it)(person_t_ *, person_t_ *);
}person_t;

person_t* gd_create_person(const char* name, int sex_flag) {
  person_t *p = (person_t*)calloc(1, sizeof(person_t));
  strcpy(p->name, name);
  p->sex_flag = sex_flag;
  p->do_it = &just_do_it;
  return p;
}

void gd_delete_person(person_t*p) {
  if (p) free(p);
}

void gd_make_friend(person_t*pp, person_t*dashi) {
  pp->the_other_half = dashi;
  dashi->the_other_half = pp;
}

void gd_do_it(person_t*pp) {
  if (pp->do_it) {
    (*pp->do_it)(pp, pp->the_other_half);
  }
}

int main(int argc, char *argv[]) {
  person_t *pp = gd_create_person("pp", 0);
  person_t *dashi = gd_create_person("dashi", 0);
  gd_make_friend(pp, dashi);
  gd_do_it(dashi);
  gd_delete_person(pp);
  gd_delete_person(dashi);
  return 0;
}