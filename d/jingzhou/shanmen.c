// shanmen.c �䵱ɽ��
// by Xiang

inherit ROOM;

void create()
{
	set("short", "�䵱ɽ��");
	set("long", @LONG
	�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�ʯ����д�š��䵱ɽ���������֣�ԭ�������
�����������䵱ɽ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad8",
		"westup" : "d/wudang/zixiaogate",
	]));
//        set("objects", ([
//                __DIR__"npc/guest" : 1]));
	setup();
	replace_program(ROOM);
}

