#include <vcl_iostream.h>
#include <vcl_fstream.h>
#include <vcl_utility.h>

#include <vnl/vnl_test.h>
#include <vnl/vnl_math.h>
#include <vnl/vnl_vector.h>
#include <vnl/vnl_matrix_fixed.h>



void test_matrix_fixed_double_2_2_io()
{
    vcl_cout << "***********************" << vcl_endl;
    vcl_cout << "Testing vnl_matrix_fixed<double,2,2> io" << vcl_endl;
    vcl_cout << "***********************" << vcl_endl;  
    //// test constructors, accessors
     double datablock[4] = {
    1.1, 1.2,
    2.1, 2.2
     };
    vnl_matrix_fixed<double,2,2> m_out(datablock), m_in;
    
    vsl_b_ofstream bfs_out("vnl_matrix__fixed_io.tmp", 
            vcl_ios::out | vcl_ios::binary);
    TEST ("vnl_matrix__fixed_io.tmp for writing", (!bfs_out), false);
    vsl_b_write(bfs_out, m_out);
    bfs_out.close();        
        
    vsl_b_ifstream bfs_in("vnl_matrix__fixed_io.tmp", 
            vcl_ios::in | vcl_ios::binary);
    TEST ("vnl_matrix__fixed_io.tmp for reading", (!bfs_in), false);
    vsl_b_read(bfs_in, m_in);
    bfs_in.close();     
        
    
    
    TEST ("m_out == m_in", m_out == m_in, true);

  vsl_print_summary(vcl_cout, m_out);
  vcl_cout << vcl_endl;

  
}




   
void test_matrix_fixed_prime()
{
  test_matrix_fixed_double_2_2_io();
}


TESTMAIN(test_matrix_fixed_prime);
