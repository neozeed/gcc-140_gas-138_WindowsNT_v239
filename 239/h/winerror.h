/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991  Microsoft Corporation

Module Name:

    winerror.h

Abstract:

    This file contains the error code definitions for the Win32 API
    functions.

Created:

    25-Jan-1991

Revision History:

Notes:

    This file is generated by the MC tool from the winerror.msg file.

--*/

#ifndef _WINERROR_
#define _WINERROR_


//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: NO_ERROR
//
// MessageText:
//
//  NO_ERROR
//
#define NO_ERROR                         0L

//
// MessageId: ERROR_INVALID_FUNCTION
//
// MessageText:
//
//  Incorrect function
//
#define ERROR_INVALID_FUNCTION           1L

//
// MessageId: ERROR_FILE_NOT_FOUND
//
// MessageText:
//
//  The system cannot find the file specified.
//
#define ERROR_FILE_NOT_FOUND             2L

//
// MessageId: ERROR_PATH_NOT_FOUND
//
// MessageText:
//
//  The system cannot find the path specified.
//
#define ERROR_PATH_NOT_FOUND             3L

//
// MessageId: ERROR_TOO_MANY_OPEN_FILES
//
// MessageText:
//
//  The system cannot open the file.
//
#define ERROR_TOO_MANY_OPEN_FILES        4L

//
// MessageId: ERROR_ACCESS_DENIED
//
// MessageText:
//
//  Access Denied.
//
#define ERROR_ACCESS_DENIED              5L

//
// MessageId: ERROR_INVALID_HANDLE
//
// MessageText:
//
//  Incorrect internal file identifier.
//
#define ERROR_INVALID_HANDLE             6L

//
// MessageId: ERROR_ARENA_TRASHED
//
// MessageText:
//
//  The storage control blocks were destroyed.
//
#define ERROR_ARENA_TRASHED              7L

//
// MessageId: ERROR_NOT_ENOUGH_MEMORY
//
// MessageText:
//
//  Not enough storage is available to
//  process this command.
//
#define ERROR_NOT_ENOUGH_MEMORY          8L

//
// MessageId: ERROR_INVALID_BLOCK
//
// MessageText:
//
//  The storage control block address is invalid.
//
#define ERROR_INVALID_BLOCK              9L

//
// MessageId: ERROR_BAD_ENVIRONMENT
//
// MessageText:
//
//  The environment is incorrect.
//
#define ERROR_BAD_ENVIRONMENT            10L

//
// MessageId: ERROR_BAD_FORMAT
//
// MessageText:
//
//  An attempt was made to load a program with an
//  incorrect format.
//
#define ERROR_BAD_FORMAT                 11L

//
// MessageId: ERROR_INVALID_ACCESS
//
// MessageText:
//
//  The access code is invalid.
//
#define ERROR_INVALID_ACCESS             12L

//
// MessageId: ERROR_INVALID_DATA
//
// MessageText:
//
//  The data is invalid.
//
#define ERROR_INVALID_DATA               13L

//
// MessageId: ERROR_INVALID_DRIVE
//
// MessageText:
//
//  The system cannot find the drive specified.
//
#define ERROR_INVALID_DRIVE              15L

//
// MessageId: ERROR_CURRENT_DIRECTORY
//
// MessageText:
//
//  The directory cannot be removed.
//
#define ERROR_CURRENT_DIRECTORY          16L

//
// MessageId: ERROR_NOT_SAME_DEVICE
//
// MessageText:
//
//  The system cannot move the file
//  to a different disk drive.
//
#define ERROR_NOT_SAME_DEVICE            17L

//
// MessageId: ERROR_NO_MORE_FILES
//
// MessageText:
//
//  There are no more files.
//
#define ERROR_NO_MORE_FILES              18L

//
// MessageId: ERROR_WRITE_PROTECT
//
// MessageText:
//
//  The diskette is write protected.
//
#define ERROR_WRITE_PROTECT              19L

//
// MessageId: ERROR_BAD_UNIT
//
// MessageText:
//
//  The system cannot find the device specified.
//
#define ERROR_BAD_UNIT                   20L

//
// MessageId: ERROR_NOT_READY
//
// MessageText:
//
//  The drive is not ready.
//
#define ERROR_NOT_READY                  21L

//
// MessageId: ERROR_BAD_COMMAND
//
// MessageText:
//
//  The device does not recognize the command.
//
#define ERROR_BAD_COMMAND                22L

//
// MessageId: ERROR_CRC
//
// MessageText:
//
//  Data error (cyclic redundancy check)
//
#define ERROR_CRC                        23L

