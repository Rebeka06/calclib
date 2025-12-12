# test_poly 
add_executable(test_poly test_poly.c) 
target_link_libraries(test_poly PRIVATE calclib) 
add_test(NAME test_poly COMMAND test_poly)

# test_matrix
add_executable(test_matrix test_matrix.c) 
target_link_libraries(test_matrix PRIVATE calclib) 
add_test(NAME test_matrix COMMAND test_matrix)

# test_calculus
add_executable(test_calculus test_calculus.c) 
target_link_libraries(test_calculus PRIVATE calclib) 
add_test(NAME test_calculus COMMAND test_calculus)

# test_frac
add_executable(test_frac test_frac.c)
target_link_libraries(test_frac PRIVATE calclib) 
add_test(NAME test_frac COMMAND test_frac)

# test_trig
add_executable(test_trig test_trig.c) 
target_link_libraries(test_trig PRIVATE calclib) 
add_test(NAME test_trig COMMAND test_trig)
