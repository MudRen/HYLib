#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name(HIY"�����ĸ��"NOR,({ "zimu huan", "huan","axe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "��");
               set("treasure",1);
               set("value", 80);
               set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);    
                set("material", "steal");
                set("wield_msg",HIW"ֻ����Ǻ�ॡ�һ�����죬$N�������ĸ���������С�\n"NOR);
                set("long", WHT"\n���Ǽ����׺ݵ����ű��У����а��ۣ��ƺ����Ժ���һ������ϣ�zuhe����һ����\n"NOR);               
                set("unwield_msg", HIW "$NС�ĵذ������ĸ�����뻳�С�\n"NOR);               
        }
        init_axe(300);
        setup();
}

void init()
{
    add_action("do_add",({"zuhe", "���"}));
}

int do_add()
{
     object me,ob, obj;
     me = this_player();
     ob = this_object();
     obj = present("wanzi duo", me);
     if(!objectp(obj))
           return notify_fail("��Ҫ�������ĸ����ʲô������ϣ�\n");
     me->add("neili", -10);
     message_vision(BLU"\nֻ����������һ�����죬����÷����������ĸ����ϳ���һ����ĸԧ���ᡣ\n"NOR, me);
     destruct(obj);   
     new(__DIR__"yuanyang-yue")->move(me, 1);     
     destruct(ob);
     return 1;
}