//
// MessageId: ERROR_BAD_LENGTH
//
// MessageText:
//
//  The program issued a command but the
//  command length is incorrect.
//
#define ERROR_BAD_LENGTH                 24L

//
// MessageId: ERROR_SEEK
//
// MessageText:
//
//  The drive cannot locate a specific
//  area or track on the disk.
//
#define ERROR_SEEK                       25L

//
// MessageId: ERROR_NOT_DOS_DISK
//
// MessageText:
//
//  The specified disk or diskette cannot be accessed.
//
#define ERROR_NOT_DOS_DISK               26L

//
// MessageId: ERROR_SECTOR_NOT_FOUND
//
// MessageText:
//
//  The drive cannot find the sector requested.
//
#define ERROR_SECTOR_NOT_FOUND           27L

//
// MessageId: ERROR_OUT_OF_PAPER
//
// MessageText:
//
//  The printer is out of paper.
//
#define ERROR_OUT_OF_PAPER               28L

//
// MessageId: ERROR_WRITE_FAULT
//
// MessageText:
//
//  The system cannot write to the specified device.
//
#define ERROR_WRITE_FAULT                29L

//
// MessageId: ERROR_READ_FAULT
//
// MessageText:
//
//  The system cannot read from the specified device.
//
#define ERROR_READ_FAULT                 30L

//
// MessageId: ERROR_GEN_FAILURE
//
// MessageText:
//
//  A device attached to the system is not functioning.
//
#define ERROR_GEN_FAILURE                31L

//
// MessageId: ERROR_SHARING_VIOLATION
//
// MessageText:
//
//  The process cannot access the file because
//  it is being used by another process.
//
#define ERROR_SHARING_VIOLATION          32L

//
// MessageId: ERROR_LOCK_VIOLATION
//
// MessageText:
//
//  The process cannot access the file because
//  another process has locked a portion of the file.
//
#define ERROR_LOCK_VIOLATION             33L

//
// MessageId: ERROR_WRONG_DISK
//
// MessageText:
//
//  The wrong diskette is in the drive.
//  Insert %2 (Volume Serial Number: %3)
//  into drive %1.
//
#define ERROR_WRONG_DISK                 34L

//
// MessageId: ERROR_SHARING_BUFFER_EXCEEDED
//
// MessageText:
//
//  Too many files opened for sharing.
//
#define ERROR_SHARING_BUFFER_EXCEEDED    36L

//
// MessageId: ERROR_HANDLE_EOF
//
// MessageText:
//
//  Reached End of File.
//
#define ERROR_HANDLE_EOF                 38L

//
// MessageId: ERROR_HANDLE_DISK_FULL
//
// MessageText:
//
//  The disk is full.
//
#define ERROR_HANDLE_DISK_FULL           39L

//
// MessageId: ERROR_NOT_SUPPORTED
//
// MessageText:
//
//  The network request is not supported.
//
#define ERROR_NOT_SUPPORTED              50L

//
// MessageId: ERROR_REM_NOT_LIST
//
// MessageText:
//
//  The remote computer is not available.
//
#define ERROR_REM_NOT_LIST               51L

//
// MessageId: ERROR_DUP_NAME
//
// MessageText:
//
//  A duplicate name exists on the network.
//
#define ERROR_DUP_NAME                   52L

//
// MessageId: ERROR_BAD_NETPATH
//
// MessageText:
//
//  The network path was not found.
//
#define ERROR_BAD_NETPATH                53L

//
// MessageId: ERROR_NETWORK_BUSY
//
// MessageText:
//
//  The network is busy.
//
#define ERROR_NETWORK_BUSY               54L

//
// MessageId: ERROR_DEV_NOT_EXIST
//
// MessageText:
//
//  The specified network resource is no longer
//  available.
//
#define ERROR_DEV_NOT_EXIST              55L

//
// MessageId: ERROR_TOO_MANY_CMDS
//
// MessageText:
//
//  The network BIOS command limit has been reached.
//
#define ERROR_TOO_MANY_CMDS              56L

//
// MessageId: ERROR_ADAP_HDW_ERR
//
// MessageText:
//
//  A network adapter hardware error occurred.
//
#define ERROR_ADAP_HDW_ERR               57L

//
// MessageId: ERROR_BAD_NET_RESP
//
// MessageText:
//
//  The specified server cannot perform the requested
//  operation.
//
#define ERROR_BAD_NET_RESP               58L

//
// MessageId: ERROR_UNEXP_NET_ERR
//
// MessageText:
//
//  An unexpected network error occurred.
//
#define ERROR_UNEXP_NET_ERR              59L

//
// MessageId: ERROR_BAD_REM_ADAP
//
// MessageText:
//
//  The remote adapter is not compatible.
//
#define ERROR_BAD_REM_ADAP               60L

