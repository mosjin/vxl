#ifndef mcal_var_basis_cost_h_
#define mcal_var_basis_cost_h_
//:
// \file
// \author Tim Cootes
// \brief Cost function returning variance along given vector

#include <iostream>
#include <iosfwd>
#include <mcal/mcal_single_basis_cost.h>
#include <vnl/io/vnl_io_vector.h>
#include <vnl/io/vnl_io_matrix.h>
#ifdef _MSC_VER
#  include <vcl_msvc_warnings.h>
#endif

//: Cost function returning variance along given vector
class mcal_var_basis_cost : public mcal_single_basis_cost
{
 private:
 public:

  //: Dflt ctor
  mcal_var_basis_cost();

  //: Destructor
  ~mcal_var_basis_cost() override;

  //: Returns true since cost can be computed from the variance.
  bool can_use_variance() const override;

  //: Compute component of the cost function from given basis vector
  // \param[in] unit_basis   Unit vector defining basis direction
  // \param[in] projections  Projections of the dataset onto this basis vector
  double cost(const vnl_vector<double>& unit_basis,
                      const vnl_vector<double>& projections) override;

  //: Compute component of the cost function from given basis vector
  // \param[in] unit_basis Unit vector defining basis direction
  // \param[in] variance   Variance of projections of the dataset onto this basis vector
  double cost_from_variance(const vnl_vector<double>& unit_basis,
                                    double variance) override;

  //: Version number for I/O
  short version_no() const;

  //: Name of the class
  std::string is_a() const override;

  //: Create a copy on the heap and return base class pointer
   mcal_single_basis_cost*  clone()  const override;

  //: Print class to os
  void print_summary(std::ostream& os) const override;

  //: Save class to binary file stream
  void b_write(vsl_b_ostream& bfs) const override;

  //: Load class from binary file stream
  void b_read(vsl_b_istream& bfs) override;

  //: Read initialisation settings from a stream.
  // Parameters:
  // \verbatim
  // {
  //   alpha: 1.0
  // }
  // \endverbatim
  // \throw mbl_exception_parse_error if the parse fails.
  void config_from_stream(std::istream & is) override;
};

#endif // mcal_var_basis_cost_h_
