inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�������鷿����ǽһ�Ŵ���ܣ��ڷ��źܶ���鼮��������ʥ�������
������ų��ԡ�ʥ������������һֱ����Ϊ�٣���������ѧ�����ա�һ��
����ȥ���ƺ��й��ڲ������巽����顣
LONG
	);
	set("exits", ([
		"west"  : __DIR__"shilu1",
	]));
/*	
set("objects", ([
		"/d/village/obj/zhujian" : 2,
	]));
*/
	
	setup();
	replace_program(ROOM);
}
