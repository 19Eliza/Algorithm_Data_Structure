#include "stack_class.h"

int main() {
  Stack st;
  std::cout << st.empty() << std::endl;
  std::cout << st.get_top() << std::endl;
  for (auto i : {1, 2, 3, 4, 5})
    st.push(i);
  std::cout << st.get_top() << std::endl;
  st.pop();
  std::cout << st.get_top() << std::endl;
  return 0;
}