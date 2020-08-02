#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_to_int(char ch) {
  return (int)(ch - 48);
}

char convert_to_char(int in) {
  return (char)(in + 48);
}

char itooa(int i) {
    if (i == 0) {
        return '0';
    }
    else if (i == 1) {
        return '1';
    }
    else if (i == 2) {
        return '2';
    }
    else if (i == 3) {
        return '3';
    }
    else if (i == 4) {
        return '4';
    }
    else if (i == 5) {
        return '5';
    }
    else if (i == 6) {
        return '6';
    }
    else if (i == 7) {
        return '7';
    }
    else if (i == 8) {
        return '8';
    }
    else {
        return '9';
    }
}

char* itoaa(int i) {
    if (i == 0) {
        return "0\0";
    }
    else if (i == 1) {
        return "1\0";
    }
    else if (i == 2) {
        return "2\0";
    }
    else if (i == 3) {
        return "3\0";
    }
    else if (i == 4) {
        return "4\0";
    }
    else if (i == 5) {
        return "5\0";
    }
    else if (i == 6) {
        return "6\0";
    }
    else if (i == 7) {
        return "7\0";
    }
    else if (i == 8) {
        return "8\0";
    }
    else {
        return "9\0";
    }
}

char* strip(char* str) {

    int i;
    
    for (i = 0; i < strlen(str); i++) {
        if(str[i] != '0') break;
    }
    
    int l = strlen(str) - i + 1;
    
    char* temp = (char*) malloc(sizeof(char) * (l));
    temp[0] = '\0';

    return strcat(temp, str+i);
}

char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}

int intal_compare(const char* intal1, const char* intal2) {
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);

    if (len1 == len2) {

        for (int i = 0; i < len1; i++) {
            
            if (intal1[i] > intal2[i]) return 1;
            else if (intal1[i] < intal2[i]) return -1;
            else continue;

        }

        return 0;
    }
    else if (len1 > len2) return 1;
    else return -1;

}

char* intal_add(const char* intal1, const char* intal2) {

    int len1 = strlen(intal1);
    int len2 = strlen(intal2);

    char* x = (char*) malloc(sizeof(char) * 1001);
    x[0] = '\0';
    char* y = (char*) malloc(sizeof(char) * 1001);
    y[0] = '\0';

    strcpy(x, intal1);
    strcpy(y, intal2);

    strrev(y);
    strrev(x);

    char* res = (char*) malloc(sizeof(char) * 1001);
    res[0] = '\0';

    if (len1 != len2) {
        int flag = 0;
        if (len1 > len2) flag = 1;

        if (!flag) {

            for(int i = len1; i < len2; i++) {
                strcat(x, itoaa(0));
            }

        }
        else {

            for (int i = len2; i < len1; i++) {
                strcat(y, itoaa(0));
            }

        }
    }

    int carry = 0, sum = 0;

    for (int i = 0; i < (len1 > len2? len1 : len2); i++) {
        int a = (int) x[i] - 48;
        int b = (int) y[i] - 48;

        sum = a + b + carry;
        
        if(sum >= 10) {
            carry = 1;
            sum = sum % 10;
        }
        else carry = 0;
        
        strcat(res, itoaa(sum));
    }

    if (carry == 1) strcat(res, itoaa(carry));

    strrev(res);

    free(x);
    free(y);

    return res;
}