//
// MessageId: ERROR_PRINTQ_FULL
//
// MessageText:
//
//  The printer queue is full.
//
#define ERROR_PRINTQ_FULL                61L

//
// MessageId: ERROR_NO_SPOOL_SPACE
//
// MessageText:
//
//  Space to store the file waiting to be printed is
//  not available on the server.
//
#define ERROR_NO_SPOOL_SPACE             62L

//
// MessageId: ERROR_PRINT_CANCELLED
//
// MessageText:
//
//  Your file waiting to be printed was deleted.
//
#define ERROR_PRINT_CANCELLED            63L

//
// MessageId: ERROR_NETNAME_DELETED
//
// MessageText:
//
//  The specified network name is no longer available.
//
#define ERROR_NETNAME_DELETED            64L

//
// MessageId: ERROR_NETWORK_ACCESS_DENIED
//
// MessageText:
//
//  Network access is denied.
//
#define ERROR_NETWORK_ACCESS_DENIED      65L

//
// MessageId: ERROR_BAD_DEV_TYPE
//
// MessageText:
//
//  The network resource type is not correct.
//
#define ERROR_BAD_DEV_TYPE               66L

//
// MessageId: ERROR_BAD_NET_NAME
//
// MessageText:
//
//  The network name cannot be found.
//
#define ERROR_BAD_NET_NAME               67L

//
// MessageId: ERROR_TOO_MANY_NAMES
//
// MessageText:
//
//  The name limit for the local computer network
//  adapter card was exceeded.
//
#define ERROR_TOO_MANY_NAMES             68L

//
// MessageId: ERROR_TOO_MANY_SESS
//
// MessageText:
//
//  The network BIOS session limit was exceeded.
//
#define ERROR_TOO_MANY_SESS              69L

//
// MessageId: ERROR_SHARING_PAUSED
//
// MessageText:
//
//  The remote server has been paused or is in the
//  process of being started.
//
#define ERROR_SHARING_PAUSED             70L

//
// MessageId: ERROR_REQ_NOT_ACCEP
//
// MessageText:
//
//  The network request was not accepted.
//
#define ERROR_REQ_NOT_ACCEP              71L

//
// MessageId: ERROR_REDIR_PAUSED
//
// MessageText:
//
//  The specified printer or disk device has been paused.
//
#define ERROR_REDIR_PAUSED               72L

//
// MessageId: ERROR_FILE_EXISTS
//
// MessageText:
//
//  The file exists.
//
#define ERROR_FILE_EXISTS                80L

//
// MessageId: ERROR_CANNOT_MAKE
//
// MessageText:
//
//  The directory or file cannot be created.
//
#define ERROR_CANNOT_MAKE                82L

//
// MessageId: ERROR_FAIL_I24
//
// MessageText:
//
//  Fail on INT 24
//
#define ERROR_FAIL_I24                   83L

//
// MessageId: ERROR_OUT_OF_STRUCTURES
//
// MessageText:
//
//  Storage to process this request is not available.
//
#define ERROR_OUT_OF_STRUCTURES          84L

//
// MessageId: ERROR_ALREADY_ASSIGNED
//
// MessageText:
//
//  The local device name is already in use.
//
#define ERROR_ALREADY_ASSIGNED           85L

//
// MessageId: ERROR_INVALID_PASSWORD
//
// MessageText:
//
//  The specified network password is not correct.
//
#define ERROR_INVALID_PASSWORD           86L

//
// MessageId: ERROR_INVALID_PARAMETER
//
// MessageText:
//
//  The parameter is incorrect.
//
#define ERROR_INVALID_PARAMETER          87L

//
// MessageId: ERROR_NET_WRITE_FAULT
//
// MessageText:
//
//  A write fault occurred on the network.
//
#define ERROR_NET_WRITE_FAULT            88L

//
// MessageId: ERROR_NO_PROC_SLOTS
//
// MessageText:
//
//  The system cannot start another process at
//  this time.
//
#define ERROR_NO_PROC_SLOTS              89L

//
// MessageId: ERROR_TOO_MANY_SEMAPHORES
//
// MessageText:
//
//  Cannot create another system semaphore.
//
#define ERROR_TOO_MANY_SEMAPHORES        100L

//
// MessageId: ERROR_EXCL_SEM_ALREADY_OWNED
//
// MessageText:
//
//  The exclusive semaphore is owned by another process.
//
#define ERROR_EXCL_SEM_ALREADY_OWNED     101L

//
// MessageId: ERROR_SEM_IS_SET
//
// MessageText:
//
//  The semaphore is set and cannot be closed.
//
#define ERROR_SEM_IS_SET                 102L

