// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
��ת����һ��ɽ�ڣ�ӭ�����һ����ֱ����������������������������
Ʈ�
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
	    "northwest" : __DIR__"dadao5",
	    "east" : __DIR__"xiaodao2",
        ]));
        set("objects", ([
              __DIR__"npc/dadao" : 1,
	]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