char* intal_diff(const char* intal1, const char* intal2) {
    
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);

    char* x = (char*) malloc(sizeof(char) * 1001);
    x[0] = '\0';
    char* y = (char*) malloc(sizeof(char) * 1001);
    y[0] = '\0';

    strcpy(x, intal1);
    strcpy(y, intal2);

    strrev(y);
    strrev(x);

    int flag = intal_compare(intal1, intal2);

    char* res = (char*) malloc(sizeof(char) * 1001);
    res[0] = '\0';

    int i, dif, borrow = 0;

    if (!flag) return strcat(res, "0\0");
    else {

        for (i = 0; i < (len1 < len2? len1 : len2); i++) {

            if (flag == 1) dif = (int) x[i] - (int) y[i] - borrow;
            else dif = (int) y[i] - (int) x[i] - borrow;

            if (dif < 0) {
                borrow = 1;
                dif = 10 + dif;
                strcat(res, itoaa(dif));
            }
            else {
                borrow = 0;
                strcat(res, itoaa(dif));
            }

        }

        if (len1 == len2) return strcat(strrev(res), "\0");
        else {

            for (; i < (len1 > len2? len1 : len2); i++) {

                if (flag == 1) dif = (int) x[i] - borrow - 48;
                else if (flag == -1) dif = (int) y[i] - borrow - 48;

                if (dif < 0) {
                    
                    borrow = 1;
                    dif = 10 + dif;
                    strcat(res, itoaa(dif));
                    
                }
                else {

                    borrow = 0;
                    strcat(res, itoaa(dif));
                    
                }

            }

            strrev(res);
            char* temp = strip(res);
            free(x);
            free(y);
            free(res);
            return temp;

        }

    }
}

char* intal_multiply(char* intal1, char* intal2) {
  if(strcmp(intal1, "0") == 0 || strcmp(intal2, "0") == 0) {
    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = '0';
    result[1] = '\0';
    return result;
  }

  int i, j, d1, d2, d3, rd, c = 0;
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);

  int l = l1 + l2;
  char* result = (char*)malloc((l + 1) * sizeof(char));

  for(i = 0; i < l; ++i)
    result[i] = '0';

  for(i = 0; i < l1; ++i) {
    c = 0;
    for(j = 0; j < l2; ++j) {
      d1 = convert_to_int(intal1[l1 - 1 - i]);
      d2 = convert_to_int(intal2[l2 - 1 - j]);
      d3 = convert_to_int(result[l - 1 - i - j]);

      rd = (d1 * d2) + c + d3;
      c = rd / 10;
      rd = rd % 10;

      result[l - 1 - i - j] = convert_to_char(rd);
    }

    for(j = l2 + i; j < l2 + l1; ++j) {
      int d3 = convert_to_int(result[l - 1 - j]);

      rd = c + d3;
      c = rd / 10;
      rd = rd % 10;
      result[l - 1 - j] = convert_to_char(rd);
    }
  }

  result[l] = '\0';
  if(result[0] == '0') {
    for(i = 0; i <= l; ++i)
      result[i] = result[i + 1];

    result = realloc(result, l * sizeof(char));
  }


  return result;
}

