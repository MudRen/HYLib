// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
���ڴ���ϣ����߶���������������·���������˲����࣬ż�������м�
�����߹���ֻ�������������У�С������һ�ǻ�ǽ¶����
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"dadao6",
	    "southeast" : __DIR__"shangang",
            "west" : __DIR__"yuxuguanmen",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
