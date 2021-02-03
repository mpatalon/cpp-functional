#include <iostream>
#include <string>

#ifndef PERSON_H
#define PERSON_H

class person_t {
 public:
  enum gender_t { female, male, other };

  enum output_format_t { name_only, full_name };

  person_t() : m_name("John"), m_surname("Doe"), m_gender(other) {}

  person_t(std::string name, gender_t gender, int age = 0)
      : m_name(name), m_surname("Doe"), m_gender(gender), m_age(age) {}

  person_t(std::string name, const std::string &surname, gender_t gender,
           int age = 0)
      : m_name(name), m_surname(surname), m_gender(gender), m_age(age) {}

  std::string name() const { return m_name; }

  std::string surname() const { return m_surname; }

  gender_t gender() const { return m_gender; }

  int age() const { return m_age; }

  void print(std::ostream &out, person_t::output_format_t format) const {
    if (format == person_t::name_only) {
      out << name() << '\n';

    } else if (format == person_t::full_name) {
      out << name() << ' ' << surname() << '\n';
    }
  }

 private:
  std::string m_name;
  std::string m_surname;
  gender_t m_gender;
  int m_age;
};

#if 0
bool operator==(const person_t &lhs, const person_t &rhs) {
  std::cout << "operator==\n";
  lhs.print(std::cout, person_t::full_name);
  rhs.print(std::cout, person_t::full_name);

  bool res = lhs.name() == rhs.name();
  if (res != 0) {
    return res;
  }

  res = lhs.surname() == rhs.surname();
  if (res != 0) {
    return res;
  }

  res = lhs.gender() == rhs.gender();
  if (res != 0) {
    return res;
  }

  return lhs.age() == rhs.age();
}

bool operator<(const person_t &lhs, const person_t &rhs) {
  std::cout << "operator<\n";
  lhs.print(std::cout, person_t::full_name);
  rhs.print(std::cout, person_t::full_name);

  bool res = lhs.name() < rhs.name();
  if (res != 0) {
    return res;
  }

  res = lhs.surname() < rhs.surname();
  if (res != 0) {
    return res;
  }

  res = lhs.gender() < rhs.gender();
  if (res != 0) {
    return res;
  }

  return lhs.age() < rhs.age();
}
#endif

#if 0
auto operator<=>(const person_t &lhs, const person_t &rhs) {
  std::cout << "operator<=>\n";
  lhs.print(std::cout, person_t::full_name);
  rhs.print(std::cout, person_t::full_name);

  auto res = lhs.name() <=> rhs.name();
  if (res != 0) {
    return res;
  }

  res = lhs.surname() <=> rhs.surname();
  if (res != 0) {
    return res;
  }

  res = lhs.gender() <=> rhs.gender();
  if (res != 0) {
    return res;
  }

  return lhs.age() <=> rhs.age();
}
#endif

#endif  // PERSON_H
