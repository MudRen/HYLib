// Room: /testmud/d/changan/gudi.c
// This is a room made by Wsl.

inherit ROOM;
int do_break(string arg);
int do_jump(string arg);
int do_enter(string arg);
void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
ͷ�������������ڵ��ϣ�������һƬ�ܺ�Ĳݵأ�������������
��ģ�����ǡ�⣬���ܿ���ȥ�߲����ʣ���ʯ��ᾣ������в���һ��
��Ҫ������Ƭ���Ĳݶѵ��ţ��ںõ��ṦҲ��ˤ�ñ��һ�����ࡣ
LONG
);
        setup();
}
void init()
{
    add_action("do_break", "break");
    add_action("do_jump", "jump");
    add_action("do_enter", "enter");
}
int do_break(string arg)
{
    int n;
int i;
	object *inv;
	int sizeinv;
        object room;
    object me = this_player();
    if(!this_player()->query_temp("killer")) return 0;
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㱳����ʲôҲ�����ˣ�\n");
      		
		}

    if(!this_player()->query_temp("killer")) return 0;
    if(this_player()->query_temp("break")) return 0;
    if( !arg || arg!="��ʯ" )
    {
        write("��Ҫ����ʲô��\n");
        return 1;
    }
    n = (int)me->query("neili");
    if (n >= 3000)
    {
        message_vision("$N���˵��˫��ֱ��ǰ�����һ��������\n", this_player());
        message_vision("ֻ����$N�������ʯ�ĳ��ɽ����м��һ����ҳ��ܲ����𶯣�\n", this_player());
        message_vision("�����ڲݵ��ϣ������޴���������㾪ϲ�ķ�������ʯ�Ϸ�������һ������\n", this_player());
        this_player()->set_temp("break",1);
        this_player()->set("neili",0);
        remove_call_out("close");
        call_out("close", 5, me);
    }else{
        message_vision("���ֻ��һ���ƺߣ�$N���Լ������������ǰһ��....\n", this_player());
        this_player()->set("neili",0);
        this_player()->unconcious();
    }
    return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if(!me->query_temp("break")) return 0;
        if(me->query_temp("climb")) return 0;
        if( !arg || arg!="����" )
        {
        write("��������ʲô�ط�ȥ��\n");
        return 1;
        }
        if ((int)me->query_skill("dodge",1) > 100 ) {
        message_vision("$Nһ��������������ʯ��\n", me);
        me->set_temp("climb",1);
        me->delete_temp("braek");
        }else{
        message_vision("$Nʩչ�Ṧ��������ȥ����ȴ��ôҲ������ȥ��\n", me);
        }
        return 1;
}
int do_enter(string arg)
{
    int n;
int i;
	object *inv;
	int sizeinv;
        object room;
    object me = this_player();
    if(!this_player()->query_temp("killer")) return 0;
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㱳����ʲôҲ�����ˣ�\n");
      		
		}
        if(!me->query_temp("climb")) return 0;
        if( !arg || arg!="�Ҷ�" )
        {
        write("����ȥ�ǰ���\n");
        return 1;
        }
        message_vision("$N���˹����壬������Ҷ��\n", me);
        me->move("/d/changan/mudong0");
        message_vision("��¡¡���������Ѿ������ˡ�\n", me);
        return 1;
}
void close(object room)
{
    object me;
    me = this_player();
    message("vision","�ƺ��й����ص��������������ʯ��������ȥ��\n", room);
    me->delete_temp("braek");
    me->delete_temp("climb");
}

