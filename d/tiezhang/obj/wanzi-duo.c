#include <weapon.h>
#include <ansi.h>

inherit AXE;
void create()
{
        set_name(HIY"����÷����"NOR,({ "wanzi duo", "duo","axe" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "��");
                 set("treasure",1);
                 set("value", 70);
                 set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);    
                set("material", "steal");
                set("wield_msg",YEL"$N������÷�����������С�\n"NOR);
                set("long", YEL"\n���Ǽ����׺ݵ����ű��У����а��ۣ��ƺ����Ժ���һ������ϣ�zuhe����һ����\n"NOR);                
                set("unwield_msg", YEL "$N�����е�����÷��������������\n"NOR);               
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
     obj = present("zimu huan", me);
     if(!objectp(obj))
           return notify_fail("��Ҫ������÷�����ʲô������ϣ�\n");
     me->add("neili", -10);
     message_vision(BLU"\nֻ����������һ�����죬����÷����������ĸ����ϳ���һ����ĸԧ���ᡣ\n"NOR, me);
     destruct(obj);
     new(__DIR__"yuanyang-yue")->move(me, 1);     
     destruct(ob);
     return 1;
}

