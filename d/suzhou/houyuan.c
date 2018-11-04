inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ��ָ��ĺ�Ժ��Ժ�������˲��ٵĸ����滨��ݣ�����
��ɫ�ջ�Ϊ�ࡣ������һ����(men)��
LONG
        );
        set("item_desc", ([
                "men" : "�����ź������С��Ĺ뷿��\n",
        ]));

        set("exits", ([
                "north" : __DIR__"dongxiang",
                "south" : __DIR__"dayuan1",
        ]));
        set("objects", ([
                __DIR__"npc/lintuisi" : 1,
        ]));

        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_kai", "kai");
        if (present("ling tuisi", environment(this_player())))
                delete("exits/north");
}
int do_kai(string arg)
{
        object ob;
        if (query("exits/north"))
                return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
        if (!arg || (arg != "men" && arg != "north"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!(ob = present("tong yaoshi", this_player())))
                return notify_fail("����Կ��������ת�˼���,������ôҲ�򲻿���\n");
        set("exits/north", __DIR__"dongxiang");
        message_vision("$N����ͭԿ�״򿪷��ţ�����Կ��ȴ���ˡ�\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ling tuisi", environment(me))) && 
                (dir == "north"))
                return notify_fail("����˼��ס���㣺��������լ��ʲô? \n");
        return ::valid_leave(me, dir);
}

