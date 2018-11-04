#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
          set_name(HIC"��ĸԧ����"NOR,({ "yuanyang yue", "yue", "axe" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "��");
                set("value", 80);
                set("treasure",1);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1); 
                set("material", "steal");
                set("wield_neili", 50);
                set("wield_maxneili", 500);
                set("wield_msg",HIC"$N����һ����������������ĸԧ���ᣬȴ�����е��һ����ɭ��ĺ�������������\n"NOR);
                set("long", HIC"\n���ԧ������״���ӣ�����д���ī�̲���ҫ��\n�Ĺ�â����ָ��һ�������������ֱ͸�ĸ���\n"NOR);
                set("unwield_msg", HIC "$N�����е���ĸԧ�����������䡣\n"NOR);     
        }
        init_axe(600);
        setup();
}

void init()
{
    add_action("do_sub",({"fenjie", "�ֽ�"}));
}

int do_sub()
{
     object me,ob, ob1, obj;
     me = this_player();
     obj = this_object();
     if((int)me->query("neili") < 100)
               return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֽⲻ����ĸԧ���ᣡ\n");
     if((int)me->query_str() < 20)
               return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֽⲻ����ĸԧ���ᣡ\n");

     message_vision(HIW"\n$N����ĸԧ����ֽ�Ϊ�����ĸ��������÷���ᣡ\n"NOR, me);
     me->add("neili", -30);
     new(__DIR__"zimu-huan")->move(me, 1);
     new(__DIR__"wanzi-duo")->move(me, 1);
     destruct(obj); 
     return 1;

}

