inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ�䰫С���߷���ƽʱ��Ϊ�ѷ��������á������ﲼ
�����������������ǻҳ����������Ѿ��ܾ�û���˴�ɨ�ˡ���
����һ��б���ż����ɲ�
LONG);
	set("exits", ([
  		"north" : __DIR__"miaojia_dayuan",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/obj/ganchai" : 2,
        ]));
	set("coor/x", -210);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
