// baling/xidajie1
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�
����ϡ�٣������ĵغ������塣������һ�����ֵĹ㳡���ϱ�����������
�������������
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"east" : __DIR__"guangchang",
                "north" : __DIR__"yanju",
		"west" : __DIR__"ximen",
		
	]));

	setup();
	replace_program(ROOM);
}

