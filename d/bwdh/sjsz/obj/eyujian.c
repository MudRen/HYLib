//Cracked by Kafei
// Ryu, 12/16/96
inherit F_UNIQUE;
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void init()
{
        add_action("do_cut", "cut");
	add_action("do_cut", "jian");
}

void create()
{
        set_name(GRN"�����"NOR, ({"ezui jian", "jian"}));
//	set_color("$GRN$");
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѳ����Ĵ��������������ֵ�����״��������һ�����ݣ������������һ����\n");
                set("value", 300);
		set("rigidity", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���¡�\n");
		set("clone_ob", "/clone/weapon/eyujian");
        }
//	::create();
	init_blade(260);
	setup();
}

int do_cut(string arg)
{
        object target;
	object me = this_player();
	object weapon;
//        if( !target ) target = offensive_target(me);

	if (!arg)
        return notify_fail("��Ҫ��ʲô��\n");

	target = present(arg,environment(me));
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ʲ�᣿\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("id") != "ezui jian" ) 
		return notify_fail("ʲ�᣿\n");

	if( me->is_busy() )
                return notify_fail("��ǰһ��������û�����ꡣ\n");

        if( !objectp(weapon = target->query_temp("weapon")))
//        || (string)weapon->query("skill_type") == 0 )
                return notify_fail("ʲ�᣿\n");
	message_vision(HIW "$N���������������$n��" + weapon->name()
			+ "��ȥ��\n" NOR, me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2){ 
/*	if( weapon->name() != "���콣" && weapon->name() != "�����ؽ�"
	&& weapon->query("id") != "fumo dao" && weapon->query("id") != "xiangmo chu"
	&& weapon->query("id") != "xue dao" && weapon->name() != "������"
	&& weapon->name() != "�쵶" && weapon->name() != "ԧ��"
	&& weapon->query("id") != "ezui jian" && weapon->query("id") != "ewei bian") {
*/
	if( weapon->query("weapon_prop/damage") < 80){
	message_vision(HIW "ֻ���������꡹��һ����$n���е�" + weapon->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, me, target);
                        weapon->unequip();
                        weapon->move(environment(target));
                        weapon->set("name", "�ϵ���" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        target->reset_action();
	}else {
	message_vision(HIW"ֻ�����ҽ���$n����" +weapon->name() +"��춽�ʵ��������������ϡ�\n"NOR, me, target);
	me->start_busy(1+ random(3));
		
	}
        } else {
        message_vision(HIW"����$n������$N����ͼ�����е�����\n" NOR, me, target);
	me->start_busy(1+ random(3));
        }

        return 1;
}
