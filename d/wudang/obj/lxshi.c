// lianxinshi.c����ʯ

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIW"����ʯ"NOR,({"lianxin shi", "lianxin", "shi"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("material", "stone");
                set("unique",1);
                set("treasure", 1);
                set("long", "����һ���޴�İ���ɫ����ʯ��һ��ƽ��������д��һЩ֮��\n"+


        HIW" �� �� ʯ "NOR+"~~~~~~~~~~~~~~~~~~~~~~~~
        ��ʯ���ϵ�����֮�Ҳ��������������֮�á�����Ϊ����������������Դ���Ե��
                                                                 ������\n");
                set("wield_msg", "$N˫������һ��$n���������۾�����ס�ˡ�\n");
                set("unequip_msg", "$N�������е�$n���ֱ۶����ˡ�\n");
        }
        init_hammer(20);
        setup();
}                                                   
void init()
{
        if( this_player() == environment() )
        add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
        int damage;
        object me;
        me = this_player();
        if ( (int)me->query_skill("taoism", 1) < 101 )
           return notify_fail("�㾲������,һ��ʹ������˯��\n");
        if ( (int)me->query_skill("taoism", 1) >120 )
        return notify_fail("�㾲������,���ƺ��ѵ���ƿ����\n");
        me->receive_damage("jing", 30 + random(20));
        me->improve_skill("taoism", me->query("int"));
        message_vision("$N��Ŀ����,����������ʲô��\n", me);
        return 1;
}
