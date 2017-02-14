#include <chl/chl.h>
#include <chl/mysql.h>

void db_connect() {
  chl_mysql_toggle_errors(ERRORS_STATE_TRUE);

  if(! chl_mysql_connect("127.0.0.1", "root", "root", "cocks"))
    return;
}

void insert_data() {
  char * query = malloc(2000);
  snprintf(query, 2000, "INSERT INTO dicks (width,length,name,country,age) VALUES (%s,%s,'%s','%s',%s)", chl_post("width"), chl_post("length"), chl_post("name"), chl_post("country"), chl_post("age"));


  chl_mysql_query(query);
}

void _get_average(char * args) {
  int avg_length = 0;
  int avg_width = 0;
  int nr = 0;

  chl_mysql_query("SELECT width,length FROM dicks");
  
  MYSQL_ROW row;
  while((row = chl_mysql_next_row())) {
    nr++;
    avg_width += (int) strtol(row[0], (char **) NULL, 10);
    avg_length += (int) strtol(row[1], (char **) NULL, 10);
  }
  
  chl_mysql_free_result();

  printf("<p>Average circ: %d - your circ: %s</p>", avg_width / nr, chl_post("width"));
  printf("<p>Average length: %d - your length: %s</p>", avg_length / nr, chl_post("length"));
}

int main() {
  chl_func_append("get_average", _get_average);

  if(chl_post("submit")) {
    db_connect();
    insert_data();

    chl_view("results.vw");
  }
  
  chl_mysql_close();
  return 0;
}
