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
        set("item_desc", ([
        "��ʯ" : "����᾵Ĺ�ʯ�У��п���ʯʮ�ֹ⻬����������ʯ��ͬ��\n", 
])); 

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

    if( !arg || arg!="��ʯ" )
    {
        write("��Ҫ����ʲô��\n");
        return 1;
    }
    if (query("break"))
        return notify_fail("��ʯ�ѱ������ˡ�\n");
    n = (int)me->query("neili");
    if (n >= 3000)
    {
        message_vision("$N���˵��˫��ֱ��ǰ�����һ��������\n", this_player());
        message_vision("ֻ����$N�������ʯ�ĳ��ɽ����м��һ����ҳ��ܲ����𶯣�\n", this_player());
        message_vision("�����ڲݵ��ϣ������޴���������㾪ϲ�ķ�������ʯ�Ϸ�������һ������\n", this_player());
        set("break",1);
        this_player()->set("neili",0);
        remove_call_out("close");
        call_out("close", 5, me);
    }
    else
    {
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
        if(!query("break")) return 0;
        if (me->query_temp("climb"))
                return notify_fail("���Ѿ�վ����ʯ���ˡ�\n");
        if( !arg || arg!="����" )
        {
        write("��������ʲô�ط�ȥ��\n");
        return 1;
        }
        if ((int)me->query_skill("dodge",1) > 100 ) {
                message_vision("$Nһ��������������ʯ��\n", me);
                me->set_temp("climb",1);
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
        me->move("/d/changan/qinhuang/mudong0.c");
        message_vision("��¡¡���������Ѿ������ˡ�\n", me);
        return 1;
}

void close(object me)
{
    if (me)
        me->delete_temp("climb");
    message("vision","���漸����ʯ�����������Ѷ����ַ�ס�ˡ�\n", this_object());
    delete("break");
}