//
// MessageId: ERROR_TOO_MANY_SEM_REQUESTS
//
// MessageText:
//
//  The semaphore cannot be set again.
//
#define ERROR_TOO_MANY_SEM_REQUESTS      103L

//
// MessageId: ERROR_INVALID_AT_INTERRUPT_TIME
//
// MessageText:
//
//  Cannot request exclusive semaphores at interrupt time.
//
#define ERROR_INVALID_AT_INTERRUPT_TIME  104L

//
// MessageId: ERROR_SEM_OWNER_DIED
//
// MessageText:
//
//  The previous ownership of this semaphore has ended.
//
#define ERROR_SEM_OWNER_DIED             105L

//
// MessageId: ERROR_SEM_USER_LIMIT
//
// MessageText:
//
//  Insert the diskette for drive %1.
//
#define ERROR_SEM_USER_LIMIT             106L

//
// MessageId: ERROR_DISK_CHANGE
//
// MessageText:
//
//  Program stopped because alternate diskette was not inserted.
//
#define ERROR_DISK_CHANGE                107L

//
// MessageId: ERROR_DRIVE_LOCKED
//
// MessageText:
//
//  The disk is in use or locked by
//  another process.
//
#define ERROR_DRIVE_LOCKED               108L

//
// MessageId: ERROR_BROKEN_PIPE
//
// MessageText:
//
//  The pipe has been ended.
//
#define ERROR_BROKEN_PIPE                109L

//
// MessageId: ERROR_OPEN_FAILED
//
// MessageText:
//
//  The system cannot open the
//  device or file specified.
//
#define ERROR_OPEN_FAILED                110L

//
// MessageId: ERROR_BUFFER_OVERFLOW
//
// MessageText:
//
//  The file name is too long.
//
#define ERROR_BUFFER_OVERFLOW            111L

//
// MessageId: ERROR_DISK_FULL
//
// MessageText:
//
//  There is not enough space on the disk.
//
#define ERROR_DISK_FULL                  112L

//
// MessageId: ERROR_NO_MORE_SEARCH_HANDLES
//
// MessageText:
//
//  No more internal file identifiers available.
//
#define ERROR_NO_MORE_SEARCH_HANDLES     113L

//
// MessageId: ERROR_INVALID_TARGET_HANDLE
//
// MessageText:
//
//  The target internal file identifier is incorrect.
//
#define ERROR_INVALID_TARGET_HANDLE      114L

//
// MessageId: ERROR_INVALID_CATEGORY
//
// MessageText:
//
//  The IOCTL call made by the application program is
//  not correct.
//
#define ERROR_INVALID_CATEGORY           117L

//
// MessageId: ERROR_INVALID_VERIFY_SWITCH
//
// MessageText:
//
//  The verify-on-write switch parameter value is not
//  correct.
//
#define ERROR_INVALID_VERIFY_SWITCH      118L

//
// MessageId: ERROR_BAD_DRIVER_LEVEL
//
// MessageText:
//
//  The system does not support the command requested.
//
#define ERROR_BAD_DRIVER_LEVEL           119L

//
// MessageId: ERROR_CALL_NOT_IMPLEMENTED
//
// MessageText:
//
//  The Application Program Interface (API) entered
//  will only work in Windows/NT mode.
//
#define ERROR_CALL_NOT_IMPLEMENTED       120L

//
// MessageId: ERROR_SEM_TIMEOUT
//
// MessageText:
//
//  The semaphore timeout period has expired.
//
#define ERROR_SEM_TIMEOUT                121L

//
// MessageId: ERROR_INSUFFICIENT_BUFFER
//
// MessageText:
//
//  The data area passed to a system call is too
//  small.
//
#define ERROR_INSUFFICIENT_BUFFER        122L

//
// MessageId: ERROR_INVALID_NAME
//
// MessageText:
//
//  A file name or volume label contains an incorrect character.
//
#define ERROR_INVALID_NAME               123L

//
// MessageId: ERROR_INVALID_LEVEL
//
// MessageText:
//
//  The system call level is not correct.
//
#define ERROR_INVALID_LEVEL              124L

//
// MessageId: ERROR_NO_VOLUME_LABEL
//
// MessageText:
//
//  The disk has no volume label.
//
#define ERROR_NO_VOLUME_LABEL            125L

//
// MessageId: ERROR_MOD_NOT_FOUND
//
// MessageText:
//
//  The specified module could not be found.
//
#define ERROR_MOD_NOT_FOUND              126L

