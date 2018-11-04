// duanchang.c

#include <ansi.h>
#include <room.h>
#include "tiao.c"
inherit ROOM;


void init()
{
        add_action("do_pa", "pa");
        add_action("do_bang", "bang");
        add_action("do_cuo", "cuo");
        add_action("do_tiao", "tiao");
        add_action("do_yes", "yes");
        add_action("do_no", "no");
        add_action("do_jump","jump");        
        add_action("do_xiao","xiao");
}

void create()
{
        set("short",YEL"�ͱ�"NOR);
        set("long", @LONG
������ɽ��������һ���ͱڣ��ұ��ϲ�֪��˭�̵��м��д��֣�dazi����
�Դ����ϣ���ʮ�ɹ�����Ĵ�ݲ��������������ƣ�������ң������Ҳ��
���ڷ嶥ͣ�㡣ɽ���Ա߾���һ����Ԩ��shenyuan�������±��ϳ���һ������
����song��бб��̽���±ߡ�
LONG);
        set("item_desc", ([
        "dazi": HIY"                             
            ������������������������������������
            ����������                  ��������
            ��������    ʮ �� �� ��   ��������
            ��������                    ��������
            ��������    �� �� �� �ᣬ   ��������
            ��������                    ��������
            ��������    �� �� �� �   ��������
            ��������                    ��������
            ��������    �� ʧ �� Լ���� �������� 
            ����������                  ��������
            ������������������������������������\n"NOR,
        "shenyuan":HIB"���Ԩ��������ȥ������Ԩ���������ƣ������ĵ�����ס�\n"NOR,
        "song": HIG"һ������������֦����б̽��֦������������\n"NOR,
        ]));

        set("outdoors", "�����");

        setup();
}

int do_pa(string arg)
{
        object me;

        me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if ( !arg || arg != "down" )
                return notify_fail("��Ҫ��������\n");
        if (!me->query_temp("mark/bang"))
                return notify_fail("����������ɱô��ֱ������ȥ�ɣ�\n");
        message_vision(HIG"$N���������������ȥ��\n"NOR, me);
        me->move(__DIR__"yabi1");
        me->add_temp("tengacc",-1);
        tell_room(environment(me), me->name() + "������������������������\n", ({ me }));
        me->delete_temp("mark/bang");
        return 1;
}

int do_bang(string arg)
{      
        object me;
        me = this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if( (int)me->query_temp("tengacc", 1)<=0 )
            return notify_fail("��Ҫ��ʲô��\n");
        if ( !arg || arg != "song" )
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query_temp("mark/bang"))
                return notify_fail("�����Ѿ�����ˡ�\n");
        message_vision(HIY"$N����ϸϸ�ذ�����һ�˰����������ϡ�\n"NOR, me);
        me->set_temp("mark/bang",1);
        return 1;
}

int do_cuo(string arg)
{
        object me;
        me = this_player();
        if ( !arg || arg != "shupi" )
        return notify_fail("��Ҫ��ʲô��\n");         
        if( (int)me->query_temp("tengacc", 1)<=0 )
        {
                if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");                
                message_vision(GRN"$N����һ����Ƥ���������һ�����١�\n"NOR, me);
                me->set_temp("tengacc", 1);
                return 1;
        }
        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n"); 
        if ((int)me->query_temp("tengacc") >= 8)
          return notify_fail("��Ƥ����������ˣ��㻹��ʲô����\n");
        message_vision(GRN"$N����һ����Ƥ�����������ٽӳ���\n"NOR, me);
        me->add_temp("tengacc",1);
        return 1;
}

int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "back" ) return 0;
       if (!arg ) return 0;        
       if (!living(me)) return 0;
         message_vision("$N������ϳ������˻�ȥ��\n", me);
       if(me->query_temp("tengacc"))
         me->delete_temp("tengacc");
         me->move(__DIR__"shanlu10");
         tell_room(environment(me), me->name() + "���ͱ����˹�����\n", ({ me }));
         return 1;
}

int get_object(object ob)
{
       return userp(ob);
}

int do_xiao(string arg,object *obj)
{
        object me=this_player();
        mapping fam;
        object *inv = deep_inventory(me);        
        fam = me->query("family");
        if (arg) return 0;
        if( ! fam || fam["family_name"] != "��Ĺ��") return 0;
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
          tell_object(me,HIR"�����͵͵���������ϰ׵񣬽������̫�࣬����һ����˩��ˤ���ڵء�\n"NOR);
          me->unconcious();
          return 1;
        }
        message_vision(HIW"\n$N���������е�ֻ���׵�˫��һ�񣬸߷����ƣ�������Ȧ���͵���ӿ��м�����¡�\n"+
                          "$N���ϰ׵���ǰ׵�����������������������ɽ�¡�\n\n"NOR,me);
        me->move(__DIR__"tanan");
        tell_room(environment(me), me->name() + "�Ӱ׵����������������׵�˫��һ�񣬸߷����ơ�\n", ({ me }));
        return 1;
}
