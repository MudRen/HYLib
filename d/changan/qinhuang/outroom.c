// This is a room made by wsl.

inherit ROOM;
int do_climb(string arg);
void create()
{
    set("short", "����ٸ");
    set("long", @LONG
���������ƺ��Ѿ���·�����ˣ������и�ʯ̨����֪����ʲô��
�ģ�ʯ̨���Ϸ����Կ������ֲ��ĸ����̸���ڣ���Щ�Ѿ�������
ʯ̨���ˡ�
LONG
);
        set("exits", ([
          "south" : __DIR__"shidao5",
]));
    setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_jump", "jump");
        add_action("do_pa", "��");
}
int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg == "" ) return 0;
        if(me->query_temp("pa")) return notify_fail("���Ѿ���ʯ̨���ˣ�����ʲôѽ��\n");
        if( arg == "ʯ̨" ) {
                message_vision("$N�붼���룬��������ȥ��\n",me);
        me->set_temp("pa",1);
        return 1;
        }
}
int do_jump(string arg)
{
        object me = this_player();
        if( !me->query_temp("pa")) return 0; 
        if( !arg || arg == "") return notify_fail("��Ҫ����ʲô�ط�ȥѽ��\n");
        if( me->query_temp("jump")) return notify_fail("���Ѿ��������ˡ�\n");
        if( arg == "down" ) {
                message_vision("$N������������������ȥ��\n",me);
        me->set_temp("jump",1);
        me->delete_temp("pa");
        return 1;
        }
}
int do_pa(string arg)
{
        object me = this_player();
        if( !me->query_temp("pa")) return 0;
        if(!arg || arg == "") return notify_fail("��Ҫ��������\n");
        if( arg == "��" ) {
                message_vision("$N�����Ƶ�����������ʯ̨�ϵ�����......\n",me);
        me->delete_temp("pa");
        me->delete_temp("jump");
        call_out("go_up", 10 , me );
        return 1;
        }
}
void go_up(object me)
{
        if(!me) return;
        tell_object(me, "��˳��������ѽ...��ѽ......\n�����˺ܾã��������ּ��������⡣\n");
        me->move("/d/changan/caodi.c");
}       
