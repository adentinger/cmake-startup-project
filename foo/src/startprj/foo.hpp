#ifndef FOO_FOO_HPP_
// It's a good idea to name include guard macros something like
// <PRJNAME>_<DIR>_..._<DIR>_<FILENAME>_H_ ....
//
// 1) ...so that it doesn't conflict with other headers that have the same
// basename in the same project (thus the <DIR>_..._<DIR>) or in other projects
// (thus the initial <PRJNAME>), and...
//
// 2) ...so that a regex that matches only include guard macros can easily be
// made, which allows tools like clang-format to know to ignore these macros
// when validating that their names are according to project standard.
#define FOO_FOO_HPP_

namespace startprj {

}  // namespace startprj

#endif