//
// MessageId: ERROR_PROC_NOT_FOUND
//
// MessageText:
//
//  The specified procedure could not be found.
//
#define ERROR_PROC_NOT_FOUND             127L

//
// MessageId: ERROR_WAIT_NO_CHILDREN
//
// MessageText:
//
//  There are no child processes to wait for.
//
#define ERROR_WAIT_NO_CHILDREN           128L

//
// MessageId: ERROR_CHILD_NOT_COMPLETE
//
// MessageText:
//
//  The %1 application cannot be run in Windows mode.
//
#define ERROR_CHILD_NOT_COMPLETE         129L

//
// MessageId: ERROR_DIRECT_ACCESS_HANDLE
//
// MessageText:
//
//  BUGBUG - message text missing.
//
#define ERROR_DIRECT_ACCESS_HANDLE       130L

//
// MessageId: ERROR_NEGATIVE_SEEK
//
// MessageText:
//
//  BUGBUG - message text missing.
//
#define ERROR_NEGATIVE_SEEK              131L

//
// MessageId: ERROR_SEEK_ON_DEVICE
//
// MessageText:
//
//  BUGBUG - message text missing.
//
#define ERROR_SEEK_ON_DEVICE             132L

//
// MessageId: ERROR_IS_JOIN_TARGET
//
// MessageText:
//
//  A JOIN or SUBST command
//  cannot be used for a drive that
//  contains previously joined drives.
//
#define ERROR_IS_JOIN_TARGET             133L

//
// MessageId: ERROR_IS_JOINED
//
// MessageText:
//
//  An attempt was made to use a
//  JOIN or SUBST command on a drive that has
//  already been joined.
//
#define ERROR_IS_JOINED                  134L

//
// MessageId: ERROR_IS_SUBSTED
//
// MessageText:
//
//  An attempt was made to use a
//  JOIN or SUBST command on a drive that has
//  already been substituted.
//
#define ERROR_IS_SUBSTED                 135L

//
// MessageId: ERROR_NOT_JOINED
//
// MessageText:
//
//  The system tried to delete
//  the JOIN of a drive that is not joined.
//
#define ERROR_NOT_JOINED                 136L

//
// MessageId: ERROR_NOT_SUBSTED
//
// MessageText:
//
//  The system tried to delete the
//  substitution of a drive that is not substituted.
//
#define ERROR_NOT_SUBSTED                137L

//
// MessageId: ERROR_JOIN_TO_JOIN
//
// MessageText:
//
//  The system tried to join a drive
//  to a directory on a joined drive.
//
#define ERROR_JOIN_TO_JOIN               138L

//
// MessageId: ERROR_SUBST_TO_SUBST
//
// MessageText:
//
//  The system tried to substitute a
//  drive to a directory on a substituted drive.
//
#define ERROR_SUBST_TO_SUBST             139L

//
// MessageId: ERROR_JOIN_TO_SUBST
//
// MessageText:
//
//  The system tried to join a drive to
//  a directory on a substituted drive.
//
#define ERROR_JOIN_TO_SUBST              140L

//
// MessageId: ERROR_SUBST_TO_JOIN
//
// MessageText:
//
//  The system tried to SUBST a drive
//  to a directory on a joined drive.
//
#define ERROR_SUBST_TO_JOIN              141L

//
// MessageId: ERROR_BUSY_DRIVE
//
// MessageText:
//
//  The system cannot perform a JOIN or SUBST at this time.
//
#define ERROR_BUSY_DRIVE                 142L

//
// MessageId: ERROR_SAME_DRIVE
//
// MessageText:
//
//  The system cannot join or substitute a
//  drive to or for a directory on the same drive.
//
#define ERROR_SAME_DRIVE                 143L

//
// MessageId: ERROR_DIR_NOT_ROOT
//
// MessageText:
//
//  The directory is not a subdirectory of the root directory.
//
#define ERROR_DIR_NOT_ROOT               144L

//
// MessageId: ERROR_DIR_NOT_EMPTY
//
// MessageText:
//
//  The directory is not empty.
//
#define ERROR_DIR_NOT_EMPTY              145L

//
// MessageId: ERROR_IS_SUBST_PATH
//
// MessageText:
//
//  The path specified is being used in
//  a substitute.
//
#define ERROR_IS_SUBST_PATH              146L

//
// MessageId: ERROR_IS_JOIN_PATH
//
// MessageText:
//
//  Not enough resources are available to
//  process this command.
//
#define ERROR_IS_JOIN_PATH               147L

//
// MessageId: ERROR_PATH_BUSY
//
// MessageText:
//
//  The path specified cannot be used at this time.
//
#define ERROR_PATH_BUSY                  148L

