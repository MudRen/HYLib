// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ɭ��");
	set("long", @LONG
�������ܶ����ǲ����ľ������������ã�����ȴ�ڳ���������ƻ裬Խ
������Խ�ܣ���ʱ���ò�������С�� 
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "south" : __DIR__"shanlin-3",
	    "west" : __DIR__"shanlin-5",
	]));

	setup();
	replace_program(ROOM);
}
