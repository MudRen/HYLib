// shuhou.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "���Ժ�");
	set("long", @LONG
�����ͺͺ��һ��Ƭʯ�ڣ���������������ʯ��ƽ���쳣����Ȼһ��ͭ����
ֻ�ǱȺ�����ɽ��С����࣬��ϸ����ʯ�ڣ�ƽ���⻬���������졣
LONG
	);
        set("exits", ([
		"out" : __DIR__"shulin1",
	]));
        set("outdoors", "����");
	setup();
}

void init()
{
        add_action("do_down", "tear");
        add_action("do_down", "si");
}

int do_down(string arg)
{
	object me = this_player();
        if (!arg || arg!="teng") return 0;
        message_vision("$N��ʯ���ϵ�����˺�øɸɾ�����������档\n" , me);
        me->move(__DIR__"shibi");
        return 1; 
}
