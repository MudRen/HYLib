// jinchuang.c ��ҩ
#include <ansi.h>
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
        set_name("��ҩ", ({"jinchuang yao", "jin", "jinchuang", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 3000);
                    set("heal_up", 1);
               set("heal_up", 1);
               set("medicine", "drug");
                set("unit", "Щ");
                set("long", "����������ʿ�ر��Ľ�ҩ��\n");
                set("base_value", 0);
                set("base_unit", "��");
                set("base_weight", 30);
        }
        set_amount(1);
}

int do_eat(string arg)
{
   object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if ((int)this_player()->query("eff_qi") == 
            (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        else {
        if( !environment(me)->query("bwdhpk"))
{
       message_vision(HIR "\n$N��ҩ Ϊ����ר�ã�ҩ��û���ˣ�\n\n" NOR,
                       me);
	destruct(this_object());   
       return 1;       
}

                this_player()->add("eff_qi", 100);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
                add_amount(-1);
                return 1;
        }
}
