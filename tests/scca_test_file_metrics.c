/*
 * Library file_metrics type test program
 *
 * Copyright (C) 2011-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "scca_test_libcerror.h"
#include "scca_test_libscca.h"
#include "scca_test_macros.h"
#include "scca_test_memory.h"
#include "scca_test_unused.h"

#include "../libscca/libscca_file_metrics.h"

#if defined( __GNUC__ ) && !defined( LIBSCCA_DLL_IMPORT )

/* Tests the libscca_file_metrics_initialize function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_initialize(
     void )
{
	libcerror_error_t *error                     = NULL;
	libscca_file_metrics_t *file_metrics         = NULL;
	libscca_filename_strings_t *filename_strings = NULL;
	int result                                   = 0;

#if defined( HAVE_SCCA_TEST_MEMORY )
	int number_of_malloc_fail_tests              = 1;
	int number_of_memset_fail_tests              = 1;
	int test_number                              = 0;
#endif

	/* Initialize test
	 */
	result = libscca_filename_strings_initialize(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libscca_internal_file_metrics_free(
	          (libscca_internal_file_metrics_t **) &file_metrics,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libscca_file_metrics_initialize(
	          NULL,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	file_metrics = (libscca_file_metrics_t *) 0x12345678UL;

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	file_metrics = NULL;

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          NULL,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_SCCA_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libscca_file_metrics_initialize with malloc failing
		 */
		scca_test_malloc_attempts_before_fail = test_number;

		result = libscca_file_metrics_initialize(
		          &file_metrics,
		          filename_strings,
		          &error );

		if( scca_test_malloc_attempts_before_fail != -1 )
		{
			scca_test_malloc_attempts_before_fail = -1;

			if( file_metrics != NULL )
			{
				libscca_internal_file_metrics_free(
				 (libscca_internal_file_metrics_t **) &file_metrics,
				 NULL );
			}
		}
		else
		{
			SCCA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			SCCA_TEST_ASSERT_IS_NULL(
			 "file_metrics",
			 file_metrics );

			SCCA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libscca_file_metrics_initialize with memset failing
		 */
		scca_test_memset_attempts_before_fail = test_number;

		result = libscca_file_metrics_initialize(
		          &file_metrics,
		          filename_strings,
		          &error );

		if( scca_test_memset_attempts_before_fail != -1 )
		{
			scca_test_memset_attempts_before_fail = -1;

			if( file_metrics != NULL )
			{
				libscca_internal_file_metrics_free(
				 (libscca_internal_file_metrics_t **) &file_metrics,
				 NULL );
			}
		}
		else
		{
			SCCA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			SCCA_TEST_ASSERT_IS_NULL(
			 "file_metrics",
			 file_metrics );

			SCCA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_SCCA_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libscca_filename_strings_free(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_metrics != NULL )
	{
		libscca_internal_file_metrics_free(
		 (libscca_internal_file_metrics_t **) &file_metrics,
		 NULL );
	}
	if( filename_strings != NULL )
	{
		libscca_filename_strings_free(
		 &filename_strings,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBSCCA_DLL_IMPORT ) */

/* Tests the libscca_file_metrics_free function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libscca_file_metrics_free(
	          NULL,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libscca_file_metrics_get_utf8_filename_size function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_get_utf8_filename_size(
     void )
{
	libcerror_error_t *error                     = NULL;
	libscca_file_metrics_t *file_metrics         = NULL;
	libscca_filename_strings_t *filename_strings = NULL;
	size_t utf8_filename_size                    = 0;
	int result                                   = 0;
	int utf8_filename_size_is_set                = 0;

	/* Initialize test
	 */
	result = libscca_filename_strings_initialize(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libscca_file_metrics_get_utf8_filename_size(
	          file_metrics,
	          &utf8_filename_size,
	          &error );

	SCCA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_filename_size_is_set = result;

	/* Test error cases
	 */
	result = libscca_file_metrics_get_utf8_filename_size(
	          NULL,
	          &utf8_filename_size,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_filename_size_is_set != 0 )
	{
		result = libscca_file_metrics_get_utf8_filename_size(
		          file_metrics,
		          NULL,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libscca_file_metrics_free(
	          &file_metrics,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
	result = libscca_filename_strings_free(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_metrics != NULL )
	{
		libscca_file_metrics_free(
		 &file_metrics,
		 NULL );
	}
	if( filename_strings != NULL )
	{
		libscca_filename_strings_free(
		 &filename_strings,
		 NULL );
	}
	return( 0 );
}

/* Tests the libscca_file_metrics_get_utf8_filename function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_get_utf8_filename(
     void )
{
	uint8_t utf8_filename[ 512 ];

	libcerror_error_t *error                     = NULL;
	libscca_file_metrics_t *file_metrics         = NULL;
	libscca_filename_strings_t *filename_strings = NULL;
	int result                                   = 0;
	int utf8_filename_is_set                     = 0;

	/* Initialize test
	 */
	result = libscca_filename_strings_initialize(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libscca_file_metrics_get_utf8_filename(
	          file_metrics,
	          utf8_filename,
	          512,
	          &error );

	SCCA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_filename_is_set = result;

	/* Test error cases
	 */
	result = libscca_file_metrics_get_utf8_filename(
	          NULL,
	          utf8_filename,
	          512,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_filename_is_set != 0 )
	{
		result = libscca_file_metrics_get_utf8_filename(
		          file_metrics,
		          NULL,
		          512,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libscca_file_metrics_get_utf8_filename(
		          file_metrics,
		          utf8_filename,
		          0,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libscca_file_metrics_get_utf8_filename(
		          file_metrics,
		          utf8_filename,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libscca_file_metrics_free(
	          &file_metrics,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
	result = libscca_filename_strings_free(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_metrics != NULL )
	{
		libscca_file_metrics_free(
		 &file_metrics,
		 NULL );
	}
	if( filename_strings != NULL )
	{
		libscca_filename_strings_free(
		 &filename_strings,
		 NULL );
	}
	return( 0 );
}

/* Tests the libscca_file_metrics_get_utf16_filename_size function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_get_utf16_filename_size(
     void )
{
	libcerror_error_t *error                     = NULL;
	libscca_file_metrics_t *file_metrics         = NULL;
	libscca_filename_strings_t *filename_strings = NULL;
	size_t utf16_filename_size                   = 0;
	int result                                   = 0;
	int utf16_filename_size_is_set               = 0;

	/* Initialize test
	 */
	result = libscca_filename_strings_initialize(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libscca_file_metrics_get_utf16_filename_size(
	          file_metrics,
	          &utf16_filename_size,
	          &error );

	SCCA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_filename_size_is_set = result;

	/* Test error cases
	 */
	result = libscca_file_metrics_get_utf16_filename_size(
	          NULL,
	          &utf16_filename_size,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_filename_size_is_set != 0 )
	{
		result = libscca_file_metrics_get_utf16_filename_size(
		          file_metrics,
		          NULL,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libscca_file_metrics_free(
	          &file_metrics,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
	result = libscca_filename_strings_free(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_metrics != NULL )
	{
		libscca_file_metrics_free(
		 &file_metrics,
		 NULL );
	}
	if( filename_strings != NULL )
	{
		libscca_filename_strings_free(
		 &filename_strings,
		 NULL );
	}
	return( 0 );
}

/* Tests the libscca_file_metrics_get_utf16_filename function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_get_utf16_filename(
     void )
{
	uint16_t utf16_filename[ 512 ];

	libcerror_error_t *error                     = NULL;
	libscca_file_metrics_t *file_metrics         = NULL;
	libscca_filename_strings_t *filename_strings = NULL;
	int result                                   = 0;
	int utf16_filename_is_set                    = 0;

	/* Initialize test
	 */
	result = libscca_filename_strings_initialize(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libscca_file_metrics_get_utf16_filename(
	          file_metrics,
	          utf16_filename,
	          512,
	          &error );

	SCCA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_filename_is_set = result;

	/* Test error cases
	 */
	result = libscca_file_metrics_get_utf16_filename(
	          NULL,
	          utf16_filename,
	          512,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_filename_is_set != 0 )
	{
		result = libscca_file_metrics_get_utf16_filename(
		          file_metrics,
		          NULL,
		          512,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libscca_file_metrics_get_utf16_filename(
		          file_metrics,
		          utf16_filename,
		          0,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libscca_file_metrics_get_utf16_filename(
		          file_metrics,
		          utf16_filename,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libscca_file_metrics_free(
	          &file_metrics,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
	result = libscca_filename_strings_free(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_metrics != NULL )
	{
		libscca_file_metrics_free(
		 &file_metrics,
		 NULL );
	}
	if( filename_strings != NULL )
	{
		libscca_filename_strings_free(
		 &filename_strings,
		 NULL );
	}
	return( 0 );
}

/* Tests the libscca_file_metrics_get_file_reference function
 * Returns 1 if successful or 0 if not
 */
int scca_test_file_metrics_get_file_reference(
     void )
{
	libcerror_error_t *error                     = NULL;
	libscca_file_metrics_t *file_metrics         = NULL;
	libscca_filename_strings_t *filename_strings = NULL;
	uint64_t file_reference                      = 0;
	int file_reference_is_set                    = 0;
	int result                                   = 0;

	/* Initialize test
	 */
	result = libscca_filename_strings_initialize(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libscca_file_metrics_initialize(
	          &file_metrics,
	          filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libscca_file_metrics_get_file_reference(
	          file_metrics,
	          &file_reference,
	          &error );

	SCCA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	file_reference_is_set = result;

	/* Test error cases
	 */
	result = libscca_file_metrics_get_file_reference(
	          NULL,
	          &file_reference,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	SCCA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( file_reference_is_set != 0 )
	{
		result = libscca_file_metrics_get_file_reference(
		          file_metrics,
		          NULL,
		          &error );

		SCCA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		SCCA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libscca_file_metrics_free(
	          &file_metrics,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "file_metrics",
	 file_metrics );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
	result = libscca_filename_strings_free(
	          &filename_strings,
	          &error );

	SCCA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	SCCA_TEST_ASSERT_IS_NULL(
	 "filename_strings",
	 filename_strings );

	SCCA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_metrics != NULL )
	{
		libscca_file_metrics_free(
		 &file_metrics,
		 NULL );
	}
	if( filename_strings != NULL )
	{
		libscca_filename_strings_free(
		 &filename_strings,
		 NULL );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc SCCA_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] SCCA_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc SCCA_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] SCCA_TEST_ATTRIBUTE_UNUSED )
#endif
{
	SCCA_TEST_UNREFERENCED_PARAMETER( argc )
	SCCA_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBSCCA_DLL_IMPORT )

	SCCA_TEST_RUN(
	 "libscca_file_metrics_initialize",
	 scca_test_file_metrics_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBSCCA_DLL_IMPORT ) */

	SCCA_TEST_RUN(
	 "libscca_file_metrics_free",
	 scca_test_file_metrics_free );

#if defined( TODO )

	SCCA_TEST_RUN(
	 "libscca_file_metrics_get_utf8_filename_size",
	 scca_test_file_metrics_get_utf8_filename_size );

	SCCA_TEST_RUN(
	 "libscca_file_metrics_get_utf8_filename",
	 scca_test_file_metrics_get_utf8_filename );

	SCCA_TEST_RUN(
	 "libscca_file_metrics_get_utf16_filename_size",
	 scca_test_file_metrics_get_utf16_filename_size );

	SCCA_TEST_RUN(
	 "libscca_file_metrics_get_utf16_filename",
	 scca_test_file_metrics_get_utf16_filename );

	SCCA_TEST_RUN(
	 "libscca_file_metrics_get_file_reference",
	 scca_test_file_metrics_get_file_reference );

#endif /* defined( TODO ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

