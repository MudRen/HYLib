// dadian ���
// by yuan

inherit ROOM;

void create()
{
	set("short", "�߲����");
	set("long", @LONG
	������Ǵ�˵��������������ظ߲��Թ��Ĵ��ıڹ��Ķ�������ľ��ķ���.
���֮����һ���������Σ�����֮��͸��һ�����ϣ���һ����ң����飺

                ****************
                *              * 
                *   �ĳ����   *
                *              *
                ****************

�������涼�ǵ��á�
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"wroom1",
		"east" : __DIR__"eroom1", 
	]));
//	set("objects", ([
//		CLASS_D("wudang") + "/guxu" : 1,
//		CLASS_D("wudang") + "/song" : 1]));
	setup();
//	replace_program(ROOM);
//	"/clone/board/wudang_b"->foo();
}

