// yyd.c ԧ�챦��
// zly 99.6.22

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"ԧ�챦��"NOR,({ "yuanyang dao", "dao","yuanyang","blade" }) );
        set("long", HIC"\n���������������ԧ�챦������˵��������޵������µĴ����ܡ�\n"NOR);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 1000000);
                set("unique", 1);
                set("rigidity", 6);
                set("sharpness", 2);
                set("weapon_prop/parry", 10);        
                set("weapon_prop/dodge", 10);
                set("wield_neili", 300);
                set("wield_maxneili", 1500);
                set("wield_str", 25);
                set("wield_msg", HIC"ֻ����һ�����죬$N���ԧ�챦���������\n"NOR);
                set("unwield_msg", HIC"$N�����е�ԧ�챦������ز��뵶�ʡ�\n" NOR);               
        }
          init_blade(800);
        setup();
}

void init()
{
    add_action("do_sub",({"fen", "��"}));
}

int do_sub()
{
     object me,ob, ob1, obj;
     me = this_player();
//     obj = this_object();
     ob = this_object();
     obj = present("yuanyang dao", me);
     if((int)me->query("neili") < 500)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ͷ��Ŀѣ��ԭ���������������ֲ���ԧ�챦����\n");
     if((int)me->query_str() < 28)
                return notify_fail("��о�ʹ����ȫ���������Ҳ�ֲ���ԧ�챦����\n");
     message_vision(HIY"\nֻ��һ�����죬$N��ԧ�챦������һ��һ�֣�ԧ�챦����ʱһ��Ϊ�����ֲ���$N�����������У�\n"NOR, me);
     me->add("neili", -300);
     new(__DIR__"yuan")->move(me, 1);
     new(__DIR__"yang")->move(me, 1);  
     destruct(obj); 
     return 1;

}