//
// MessageId: ERROR_IS_SUBST_TARGET
//
// MessageText:
//
//  An attempt was made to join
//  or substitute a drive for which a directory
//  on the drive is the target of a previous
//  substitute.
//
#define ERROR_IS_SUBST_TARGET            149L

//
// MessageId: ERROR_SYSTEM_TRACE
//
// MessageText:
//
//  System trace information was not specified in your
//  CONFIG.SYS file, or tracing is disallowed.
//
#define ERROR_SYSTEM_TRACE               150L

//
// MessageId: ERROR_INVALID_EVENT_COUNT
//
// MessageText:
//
//  The number of specified semaphore events for
//  DosMuxSemWait is not correct.
//
#define ERROR_INVALID_EVENT_COUNT        151L

//
// MessageId: ERROR_TOO_MANY_MUXWAITERS
//
// MessageText:
//
//  DosMuxSemWait did not execute; too many semaphores
//  are already set.
//
#define ERROR_TOO_MANY_MUXWAITERS        152L

//
// MessageId: ERROR_INVALID_LIST_FORMAT
//
// MessageText:
//
//  The DosMuxSemWait list is not correct.
//
#define ERROR_INVALID_LIST_FORMAT        153L

//
// MessageId: ERROR_LABEL_TOO_LONG
//
// MessageText:
//
//  The volume label you entered exceeds the
//  11 character limit.  The first 11 characters were written
//  to disk.  Any characters that exceeded the 11 character limit
//  were automatically deleted.
//
#define ERROR_LABEL_TOO_LONG             154L

//
// MessageId: ERROR_TOO_MANY_TCBS
//
// MessageText:
//
//  Cannot create another thread.
//
#define ERROR_TOO_MANY_TCBS              155L

//
// MessageId: ERROR_SIGNAL_REFUSED
//
// MessageText:
//
//  The recipient process has refused the signal.
//
#define ERROR_SIGNAL_REFUSED             156L

//
// MessageId: ERROR_DISCARDED
//
// MessageText:
//
//  The segment is already discarded and cannot be locked.
//
#define ERROR_DISCARDED                  157L

//
// MessageId: ERROR_NOT_LOCKED
//
// MessageText:
//
//  The segment is already unlocked.
//
#define ERROR_NOT_LOCKED                 158L

//
// MessageId: ERROR_BAD_THREADID_ADDR
//
// MessageText:
//
//  The address for the thread ID is not correct.
//
#define ERROR_BAD_THREADID_ADDR          159L

//
// MessageId: ERROR_BAD_ARGUMENTS
//
// MessageText:
//
//  The argument string passed to DosExecPgm is not correct.
//
#define ERROR_BAD_ARGUMENTS              160L

//
// MessageId: ERROR_BAD_PATHNAME
//
// MessageText:
//
//  Invalid path name specified.
//
#define ERROR_BAD_PATHNAME               161L

//
// MessageId: ERROR_SIGNAL_PENDING
//
// MessageText:
//
//  A signal is already pending.
//
#define ERROR_SIGNAL_PENDING             162L

//
// MessageId: ERROR_MAX_THRDS_REACHED
//
// MessageText:
//
//  No more threads can be created in the system.
//
#define ERROR_MAX_THRDS_REACHED          164L

//
// MessageId: ERROR_LOCK_FAILED
//
// MessageText:
//
//  Attempt to lock a region of a file failed.
//
#define ERROR_LOCK_FAILED                167L

//
// MessageId: ERROR_BUSY
//
// MessageText:
//
//  The requested resource is in use.
//
#define ERROR_BUSY                       170L

//
// MessageId: ERROR_INVALID_SEGMENT_NUMBER
//
// MessageText:
//
//  The system detected a segment number that was not correct.
//
#define ERROR_INVALID_SEGMENT_NUMBER     180L

//
// MessageId: ERROR_INVALID_ORDINAL
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INVALID_ORDINAL            182L

//
// MessageId: ERROR_ALREADY_EXISTS
//
// MessageText:
//
//  Attempt to create file that already exists.
//
#define ERROR_ALREADY_EXISTS             183L

//
// MessageId: ERROR_INVALID_FLAG_NUMBER
//
// MessageText:
//
//  The flag passed is not correct.
//
#define ERROR_INVALID_FLAG_NUMBER        186L

//
// MessageId: ERROR_SEM_NOT_FOUND
//
// MessageText:
//
//  The specified system semaphore name was not found.
//
#define ERROR_SEM_NOT_FOUND              187L

//
// MessageId: ERROR_INVALID_STARTING_CODESEG
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INVALID_STARTING_CODESEG   188L

//
// MessageId: ERROR_INVALID_STACKSEG
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INVALID_STACKSEG           189L

