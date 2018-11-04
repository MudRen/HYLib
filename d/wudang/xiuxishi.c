// Room: xiuxishi.c ��Ϣ��
// By Marz

inherit ROOM;

void init();
void close_men();
int do_open(string arg);
int do_close(string arg);
int valid_leave(object me, string dir);

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_fight", 1);
	set("tan_count", 2);

        setup();
}

void init()
{
        add_action("do_open", "open");
        add_action("do_close", "close");
        add_action("do_zhao", "find");
        add_action("do_zhao", "zhao");

}

void close_men()
{
        object room;

        if(!( room = find_object(__DIR__"donglang2")) )
                room = load_object(__DIR__"donglang2");
        if(objectp(room))
        {
                delete("exits/south");
                        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
                room->delete("exits/north");
                message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
        }
}

int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("���Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "men" && arg != "door"))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N����Ź��ϡ�\n", this_player());

        remove_call_out("close_men");
        call_out("close_men", 2);

        return 1;
}

int do_open(string arg)
{
        object room;
        object me = this_player();
        if (query("exits/south"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");

        if (!arg || (arg != "men" && arg != "door" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        if(!( room = find_object(__DIR__"donglang2")) )
                room = load_object(__DIR__"donglang2");
        if(objectp(room))
        {
                set("exits/south", __DIR__"donglang2");
                message_vision("$N������ŵذ��Ŵ򿪡�\n", this_player());
                room->set("exits/north", __FILE__);

                if (me->query_temp("sleeped"))
                {
                message("vision", "֨��һ����"+me->query("name")+"��������ش���
����Ŵ��ˡ�\n",
                room);
                } else
                {
                message("vision", "���һ����"+me->query("name")+"��������Ŵ�
��һ���Ĳ��ͷ���\n",
                         room);
                }

                remove_call_out("close_men");
                call_out("close_men", 10);
        }

        return 1;
}


int valid_leave(object me, string dir)
{
        object room;

        if ( !::valid_leave(me, dir) )
                return 0;

        if(!(room = find_object(__FILE__)) )
                room = load_object(__FILE__);
        if(objectp(room))
        {
                room->add_temp("person_inside", -1);
                if ((int)room->add_temp("person_inside", -1) <= 0)
                        room->delete_temp("person_inside");
        }

        return 1;
}

int do_zhao(string arg)
{       object tan;
        object me;
        me=this_player();
        if ( !arg || arg != "mao tan" )
            return notify_fail("��Ҫ��ʲô\n");
	if (present("mao tan", me))
	   return notify_fail("��������ȥ�������Լ�ԭ���Ѿ����ˣ�\n");
	if (objectp(present("mao tan", environment(me))))
	   return notify_fail("���Ͼ��У��㻹��ʲô����\n");

        if (query("tan_count") > 0) 
          {
           message_vision("$N�ڴ��Ϸ�����ȥ�ҳ�һ��ë̺��\n", me);
           add("tan_count", -1);
           tan=new(__DIR__"obj/maotan");
           tan->move(me);
          }
        else
           message_vision("$N�ڴ��Ϸ�����ȥʲôҲû���š�\n", me);
     return 1;
}
