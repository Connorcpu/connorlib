// The MIT License (MIT) 
// Copyright (c) 2016 Connor Hilarides
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <connorlib/dll.h>
#include <connorlib/rustop.h>
#include <stdint.h>

namespace TOML
{
    namespace FFI
    {
        struct Value;
        struct Array;
        struct Table;

        /// Free a value that you have ownership of
        extern "C" void DLL_IMPORT toml_free_value(Value *value);
        
        /// Create a new Value containing a string, you have ownership of the returned value.
        /// This function will fail and return nullptr if the data is not valid UTF-8.
        extern "C" Value * DLL_IMPORT toml_new_string(Rust::Slice<const char> data);
        /// Create a new Value containing an i64, you have ownership of the returned value.
        extern "C" Value * DLL_IMPORT toml_new_i64(int64_t data);
        /// Create a new Value containing an f64, you have ownership of the returned value.
        extern "C" Value * DLL_IMPORT toml_new_f64(double data);
        /// Create a new Value containing a datetime, you have ownership of the returned value.
        /// This function will fail and return nullptr if the data is not valid UTF-8.
        extern "C" Value * DLL_IMPORT toml_new_datetime(Rust::Slice<const char> data);
        /// Create a new Value containing an array, you have ownership of the returned value.
        extern "C" Value * DLL_IMPORT toml_new_array();
        /// Create a new Value containing a table, you have ownership of the returned value.
        extern "C" Value * DLL_IMPORT toml_new_table();
        
        /// Get a slice containing the UTF-8 data of the string.
        /// Returns false if the value is not a string.
        extern "C" bool DLL_IMPORT toml_get_string(const Value *value, Rust::Slice<const char> *data);
        /// Get the 64-bit integer stored in the value
        /// Returns false if the value is not an i64.
        extern "C" bool DLL_IMPORT toml_get_i64(const Value *value, i64 *data);
        /// Get the 64-bit float stored in the value.
        /// Returns false if the value is not an f64.
        extern "C" bool DLL_IMPORT toml_get_f64(const Value *value, f64 *data);
        /// Get a slice containing the UTF-8 data of the datetime.
        /// Returns false if the value is not a datetime.
        extern "C" bool DLL_IMPORT toml_get_datetime(const Value *value, Rust::Slice<const char> *data);
        /// Get an immutable view of the array contained in this value.
        /// Returns false if the value is not an array.
        extern "C" bool DLL_IMPORT toml_get_array(const Value *value, const Array **data);
        /// Get a mutable view of the array contained in this value.
        /// Returns false if the value is not an array.
        extern "C" bool DLL_IMPORT toml_get_array_mut(Value *value, Array **data);
        /// Get an immutable view of the table contained in this value.
        /// Returns false if the value is not a table.
        extern "C" bool DLL_IMPORT toml_get_table(const Value *value, const Table **data);
        /// Get a mutable view of the table contained in this value.
        /// Returns false if the value is not a table.
        extern "C" bool DLL_IMPORT toml_get_table_mut(Value *value, Table **data);
        
        /// Sets the value to be a String containing the data.
        /// Returns false and makes no changes to the value if the data is not valid UTF-8.
        extern "C" bool DLL_IMPORT toml_set_string(Value *value, Rust::Slice<const char> data);
    }
}