//
// MessageId: ERROR_INVALID_MODULETYPE
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INVALID_MODULETYPE         190L

//
// MessageId: ERROR_INVALID_EXE_SIGNATURE
//
// MessageText:
//
//  %1 cannot be run in Windows/NT mode.
//
#define ERROR_INVALID_EXE_SIGNATURE      191L

//
// MessageId: ERROR_EXE_MARKED_INVALID
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_EXE_MARKED_INVALID         192L

//
// MessageId: ERROR_BAD_EXE_FORMAT
//
// MessageText:
//
//  %1 is not a valid Windows application.
//
#define ERROR_BAD_EXE_FORMAT             193L

//
// MessageId: ERROR_ITERATED_DATA_EXCEEDS_64k
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_ITERATED_DATA_EXCEEDS_64k  194L

//
// MessageId: ERROR_INVALID_MINALLOCSIZE
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INVALID_MINALLOCSIZE       195L

//
// MessageId: ERROR_DYNLINK_FROM_INVALID_RING
//
// MessageText:
//
//  The operating system cannot run this
//  application program.
//
#define ERROR_DYNLINK_FROM_INVALID_RING  196L

//
// MessageId: ERROR_IOPL_NOT_ENABLED
//
// MessageText:
//
//  The operating system is not presently
//  configured to run this application.
//
#define ERROR_IOPL_NOT_ENABLED           197L

//
// MessageId: ERROR_INVALID_SEGDPL
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INVALID_SEGDPL             198L

//
// MessageId: ERROR_AUTODATASEG_EXCEEDS_64k
//
// MessageText:
//
//  The operating system cannot run this
//  application program.
//
#define ERROR_AUTODATASEG_EXCEEDS_64k    199L

//
// MessageId: ERROR_RING2SEG_MUST_BE_MOVABLE
//
// MessageText:
//
//  The code segment cannot be greater than or equal to 64KB.
//
#define ERROR_RING2SEG_MUST_BE_MOVABLE   200L

//
// MessageId: ERROR_RELOC_CHAIN_XEEDS_SEGLIM
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_RELOC_CHAIN_XEEDS_SEGLIM   201L

//
// MessageId: ERROR_INFLOOP_IN_RELOC_CHAIN
//
// MessageText:
//
//  The operating system cannot run %1.
//
#define ERROR_INFLOOP_IN_RELOC_CHAIN     202L

//
// MessageId: ERROR_ENVVAR_NOT_FOUND
//
// MessageText:
//
//  The system could not find the environment
//  option that was entered.
//
#define ERROR_ENVVAR_NOT_FOUND           203L

//
// MessageId: ERROR_NO_SIGNAL_SENT
//
// MessageText:
//
//  No process in the command subtree has a
//  signal handler.
//
#define ERROR_NO_SIGNAL_SENT             205L

//
// MessageId: ERROR_FILENAME_EXCED_RANGE
//
// MessageText:
//
//  The file name or extension is too long.
//
#define ERROR_FILENAME_EXCED_RANGE       206L

//
// MessageId: ERROR_RING2_STACK_IN_USE
//
// MessageText:
//
//  The ring 2 stack is in use.
//
#define ERROR_RING2_STACK_IN_USE         207L

//
// MessageId: ERROR_META_EXPANSION_TOO_LONG
//
// MessageText:
//
//  The global file name characters, * or ? are entered
//  incorrectly or too many global file name characters are specified.
//
#define ERROR_META_EXPANSION_TOO_LONG    208L

//
// MessageId: ERROR_INVALID_SIGNAL_NUMBER
//
// MessageText:
//
//  The signal being posted is not correct.
//
#define ERROR_INVALID_SIGNAL_NUMBER      209L

//
// MessageId: ERROR_THREAD_1_INACTIVE
//
// MessageText:
//
//  The signal handler cannot be set.
//
#define ERROR_THREAD_1_INACTIVE          210L

//
// MessageId: ERROR_LOCKED
//
// MessageText:
//
//  The segment is locked and cannot be reallocated.
//
#define ERROR_LOCKED                     212L

//
// MessageId: ERROR_TOO_MANY_MODULES
//
// MessageText:
//
//  Too many dynamic link modules are attached to this
//  program or dynamic link module.
//
#define ERROR_TOO_MANY_MODULES           214L

//
// MessageId: ERROR_NESTING_NOT_ALLOWED
//
// MessageText:
//
//  Can't nest calls to LoadModule.
//
#define ERROR_NESTING_NOT_ALLOWED        215L

//
// MessageId: ERROR_BAD_PIPE
//
// MessageText:
//
//  Invalid pipe state.
//
#define ERROR_BAD_PIPE                   230L

