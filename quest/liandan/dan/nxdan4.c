//Cracked by Kafei
// /d/shenlong/obj/bmdan.c ����������
// by Aln  1/98

#include <ansi.h>

inherit ITEM;
void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
        set_name("����������", ({"baoming dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 4000);
                set("long", 
"������������������������ɽ�˲Ρ����ܵ���ѩ���������ɵ��鵤\n");
                set("medicine", 1);
                set("no_drop", "�������������ƣ��������ӣ� \n");
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
        if( (int)me->query("eff_qi")*10 > (int)me->query("max_qi")*3 
        &&  (int)me->query("eff_jing")*10 > (int)me->query("max_jing")*3 ) {
                write("�������ò��ŷ�������������\n");
                return 1;
        }

        if( !me->is_fighting() ) {
                write("�����ֲ���Σ����ͷ�����˷��ˣ�\n");
                return 1;
        }

        message_vision("$N����һ��" + name() + "��\n", me);

        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("eff_jing", (int)me->query("max_jing"));

        message_vision(YEL "$Nֻ������ȫ���ˡ�\n\n" NOR, me);
        destruct(this_object());
        return 1;
}
