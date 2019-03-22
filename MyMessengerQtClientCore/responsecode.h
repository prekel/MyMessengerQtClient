#ifndef RESPONSECODE_H
#define RESPONSECODE_H

enum ResponseCode
{
	Ok = 0,
	WrongNickname = 1,
	WrongPassword = 2,
	AccessDenied = 3,
	NicknameAlreadyExists = 4,
	InvalidToken = 5,
	InvalidRequest = 6,
	UnknownError = 7,
	InternalServerError = 8,
	NicknameNotFound = 9,
	DialogNotFound = 10,
	LongPoolTimeSpanExpired = 11,
	IdNotFound = 12
};

#endif // RESPONSECODE_H
