// Modify By River 98/12 
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ʯ�������أ�û��һ��������·������������ţ������°ڱ�����
˺��һƬһƬ���������ƺ���ʱ���ɭ�֡��㴭�˿�����ͻȻ����һ����Ӱ��
������ȥ��
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "east" : __DIR__"shanlin-2",
	    "west" : __DIR__"shanlu12",
	]));

	setup();
	replace_program(ROOM);
}

