// Room: /d/hainan/chucang.c

inherit ROOM;

void create()
{
	set("short","�����ִ�����");
	set("long", @LONG
����ʯ��������һ�䴢����.�����ǽ�����Ŵ�.....��Ϊ����͸����
��ԭ��,����һ�㶼���Ե�����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"shutang",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/roujing_sword.c" : 3,
]));

	setup();
}

void init()
{
        add_action("do_fan","xian");
}
int do_fan(string arg)
{
        object me,ob;   
        me = this_player();
        if (arg != "����") return 0;
        if (me->query("family/family_name") != "������")
                return notify_fail("��Ҫ��ʲô������\n");
        message_vision("$N�ƿ����壬��Ȼ������һ���ص�����ڣ��������ȥ��������\n\n",me);
        me->move(__DIR__"mishi");
        me->start_busy(2);
        return 1;
}

