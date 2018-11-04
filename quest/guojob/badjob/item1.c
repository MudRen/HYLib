
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"ʯ�ҷ�"NOR, ({ "shi huifeng", "huifeng" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ʯ�ҷۿ���(sa)��\n") ;
                set("unit", "��");
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_shot","sa");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();


        if( !arg ) return notify_fail("�����˭��ʯ�ҷۣ�\n");

        if( !objectp(target = present(arg, environment(me))) )
                return notify_fail("����û������ˡ�\n");


       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��ʯ�ҡ�ֻ����ս����ʹ�á�\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");

        if(userp(target))
                return notify_fail("���ܶ��������ô�������ַ���\n");

        if( (string)this_player()->query("family/family_name")!="������" ) {
                message_vision("\n$N�㲻�����������������ַ���\n", me);
                return 1;
                }
        message_vision(HIR"\n$Nһ����Ц��һ���ʯ������ǵص����˳���!\n"NOR,me,target);
        me->start_busy(1) ;
        if( !target->is_killing(me) ) target->kill_ob(me);
        if( random(me->query("combat_exp"))<target->query("combat_exp")/2)
        message_vision(HIW"\n$n���һ�����͵�һ�����ذδ����г����������ߣ����������$N��ʯ�ң�\n"NOR,me,target);
        else {
                message_vision(HIW"\n$n������������ʯ������һ��\n"NOR,me,target);
                tell_object (target, HIR "\n��ֻ��������һ�ڣ�ʲôҲ��������!\n"NOR);
                target->start_busy (6);
                }
        destruct(this_object());
        return 1;
}

