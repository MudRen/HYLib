// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "������Ұ");
	set("long", @LONG
�����������Ұ���ϣ����������԰��⣬�㲻����������һ���������
������Ŀ�����
LONG
	);
        set("outdoors", "����");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"xiaodao2",
	    "northeast" : "/d/dali/jianchuan",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
