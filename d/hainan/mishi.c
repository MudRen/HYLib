// Room: /d/hainan/mishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������С�ݣ��ܳ�ʪ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"chucang",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_tui","tui");
}
int do_tui(string arg)
{
        object me;
        me = this_player();
        if (arg != "����")return 0;
        if (me->query("str") < 25 || me->query("force") < 200)
                return notify_fail("��ʹ�������ƴ��������û�ƶ���\n");
        message_vision("$N�ƿ��˴�������ǰ��ʱһ����ԭ��������߱���һ����ء�\n",me);
        set("exits/out", __DIR__"taoyuan");
        me->add("force",-200);
        return 1;
}