//
// MessageId: ERROR_PIPE_BUSY
//
// MessageText:
//
//  All pipe instances busy.
//
#define ERROR_PIPE_BUSY                  231L

//
// MessageId: ERROR_NO_DATA
//
// MessageText:
//
//  Pipe close in progress.
//
#define ERROR_NO_DATA                    232L

//
// MessageId: ERROR_PIPE_NOT_CONNECTED
//
// MessageText:
//
//  No process on other end of pipe.
//
#define ERROR_PIPE_NOT_CONNECTED         233L

//
// MessageId: ERROR_MORE_DATA
//
// MessageText:
//
//  More data is available.
//
#define ERROR_MORE_DATA                  234L

//
// MessageId: ERROR_VC_DISCONNECTED
//
// MessageText:
//
//  The session was cancelled.
//
#define ERROR_VC_DISCONNECTED            240L

//
// MessageId: ERROR_INVALID_EA_NAME
//
// MessageText:
//
//  The specified EA name was invalid.
//
#define ERROR_INVALID_EA_NAME            254L

//
// MessageId: ERROR_EA_LIST_INCONSISTENT
//
// MessageText:
//
//  The EAs are inconsistent.
//
#define ERROR_EA_LIST_INCONSISTENT       255L

//
// MessageId: ERROR_NO_MORE_ITEMS
//
// MessageText:
//
//  No more data is available.
//
#define ERROR_NO_MORE_ITEMS              259L

//
// MessageId: ERROR_DIRECTORY
//
// MessageText:
//
//  Invalid directory name.
//
#define ERROR_DIRECTORY                  267L

//
// MessageId: ERROR_EAS_DIDNT_FIT
//
// MessageText:
//
//  The EAs did not fit in the buffer.
//
#define ERROR_EAS_DIDNT_FIT              275L

//
// MessageId: ERROR_EAS_NOT_SUPPORTED
//
// MessageText:
//
//  The mounted file system does not support extended attributes.
//
#define ERROR_EAS_NOT_SUPPORTED          282L

//
// MessageId: ERROR_NOT_OWNER
//
// MessageText:
//
//  Attempt to release mutex not owned by caller.
//
#define ERROR_NOT_OWNER                  288L

//
// MessageId: ERROR_TOO_MANY_POSTS
//
// MessageText:
//
//  Too many posts were made to a semaphore.
//
#define ERROR_TOO_MANY_POSTS             298L

//
// MessageId: ERROR_MR_MID_NOT_FOUND
//
// MessageText:
//
//  The system cannot find message for message number 0x%1
//  in message file for %2.
//
#define ERROR_MR_MID_NOT_FOUND           317L

//
// MessageId: ERROR_INVALID_ADDRESS
//
// MessageText:
//
//  Attempt to access invalid address.
//
#define ERROR_INVALID_ADDRESS            487L

//
// MessageId: ERROR_ARITHMETIC_OVERFLOW
//
// MessageText:
//
//  Arithmatic result exceeded 32-bits.
//
#define ERROR_ARITHMETIC_OVERFLOW        534L

//
// MessageId: ERROR_PIPE_CONNECTED
//
// MessageText:
//
//  There is a process on other end of the pipe.
//
#define ERROR_PIPE_CONNECTED             535L

//
// MessageId: ERROR_PIPE_LISTENING
//
// MessageText:
//
//  Waiting for a process to open the other end of the pipe.
//
#define ERROR_PIPE_LISTENING             536L

//
// MessageId: ERROR_EA_ACCESS_DENIED
//
// MessageText:
//
//  Access to the EA was denied.
//
#define ERROR_EA_ACCESS_DENIED           994L

//
// MessageId: ERROR_OPERATION_ABORTED
//
// MessageText:
//
//  The IO operation has been aborted due to either thread exit
//  or application request.
//
#define ERROR_OPERATION_ABORTED          995L

//
// MessageId: ERROR_IO_INCOMPLETE
//
// MessageText:
//
//  Overlapped IO event not in signalled state.
//
#define ERROR_IO_INCOMPLETE              996L

//
// MessageId: ERROR_IO_PENDING
//
// MessageText:
//
//  Overlapped IO operation in progress.
//
#define ERROR_IO_PENDING                 997L

//
// MessageId: ERROR_NOACCESS
//
// MessageText:
//
//  Invalid access to memory location.
//
#define ERROR_NOACCESS                   998L

//
// MessageId: ERROR_SWAPERROR
//
// MessageText:
//
//  Error accessing paging file.
//
#define ERROR_SWAPERROR                  999L

#endif // _WINERROR_
