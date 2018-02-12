int partition(char *str_to_part, int low, int high) {
  int first_high = 0;
  int p = high;

  for (int i=0; *(str_to_part+i); i++) {
    if(*(str_to_part + high) > *(str_to_part+i)) {
      swap(*(str_to_part+i),*(str_to_part+first_high));
      first_high++;
    }
  }

  swap(*(str_to_part+high), *(str_to_part+first_high));
  return first_high;
}

void quicksort(char *str_to_sort, int low, int high) {
  if (*str_to_sort) return;
  else if (low < high) {
    int p = partition(str_to_sort, low, high);
    quicksort(str_to_sort, low, p-1);
    quicksort(str_to_sort, p+1, high);
  }
}

bool unique_string(char *str_to_unique) {
  quicksort(str_to_unique, 0, *str_to_unique.size()-1);
  
  for (char *it = str_to_unique; *it; ++it)
    if (*it == *(it+1)) return false;
  return true;
}