char* intal_mod(char* intal1, char* intal2) {

    if (intal_compare(intal1, "0\0") == 0 || intal_compare(intal2, "0\0") == 0) {
        char* res = (char*) malloc(sizeof(char) * 1001);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    int cmp = intal_compare(intal1, intal2);
    if(cmp == -1) {
        char* result = (char*)malloc(1001 * sizeof(char));
        result[0] = '\0';
        strcat(result, intal1);
        return result;
    } else if(cmp == 0) {
        char* result = (char*)malloc(1001 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int p = strlen(intal2);
    int stop = strlen(intal1);
    char* current = (char*)malloc(1001 * sizeof(char));
    for(int i = 0; i < p; ++i)
        current[i] = intal1[i];
    current[p] = '\0';

    do {
        if(intal_compare(current, intal2) == -1 && p < stop) {
        int len = strlen(current);
        if(intal_compare(current, "0\0") == 0)
            len = 0;
        current[len] = intal1[p];
        current[len + 1] = '\0';
        ++p;
        }

        if(intal_compare(current, intal2) != -1){
        char* result = intal_diff(current, intal2);
        while(intal_compare(result, intal2) > -1) {
            char* tmp = result;
            result = intal_diff(result, intal2);
            free(tmp);
        }
        
        strcpy(current, result);
        free(result);
        }    
    } while(p < stop);

    current = realloc(current, (strlen(current) + 1) * sizeof(char));
    current[strlen(current) + 1] = '\0';
    char* t = strip(current);
    free(current);
    current = t;
    t = NULL;
    free(t);
    if (strlen(current) == 0) {
        char *lol = (char*) malloc(sizeof(char) * 1001);
        lol[0] = '0';
        lol[1] = '\0';
        return lol;
    }
    return current;
}

char* intal_pow(const char* intal1, unsigned int n) {
    if (n == 0) {
        char* temp = (char*) malloc(sizeof(char) * 2);
        temp[0] = '1';
        temp[1] = '\0';
        return temp;
    }
    else if (intal_compare(intal1, "1\0") == 0) {
        char* temp = (char*) malloc(sizeof(char) * 2);
        temp[0] = '1';
        temp[1] = '\0';
        return temp;
    }
    else {

        char* res = (char*) malloc(sizeof(char) * 1001);
        res[0] = '1';
        res[1] = '\0';

        char* temp1 = (char*) malloc(sizeof(char) * 1001);
        temp1[0] = '\0';
        strcpy(temp1, intal1);

        char* temp2;
        // printf("here\n");
        for (int i = 0; i < n; i++) {

            temp2 = intal_multiply(res, temp1);

            char* temp3 = res;
            res = temp2;
            free(temp3);

            temp2 = NULL;

        }

        free(temp2);
        free(temp1);
        return res;
    }
}

char* intal_gcd(char* intal1, char* intal2) {

    char* a = (char*)malloc(sizeof(char) * 1001);
    a[0] = '\0';
    strcat(a, intal1);
    char* b = (char*)malloc(1001 * sizeof(char));
    b[0] = '\0';
    strcat(b, intal2);

    int flag = intal_compare(a, b);

    char* temp1, *temp2;

    while(intal_compare(a, "0\0") != 0 && intal_compare(b, "0\0") != 0) {
        if (flag == 1) {
            temp1 = intal_mod(a, b);
            temp2 = a;
            a = temp1;
            free(temp2);
            temp2 = NULL;
            temp1 = NULL;
        }
        else {
            temp1 = intal_mod(b, a);
            temp2 = b;
            b = temp1;
            free(temp2);
            temp2 = NULL;
            temp1 = NULL;
        }

        flag = intal_compare(a, b);
    }

    free(temp1);
    free(temp2);

    if (intal_compare(a, "0\0") == 0) {
        free(a);
        return b;
    }
    else {
        free(b);
        return a;
    }
}

char* intal_fibonacci(unsigned int n) {
    char* res = (char*) malloc(sizeof(char) * 2);
    res[0] = '0';
    res[1] = '\0';

    char* temp1 = (char*) malloc(sizeof(char) * 2);
    temp1[0] = '1';
    temp1[1] = '\0';

    if (n == 0) {
        free(temp1);
        return res;
    }
    else if (n == 1) {
        free(res);
        return temp1;
    }
    else {

        char* temp2;

        for (int i = 1; i < n; i++) {

            temp2 = intal_add(res, temp1);

            free(res);
            res = temp1;
            temp1 = temp2;
            temp2 = NULL;

        }

        free(res);
        free(temp2);
        return temp1;
    }
}

long long int multiply(long long int x, char* res, long long int res_size) 
{ 
    int carry = 0;
 
    for (long long int i = 0; i < res_size; i++) 
    {
        
        long long int prod = ((int) res[i] - 48) * x + carry;

        res[i] = itooa(prod % 10);

        carry  = prod / 10;     
        
    }

    while (carry)
    {

        // res[res_size] = carry % 10;
        res[res_size] = itooa(carry % 10);
        carry = carry / 10;
        res_size++;
        
    }
     
    return res_size; 
}

char* intal_factorial(unsigned int n) {
    if (n == 0) return "1\0";
    else {

        char* res = (char*) malloc(sizeof(char) * 1001);  
        res[0] = '1';
        long long int res_size = 1; 
    
        for (long long int x = 2; x <= n; x++) res_size = multiply(x, res, res_size);

        res[res_size] = '\0';

        strrev(res);
        return res;
    }
}

char* intal_bincoeff(unsigned int n, unsigned int k) {
  char** c = (char**)malloc((k+1) * sizeof(char*));
  for(int i = 0; i < k + 1; ++i) {
    c[i] = (char*)malloc(2 * sizeof(char));
    c[i][0] = '0';
    c[i][1] = '\0';
  }

  c[0][0] = '1';

  for(int i = 1; i < n + 1; ++i) {
    int j = (i > k)? k: i;
    while(j > 0) {
      char* tmp = c[j];
      c[j] = intal_add(c[j], c[j - 1]);
      free(tmp);
      --j;
    }
  }

  char* result = (char*)malloc((strlen(c[k]) + 1) * sizeof(char));
  strcpy(result, c[k]);
  
  for(int i = 0; i < k + 1; ++i) {
    free(c[i]);
  }
  free(c);

  return result;
}

int intal_max(char **arr, int n) {
    char* temp = arr[0];
    int offset = 0;
    for (int i = 1; i < n; i++) {
        int flag = intal_compare(temp, arr[i]);
        if (flag == 0 || flag == 1) continue;
        else {
            temp = arr[i];
            offset = i;
        }
    }
    return offset;
}

int intal_min(char **arr, int n) {
    char* temp = arr[0];
    int offset;
    for (int i = 1; i < n; i++) {
        int flag = intal_compare(temp, arr[i]);
        if (flag == 0 || flag == -1) continue;
        else {
            temp = arr[i];
            offset = i;
        }
    }

    return offset;
}

int intal_search(char **arr, int n, const char* key) {
    for (int i = 0; i < n; i++) {
        int flag = intal_compare(arr[i], key);
        if(!flag) return i;
    }
    return -1;
}

int bsh(char** arr, int l, int r, char* x) {
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        int temp = intal_compare(arr[mid], x);
        
        if (temp == 0) 
            return mid;

        if (temp == 1) 
            return bsh(arr, l, mid - 1, x); 
   
        return bsh(arr, mid + 1, r, x); 
    } 

    return -1;
}

int intal_binsearch(char **arr, int n, const char* key) {
    char* temp = (char*) malloc(sizeof(char) * 1001);
    temp[0] = '\0';
    strcat(temp, key);
    return bsh(arr, 0, n - 1, temp);
}

void swap(char* a, char* b) 
{ 
    char* t = (char*) malloc(sizeof(char) * 1001); 
    t[0] = '\0';
    strcat(t, a);
    strcpy(a, b);
    strcpy(b, t);
    free(t);
} 

int partition (char** arr, int low, int high) 
{ 
    char* pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        int temp = intal_compare(arr[j], pivot);

        if (temp == -1 || temp == 0) 
        { 
            i++;    // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quickSort(char** arr, int low, int high) 
{ 
    if (low < high) 
    {
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void intal_sort(char **arr, int n) {
    quickSort(arr, 0, n-1);
}

char* coin_row_problem(char **arr, int n) {
  char** f = (char**)malloc((n + 1) * sizeof(char*));
  f[0] = (char*)malloc(2 * sizeof(char));
  f[0][0] = '0';
  f[0][1] = '\0';

  for(int i = 0; i < n; ++i) {
    f[i + 1] = (char*)malloc((strlen(arr[i]) + 1) * sizeof(char));
    strcpy(f[i + 1], arr[i]);
  }

  for(int i = 2; i < n + 1; ++i) {
    char* val = intal_add(arr[i -1], f[i - 2]);
    if(intal_compare(val, f[i - 1]) > 0) {
      char* tmp = f[i];
      f[i] = val;
      free(tmp);
    } else {
      free(f[i]);
      f[i] = (char*) malloc((strlen(f[i - 1]) + 1) * sizeof(char));
      strcpy(f[i], f[i - 1]);
      free(val);
    }
  }

  char* result = (char*)malloc((strlen(f[n]) + 1) * sizeof(char));
  strcpy(result, f[n]);

  for(int i = 0; i < n + 1; ++i) {
    free(f[i]);
  }
  free(f);

  return result;
}