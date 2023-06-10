#include "jni_example.h"
#include <stdlib.h>

JNIEXPORT jint JNICALL Java_JNIExample_sum
(JNIEnv*, jobject, jint a, jint b)
{
	return a + b;
}

int comp(const void* a, const void* b)
{
	return *(jint*)a - *(jint*)b;
}

JNIEXPORT void JNICALL Java_JNIExample_quickSort
(JNIEnv* env, jobject jobj)
{
	jclass jc = env->GetObjectClass(jobj);								//�������� ����� ������� jobj
	jfieldID id = env->GetFieldID(jc, "data", "[I");					//�������� id ���� data
	jobject data_from_array = env->GetObjectField(jobj, id);			//�������� ������ �� ���� data

	jintArray* array = reinterpret_cast<jintArray*>(&data_from_array);	//�������� ��������� �� ������ 
	jboolean isCopy;													//��������� ���������� ��� �������� ����� (����� ��� ���)
	jint* data = env->GetIntArrayElements(*array, &isCopy);
	jint len = env->GetArrayLength(*array);

	qsort(data, len, sizeof(jint), comp);

	env->ReleaseIntArrayElements(*array, data, 0);
}